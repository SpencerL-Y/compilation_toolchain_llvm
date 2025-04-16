import os
import sys
import re
from pathlib import Path
from openai import OpenAI
import logging

print("here")
PROJECT_DIR = os.path.dirname(os.path.abspath(__file__))
STATIC_SOURCE_FOLDER = os.path.join(PROJECT_DIR, "static_file_data/src")
TARGET_LABELLED_SRC = os.path.join(PROJECT_DIR, "files_with_label")
TRAINING_DATA_SRC_FOLDER = os.path.join(PROJECT_DIR, "training_data/src")
TRAINING_DATA_PROMPT_FOLDER = os.path.join(PROJECT_DIR, "training_data/prompt")
RESULT_FOLDER = os.path.join(PROJECT_DIR, "result")


os.makedirs(RESULT_FOLDER, exist_ok=True)

global_model = "openai/gpt-4o"  
secrete = "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"

class PointerAnalysisLLM:
    def __init__(self, api_key: str = secrete):
        self.set_up_openrouter_configs()
        self.system_prompt = self._get_system_prompt()
        
    def set_up_openrouter_configs(self):
        try:
            self.client = OpenAI(
                api_key=secrete,
                base_url="https://openrouter.ai/api/v1",
                timeout=30
            )
        except Exception as e:
            logging.error(f"OpenRouter configuration failed: {e}")
            raise

    def _get_system_prompt(self) -> str:
        return """You are a pointer analysis expert focusing on C program alias analysis.

Core Analysis Principles:
1. Memory Location Focus
   - Track where each pointer points to
   - Consider all possible runtime values
   - Analyze memory access patterns

2. Conservative Analysis
   - Array indices are unknown at runtime
   - Uninitialized pointers are undefined
   - Multiple execution paths need consideration

3. Struct Field Rules
   - Different fields never alias
   - Same field may alias across instances
   - Field access patterns matter

4. Array Handling
   - Array elements may alias
   - Array indices are dynamic
   - Conservative array analysis required

5. Assignment Rules
   - Direct assignments create must-alias
   - Indirect assignments may create aliases
   - Consider all assignment paths

Your task is to determine if two pointers:
- MUST alias (always point to same location)
- MAY alias (might point to same location)
- NO alias (never point to same location)"""

    def preprocess_program(self, program: str) -> str:

        program = re.sub(r'/\*.*?\*/', '', program, flags=re.DOTALL)
        program = re.sub(r'//.*$', '', program, flags=re.MULTILINE)
        
        
        program = re.sub(r'([a-zA-Z_][a-zA-Z0-9_]*\s*(?:\[.*?\])?\s*(?:->|\.)\s*[a-zA-Z_][a-zA-Z0-9_]*)',
                        r'POINTER_OP[\1]', program)
        program = re.sub(r'(&[a-zA-Z_][a-zA-Z0-9_]*)', r'ADDRESS_OF[\1]', program)
        
        return program

    def analyze_pointers(self, program: str, ptr1: str, ptr2: str) -> str:
        try:
            
            processed_program = self.preprocess_program(program)
            content = f"""Given a C program with pointer analysis task:

Program:
{processed_program}

Task:
Analyze the aliasing relationship between pointers {ptr1} and {ptr2}.

Key Rules to Consider:
1. Array elements with different indices MAY alias (array indices are uncertain at runtime)
2. Same fields in different struct array elements MAY alias (conservative array handling)
3. Different struct fields NEVER alias (field sensitivity)
4. Uninitialized pointers are undefined
5. After direct assignment p = q, p and q MUST alias

You must output in exactly this format:
1. POINTERS: {ptr1},{ptr2}
2. RESULT: [MAY|NO|MUST]
3. REASON: [Single clear sentence explaining the result]

Guidelines for determining RESULT:
- MUST = Pointers are guaranteed to point to same address (100% certain)
- MAY = Pointers could potentially point to same address
- NO = Pointers definitely never point to same address

Analyze step by step:
1. Track all assignments to both pointers
2. Consider all possible execution paths
3. Apply pointer analysis rules
4. Make conservative assumptions for uncertainty
"""
            response = self.client.chat.completions.create(
                model=global_model,
                messages=[
                    {"role": "system", "content": self.system_prompt},
                    {"role": "user", "content": content}
                ],
                max_tokens=1000,
                temperature=0.1
            )
            result = response.choices[0].message.content
            print(f"LLM Analysis for {ptr1} and {ptr2}:\n{result}")
            return result
        except Exception as e:
            logging.error(f"LLM analysis failed: {str(e)}")
            return None


def parse_llm_response(response: str) -> dict:
    
    if not response:
        return {"result": "", "reason": "No analysis available"}
    
    lines = response.strip().split('\n')
    result = {"result": "", "reason": "No analysis available"}
    
    for line in lines:
        line = line.strip()
        if line.startswith('2. RESULT:'):
            result_text = line.split(':')[1].strip()
            
            if result_text in ["MAY", "NO", "MUST"]:
                result['result'] = result_text
        elif line.startswith('3. REASON:'):
            result['reason'] = line.split(':')[1].strip()
    
    return result

def verify_analysis_result(ground_truth: str, llm_result: str, ptr1: str, ptr2: str) -> bool:
    
    if ground_truth == llm_result:
        return True
        
    
    if ground_truth == "MAY" and llm_result == "NO":
        
        if "[" in ptr1 or "[" in ptr2:
            return False
    elif ground_truth == "MUST" and llm_result != "MUST":
        
        return False
        
    return True

def sift_usable_cases():
    for item in list(Path(STATIC_SOURCE_FOLDER).rglob("*.c")):
        with open(item, "r", encoding="utf-8") as file:
            for line in file:
                if("MAYALIAS" in line or "MUSTALIAS" in line or "NOALIAS" in line):
                    os.system("cp " + item.as_posix() + " " + TARGET_LABELLED_SRC)

def parse_alias_stmt(line):
    line = line.strip()  #
    pattern = re.compile(r'(MAYALIAS|MUSTALIAS|NOALIAS)\s*\(\s*([^,)]+?)\s*,\s*([^,)]+?)\s*\)[^;]*;')
    match = pattern.search(line)
    if match:
        kind = match.group(1).replace("ALIAS", "")
        expr1 = match.group(2).strip()
        expr2 = match.group(3).strip()
        return ([expr1, expr2], kind)
    return None

def create_labelled_data():
    for item in list(Path(TARGET_LABELLED_SRC).rglob("*.c")):
        accumulated_program = ""
        label_id = 0
        label_id2test_result = {}
        f = open(item, "r", encoding="utf-8")
        print("processing " + item.as_posix())
        for line in f:
            pattern = re.compile(r'(MAYALIAS|MUSTALIAS|NOALIAS)\s*\(\s*([^,)]+?)\s*,\s*([^,)]+?)\s*\)[^;]*;')
            match = pattern.search(line)
            if match:
                label_id += 1
                accumulated_program += "------- LABEL " + str(label_id) + "\n"
                label_id2test_result[label_id] = parse_alias_stmt(line)
            else:
                accumulated_program += line
        new_file_name = os.path.splitext(os.path.basename(item))[0] + "_labelled.c"
        nf = open(os.path.join(TRAINING_DATA_SRC_FOLDER, new_file_name), "w+", encoding="utf-8")
        nf.write(accumulated_program)
        nf.close()
        nfl = open(os.path.join(TRAINING_DATA_SRC_FOLDER, os.path.splitext(os.path.basename(item))[0] + "_labels.txt"), "w", encoding="utf-8")
        for key in label_id2test_result:
            print(label_id2test_result[key])
            nfl.write("LABEL " + str(key) + "," + label_id2test_result[key][0][0] + "," + label_id2test_result[key][0][1] + "," + label_id2test_result[key][1] + "\n") 

def formulating_training_prompt(filename: str):
    """
    Generate training prompt for a single file
    Args:
        filename: Name of the file to process, e.g. "array_alias_1_labelled.c"
    """
    llm = PointerAnalysisLLM()
    
    # Build file path
    file_path = os.path.join(TRAINING_DATA_SRC_FOLDER, filename)
    if not os.path.exists(file_path):
        print(f"Error: File {filename} does not exist")
        return
        
    file_base_name = os.path.splitext(filename)[0]
    
    # Skip non-labelled files
    if not file_base_name.endswith('_labelled'):
        print(f"Error: {filename} is not a labelled file")
        return
        
    print(f"Processing file: {filename}")
    
    try:
        # Read source file with encoding
        with open(file_path, "r", encoding="utf-8") as f:
            src_content = f.read()
        
        original_base_name = file_base_name.split("_labelled")[0]
        labels_file_name = original_base_name + "_labels.txt"
        labels_file_path = os.path.join(TRAINING_DATA_SRC_FOLDER, labels_file_name)
        wf_path = os.path.join(TRAINING_DATA_PROMPT_FOLDER, original_base_name + "_prompt.txt")
        
        # Check if labels file exists
        if not os.path.exists(labels_file_path):
            print(f"Warning: Labels file {labels_file_name} not found")
            return
            
        # Read and process labels
        with open(labels_file_path, "r", encoding="utf-8") as lf, \
             open(wf_path, "w", encoding="utf-8") as wf:
            role_str = "Pointer analyzer that analyzes whether two pointer in a program alias"
            wf.write("[ROLE]\n")
            wf.write(role_str + "\n")
            
            total_labels = len(lf.readlines())
            lf.seek(0)  # Reset file pointer
            
            for i, line in enumerate(lf, 1):
                print(f"  Analyzing label {i}/{total_labels}...")
                
                try:
                    splitted_labels = line.strip().split(",")
                    label_str = splitted_labels[0]
                    first_ptr = splitted_labels[1]
                    second_ptr = splitted_labels[2]
                    ground_truth = splitted_labels[3]
                    
                    # Use LLM for analysis
                    llm_analysis = llm.analyze_pointers(src_content, first_ptr, second_ptr)
                    
                    # Write question
                    question = (f"Analyze whether pointer expression {first_ptr} and pointer expression {second_ptr} "
                              f"alias in the following program at the position with \"------- {label_str}\":\n")
                    wf.write("[QUESTION]\n")
                    wf.write(question)
                    wf.write(src_content + "\n")
                    
                    # Write answer
                    answer = f"Ground Truth: The two pointer expressions {ground_truth} alias\n"
                    answer += f"LLM Analysis:\n{llm_analysis}\n"
                    wf.write("[ANSWER]\n")
                    wf.write(answer)
                    
                except Exception as e:
                    print(f"  Warning: Error processing label {i}: {str(e)}")
                    continue
                    
        print(f"Completed processing file {filename}")
        
    except Exception as e:
        print(f"Error: Failed to process file {filename}: {str(e)}")

def analyze_single_file(filename: str):
    """分析单个文件的指针别名关系"""
    llm = PointerAnalysisLLM()
    
   
    src_file_path = os.path.join(TRAINING_DATA_SRC_FOLDER, filename)
    if not os.path.exists(src_file_path):
        print(f"Error: File {src_file_path} does not exist")
        return
    
    
    with open(src_file_path, "r") as f:
        src_content = f.read()
    
    
    base_name = os.path.splitext(filename)[0]
    if "_labelled" in base_name:
        original_base_name = base_name.split("_labelled")[0]
    else:
        original_base_name = base_name
        
    labels_file_name = original_base_name + "_labels.txt"
    labels_file_path = os.path.join(TRAINING_DATA_SRC_FOLDER, labels_file_name)
    
    if not os.path.exists(labels_file_path):
        print(f"Error: Labels file {labels_file_path} does not exist")
        return
    
    
    result_file_path = os.path.join(RESULT_FOLDER, f"{original_base_name}_analysis.txt")
    results_summary = [] 
    
    with open(result_file_path, "w", encoding="utf-8") as result_file:
        result_file.write(f"Analysis Results - {original_base_name}\n")
        result_file.write("=" * 50 + "\n\n")
        
       
        with open(labels_file_path, "r", encoding="utf-8") as lf:
            for line in lf.readlines():
                splitted_labels = line.strip().split(",")
                label_str = splitted_labels[0]
                first_ptr = splitted_labels[1]
                second_ptr = splitted_labels[2]
                ground_truth = splitted_labels[3]
                
                
                llm_analysis = llm.analyze_pointers(src_content, first_ptr, second_ptr)
                
                
                analysis_result = parse_llm_response(llm_analysis)
                llm_result = analysis_result['result']
                reason = analysis_result['reason']
                
                if llm_result:
                    if not verify_analysis_result(ground_truth, llm_result, first_ptr, second_ptr):
                        print(f"Warning: Suspicious analysis result for {first_ptr} and {second_ptr}")
                      
                
                if llm_result: 
                    results_summary.append(f"{ground_truth},{llm_result}")
                

                result_file.write(f"Label: {label_str}\n")
                result_file.write(f"Pointers: {first_ptr} and {second_ptr}\n")
                result_file.write(f"Ground Truth: {ground_truth}\n")
                result_file.write(f"LLM Result: {llm_result}\n")
                result_file.write(f"Reason: {reason}\n")
                result_file.write("-" * 50 + "\n\n")
                
                print(f"Analysis for {label_str} completed - Result: {llm_result}")
        

        result_file.write("Summary (Ground Truth,LLM Result):\n")
        for result in results_summary:
            result_file.write(f"{result}\n")
        
        print(f"All analysis results saved to {result_file_path}")

def process_multiple_files(filenames: list):
    """
    Process multiple files in batch
    Args:
        filenames: List of file names
    """
    print(f"\nStarting to process {len(filenames)} files...")
    
    for i, filename in enumerate(filenames, 1):
        print(f"\nProcessing file {i}: {filename}")
        print("-" * 50)
        
        try:
            formulating_training_prompt(filename)
            analyze_single_file(filename)
            print(f"File {filename} processing completed")
        except Exception as e:
            print(f"Error processing file {filename}: {str(e)}")
            continue
            
    print("\nAll files processing completed!")

if __name__ == "__main__":
    print("Start")
    sift_usable_cases()
    print("Sift usable cases done")
    create_labelled_data()
    print("Create labelled data done")
    
    # List of files to process
    files_to_process = [
        "test-su_labelled.c",
    ]
    
    # Process multiple files
    process_multiple_files(files_to_process)
    print("Complete")



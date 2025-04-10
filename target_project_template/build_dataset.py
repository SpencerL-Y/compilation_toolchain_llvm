import os
import sys
import re
from pathlib import Path

print("here")
PROJECT_DIR = os.path.dirname(os.path.abspath(__file__))
STATIC_SOURCE_FOLDER = os.path.join(PROJECT_DIR, "static_file_data/src")
TARGET_LABELLED_SRC = os.path.join(PROJECT_DIR, "files_with_label")
TRAINING_DATA_SRC_FOLDER = os.path.join(PROJECT_DIR, "training_data/src")
TRAINING_DATA_PROMPT_FOLDER = os.path.join(PROJECT_DIR, "training_data/prompt")


def sift_usable_cases():
    for item in list(Path(STATIC_SOURCE_FOLDER).rglob("*.c")):
        with open(item, "r", encoding="utf-8") as file:
            for line in file:
                if("MAYALIAS" in line or "MUSTALIAS" in line or "NOALIAS" in line):
                    os.system("cp " + item.as_posix() + " " + TARGET_LABELLED_SRC)

def parse_alias_stmt(line):
    line = line.strip()  # 去除首尾空格
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
        f = open(item, "r")
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
        nf = open(os.path.join(TRAINING_DATA_SRC_FOLDER, new_file_name),"w+")
        nf.write(accumulated_program)
        nf.close()
        nfl = open(os.path.join(TRAINING_DATA_SRC_FOLDER, os.path.splitext(os.path.basename(item))[0] + "_labels.txt"),"w")
        for key in label_id2test_result:
            print(label_id2test_result[key])
            nfl.write("LABEL " + str(key) + "," + label_id2test_result[key][0][0] + "," + label_id2test_result[key][0][1] + "," + label_id2test_result[key][1] + "\n") 

def formulating_training_prompt():
    for item in list(Path(TRAINING_DATA_SRC_FOLDER).rglob("*.c")):
        f = open(item, "r")
        src_content = f.read()
        file_base_name = os.path.splitext(os.path.basename(item))[0]
        original_base_name = file_base_name.split("_labelled")[0]
        labels_file_name = original_base_name + "_labels.txt"
        labels_file_path = os.path.join(TRAINING_DATA_SRC_FOLDER, labels_file_name)
        lf = open(labels_file_path, "r")
        for line in lf.readlines():
            splitted_labels = line.strip().split(",")
            label_str = splitted_labels[0]
            first_ptr = splitted_labels[1]
            second_ptr = splitted_labels[2]
            answer = splitted_labels[3]
        
        role_str = "Pointer analyzer that analyzes whether two pointer in a program alias"
        question = "Analyze whether pointer expression " + first_ptr + " and pointer expression " + second_ptr + \
                   " alias in the following program at the position with \"------- " + label_str + " \":\n"
        question += src_content + "\n"
        answer = "The two pointer expression " + answer + " alias\n"
        wf_path = os.path.join(TRAINING_DATA_PROMPT_FOLDER, original_base_name + "_prompt.txt")
        wf = open(wf_path, "w")
        wf.write("[ROLE]\n")
        wf.write(role_str + "\n")
        wf.write("[QUESTION]\n")
        wf.write(question)
        wf.write("[ANSWER]\n")
        wf.write(answer)



if __name__ == "__main__":
    print("start")
    sift_usable_cases()
    create_labelled_data()
    formulating_training_prompt()
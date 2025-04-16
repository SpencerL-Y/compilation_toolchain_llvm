#include <stdlib.h>
#include <stdio.h>
#include <time.h>



void clexma_log_malloc_result(void* ptr, const char* filename, int line, const char* varname) {
    printf("[OBJ ALLOC] malloc result: %p, in file: %s, at line: %d, variable: %s\n", ptr, filename, line, varname);
}

void clexma_log_before_free_result(void *ptr, const char* filename, int line, const char* varname) {
    printf("[OBJ FREE] free result: %p freed, in file %s, at line %d, variable freed: %s\n", ptr, filename, line, varname);
}

void clexma_log_after_free_result(void *ptr, const char* filename, int line, const char* varname) {
    printf("[AFTER FREE] freed ptr: %p, in file %s, at line %d, variable freed: %s\n", ptr, filename, line, varname);
}

void clexma_log_store_result(void *ptr, const char* filename, int line, const char* varname) {
    printf("[STORE RESULT] store ptr: %p, in file %s, at line %d, variable name: %s\n", ptr, filename, line, varname);
}

void clexma_log_alloca_result(const char* varname, const char* filename, int line) {
    printf("[STACK PTR VAR CREATED] ptr variable name: %s, in file %s, at line %d\n", varname, filename, line);
}

int __VERIFIER_nondet_int() {
    srand(time(NULL));
    int r1 = rand();  
    return r1;   
}
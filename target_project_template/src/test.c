
#include <stdlib.h>

#include <stdio.h>
int main() {
    struct T {
        struct T* next;
    };
    struct T* x;
    struct T* y;
    y = malloc(sizeof(*y));
    free(y);
    x = malloc(sizeof(*x));
    if (x == y + 1)
    {
        free(x);
    }
    return 0;
}


void clexma_log_malloc_result(void* ptr, const char* filename, int line, const char* varname) {
    printf("[OBJ ALLOC] malloc result: %p, in file: %s, at line: %d, variable: %s\n", ptr, filename, line, varname);
}

void clexma_log_before_free_result(void *ptr, const char* filename, int line, const char* varname) {
    printf("[OBJ FREE] free result: %p freed, in file %s, at line %d, variable freed: %s\n", ptr, filename, line, varname);
}

void clexma_log_after_free_result(void *ptr, const char* filename, int line, const char* varname) {
    printf("[AFTER FREE] freed ptr: %p, in file %s, at line %d, variable freed: %s\n", ptr, filename, line, varname);
}
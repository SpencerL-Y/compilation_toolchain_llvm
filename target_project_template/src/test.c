
#include <stdlib.h>

#include <stdio.h>
int main() {
    struct T {
        struct T* next;
    };
    struct T* x = ((void *)0);
    struct T* y = ((void *)0);
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
    printf("[OBJ CERATE] malloc result: %p, in file: %s, at line: %d, variable: %s\n", ptr, filename, line, varname);
}
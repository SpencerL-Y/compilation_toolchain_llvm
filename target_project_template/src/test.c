
#include <stdlib.h>

#include <stdio.h>
int main() {
    struct T {
        struct T* next;
    };
    struct T* x;
    struct T* y;
    struct T* z;
    y = malloc(sizeof(*y));
    x = malloc(sizeof(*x));

    z = x;
    y = x;

    if (x == y + 1)
    {
        free(x);
    }
    return 0;
}

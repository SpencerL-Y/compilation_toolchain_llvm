#include <stdlib.h>

int main() {
    int* a = malloc(4*sizeof(int));
    *a = 10;
    return 0;
}
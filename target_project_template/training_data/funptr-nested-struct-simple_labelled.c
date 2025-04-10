------- LABEL 1
struct interesting {
        int dummy;
        void (*f1)(int*);
        void (*f2)(int*);
};

struct nested_ptr {
        int dummy;
        struct interesting* ptr;
};

int g;
------- LABEL 2
------- LABEL 3

struct interesting i1 = {
        .f1 = f1,
        .f2 = f2
};

struct nested_ptr n1 = {
        .ptr = &i1
};

void test_ptr() {
        struct interesting interesting_stub = *n1.ptr;
        interesting_stub.f1(&g);
        interesting_stub.f2(&g);
}

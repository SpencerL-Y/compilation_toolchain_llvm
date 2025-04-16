/*
 * Struct assignment.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct InnerArrayStruct {
	int* in1[10];
	int* in2[20];
	char in3;
};

struct MidArrayStruct {
	char mid1[10];
	struct InnerArrayStruct mid2[5];
};

struct ArrayStruct {
	char out2;
	struct MidArrayStruct out3;
	int* out4;
};

int main() {
	struct ArrayStruct* p;
	struct ArrayStruct s1, s2;
	int x, y;

	s1.out4 = &x;
	p = &s1;
	p->out3.mid2[3].in1[3] = &y;

	s2 = s1;

------- LABEL 1
------- LABEL 2
------- LABEL 3
	
	return 0;
}

/*
 * Struct casting.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct InnerStruct {
	char in1;
	int* in2;
};

struct SrcStruct {
	int* f1[10];
	char f2[10];
	struct InnerStruct f3[5];
	char f4;
};

struct DstStruct {
	int* f1[10];
	char f2[20];
	struct InnerStruct f3[5];
};

int main() {
	struct DstStruct* pdst;
	struct SrcStruct* psrc;
	struct SrcStruct s;
	int x, y, z;

	psrc = &s;
	psrc->f1[3] = &x;
	psrc->f3[2].in2 = &y;

	pdst = psrc;

------- LABEL 1
------- LABEL 2
------- LABEL 3

	pdst->f3[1].in2 = &z;
------- LABEL 4

	return 0;
}

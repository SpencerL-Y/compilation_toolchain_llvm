/*
 * Struct casting.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct SrcStruct {
	int* f1;
	int* f2;
	char f3;
};

struct DstStruct {
	char f1;
	int* f2;
	int* f3;
};

int main() {
	struct DstStruct* pdst;
	struct SrcStruct* psrc;
	struct SrcStruct s;
	int x, y, z;

	psrc = &s;
	psrc->f1 = &x;
	psrc->f2 = &y;

	pdst = (struct DstStruct*)psrc;

------- LABEL 1
------- LABEL 2

	pdst->f3 = &z;
------- LABEL 3

	return 0;
}

/*
 * Struct alias in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

struct MyStruct {
	int *f1;
	int *f2;
};

int main() {
	struct MyStruct s1, s2;
	int x, y;
	s1.f1 = &x;
	s1.f2 = &y;
	s2.f1 = &y;
	s2.f2 = &x;
------- LABEL 1
------- LABEL 2

	s1.f1 = &y;
------- LABEL 3
	return 0;
}

/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
	float * f3;
};

int main() {
	struct MyStruct s[3];
	int * p[2];
	int a,b,c,d;
	float x,y;
	s[0].f1 = &a, s[0].f2 = &c, s[0].f3 = &x;
	s[1].f1 = &b, s[1].f2 = &d, s[1].f3 = &y;
	p[0] = &c, p[1] = &d;

	// Same fields of different elements in a certain
	// array are treated as one object.
------- LABEL 1
------- LABEL 2
------- LABEL 3

	// Different fields of different elements in a 
	// certain array are treated as different objects.
------- LABEL 4
------- LABEL 5

	if (a)
		s[1].f1 = &c;
------- LABEL 6

	return 0;
}

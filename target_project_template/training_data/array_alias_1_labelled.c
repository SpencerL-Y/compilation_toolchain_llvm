/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
};

int main() {
	struct MyStruct s[2];
	int a,b;
	s[0].f1 = &a;
	s[1].f1 = &b;

	// Different fields of different elements in a 
	// certain array are treated as different objects.
------- LABEL 1
------- LABEL 2

	return 0;
}
/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
};

int main() {
	struct MyStruct s[2];
	int a,b;
	s[0].f1 = &a;
	s[1].f1 = &b;

	// Different fields of different elements in a 
	// certain array are treated as different objects.
------- LABEL 1

	return 0;
}
/*
 * Alias with array
 * Author: Sen Ye
 * Date: 06/09/2013
 */
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	int * f2;
};

int main() {
	struct MyStruct s[2];
	int a,b;
	s[0].f1 = &a;
	s[1].f1 = &b;

	// Different fields of different elements in a 
	// certain array are treated as different objects.
------- LABEL 1
------- LABEL 2

	return 0;
}
------- LABEL 1
int main() {
	int a, b;
	int* source[2] = {&a, &b};
	int* x = source[1];
------- LABEL 2
	return 0;
}
/*
 * Array alias in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

struct MyStruct {
	int *f1;
	int *f2;
};

int main() {
	struct MyStruct s[2];
	int x, y;
	s[0].f1 = &x;
	s[1].f2 = &y;

	// Arrays are treated as a single element.
	// Different fields have its own points-to set.
	// Same fields have same points-to set, even they belong
	// to different elements.
------- LABEL 1
------- LABEL 2
------- LABEL 3

	s[0].f1 = &y;
------- LABEL 4
	return 0;
}

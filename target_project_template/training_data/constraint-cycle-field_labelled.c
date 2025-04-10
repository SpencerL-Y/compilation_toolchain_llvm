/*
 * Field cycle.
 * Author: Sen Ye
 * Date: 10/10/2013
 */

#include <stdlib.h>
#include "aliascheck.h"

struct MyStruct {
	int * f1;
	struct MyStruct * next;
};

int main() {
	struct MyStruct * p = (struct MyStruct *) malloc (sizeof(struct MyStruct));
	int num = 10;
	while (num) {
		p->next = (struct MyStruct *) malloc (sizeof(struct MyStruct));
		p->next->f1 = (int *) malloc (sizeof(int));
		p = p->next;
	}
	struct MyStruct *q = p;
------- LABEL 1
------- LABEL 2
	return 0;
}


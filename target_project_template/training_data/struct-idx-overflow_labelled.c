------- LABEL 1

struct S {int f0; int f1; int f2;};

int main()
{
	struct S s;
	void *a, *b, *c, *d;
	
	a = &s;
	b = &((struct S*) a)->f2;
	c = &((struct S*) b)->f2;
	d = &((struct S*) a)->f1;
	
------- LABEL 2

	return 0;
}


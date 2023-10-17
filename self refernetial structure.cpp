#include<stdio.h>
struct self
{
int a;
char c;
struct self *p;
};
int main()
{
	struct self v;
	v.a = 10;
	v.c = 'D';
	v.p = NULL;
	struct self x;
	x.a = 20;
	x.c = 'S';
	x.p = NULL;
	v.p = &x;
	printf("Block 1 %d %c %d\n",v.a,v.c,v.p);
	printf("\nBlock 2 %d %c %d\n",v.p->a,v.p->c,v.p->p);
}


#include <stdio.h>
#include <stdlib.h>

struct P1 {
	char a;
	int b;
	char c;
	int d;
}; 

struct P1 obj;

int main(){
	struct P1 *p1 = &obj;
	p1 -> a = 'a';
	p1 -> b = 1;
	p1 -> c = 'b';
	p1 -> d = 2;

	void *p2 = (void *) p1;
	int size = sizeof(obj);
	
	printf("%d \n", size);
	printf("%c \n", *(char *)p2);
	printf("%d \n", *(int *)(p2 + 4)); //reason why +4 and not +1 is because of data alignment on structs (padding)
	printf("%c \n", *(char *)(p2 + 8));
	printf("%d \n", *(int *)(p2 + 12));
}

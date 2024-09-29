//some practice on bit masking, inspired by problem 2.12

#include<stdio.h>
#include<stdlib.h>

void binary(void* val){
	//little endian
	char *p = (char *)val;
	printf("binary: ");
	for(int i = 0; i < sizeof(long); i++){
		for(int j = 0; j < 8; j++){ //number of bits in byte
			printf("%u", (*(p+i) >> j+i) & 1);
		}
	}	
}

int main(){
	long x = 0x89ABCDEF;
	int mask = 0xFF;
	
	//always convert boolean operations to binary
	printf("decimal: %ld, hex x: %lx \n", x, x);
	binary(&x);
	printf("\n");
	
	//convert mask to boolean
	//then explicitly show x & mask compares the boolean expressions to give the resulting value
	
}

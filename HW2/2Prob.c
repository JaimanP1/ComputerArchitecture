//figure 2.14 from textbook

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdint.h>

int main(){
	printf("\t\t\t\tWord Sizes:\n");
	printf("Value:\t\t8\t\t16\t\t32\t\t64\n");
	printf("UMax hex:\t%X\t\t%X\t\t%lX\t%lX\n", UINT8_MAX, UINT16_MAX, UINT32_MAX, UINT64_MAX);
	printf("UMax dec:\t%d\t\t%d\t\t%ld\t%lu\n", UINT8_MAX, UINT16_MAX, UINT32_MAX, UINT64_MAX);
	printf("TMin hex:\t%X\t%X\t%lX\t%lX\n", INT8_MIN, INT16_MIN, INT32_MIN, INT64_MIN);
	printf("TMin hex:\t%d\t\t%d\t\t%ld\t%ld\n", INT8_MIN, INT16_MIN, INT32_MIN, INT64_MIN);
	printf("TMax hex:\t%X\t\t%X\t\t%lX\t%lX\n", INT8_MAX, INT16_MAX, INT32_MAX, INT64_MAX);
	printf("TMax dec:\t%d\t\t%d\t\t%ld\t%ld\n", INT8_MAX, INT16_MAX, INT32_MAX, INT64_MAX);
	printf("-1 hex:\t\t%X\t%X\t%lX\t%lX\n", -1, -1, -1, -1);
	printf("0 hex:\t\t%X\t\t%X\t\t%X\t\t%X\n", 0, 0, 0, 0);
}

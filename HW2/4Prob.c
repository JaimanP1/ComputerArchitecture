//page 28 of lecture note 2

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdint.h>

int main(){
	int num1 = 0;
	unsigned int num2 = 0;
	signed int num3 = -1;
	int num4 = INT32_MAX;
	signed int num5 = INT32_MIN - 1;
	unsigned int num6 = INT32_MAX;
	signed int num7 = -2;
	unsigned int num8 = -1;

	//case1
	if(num1 == num2){
		printf("case1: unsigned\n");
	}

	//case2
	if(num3 < num1){
		printf("case2: signed\n");
	}

	//case3
	if(num3 > num2){
		printf("case3: signed\n");
	}

	//case4
	if(num4 > num5){
		printf("case4: signed\n");
	}

	//case5
	if(num6 < num5){
		printf("case5: unsigned\n");
	}

	//case6
	if(num3 > num7){
		printf("case6: signed\n");
	}

	//case7
	if(num8 > num7){
		printf("case7: unsigned\n");
	}

	//case8
	if(num4 < num6){
		printf("case8: unsigned\n");
	}

	//case9
	if(num4 > (int) num6){
		printf("case9: signed\n");
	}
}

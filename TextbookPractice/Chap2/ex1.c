//Based on figure 2.4 in the textbook, my own code though
//Want to print various data type sized
//Do not like how much they used datatypes; no need for typedef or typecast

#include<stdio.h>
#include<stdlib.h>

void bytes(void *start, int length){
	//given an array (void *) and then print out all elements, which are bytes
	printf("address, value \n");
	for(int i=0; i<length; i++){
		//address
		printf("address byte %d: %x \n", i+1, *(start+i));
		//value
		printf("value byte %d: %x \n", i+1, *(start+i));
	}
	printf("\n");
}

int main(){
	int integer = 0;
	char character = "c";
	char *string = "The C Programming Language";
	int *pointer = &integer;
	
	printf("integer: \n");
	bytes(&integer, sizeof(int));
	printf("character: \n");
	bytes(&character, sizeof(char));
	printf("character array: \n");
	bytes(void* (string), sizeof(char) * sizeof(string));
	printf("character array v2: \n");
	bytes(&string, sizeof(char) * sizeof(string));
	printf("integer pointer : \n");
	bytes(void* (pointer), sizeof(int));
	printf("integer pointer v2: \n");
	bytes(&pointer, sizeof(int));
	
}

//Based on figure 2.4 in the textbook, my own code though
//Want to print various data type sized
//Do not like how much they used datatypes; no need for typedef or typecast

#include<stdio.h>
#include<stdlib.h>

void bytes(void *start, int length){
	//given an array (void *) and then print out all elements, which are bytes
	printf("\naddress, value \n");
	for(int i=0; i<length; i++){
		//address
		printf("address byte %d: %p \n", i+1, (start+i));
		//value
		printf("value byte %d: %x \n", i+1, *(char *)(start+i));
	}
	printf("\n");
}

int main(){
	int integer = 987654321;
	char character = 'c';
	char *string = "The C Programming Language";
	int *pointer = &integer;
	int array[] = {1, 2, 3};
	
	printf("integer: %d (%x) \n", integer, integer);
	bytes(&integer, sizeof(int));

	printf("character: %c (%x) \n", character, character);
	bytes(&character, sizeof(char));

	printf("character array: %c (%x) \n", *string, *string); 
	bytes((void*) (string), sizeof(string)/sizeof(char));
	
	printf("character array v2: %s (%p) \n", string, string);
	bytes(&string, sizeof(char*));
	
	printf("integer pointer: %d (%x) \n", *pointer, *pointer);
	bytes((void*) (pointer), sizeof(int));
	
	printf("integer pointer v2: %ls (%p) \n", pointer, pointer);
	bytes(&pointer, sizeof(int *));
	
	printf("array: %d (%x) \n", *array, *array);
	bytes((void*)array, sizeof(array));

	printf("array v2: %ls (%p) \n", array, array);
	bytes(&array, sizeof(array));
}

//just some more experimenting

#include<stdio.h>
#include<stdlib.h>

int main(){
	int array[] = {1,2,3};
	int *p = array;
	void *p2 = &array;

	printf("array, first element value: %d \n", *array);
	printf("array, first element adddress: %p \n", array);
	printf("array, entire array address: %p \n", &array);
	for(int i = 0; i < 3; i++) printf("address: %p, value: %d \n", (array+i), array[i]);

	printf("\npointer points to: %p \n", p);
	printf("pointer value: %d \n", *p);
	printf("pointer address: %p \n", &p);
	for(int i = 0; i < 3; i++) printf("address: %p, value: %d \n", (p+i), *(p+i)); 

	printf("\npointer2 points to: %p \n", p2);
	printf("pointer value: %d \n", *(int*)p2);
	printf("pointer address: %p \n", &p2);
	for(int i = 0; i < 3; i++) printf("address: %p, value: %d \n", ((int*)p2+i), *(int*)(p2+i)); 

	//typecast in last line prints correct address but for some reason wrong value. Why is it interpreted as such?
	
	char *string = "The C Programming Language";
	printf("\naddress: %p, points to: %p, value: %c, entire string: %s \n", &string, string, *string, string);
	for(int i = 0; i < sizeof(array); i++) printf("address: %p, value: %c \n", (string+i), *(string+i));

}

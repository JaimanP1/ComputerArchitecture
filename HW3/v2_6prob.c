#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//run with double quotes on argument

struct binary{
	char sign[2];
	char exp[9];
	char mant[24]; //added 1 to size of arrays because whitespace/period
};

void string_to_float(struct binary* values, float *f){
	char *iterator;
	int *value;
	*f = 1;
	float fraction = 1;
	unsigned int length = sizeof(values);
	for(int i = 0; i < length + 1; i++){
		iterator = (char*)(&values + i);
		value = (int *)iterator;
		*value -= 48; //turns ascii for 0/1 into integer 0/1
		if(i == 1 || i == 10 || i == 35){
			continue; //whitespace/period case
		}
		if(i == 0){
			*f = powf(-2, *value);
		}
		*f *= powf(2, -127); //bias in the exponent
		if(i > 1 && i < 10){
			*f *= powf(2, *value);
		}
		if(i > 11 && i < 35){
			fraction += pow(2, -(i + 1));
		}
	}
	*f *= fraction;
}

int main(int argc, char **argv){
	struct binary values;
	char *iterator;
	for(int i = 0; i < 35; i++){
		iterator = (char*)&values;
		*(iterator + i) = argv[1][i]; //mapping values to struct
	}
	float f;
	string_to_float(&values, &f);
	printf("%f", f);


}

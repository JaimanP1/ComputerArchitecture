//Problem 2.17 from textbook

#include <stdio.h>
#include <stdlib.h>

int* binary(int val){
    int *digit = malloc(sizeof(int)*8);
    for(int i = 0; i < 8; i++){
        digit[7 - i] = (val >> i) & 1;
    }
    for(int i = 0; i < 8; i++){
        printf("%d", digit[i]);
    }
    printf("\n");
    return digit;
}

void unsigned_val(int* val){
    int u_decimal = 0;
    int base = 1;
    for(int i = 7; i >= 0; i--){
        if(val[i] == 1){
            u_decimal += base;
        }
	base *= 2; 
    }
    printf("%d \n", u_decimal);
}

void signed_val(int *val){
	int s_decimal = 0;
	int base = 1;
	if(val[0] == 1){
		s_decimal += -16;
	}
	for(int i = 6; i >= 0; i--){
		if(val[i] == 1){
			s_decimal += base;
		}
	}
	base *= 2;
	printf("%d \n", s_decimal);
}

int main()
{
    int num = 0x0A;
    int *binary_array = binary(num);
    unsigned_val(binary_array);
    
    int num2 = 0x06;
    int *binary_array2 = binary(num2);
    unsigned_val(binary_array2);

    int num3 = 0xFF;
    int *binary_array3 = binary(num3);
    signed_val(binary_array3);
    
    free(binary_array);
    free(binary_array2);
    free(binary_array3);
    return 0;
}

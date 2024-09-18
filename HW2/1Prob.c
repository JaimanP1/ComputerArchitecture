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
    printf("\t");
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
    printf("%d\t\t", u_decimal);
}

void signed_val(int *val){
	int s_decimal = 0;
	int base = 1;
	if(val[0] == 1){
		s_decimal += -128;
	}
	for(int i = 7; i >= 1; i--){
		if(val[i] == 1){
			s_decimal += base;
		}
		base *= 2;
	}
	printf("%d\n", s_decimal);
}

int main()
{
    printf("Hex		Binary		Unsigned	Signed\n");

    int num = 0x0A;
    printf("%X\t\t", num);
    int *binary_array = binary(num);
    unsigned_val(binary_array);
    signed_val(binary_array);
    
    int num2 = 0x06;
    printf("%X\t\t", num2);
    int *binary_array2 = binary(num2);
    unsigned_val(binary_array2);
    signed_val(binary_array2);

    int num3 = 0x14;
    printf("%X\t\t", num3);
    int *binary_array3 = binary(num3);
    unsigned_val(binary_array3);
    signed_val(binary_array3);

    int num4 = 0x6B;
    printf("%X\t\t", num4);
    int *binary_array4 = binary(num4);
    unsigned_val(binary_array4);
    signed_val(binary_array4);

    int num5 = 0x8A;
    printf("%X\t\t", num5);
    int *binary_array5 = binary(num5);
    unsigned_val(binary_array5);
    signed_val(binary_array5);

    int num6 = 0x86;
    printf("%X\t\t", num6);
    int *binary_array6 = binary(num6);
    unsigned_val(binary_array6);
    signed_val(binary_array6);

    int num7 = 0x94;
    printf("%X\t\t", num7);
    int *binary_array7 = binary(num7);
    unsigned_val(binary_array7);
    signed_val(binary_array7);

    int num8 = 0xEB;
    printf("%X\t\t", num8);
    int *binary_array8 = binary(num8);
    unsigned_val(binary_array8);
    signed_val(binary_array8);
    
    free(binary_array);
    free(binary_array2);
    free(binary_array3);
    free(binary_array4);
    free(binary_array5);
    free(binary_array6);
    free(binary_array7);
    free(binary_array8);
    return 0;
}

//From lecture note 2, slide 23

#include<stdio.h>
#include<stdlib.h>
#define N 5

int* binary(int val){
    int *digit = malloc(sizeof(int)*8);
    for(int i = 0; i < N; i++){
        digit[N - 1 - i] = (val >> i) & 1;
    }
    for(int i = 0; i < N; i++){
        printf("%d", digit[i]);
    }
    printf("\t\t");
    return digit;
}

void unsigned_val(int* val){
    int u_decimal = 0;
    int base = 1;
    for(int i = (N - 1); i >= 0; i--){
        if(val[i] == 1){
            u_decimal += base;
        }
        base *= 2;
    }
    printf("%d\n", u_decimal);
}

void signed_val(int *val){
        int s_decimal = 0;
        int base = 1;
        if(val[0] == 1){
                s_decimal += -16; //hardcoded lower limit
        }
        for(int i = (N - 1); i >= 1; i--){
                if(val[i] == 1){
                        s_decimal += base;
                }
                base *= 2;
        }
        printf("%d\t\t", s_decimal);
}

int main(){
	printf("Decimal:\tBits:\t\tSigned:\t\tUnsigned:\n");
	for(int i = 0; i < 32; i++){
		printf("%d:\t\t", i);
		int *binary_array = binary(i);
		signed_val(binary_array);
		unsigned_val(binary_array);
	}	
}

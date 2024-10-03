#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//run with double quotes on argument

struct binary{
        char sign[2];
        char exp[9];
        char mant[24]; //added 1 to size of arrays because whitespace/period
};

void string_to_float(struct binary* arrays, float *f){
        char *iterator = (char *)arrays;
        int *value;
        *f = 1;
        float fraction = 1;
        float sign = 0;
        float exponent = 1;
        int place_holder;
        for(int i = 0; i < 35; i++){
                iterator += i;
                value = (int *)iterator;
                place_holder = *value;
                place_holder -= 48; //turns ascii for 0/1 into integer 0/1
                if(place_holder != 0 || place_holder != 1){
                        continue; //whitespace/period case
                }
                if(i == 0){
                        sign = powf(-2, *value);
                }
                *f *= powf(2, -127); //bias in the exponent
                if(i > 1 && i < 10){
                        exponent *= powf(2, *value);
                }
                if(i > 11 && i < 35){
                        fraction += powf(2, -(i + 1));
                }
        }
        *f *= exponent;
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

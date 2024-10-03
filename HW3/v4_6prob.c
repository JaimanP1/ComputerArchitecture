#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//run with double quotes on argument
//only works somewhat for normalized values

struct binary{
        char sign[2];
        char exp[9];
        char mant[24]; //added 1 to size of arrays because whitespace/period
};

void string_to_float(struct binary* arrays, float *f){
        char *iterator = (char *)arrays;
        *f = 1;
        float fraction = 1;
        float sign = 0;
        int exponent = 1;
        int place_holder;
        *f *= powf(2, -127); //bias in the exponent
        for(int i = 0; i < 35; i++){
                place_holder = (int)iterator[i];
                place_holder -= 48; //turns ascii for 0/1 into integer 0/1
                if(place_holder == 0 || place_holder == 1){
                    if(i == 0){
                        sign = (place_holder == 0) ? 1 : -1;
                    }
                    if(i > 1 && i < 10){
                            if (place_holder == 1){
                                exponent += (int)powf(2, 9-i);
                            }
                    }
                    if(i > 11 && i < 35){
                            if (place_holder == 1){
                                fraction += powf(2, -(i + 1));
                            }
                    }
                }
        }
        *f *= powf(2, exponent);
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
        printf("%.30f", f);


}

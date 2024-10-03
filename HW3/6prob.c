/* Print a binary to float: ftob.c */
#include <stdio.h>
#include <stdlib.h>

//void float_to_string(float f, char *s, int n);
void string_to_float(float,char *,int);
void print_float();

#define LEN 32
#define EXP_32 8		/* ending index of s for exponent */
#define MAN_32 9		/* starting index of s for significand */

int main(int argc, char **argv) {
  int n=LEN;
  float f;
  char s[LEN];

  s = &argv[1];
  for(int i = 0; i < 32; i++){
	printf("%c", s[i]);
  }
  printf("\n");

  string_to_float(f,s,n);
  print_float(s,n);

  return 0;
}

/* convert float to binary and store in s, a string of 32 chars */
void string_to_float(float f, char *s, int n){
  unsigned int u_int;
  int i;			/* for loop index */

  /* fill here */

}

/* print space in between sign bit, exponent, and significand */
void print_float(char *s, int n) {
  int i=0;

  /* fill here */

}

/* End of ftob.c */

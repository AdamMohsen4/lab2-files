/*
 print-primes.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

void print_number(int num);
int is_prime(int n);

void print_primes(int n){
    // Should print out all prime numbers less than 'n'
    // with the following formatting. Note that
    // the number of columns is stated in the define
    // COLUMNS

    int counter = 0;

    for (int i = 2; i < n; i++){
      if(is_prime(i) == 1){
         print_number(i);
     
       counter++;
      if(counter % COLUMNS == 0)
       printf("\n");
    }
  }
    if (counter % COLUMNS != 0){
       printf("\n");
    }
}

  void print_number(int num){
      printf("%10d ", num);
    }


  int is_prime(int n){

      if (n <= 1)
      return 1;

      for (int i=2; i < n; i++){
      if (n % i == 0)
        return 0;	
    }	
      return 1;
  }
// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
    if(argc == 2)
    {
        print_primes(atoi(argv[1]));
    }
  else
    printf("Please state an integer number.\n");
  return 0;
}

 

/*
 print-primes.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

// Declare functions
void print_number(int num);
int is_prime(int n);

void print_primes(int n){

    int counter = 0;

    for (int i = 2; i < n; i++){
      if(is_prime(i) == 1){
         print_number(i);
         counter++;

         if(counter % COLUMNS == 0)
           printf("\n");
    }
  }
  // If the last line was not complete, print a newline.
    if (counter % COLUMNS != 0){ 
       printf("\n");
    }
}

/*
 Prints a number 'num' with a specific format.
*/
  void print_number(int num){
      printf("%10d ", num);
    }

/*
 Checks if a number 'n' is prime.
*/
  int is_prime(int n){

      if (n <= 1)
      return 0;  // Numbers <= 1 are NOT prime

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
    printf("Please state an integer number bludclot battyboy.\n");
  return 0; 
}

 

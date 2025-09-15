#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
/*
 Prints a number 'num' with a specific format.
*/
  void print_number(int num){
      printf("%10d ", num);
    }

  /*
  Checks if a number 'n' is prime using Sieves algorithm using heap memory.
  */
  void print_sieves(int n){

    int counter = 0;

    if (n < 2) return;
    unsigned char *a = malloc(n * sizeof(unsigned char));  // malloc(size) => pointer to allocated memory

    for(int i = 0; i < n; i++) a[i] = 1; // Initialize all elements to 1 (prime)

    for(int i = 2; i*i < n; i++){ 
      // Mark multiples of i as non-prime
      if (a[i-1] == 1){  // If i is prime
        // Mark all multiples of i as non-prime
        for(int j = i*i; j <= n; j += i){
          a[j-1] = 0;
        }
      }
    }
    // Print prime numbers
    for(int i = 2; i < n; i++){
      if (a[i-1] == 1){
        counter++;
        print_number(i);
        if(counter % COLUMNS == 0)
          printf("\n");
      }
    }
    printf("\n");

    free(a); //Freeing the heap allocated memory
  }


// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
    if(argc == 2)
    {
         print_sieves(atoi(argv[1]));
       
    }
  else
    printf("Please state an integer number bludclot battyboy.\n");
  return 0; 
}

 

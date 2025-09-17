/*
 pointers.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

/*
A pointer is a variable that stores the address of another variable.
Syntax for pointers in C: 
  type *name;  // Declare a pointer variable
  name = &var; // Get the address of a variable
  *name = value; // Set the value at the address
  value = *name; // Get the value at the address
*/

#include <stdio.h>
#include <stdlib.h>

// Declaration of two strings, two lists, and a counter variable.
char* text1 = "This is a string."; 
char* text2 = "Yet another thing.";
int list1[20] = {0};  // Match assembly: 80 bytes / 4 bytes per int = 20 ints. 
int list2[20] = {0};  
int counter = 0;
void work();
void copycodes(const char* scr, int* dst);

void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

void work(){

  // Create pointers to the strings and the lists.
  // Call copycodes() twice, once for each string/list pair.
  // After each call, the variable "counter" should contain
  // the number of characters copied so far.

  char* src1 = text1; // pointer to the string (source)
  int* dst1 = list1; // pointer to the list (destination)
  copycodes(src1, dst1); // Call copycodes to copy from src1 to dst1
  char* src2 = text2; 
  int* dst2 = list2; 
  copycodes(src2, dst2);
}

void copycodes(const char* scr, int* dst){
  // Copy characters from the string 'src' to the list 'dst'
  // until the null-character is reached.
  // Return the number of characters copied.

  while((*scr & 0xFF) != 0) {  
    *dst = (int)*scr; // * Copy the ASCII code of the character (in assembly: sw - store word). 
    scr++;            // * Move to the next character
    dst++;            // * Move to the next position in the list (4 bytes in assembly)
    counter++;       
  }
}
int main(void){
 
    work();
    printf("\nlist1: ");
    printlist(list1);
    printf("\nlist2: ");
    printlist(list2);
    printf("\nCount = %d\n", counter);

    endian_proof((char*) &counter);
}

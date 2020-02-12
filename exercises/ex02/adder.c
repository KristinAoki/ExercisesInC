/* This file contains my solutions for exercise 3.
 * I worked with Shreya Chowdhardy.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LENGTH 100
#define BUFFER 32

 // Global variables
int num_array[ARRAY_LENGTH];
int sum = 0;

/*
 * This function converts the given character to an integer. If the given
 * character is not an integer the code will generate an error message stating
 * that you had an ivalid input. If the length of the character string is longer
 * than the defined buffer you will see another error that states the input strings
 * is greater than allocated space.
 */
int get_number(char* num) {
  int n = atoi(num);
  if ((n == 0) && (*num  != '0')) {
    printf("Error: Invalid input\n");
    return -1;
  }
  if (strlen(num) >= BUFFER) {
    printf("Error: Input string exceeds allocated space\n");
  }
  return n;
}

/*
 * This function adds up all the elements in the array and stores it in the
 * global variable sum
 */
void total() {
  for (int i = 0; i <= sizeof(num_array); i++) {
    sum = sum + num_array[i];
  }
}

/*
 * This function prompts the user to input a character string and runs the input
 * through get_number(). When the user presses Ctrl-D the program ends and
 * calculates the sum of the array. Then the program prints the sum for the user
 * to see.
 */
int main() {
  char input_num[BUFFER];
  int i = 0;
  printf("Input Number:\n");
  while (fgets(input_num, sizeof(input_num), stdin) != NULL) {
    int num = get_number(input_num);
    if (i >= ARRAY_LENGTH) {
      printf("Error: Entered more numbers than allowed by array\n");
      break;
    }
    if (num != -1) {
      num_array[i] = num;
      i++;
    }
  }
  total();
  printf("Your sum is: %i\n", sum);
}

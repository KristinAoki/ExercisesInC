#include <stdio.h>

int main() {
    
    int x = 5;
    int y = x + 1;
    printf("%i\n", y);
    return 0;
}

/* 1. You can see the change starting at line 18 in the assembly code.
   2. When you turn on the optimization flag the overall number of lines
      decrease. The numbers of lines in the main decreased and there are
      additional lines in .LCO, .section and .p2align.
   3. When you print x, .string in .LCO changes to interpret and integer rather
      than a string. Everything else appears to remain the same.
   4. With optimization you only see the value for y and the overall code is
      shorter. You see y but not x because to run more optimally x no loner
      needs to be stored since its value is now part of y. Without optimization
      you can still see the value for x, but y is not present.
*/

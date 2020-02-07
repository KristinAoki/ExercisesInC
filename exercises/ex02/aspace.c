/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void address() {

  int var3 = 6;
  printf ("Address of var3 is %p\n", &var3);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";
    void *m = malloc(128);
    void *chunk1 = malloc(32);
    void *chunk2 = malloc(32);

    address();

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("m points to %p\n", m);
    printf ("chunk1 points to %p\n", chunk1);
    printf ("chunk2 points to %p\n", chunk2);

    return 0;
}

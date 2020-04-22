/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}

int read_element(int *array, int index) {
    int x = array[index];
    return x;
}

int main()
{
    int never_allocated;
    int *free_twice = malloc(sizeof (int));
    int *use_after_free = malloc(sizeof (int));
    int *never_free = malloc(sizeof (int));
    int array1[100];
    int *array2 = malloc(100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    read_element(array1, -1);
    read_element(array1, 100);

    // but it does bounds-check dynamic arrays

    // updated indexes to be within bounds of array
    read_element(array2, 0);
    read_element(array2, 99);

    // free malloced space for array2
    free(array2);

    // and it catches use after free

    *use_after_free = 17;

    // moved free to after accessing
    free(use_after_free);

    // never_free is definitely lost
    *never_free = 17;

    // free so that memory is no longer lost
    free(never_free);

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    // never_allocated is not a pointer and has no space allocated
    // free_anything(&never_allocated);

    free(free_twice);

    // remove the second free of pointer
    // free(free_twice);

    return 0;
}

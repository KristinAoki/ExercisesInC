/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

Homework Response:
  I tested the relationship among parent and children processes in the heap,
  global, and stack. I malloced an integer in the heap and between creating
  children I incremented the value. To see the difference I printed the value
  and address with each child and compared it to the parent. When I first did
  this I thought there was an error because the value returned from the heap
  after the parent ran was always the final value from the final child. I realized
  this was actually ok because the parent ran after all the children so it makes
  sense that the value it printed was the same as the final child. To test global
  variables, I created a string literal and made sure that the child and parent
  printed the same string and they had the same address. To check if the child
  and parent have a different stack I assigned them local variables and in the
  main function (line 56 and 121) I tried to use a variable from the child, but it
  threw an error, undefined variable. If the parent and child shared a stack
  this error would not come up because it woud still be able to access the
  child's stack and get the variable.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;
char *lit = "hello";

// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i, int *num)
{
    sleep(i);
    int x = 10;
    printf("Hello from child %d.\n", i);
    printf("malloc() value is %d at address %p in memory\n", *num, num);
    printf("string value is %s at address %p in memory\n", lit, &lit);
    // printf("%*d%*d",x,' ',y,' ');
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;
    int *num = malloc(sizeof(int));
    *num = 1;
    int y = 5;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {
        *num = *num + 1;
        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i, num);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
        printf("Check relationship of global, heap, and stack variables.\n");
        printf("malloc() value is %d at address %p in memory\n", *num, num);
        printf("string value is %s at address %p in memory\n", lit, &lit);
        // printf("%*d%*d",x,' ',y,' ');
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}

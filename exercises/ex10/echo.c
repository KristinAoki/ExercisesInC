/* Starter code for the echo exercise.

Loosely based on the example in Head First C Chapter 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void parent_code(int pipe_to_child1[], int pipe_to_child2 [])
{
    // close the read end of pipe to child
    close(pipe_to_child1[0]);
    close(pipe_to_child2[1]);

    int count = 128;
    char buffer[count];

    // write a string to the child
    char line[] = "I'm proud of you, child.";
    ssize_t sizeW = write(pipe_to_child1[1], line, strlen(line)+1);
    ssize_t sizeR = read(pipe_to_child2[0], buffer, count);
    if (sizeW == -1)
        error("Parent can't write to child");
    printf("Parent wrote %ld bytes\n", sizeW);
    if (sizeR == -1)
        error("Parent can't read from child");
    printf("Parent read %ld bytes.\n", sizeR);
    printf("Parent read: %s\n", buffer);
}


void child_code(int pipe_to_child1[], int pipe_to_child2 [])
{
    // close the write end of pipe to child
    close(pipe_to_child1[1]);
    close(pipe_to_child2[0]);

    int count = 128;
    char buffer[count];

    // write a string to the parent
    char line[] = "Thanks ma!";

    // read from pipe_to_child
    ssize_t sizeR = read(pipe_to_child1[0], buffer, count);
    ssize_t sizeW = write(pipe_to_child2[1], line, strlen(line)+1);
    if (sizeR == -1)
        error("Child can't read from parent");
    printf("Child read %ld bytes.\n", sizeR);
    printf("Child read: %s\n", buffer);

    if (sizeW == -1)
        error("Child can't write to parent");
    printf("Child wrote %ld bytes\n", sizeW);

    exit(0);
}


int main(int argc, char *argv[])
{
    /*Create a pipe */
    int pipe_to_child1[2];
    if (pipe(pipe_to_child1) == -1)
        error("Can't create the first pipe");

    int pipe_to_child2[2];
    if (pipe(pipe_to_child2) == -1)
        error("Can't create the second pipe");

    /*Fork a child process*/
    pid_t child_pid = fork();
    if (child_pid == -1)
        error("Can't fork process");

    if (child_pid == 0) {
        child_code(pipe_to_child1, pipe_to_child2);
    } else {
        parent_code(pipe_to_child1, pipe_to_child2);
    }

    int status;
    pid_t pid = wait(&status);
    if (pid == -1) {
        error("Error waiting for child process");
    }
    printf("Child %d exited with code %d\n", pid, status);
}

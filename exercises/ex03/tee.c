#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 1000

int main(int argc, char *argv[]) {
  int append_flag = 0;
  char *error = "";
  char user_input[BUFFER];
  FILE *file1;
  char ch;

  while ((ch = getopt(argc, argv, "a:")) != EOF) {
    switch (ch) {
      case 'a':
        append_flag = 1;
        break;
      default:
        append_flag = 0;
        fprintf(stderr, "ERROR: Invalid option, %s\n", error);
        return 1;
    }
  }

  argc -= optind;
  argv += optind;

  while (fgets(user_input, 1000, stdin)) {
    for (int i = 0; i < argc; i++) {
      if (append_flag) {
        file1 = fopen(argv[i], "a");
      } else {
        file1 = fopen(argv[i], "w");
      }
      fputs(user_input, file1);
      fclose(file1);
    }
    fprintf(stdout, "%s\n", user_input);
  }
  return 0;
}

/* 3. At first I did not really understand how to begin. I knew what the code
      needed to do, but not how to actually implement the code. I definitely
      had to reread the chapter from Head First C to fully understand the
      process of implementation. Once I reread the chapter, coding this
      assignment was easy and quick. If I did this again, I probably would have
      consulted the book and NINJAs before dpending so much time thinking on my
      own.

   4. Something that I noticed in the pro code is the use of an error header for
      file. I am assuming the header file takes care of a lot of error handling.
      Actually there are a lot of additional header files.They also have two
      functions, main and add. I am not really sure what add does but it does
      have components I do understand, like malloc().
*/

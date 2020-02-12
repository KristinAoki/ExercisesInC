/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    // TODO: fill this in
    regex_t regex;
    int error = regcomp(&regex, pattern, 0);
    /* Checks to see if the pattern is valid
     * if it is false, it will print an error message */
    if (error) {
      printf("Error: Could not compile exit program\n");
      exit(1);
    }

    for (int i = 0; i < NUM_TRACKS; i++) {
      int result = regexec(&regex, tracks[i], 0, NULL, 0);
      /* Checks to see if the pattern is found in the track title
       * if the pattern is found print track name and number otherwise print
       * print track and error message */
      if (!result) {
        printf("Track number: %i\n", i);
        printf("Track name: %s\n", tracks[i]);
      } else {
        printf("Track number: %i\nTrack name does not match pattern\n", i);
      }
    }
    regfree(&regex);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    find_track(search_for);
    find_track_regex(search_for);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "trout.h"
#include "minunit.h"

static int test1() {
  char   *res = icmpcode_v4(4);
  char *message = "test1 failed: icmpcode_v4(4) should return 'fragmentation required but DF bit set'";
  mu_assert(strcmp(res, "fragmentation required but DF bit set"), message);
  return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

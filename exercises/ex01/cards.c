/*
 * Program to evaluate face values.
 * Released under the Vegas Public License.
 * (c)2014 The College Blackjack Team.
 */

#include <stdio.h>
#include <stdlib.h>

int card_count(int val) {

  /* Check if the value is 3 to 6 */
  if ((val >= 3) && (val<= 6)) {
    return 1;
  }
  /* Otherwise check if the card was 10, J, Q, K */
  else if (val == 10) {
    return -1;
  }
  return 0;
}
void user_input(char *card_name) {
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}

void card_value(char *card_name) {
  int count = 0;
  while (card_name[0] != 'X') {
    user_input(card_name);
    int val = 0;
    switch (card_name[0]) {
      case 'K':
      case 'Q':
      case 'J':
        val = 10;
        break;
      case 'A':
        val = 11;
        break;
      case 'X':
        continue;
      default:
        val = atoi(card_name);
        if ((val < 1) || (val > 10)) {
          puts("I don't understand that value");
          continue;
        }
    }
    count += card_count(val);
    printf("Current count: %i\n", count);
  }
}

int main() {
  char card_name[3];
  card_value(card_name);
  return 0;
}

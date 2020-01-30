/*
 * Worked with Shreya Chowdhardy
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Adjusts the card count depending on the value inputed.
 * If the value is between 2 and 7, it will add 1 to the count.
 * If the value is equal to 10, it will subtract 1 from the count.
 *
 * val: the value of the card
 */
int card_count(int val) {

  if ((val >= 3) && (val<= 6)) {
    return 1;
  }
  else if (val == 10) {
    return -1;
  }
  return 0;
}

/*
 * Prompts user to input a card name
 * card_name: buffer where card_name is stored
 */
void user_input(char *card_name) {

  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}

/*
 * Determines the value of a card based on the user input.
 * After assigning value to the card, it determines if the count is adjusted
 *  or if the value is not recognized.
 * count: the count of cards
 * val: the value of the card
 */
void card_value(char *card_name) {

  int count = 0;
  int val = 0;
  while (card_name[0] != 'X') {
    user_input(card_name);
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

/*
 * Initializes length of card_name array and runs card_value.
 */
int main() {

  char card_name[3];
  card_value(card_name);
  return 0;
}

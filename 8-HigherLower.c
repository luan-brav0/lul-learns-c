// done by @luan-brav0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int guess;
  int lowest;
  int highest;
  int strikes = 0;

  printf("Enter Lower Limit: ");
  scanf("%d", &lowest);
  printf("Enter Upper Limit: ");
  scanf("%d", &highest);
  int secret = rand() % (highest - lowest + 1) + lowest;

  while (guess != secret && strikes < 3) {
    printf("Guess a number between %d and %d: ", lowest, highest);
    scanf("%d", &guess);

    if (guess < lowest) {
      printf("\tGuess is too low! Guess again...\n");
      continue;
    } else if (guess > highest) {
      printf("\tGuess is too high! Guess again...\n");
      continue;
    }

    if (guess != secret) {
      strikes++;
      printf("\tStrike %d!\n", strikes);
    }
  }

  if (guess == secret) {
    printf("\tYOU WON!\n You guessed it in %d tries\n", strikes);
  } else {
    printf("\tYOU LOSE!\n The number was %d\n", secret);
  }
  return 0;
}

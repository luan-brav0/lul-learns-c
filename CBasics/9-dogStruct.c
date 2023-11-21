#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char name[20];
  char *sound;
  int hunger;
  int fatigueFactor;
  bool big;
} Dog;

char dogSounds[][20] = {"bark", "woof"};

void initializeDog(Dog *d) {
  d->hunger = 0;

  printf("What is your dog's name? ");
  scanf("%s", d->name);

  char isBigBoi;
  do {
    printf("Is your dog a big boi? [y/n] ");
    scanf("%s", &isBigBoi);
  } while (isBigBoi != 'y' && isBigBoi != 'n');
  d->big = isBigBoi == 'y' ? true : false;

  int fatigueFactor;
  d->fatigueFactor = d->big ? 2 : 1;
  d->sound = d->big ? dogSounds[1] : dogSounds[0];
  return;
}

void printDogStats(Dog *d) {
  printf("Name: %s\n", d->name);
  printf("Hunger: %d\n", d->hunger);
  printf("Fatigue: %d\n", d->fatigueFactor);
  printf("Sound: %s\n", d->sound);
  printf("Size: %s\n", d->big == true ? "b i g b o i" : "smolboi");
  printf("\n");
  return;
}

void play(Dog *d) {
  if (d->hunger > 10) {
    printf("\t%s is too hungry to play!\n", d->name);
    return;
  }
  if (d->big) {
    printf("\t%s is playing fetch!\n", d->name);
  } else {
    printf("\t%s is playing with a toy!\n", d->name);
  }
  d->hunger += d->fatigueFactor;
  return;
}

void feed(Dog *d) {
  if (d->hunger <= 3) {
    printf("\t%s is not hungry to eat. Let's Play!\n", d->name);
    return;
  }
  printf("\t%s is eating...\n", d->name);
  d->hunger = 0;
  return;
}

void talk(Dog *d) {
  printf("\t%s says '%s, %s'!\n", d->name, d->sound, d->sound);
  return;
}

int main() {
  Dog usersDog;
  initializeDog(&usersDog);
  printDogStats(&usersDog);

  int action;
  do {
    printf("\nWhat would you like to do?\n");
    printf("1 - Play\n");
    printf("2 - Feed\n");
    printf("3 - Talk\n");
    printf("4 - Get Stats\n");
    printf("0 - Exit\n");
    scanf("%d", &action);
    switch (action) {
    case 1:
      play(&usersDog);
      break;
    case 2:
      feed(&usersDog);
      break;
    case 3:
      talk(&usersDog);
      break;
    case 4:
      printDogStats(&usersDog);
      break;
    case 0:
      printf("Goodbye!\n");
      break;
    }
  } while (action != 0);

  return 0;
}

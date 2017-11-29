#include <stdio.h>
#include <ctype.h>
#include "word.h"

void
Display_round (int attemptsLeft, Word *word)
{
  switch (attemptsLeft) {
  case 10:
    printf("\n\n\n\n\n\n");
    break;
  case 9:
    printf("\n\n\n\n\n_______\n");
    break;
  case 8:
    printf("\n|\n|\n|\n|\n|_____\n");
    break;
  case 7:
    printf("\n|\n|\n|\n|\n|_____\n");
    break;
  case 6:
    printf("______\n|/\n|\n|\n|\n|_____\n");
    break;
  case 5:
    printf("______\n|/  |\n|\n|\n|\n|_____\n");
    break;
  case 4:
    printf("______\n|/  |\n|   o\n|\n|\n|_____\n");
    break;
  case 3:
    printf("______\n|/  |\n|   o\n|   |\n|\n|_____\n");
    break;
  case 2:
    printf("______\n|/  |\n|   o\n|  -|-\n|\n|_____\n");
    break;
  case 1:
    printf("______\n|/  |\n|   o\n|  -|-\n|  /\n|_____\n");
    break;
  case 0:
    printf("______\n|/  |\n|   o\n|  -|-\n|  / \\\n|_____\n");
    break;
  }
  printf("\n\n> %s\n", Word_hidden(word));
}

char
Display_askChar ()
{
  char c;

  printf("Lettre à essayer ? ");
  do {
    scanf("%c", &c);
  } while (!isalpha(c));

  return toupper(c);
}

void
Display_alreadyTried (char guess)
{
  printf("\nVous avez déjà essayé cette lettre…\n");
}

void
Display_congrats (char guess)
{
  printf("\nOui ! La lettre '%c' est bien dans le mot.\n", guess);
}

void
Display_sorry (char guess)
{
  printf("\nNon… La lettre '%c' n'est pas dans le mot.\n", guess);
}

void
Display_won ()
{
  printf("\nGAGNÉ !\n");
}

void
Display_lost ()
{
  printf("\nPERDU…\n");
}

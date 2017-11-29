#ifndef DISPLAY_H___
#define DISPLAY_H___

#include "word.h"

void Display_round (int attemptsLeft, Word *guessed);
char Display_askChar ();
void Display_alreadyTried (char guess);
void Display_congrats (char guess);
void Display_sorry (char guess);
void Display_won ();
void Display_lost ();

#endif /* DISPLAY_H___ */

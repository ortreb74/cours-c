#include <stdlib.h>
#include <assert.h>
#include "charlist.h"
#include "word.h"
#include "display.h"
#include "pendu.h"

#include <stdio.h>

struct Pendu {
  Word *word;
  int attemptsLeft;
  CharList *attempts;
  CharList *goodGuesses;
};

Pendu *
Pendu_new ()
{
  Pendu *self = NULL;

  self = malloc(sizeof(*self));
  assert(self != NULL);

  self->word = Word_new();
  self->attemptsLeft = 10;
  self->attempts = CharList_nil();
  self->goodGuesses = Word_listCharacters(self->word);
  displayList(self->goodGuesses);
  return self;
}

void
Pendu_delete (Pendu *self)
{
  Word_delete(self->word);
  CharList_delete(self->attempts);
  CharList_delete(self->goodGuesses);
}

void
Pendu_round (Pendu *self)
{
  char guess;

  Display_round(self->attemptsLeft, self->word);
  guess = Display_askChar();

  if (CharList_has(self->attempts, guess)) {
    Display_alreadyTried(guess);
    return;
  }
  self->attempts = CharList_insert(self->attempts, guess);

  if (CharList_has(self->goodGuesses, guess)) {
    self->goodGuesses = CharList_remove(self->goodGuesses, guess);
    Word_uncoverCharacter(self->word, guess);
    Display_congrats(guess);
  }
  else {
    self->attemptsLeft--;
    Display_sorry(guess);
  }
}

void
Pendu_launch (Pendu *self) {  
  while (self->attemptsLeft > 0 && !CharList_isEmpty(self->goodGuesses)) {    
    Pendu_round(self);
  }

  Display_round(self->attemptsLeft, self->word);

  if (CharList_isEmpty(self->goodGuesses)) {
    Display_won();
  }
  else {
    Display_lost();
  }
}

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "charlist.h"
#include "word.h"

struct Word {
  int size;
  char original[20];
  char hidden[20];
};

Word *
Word_new ()
{
  Word *self = NULL;
  FILE *words = NULL;
  int count, w;

  self = calloc(1, sizeof(*self));
  assert(self != NULL);

  words = fopen(WORDS_FILE, "r");
  assert(words != NULL);

  srand(time(NULL));

  fscanf(words, "%d", &count);
  w = rand() % count;

  while (w > 0) {
    while (fgetc(words) != '\n');
    w--;
  }

  fscanf(words, "%s", (char *)&self->original);
  self->size = strlen(self->original);
  for (w = 0; w < self->size; w++) {
    self->hidden[w] = '_';
  }

  fclose(words);

  return self;
}

void
Word_delete (Word *self)
{
  free(self);
}

char *
Word_hidden (Word *self)
{
  return self->hidden;
}

CharList *
Word_listCharacters (Word *self)
{
  CharList *l = CharList_nil();
  int i;

  for (i = 0; i < self->size; i++) {
    l = CharList_insert(l, self->original[i]);
  }

  return l;
}

void
Word_uncoverCharacter (Word *self, char c)
{
  int i;

  for (i = 0; i < self->size; i++) {
    if (c == self->original[i]) {
      self->hidden[i] = c;
    }
  }
}

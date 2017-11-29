#ifndef WORD_H___
#define WORD_H___

#include "charlist.h"

#define WORDS_FILE "dict.txt"

typedef struct Word Word;

Word *Word_new ();
void Word_delete (Word *self);

char *Word_hidden (Word *self);

CharList *Word_listCharacters (Word *self);
void Word_uncoverCharacter (Word *self, char c);

#endif /* WORD_H___ */

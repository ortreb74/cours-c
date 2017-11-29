#ifndef PENDU_H___
#define PENDU_H___

typedef struct Pendu Pendu;

Pendu *Pendu_new ();
void Pendu_delete (Pendu *self);

void Pendu_launch (Pendu *self);

#endif /* PENDU_H___ */

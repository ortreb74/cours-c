#ifndef CHARLIST_H___
#define CHARLIST_H___

typedef struct CharList CharList;

CharList *CharList_nil ();
CharList *CharList_cons (char head, CharList *tail);
char      CharList_head (CharList *self);
CharList *CharList_tail (CharList *self);
void      CharList_delete (CharList *self);
int       CharList_isEmpty (CharList *self);

int       CharList_has (CharList *self, char c);
CharList *CharList_insert (CharList *self, char c);
CharList *CharList_remove (CharList *self, char c);

void displayList(CharList *self);

#endif /* CHARLIST_H___ */

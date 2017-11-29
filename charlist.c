#include <stdlib.h>
#include <assert.h>
#include "charlist.h"

#include <stdio.h>

struct CharList {
   char head;
   CharList *tail;
};

CharList * CharList_nil () {
  return NULL;
}

CharList * CharList_cons (char head, CharList *tail) {
  CharList *self;
  self = malloc(sizeof(*self));
  assert(self != NULL);
  self -> head = head;
  self -> tail = tail;
  return self; 
}

char
CharList_head (CharList *self)
{
return self -> head;
}

CharList *
CharList_tail (CharList *self)
{
return self -> tail;
}

void
CharList_delete (CharList *self)
{
  void free (void *self);
}

int
CharList_isEmpty (CharList *self)
{
  return (self == NULL);
}

/* ----- */

int
CharList_has (CharList *self, char c)
{
  while (self != NULL) {    
    //printf ("La liste contient : %c\n",self->head);
    if (self -> head == c) {      
      return 1;  
    }
    self = self->tail;  
  }
  
  return 0;
   
}

CharList *
CharList_insert (CharList *self, char c)
{
  if (CharList_has(self,c)) return self;
  
  self = CharList_cons(c,self);
  
  return self;
}

CharList *
CharList_remove (CharList *self, char c)
{
  CharList * cursor = self;
  CharList * prevCursor = NULL;

  while (cursor != NULL)
  {
    if (cursor -> head == c)
    {
      if (prevCursor == NULL) {
        cursor = self->tail;
        free(self);
        return cursor;
      }

      prevCursor -> tail = cursor -> tail;
      free(cursor);
      return self;
    } 

    prevCursor = cursor;
    cursor = cursor -> tail;
    
  }
  return self; // TODO
}

void displayList(CharList *self) {
  while (self != NULL) {
    printf ("%c",self->head);
    self = self->tail;  
  }
  printf ("\n");
}
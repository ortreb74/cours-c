#include "pendu.h"

int
main (int argc, char *argv[])
{
  Pendu *game;

  game = Pendu_new();
  Pendu_launch(game);
  Pendu_delete(game);
  
  return 0;
}

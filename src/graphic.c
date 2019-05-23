#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_draw.h>
#include <math.h>
#include "graphic.h"

/*
----------------------------------------------------------------------------
FONCTION : SdlPause()
----------------------------------------------------------------------------
DESCRIPTION : fonction perso pour mettre une fenètre sdl en attente d'un evenement
----------------------------------------------------------------------------
PARAMETERS :
  - void
----------------------------------------------------------------------------
RETURN : void
----------------------------------------------------------------------------
*/

void SdlPause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
        case SDL_QUIT:
          continuer = 0;
      }
    }
}

/*
----------------------------------------------------------------------------
FONCTION : SDL_Surface *SdlNewWindow(int x, int y, const char *title)
----------------------------------------------------------------------------
DESCRIPTION : ouvre une fenètre de la dimension voulue, couleur 32 bits,
              chargement dans la mémoire du GPU
----------------------------------------------------------------------------
PARAMETERS :
  -int x ; //regle la dimension de l'index des ordonnées
  -int y ; //regle la dimension de l'index des abscices
  -const char *title ; //défini le titre de la fenètre
----------------------------------------------------------------------------
RETURN :  SDL_Surface *screen
----------------------------------------------------------------------------
*/
SDL_Surface *SdlNewWindow(int x, int y, const char *title, Color c){
  if (SDL_Init(SDL_INIT_VIDEO)==-1){
    fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_Surface *screen = NULL;
  screen = SDL_SetVideoMode(x,y,32,SDL_HWSURFACE | SDL_RESIZABLE);
  if (screen == NULL)
  {
    fprintf(stderr, "Erreur lors du chargement du mode video : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_WM_SetCaption(title,NULL);
  Uint32 backgroundColor = SDL_MapRGB(screen->format,c.r,c.g,c.b);
  SDL_FillRect(screen,NULL,backgroundColor);
  SDL_Flip(screen);
  return screen;
}

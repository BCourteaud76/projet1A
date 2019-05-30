#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include <SDL/SDL.h>
#include "struct.h"
#include "Aliste.h"

#define LARGEUR 1700
#define HAUTEUR 1700
#define MARGIN 10

typedef struct _color{
  char r;
  char g;
  char b;
} Color;

typedef struct{
  Sint16 x;
  Sint16 y;
} Point;

void SdlPause();
SDL_Surface *SdlNewWindow(int x, int y, const char *title, Color c);
void homotetie(double *xa,double*ya,double*xb,double*yb,double a, double bx,double by);
void reseauGraphique(SDL_Surface *screen, T_SOMMET* graph, unsigned long len);
void itineraireGraphique(SDL_Surface *screen, T_SOMMET *graph,unsigned long len, ALIST path);
#endif

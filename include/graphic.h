#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include <SDL/SDL.h>


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

#endif

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_draw.h>
#include <math.h>
#include "struct.h"
#include "listeArc.h"
#include "graphic.h"
#include "Aliste.h"

void SdlPause()
  /*
  ----------------------------------------------------------------------------
  DESCRIPTION : fonction perso pour mettre une fenètre sdl en attente d'un evenement
  ----------------------------------------------------------------------------
  PARAMETERS :
    - void
  ----------------------------------------------------------------------------
  RETURN : void
  ----------------------------------------------------------------------------
  */
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


SDL_Surface *SdlNewWindow(int x, int y, const char *title, Color c){
  /*
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
  if (SDL_Init(SDL_INIT_VIDEO)==-1){
    fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_Surface *screen = NULL;
  printf("resolution %d x %d\n",x,y);
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

void coefficients(double *a,double *bx, double *by,T_SOMMET *graph, unsigned  long len){
  /*
  ----------------------------------------------------------------------------
  DESCRIPTION : calcul de coefficients pour l'homotétie
  ----------------------------------------------------------------------------
  PARAMETERS :
    -
  ----------------------------------------------------------------------------
  RETURN :
  ----------------------------------------------------------------------------
  */

  unsigned long i;
  double xmax,xmin,ymax,ymin;
  xmin = graph[0].x; xmax = graph[0].x;
  ymin = graph[0].y; ymax = graph[0].y;
  for(i=0;i<len;i++){
    /*
    if(graph[i].x<2.0){
      printf("FUCK %lu\n",i);
    }
    */
    if( xmin > graph[i].x){
      xmin = graph[i].x;
    }
    if( xmax < graph[i].x){
      xmax = graph[i].x;
    }
    if( ymin > graph[i].y){
      ymin = graph[i].y;
    }
    if( ymax < graph[i].y){
      ymax = graph[i].y;
    }
  }
  if((xmax-xmin) > (ymax-ymin)){
    *a = (LARGEUR-2*MARGIN)/(xmax-xmin);
  }
  else {
    *a = (HAUTEUR-2*MARGIN)/(ymax-ymin);
  }
  *bx = MARGIN-(*a)*xmin;
  *by = MARGIN -(*a)*ymin;
  //printf("xmax %lf, xmin %lf, ymax %lf, ymin %lf\n",xmax,xmin,ymax,ymin );
}
void homotetie(double *xa,double*ya,double*xb,double*yb,double a, double bx,double by){
  /*
  ----------------------------------------------------------------------------
  DESCRIPTION : trouve les rappport d'agrandissement pour l'affichage du graphe
  en fonction de la plus grande difference des coordonée en x ou y
  ----------------------------------------------------------------------------
  PARAMETERS :
    - double *xa :
    -
  ----------------------------------------------------------------------------
  RETURN : void
  ----------------------------------------------------------------------------
  */
  *xa = a * (*xa) + bx;
  *ya = HAUTEUR - (a * (*ya)+ by);
  *xb = a * (*xb) + bx;
  *yb = HAUTEUR - (a*(*yb)+ by);
}


void reseauGraphique(SDL_Surface *screen, T_SOMMET* graph, unsigned long len){
  /*
  ----------------------------------------------------------------------------
  DESCRIPTION : affiche graphiquement un réseau à partir d'un graphe
  ----------------------------------------------------------------------------
  PARAMETERS :
    -SDL_Surface *screen : pointeur SDL vers l'écran
    -T_SOMMET *graph
    -unsigned long len taille du graph

  ----------------------------------------------------------------------------
  RETURN : void
  ----------------------------------------------------------------------------
  */
  unsigned long i = 0;
  Liste h = NULL;
  double xa = 0,ya=0,xb = 0, yb=0;
  double a=0, bx=0, by =0;
  Uint32 color = SDL_MapRGB(screen->format,50,50,50);
  coefficients(&a,&bx,&by,graph,len);
  //printf("A =  %lf B= %lf \n", a, b);
  for(i=0; i<len ; i++){
    for(h = graph[i].voisins; !liste_vide(h); h = h->suiv){
      xa = graph[i].x;
      ya = graph[i].y;
      xb = graph[h->val.arrivee].x;
      yb = graph[h->val.arrivee].y;
      homotetie(&xa,&ya,&xb,&yb, a,bx,by);
      //printf("xa %lf ya %lf xb %lf yb %lf\n", xa ,ya, xb , yb);
      Draw_Line(screen, (Sint16)xa, (Sint16)ya, (Sint16)xb , (Sint16)yb, color);
    }
  }
  SDL_Flip(screen);
}

void itineraireGraphique(SDL_Surface *screen, T_SOMMET *graph,unsigned long len, ALIST path){
  /*
  ----------------------------------------------------------------------------
  DESCRIPTION :
  ----------------------------------------------------------------------------
  PARAMETERS :
    -
  ----------------------------------------------------------------------------
  RETURN :
  ----------------------------------------------------------------------------
  */

  ALIST p = NULL;
  double xa,ya,xb,yb,a,bx,by;
  Uint32 color = SDL_MapRGB(screen->format,64,64,255);
  coefficients(&a,&bx,&by,graph,len);
  for( p = path ; !Aliste_vide(p); p = p->suiv){
    //puts("cheh");
    xa = graph[p->val.indice].x;
    ya = graph[p->val.indice].y;
    xb = graph[p->val.path.indice].x;
    yb = graph[p->val.path.indice].y;
    homotetie(&xa,&ya,&xb,&yb,a,bx,by);
    //printf("xa %lf ya %lf xb %lf yb %lf",xa,ya,xb,yb);
      int o;
    for(o=0;o<5;o++){
      xa++;
      ya++;
      xb++;
      yb++;
    Draw_Line(screen, (Sint16)xa, (Sint16)ya, (Sint16)xb , (Sint16)yb, color);
  }
  SDL_Flip(screen);
  }

}

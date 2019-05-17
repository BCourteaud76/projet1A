#ifndef _STRUCT
#define _STRUCT



typedef struct { unsigned long arrivee; double cout; } T_ARC ;

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC;

typedef struct {
  char nom[100];
  char ligne[4];
  double x,y ;
  L_ARC voisins;
} T_SOMMET ;

<<<<<<< current
//typedef struct graph { T_SOMMET noeud; struct graph *suiv;}* GRAPHE;

#endif
=======
typedef struct { int arrivee; double cout; } T_ARC ;

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC;
>>>>>>> before discard

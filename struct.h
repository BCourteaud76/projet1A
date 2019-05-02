#include "struct.c"

typedef struct {
  char*nom;
  char* ligne;
  double x,
  double y;
  L_ARC voisins;
} GRAPHE;

typedef struct { char* nom; double x,y ; L_ARC voisins;} T_SOMMET ;

typedef struct { int arrivee; double cout; } T_ARC ;

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC;

typedef struct liste {
  struct liste* suiv;
  double distance;
    }* LISTE;

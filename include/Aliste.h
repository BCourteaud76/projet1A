#ifndef ALIST_H
#define ALIST_H
#define namelength 100

#include "struct.h"
typedef struct pt {
  unsigned long indice;
  char* nom;
} PATH ;

typedef struct node{
  char *name ;//pointeur vers une adresse résevé dans une cellule T_SOMMET du graphe
  unsigned long indice; // indice du sommet dans le graphe
  double weight;
  PATH path;
  double cbwght; //combined weight
} NODE;

typedef struct Alist{ NODE val; struct Alist *suiv;} *ALIST;


ALIST creer_Aliste();
int Aliste_vide(ALIST l);
ALIST Aliste_ajout_tete(NODE node, ALIST l);
ALIST Aliste_ajout_queue(NODE node, ALIST l);
ALIST Aliste_supprimer_tete(ALIST l);
int taille_Aliste(ALIST l);
void visualiser_Aliste(ALIST l);
ALIST liberer_Aliste(ALIST l);

ALIST rechercheAliste(ALIST l, unsigned long e, ALIST prevCell);
void supprimeCellule(ALIST cell, ALIST prevCell);
ALIST AlisteTriInsertion(ALIST l, NODE node);

ALIST augmenteLO(ALIST LO, NODE noeud);


#endif

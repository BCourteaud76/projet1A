#ifndef ALIST_H
#define ALIST_H
#define namelength 100

typedef struct node{
  char *name //pointeur vers une adresse résevé dans une cellule T_SOMMET du graphe
  unsigned double indice;
  double weight;
  T_SOMMET path;
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

ALIST augmenteLO(ALIST LO, NODE noeud);


#endif

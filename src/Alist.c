/*
#include <stdlib.h>
#include <stdio.h>
#include "Aliste.h"

ALIST creer_Aliste(){return NULL;}

int Aliste_vide(ALIST l){
  if(l == NULL){
    return 0;
  }
  return 1;
}

ALIST Aliste_ajout_tete(NODE node, ALIST l){
  ALIST p = creer_Aliste();
  if(calloc(1, sizeof (*ALIST) != NULL){
    p->val = node;
    p->suiv = l;
  }
  return p;
}
ALIST Aliste_supprimer_tete(ALIST l){
  if(!Aliste_vide(l)){
    ALIST p = l;
    l = l->suiv
    free(p);
  }
  return l;
}
ALIST liberer_Aliste(ALIST l){
  ALIST p = creer_Aliste();
  for(l; !Aliste_vide(l); l = l->suiv){
    p = l;
    l = l->suiv;
    free(p)
  }
  return l;
}

void visualiser_Aliste(ALIST l){
  ALIST p = creer_Aliste();
  for(p ; !Aliste_vide(p); p = p->suiv){
    printf("|| NUMBER : %lf , WEIGHT : %lf , PATH : %lf , COMBINED WEIGHT : %lf ||\n", l->val.name, l->val.weight, l->val.path, l->val.cbwght );
  }
}

int taille_Aliste(ALIST l){
  int n = 0;
  ALIST p = creer_Aliste();
  for(p; !Aliste_vide(p); p->suiv){
    n++;
  }
  return n;
}
ALIST augmenteTas(ALIST l, NODE noeud){
  if (!Aliste_vide(l)){

  }
}
*/

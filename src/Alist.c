#include <stdlib.h>
#include <stdio.h>
#include "Aliste.h"

ALIST creer_Aliste(){return NULL;}

int Aliste_vide(ALIST l){
  return l == NULL;
}

ALIST Aliste_ajout_tete(NODE node, ALIST l){
  printf("entrée dans Aliste_ajout_tete\n");
  ALIST p;// = creer_Aliste();
  p= (ALIST) calloc(1, sizeof (ALIST));
  if (p != NULL){
    printf("ajout_tete 3\n");
    printf("node.name : %s \n",node.name);
    printf("p->val.name : %s \n",p->val.name);
    p->val.name="lo";
    printf("p->val.name : %s \n",p->val.name);
    p->suiv = l;
    printf("ajout_tete 4\n");
    //p->val = node;

    p->val.name = node.name;
    p->val.indice = node.indice;
    p->val.weight = node.weight;
    p->val.path = node.path;
    p->val.cbwght = node.cbwght;

    printf("ajout_tete 5\n");
  }
  else {
    printf ("problème d'allocation mémoire dans Aliste_ajout_tete");
    exit(1);
  }
  printf("retour fonction Aliste_ajout_tete : %p",p);
  return p;
}

/*
----------------------------------------------------------------------------
FONCTION : Aliste_supprimer_tete
----------------------------------------------------------------------------
DESCRIPTION : Supprime l'élément en tête de liste
----------------------------------------------------------------------------
PARAMETERS :
  -ALIST l
----------------------------------------------------------------------------
RETURN : ALIST l : la liste sans son premier élément
----------------------------------------------------------------------------
*/

ALIST Aliste_supprimer_tete(ALIST l){
  if(!Aliste_vide(l)){
    ALIST p = l;
    l = l->suiv;
    free(p);
  }
  return l;
}
ALIST liberer_Aliste(ALIST l){
  ALIST p = creer_Aliste();
  for(l=l; !Aliste_vide(l); l = l->suiv){
    p = l;
    l = l->suiv;
    free(p);
  }
  return l;
}

void visualiser_Aliste(ALIST l){
  ALIST p = creer_Aliste();
  for(p=l ; !Aliste_vide(p); p = p->suiv){
    printf("|| NUMBER : %s , WEIGHT : %lf , PATH : %s , COMBINED WEIGHT : %lf ||\n", l->val.name, l->val.weight, l->val.path.nom, l->val.cbwght );
  }
}

int taille_Aliste(ALIST l){
  int n = 0;
  ALIST p = creer_Aliste();
  for(p=l; !Aliste_vide(p); p = p->suiv){
    n++;
  }
  return n;
}

/*
----------------------------------------------------------------------------
FONCTION : augmenteLO
----------------------------------------------------------------------------
DESCRIPTION : realise un tri par insertion et remplace les noeuds si le une
meilleure valeur est trouvée
----------------------------------------------------------------------------
PARAMETERS :
  - ALIST l
  - NODE noeud
----------------------------------------------------------------------------
RETURN : retourne une liste (ALIST) formant un tas contenant le nouveau noeud
----------------------------------------------------------------------------
*/

ALIST augmenteLO(ALIST LO, NODE noeud){
  ALIST p = creer_Aliste();
  if (Aliste_vide(LO)){
    LO = Aliste_ajout_tete(noeud, LO);
    return LO;

  }

  for(p=LO; !Aliste_vide(p); p= p->suiv){

    //suppression de l'ancien noeud si identique avec un meilleur cout
    if( ((p->suiv)->val).indice == noeud.indice && ((p->suiv)->val).cbwght > noeud.cbwght){
      ALIST h = p->suiv;
      p->suiv = (p->suiv)->suiv;
      free(h);
    }

    //ajout du noeud au bon endroit
    if( ((p->suiv)->val).cbwght > noeud.cbwght ){
      ALIST l = creer_Aliste();
      if( (l=calloc(1, sizeof(ALIST *))) != NULL){
        l->suiv = (p->suiv)->suiv;
        p->suiv = l;
      }
      else {
        puts("pb lors de l'allocation dynamique augmenteLO()");
        return LO;
      }
    }
  }
  return LO;
}

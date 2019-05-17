#include <stdlib.h>
#include <stdio.h>
#include "Aliste.h"

ALIST creer_Aliste(){return NULL;}

int Aliste_vide(ALIST l){
  return l == NULL;
}

ALIST Aliste_ajout_tete(NODE node, ALIST l){
  ALIST p = creer_Aliste();
  if( (p=calloc(1, sizeof (*p))) != NULL){
    p->val = node;
    p->suiv = l;
  }
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

ALIST Aliste_ajout_queue(NODE node, ALIST l){
  if (Aliste_vide(l)){
    return Aliste_ajout_tete(node, l);
  }
  ALIST p = l, u =NULL, q = NULL;
  if( (q=calloc(1, sizeof(*q))) != NULL ){
    q->val=node;
  }
  while(!Aliste_vide(p)){
    u = p;
    p=p->suiv;
  }
  u->suiv = q;
  return l;
}

ALIST liberer_Aliste(ALIST l){
  ALIST p = creer_Aliste();
  for(l; !Aliste_vide(l); l = l->suiv){
    p = l;
    l = l->suiv;
    free(p);
  }
  return l;
}

void visualiser_Aliste(ALIST l){
  ALIST p = creer_Aliste();
  for(p=l ; !Aliste_vide(p); p = p->suiv){
    printf("||\nSommet n° %lu : %s depuis %s WEIGHT : %lf , COMBINED WEIGHT : %lf \n||\n", l->val.indice, l->val.name,l->val.path.nom, l->val.weight,  l->val.cbwght  );
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
  char flag = 0;

  if (Aliste_vide(LO)){
    puts("#1");
    LO = Aliste_ajout_tete(noeud, LO);
    return LO;
  }
  puts("#2");

  for(p=LO; !Aliste_vide(p); p= p->suiv){
    puts("#3");
    if(Aliste_vide(p)){
      puts("that's not suppose to append ouuups");
    }
    //changement du cntenu de l'ancien noeud si identique avec un meilleur cout
    if( ((p->val).indice == noeud.indice) && ((p->val).cbwght > noeud.cbwght)){
      p->val = noeud;
      puts("+++++++++++");
    }
    //traitement du cas ou il n'y a qu'un élément dans la liste
    if(Aliste_vide(p->suiv)){
      puts("#4");
      ALIST h = creer_Aliste();
      if ( (h=calloc(1,sizeof(*h))) == NULL ){
        printf("probleme d'allocation #1");
        return LO;
      }
      else if(noeud.cbwght > (p->val).cbwght){
        puts("#5");
        h->val = noeud;
        p->suiv = h;
        h->suiv = NULL;
      }
      else {
        puts("#6");
        h->val=p->val;
        p->val = noeud;
        p->suiv = h;
        h->suiv = NULL;
      }
    }
    //ajout du noeud au bon endroit
    if( ( (p->val).cbwght > noeud.cbwght ) && ( flag == 0 ) ){
      puts("#7");
      flag = 250;
      printf("soin %s\n", noeud.name);
      ALIST l = creer_Aliste();
      if( (l=calloc(1, sizeof(*l))) != NULL){
        l->val = p->val;
        p->val = noeud;
        l->suiv = (p->suiv)->suiv;
        p->suiv = l;
      }
      else {
        puts("pb lors de l'allocation dynamique augmenteLO()");
        return LO;
      }
    }
  }
  //traitons le cas où il n'y a qu'un élément dans LO

  return LO;
}

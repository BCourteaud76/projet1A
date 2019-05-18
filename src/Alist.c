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
  if(!Aliste_vide(l)){
    l = liberer_Aliste(Aliste_supprimer_tete(l));
  }
  return l;
}

void visualiser_Aliste(ALIST l){
  ALIST p = creer_Aliste();
  for(p=l ; !Aliste_vide(p); p = p->suiv){
    printf("||n° %lu : %s||via n° %lu : %s||WEIGHT : %lf , COMBINED WEIGHT : %lf||\n\n", p->val.indice, p->val.name,p->val.path.indice,p->val.path.nom, p->val.weight,  p->val.cbwght  );
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
FONCTION : ALIST rechercheAliste(ALIST liste, unsigned long e)
----------------------------------------------------------------------------
DESCRIPTION : recherche la présence d'un (NODE) élément d'un certain (unsigned long)
indice dans une ALIST et retourne sont addresse
----------------------------------------------------------------------------
PARAMETERS :
  - ALIST liste : liste dans laquelle on effectue la recherche
  - unsigned long e : élément à rechercher
----------------------------------------------------------------------------
RETURN : ALIST : addresse de l'élément dans la liste, NULL si absent
          prev contient l'addresse avant l'élément recheché NULL si innexistant
----------------------------------------------------------------------------
*/
ALIST rechercheAliste(ALIST liste,unsigned long e, ALIST prevCell){
  ALIST p = creer_Aliste();
  for(p = liste; !Aliste_vide(p);p=p->suiv){
    if(e == p->val.indice){
      return p;
    }
    prevCell = p;
  }
  prevCell = NULL;
  return p;
}

void supprimeCellule(ALIST cell,ALIST prevCell){
  ALIST p = creer_Aliste();
  if(prevCell == NULL && cell == NULL){
    //ne rien faire (nos paramètres sont innexistants)
    return;
  }
  else if(cell == NULL){
    //ne rien faire car la cellule à supprimer n'éxiste pas
    return;
  }
  else if(prevCell==NULL){
    //il n'a pas de cellule précedente
    p = cell;
    cell = cell -> suiv;
    free(p);
    return;
  }
  else {
    prevCell->suiv = cell->suiv;
    free(cell);
    prevCell=NULL;
    return;
  }
}

ALIST AlisteTriInsertion(ALIST l, NODE node){
  puts("#0");

  if (Aliste_vide(l)){
    puts("#1");
    l = Aliste_ajout_tete(node, l);
    return l;
  }

  ALIST p = creer_Aliste();
  for(p = l; !Aliste_vide(p); p = p->suiv){
    puts("#2");
    if(node.cbwght < p->val.cbwght ){
      puts("#3");
      ALIST h = creer_Aliste();
      if( (h=calloc(1, sizeof(*h))) != NULL){
        puts("#4");
        h->val = p->val;
        p->val = node;
        h->suiv = p->suiv;
        p->suiv = h;
        return l;
      }
      else{
        puts("probleme allocation dynamique");
      }
    }
    else if (p->suiv==NULL){
      ALIST h = creer_Aliste();
      if( (h=calloc(1,sizeof(*h))) != NULL){
        puts("#6");
        h->val = node;
        h->suiv = p->suiv;
        p->suiv = h;
        return l;
      }
    }
  }
  puts("#6");
  return l;
}




/*
----------------------------------------------------------------------------
 !!!!!!!!!!!!!!!!!!!!!!!!!!NON FONCTIONNELLE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
FONCTION : ALIST augmenteLO(ALIST LO, NODE noeud)
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
  printf("LO : ajout du noeud n°%lu %s",noeud.indice, noeud.name);
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
    //suppression de la cellule si elle possede la meme etiquette que noeud
    //avec un meilleur cout
    if( ((p->val).indice == noeud.indice) && ((p->val).cbwght > noeud.cbwght)){
      puts("#8");
      ALIST h = creer_Aliste();
      p->val= p->suiv->val;
      h = p->suiv;
      p->suiv = p->suiv->suiv;
      free(h);
    }
    else if (p->val.indice == noeud.indice && p->val.cbwght <= noeud.cbwght){
      puts("#11");
      //ne rien Faire
      return LO;
    }

    //ajout du noeud au bon endroit
    if( ( (p->val).cbwght > noeud.cbwght ) && ( flag == 0 ) ){
      //ajout en p
      puts("#7");
      flag = 250;
      ALIST l = creer_Aliste();
      if( (l=calloc(1, sizeof(*l))) != NULL){
        puts("#9");
        l->val = p->val;
        p->val = noeud;
        l->suiv = p->suiv;
        p->suiv = l;
      }
      else {
        puts("pb lors de l'allocation dynamique augmenteLO()");
        return LO;
      }
    }
    else if(flag == 0 && p->suiv == NULL) {
      //ajout derriere p
      flag = 250;
      ALIST h = creer_Aliste();
      puts("#10");
      if((h=calloc(1,sizeof(*h))) != NULL){
      h->val = noeud;
      h->suiv = p->suiv;
      p->suiv = h;
      }
      else{
        puts("pb lors de l'allocation dynamique augmenteLO()");
        return LO;
      }
    }
  }
  //traitons le cas où il n'y a qu'un élément dans LO

  return LO;
}

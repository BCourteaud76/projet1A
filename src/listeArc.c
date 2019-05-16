#include <stdio.h>
#include <stdlib.h>
#include "listeArc.h"
Liste creer_liste() { return NULL; }

int liste_vide(Liste l) { return l==NULL; }

Liste ajout_tete(ELEMENT arc, Liste l) { Liste p=NULL;
  if ( (p=calloc( 1, sizeof (*p)))!=NULL)  { p->val.arrivee=arc.arrivee; p->val.cout=arc.cout; p->suiv=l; }
  return p;
}

Liste supprimer_tete(Liste l) {
  if (!liste_vide(l)) {
    Liste p=l;
    l=l->suiv;
    free(p);
    return l;
  }
  return NULL;
}
/*
void visualiser_liste(Liste l) { Liste p=NULL;
  for (p=l; !liste_vide(p); p=p->suiv) affiche_carte_visible(&(p->val));
  puts("");
}
*/

Liste liberer_liste(Liste l) {
  if (!liste_vide(l)) {
    l = liberer_liste(supprimer_tete(l));
  }
  return l;
}

Liste ajout_queue(ELEMENT arc, Liste l) {

  if (liste_vide(l)) {
		return ajout_tete(arc, l);
	}
	Liste p=l, u = NULL;
	Liste q;
  if ( (q=calloc( 1, sizeof (*q)))!=NULL)  { q->val=arc;}

	while (!liste_vide(p)) {
    u = p;
		p=p->suiv;
	}
	u->suiv=q;
	return l;
}

/*
----------------------------------------------------------------------------
FONCTION : taille_liste
----------------------------------------------------------------------------
DESCRIPTION : compte et retourne le nombre d'élément dans la liste
----------------------------------------------------------------------------
PARAMETERS :
  - Liste l
----------------------------------------------------------------------------
RETURN : nb délément dans la liste
----------------------------------------------------------------------------
*/

int taille_liste(Liste l) {
  int n;

  Liste p;
  p = l;
  n=0;
  while(!liste_vide(p)){
    p = p->suiv;
    n += 1;
  }
  return n;
}

/*
----------------------------------------------------------------------------
FONCTION : recherche_liste
----------------------------------------------------------------------------
DESCRIPTION : recherche un élément du type carte dans une liste
----------------------------------------------------------------------------
PARAMETERS :
  - ELEMENT c
  - Liste l
----------------------------------------------------------------------------
RETURN : retourne le pointeur sur le maillon contenant la carte si cette dernière
 est présente, NULL sinon.
----------------------------------------------------------------------------
*/

Liste recherche_liste(ELEMENT arc, Liste l) {
  Liste p = l;

  while (!liste_vide(p)){

    if( p->val.arrivee == arc.arrivee&& p->val.cout == arc.cout){

        return p;
    }
      p = p->suiv;
  }
  return NULL;
}

Liste concat(Liste l1, Liste l2) {
  if (liste_vide(l1)) {
		return l2;
	}
  if (liste_vide(l2)){
    return l1;
  }
  Liste res;
  res = copie(l1);
	Liste p=res;
  Liste q = NULL;
	while (!liste_vide(p)) {
    q = p ;
		p=p->suiv;
	}
	q->suiv=l2;
	return res;
}

Liste copie(Liste l) {
  Liste p = l, q = creer_liste();
	while (!liste_vide(p)) {
		q=ajout_queue(p->val, q);
		p=p->suiv;
	}
	return q;
}

Liste supprimen(int n, Liste l) {
  if (n==0) {
    return supprimer_tete(l);
  }
  Liste p = l;
  Liste q;
  int i;
  for (i = 0; i<n-1; i++) {
    if (liste_vide(p)) {
      return l;
    }
    p=p->suiv;
  }
  if (!liste_vide(p) && !liste_vide(p->suiv)) {
    q=p->suiv;
    p->suiv = (p->suiv)->suiv;
    free(q);
  }
  return l;
}

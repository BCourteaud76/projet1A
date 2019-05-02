#ifndef _LISTE
#define _LISTE
#include "carte.h"

typedef struct _liste {
  CARTE val;
  struct _liste * suiv;
}* Liste;

Liste creer_liste();
int liste_vide(Liste l);
Liste ajout_tete(CARTE c, Liste l);
Liste supprimer_tete(Liste l);
int taille_liste(Liste l);
Liste recherche_liste(CARTE c, Liste l);
void visualiser_liste(Liste l);
Liste liberer_liste(Liste l);
Liste ajout_queue(CARTE c, Liste l);
Liste copie(Liste l);
Liste concat(Liste l1, Liste l2);
Liste supprimen(int n, Liste l);
#endif

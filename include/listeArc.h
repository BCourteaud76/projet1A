#ifndef _LISTE
#define _LISTE

#include "struct.h"

typedef T_ARC ELEMENT;
typedef L_ARC Liste;

Liste creer_liste();
int liste_vide(Liste l);
Liste ajout_tete(ELEMENT arc, Liste l);
Liste supprimer_tete(Liste l);
int taille_liste(Liste l);
Liste recherche_liste(ELEMENT arc, Liste l);
void visualiser_liste(Liste l);
Liste liberer_liste(Liste l);
Liste ajout_queue(ELEMENT arc, Liste l);
Liste copie(Liste l);
Liste concat(Liste l1, Liste l2);
Liste supprimen(int n, Liste l);

#endif

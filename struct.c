LISTE creer_liste() {
  liberer_liste p;
  if ( (p=calloc( 1, sizeof (LISTE)))!=NULL)  { p->suiv=NULL; }
  return p;
}

int liste_vide(LISTE l) {
  if (l==NULL) return 1;
  else return 0;
}

LISTE ajout_tete(ELEMENT c, LISTE l) { LISTE p=NULL;
  if ( (p=calloc( 1, sizeof (*p)))!=NULL)  { p->distance=c; p->suiv=l; }
  return p;
}

LISTE supprimer_tete(LISTE l) {
  if (!liste_vide(l)) { LISTE p=l;
    l=l->suiv; free(p);
  }
  return l;
}

void visualiser_liste(LISTE l) { LISTE p = creer_liste();
  for (p=l; !liste_vide(p); p=p->suiv) affiche_carte(&(p->distance));
  puts("");
}

LISTE liberer_liste(LISTE l) {
  LISTE s=l;
  while ( liste_vide(s)) {
    s=supprimer_tete(l);
  }
  return creer_liste();
}

LISTE ajout_queue(ELEMENT distance, LISTE l) {
  LISTE parcours = l;
  while(! liste_vide(parcours->suiv)) {
    parcours=parcours->suiv;
  }
  LISTE p= creer_liste();
  p->distance= distance;
  parcours->suiv=p;
  return l;
}

int taille_liste(LISTE l) {
  int i = 0;
  LISTE ad_l = l;
  while (!liste_vide(ad_l)) {
    ad_l=ad_l->suiv;
    i++;
  }
  return i;
}

LISTE recherche_liste(ELEMNT c, LISTE l) {
  if (liste_vide(l)) return l;
  LISTE parcours=l;
  while((parcours->distance !=c && !liste_vide(parcours->suiv)){
    parcours=parcours->suiv;
  }
  return parcours->suiv;
}

LISTE concat(LISTE l1, LISTE l2) {
  LISTE sui  = l1;
  while (liste_vide(sui->suiv)) {
    sui=sui->suiv;
  }
  sui->suiv = l2;
  return l1;
}

LISTE copie(LISTE l) {
  LISTE parcours=l;
  LISTE cop = creer_liste();
  while (liste_vide(parcours->suiv)) {
    cop = ajout_queue(parcours->distace, cop);
    parcours = parcours->suiv;
  }
  return cop;
}

LISTE supprimen(int n, LISTE l) {
  LISTE element=l;
  int i;
  for (i=0 ; i>n-1 ; i++){
    element=element->suiv;
  }
  LISTE asupp=element->suiv;
  element->suiv = (element->suiv)->suiv;
  free(asupp);
}

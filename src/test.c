#include"hach.h"
#include <stdio.h>
#include "listeArc.h"

void essaiTableHachage(){
  char* fichier="metroetu.csv";
  HACH* table=remplirTabHach(fichier);
  char stationcherchee[100];
  printf("entrez la station cherchée : \n");
  gets(stationcherchee);
  unsigned long indice;
  indice = rechercheStation(stationcherchee,table);
  //printf("son indice est : %ld\n",indice);

  freeTable(table);

}

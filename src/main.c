#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Aliste.h"
#include "graphe.h"
#include "fct.h"
#include "Astar.h"
#include "hach.h"

int main (){

  char* fichier="metroetu.csv";
  HACH* table=remplirTabHach(fichier);
  char stationcherchee[100];
  printf("entrez la station cherchée : \n");
  gets(stationcherchee);
  unsigned long indice;
  indice = rechercheStation(stationcherchee,table);
  printf("son indice est : %ld\n",indice);
  
  freeTable(table);
  /*
  GRAPHE graphe= NULL;
  ALIST path = NULL;
  unsigned long len =0;
  unsigned long a =0, d=0;
  graphe = lectureFichier("metroetu.csv", &len);
  //afficheGraphe(graphe, len);
  char stationcherchee[100];
  char* fichier="metroetu.csv";
  HACH* table=remplirTabHach(fichier);
  do {
    puts("entrez la station de départ cherchée :");
    gets(stationcherchee);
    d = rechercheStation(stationcherchee,table);
  } while (d==0);
  do {
    puts("entrez la station d'arrivée cherchée :");
    gets(stationcherchee);
    a = rechercheStation(stationcherchee,table);
  } while (a==0);
  printf("%ld %ld\n", d, a);
  free(table);
  path = Astar(graphe, d , a);
  puts("MAIIIIIN");
  visualiser_Aliste(path);
  liberer_Aliste(path);
  libereGraphe(graphe, len);
  /**/
  return 0;
}

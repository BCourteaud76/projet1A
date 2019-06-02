#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Aliste.h"
#include "graphe.h"
#include "fct.h"
#include "Astar.h"
#include "hach.h"

int main (){
  GRAPHE graphe= NULL;
  ALIST path = NULL;
  unsigned long len =0;
  unsigned long a =0, d=0;
  graphe = lectureFichier("metroetu.csv", &len);
  //afficheGraphe(graphe, len);
  /*
  //ancienne version
  puts("entrez le sommet de départ");
  scanf("%lu", &d);
  puts("entrez le sommet d'arrivée");
  scanf("%lu", &a);
  */
  char stationcherchee[100]={0};
  char* fichier="metroetu.csv";
  HACH* table=remplirTabHach(fichier);
  do {
    puts("entrez la station de départ cherchée :");
    scanf("%[^\n]",stationcherchee);
    clean_stdin();
    d = rechercheStation(stationcherchee,table, len);
  } while (d==0);
  do {
    puts("entrez la station d'arrivée cherchée :");
    scanf("%[^\n]",stationcherchee);
    clean_stdin();
    a = rechercheStation(stationcherchee,table,len);
  } while (a==0);
  printf("%ld %ld\n", d, a);
  freeTable(table, len);
  path = Astar(graphe, d , a);
  puts("MAIIIIIN");
  visualiser_Aliste(path);
  liberer_Aliste(path);
  libereGraphe(graphe, len);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Aliste.h"
#include "graphe.h"
#include "fct.h"
#include "Astar.h"

int main (){
  GRAPHE graphe= NULL;
  //ALIST path = NULL;
  unsigned long len =0;
  graphe = lectureFichier("data/metroetu.csv", &len);
  printf("+++ WESH ALORS %s +++\n", graphe[0].nom);
  printf("len = %lu\n", len);
  afficheGraphe(graphe, len);

  //path = Astar(graphe, 10 , 100);
  //visualiser_Aliste(path);
  free(graphe);
  return 0;
}

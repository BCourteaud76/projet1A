#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Aliste.h"
#include "graphe.h"
#include "fct.h"
#include "Astar.h"

int main (){
  GRAPHE graphe= NULL;
  ALIST path = NULL;
<<<<<<< HEAD
  unsigned long len =0;  //long avant mais problème
  graphe = lectureFichier("data/metroetu.csv", &len);
  printf("+++ WESH ALORS %s +++\n", graphe[0].nom);
  printf("len = %ld \n", len);
  afficheGraphe(graphe, len);
  printf("graphe : %p \n", graphe);
  //path = Astar(graphe, 10 , 100);
  //visualiser_Aliste(path);
  free(graphe);
  return 0;
}
=======
  unsigned long len =0;
  graphe = lectureFichier("metroetu.csv", &len);
  //afficheGraphe(graphe, len);
>>>>>>> 1e11decbdaaf08c16e29dd6acfe4f4333eb8e503

  path = Astar(graphe, 0 , 676);
  visualiser_Aliste(path);
  free(graphe);
}

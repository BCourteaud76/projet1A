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
  HACH table=remplirTabHach(fichier);
  freeTable(table);
  /*
  GRAPHE graphe= NULL;
  ALIST path = NULL;
  unsigned long len =0;
  unsigned long a =0, d=0;
  graphe = lectureFichier("metroetu.csv", &len);
  //afficheGraphe(graphe, len);
  puts("entrez le sommet de départ");
  scanf("%lu", &d);
  puts("entrez le sommet d'arrivée");
  scanf("%lu", &a);
  path = Astar(graphe, d , a);
  puts("MAIIIIIN");
  visualiser_Aliste(path);
  liberer_Aliste(path);
  libereGraphe(graphe, len);
*/
  return 0;
}

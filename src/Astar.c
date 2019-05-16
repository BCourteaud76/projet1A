#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "graphe.h"

/*toutes les fonctions sur les listes adaptée à la structure NODE (voir algo.h)
commencent par la capitale A*/


double distanceEuclidienne(T_SOMMET a, T_SOMMET b){
    return sqrt((abs(a.x-b.x)+ abs (a.y-b.y))/2);
}

/*
----------------------------------------------------------------------------
FONCTION : algoAstar
----------------------------------------------------------------------------
DESCRIPTION :
----------------------------------------------------------------------------
PARAMETERS :
  - graph : le graphe contruit après lecture des fichiers contenant la carte
  - d : indice du sommet de départ dans le graphe
  - a : indice du sommet d'arrivée dans le graphe
----------------------------------------------------------------------------
RETURN : La liste de type ALIST (voir algo.h) contenant tout les sommets
retenus, on en extrait le plus court chemin
----------------------------------------------------------------------------
*/
ALIST Astar(GRAPHE graph,unsigned int d, unsigned int a){
  //liste contenant les noeuds visités
  ALIST LF = creer_Aliste();
  //
  ALIST LO = creer_Aliste();
  NODE node;
  int i;

  node.name = graph[d].name;
  node.weight = 0;
  node.path = graph[d];
  node.cbwght = distanceEuclidienne;
  LF = Aliste_ajout_tete(node ,LF );
  L_ARC listeArc=NULL;
  for(listeArc = graph[d].voisins; !liste_vide(listeArc); listeArc = listeArc->suiv){
    
  }





  }
}

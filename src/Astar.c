#include <math.h>
#include <stdlib.h>
#include "struct.h"
#include "Aliste.h"

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
ALIST Astar(GRAPHE graph,unsigned double d, unsigned double a){
  //liste contenant les noeuds visités
  ALIST LF = creer_Aliste();
  //
  ALIST LO = creer_Aliste();
  NODE node1,node2;
  int i;
  unsigned double s;//sommet courant
  s = d;

  node2.indice = d;
  node2.name = graph[d].name;
  node2.weight = 0;
  node2.path = graph[d];
  node2.cbwght = distanceEuclidienne(graph[d], graph[a]);

  LF = Aliste_ajout_tete(node,LF); //ajout du noeud de départ dans la liste finale

  while(node2.indice != a)*
  {
    s = node2.indice; //s devient le dernier sommet ajouté dans LF
    L_ARC listeArc=NULL;
    for(listeArc = graph[s].voisins; !liste_vide(listeArc); listeArc = listeArc->suiv)
    {
      node1.indice = (listeArc->val).arrivee;
      node1.name = graph[node1.indice].name;//nom du sommet cible
      node1.weight = (listeArc->val).cout + node2.weight;
      node1.path = graph[s];
      node1.cbwght = node1.weight + distanceEuclidienne(graph[node1.indice], graph[a]);
      LO = seekAndReplace(LO, node1);
    }
    LO = augmenteTas(LO,node1);
    node1 = descendreTas(LO);
    node2 = node1;
    LF = Aliste_ajout_tete(node1, LF );
  }
  return LF;
}

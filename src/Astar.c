#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Aliste.h"
#include "graphe.h"
#include "listeArc.h"
#include "Astar.h"


double distanceEuclidienne(T_SOMMET a, T_SOMMET b){
  /*
  ----------------------------------------------------------------------------
  DESCRIPTION : calcul la distance euclidienne entre deux sommets
  ----------------------------------------------------------------------------
  PARAMETERS :
    - T_SOMMET a;
    - T_SOMMET b;
  ----------------------------------------------------------------------------
  RETURN : la distance euclidenne 
  ----------------------------------------------------------------------------
  */

    return sqrt((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
}


ALIST Astar(GRAPHE graph,unsigned long d, unsigned long a){
  /*
  ----------------------------------------------------------------------------
  DESCRIPTION : determine le plus court chemin et le retourne sous la forme
  d'une ALIST
  ----------------------------------------------------------------------------
  PARAMETERS :
    - graph : le graphe construit après lecture des fichiers contenant la carte
    - d : indice du sommet de départ dans le graphe
    - a : indice du sommet d'arrivée dans le graphe
  ----------------------------------------------------------------------------
  RETURN : La liste de type ALIST (voir Alsite.h) contenant tout les sommets
  retenus (LF).
  On peut en extraire l'itinéraire à l'aide de la fonction
  ALIST intineraire(ALIST LF);
  ----------------------------------------------------------------------------
  */
  //liste contenant les noeuds visités
  ALIST LF = creer_Aliste();
  //liste ouverte
  ALIST LO = creer_Aliste();
  //un pointeur pour la fonction supprimeCellule (AList.h)
  ALIST prevCell = creer_Aliste();
  ALIST cell = NULL;
  NODE node1,node2;
  unsigned long s;//sommet courant
  s = d;
  //char str[10];

  node2.indice = d;
  node2.name = graph[d].nom;
  node2.weight = 0;
  node2.cbwght = distanceEuclidienne(graph[d], graph[a]);
  node2.path.indice = d;
  node2.path.nom = node2.name;


  LO = Aliste_ajout_tete(node2,LO); //ajout du noeud de départ dans la liste finale
  while(node2.indice != a && !Aliste_vide(LO))
  {
    //puts("\n++++++++++++++++++++LO+++++++++++++++++++");
    //visualiser_Aliste(LO);
    //mise à jour
    node2 = LO->val;
    LF = Aliste_ajout_tete(node2,LF);
    LO = Aliste_supprimer_tete(LO);
    //puts("======================LF=======================");
    //visualiser_Aliste(LF);
    printf("n°courant %lu, n°arrivée %lu\n", node2.indice, a);
    s = node2.indice; //s devient le dernier sommet ajouté dans LF
    if (s==a){
      LO = liberer_Aliste(LO);
      LF = itineraire(LF);
      return LF;//fin
    }

    L_ARC listeArc=NULL;
    //parcours de tout les voisins :
    for(listeArc = graph[s].voisins; !liste_vide(listeArc); listeArc = listeArc->suiv)
    {
      //scanf("%c",str);
      node1.indice = (listeArc->val).arrivee;
      node1.name = graph[node1.indice].nom;//nom du sommet cible
      node1.weight = (listeArc->val).cout + node2.weight;
      node1.cbwght = 0*node1.weight + 10*distanceEuclidienne(graph[node1.indice], graph[a]);
      //construction du noeud.path
      node1.path.indice = node2.indice;
      node1.path.nom = node2.name;
      if(rechercheAliste(LF, node1.indice, prevCell) != NULL){
        //ne rien faire, passer au voisin suivant
      }
      else if ( (cell = rechercheAliste(LO, node1.indice, prevCell)) != NULL){
        if(node1.cbwght < cell->val.cbwght){
          LO = supprimeCellule(LO , cell, prevCell);
          LO = AlisteTriInsertion(LO, node1);
        }
        else{
          //ne rien faire : on garde le sommet deja présent dans LO
        }
      }
      else {
        LO = AlisteTriInsertion(LO, node1);
      }
    }
  }
  puts("l'algorithme s'est terminé sans trouver la destination");
  LO = liberer_Aliste(LO);
  LF = liberer_Aliste(LF);
  return LF;
}

/*
----------------------------------------------------------------------------
FONCTION : ALIST itineraire(ALIST LF)
----------------------------------------------------------------------------
DESCRIPTION : extrait l'itinéraire de la liste fermée
----------------------------------------------------------------------------
PARAMETERS :
  - ALIST LF prends en paramètre la liste fermée générée dans Astar() pour en
  supprimer les cellules inutile au chemin
----------------------------------------------------------------------------
RETURN : ALIST retourne l'itinéraire sous forme d'une ALIST, l'arrivée en tête
----------------------------------------------------------------------------
*/

ALIST itineraire(ALIST LF){
  ALIST p = NULL;
  ALIST h =NULL;
  for(p = LF; !Aliste_vide(p->suiv); p = p->suiv){
    //printf(" indice suiv %lu indice path %lu \n",p->suiv->val.indice, p->val.path.indice);
    while(p->suiv->val.indice != p->val.path.indice && p->suiv != NULL){
      h = p->suiv;
      //printf("suppression de %lu\n", h->val.indice);
      p->suiv = p->suiv->suiv;
      free(h);
    }
  }
  return LF;
}

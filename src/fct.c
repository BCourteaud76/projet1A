#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "liste.h"

T_SOMMET* lectureFichier(char* fileName){
    FILE* f = fopen(fileName,"r");
    int nl,nbArc;
    fscanf(f,"%d %d", &nl, &nbArc);
    T_SOMMET* graph;
    graph=calloc(nl, sizeof(T_SOMMET)*nl);
    //fgets(f);
    int i,d;
    char n[40];
    fscanf(f,"%s",n);
    for(i=0; i<nl; i++){
      fscanf(f,"%d %lf %lf %s %s", &d, &(graph[i].x), &(graph[i].y), &(graph[i].ligne[0]), &(graph[i].nom[0]));
      /*
      int j;
      for (j=0; j<3;j++){
        graph[i].ligne[j]=l[j];
      }
      for (j=0; j<40;j++){
        graph[i].nom[j]=n[j];
      }
      */
    }

    fscanf(f,"%s",n);
    int origine;
    for(i=0; i<nbArc; i++){
      T_ARC voisins;
      fscanf(f,"%d %d %lf", &origine, &(voisins.arrivee), &(voisins.cout));
      ajout_queue( voisins, graph[origine].voisins);
    }
    return graph;
}


double distancemetre(T_SOMMET* a, T_SOMMET* b){
  return sqrt(a->x*b->x + a->y+b->y);
}

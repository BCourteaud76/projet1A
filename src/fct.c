#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "listeArc.h"

T_SOMMET * lectureFichier(char* fileName, unsigned long *len){
    FILE* f = fopen(fileName,"rt");
    if (f==NULL){
      printf("erreur lors de l'ouverture du fichier : %s \n", fileName);
      exit(1);
    }
    unsigned long nl,nbArc;
    fscanf(f,"%lu %lu", &nl, &nbArc);
    //printf("nl = %lu ; nbArc = %lu\n", nl, nbArc);
    T_SOMMET *graph=calloc(nl, sizeof(T_SOMMET));
    unsigned long i,d;
    //initialisation des L-ARC
    for(i=0;i<nl;i++){
      graph[i].voisins=creer_liste();
    }

    *len = nl;
    // rejet d'une ligne dans le document
    char str[60];
    fgets(str,59,f);
    fgets(str,59,f);
    //fscanf(f,"%s",str);   => il faudrait en faire 3 pour supprimer tt les mots
    //printf(" ligne rejetée : '%s'\n", str);
    //puts("indices sommets :");
    for(i=0; i<nl; i++){
      fscanf(f,"%lu %lf %lf %s", &d, &(graph[i].x), &(graph[i].y), &(graph[i].ligne[0]));
      fgets(graph[i].nom,80,f);
      //printf("indice : %lu , x : %lf y : %lf ligne '%s' nom '%s'\n",d, graph[i].x, graph[i].y, graph[i].ligne, graph[i].nom );
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

    //fscanf(f,"%s",str);
    fgets(str,59,f);
    //printf(" ligne rejetée : '%s'\n", str);
    // !!! probleme ici origine n'est jamais mis à jour, pk ?
    unsigned long origine=0;
    for(i=0; i<nbArc; i++){
      T_ARC arc;
      fscanf(f,"%lu %lu %lf", &origine, &(arc.arrivee), &(arc.cout));
      //printf("%lu %lu %lf\n",origine, voisins.arrivee, voisins.cout);
      graph[origine].voisins = ajout_tete( arc, graph[origine].voisins);
    }
    return graph;
}


double distancemetre(T_SOMMET* a, T_SOMMET* b){
  return sqrt(a->x*b->x + a->y+b->y);
}

void afficheGraphe(T_SOMMET*graph, unsigned long len){
  unsigned long i;
  for(i=0; i<len; i++){
    printf("%s %lf %lf %s\n", graph[i].ligne, graph[i].x, graph[i].y,  graph[i].nom);
  }
}

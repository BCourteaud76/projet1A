#include "struct.h"

int main (){


}


GRAPHE lectureFichier(char* fileName){
    FILE f = fopen(fileName,rt);
    int nl,nbArc;
    fsanf(f,"%lf %lf", &nl, &nbArc);
    T_SOMMET* graph=calloc(nl, sizeof(T_SOMMET));
    fgets(f);
    int i,d;
    double x,y;
    char l[4],n[40];
    for(i=0; i<nl; i++){
      fsanf(f,"%d %lf %lf %s %s", &d, &(graph[i].x), &(graph[i].y), l, n);
      int j;
      for (j=0; j<3;j++){
        graph[i].ligne[j]=l[j];
      }
      for (j=0; j<40;j++){
        graph[i].nom[j]=n[j];
      }
    }
    fgets(f);
    int origine,destination;
    double longueur;
    for(i=0; i<nbArc; i++){
      fsanf(f,"%d %d %lf", &origine, &destination, &longueur);
      ajout_queue(graph[origine].voisins, destination, longueur); //a definir proprement
    }
}

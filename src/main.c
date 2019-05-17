#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "fct.h"

void testRemplirGraphe(){
  T_SOMMET* graph;
  printf("etape1\n");
  graph=lectureFichier("data/metroetu.cvs");
  printf("etape2\n");
  printf("%s", graph[0].ligne); printf('\n');
  printf("%s", graph[0].nom); printf('\n');
  printf("%lf", graph[0].x); printf('\n');
  printf("%lf", graph[0].y); printf('\n');
  free (graph);
}

int main (){
  testRemplirGraphe();
  return 0;
}

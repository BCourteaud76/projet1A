#ifndef ASTAR_H
#define ASTAR_H
#include "struct.h"
#include "graphe.h"
double distanceEuclidienne(T_SOMMET a, T_SOMMET b);
ALIST Astar(GRAPHE graph, nb_sommets, int d, int s);


#endif
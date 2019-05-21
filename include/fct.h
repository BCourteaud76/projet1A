#ifndef FCT_H
#define FCT_H

#include "struct.h"

T_SOMMET *lectureFichier(char* fileName, unsigned long *len);
double distancemetre(T_SOMMET a, T_SOMMET b);
void afficheGraphe(T_SOMMET*graph, unsigned long len);
void libereGraphe(T_SOMMET *graph, unsigned long len);
#endif

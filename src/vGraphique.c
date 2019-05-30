#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Aliste.h"
#include "graphe.h"
#include "fct.h"
#include "Astar.h"
#include "graphic.h"
#include "hach.h"


int main(int agrc,char* agrv[]){
  GRAPHE graphe= NULL;
  ALIST path = NULL;
  unsigned long len =0;
  unsigned long a =0, d=0;
  if(agrc != 2){
    puts("nombre d'argument incompatible");
    exit(EXIT_FAILURE);
  }
  graphe = lectureFichier(agrv[1], &len);

  //affichage graphique du graphe
  SDL_Surface *screen;
  Color c;
  c.r = 255; c.g=255; c.b = 255; //regle la couleur du background (RVB)
  screen = SdlNewWindow(LARGEUR, HAUTEUR, "PROJET S2", c);
  reseauGraphique(screen, graphe, len);

/*
  //parametrage du trajet
  puts("entrez le sommet de départ");
  scanf("%lu", &d);
  puts("entrez le sommet d'arrivée");
  scanf("%lu", &a);
*/

  char stationcherchee[100];
  char* fichier=agrv[1];
  HACH* table=remplirTabHach(fichier);
  do {
    puts("entrez la station de départ cherchée :");
    scanf("%[^\n]",stationcherchee);
    clean_stdin();
    d = rechercheStation(stationcherchee,table);
  } while (d==0);
  do {
    puts("entrez la station d'arrivée cherchée :");
    scanf("%[^\n]",stationcherchee);
    clean_stdin();
    a = rechercheStation(stationcherchee,table);
  } while (a==0);
  printf("%ld %ld\n", d, a);
  free(table);

  path = Astar(graphe, d , a);
  visualiser_Aliste(path);

  //affichage du trajet sur le graphique
  itineraireGraphique(screen, graphe,len, path);
  SdlPause(screen);
  SDL_Quit();
  liberer_Aliste(path);
  libereGraphe(graphe, len);
  return 0;
}

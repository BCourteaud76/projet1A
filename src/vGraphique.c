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

  char stationcherchee[100] = {0};
  char* fichier=agrv[1];
  reseauGraphique(screen, graphe, len);
  puts("construction de la table de hachage, cela peut prendre plusieurs dixaines de secondes");
  HACH* table=remplirTabHach(fichier);
  char quit = 0;
  while(quit==0){
    reseauGraphique(screen, graphe, len);
/*
  //parametrage du trajet
  puts("entrez le sommet de départ");
  scanf("%lu", &d);
  puts("entrez le sommet d'arrivée");
  scanf("%lu", &a);
*/


    do {
      puts("entrez la station de départ cherchée :");
      scanf("%[^\n]",stationcherchee);
      clean_stdin();
      d = rechercheStation(stationcherchee,table, len);
    } while (d==0);
    do {
      puts("entrez la station d'arrivée cherchée :");
      scanf("%[^\n]",stationcherchee);
      clean_stdin();
      a = rechercheStation(stationcherchee,table, len);
    } while (a==0);

  //printf("%ld %ld\n", d, a);


    path = Astar(graphe, d , a);
    visualiser_Aliste(path);
    //affichage du trajet sur le graphique
    itineraireGraphique(screen, graphe,len, path);
    puts("fermer l'application ? Y/N ");
    scanf("%[^\n]", stationcherchee);
    clean_stdin();
    if(strcmp(stationcherchee, "Y")==0){
      quit++;
    }
    SDL_FillRect(screen,NULL, SDL_MapRGB(screen->format,c.r,c.g,c.b));
  }
  //SdlPause(screen);
  freeTable(table,len);
  SDL_Quit();
  liberer_Aliste(path);
  libereGraphe(graphe, len);
  return 0;
}

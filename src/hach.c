#include "hach.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* nettoyage(char* station){
	char* nouv=station;
	int i=0;
	while ((*nouv==' '||*nouv=='	')&& i<10){
		nouv++;
		i++;
	}
	while (*station!='\n' && station!='\0'){
		station++;
	}
	*station='\0';
	return nouv;
}

unsigned long hachage (char* mot){
	/* fonction de hachage non optimale
	 * Aditionne les valeur ascii des éléments de la chane de caractère
	 * division module la taille de la table pour rester dedans
	 */

	int hacha = 0;
	int i = 0;
	while (*(mot+i) !='\0'){
		hacha=(hacha+abs(*(mot+i)))%(TAILLE_TAB_HACH-1);
		i++;
	}
	return hacha+1;
}

unsigned long rechercheStation(char* station,HACH tabHach){
	/* Fonction qui transforme la chanie de caractère en un indice comprehansible par le AStar
	 * Retourne 0 si nom de station inconu
	 */
	unsigned long hacha=hachage(station);
	HACH p=tabHach+hacha;
	if (strcmp (p->nom,station)!=0){
		if (p->suiv!=NULL){
			p=p->suiv;
		}
		else{
			printf("Hum, la station %s n'est pas dans nos listings.\n Veulliez réessayer.\n", station);
			return 0;
		}
	}
	return p->sommet;
}

HACH remplirTabHach(char* fichier){
	FILE* f = fopen(fichier,"rt");
    if (f==NULL){
		printf("erreur lors de l'ouverture du fichier pour la table de hachage : %s \n", fichier);
		exit(1);
	}
	unsigned long nl,nbArc;
  fscanf(f,"%lu %lu", &nl, &nbArc);
	//printf("on a nl = %ld\n",nl);
  HACH tabHach=calloc(nl, sizeof(struct hachsui));
  unsigned long d;
  double x,y;
  char ligne[30];
	char* station=calloc(100,sizeof(char));
	char* stationNet;//=calloc(100,sizeof(char));
  //char station[100];
	char str[60];
	fgets(str,59,f);
	fgets(str,59,f);
  int hacha;
	unsigned long i;
  for (i=0; i<nl; i++){
		fscanf(f,"%lu %lf %lf %s", &d, &x, &y, ligne);
		fgets(station,100,f);
		stationNet=nettoyage(station);
		//printf("le nom de la station est : %s\n", stationNet);
		hacha=hachage(stationNet);
		//printf("son hach est : %d\n", hacha);
		if (tabHach[hacha].suiv==NULL){	//si pas de collisions
			tabHach[hacha].sommet=i;
			strncpy(tabHach[hacha].nom, stationNet, sizeof(*stationNet));
			tabHach[hacha].suiv=NULL;
		}
		else{							// si colision
			HACH p=tabHach+hacha;
			while (p->suiv!=NULL){
				p=p->suiv;
			}
			p->suiv=calloc(1,sizeof(HACH));
			if (p->suiv == NULL){
				printf("probleme d'allocation mémoire dans une collision\n");
				exit(1);
			}
			p->suiv->sommet=i;
			p->suiv->suiv=NULL;
			strncpy(p->suiv->nom, station, sizeof(*station));
		}
	}
	fclose(f);
	free(station);
	//free(stationNet);
	printf("La table de hachage est correctement remplie\n");
	return tabHach;
}

HACH freeTable(HACH table){
	int i;
	for (i=0;i<TAILLE_TAB_HACH;i++){
		if (table+i!=NULL){
			HACH p=table+i;
			HACH prev;
			while (p->suiv !=NULL){
				prev=p;
				p=p->suiv;
				free(prev);
			}
		}
	}
	free(table);
	return NULL;
}

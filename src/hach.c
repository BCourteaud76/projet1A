#include "hach.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long hachage (char* mot){
	/* fonction de hachage non optimale
	 * Aditionne les valeur ascii des éléments de la chane de caractère
	 * division module la taille de la table pour rester dedans
	 */

	int hacha = 0;
	int i = 0;
	while (*(mot+i) !='\0'){
		hacha+= *(mot+i)%TAILLE_TAB_HACH;
	}
	return hacha;
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
    HACH tabHach=calloc(nl, sizeof(struct hachsui));
    unsigned long d;
    double x,y;
    char ligne[30];
    char station[100];
    int hacha;
		unsigned long i;
    for (i=0; i<nl; i++){
		fscanf(f,"%lu %lf %lf %s", &d, &x, &y, ligne);
		fgets(station,100,f);
		hacha=hachage(station);
		if (tabHach[hacha].sommet==0){	//si pas de collisions
			tabHach[hacha].sommet=i;
			strncpy(tabHach[hacha].nom, station, sizeof(station));
			tabHach[hacha].suiv=NULL;
		}
		else{							// si colision
			HACH p=tabHach+hacha;
			while (p->suiv!=NULL){
				p=p->suiv;
			}
			p->suiv=calloc(1,sizeof(HACH));
			p->suiv->sommet=i;
			p->suiv->suiv=NULL;
			strncpy(p->suiv->nom, station, sizeof(station));
		}
	}
	fclose(f);
	return tabHach;
}

HACH freeTable(HACH* table){
	int i;
	for (i=0;i<TAILLE_TAB_HACH;i++){
		if (table[i]!=0){
			HACH p=table[i];
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

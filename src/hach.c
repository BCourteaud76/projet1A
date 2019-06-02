#include "hach.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* nettoyage(char* station){
	/*
	----------------------------------------------------------------------------
	DESCRIPTION : lors de la construction du graphe les noms contiennent les
	caractère de retour chariot. On les supprimes afin de ne pas biaiser la valeur
	retournée par la fonction de hachage
	----------------------------------------------------------------------------
	PARAMETERS :
	  - char* station : chaine de charactère contenant le nom d'un station
	----------------------------------------------------------------------------
	RETURN : le nom de la station débarassée des charactères retour-chariot "\n"
	----------------------------------------------------------------------------
	*/

	char* nouv=station;
	int i=0;
	while ((*nouv==' '||*nouv=='	')&& i<10){
		nouv++;
		i++;
	}
	while (*station!='\n' && *station!='\0'){
		station++;
	}
	*station='\0';
	return nouv;
}

unsigned long hachage (char* mot, unsigned long len){
	/*
	----------------------------------------------------------------------------
	DESCRIPTION :
		fonction de hachage non optimale
	  Aditionne les valeur ascii des éléments de la chane de caractère
		division module la taille de la table pour rester dedans
	----------------------------------------------------------------------------
	PARAMETERS :
	  - char* mot : chaine de charactère dont on veut retourner la valeur de
		hachage
	----------------------------------------------------------------------------
	RETURN : valeur de la fonction de hachage
	----------------------------------------------------------------------------
	*/
	unsigned long hacha = 0;
	unsigned long i = 0;
	while (*(mot+i) !='\0'){
		if (*(mot+i)!=' ' && *(mot+i)!=' '){
			hacha=(hacha+abs(*(mot+i)))%(len-1);
		}
		i++;
	}
	return hacha+1;
}

unsigned long rechercheStation(char* station,HACH* tabHach, unsigned long len){
	/* Fonction qui transforme la chanie de caractère en un indice comprehansible par le AStar
	 * Retourne 0 si nom de station inconu
	 */
	unsigned long hacha=hachage(station, len);
	printf("le hach de la station recherchée est : %ld\n",hacha);
  printf("Elle est cherchée dans :\n");
  affichetabhach(*(tabHach+hacha));
	HACH p=*(tabHach+hacha);
	//printf("le nom de la première station est : %s\n",p->nom);
	if (p == NULL){
		puts("station introuvable");
		return 0;
	}
	while (strcmp (p->nom,station)!=0){
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

HACH* remplirTabHach(char* fichier){
	FILE* f = fopen(fichier,"rt");
    if (f==NULL){
		printf("erreur lors de l'ouverture du fichier pour la table de hachage : %s \n", fichier);
		exit(1);
	}
	unsigned long nl,nbArc;
  fscanf(f,"%lu %lu", &nl, &nbArc);
  HACH* tabHach=calloc(nl, sizeof(HACH));
  unsigned long d;
  double x,y;
  char ligne[30];
	char* station=calloc(100,sizeof(char));
	char* stationNet;

	char str[60];
	fgets(str,59,f);
	fgets(str,59,f);
  unsigned long hacha;
	unsigned long i;
  for (i=0; i<nl; i++){
		fscanf(f,"%lu %lf %lf %s", &d, &x, &y, ligne);
		fgets(station,100,f);
		stationNet=nettoyage(station);
		//printf("le nom de la station est : %s\n", stationNet);
		hacha=hachage(stationNet, nl);
		//printf("son hach est : %lu\n", hacha);
		if (tabHach[hacha]==NULL){	//si pas de collisions
			tabHach[hacha]=calloc(1,sizeof(struct hachsui));
			tabHach[hacha]->sommet=i;
			strncpy(tabHach[hacha]->nom, stationNet, 100*sizeof(*stationNet));
			tabHach[hacha]->suiv=NULL;
		}
		else{							// si colision
			//printf("on a une collision !\n");
			HACH p=*(tabHach+hacha);
			while (p->suiv!=NULL){
				//printf("ce n'est pas la première à cet indice !\n");
				p=p->suiv;
			}
			p->suiv=calloc(1,sizeof(struct hachsui));
			if (p->suiv == NULL){
				//printf("probleme d'allocation mémoire dans une collision\n");
				exit(1);
			}
			p->suiv->sommet=i;
			p->suiv->suiv=NULL;
			strncpy(p->suiv->nom, stationNet, 100*sizeof(*stationNet));
		}
	}
	fclose(f);
	free(station);
	//printf("La table de hachage est correctement remplie\n");
	return tabHach;
}

HACH libereListeHach(HACH cellule){
	HACH next=cellule;
	HACH current= cellule;
	while (next!=NULL){
		current=next;
		next=next->suiv;
		free(current);
	}
	return NULL;
}

HACH* freeTable(HACH* table, unsigned long len){
	unsigned long i;
	for (i=0;i<len;i++){
		*(table+i)=libereListeHach(*(table+i));
	}
	free(table);
	return NULL;
}

void affichetabhach(HACH aff){
	while (aff!=NULL){
		printf("la station dans la table est : %s\n", aff->nom);
    aff=aff->suiv;
	}
}

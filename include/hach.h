#ifndef _HACH
#define _HACH

typedef struct hachsui{
	int sommet;
	char nom[100];
	struct hachsui* suiv;
} HACH;

#define TAILLE_TAB_HACH 400

unsigned long hachage (char* mot);
unsigned long rechercheStation(char* station);
HACH* remplirTabHach(char* fichier);

#endif

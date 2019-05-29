#ifndef _HACH
#define _HACH

typedef struct hachsui{
	int sommet;
	char nom[100];
	struct hachsui *suiv;
} *HACH;


#define TAILLE_TAB_HACH 400

char* nettoyage(char* station);
unsigned long hachage (char* mot);
unsigned long rechercheStation(char* station,HACH* tabHach);
HACH* remplirTabHach(char* fichier);
HACH libereHach(HACH cellule);
HACH libereListeHach(HACH cellule);
HACH* freeTable(HACH* table);

#endif

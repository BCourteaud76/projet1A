#ifndef _HACH
#define _HACH

typedef struct hachsui{
	int sommet;
	char nom[100];
	struct hachsui *suiv;
} *HACH;


//#define TAILLE_TAB_HACH 400

char* nettoyage(char* station);
unsigned long hachage (char* mot, unsigned long len);
unsigned long rechercheStation(char* station,HACH* tabHach, unsigned long len);
HACH* remplirTabHach(char* fichier);
HACH libereListeHach(HACH cellule);
HACH* freeTable(HACH* table,unsigned long len);
void affichetabhach(HACH aff);

#endif

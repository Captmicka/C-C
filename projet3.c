#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void CryptageFichiersOuverts(FILE *pfIn, FILE *pfOut, int clef)
{
	int carac;
	while((carac = fgetc(pfIn)) != EOF)
	{
		int xored = carac ^ clef;
		fputc(xored, pfOut);
	}
 
}
 
void Cryptage(const char *nomFichSrc, const char *nomFichDest, int clef)
{
	FILE *pfIn = fopen(nomFichSrc, "r");
	if(pfIn == NULL)
	{
		puts("Echec d'ouverture du fichier source.");
	}
	else
	{
		FILE *pfOut =NULL;
		pfOut= fopen(nomFichDest, "w");
		if(pfOut == NULL)
		{
			puts("Echec d'ouverture du fichier destination.");
		}
		else
		{
			CryptageFichiersOuverts(pfIn, pfOut, clef);
			fclose(pfOut);
		}
 
		fclose(pfIn);
	}
 
}
 
void DemandeEtCrypte()
{
	char nomFich[300] = "";
	char *pRetour = NULL;
	int clef;
 	int i;

	printf("Nom du fichier a crypter : \n");
	fflush(stdout); // Nécessaire si une ligne ne se termine pas par \n - fflush(stdout) : fonction qui vide le tampon de sortie.
 
	/* On lit le nom du fichier, 
	   puis on vérifie qu'il rentre en entier dans la zone de 300 caractères.
	   S'il rentre, le \n sera dedans, et il faudra le supprimer.
	   Si ça ne rentre pas, le \n ne sera pas dedans, et on dira Erreur. */
 
	fgets(nomFich, 300, stdin);
	pRetour = strchr(nomFich, '\n');
	if(pRetour == NULL)
	{
		// Le \n final n'est pas dans le nom de fichier.
		puts("Nom de fichier trop grand.\n");
	}
	else
	{
		/* Le \n est présent : OK, on tronque la chaîne ici. */
		*pRetour = '\0';
 
		
		for (i=0 ;i<16;i++)
  		{
	  		clef=rand()%2;
   		}
		printf("le clé de cryptage est : %p",&clef); 

		
 
		/* On lance le cryptage du fichier, et on met le resultat dans "fichier_crypte.txt".
		   Si on veut, on peut demander le nom du fichier destination à la place... */
		Cryptage("test", "fichier_crypte.txt", clef);
		printf ("fichier crypté\n");	
		}	
}
 
int main(int argc, char *argv[]) {
	DemandeEtCrypte();
	return 0; 
}

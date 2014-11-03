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
	FILE *pfIn; 
	pfIn= fopen(nomFichSrc, "r");
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
			printf("fichier en cryptage niveau 1 \n");
			CryptageFichiersOuverts(pfIn, pfOut, clef);
			fclose(pfOut);
		}
 
		fclose(pfIn);
	}
 
}
 
void DemandeEtCrypte(int choix,int clef)
{
	char nomFich[300] = "";
	char *pRetour = NULL;
	int i;
 
	printf("Nom du fichier a crypter : \n");
	fflush(stdout); /* Nécessaire si une ligne ne se termine pas par \n */
 
	/* On lit le nom de fichier, 
	   puis on vérifie qu'il rentre en entier dans la zone de 300 char.
	   S'il rentre, le \n sera dedans, et il faudra le supprimer.
	   Si ça ne rentre pas, le \n ne sera pas dedans, et on dira Erreur. */
	fgets(nomFich, 300, stdin);
	pRetour = strchr(nomFich, '\n');
	if(pRetour == NULL)
	{
		/* Le \n final n'est pas dans le nom de fichier. */
		puts("Nom de fichier trop grand.");
	}
	else
	{	

		if (choix == 1)
		{



			/* Le \n est présent : OK, on tronque la chaîne ici. */
			*pRetour = '\0';
 
			
			/*
			printf("Entrer clef(numerique) : ");
			fflush(stdout);
 			scanf("%d", &clef);
			printf("la clef %p \n",&clef);
			*/
			
			for (i=0 ;i<6;i++)
  			{
	  			clef=rand()%2;
   			}
			printf("le clé de cryptage est : %p \n",&clef); 
		
		
 
			/* On lance le cryptage du fichier, et on met le resultat dans "fichier_crypte.txt". */
			Cryptage(nomFich, "fichier_crypte.txt", clef);
			printf ("fichier crypté\n");	
			}
		
		else if (choix == 2)
			{
			

			/* Le \n est présent : OK, on tronque la chaîne ici. */
			*pRetour = '\0';
 
						
			printf("Entrer clef(numerique) : ");
			fflush(stdout);
 	
			scanf("%d", &clef);
			printf("la clef %p \n",&clef);
					
		
 
			/* On lance le cryptage du fichier, et on met le resultat dans "fichier_crypte.txt".
		   Si on veut, on peut demander le nom du fichier destination à la place... */
			Cryptage(nomFich, "fichier_crypte.txt", clef);
			printf ("fichier décrypté\n");
			}		
}
}
 
int main(int argc, char *argv[]) {
	
int choix;
int clef;
	printf("Voulez vous crypter 1 ou decrypter 2\n");
	fflush(stdout);
 	scanf("%d",&choix);
	
	if (choix == 1)
	{
		DemandeEtCrypte(1,0);
	}
	else if(choix == 2)
	{
		printf("Entrer clef(numerique) : ");
		fflush(stdout);
	 	scanf("%d", &clef);
		DemandeEtCrypte(2,clef);
	}
	return 0; 
}

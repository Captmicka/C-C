#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int encipher();
int decipher();

int main(void)
{
int choice;
while(1)
  {
  printf("\n1. Crypter un Texte\n");
  printf("2. Decrypter un Texte\n");
  printf("3. Quitter\n");
  printf("Choisir 1,2 ou 3 : ");
  scanf("%d" ,&choice);
  fflush(stdin);
  if(choice == 3)
    exit(0);
  else if(choice == 1)
       encipher();
       else if(choice == 2)
	    decipher();
	    else
	     printf("Vous n'avez pas choisi une option valide");
	break;
  }
}


int encipher()
{
unsigned int a,b;
char Lettre[257];
char key[33];
printf("Entree le texte a crypter [Max. 256 char]: ");
fgets(Lettre, sizeof Lettre,stdin);
printf("Entrer cle de cryptage [Max. 32 Char]: ");
fgets(key,sizeof key,stdin);
printf("Resultat :  ");
  for(a=0,b=0;a<strlen(Lettre);a++,b++)
  {	               
    if(b>=strlen(key))
      {
	b=0;
      }
    printf("%c",65+(((toupper(Lettre[a])-65)+(toupper(key[b])-65))%26));
  }
  printf("\n");
  exit(0);
}

int decipher()
{
unsigned int a,b;
char Lettre[257];
char key[33];
int value;
printf("Entrer le Texte a Decrypter [Max. 256 char]:");
fgets(Lettre, sizeof Lettre, stdin);
printf("Entrer la cle de Decryptage [Max. 32 Char]:");
fgets(key,sizeof key,stdin);
printf("Resultat: ");
for(a=0,b=0;a<strlen(Lettre);a++,b++)
  {
    if(b>=strlen(key))
     {
	b=0;
      }
      value = (toupper(Lettre[a])-64)-(toupper(key[b])-64);
    if( value < 0)
      {
	value = 26 + value;
      }        
  printf("%c",65 + (value % 26));
 }
 printf("\n");
 exit(0);
}

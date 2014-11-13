/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package verman;

import java.util.*;
import java.io.*;
/**
 *
 * @author Philippe
 */
public class Verman {

    /**
     * @param args the command line arguments
     */
public static void main(int argc, char argv) {
       int choix;
       int[] clef = null;
       byte[] lu = new byte[15];
	System.out.printf("Voulez vous crypter 1 ou decrypter 2\n");
	Scanner sc = new Scanner(System.in);
        choix = sc.nextInt();
        System.out.println("Vous avez saisi : " + choix);
 	
	
	if (choix == 1)
	{
                DemandeEtCrypte(1,null);
	}
	else if(choix == 2)
	{
		sc = new Scanner(System.in);
                System.out.println("Veuillez saisir la clé :");
                System.out.println("Saisissez une lettre :");
                Scanner scl = new Scanner(System.in);
                String str = scl.nextLine();
                for (int i=0;i<16;i++)
                {
                clef[i] = str.charAt(i);
                }       
                System.out.println("Vous avez saisi : " + clef);;
		DemandeEtCrypte(2,clef);
	}
    

}


static void DemandeEtCrypte(int choix,int[] clef)
{
	String nomFich = new String();
	int i;
 
	System.out.printf("Nom du fichier a crypter ou decrypter : \n");
        Scanner sc = new Scanner(System.in);
	nomFich = sc.nextLine(); /* Nécessaire si une ligne ne se termine pas par \n */
 
	/* On lit le nom de fichier, 
	   puis on vérifie qu'il rentre en entier dans la zone de 300 char.
	   S'il rentre, le \n sera dedans, et il faudra le supprimer.
	   Si ça ne rentre pas, le \n ne sera pas dedans, et on dira Erreur. */

	if (choix == 1)
		{

		for (i=0 ;i<6;i++)
  		{
	  		clef[i]=(Math.random()<0.5)?0:1;;
   		}
		System.out.printf("le clé de cryptage est : ", clef); 
		
		
 		/* On lance le cryptage du fichier, et on met le resultat dans "fichier_crypte.txt". */
		Cryptage(nomFich, "fichier_crypte.txt", clef);
		System.out.printf ("fichier crypté\n");	
		}
		
		else if (choix == 2)
			{
			
			/* On lance le cryptage du fichier, et on met le resultat dans "fichier_crypte.txt".
		   Si on veut, on peut demander le nom du fichier destination à la place... */
			Cryptage(nomFich, "fichier_crypte.txt", clef);
			System.out.printf ("fichier décrypté\n");
			}		
}    
    

static void Cryptage(String nomFichSrc,String nomFichDest, int[] clef)
{
    try {
         
    BufferedReader infile = new BufferedReader(new FileReader(nomFichSrc));
    String str;
    while ((str = infile.readLine()) != null) 
    {
          try 
            {
                BufferedWriter outfile = new BufferedWriter(new FileWriter(nomFichDest));
                char[] encrypt = null;
                char[] crypstr = str.toCharArray();
                int i;
                
                for (i=0; i<15; i++)
                {
                encrypt[i]= (char) (clef[i-5]^clef[i-6]^clef[i-15]^clef[i-16]);
                }
                
                for (i=16; i < crypstr.length;i++)
                {
                encrypt[i]= (char) (crypstr[i-5]^crypstr[i-6]^crypstr[i-15]^crypstr[i-16]);
                }
                
                outfile.write(encrypt);
                outfile.close();
            }
          
    catch (IOException e)    {    }
    }
    infile.close();
    } 
    catch (IOException e) 
    {
        System.out.printf("fichier non trouvé");
    }
            
 
}


}

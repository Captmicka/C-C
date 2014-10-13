import java.io.*;

public class cryptage{
   public static void main (String[] args){
	  int taillemot; //recupére la taille du mot a crypter
	  String masque=null; //le masque utiliser pour crypter
	  BufferedReader IN=null;
	  try{
		 IN=new BufferedReader(new InputStreamReader(System.in));
	  }
	  catch(Exception ex){}
	  System.out.print("Mot a Crypter : ");
	  String mot = null;
	  try{
		 mot=IN.readLine();//recupere le mot
	  }
	  catch (Exception ex){
	  System.out.print("Vous n'avez pas rentrer de mot");
	  }
	  taillemot=mot.length();//calcul la taille du mot
	  int taillemasque=0;
	  BufferedReader IN2=null;
	  try{
		 IN2=new BufferedReader(new InputStreamReader(System.in));//recupere le masque
	  }
	  catch (Exception ex){}
	  while (taillemasque != taillemot){
		 System.out.print("Pas la meme taille \n");
		 System.out.print("Masque de "+taillemot+" caractere : ");
		 try{
			masque=IN.readLine();
		 }
		 catch (Exception ex){};
		 taillemasque = masque.length();
	  }
	  char[] Tableau1 = mot.toCharArray();
	  char[] Tableau2 = masque.toCharArray();
	  int z=0;
	  System.out.print("Le mot crypter est : ");
	  while (z<taillemot){
		 char a = (char) (Tableau1[z]^Tableau2[z]);
			   z=z+1;
			   System.out.print(a);
	  }

	  System.out.println(masque);
   }
}

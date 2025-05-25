import java.util.Scanner;
import java.lang.Math;
import java.util.Random;

public class AlteracaoAleatoriaRecursiva {

    private static Random gerador = new Random(4);
    
    //funcao para comparar strings e determinar se sao identicas
    public static boolean isEquals(String palavra1, String palavra2){
        int n = palavra1.length();
        boolean resp = true;
        // comparar tamanho das palavras 1 e 2
        if(n != palavra2.length()){
            resp = false;
        } else {
            for(int i = 0; i < n; i++){
                if(palavra1.charAt(i) != palavra2.charAt(i)){
                    resp = false;
                    i = n;
                 }
            }
        }
        return (resp);
    }

	public static String substituirString(String frase){
		char letraAntiga = (char)('a' + (Math.abs(gerador.nextInt())%26));
        char letraNova = (char)('a' + (Math.abs(gerador.nextInt())%26));
		return substituirString(frase, letraAntiga, letraNova, 0);	
	}

    // funcao para substituir caractere na String
    public static String substituirString(String frase, char letraAntiga, char letraNova, int i){
        String novaFrase = "";
		
		if(i < frase.length()){
			if (frase.charAt(i) == letraAntiga){
            	novaFrase += letraNova;
			    substituirString(frase, letraAntiga, letraNova, i + 1);
        	} else {
            	novaFrase += frase.charAt(i);  
				substituirString(frase, letraAntiga, letraNova, i + 1);
        	}
		}
        System.out.print(novaFrase);
		return (novaFrase);
    }

    public static void main (String[] args){
        Scanner sc = new Scanner(System.in, "UTF-8");
        String frase = sc.nextLine();
    
        while(!isEquals(frase,"FIM")){
            substituirString(frase);
			System.out.println();
            frase = sc.nextLine();
        }
        sc.close();
    }
}

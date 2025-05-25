import java.util.Scanner;
import java.lang.Math;
import java.util.Random;

public class AlteracaoAleatoria {

    private static Random gerador = new Random(4);
    
    //funcao para comparar strings e determinar se sao identicas
    public static boolean isEquals(String palavra1, String palavra2){
        int n = palavra1.length();
        boolean resp = true;
        // comparar tamanho das palavras 2 e 2
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

    // funcao para substituir caractere na String
    public static void substituirString(String frase){
        char letraAntiga = (char)('a' + (Math.abs(gerador.nextInt())%26));
        char letraNova = (char)('a' + (Math.abs(gerador.nextInt())%26));
        String novaFrase = "";
        
        for(int i = 0; i < frase.length(); i++){
            if(frase.charAt(i) == letraAntiga){
                novaFrase += letraNova;
            } else{
                 novaFrase += frase.charAt(i);
            }
        }
        System.out.println(novaFrase);
    }

    //metodo principal
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in, "UTF-8");
        String frase = sc.nextLine();
    
        while(!isEquals(frase,"FIM")){
            substituirString(frase);
            frase = sc.nextLine();
        }
        sc.close();
    }
}

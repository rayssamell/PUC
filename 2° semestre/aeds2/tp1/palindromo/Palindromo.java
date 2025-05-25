import java.util.Scanner;

public class Palindromo {
    //funcao para comparar strings e determinar se sao identicas
    public static boolean isEquals(String palavra1, String palavra2){
        int n = palavra1.length();
        boolean resp = true;

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
    // metodo para classificar se uma palavra e' ou nao um palindromo
    public static void classificarPalindromo(String palavra){
        int n = palavra.length();
        boolean resp = true;
        
        for(int i = 0; i < n / 2; i++){
            if(palavra.charAt(i) != palavra.charAt(n - i - 1)){
                resp = false;
                i = n;
            }
        }
        if(resp) System.out.println("SIM");
        else System.out.println("NAO");
    }
    // metodo principal
    public static void main (String[] args){
        String palavra;
        Scanner entrada = new Scanner(System.in);
        
        palavra = entrada.nextLine();
       
        while(!isEquals(palavra, "FIM")){
            classificarPalindromo(palavra);
            palavra = entrada.nextLine();
        }
        entrada.close();
    }
}
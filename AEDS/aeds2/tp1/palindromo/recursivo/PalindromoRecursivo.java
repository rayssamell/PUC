import java.util.Scanner;

public class PalindromoRecursivo {
    
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
    public static void classificarPalindromo(String s){
		if (classificarPalindromo(s, 0)) {
            System.out.println("SIM");
        } else {
            System.out.println("NAO");
        }
    }

    // metodo para classificar se uma palavra e' ou nao um palindromo
    public static boolean classificarPalindromo(String s, int i){
    	int n = s.length();
        boolean resp;
		
		// caso base
        if (i >= n / 2) {
            resp = true;
        } else if (s.charAt(i) != s.charAt(n - i - 1)) {
            resp = false;
        } else {
        	// chamada recursiva 
        	resp = classificarPalindromo(s, i + 1);
		}
   
		return (resp);
	}

    // metodo principal
    public static void main (String[] args){
    	String s;
        Scanner sc = new Scanner(System.in);
            
        s = sc.nextLine();
           
        while(!isEquals(s, "FIM")){
        	classificarPalindromo(s);
            s = sc.nextLine();
        }
 		sc.close();         
    }
}

import java.util.Scanner;

public class CiframentoCesar {
    
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
    
    //funcao para criptografar cifra de cesar
    public static void criptografar(String frase){
        for(int i = 0; i < frase.length(); i++){
			if( frase.charAt(i) != '\uFFFD'){
				//aplicar deslocamento de 3 em cada letra
				char novaLetra = (char) (frase.charAt(i) + 3);
            	System.out.print(novaLetra);
			} else{
				System.out.print(frase.charAt(i));
			}
        }
        System.out.println();
    }
    
    //metodo principal
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    	String frase = sc.nextLine();
    
        while(!isEquals(frase,"FIM")){
        	criptografar(frase);
            frase = sc.nextLine();
        }
		sc.close();
       
    }
}

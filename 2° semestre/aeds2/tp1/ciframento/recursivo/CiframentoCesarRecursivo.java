import java.util.Scanner;

public class CiframentoCesarRecursivo {
    
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
    
	//chamando funcao recursiva
	public static boolean criptografar(String frase){
		return criptografar(frase, 0); 	
	}

    //funcao para criptografar cifra de cesar recursivamente
    public static boolean criptografar(String frase, int i){
		boolean resp = false;
		//caso base
		if(i == frase.length()){		
			resp = true;	
		} else { 
			if( frase.charAt(i) != '\uFFFD'){
				//aplicar deslocamento de 3 em cada letra diferente de �
				char novaLetra = (char) (frase.charAt(i) + 3);
            	System.out.print(novaLetra);
			} else {
				System.out.print(frase.charAt(i));
			}
			//chamando funcao recursiva
			resp = criptografar(frase, i + 1);
		}
        return (resp);
    }
    
    //metodo principal
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    	String frase = sc.nextLine();
    
        while(!isEquals(frase,"FIM")){
        	criptografar(frase);
			System.out.println();	
            frase = sc.nextLine();
        }
		sc.close();
       
    }
}

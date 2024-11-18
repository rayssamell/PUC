import java.util.Scanner;

public class Is {
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

    // funcao converter caractere de minuscula para maiscula
    public static char toUpper(char c) {
        return (c >= 'a' && c <= 'z') ? (char)(c - 32) : c;
    }

    //metodo para verificar se a letra e' uma vogal
    public static boolean isVogal(char letra){
        char c = toUpper(letra);
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

	//metodo para verificar se a string e' composta somente por vogais
    public static void somenteVogal(String frase){
         boolean resp = true;

        for(int i = 0; i < frase.length(); i++){
            char c = toUpper(frase.charAt(i)); 
            if(!isVogal(c)){
                resp = false;
                i = frase.length();
            }
        }
        
        if(resp) System.out.print("SIM ");
        else System.out.print("NAO ");
    }
    
    //metodo para verificar se a string e' composta somente por consoantes
    public static void isConsoante(String frase){
        boolean resp = true;
        
        for(int i = 0; i < frase.length(); i++){
            char c = toUpper(frase.charAt(i)); 
            if (c < 'A' || c > 'Z' || isVogal(c)){
                resp = false;
  				i = frase.length();
            }
        }
    
        if(resp) System.out.print("SIM ");
        else System.out.print("NAO ");
    }

	// metodo para verificar se a string e' composta somenete por numeros inteiros
    public static void isInteiro(String frase){
        boolean resp = true;

        for(int i = 0; i < frase.length(); i++){
            char c = frase.charAt(i); 
            if(!(c >= '0' && c <= '9')){
                resp = false;
                i = frase.length();
            }
        }
        
        if(resp) System.out.print("SIM ");
        else System.out.print("NAO ");
    }

	// metodo para verificar se a string e' composta somente por numeros reais
    public static void isDouble(String frase){
     	boolean resp = false;
   		int count = 0;

    	for (int i = 0; i < frase.length(); i++) {
        	char c = frase.charAt(i);
			//verificar se e' um numero
        	if (c >= '0' && c <= '9') {
            	resp = true;
        	} else if (c == '.' || c == ',') {
            	count++; //se encontrar um "." ou "," incrementa um
            	if (count > 1) {
                	resp = false; // mais de um ponto ou virgula
                	i = frase.length();
            	}
        	} else {
            	resp = false; // caracteres nao permitidos
            	i = frase.length();
        	}
    	}	

    	if (resp) System.out.print("SIM");
    	else System.out.print("NAO");
    }
    
    //metodo principal
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String frase;

        frase = sc.nextLine();
        
        while(!isEquals(frase,"FIM")){
            somenteVogal(frase);
            isConsoante(frase);
            isInteiro(frase);
            isDouble(frase);
            
            System.out.println();
            frase = sc.nextLine();
        }
        sc.close();
    }
}

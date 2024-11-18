import java.util.Scanner;

public class IsRecursivo {
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

    //metodo para chamar funcao recursiva isVogal
    public static void somenteVogal(String frase){
        if(somenteVogal(frase,0)) System.out.print("SIM ");
        else System.out.print("NAO ");
    }

	//funcao recursivo para verificar se a string e' composta somente por vogais
    public static boolean somenteVogal(String frase, int i){
    	boolean resp;

        //caso base
		if(i == frase.length()){
			resp = true;
		} else if(!isVogal(frase.charAt(i))){
            resp = false;
        } else {
            //chamada recursiva
			resp = somenteVogal(frase, i + 1);
        }
        
		return resp;
    }
    
    //metodo para chamar a funcao recursiva isConsoante
    public static void isConsoante(String frase){
        if(isConsoante(frase, 0)) System.out.print("SIM ");
        else System.out.print("NAO ");
    }

	//metodo recursivo para verificar se a string e' composta somente por consoantes
    public static boolean isConsoante(String frase, int i){
        boolean resp;

        //caso base
		if(i == frase.length()){
			resp = true;
		} else{
            //caso o caracter for minusculo converte para maiusculo
            char c = toUpper(frase.charAt(i)); 
            // nao e' letra ou e' vogal = falso
            if (!(c >= 'A' && c <= 'Z') || isVogal(c)){
			    resp = false;
            } else {
                //chamada recursiva
                resp = isConsoante(frase, i + 1);
            }
        }
   		return (resp);
    }

    public static void isInteiro(String frase){
        if(isInteiro(frase, 0)) System.out.print("SIM ");
        else System.out.print("NAO ");
    }

	// metodo para verificar se a string e' composta somente por numeros inteiros
	public static boolean isInteiro(String frase, int i){
        boolean resp;
		
        //caso base
		if(i == frase.length()){
			resp = true;
		} else if(frase.charAt(i) >= '0' && frase.charAt(i) <= '9'){
            //chamada recursiva
			resp = isInteiro(frase, i + 1);
		} else {
            resp = false;
        }
       
		return (resp);
    }

    public static void isDouble(String frase){
        if(isDouble(frase, 0, 0)) System.out.print("SIM ");
        else System.out.print("NAO ");
    }

	// metodo para verificar se a string e' composta somente por numeros reais
    public static boolean isDouble(String frase, int i, int count){
     	boolean resp;

		//caso base
		if(i == frase.length()){
			resp = (count <= 1);
		} else if(frase.charAt(i) >= '0' && frase.charAt(i) <= '9'){
            //chamada recursiva caso for um numero
            resp = isDouble(frase, i+1, count);
        } else if(frase.charAt(i) == '.' || frase.charAt(i)== ','){
            count++; //contador para quantidade de pontos e virgulas
            if(count > 1){
                //mais de um ponto ou virgula = falso
                resp = false;
            }
            resp = isDouble(frase, i + 1, count);
        } else {
            resp = false;
        }
           
    	return (resp);
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

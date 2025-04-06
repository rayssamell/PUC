import java.util.Scanner;

public class Main {
    public static void tratarExpressao(String line){
        boolean barra = false;
        String novaLine = "";
        String[] linha = line.split(""); 

        for(int i=0; i < linha.length; i++){ 
            int j = i + 1;
            if(linha[i].equals("+") || linha[i].equals("-") || linha[i].equals("*") || linha[i].equals("^")){
                novaLine += linha[j];
                novaLine += linha[i];
                i++; 
            } else if(!linha[i].equals("/") || !linha[j].equals(")") || !linha[i].equals("(")){
                novaLine+= linha[i];
            } else if(linha[i].equals("/")){
                novaLine += linha[j];
                novaLine += "/";
                i++; 
            }
            
                
            
        }

       
        
        System.out.print(novaLine);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0; i < n; i++){
            String line = sc.nextLine();
            tratarExpressao(line);
            System.out.println();
        }

        sc.close();
    }
}
import java.util.Scanner;

public class InfixaPosfixa {
  
    public static void tratarExpressao(String line){
        String novaLine = "";
        boolean existe = false;
        int tam = line.length();

        for(int i=0; i < tam; i++){
            int j = i + 1;
        
            if(line.charAt(i) != '(' && line.charAt(i) != '/'){
                if(line.charAt(i) == '*' || line.charAt(i) == '+' || line.charAt(i) == '-' || line.charAt(i) == '^'){
                    novaLine += line.charAt(j);
                    novaLine += line.charAt(i); 
                    i++;
                } else if(line.charAt(i) == ')'){
                    if(i+2 == tam-1){
                        existe = true;
                    } else {
                        novaLine += '/';
                    }
                } else {
                    novaLine += line.charAt(i);
                }
            }
        }
        if(existe){
            novaLine += '/';
        }
        System.out.print(novaLine + "");
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
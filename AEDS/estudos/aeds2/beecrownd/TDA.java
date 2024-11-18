import java.util.Scanner;

public class TDA {
    public static int operacao(String line){
        switch(line){
            case "+": return 0;
            case "-": return 1;
            case "*": return 2;
            case "/": return 3;
            default: return -1;
        }
    }
    public static void calcular(String line){
        String[] novaLine = line.split(" ");
        int pos = 0;
        int result1 = 0, result2 = 0, result3 = 0, result4 = 0;

        int numA = Integer.parseInt(novaLine[0]);
        int denA = Integer.parseInt(novaLine[2]);

        int op = operacao(novaLine[3]);

        int numB = Integer.parseInt(novaLine[4]);
        int denB = Integer.parseInt(novaLine[6]);
       
        int denominador = denA * denB;

        result1 = (denominador/denA) * numA;
        result2 = (denominador/denB) * numB;
        
        if(op == 0){
            result3 = result1 + result2; 
        } else if(op == 1){
            result3 = result1 - result2; 
        } else if(op == 2){
            result3 = numA * numB; 
            result4 = denA * denB;
        } else {
            result3 = (numA*denB);
            result4 = (numB*denA);
        }
        
        if(op == 0 || op == 1){
            if(result3 % 2 == 0 && denominador % 2 == 0){
                int simplificar1 = result3 / 2;
                int simplificar2 = denominador / 2;
                System.out.println(result3 + "/" + denominador + " = " + simplificar1 + "/" + simplificar2);
            } else {
                System.out.println(result3 + "/" + denominador + " = " + result3 + "/" + denominador);
            }
        } else {
            int simplificar1  = 0;
            int simplificar2 = 0;
            if(result3 % denB == 0 && result4 % denB == 0){
                simplificar1 = result3 / denB;
                simplificar2 = result4 / denB;
            } else if(result3 % 2 == 0 || result4 % 2 == 0) {
                simplificar1 = result3 / 2;
                simplificar2 = result4 / 2;
            }
            System.out.println(result3 + "/" + result4 + " = " + simplificar1 + "/" + simplificar2);
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        String line;
        for(int i=0; i < n; i++){
            line = sc.nextLine();
            calcular(line);
        }


        sc.close();
    }
}
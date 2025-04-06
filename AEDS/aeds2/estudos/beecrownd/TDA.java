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
    public static int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b,a%b);
    }
     
    public static void simplificar(int r1, int r2){
        int mdc = gcd(r1, r2);

        if(mdc < 0){
            mdc = mdc*(-1);
        }
        int result1 = r1 / mdc;
        int result2 = r2 / mdc;

        System.out.println(result1 + "/" + result2);
    }

    public static void calcular(String line){
        String[] novaLine = line.split(" ");
        int result1 = 0, result2 = 0;

        int numA = Integer.parseInt(novaLine[0]);
        int denA = Integer.parseInt(novaLine[2]);

        int op = operacao(novaLine[3]);

        int numB = Integer.parseInt(novaLine[4]);
        int denB = Integer.parseInt(novaLine[6]);
        
        if(op == 0){
            result1 = (numA*denB + numB*denA);
            result2 =  (denA * denB);
        } else if(op == 1){
            result1 = (numA * denB - numB*denA);
            result2 =  (denA * denB);
        } else if(op == 2){
           result1 = (numA * numB);
           result2 =  (denA * denB);
        } else {
           result1 = (numA * denB); 
           result2 =  (numB * denA);
        }
        System.out.print(result1 + "/" + result2 + " = ");
        simplificar(result1, result2);
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
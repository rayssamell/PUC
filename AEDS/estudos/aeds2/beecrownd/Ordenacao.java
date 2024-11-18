import java.util.Scanner;

public class Ordenacao {

    public static void swap(String[] frase, int i, int j){
        String tmp = frase[i];
        frase[i] = frase[j];
        frase[j] = tmp;
    }
    
    public static void ordenar(String f){
        String[] frase = f.split(" ");
        int n = frase.length;
        int last = n - 1;

        for(int i=n-1; i >=0 ; i--){
            int newSwap = 0;
            for(int j = n-i-1; j > 0; j--){
                if(frase[j].length() > frase[j-1].length()){
                    swap(frase, j, j-1);
                    newSwap = j;
                }
            }
            if(newSwap == 1) i = frase.length;
            else last = newSwap;
            
        }
        for(int i=0; i < n; i++){
            System.out.print(frase[i]);
            if (i < frase.length - 1) { 
                System.out.print(" ");
            }
        }
        
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        sc.nextLine();

        for(int i=0; i < n; i++){
            String f = sc.nextLine();
            ordenar(f);
            System.out.println();
        }

        sc.close();
    }    
}

import java.util.Scanner;

public class Cartas {
    private int[] array;
    private int n;

    public Cartas(int tamanho){
        array = new int[tamanho];
        n = 0;
    }

    public  int desempilhar(){
        if(n == 0) System.out.println("ERRO");

        int resp = array[0];
        n--;
        for(int i=0; i < n; i++){
            array[i] = array[i+1];
        }
        return resp;
    }
    public void empilhar(int valor){
        if(n >= array.length) System.out.println("ERRO");

        array[n++] = valor;
        //n++;
    }

    public void baralho(int x){
        for(int i=0; i < x; i++){
            empilhar(i+1);
        }

        int j = 0;
        int[] discarted = new int[x-1];
        while(n > 1){
            discarted[j++] = desempilhar();
            empilhar(desempilhar());

        }
         // Imprime as cartas descartadas
        System.out.print("Discarded cards: ");
        for(int i = 0; i < j; i++){
            System.out.print(discarted[i]);
            if(i < j - 1) {
                System.out.print(", ");
            }
        }

        // Imprime a carta restante
        System.out.println("\nRemaining card: " + array[0]);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();

        if(x >= 1 && x <= 50){

            while(x != 0){
                Cartas c = new Cartas(x);
                c.baralho(x);
                x = sc.nextInt();
            }
        }
        sc.close();
    }


}
import java.util.Scanner;

public class Cartas {
    private int[] cartas;
    private int n;
    private int r;
    private int[] removidos;

    public Cartas(int tam){
        cartas = new int[tam];
        removidos = new int[tam];
        r = 0;
        n = 0;
    }

    public void inserir(int x){
        cartas[n] = x;
        n++;
    }

    public int remover(){
        int remover = cartas[0];
        n--;
        for(int i=0; i < n; i++){
            cartas[i] = cartas[i+1];
        }
        return remover;
    }

    public void preencher(int tam){
        for(int i=1; i <= tam; i++){
            inserir(i);
        }
    }

    public void mostrar(){
        System.out.print("Discarded cards: ");
        for(int x=0; x < r; x++){
            System.out.print(removidos[x]);
            if(x != r - 1){
                System.out.print(", ");
            }
        }
        System.out.println();
        System.out.println("Remaining card: " + cartas[n]);
    }

    public void setRemover(int removido){
        removidos[r] = removido;
        r++;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = 0;

        while((n = sc.nextInt()) != 0){
            Cartas cartas = new Cartas(n);
            cartas.preencher(n);

            int i = n-1;

            while(i > 0){
                int removido = cartas.remover();
                cartas.setRemover(removido);
                int r = cartas.remover();
                cartas.inserir(r);
                i--;
            }
            cartas.mostrar();
        }

        sc.close();
    }
}

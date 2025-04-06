import java.util.Scanner;
import java.util.ArrayList;

public class Trilhos {
    private int n;
    private String[] array;

    public Trilhos(int tam){
        this.n = 0;
        this.array = new String[tam]; 
    }

    public void inserir(String x){
        System.out.print("I");
        array[n] = x;
        n++; 
    }

    public String remover(){
        System.out.print("R");
        return array[--n];
    }

    public static void ordenar(ArrayList<String> vagoes, ArrayList<String> saida){
        int t = vagoes.size();
        Trilhos pilha = new Trilhos(t);
        for (int i = 0; i < t; i++) {
            if (vagoes.get(i).equals(saida.get(t - i - 1))) {
                pilha.inserir(vagoes.get(i));
            } else {
                if(vagoes.get(i-1).equals(saida.get(i))){
                    pilha.inserir(vagoes.get(i));
                    pilha.remover();
                } else {
                    pilha.inserir(vagoes.get(i));
                }
            }
        }
        while (pilha.n > 0) {
            pilha.remover();
        }
        System.out.println();
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<String> vagoes = new ArrayList<>();
        ArrayList<String> saida = new ArrayList<>();

        for(int i=0; i < n; i++){
            vagoes.add(sc.next());
        }

        for(int i=0; i < n; i++){
            saida.add(sc.next());
        }

        ordenar(vagoes, saida);

        sc.close();
    }
}

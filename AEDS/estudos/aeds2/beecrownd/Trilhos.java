import java.util.Scanner;
import java.util.ArrayList;

public class Trilhos {
    private int n;
    String[] array;

    public Trilhos(int tam){
        this.n = 0;
        this.array = new String[tam]; 
    }

    public void inserir(String x){
        array[n] = x;
         n++; 
    }

    public String remover(){
        return array[--n];
    }

    public static void ordenar(ArrayList<String> vagoes, ArrayList<String> saida){
        int t = vagoes.size();
        Trilhos pilha = new Trilhos(t);
        String ordem = "";
        String sequencia = "";
        for (int i = 0; i < t; i++) {
            if (vagoes.get(i).equals(saida.get(t - i - 1))) {
                pilha.inserir(vagoes.get(i));
                //sequencia += "I";
            } else {
                pilha.inserir(vagoes.get(i));
                sequencia += "I";
                i++;
                ordem += pilha.remover();
                sequencia += "R";
                pilha.inserir(vagoes.get(i));
                sequencia += "I";
            }
        }
        while (pilha.n > 0) {
            ordem += pilha.remover();
            sequencia += "R";
        }
        System.out.print(ordem);
        System.out.println();
        System.out.println(sequencia);
        
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

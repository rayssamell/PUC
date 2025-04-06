import java.util.Scanner;

public class Tabela {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        for(int i=0; i<n; i++){
            int m = sc.nextInt();
            int c = sc.nextInt();
            Hash hash = new Hash(m);
            for(int j=0; j < c; j++){
                int v = sc.nextInt();
                hash.inserir(v);
            }
            hash.mostrar();
            System.out.println();
        }

        sc.close();
    }
}

class Hash {
    public Lista[] tabela;
    public int tamanho;
    final int NULO = -1;

    public Hash(int tamanho){
        tabela = new Lista[tamanho];
        this.tamanho = tamanho;
        for (int i = 0; i < tamanho; i++) {
            tabela[i] = new Lista();
        }
    }

    int hash(int x){
        return x % tamanho;
    }

    void inserir(int x){
        int pos = hash(x);
        tabela[pos].inserirFim(x);
    }

    void mostrar(){
        for(int i=0; i < tamanho; i++){
            System.out.print(i + " -> ");
            tabela[i].mostrar();
        }
    }
}

class Lista {
    public Celula primeiro, ultimo;
    
    public Lista(){
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserirFim(int x){
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    public void mostrar(){
        for(Celula i=primeiro.prox; i != null; i=i.prox){
            System.out.print(i.elemento + " -> ");
        }
        System.out.println("\\");
    }
        
}

class Celula {
    public int elemento;
    public Celula prox;

    public Celula(){
        this(0);
    }
    public Celula(int elemento){
        this.elemento = elemento;
        prox = null;
    }
}
import java.util.Scanner;

public class Time {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Lista list = new Lista(n);

        for(int i=0; i < n; i++){
            Duendes d = new Duendes();

            String nome = sc.next();
            int idade = sc.nextInt();

            list.setList(nome, idade);
        }
        list.ordenar();
        list.mostrar();

        sc.close();
    }
}

class Duendes {
    public String nome;
    public int idade;

    public Duendes(){
        nome = "";
        idade = 0;
    }
}

class Lista {
    private Duendes[] duendes;
    private int tam;

    public Lista(int n){
        duendes = new Duendes[n];
        for (int i = 0; i < n; i++) {
            duendes[i] = new Duendes(); // Inicializa cada posição do array.
        }
        tam = 0;
    }

    public void setList(String nome, int idade){
        duendes[tam].nome = nome;
        duendes[tam].idade = idade;
        tam++;
    }

    public void swap(int i, int j){
        Duendes tmp = duendes[i];
        duendes[i] = duendes[j];
        duendes[j] = tmp;
    }
    public void ordenar(){
        for(int i=0; i < tam; i++){
            for(int j=0; j < tam-i-1; j++){
                if(duendes[j].idade == duendes[j+1].idade){
                    if(duendes[j].nome.compareTo(duendes[j+1].nome) < 0){
                        swap(j, j+1);
                    }
                }
                if(duendes[j].idade < duendes[j+1].idade){
                    swap(j, j+1);
                }
            }
        }
    }

    public void mostrar() {
        int time = tam / 3; // Número de times
        Pilha pilha[] = new Pilha[time];
    
        // Inicializa as pilhas para cada time
        for (int i = 0; i < time; i++) {
            pilha[i] = new Pilha(tam / time + 1); // Capacidade ajustada dinamicamente
        }
    
        // Distribui os duendes de forma cíclica entre os times
        for (int i = 0; i < tam; i++) {
            int t1 = i % time; // Define o índice do time
            pilha[t1].empilhar(duendes[i]);
        }
    
        // Exibe os duendes de cada time
        for (int i = 0; i < time; i++) {
            Pilha pilhaTemp = new Pilha(tam / time + 1);
    
            // Transfere os elementos da pilha para a pilha temporária
            while (pilha[i].tam > 0) {
                pilhaTemp.empilhar(pilha[i].desempilhar());
            }
    
            // Exibe os elementos da pilha temporária
            System.out.println("Time " + (i + 1) + ":");
            while (pilhaTemp.tam > 0) {
                Duendes duende = pilhaTemp.desempilhar();
                System.out.println(duende.nome + " " + duende.idade);
            }
            System.out.println();
        }
    }
}

class Pilha{
    private Duendes[] duendes;
    public int tam;

    public Pilha(int n){
        duendes = new Duendes[n];
        tam = 0;
    }

    public void empilhar(Duendes duende){
        duendes[tam] = duende;
        tam++;
    }

    public Duendes desempilhar(){
        return duendes[--tam]; 
    }
}
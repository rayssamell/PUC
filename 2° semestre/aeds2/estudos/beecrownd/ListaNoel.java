import java.util.Scanner;

public class ListaNoel {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int comportados = 0, nComportados =0;

        Lista lista = new Lista();

        int n = sc.nextInt();
        for(int i=0; i < n; i++){
            String caractere = sc.next();
            String nome = sc.next();
            lista.inserir(nome);

            if(caractere.equals("+")){
                comportados++;
            } else {
                nComportados++;
            }
        }
        lista.quicksort();
        lista.mostrar();
        
        System.out.println();
        System.out.println("Se comportaram: " + comportados + " | Nao se comportaram: " + nComportados);

        sc.close();
    }
}

class Lista {
    private String[] nome;
    private int tam;

    public Lista(){
        nome = new String[100];
        tam = 0;
    }

    public void inserir(String nome){
        this.nome[tam] = nome;
        tam++;
    }

    public void swap(int i, int j){
        String tmp = nome[i];
        nome[i] = nome[j];
        nome[j] = tmp;
    }

    public void quicksort(int esq, int dir){
        int i =esq, j = dir;
        String pivo = nome[(esq+dir)/2];

        while(i <= j){
            while(nome[i].compareTo(pivo) < 0) i++;
            while(nome[j].compareTo(pivo) > 0) j--;

            if(i <= j){
                swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j) quicksort(esq, j);
        if (i < dir) quicksort(i, dir);
    }

    public void quicksort(){
        quicksort(0, tam-1);
    }
    
    public void mostrar(){
        for(int i=0; i < tam; i++){
            System.out.println(nome[i]);
        }
    }
}

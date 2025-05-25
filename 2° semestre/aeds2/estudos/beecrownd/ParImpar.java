import java.util.Scanner;

public class ParImpar {
    int n; //tamanho
    int[] array;

    public ParImpar(int tam){
        array = new int[tam];
        n = 0;
    }

    public void empilhar(int x) throws Exception{
        if(array.length == n){
            throw new Exception("Pilha Cheia");
        }

        array[n] = x;
        n++;
    }

    public void swap(int[] array, int i, int j){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    public void quicksort(){
        quicksort(0, n-1);
    }
    public void quicksort(int esq, int dir){
        int i = esq, j = dir;
        int pivo = array[(esq+dir)/2];

        while(i <= j){
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <= j){
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if (esq < j)  quicksort(esq, j);
        if (i < dir)  quicksort(i, dir);
    }

    public void mostrarCrescente(){
        for(int i=0; i < n; i++){
            System.out.println(array[i]);
        }
    }

    public void mostrarDecrescente(){
        for(int i=n-1; i >= 0; i--){
            System.out.println(array[i]);
        }
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        ParImpar p1 = new ParImpar(n);
        ParImpar p2 = new ParImpar(n);

        for(int i=0; i < n; i++){
            int num = sc.nextInt();
            if(num % 2 == 0){
                p1.empilhar(num);
            } else{
                p2.empilhar(num);
            }
        }
        p1.quicksort();
        p2.quicksort();

        p1.mostrarCrescente();
        p2.mostrarDecrescente();

        sc.close();
    }
}

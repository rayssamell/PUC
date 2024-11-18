package quaseOrdenados;
import java.util.Date;

public class Quicksort {
    private int[] array;
    private int n;

    public Quicksort() {
        array = new int[100];
        n = array.length;
    }

    public Quicksort(int tam) {
        array = new int[tam];
        n = array.length;
    }

    /**
     * Produz um array modo quaseOrdenado
     */
    public void quaseOrdenados() {
        int limite = (int)(0.1 * n);
        for (int i = 0; i < n; i++) {
            array[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            if(limite % i == 0){
                swap(limite, i+5);
            }
        }
    }

    /**
     * Algoritmo de ordenacao Quicksort.
     */
    public void sort() {
        QuickSortFirstPivot(0, n - 1);
    }

    public void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /**
     * Algoritmo de ordenacao Quicksort.
     * @param int esq inicio do array a ser ordenado
     * @param int dir fim do array a ser ordenado
     */
    private void QuickSortFirstPivot(int esq, int dir) {
        int i = esq, j = dir;
        int pivo = array[esq]; // Seleciona o pivô como o elemento do meio
        while (i <= j) {
            while (array[i] < pivo) i++;
            while (array[j] > pivo) j--;
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        }
        // Chama recursivamente para as duas subarrays
        if (esq < j) QuickSortFirstPivot(esq, j);
        if (i < dir) QuickSortFirstPivot(i, dir);
    }

    /**
     * Mostra os elementos do array.
     */
    public void mostrar() {
        System.out.print("[");
        for (int i = 0; i < n; i++) {
            System.out.print(array[i]);
            if (i < n - 1) {
                System.out.print(", "); // Adiciona vírgula entre os elementos
            }
        }
        System.out.println("]");
    }

    /**
	 * Retorna o timestamp atual
	 * @return timestamp atual
	 */
	public long now(){
		return new Date().getTime();
	}
    
    public static void main(String[] args) {
        Quicksort quickFirst = new Quicksort();
        double inicio, fim;

        quickFirst.quaseOrdenados();
        inicio = quickFirst.now();
        quickFirst.sort();
        fim = quickFirst.now();

        System.out.println("------ Vetor com 100 elementos -------");
        quickFirst.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s.");   
        System.out.println();

        System.out.println("------ Vetor com 1000 elementos -------");
        Quicksort quickSecond = new Quicksort(1000);
        quickSecond.quaseOrdenados();
        inicio = quickSecond.now();
        quickSecond.sort();
        fim = quickSecond.now();
        quickSecond.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s."); 
        System.out.println();

        System.out.println("------ Vetor com 10000 elementos -------");
        Quicksort quickThirst = new Quicksort(10000);
        quickThirst.quaseOrdenados();
        inicio = quickThirst.now();
        quickThirst.sort();
        fim =  quickThirst.now();
        quickThirst.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s."); 
    }
}

package random;
import java.util.Random;
import java.util.Date;

public class Quicksort4 {
    private int[] array;
    private int n;

    public Quicksort4() {
        array = new int[100];
        n = array.length;
    }

    public Quicksort4(int tam) {
        array = new int[tam];
        n = array.length;
    }

     /**
	 * Produz um array ordenado de modo crescente.
	 */
	public void crescente() {
		for (int i = 0; i < n; i++) {
			array[i] = i;
		}
	}

    /**
	 * Produz um array com numeros aleatorios.
	 */
	public void aleatorio() {
		Random rand = new Random();
		crescente();	
		for (int i = 0; i < n; i++) {
			swap(i, Math.abs(rand.nextInt()) % n);
		}
	}

    /**
     * Algoritmo de ordenacao Quicksort.
     */
    public void sort() {
        QuickSortMedianOfThree(0, n - 1);
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
    private void QuickSortMedianOfThree(int esq, int dir) {
        int i = esq, j = dir;
        int meio = (esq+dir)/2;
        int pivo = (array[esq] + array[dir] + array[meio])/3; 

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
        if (esq < j) QuickSortMedianOfThree(esq, j);
        if (i < dir) QuickSortMedianOfThree(i, dir);
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
        Quicksort4 quickFirst = new Quicksort4();
        double inicio, fim;

        quickFirst.aleatorio();
        quickFirst.mostrar();
        System.out.println();
        inicio = quickFirst.now();
        quickFirst.sort();
        fim = quickFirst.now();

        System.out.println("------ Vetor com 100 elementos -------");
        quickFirst.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s.");   
        System.out.println();

        System.out.println("------ Vetor com 1000 elementos -------");
        Quicksort4 quickSecond = new Quicksort4(1000);
        quickSecond.aleatorio();
        quickSecond.mostrar();
        System.out.println();
        inicio = quickSecond.now();
        quickSecond.sort();
        fim = quickSecond.now();
        quickSecond.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s."); 
        System.out.println();

        System.out.println("------ Vetor com 10000 elementos -------");
        Quicksort4 quickThirst = new Quicksort4(10000);
        quickThirst.aleatorio();
        quickSecond.mostrar();
        System.out.println();
        inicio = quickThirst.now();
        quickThirst.sort();
        fim =  quickThirst.now();
        quickThirst.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s."); 
    }
}

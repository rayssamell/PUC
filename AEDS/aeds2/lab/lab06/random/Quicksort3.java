package random;

import java.util.Date;
import java.util.Random;

public class Quicksort3 {
    private int[] array;
    private int n;

    public Quicksort3() {
        array = new int[100];
        n = array.length;
    }

    public Quicksort3(int tam) {
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
        QuickSortRandomPivot(0, n - 1);
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
    private void QuickSortRandomPivot(int esq, int dir) {
        int i = esq, j = dir;
        Random rand = new Random();
        
        int pivo = array[rand.nextInt(dir - esq + 1) + esq]; // Seleciona o pivô como o elemento do meio

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
        if (esq < j) QuickSortRandomPivot(esq, j);
        if (i < dir) QuickSortRandomPivot(i, dir);
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
        Quicksort3 quickFirst = new Quicksort3();
        double inicio, fim;

        quickFirst.aleatorio();
        inicio = quickFirst.now();
        quickFirst.sort();
        fim = quickFirst.now();

        System.out.println("------ Vetor com 100 elementos -------");
        quickFirst.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s.");   
        System.out.println();

        System.out.println("------ Vetor com 1000 elementos -------");
        Quicksort3 quickSecond = new Quicksort3(1000);
        quickSecond.aleatorio();
        inicio = quickSecond.now();
        quickSecond.sort();
        fim = quickSecond.now();
        quickSecond.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s."); 
        System.out.println();

        System.out.println("------ Vetor com 10000 elementos -------");
        Quicksort3 quickThirst = new Quicksort3(10000);
        quickThirst.aleatorio();
        inicio = quickThirst.now();
        quickThirst.sort();
        fim =  quickThirst.now();
        quickThirst.mostrar();
        System.out.println();
        System.out.println("Tempo para ordenar: " + (fim-inicio)/1000.0 + " s."); 
    }
}

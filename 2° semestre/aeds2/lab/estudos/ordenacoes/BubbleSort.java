import java.util.Random;

public class BubbleSort {
    public static void swap(int[] array, int i, int j){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    public static void ordenar(int[] array){
        for(int i=0; i < array.length-1; i++){
            for(int j=0; j < array.length- i-1; j++){
                if(array[j] > array[j+1]){
                    swap(array, j, j+1);
                }
            }
        }
    }
    public static void mostrar(int[] array){
        System.out.println("---Array Ordenado -----");
        for(int i=0; i < array.length; i++){
            System.out.print("   " + array[i]);
        }
    }
    //metodo principal
    public static void main(String[] args){
        int[] array = new int[10];
        Random gerador = new Random();

        for (int i = 0; i < 10; i++) {
            array[i] = gerador.nextInt(26);
            System.out.print("   " + array[i]);
        }

        System.out.println();
        ordenar(array);
        mostrar(array);
        System.out.println();
    }
}
import java.util.Random;

public class BubbleSort {

    public static void swap(int[] array, int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void bubble(int[] array){
        int last = array.length - 1;
        for(int i=0; i < array.length - 1; i++){
            int newSwap = 0;
            for(int j=0; j < last; j++){
                if(array[j] > array[j+1]){
                    swap(array, j, j+1);
                    newSwap = j;
                }
            }
            if(newSwap == 1)
                i = array.length;
            else 
                last = newSwap;
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
        bubble(array);
        mostrar(array);
        System.out.println();
    }
}
import java.util.Scanner;

public class Sort {
    public static void swap(int[] array, int i, int j){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    public static void ordenar(int[] array){
        for(int i=0; i < array.length; i++){
            for(int j=i+1; j < array.length; j++){
                if(array[i] > array[j]){
                    swap(array, i, j);
                }
            }
        }
        for(int i=0; i < array.length; i++){
            System.out.println(array[i]);
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int[] array1 = new int[3];
        int[] array2 = new int[3];
        for(int i=0; i < array1.length; i++){
            array1[i] = sc.nextInt();
            array2[i] = array1[i];
        }

        ordenar(array1);
        System.out.println();
        for(int i=0; i < array2.length; i++){
            System.out.println(array2[i]);
        }
        sc.close();
    }
}

import java.util.Scanner;

public class Vagoes {
    public static void swap(int[] array, int i, int j){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    public static void contarSwap(int l, int[] array){
        int cont = 0;
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - 1 - i; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array, j, j + 1);
                    cont++;
                }
            }
        }
        System.out.println("Optimal train swapping takes " + cont + " takes");
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int[] array;
        int n = sc.nextInt();
        int l = 0;
        for(int i=0; i < n; i++){
            l = sc.nextInt();
            array = new int[l];
            for(int j=0; j < l; j++){
                array[j] = sc.nextInt();
            }
            contarSwap(l, array);
        }
        sc.close();
    }
}

   

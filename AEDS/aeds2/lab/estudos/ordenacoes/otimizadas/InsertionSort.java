import java.util.Random;

public class InsertionSort{
    public static int pesquisaBinaria(int []array, int dir, int valor){
        int esq = 0;
        while(esq <= dir){
            int meio = (esq + dir)/2;
            if(array[meio] == valor){
                return meio + 1;
            } else if(array[meio] > valor){
                dir = meio - 1;
            } else {
                esq = meio + 1;
            }
        }
        return esq;
    }
    public static void insertion(int[] array){
        for(int i=1; i < array.length; i++){
            int temp = array[i];
            int j = i - 1;
            int pesq = pesquisaBinaria(array, i, array[i]);
            while(j >= pesq){
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = temp;
        }
    }
    public static void mostrar(int[] array){
        System.out.print("---Array Ordenado ---");
        for(int i=0; i < array.length; i++){
            System.out.print("  " + array[i]);
        }
    }
    public static void main(String[] args){
        Random gerador = new Random();
        int[] array = new int[10];

        for(int i=0; i < array.length; i++){
            array[i] = gerador.nextInt(26);
            System.out.print("  " + array[i]);
        }
        System.out.println();
        insertion(array);
        mostrar(array);
        System.out.println();    
    }
}
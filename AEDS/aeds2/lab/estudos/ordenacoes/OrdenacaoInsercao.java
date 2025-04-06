import java.util.Random;

public class OrdenacaoInsercao {
    public static void ordenar(int[] array){
        for(int i=1; i < array.length; i++){
            int tmp = array[i];
            int j = i - 1;
            while((j >= 0) && (array[j] > tmp)){
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = tmp;
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
        ordenar(array);
        mostrar(array);
        System.out.println();    
    }
}
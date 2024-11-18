import java.util.Random;

public class OrdenacaoSelecao {
    //metodo de swap
    public static void swap(int[] array, int menor, int i){
        int temp = array[menor];
        array[menor] = array[i];
        array[i] = temp;
    }
    //metodo de ordenacao por selecao
    public static void selecao(int[] array){
        for(int i=0; i < array.length-1; i++){
            int menor = i;
            for(int j=(i+1); j < array.length; j++){
                if(array[menor] > array[j]){
                    menor = j;
                }
            }
            swap(array, menor, i);
        }
    }
    //metodo para mostrar arranjo
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
        selecao(array);
        mostrar(array);
        System.out.println();
    }
}
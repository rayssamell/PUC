import java.util.Scanner;

public class Ordenacao {
    public static void swap(String[] array, int i, int j){
        String temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void ordenar(String[] array){    
        int last = array.length-1;
        for(int i=0; i < array.length-1; i++){
            int newSwap = -1;
            for(int j=0; j < last; j++){
                if (array[j].length() < array[j + 1].length()) {
                    swap(array, j, j + 1);
                    newSwap = j;
                }
            }
            if(newSwap == -1) i = array.length;
            else last = newSwap;
        }

        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); //para limpar o buffer da quebra de linha
        
        for (int i = 0; i < n; i++) {
            String frase = sc.nextLine(); // Lê uma frase inteira
            String[] palavras = frase.split("\\s+"); // Divide a frase em palavras ignorando múltiplos espaços
            ordenar(palavras); // Envia o array de palavras para processamento
            System.out.println();
        }
            //ordenar(array);
        
        //ordenar(array);
        sc.close();
    }
}
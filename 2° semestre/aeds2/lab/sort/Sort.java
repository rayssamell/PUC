import java.util.Scanner;

public class Sort {
	
	//funcao para realizar a troca de valores
	private static void swap(int[] array, int i, int j) {
    	int temp = array[i];
    	array[i] = array[j];
    	array[j] = temp;
	}

	//funcao para ordenar o arranjo
	public static void ordenar(int[] array, int m){

		for(int i= 0; i < array.length-1; i++){
    		for(int j = 0; j < array.length - i -1; j++){

				int mA = array[j] % m;
				int mB = array[j+1] % m;

				//se o modulo de A e' maior que o modulo de B
      			if (mA > mB) {
		            swap(array, j, j + 1); //chama a funcao de troca
            	} else if (mA == mB) { //se os modulos sao iguais 
		            boolean isImparA = array[j] % 2 != 0;  
		            boolean isImparB = array[j + 1] % 2 != 0;

		            // Se ambos sao impares ou um e' impar e o outro e' par, ordenar pelo maior numero
		            if ((isImparA || !isImparA) && isImparB  && array[j] < array[j + 1]) {
		                swap(array, j, j + 1); //chama a funcao de troca
		            } 
		            // Se ambos sao pares, ordenar pelo menor numero
		            else if (!isImparA && !isImparB && array[j] > array[j + 1]) {
		                swap(array, j, j + 1); //chama a funcao de troca
		            }
                }
        	}
   
  		} // fim da ordenacao
	    
		//mostrar array ordenado
		for(int i = 0; i < array.length; i++){
			System.out.println(array[i]);								
		}
	}

	//metodo princicipal
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int valor;

		int n = sc.nextInt();
		int m = sc.nextInt();

		//enquantos ambos forem diferente de 0
		while(n != 0 && m != 0){
			int[] array = new int[n];
			for(int i = 0; i < n; i++){			
				array[i] = sc.nextInt();			
			}
			System.out.print(n);
			System.out.println(" " + m);
			ordenar(array, m);
			
			n = sc.nextInt();
			m = sc.nextInt();
		}

		System.out.println("0 0");

		sc.close();	
	}



}


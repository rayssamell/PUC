#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Array */

/* Method_01 */
void method_01(void){
	int n = 0, x = 0;
	int valor = 0;
	
	printf("Digite o tamanho: ");
	scanf("%d", &n);
	
	
	if(n > 0){
		int array[n];
		while(x < n){
			printf("\nValor: ");
			scanf("%d", &valor);
			
			if(valor > 0 && valor % 2 == 0){
				array[x] = valor;
			}
			else{
				array[x] = 0;
			}
			x = x + 1;
		}
		
		for(x=0; x < n; x = x + 1){
			printf("\nArray[%d]: %d\n", x, array[x]);
		}
	}
	else{
		printf("\nTamanho invalido.\n");
	}
	
}

/* Method_02 */
void lerArquivo(chars fileName, int array[]){
	FILE *arquivo = fopen(fileName, "rt");
	int n = 0, x = 0, y = 0;
	fscanf(arquivo, "%d", &n);
	if(n > 0){
		while(!feof(arquivo) && x < n){
			fscanf(arquivo, "%d", &y);
			if(y > 0 && y % 2 == 0){
				array[x] = y;
			}
			x = x + 1;
		}
	}
}

void print_Array(int array[], int n){
	for(int x = 0; x < n; x= x + 1 ){
		printf("arranjo [%d] =  %d\n", x, array[x]);
	}
}


void method_02(void){
	int array[10];
	lerArquivo("METHOD2.TXT", array);
	print_Array(array, 10);
}

/* Method_03 */
int gerarInt(int inferior, int superior,int n, int array[]){
	int x = 0, y = 0;
	while(x < n ){
		y = rand() % superior - inferior;
		array[x] = y;
		x = x + 1;
	}
}

void method_03(void){
	int n = 0;
	int inferior= 0, superior= 0;
	
	printf("\nDigite a quantidade: ");
	scanf("%d", &n);
	
	if(n > 0){
		int array [n];
		printf("\nDigite o limite inferior: ");
		scanf("%d", &inferior);
		printf("\nDigite o limite superior: ");
		scanf("%d", &superior);
		
		gerarInt(inferior,superior,n,array);
		print_Array(array,n);
	}
}

/* Method_04 */
int menorPar(int array[], int n){
	int menor = array[0];
	for(int x = 0; x < n; x = x + 1){
		if(array[x] < menor){
			menor = array[x];
		}
	}
	return menor;
}

void method_04(void){
	int n = 0;
	printf("\nDigite a quantidade: ");
	scanf("%d", &n);
	
	if(n > 0){
		int array[n];
		lerArquivo("METHOD2.TXT",array);
		int menor = menorPar(array,n);
		
		printf("\nMenor par no arquivo: %d", menor);
	}
}


int main(){
	int opcao = 0;
	printf ( "%s\n", "Exemplos 0800 - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
	
	do{
		printf("\n%s\n", "\nOpcoes: ");
		printf("\n%s", "0 - Terminar");
		printf("\n%s", "1 - Metodo_01	2 - Metodo_02");
		printf("\n%s", "3 - Metodo_03	4 - Method_04");
		printf("\n%s", "5 - Metodo_05	6 - Method_06");
		printf("\n%s", "7 - Metodo_07	8 - Method_08");
		printf("\n%s", "9 - Metodo_09	10 - Method_10");
		
		printf("\n%s", "\nOpcao = ");
		scanf("%d", &opcao);
		getchar();
		// para mostrar a opcao lida
		printf ( "\n%s%d", "Opcao =  ", opcao );
		getchar();
		//testar valor
		switch (opcao) {
		case 1:
			method_01();
			break;
		default:
			printf("Erro: opcao invalida.");
			break;
		}
		
	}while(opcao != 0);
	
	printf("Aperte ENTER para terminar.");
	getchar();
	return(0);
	
}


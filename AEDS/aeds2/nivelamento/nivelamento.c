#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Method_01 */
bool isContido(int x, int array[], int n){
	for(int i = 0; i < n; i++){
		if(x == array[i])
			return true;
	}
	return false;
}

void method_01(void){
	int n = 0, num = 0;
	
	printf("Digite a quantidade: ");
	scanf("%d", &n); getchar();
	
	if( n > 0 ){
		int array[n];
		
		printf("Digite um numero: ");
		scanf("%d", &num); getchar();
		
		for(int i = 0; i < n; i++){
			scanf("%d", &array[i]);
		}
		if(isContido(num, array, n) == 1){
			printf("%d esta contido no array", num);
		}
		else
			printf("%d nao esta contido no array", num);
	}
	
}

/* Method_02 */
bool contidoMeio(int num, int array[], int n){
	int meio = n / 2;
	
	if (num == array[meio]) {
		return true;
	}
	
	if (num < array[meio]) {
		// Verificar na metade esquerda
		for (int i = 0; i < meio; i++) {
			if (num == array[i]) {
				return true;
			}
		}
	} else {
		// Verificar na metade direita
		for (int i = meio + 1; i < n; i++) {
			if (num == array[i]) {
				return true;
			}
		}
	}
	
	return false;
}

void method_02(void){
	int n = 0, num = 0;
	
	printf("Digite a quantidade: ");
	scanf("%d", &n); getchar();
	
	if( n > 0 ){
		int array[n];
		
		printf("Digite um numero: ");
		scanf("%d", &num); getchar();
		
		for(int i = 0; i < n; i++){
			scanf("%d", &array[i]);
		}
		if(isContido(num, array, n) == 1){
			printf("%d esta contido no array", num);
		}
		else
			printf("%d nao esta contido no array", num);
	}
}

/* Method_03 */
void maiorMenor(int array[]){
	int maior = array[0];
	int menor = array[0];
	
	for(int i = 0; i < 10; i++){
		if(maior < array[i]){
			maior = array[i];
		}
		if(menor > array[i]){
			menor = array[i];
		}
	}
	printf("\nO maior valor e' %d e o menor valor e' %d", maior, menor);
}


void method_03(void){
	int array[10];
	
	for(int i = 0; i < 10; i++){
		scanf("%d", &array[i]);
	}
	maiorMenor(array);
	
}

int main(){
	int opcao = 0;
	printf ( "%s\n", "Exercicios - Programa = v0.0" );
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
		printf("\n%s", "11 - Metodo_11	12 - Method_12");
		
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
		case 2:
			method_02();
			break;
		case 3:
			method_03();
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

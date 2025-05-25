#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Matriz */

void readNegativeDoubleMatrix(int rows, int columns, double negativeMatrix[][columns])
{
	double y = 0;
	for(int i = 0; i < rows; i = i + 1){
		for(int j = 0; j < columns; j = j + 1){
			scanf("%lf", &y);
			if(y < 0){
				negativeMatrix[i][j] = y;
			}
		}
	}
}

void method_01(void){
	int rows = 0, columns = 0;
	
	printf("\nInsira a quantidade de linhas: ");
	scanf("%d", &rows);
	printf("\nInsira a quantidade de colunas: ");
	scanf("%d", &columns);
	
	if(rows > 0 && columns > 0){
		double negativeMatrix[rows][columns];
		
	}
	else{
		printf("\nDimensoes invalidas.\n");
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


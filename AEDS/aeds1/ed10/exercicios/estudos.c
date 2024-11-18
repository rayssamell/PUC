//bibliotecas
#include <stdio.h>
#include "io.h"

const int MAX = 100;
#define null NULL

typedef struct s_int_Array{
	int length;
	ints data;
	int ix;
}int_Array;

typedef int_Array* ref_int_array;

ref_int_array new_int_Array(int n){
	ref_int_array tmpArray = (ref_int_array)malloc(sizeof(int_Array));
	if(tmpArray == NULL){
		printf("Alocacao Invalida.\n");
	}
	else{
		tmpArray->length = 0;
		tmpArray->data = NULL;
		tmpArray->ix = -1;
		if(n > 0){
			tmpArray->length = n;
			tmpArray->data = (int*)malloc(n*sizeof(int));
			if(tmpArray->data == NULL){
				printf("ERRO\n");
				free(tmpArray);
				return NULL;
			}
			tmpArray->ix = 0;
		}
	}
	return tmpArray;
}


/* Method_01 */
ref_int_array RandomIntGenerate(int inferior, int superior, ref_int_array arranjo){
	int gerador = 0;
	while(arranjo->ix < arranjo->length){
		gerador = rand()% superior - inferior;
		arranjo->data[arranjo->ix] = gerador;
		arranjo->ix++;
	}
	for(arranjo->ix = 0; arranjo->ix < arranjo->length; arranjo->ix++){
		printf("%d\n", arranjo->data[arranjo->ix]);
	}
	return arranjo;
}

void fprint_array(chars fileName, ref_int_array arranjo){
	FILE* arquivo = fopen(fileName, "wt");
	fprintf(arquivo, "%d\n", arranjo->length);	
	if(arranjo){
		for(arranjo->ix = 0; arranjo->ix < arranjo->length; arranjo->ix++){
			fprintf(arquivo, "%d\n", arranjo->data[arranjo->ix]);
		}
	}
	fclose(arquivo);
}


void method_01(void){
	int inferior = 0, superior = 0;
	int n = 0;
	ref_int_array arranjo = NULL;
	inferior = IO_readint("Digite o limite inferior: "); getchar();
	superior = IO_readint("\nDigite o limite superior: "); getchar();
	n 		 = IO_readint("\nDigite a quantidade: "); getchar();
	
	arranjo = new_int_Array(n);
	RandomIntGenerate(inferior,superior, arranjo);
	fprint_array("TESTE.TXT", arranjo);
}

int main(){
	int opcao = 0;
	
	do{
		opcao = IO_readint("\nOpcao:  ");
		getchar();
		printf("\nOpcao: %d \n", opcao);
		switch (opcao) {
		case 1:
			method_01();
			break;
		//case 2:
		//	method_02();
		//	break;
		default:
			printf("\nERRO: opcao invalida.\n");
			break;
		}
	}while(opcao != 0);
	
	
	printf("Aperte ENTER para terminar.");
	getchar();
	return(0);
}

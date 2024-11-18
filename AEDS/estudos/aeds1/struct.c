#include <stdio.h>
#include "io.h"

typedef struct s_int_Array{
	int length;
	ints data;
	int ix;
}int_Array;

typedef int_Array* ref_int_Array;

ref_int_Array new_int_Array(int n){
	ref_int_Array tmpArray = (ref_int_Array)malloc(sizeof(int_Array));
	if(tmpArray == NULL){
		IO_printf("\nERRO: falta espaco.\n");
	}
	else{
		tmpArray ->length = 0;
		tmpArray->data    = NULL;
		tmpArray->ix           = -1;
		if(n > 0){
			tmpArray->length = n;
			tmpArray->data   = (ints)malloc(n*sizeof(int));
			tmpArray->ix     = 0;
		}
	}
	return(tmpArray);
}

void printIntArray(ref_int_Array array){
	if(array->data){
		for(array->ix = 0; array->ix < array->length; array->ix++){
			printf("%2d: %d\n", array->ix, array->data[array->ix]);
		}
	}
}

void scanIntArray(int_Array array){
	if(array.length != 0){
		for(array.ix=0; array.ix < array.length; array.ix++){
			scanf("%d", &array.data[array.ix]);
		}
	}
}

void fprintIntArray(chars fileName, ref_int_Array array){
	FILE* arquivo = fopen(fileName, "wt");
	
	//quantidade de dados
	fprintf(arquivo, "%d\n", array->length);
	for(array->ix = 0; !feof(arquivo) && array->ix < array->length; array->ix++){
		fprintf(arquivo, "%d\n", array->data[array->ix]);
	}
	fclose(arquivo);
}

void fscanIntArray(chars fileName, ref_int_Array array){
	FILE* arquivo = fopen(fileName, "rt");
	if(arquivo == NULL){
		printf("\nAquivo sem dados.\n");
	}else{
		fscanf(arquivo, "%d", &array->length);
		for(array->ix=0; !feof(arquivo) && array->ix < array->length; array->ix++){
			fscanf(arquivo, "%d", &array->data[array->ix]);
		}
	}
	fclose(arquivo);
}

int randomIntGenerate(int inferior, int superior, ref_int_Array array){
	if(array->length > 0){
		for(array->ix=0; array->ix < array->length; array->ix++){
			int valor = rand() % superior - inferior;
			array->data[array->ix] = valor;
		}	
	}
}

/* Method_01 */
void method_01(void){
	int n = 0;
	int inferior = 0, superior = 0;
	ref_int_Array array = NULL;
	
	n = IO_readint("\nQuantidade: "); getchar();
	inferior = IO_readint("\nLimite inferior: "); getchar();
	superior = IO_readint("\nLimite superior: "); getchar();
	
	if(n > 0){
		array = new_int_Array(n);	
		randomIntGenerate(inferior, superior, array);
		fprintIntArray("DADOSM01.TXT", array);
	}
	free(array);
	IO_pause("\nAperte ENTER para Continuar.\n");
}

/* Method_02 */
bool arraySearch(int valor, ref_int_Array array){
	bool result = false;
	if(array->length > 0){
		for(array->ix=0; array->ix < array->length && !result; array->ix++){
			result = (valor == array->data[array->ix]);
		}
	}
	return (result);
}

void method_02(void){
	//definir dados
	ref_int_Array array = NULL;
	int valor = 0;
	
	valor = IO_readint("\nDigite o valor: "); getchar();
	array = new_int_Array(10);
	fscanIntArray("DADOSM01.TXT", array);
	bool procurar = arraySearch(valor, array);
	printf("\n Procurar (%d) = %d\n", valor, procurar );
	free(array);
	IO_pause("\nAperte ENTER para Continuar.\n");
}

/* Method_03 */
bool arrayCompare(ref_int_Array arranjo1, ref_int_Array arranjo2){
	bool result = true;
	
	if(arranjo1->length == arranjo2->length){
		for(int x=0; x < arranjo1->length; x++){
			result = (arranjo1->data[x] != arranjo2->data[x]);
		}
	}
	else{
		printf("\nTamanhos incompativeis.\n");
	}
	return (result);
}

void method_03(void){
	ref_int_Array arranjo1 =  NULL;
	ref_int_Array arranjo2 =  NULL;
	
	arranjo1 = new_int_Array(10);
	arranjo2 = new_int_Array(10);
	
	fscanIntArray("DADOSM01.TXT", arranjo1);
	fscanIntArray("METHOD2.TXT",  arranjo2);
	bool resposta = arrayCompare(arranjo1, arranjo2);
	
	if(resposta){
		printf("\nSao diferentes.\n");
	}else{
		printf("\nSao iguais.\n");
	}
	free(arranjo1);
	free(arranjo2);
	IO_pause("\nAperte ENTER para Continuar.\n");
}

/* Method_04 */
ref_int_Array arrayAdd(ref_int_Array arranjo1, int y, ref_int_Array arranjo2){
	ref_int_Array arraySoma = NULL;
	if(arranjo1->length == arranjo2->length){
		arraySoma = new_int_Array(arranjo1->length);
		for(int x=0; x < arranjo1->length; x++){
			arraySoma->data[x] = arranjo1->data[x] + (arranjo2->data[x] * y);
		}
	}
	return (arraySoma);
}

void method_04(void){
	ref_int_Array arranjo1 = new_int_Array(10);
	ref_int_Array arranjo2 = new_int_Array(10);
	
	fscanIntArray("DADOSM01.TXT", arranjo1);
	printIntArray(arranjo1);
	printf("\n");
	fscanIntArray("METHOD2.TXT",  arranjo2);
	printIntArray(arranjo2);
	printf("\nSoma: \n");
	ref_int_Array  arranjo3 = arrayAdd(arranjo1,1,arranjo2);
	printIntArray(arranjo3);
	free(arranjo1);
	free(arranjo2);
	free(arranjo3);
	IO_pause("\nAperte ENTER para Continuar.\n");
}

/* Method_05 */
bool isArrayDecrescent(ref_int_Array array){
	if(array->data != 0){
		int y = array->data[0];
		for(int x=0; x < array->length; x = x + 1){
			if(y > array->data[x]){
				return false;
			}
		}
	}
	return true;
}

void method_05(void){
	ref_int_Array array = new_int_Array(10);
	
	fscanIntArray("METHOD2.TXT", array);
	bool resposta = isArrayDecrescent(array);
	if(resposta){
		printf("\nO arranjo esta na ordem decrescente.\n");
	}else{
		printf("\nO arranjo nao esta na ordem decrescente.\n");
	}
	free(array);
	IO_pause("\nAperte ENTER para Continuar.\n");
}

//--------------Matriz-------------------//

typedef struct s_int_Matrix{
	int rows;
	int columns;
	ints* data;
}int_Matrix;

typedef int_Matrix* ref_int_Matrix;

ref_int_Matrix new_int_matrix(int rows, int columns){
	ref_int_Matrix tmpMatrix = (ref_int_Matrix)malloc(sizeof(int_Matrix));
	
	if(tmpMatrix != NULL){
		tmpMatrix->rows    = 0;
		tmpMatrix->columns = 0;
		tmpMatrix->data	   = NULL;
		
		if(rows >0 && columns > 0){
			tmpMatrix->rows    = rows;
			tmpMatrix->columns = columns;
			tmpMatrix->data    = malloc(rows * sizeof(ints));
			if(tmpMatrix->data){
				for(int x = 0; x < tmpMatrix->rows; x = x + 1){
					tmpMatrix->data[x] = (ints) malloc(columns*sizeof(int)); 
				}
			}
		}
		return(tmpMatrix);
	}
}

void printIntMatrix(ref_int_Matrix matrix){
	if(matrix != NULL && matrix->data != NULL){
		for(int i=0; i < matrix->rows; i = i + 1){
			for(int j = 0; j < matrix->columns; j = j + 1){
				printf("%3d\t", matrix->data[i][j]);
			}
			printf("\n");
		}
	}
}

void fprintIntMatrix(){
	
}

void fscanIntMatrix(chars fileName, ref_int_Matrix matrix){
	FILE* arquivo = fopen(fileName, "rt");
	
	fscanf(arquivo, "%d %d", &matrix->rows, &matrix->columns);
	for(int i =0; i < matrix->rows; i++){
		for(int j =0; j < matrix->columns; j++){
			fscanf(arquivo, "%d", &matrix->data[i][j]);
		}
	}
}

/* Method_06 */

ref_int_Matrix matrixTranspose(ref_int_Matrix matrix){
	if(matrix->rows != 0 && matrix->columns != 0){
		ref_int_Matrix matrixTransposta = new_int_matrix(matrix->columns, matrix->rows);
		for(int i = 0; i < matrix->rows; i = i + 1){
			for(int j = 0; j < matrix->columns; j = j + 1){
				matrixTransposta->data[j][i] = matrix->data[i][j];
			}
		}
	return (matrixTransposta);
	}
}

void method_06(void){
	ref_int_Matrix matrix = new_int_matrix(2,3);
	fscanIntMatrix("MATRIX.TXT", matrix);
	printf("\nOriginal: \n");
	printIntMatrix(matrix);
	ref_int_Matrix matrixTransposta = new_int_matrix(2,3);
	matrixTransposta = matrixTranspose(matrix);
	printf("\nTransposta: \n");
	printIntMatrix(matrixTransposta);
}

/* Method_07 */
bool matrixZero(ref_int_Matrix matrix){
	for(int i = 0; i < matrix->rows; i = i + 1){
		for(int j = 0; j < matrix->columns; j = j + 1){
			if(matrix->data[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}

void method_07(void){
	ref_int_Matrix matrix = new_int_matrix(2,3);
	fscanIntMatrix("MATRIX.TXT", matrix);
	
	bool resposta = matrixZero(matrix);
	if(resposta){
		printf("A matriz contem so zeros.\n");
	}
	else{
		printf("\nA matriz nao contem so zeros.\n");
	}
}

int main(){
	int opcao = 0;
	printf ( "%s\n", "Exercicios 1000 - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
	
	do{
		printf("\n%s\n", "\nOpcoes: ");
		printf("\n%s", " 0 - Terminar");
		printf("\n%s", " 1 - Metodo_01	2 - Metodo_02");
		printf("\n%s", " 3 - Metodo_03	4 - Method_04");
		printf("\n%s", " 5 - Metodo_05	6 - Method_06");
		printf("\n%s", " 7 - Metodo_07	8 - Method_08");
		printf("\n%s", " 9 - Metodo_09	10 - Method_10");
		printf("\n%s", "11 - Metodo_11	12 - Method_12");
		
		printf("\n%s", "\nOpcao = ");
		scanf("%d", &opcao);
		getchar();
		// para mostrar a opcao lida
		printf ( "\n%s%d", "Opcao =  ", opcao );
		getchar();
		//testar valor
		switch (opcao) {
		case 1: method_01(); break;
		case 2: method_02(); break;
		case 3: method_03(); break;
		case 4: method_04(); break;
		case 5: method_05(); break;
		case 6: method_06(); break;
		case 7: method_07(); break;
		default:
			printf("Erro: opcao invalida.");
			break;
		}
		
	}while(opcao != 0);
	
	printf("Aperte ENTER para terminar.");
	getchar();
	return(0);
	
}


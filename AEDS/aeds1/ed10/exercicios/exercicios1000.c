/* Nome: Rayssa Mell de Souza Silva
Matricula: 860210    
----- Exercicios 1000 - Ed10 -----*/

#include <stdio.h>
#include "io.h"

// ----------------------------------------------- definicoes globais
const int MAX = 100; // tamanho maximo

#define null NULL    // referencia nula

typedef              // tipo arranjo em estrutura
struct s_int_Array  //  descritor para arranjo
{                   //   armazenadores
	int  length;      //   tamanho
	int *data  ;      //   referencia para dados
}                   //  fim descritor
int_Array;           // nome do tipo

typedef              // tipo referencia para descritor
int_Array*          //  descritor
ref_int_Array;       // nome do tipo

// reservar area
ref_int_Array new_int_Array ( int n )
{
	// definir dados locais
	ref_int_Array a = null;
	if ( n > 0 )
	{
		a = malloc ( 1 * sizeof (int_Array) );
		if ( a )  // se existir
		{
			a->data = malloc ( n * sizeof (int) );
			if ( a->data ) // se existir
			{
				a->length = n;
			}
		}
	} 
	// retornar a quantidade de dados lida
	return ( a );
} // end new_int_Array( )

/* Method_01 - Gerar valores aleatoriamente dentro de um intervalo*/

//funcao para gerar numeros aleatorios
int RandomIntGenerate(ref_int_Array a, int inferior, int superior){
	int x = 0, y = 0;
	if( a ){
		while(x < a->length){
			y = rand() % superior;
			if(y > inferior && y < superior){
				a->data[x] = y;
				x = x + 1;
			}
		}
		for(x = 0; x < a->length; x = x + 1){
			printf("%d: %d\n", x, a->data[x]);
			
		}
	}
	return 0;
	
}

//funcao para gravar no arquivo
void fprint_int_Array
( ref_int_Array a, chars filename )
{
	// abrir arquivo para gravar texto
	FILE *arquivo = fopen ( filename, "wt" );
	fprintf(arquivo, "%d\n", a->length);
	if ( a ) // se existir
	{
		for ( int x=0; x < a->length; x=x+1 ){   
			fprintf(arquivo, "%d\n", a->data[x]); 
		}
	}
	// fechar arquivo 
	fclose ( arquivo );
} // end fprint_int_Array( )

void method_01(void){
	//identificar
	IO_id("\nMethod_01 - Gerar um valor dentro de um intervalo \n");
	//definir dados
	ref_int_Array a = NULL;
	int n = 0;
	int inferior = 0, superior = 0;
	//ler dados
	inferior = IO_readint("Digite o limite inferior: "); getchar();
	superior = IO_readint("\nDigite o limite superior: "); getchar();
	n 		 = IO_readint("\nDigite a quantidade: "); getchar();
	//chamar funcoes
	a = new_int_Array(n);
	RandomIntGenerate(a, inferior, superior);
	fprint_int_Array(a, "DADOS.TXT");
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_01()

/* Method_02 - Procurar valor inteiro */

//funcao para ler arquivo
int_Array readArrayFromFile(chars fileName){
	FILE *arquivo = fopen(fileName, "rt");
	int_Array a;
	int x = 0, y = 0;
	//ler tamanho
	fscanf(arquivo, "%d", &a.length);
	//se tamanho for nulo
	if ( a.length <= 0 )
	{
		IO_printf ( "\nERRO: Valor invalido.\n" );
		a.length = 0; // nao ha' dados
	}
	else
	{
		// reservar espaco
		a.data = IO_new_ints(a.length);
		//testar existencia
		if(a.data){
			while ( ! feof ( arquivo ) && x < a.length ){
				// ler valor
				fscanf ( arquivo, "%d", &y );
				a.data[x] = y;
				// passar ao proximo
				x = x + 1;
			}
		}
		
	}
	fclose(arquivo);
	return a;
}

//funcao para procurar valor
bool arraySearch(int valor, int_Array arranjo){
	bool result = false;

	for(int i = 0; i < arranjo.length && !result; i = i + 1){
		result = ( valor == arranjo.data[i] );
	}
	return (result);
}

void method_02(void){
	//identificar
	IO_id("Method_02 - Procurar valor em arranjo.\n");
	//definir dados
	int_Array arranjo;
	int valor = 0;
	//ler dados
	valor = IO_readint("Digite um valor para procurar: ");
	getchar();
	//ler arquivo
	arranjo = readArrayFromFile("DADOS.TXT");
	//procurar valor
	bool procurar = arraySearch(valor, arranjo);
	IO_printf ( "\nProcurar por (%d) = %d\n", valor, procurar);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end emthod_02()

/* Method_03 - Comparar Arranjos */
bool arrayCompare(int_Array arranjo1, int_Array arranjo2){
	// comparar os elementos de cada arranjo
	for (int i = 0; i < arranjo1.length; i++) {
		if (arranjo1.data[i] != arranjo2.data[i]) {
			return 0; // Se encontrar elementos diferentes, retorna false
		}
	}
	
	// Se nenhum elemento diferente foi encontrado, retorna true
	return 1;
}

void method_03(void){
	//identificar
	IO_id("Method_03 - Comparar Arranjos.\n");
	//definir dados
	int_Array arranjo1;
	int_Array arranjo2;
	//ler arquivos
	arranjo1 = readArrayFromFile("DADOS.TXT");
	arranjo2 = readArrayFromFile("DADOS2.TXT");
	// verificar tamanhos dos arranjos 
	if (arranjo1.length != arranjo2.length) {
		printf("ERRO: Os arranjo sao incompativeis.\n");
	}
	else{
		//chamar funcao para comparar arranjos
		bool resposta =  arrayCompare(arranjo1, arranjo2);
		if(resposta == 1){
			printf("Os arranjos sao iguais.\n");
		}
		else{
			printf("Os arranjos sao diferentes.\n");
		}
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_03()

/* Methos_04 - Soma de arranjos */
ref_int_Array arrayAdd ( int_Array arranjo1, int x, int_Array arranjo2 ){
	ref_int_Array soma = new_int_Array(arranjo1.length);
	for(int y = 0; y < arranjo1.length; y = y + 1 ){
		soma->data[y] = (arranjo1.data[y] + (x * arranjo2.data[y]));
	}
	return (soma);
}

void method_04(void){
	//identificar
	IO_id("Method_04 - Somar arranjos.");
	//definir dados
	int_Array arranjo1;
	int_Array arranjo2;
	ref_int_Array soma = 0;
	//ler arquivo
	arranjo1 = readArrayFromFile("DADOS.TXT");
	arranjo2 = readArrayFromFile("DADOS2.TXT");
	//verificar se sao compativeis
	if (arranjo1.length != arranjo2.length) {
		printf("ERRO: Os arranjos são incompatíveis.\n");
	} else {
		// Somar arranjos
		soma = arrayAdd(arranjo1, 2, arranjo2);
		printf("Soma dos Arranjos: \n");
		for (int i = 0; i < soma->length; i++) {
			printf("%d \n", soma->data[i]);
		}
		printf("\n");
	}
	//encerrar
	IO_pause("Aperte ENTER para continuar.\n");
}//end method_04()

/* Method_05 - Ordem decrescente */
bool isArrayDecrescent ( int_Array arranjo){
	//testar se o arranjo esta vazio ou com um elemento
	if (arranjo.length <= 1) {
		return 0;
	}
	
	// verificar se os elementos estao em ordem decrescente
	for (int i = 1; i < arranjo.length; i = i + 1) {
		if (arranjo.data[i] > arranjo.data[i - 1]) {
			return 0; 
		}
	}
	
	return 1; 
}

void method_05(void){
	//identificar
	IO_id("Method_05 - Arranjo na ordem decrescente.\n");
	//definir dados
	int_Array arranjo;
	arranjo = readArrayFromFile("DADOS2.TXT");
	bool resposta = isArrayDecrescent(arranjo);
	if(resposta){
		IO_printf("O arranjo esta na ordem decrescente.\n");
	}
	else{
		IO_printf("O arranjo nao esta na ordem decrescente.\n");
	}
	//encerrar
	IO_pause("Aperte ENTER para continuar.\n");
}//end method_05()

// ---------------Matrix --------------------//

//definicao de tipo
typedef
struct s_int_Matrix
{
	int rows ;
	int columns;
	ints* data ;
	int ix, iy ;
}
int_Matrix;
//referencia 
typedef int_Matrix* ref_int_Matrix;

//reservar espaco para matriz
ref_int_Matrix new_int_Matrix ( int rows, int columns )
{
// reserva de espaco
	ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));
// estabelecer valores padroes
	if ( tmpMatrix != NULL )
	{
		tmpMatrix->rows = 0;
		tmpMatrix->columns = 0;
		tmpMatrix->data = NULL;
		// reservar espaco
		if ( rows>0 && columns>0 )
		{
			tmpMatrix->rows = rows;
			tmpMatrix->columns = columns;
			tmpMatrix->data = malloc (rows * sizeof(ints));
			if ( tmpMatrix->data )
			{
				for ( tmpMatrix->ix=0;
					tmpMatrix->ix<tmpMatrix->rows;
					tmpMatrix->ix=tmpMatrix->ix+1 )
				{
					tmpMatrix->data [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int));
				} // end for
			} // end if
		} // end if
		tmpMatrix->ix = 0;
		tmpMatrix->iy = 0;
	} // end if
	return ( tmpMatrix );
} // end new_int_Matrix ( )

//dispensar espaco
void free_int_Matrix ( ref_int_Matrix matrix )
{
// testar se ha' dados
	if ( matrix != NULL )
	{
		if ( matrix->data != NULL )
		{
			for ( matrix->ix=0;
				matrix->ix<matrix->rows;
				matrix->ix=matrix->ix+1 )
			{
				free ( matrix->data [ matrix->ix ] );
			} // end for
			free ( matrix->data );
		} // end if
		free ( matrix );
	} // end if
} // end free_int_Matrix ( )

//mostrar matriz
void printIntMatrix ( ref_int_Matrix matrix )
{
// testar a existencia
	if ( matrix != NULL && matrix->data != NULL )
	{
		// mostrar valores na matriz
		for ( matrix->ix=0; matrix->ix<matrix->rows; matrix->ix=matrix->ix+1 )
		{
			for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
			{
				// mostrar valor
				printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->iy ] );
			} // end for
			printf ( "\n" );
		} // end for
	} // end if
} // end printIntArray ( )

/* Method_06 - Matriz Transposta */
ref_int_Matrix  readMatrixFromFile(chars fileName){
	// definir dados locais
	ref_int_Matrix matrix = NULL;
	int rows = 0;
	int columns = 0;
	FILE* arquivo = fopen ( fileName, "rt" );
	// ler a quantidade de dados
	fscanf ( arquivo, "%d", &rows );
	fscanf ( arquivo, "%d", &columns );
	if ( rows <= 0 || columns <= 0 )
	{
		IO_printf ( "\nERRO: Valor invalido.\n" );
	}
	else
	{
		// reservar espaco para armazenar
		matrix = new_int_Matrix ( rows, columns );
		// testar se ha' espaco
		if ( matrix != NULL && matrix->data == NULL )
		{
			// nao ha' espaco
			matrix->rows = 0;
			matrix->columns = 0;
			matrix->ix = 0;
			matrix->iy = 0;
		}
		else
		{
			// testar a existência
			if ( matrix != NULL )
			{
				// ler e guardar valores na matriz
				matrix->ix = 0;
				while ( ! feof ( arquivo ) && matrix->ix < matrix->rows )
				{
					matrix->iy = 0;
					while ( ! feof ( arquivo ) && matrix->iy < matrix->columns )
					{
						// guardar valor
						fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) );
						// passar ao proximo
						matrix->iy = matrix->iy+1;
					} // end while
					// passar ao proximo
					matrix->ix = matrix->ix+1;
				} // end while
				matrix->ix = 0;
				matrix->iy = 0;
			} // end if
		} // end if
	} // end if
// retornar matriz lida
	return ( matrix );
}

ref_int_Matrix matrixTranspose(ref_int_Matrix matrix){

	if (matrix == NULL || matrix->data == NULL) {
		printf("Matriz inválida.\n");
		return NULL;
	}
	else{
		ref_int_Matrix transpostaMatrix= new_int_Matrix(matrix->columns,matrix->rows);
		for (int i = 0; i < matrix->rows; i++) {
			for (int j = 0; j < matrix->columns; j++) {
				transpostaMatrix->data[j][i] = matrix->data[i][j];
			}
		}
		return transpostaMatrix;
	}
}//end matrixTranspose()

void method_06 (void ){
	//identificar
	IO_id("Method_06 - Matriz Transposta\n");
	//ler dados
	ref_int_Matrix matrix = readMatrixFromFile("MATRIZ.TXT");
	ref_int_Matrix matrix2 = matrixTranspose(matrix);
	//mostrar matriz de arquivo
	printf("%2d, %d\n", matrix->rows, matrix->columns);
	printIntMatrix(matrix);
	printf("\n");
	//mostrar matriz transposta
	printf("Matriz Transposta: \n");
	printf("\n%2d, %d\n", matrix->columns, matrix->rows);
	printIntMatrix(matrix2);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_06()

/* Method_07 - Verificar 0 na matriz */
bool matrixZero(ref_int_Matrix matrix){
	bool resposta = false;
	if ( matrix != NULL )
	{
		while(matrix->ix < matrix->rows){
			while(matrix->iy < matrix->columns){
				resposta = (matrix->data[matrix->ix][matrix->iy] == 0);
				matrix->iy = matrix->iy + 1;
			}
			matrix->ix = matrix->ix + 1;
		}
	}
	return (resposta);
}

void method_07(void){
	//identificar
	IO_id("Method_07 - Matriz Zero.\n");
	//ler dados
	ref_int_Matrix matrix = readMatrixFromFile("MATRIZ2.TXT");
    bool resposta = matrixZero(matrix);
	printIntMatrix(matrix);
	if(resposta){
		printf("\nA matriz so contem zeros.\n");
	}
	else{
		printf("\nA matriz nao contem so zeros.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_07()

/* Method_08 - Igualdade de Matrizes */
bool matrixCompare(ref_int_Matrix matrix1, ref_int_Matrix matrix2){
	bool result = false;
	if (matrix1->rows != matrix2->rows && matrix1->rows != matrix2->rows) {
		printf("ERRO: Os tamanhos sao incompativeis.\n");
	}
	else{
		for(int i = 0; i < matrix1->rows; i = i + 1){
			for(int j = 0; j < matrix2->columns; j = j + 1){
				result = (matrix1->data[i][j] == matrix2->data[i][j]);
			}
		}
	}
	return (result);
}
void method_08(void){
	//identificar
	IO_id("Method_08 - Testar Igualdade de matrizes.\n");
	//ler dados
	ref_int_Matrix matrix1 = readMatrixFromFile("MATRIZ.TXT");
	ref_int_Matrix matrix2 = readMatrixFromFile("MATRIZ3.TXT");
	printIntMatrix(matrix1);
	printf("\n");
	printIntMatrix(matrix2);
	//chamar funcao para testar
	bool resposta = matrixCompare(matrix1, matrix2);
	if(resposta){
		IO_printf("\nAs matrizes sao iguais.\n");
	}
	else{
		IO_printf("\nAs matrizes sao diferentes.\n");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_08()

/* Method_09 - Somar Matrizes */
ref_int_Matrix matrixAdd(ref_int_Matrix matrix1, int x, ref_int_Matrix matrix2){
	if (matrix1->rows != matrix2->rows && matrix1->rows != matrix2->rows) {
		printf("ERRO: Os tamanhos sao incompativeis.\n");
	}
	else{
		ref_int_Matrix soma = new_int_Matrix(matrix1->rows,matrix1->columns);
		for (int i = 0; i < matrix1->rows; i = i + 1) {
			for (int j = 0; j < matrix1->columns; j = j + 1) {
				soma->data[i][j] = matrix1->data[i][j] + (x * matrix2->data[i][j]);
			}
		}
		return soma;
	}
}

void method_09(void){
	//identificar
	IO_id("Method_09 - Somar matrizes.\n");
	//ler dados
	ref_int_Matrix matrix1 = readMatrixFromFile("MATRIZ.TXT");
	ref_int_Matrix matrix2 = readMatrixFromFile("MATRIZ3.TXT");
	printIntMatrix(matrix1);
	printf("\n");
	printIntMatrix(matrix2);
	printf("\n");
	//chamar funcao para soma
	ref_int_Matrix soma = matrixAdd(matrix1, -1, matrix2);
	IO_printf("Resultado da soma: \n");
	printIntMatrix(soma);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_09()

/* Method_10 - Produto de Matrizes */
ref_int_Matrix matrixProduct(ref_int_Matrix matrix1, ref_int_Matrix matrix2){
	if (matrix1->rows != matrix2->rows && matrix1->rows != matrix2->rows) {
		printf("ERRO: Os tamanhos sao incompativeis.\n");
	}
	else{
		ref_int_Matrix produto = new_int_Matrix(matrix1->rows,matrix1->columns);
		for (int i = 0; i < matrix1->rows; i = i + 1) {
			for (int j = 0; j < matrix1->columns; j = j + 1) {
				produto->data[i][j] = matrix1->data[i][j] * matrix2->data[i][j];
			}
		}
		return (produto);
	}
}//end matrixProduct()

void method_10(void){
	//identificar
	IO_id("Method_10 - Produto de matrizes.\n");
	//ler dados
	ref_int_Matrix matrix1 = readMatrixFromFile("MATRIZ.TXT");
	ref_int_Matrix matrix2 = readMatrixFromFile("MATRIZ3.TXT");
	printIntMatrix(matrix1);
	printf("\n");
	printIntMatrix(matrix2);
	printf("\n");
	//chamar funcao para soma
	ref_int_Matrix produto = matrixProduct(matrix1, matrix2);
	IO_printf("Resultado: \n");
	printIntMatrix(produto);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_10()

/* EXTRAS */

/* 10E1 */
int_Array sortArrayDown(int_Array arranjo) {
	for (int i = 0; i < arranjo.length - 1; i = i + 1) {
		for (int j = 0; j < arranjo.length - 1; j = j + 1) {
			if (arranjo.data[j] < arranjo.data[j + 1]) {
				int troca = arranjo.data[j];
				arranjo.data[j] = arranjo.data[j + 1];
				arranjo.data[j + 1] = troca;
			}
		}
	}
	return arranjo;
}
void method_11(void){
	//identificar
	IO_id("Method_11 - Ordem decrescente.\n");
	//ler dados
	int_Array arranjo = readArrayFromFile("DADOS.TXT");
	int_Array ordenado = sortArrayDown(arranjo);
	//chamar funcao
	printf("\nOrdenado: \n");
	//mostrar dados
	for(int x = 0; x < ordenado.length; x = x + 1) {
		printf("%d\n", ordenado.data[x]);
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_11()
	
/* 10E2 */
bool identityMatrix(ref_int_Matrix product) {
	ref_int_Matrix matrix = new_int_Matrix(product->rows, product->columns);
	for(int i = 0; i < matrix->rows; i = i + 1){
		for(int j = 0; j < matrix->columns; j = j + 1){
			if(i == j){
				matrix->data[i][j] = 1;
			}
			else{
				matrix->data[i][j] = 0;
			}
		}
	}
	bool identidade = true; 
	for(int i = 0; i < product->rows && identidade; i = i + 1) {
		for(int j = 0; j < product->columns && identidade; j = j + 1) {
			if (product->data[i][j] != matrix->data[i][j]) {
				identidade = false; // se encontrar um diferente define como falso
			}
		}
	}
	return (identidade);
}

void method_12(void) {
	IO_id("Method_12 - Verficar igualdade entre produto e matriz ientidade.\n");
	// Ler as matrizes dos arquivos
	ref_int_Matrix matrix1 = readMatrixFromFile("MATRIZ.TXT");
	ref_int_Matrix matrix2 = readMatrixFromFile("MATRIZ2.TXT");
	
	// Multiplicar as duas matrizes
	ref_int_Matrix product = matrixProduct(matrix1, matrix2);
	if (matrix1->rows != matrix2->rows && matrix1->rows != matrix2->rows) {
		printf("ERRO: Os tamanhos sao incompativeis.\n");
	}
	else{
		// Testar se o produto e' igual a matriz identidade
		bool result = identityMatrix(product);
		if(result){
			printf("\nO produto das matrizes eh igual a matriz identidade.\n");
		}
		else{
			printf("\nO produto das matrizes nao eh igual a matriz identidade.\n");
		}
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_12()

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
		case 1:
			method_01();
			break;
		case 2:
			method_02();
			break;
		case 3:
			method_03();
			break;
		case 4:
			method_04();
			break;
		case 5:
			method_05();
			break;
		case 6:
			method_06();
			break;
		case 7:
			method_07();
			break;
		case 8:
			method_08();
			break;
		case 9:
			method_09();
			break;
		case 10:
			method_10();
			break;
		case 11:
			method_11();
			break;
		case 12:
			method_12();
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


/* Exercicios - ED09 - 
Rayssa Mell de Souza Silva - 860210 */

#include<stdio.h>
#include "io.h"

/* Method_01 */
void readNegativeDoubleMatrix(int m, int n, double negativeMatrix[10][10]){
	if( m > 0 && n > 0){
		for(int x = 0; x < m; x = x + 1){
			for(int y = 0; y < n; y = y + 1){
				do{
					printf("\n%d, %d: ", x, y);
					scanf("%lf", &negativeMatrix[x][y]);
					getchar();
				}while(negativeMatrix[x][y] > 0);
			}
		}
	}
	else{
		printf("\nERRO: matriz nula ou negativa");
	}
}

void printDoubleMatrix(int m, int n, double negativeMatrix[10][10]) {
	for (int i = 0; i < m; i = i + 1) {
		for (int j = 0; j < n; j = j + 1) {
			printf("%.2lf\t", negativeMatrix[i][j]);
		}
		printf("\n");
	}
}

void method_01(void){
	//identificar
	IO_id("\nMethod_01 - Ler matriz e elementos negativos.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix [10][10];
	
	//ler dados
	printf ( "\nm =  ");
	scanf  ( "%d", &m ); getchar();
	printf ( "\nn = " );
	scanf  ( "%d", &n );getchar();
	
	readNegativeDoubleMatrix(m, n, negativeMatrix);
	printf("\nMatriz:\n");
	printDoubleMatrix(m, n, negativeMatrix);
	//encerrar
	IO_pause("\nAperte ENTER para contunuar.");
}//end method_01()

/* Method_02 */
void fprintDoubleMatrix ( chars fileName, int m, int n, double negativeMatrix[10][10] ){
	FILE* arquivo = fopen(fileName, "wt");
	
	fprintf(arquivo, "%d %d \n", m, n);
	for (int i = 0; i < m; i = i + 1) {
		for (int j = 0; j < n; j = j + 1) {
			fprintf(arquivo, "%.2lf\t", negativeMatrix[i][j]);
		}
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);
}

void method_02(void){
	//identificar
	IO_id("\nMethod_02 - Gravar Matriz em arquivo.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix[10][10]; 
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();
	//chamar funcoes
	readNegativeDoubleMatrix(m,n, negativeMatrix);
	fprintDoubleMatrix ( "MATRIX_01.TXT", m, n, negativeMatrix );
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_02()

/* Method_03 */
double printSDiagonalDoubleMatrix(int m, int n, double negativeMatrix[10][10]){
	int i = 0, j = 0;
	double principal = 0.0;
	for(i = 0; i < m; i = i + 1){
		for(j = 0; j < n; j = j + 1){
			if(i == j){
				principal = negativeMatrix[i][j];
				printf("%.2lf\t", principal);
			}
		}
	}
	return (principal);
}

void method_03(void){
	//identificar
	IO_id("\nMethod_03 - Diagonal Principal.");
	//definir dados
	int m = 0;
	int n = 0;
	//ler dados
	m = IO_readint("\nm= ");getchar();
	n = IO_readint("\nn= ");getchar();
	double negativeMatrix[10][10];
	
	//verfificando se a matriz eh quadrada
	if(m == n){
		//chamando funcoes
		readNegativeDoubleMatrix(m, n, negativeMatrix);
		printf("\nDiagonal Principal: \n");
		printSDiagonalDoubleMatrix(m, n, negativeMatrix);
	}
	else{
		printf("\nERRO: a matriz deve ser quadrada.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_03()

/* Method_04 */
double printSDiagonalSecDoubleMatrix(int m, int n, double negativeMatrix[10][10]){
	double secundaria = 0.0;
	for(int i = 0; i < m; i = i + 1){
		for(int j = 0; j < n; j = j + 1){
			if(i + j == (n - 1)){
				secundaria = negativeMatrix[i][j];
				printf("%.2lf\t", secundaria);
			}
		}
	}
	return secundaria;
}

void method_04(void){
	//identifiar
	IO_id("\nMethod_04 - Diagonal Secundaria de uma matriz.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix[10][10];
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();
	if(m == n){
		readNegativeDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		printDoubleMatrix(m, n, negativeMatrix);
		printf("\nDiagonal Secundaria: \n");
		printSDiagonalSecDoubleMatrix(m, n, negativeMatrix);
	}
}//end method_04()

/* Method_05 */
void printLDTriangleDoubleMatrix(int m, int n, double negativeMatrix[10][10]){
	for(int i = 0; i < m; i = i + 1){
		for(int j = 0; j < n; j = j + 1){
			if(i >= j){
				printf("%.2lf\t", negativeMatrix[i][j]);
			}
		}
	}
}

void method_05(void){
	//identificar
	IO_id("\nMethod_05 - Diagonal Principal e abaixo.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix[10][10];
	//ler dados
	m = IO_readint("\nm= ");getchar();
	n = IO_readint("\nn= "); getchar();
	//testar se a matriz eh quadrada
	if(m == n){
		//funcao para ler elementos 
		readNegativeDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar matriz
		printDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar diagonal principal e abaixo
		printf("\nDiagonal principal e abaixo: \n");
		printLDTriangleDoubleMatrix(m, n, negativeMatrix);
	}
	else{
		printf("\nERRO: a matriz nao eh quadrada.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_05

/* Method_06 */
void printLUTriangleDoubleMatrix(int m, int n, double negativeMatrix[10][10]){
	for(int i = 0; i < m; i = i + 1){
		for(int j = 0; j < n; j = j + 1){
			if(i <= j){
				printf("%.2lf\t", negativeMatrix[i][j]);
			}
		}	
	}
} 

void method_06(void){
	//identificar
	IO_id("\nMethod_06 - Valores da diagonal principal e acima.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix[10][10];
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();
	if(m == n){
		//funcao para ler elementos 
		readNegativeDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar matriz
		printDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar diagonal principal e acima
		printf("\nDiagonal principal e acima: \n");
		printLUTriangleDoubleMatrix(m, n, negativeMatrix);
	}
	else{
		printf("\nErro: a matriz nao eh quadrada.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_06()

/*Method_07 */
void printSLDTriangleDoubleMatrix(int m, int n, double negativeMatrix[10][10]){
	for(int i = 0; i < m; i = i +1){
		for(int j = 0; j < n; j = j + 1){
			if(i + j >= (n - 1)){
				printf("%.2lf\t", negativeMatrix[i][j]);
			}
		}
	}
}

void method_07(void){
	//identificar
	IO_id("\nMethod_07 - Valores da diagonal secundaria e abaixo.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix[10][10];
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();
	if(m == n){
		//funcao para ler elementos 
		readNegativeDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar matriz
		printDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar diagonal secundaria e abaixo
		printf("\nDiagonal secundaria e abaixo: \n");
		printSLDTriangleDoubleMatrix(m, n, negativeMatrix);
	}
	else{
		printf("\nErro: a matriz nao eh quadrada.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_07()

/* Method_08 */
void printSLUTriangleDoubleMatrix(int m, int n, double negativeMatrix[10][10]){
	for(int i = 0; i < m; i = i + 1){
		for(int j = 0; j < n; j = j + 1){
			if(i + j <= n - 1){
				printf("%.2lf\t", negativeMatrix[i][j]);
			}
		}
	}
}

void method_08(void){
	//identificar
	IO_id("\nMethod_08 - Valores da diagonal secundaria e acima.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix[10][10];
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();
	if(m == n){
		//funcao para ler elementos 
		readNegativeDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar matriz
		printDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar diagonal secundaria e abaixo
		printf("\nDiagonal secundaria e acima: \n");
		printSLUTriangleDoubleMatrix(m, n, negativeMatrix);
	}
	else{
		printf("\nErro: a matriz nao eh quadrada.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_08()

/* Method_09 */
bool allZerosLTriangleDoubleMatrix ( int m, int n, double negativeMatrix[10][10]){
	bool result = true;
	for(int i = 0; i < m; i = i + 1){
		for(int j = 0; j < n; j = j + 1){
			if(i > j && negativeMatrix[i][j] != 0){
				result = false;
			}
		}
	}
	return result;
}
void method_09(void){
	//identificar
	IO_id("\nMethod_09 - Testar zeros abaixo da diagonal principal.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix[10][10];
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();
	if(m == n){
		//funcao para ler elementos 
		readNegativeDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar matriz
		printDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para testar zeros abaixo
		bool result = allZerosLTriangleDoubleMatrix (m, n, negativeMatrix);
		if (result) {
			printf("Todos os elementos abaixo da diagonal principal sao zeros.\n");
		} else {
			printf("Os valores abaixo da diagonal principal nao sao zeros.\n");
		}
	}
	else{
		printf("\nErro: a matriz nao eh quadrada.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_09()

/* Method_10 */
bool allZerosUTriangleDoubleMatrix ( int m, int n, double negativeMatrix[10][10]){
	bool result = true;
	for(int i = 0; i < m; i = i + 1){
		for(int j = 0; j < n; j = j + 1){
			if(i < j && negativeMatrix[i][j] != 0){
				result = false;
			}
		}
	}
	return result;
}
void method_10(void){
	//identificar
	IO_id("\nMethod_10 - Testar valores 0 acima da diagonal principal.");
	//definir dados
	int m = 0, n = 0;
	double negativeMatrix[10][10];
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();
	if(m == n){
		//funcao para ler elementos 
		readNegativeDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para mostrar matriz
		printDoubleMatrix(m, n, negativeMatrix);
		printf("\n");
		//funcao para testar zeros acima
		bool result = allZerosUTriangleDoubleMatrix (m, n, negativeMatrix);
		if (result) {
			printf("Todos os elementos acima da diagonal principal sao zeros.\n");
		} else {
			printf("Os valores acima da diagonal principal nao sao zeros.\n");
		}
	}
	else{
		printf("\nErro: a matriz nao eh quadrada.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_10()

/* EXTRAS */

/* 09E1 */
void readMatrix(chars fileName, int m, int n, int matrix[10][10]){
	FILE* arquivo = fopen(fileName, "at");
	printf("\n%d x %d\n", m, n);
	fprintf(arquivo, "%d  %d\n", m, n);
	for (int i = 0; i < m; i = i + 1) {
		for (int j = 0; j < n; j = j + 1) {
			
			matrix[i][j] = i * n + j + 1;
			printf("%d\t", matrix[i][j]);
			fprintf(arquivo, "%d\t", matrix[i][j]);
		}
		printf("\n");
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);
	
}

void method_11(void){
	//identificar 
	printf("\nMethod_11 - Matrizes");
	//definir dados
	int m = 0, n = 0;
	int matrix[10][10];
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();

	if(m > 0 && n > 0){
		readMatrix("METODO11.TXT",m,n, matrix);
		printf("\n");
		readMatrix("METODO11.TXT", m+1, n+1, matrix);
		printf("\n");
		readMatrix("METODO11.TXT", m+2, n+2, matrix);
	}
	else{
		printf("\nErro: matriz invalida.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_11()

/* Method_12 */
void readMatrixInversa(chars fileName, int m, int n, int matrix[10][10]){
	FILE* arquivo = fopen(fileName, "at");
	for (int i = 0; i < m; i = i + 1) {
		for (int j = 0; j < n; j = j + 1) {
			matrix[i][j] = i * n + j + 1;
		}
		printf("\n");
	}
	printf("\n%d x %d\n", m, n);
	fprintf(arquivo, "%d  %d\n", m, n);
	for (int i = m - 1; i >= 0; i = i - 1) { 
		for (int j = n - 1; j >= 0; j = j - 1) { 
			printf("%d\t", matrix[i][j]);
			fprintf(arquivo, "%d\t", matrix[i][j]);
		}
		printf("\n");
		fprintf(arquivo, "\n");
	}
	fclose(arquivo);
}

void method_12(void){
	//identificar 
	printf("\nMethod_12 - Matrizes");
	//definir dados
	int m = 0, n = 0;
	int matrix[10][10];
	//ler dados
	m = IO_readint("\nm= "); getchar();
	n = IO_readint("\nn= "); getchar();
	
	if(m > 0 && n > 0){
		printf("\nMatriz invertida:\n");
		readMatrixInversa("METODO12.TXT", m,n, matrix);
		printf("\n");
		readMatrixInversa("METODO12.TXT", m+1, n+1, matrix);
		printf("\n");
		readMatrixInversa("METODO12.TXT", m+2, n+2, matrix);
	}
	else{
		printf("\nErro: matriz invalida.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_12()

int main(){
	int opcao = 0;
	printf ( "%s\n", "Exemplos 0900 - Programa = v0.0" );
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


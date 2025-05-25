/* Exercicios 0800 -> Rayssa Mell de Souza Silva - 860210*/

#include<stdio.h>
#include "io.h"
#include <stdlib.h>

/*Method_01*/
void method_01(void){
	//identificar
	IO_id("\nMetodo_01 - Ler tamanho de arranjo e seus elementos.");
	//definir dados
	int n = 0, i = 0;
	int y = 0;
	//ler dados
	n = IO_readint("\nDigite a quantidade de dados: ");
	getchar();
	
	if(n <= 0){
		printf("Tamanho Invalido.");
	}
	else{
		//define array com n elementos
		int array[n];
		while(i < n){
			//ler array
			printf("\n%d: ", i);
			scanf("%d", &y);getchar();
			//testar se eh positivo e par 
			if(y > 0 && y % 2 == 0){
				array[i] = y;
				i = i + 1;
			}
			else{
				printf("\nInvalido: o valor deve ser positivo e par.\n");
			}
		}
		printf("\n");
		printf("Arranjo: ");
		for (i = 0; i < n; i = i + 1) {
			printf("\n%d: %d", i,array[i]);
		}
	}
}

/*Method_02*/
void lerArquivo(chars fileName, int array[]){
	//definir dados
	int x = 0;
	int y = 0;
	int cont = 0;
	//ler arquivo com dados
	FILE* arquivo = fopen(fileName, "rt");
	//abrir novo arquivo
	FILE* novoArquivo = fopen("METODO2.TXT", "at");
	// ler a quantidade de dados
	IO_fscanf ( arquivo, "%d", &x );
	
	if ( x <= 0)
	{
		IO_println ( "ERRO: Valor invalido." );
	}
	else{
		while(! feof ( arquivo ) && x > 0){
			// ler valor
			IO_fscanf ( arquivo, "%d", &y );
			if( y > 0 && y % 2 == 0){
				// guardar valor
				array [x] = y;
				fprintf(novoArquivo, "%d\n", array[x]);
				cont = cont + 1;
			}
			// passar ao proximo
			x =  x + 1;
		}
	}
	fprintf(novoArquivo, "Quantidade: %d\n", cont);
	//fechar arquivo
	fclose(arquivo);	
	fclose(novoArquivo);
}

void method_02(void){
	// identificar
	IO_id ( "Method_04 - v0.0" );
	//definir dado
	int array[15];
	//chamar funcao
	lerArquivo("DADOSMETODO2.TXT", array);
	
	// encerrar
	IO_pause ( "\nApertar ENTER para continuar" );
	getchar();
}

/* Method_03 */
int gerarInt(chars fileName, int inferior, int superior, int n){
	int num = inferior;
	int array[n];
	int cont = 0;
	FILE* arquivo = fopen(fileName, "at");
	
	fprintf(arquivo,"Intervalo de %d a %d: \n", inferior,superior);
	fprintf(arquivo, "%d -> \n", n);
	while(cont < n){
		num = rand() % superior;
		if(num > inferior && num < superior){
			array[cont] = num;
			fprintf(arquivo, "%d\n", array[cont]);	
			cont = cont + 1;
		}
	}
	fclose(arquivo);
	return (num);
}

void method_03(void){
	//identificar
	IO_id("\nMethod_03");
	//definir dados
	int inferior = 0, superior = 0;
	int n = 0;
	//ler dados
	inferior = IO_readint("\nDigite o primeiro intervalo: ");getchar();
	superior = IO_readint("\nDigite o segundo intervalo: ");getchar();
	n = IO_readint("\nDigite a quantidade: ");getchar();
	//chamar funcao
	gerarInt ("DADOS.TXT", inferior, superior, n );
	
	// encerrar
	IO_pause ( "\nApertar ENTER para continuar" );
}//end method_03

/*Method_04*/
int readArquivo(int n, chars fileName, int array[]){
	FILE* arquivo = fopen(fileName, "rt");
	
	int y = 0, x = 0;
	int m = 0;
	
	IO_fscanf ( arquivo, "%d", &m );
	
	while(! feof ( arquivo ) && x < n){
		IO_fscanf ( arquivo, "%d", &y );
		// guardar valor
		array [ x ] = y;
		printf("%2d\n", array[x]);
		x = x + 1;
	}	
	fclose(arquivo);
	return y;
}

int acharMenorPar(int n, int arranjo[]){
	int x = 0;
	int menor = arranjo[x];
	
	for(x=0; x < n; x = x + 1){
		int y = arranjo[x]; 
		if(y % 2 == 0){
			if(y < menor){
				menor = y;	
			}
		}
	}
	return menor;
}

void method_04(void){
	//identificar
	IO_id("\nMethod_04 - Achar menor par em um conjunto de dados.\n");
	//definir dados
	int n = 0;
	n = IO_readint("\nDigite um valor de 1 a 16: ");getchar();
	int array[n];
	//chamar funcao para ler arquivo
	readArquivo( n, "DADOSMETODO2.TXT",array);
	//chamar funcao para achar menor par
	int menor = acharMenorPar(n,array);
	//exibir menor par
	printf("\nMenor Par: %d\n", menor);
	//encerrar
	printf("\nAperte ENTER para continuar.");
	getchar();
}//end method_04()

/* Method_05 */
int MaiorImpar(int n, int array[]){
	int x = 0;
	int maior = array[x];
	
	for(x = 0; x < n; x = x + 1){
		int y = array[x]; 
		if(y % 2 != 0){
			if(y > maior){
				maior = y;    
			}
		}
	}
	return maior;
}
	
void method_05(void){
	//identificar
	IO_id("\nMethod_05 - Achar Maior Impar.");
	//definir dados
	int n = 0;
	//ler dados
	n = IO_readint("\nDigite um valor de 1 a 16: ");getchar();
	int array[n];
	//chamar funcao para ler arquivo
	readArquivo(n,"DADOSMETODO2.TXT", array);
	int maior = MaiorImpar(n, array);
	printf("\nMaior impar: %d", maior);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_05()

/* Method_06 */
float acharMedia(chars fileName, chars name, int n, int array[]){
	FILE* arquivo1 = fopen(fileName, "wt");
	FILE* arquivo2 = fopen(name, "wt");
	int x = 0;
	float soma = 0;
	float media = 0.0;
	
	fprintf(arquivo1, "Maiores -> \n");
	fprintf(arquivo2, "Menores ou Igual -> \n");
	
	for(x=0; x < n; x = x + 1){
		soma = soma + array [ x ];
		media = soma/n;
	}
		printf("\nSoma = %.2f", soma);
	
	for(x=0; x<n; x = x + 1){
		if(array[x] > media){
			fprintf(arquivo1, "%d\n", array[x]);
		}
		if(array[x] <= media){
			fprintf(arquivo2, "%d\n", array[x]);
		}
	}
	fclose(arquivo1);
	fclose(arquivo2);
	return media;
}
void method_06(void){
	//identificar
	IO_id("\nMethod_06 - Calcular Media.");
	//definir dados
	int n = 16;
	int array[n];
	float media = 0.0;
	//chamar metodo para ler arquivo
	printf("\nDados: \n");
	readArquivo(n, "DADOSMETODO2.TXT", array);
	printf("\n");
	//chamar metodo para calcular media
	media = acharMedia("MAIORES.TXT", "MENORES.TXT", n, array);
	//mostrar media
	printf("\nMedia: %.2f", media);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_06()

/* Method_07 */
void ordenado(int n, int array[]){
	int x = 0, z = 0;
	int maior = array[z];
	int y = 0;
	
	for(x = 0; x < n; x = x + 1){
		y = array[x];
		printf("%2d\n", y);
	}
	if(y > maior){
		printf("\nDesordenado.");
	}
	if(y < maior){
		printf("\nOrdenado.");
	}
}

void method_07(void){
	//identificar
	IO_id("\nMethod_07 - Arranjo ordenado ou desordenado.");
	//definir dados
	int n = 0;
	int x = 0;
	int valor = 0;
	//ler dado
	n = IO_readint("\nDigite a quantidade: ");
	int array[n]; //guardar no array
	if(n > 0){
		while(x < n){
			printf("\n%d: ", x);
			scanf("%d", &valor); getchar();
			array[x] = valor;
			x = x + 1;
		}
		printf("\n");
		printf("Arranjo: \n");
		//chamar funcao
		ordenado(n,array);
	}
	else{
		printf("\nERRO: Quantidade Invalida.");
	}
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_07()

/* Method_08 */
int readArquivo1(int n, chars fileName, int array[]){
	FILE* arquivo = fopen(fileName, "rt");
	
	int y = 0, x = 0;
	int m = 0;
	
	IO_fscanf ( arquivo, "%d", &m );
	//printf("\nTamanho: %d ", m);
	
	while(! feof ( arquivo ) && x < n){
		IO_fscanf ( arquivo, "%d", &y );
		// guardar valor
		array [ x ] = y;
		x = x + 1;
	}
	
	fclose(arquivo);
	return y;
}

bool acharValor(int valor, int x, int n, int array[]){
	bool result = false;
	
	while( x < n && ! result){
		result = ( valor == array [ x ] );
		x =  x + 1;
	}
	return(result);
}

void method_08(void){
	//identificar 
	IO_id("\nMethod_08 - Procurar Valor.");
	//definir dados
	int valor = 0;
	int n = 16;
	int array[n];
	readArquivo1(n,"DADOSMETODO2.TXT",array);
	valor = IO_readint("\nDigite um valor para procurar: ");
	getchar();
	bool existe = acharValor (valor, 1, n, array );
	IO_printf ( "\nProcurar por (%d) = %d\n", valor, existe);
	//encerrar
	IO_pause("Aperte ENTER para continuar.");
}//end method_08()

/*Method_09*/
int acharPosicao(int valor, int x, int n, int array[]){
	bool result = false;
	int posicao = 0;
	
	while( x < n && ! result){
		result = (valor == array [ x ]);
		x =  x + 1;
	}
	if(result){
		posicao = x;
	}
	return(posicao);
}

void method_09(void){
	//identificar 
	IO_id("\nMethod_09 - Posicao do valor procurado.");
	//definir dados
	int n = 16;
	int array[n];
	int valor = 0;
	readArquivo1(n,"DADOSMETODO2.TXT",array);
	valor = IO_readint("\nDigite um valor a ser procurado: ");
	getchar();
	int posicao = acharPosicao(valor, 0, n, array);
	IO_printf ( "\nProcurar por (%d) -> Posicao = %d\n", valor, posicao);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_09()

/* Method_10 */
int contarValor(int n, int x, int valor, int array[]){
	int contar = 0;
	
	while (x < n) {
		if (valor == array[x]) {
			contar = contar + 1;
		}
		x = x + 1;
	}

	return contar;
	
}

void method_10(void){
	//identificar 
	IO_id("\nMethod_10 - Contar quantas vezes o valor aparece.");
	//definir dados
	int n = 16;
	int array[n];
	int valor = 0;
	readArquivo1(n,"DADOSMETODO2.TXT",array);
	valor = IO_readint("\nDigite um valor a ser procurado: ");
	getchar();
	int contar = contarValor(n, 0, valor, array);
	IO_printf ( "\nProcurar por (%d) -> Quantidade = %d\n", valor, contar);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_10()

/* EXTRAS */

/* E801 */
int calcularDivisores(chars fileName, int valor, int array[]){
	FILE* arquivo = fopen(fileName, "at");
	
	fprintf(arquivo, "\n");
	fprintf(arquivo,"%d -> \n", valor);
	int x = 1;
	while(x < valor){
		if(valor % x == 0 ){
			array[x] = x;
			printf("\n[%2d]", array[x]);
			fprintf(arquivo, "%d\n", array[x]);
		}
		x = x + 2;
	}
	fclose(arquivo);
	return array[x];
}

void method_11(void){
	//identificar
	IO_id("\nMethod_11 - Calcular divisores impares.");
	//definir dado
	int valor = 0;
	//ler dado
	valor = IO_readint("\nDigite um valor: ");
	int array[valor];
	//chamar funcao
	printf("\nDivisores: \n");
	calcularDivisores("DIVISORES.TXT", valor, array);
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
}//end method_11()

/* 08E2 */
void lerPalavras(chars fileName){
	//abrir arquivo
	FILE* arquivo = fopen(fileName, "rt");
	chars linha = IO_new_chars(STR_SIZE);
	int m = 0;
	IO_fscanf ( arquivo, "%d", &m );
	// tentar ler o primeiro
	strcpy(linha, IO_freadln(arquivo));
	
	while (!feof(arquivo) && m < 10) {
		if (!(linha[0] == 'c' || linha[0] == 'C')) {
			int u = strlen(linha)-1;
			if(linha[u] != 'c' || linha[u] != 'C' ){
				printf("%s\n", linha);
			}
		}
		// tentar ler o proximo
		strcpy(linha, IO_freadln(arquivo));
	}
	// Fechar o arquivo
	fclose(arquivo);
}

void method_12(void){
	//identificar
	IO_id("\nMethod_12 - Palavras sem 'C' ou 'c'.");
	//definir dado
	lerPalavras("PALAVRAS.TXT");
	//encerrar
	IO_pause("\nAperte ENTER para continuar.");
	
}//end method_12()

int main(){
	int opcao = 0;
	printf ( "%s\n", "Exemplos 0800 - Programa = v0.0" );
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


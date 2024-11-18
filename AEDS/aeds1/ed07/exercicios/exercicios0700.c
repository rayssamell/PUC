/*
EXERCICIOS 0700 - 
Aluna: Rayssa Mell de Souza Silva - 860210 
*/

#include<stdio.h>
#include "io.h"
#include<math.h>

/*Method_01*/
int multiplosQuatro(chars fileName, int n){
	//definir dados
	FILE* arquivo = fopen (fileName, "wt");
	int multiplo = 0, cont = 1;
	
	while(cont <= n){
		multiplo = cont * 4; 
		fprintf(arquivo, "%d\n", multiplo);
		cont = cont + 1;
	}
	fclose(arquivo);//fechar o arquivo
	return multiplo;
}//end multiplosQuatro()

void method_01(void){
	//identificar
	IO_id("Method_01 - Multiplos de 4");
	//definir variavel
	int n = 0;
	n = IO_readint("Digite a quantidade: ");
	getchar();
	// executar o metodo auxiliar
	multiplosQuatro ( "DADOS1.TXT", n );
	// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
}//end method_01

/*Method_02*/
int multiplosCinco(chars fileName, int n){
	//definir variaveis
	FILE* arquivo = fopen(fileName, "wt");
	int multiplo = 0, num = 5, cont = 0;
	//testar condicao para multiplos
	for(cont = 1; cont <= n; cont = cont + 1){
		multiplo = 5 * num;
		num = num + 2;
	}
	//testar condicao para ordem decrescente
	while ( cont >= 1 ) {
		fprintf(arquivo,"%d\n", multiplo);
		multiplo = multiplo - 10;
		cont = cont - 1;
	}
	fclose(arquivo);
	return (multiplo);
}

void method_02(void){
	//identificar
	IO_id("\nMethod_02 - Multiplos impares de 5.");
	//definir variavel
	int n = 0;
	//ler dado
	n = IO_readint("Digite a quantidade: ");
	//executar metodo auxiliar
	multiplosCinco("MULTIPLOSCINCO.TXT", n);
	// encerrar
	IO_pause ( "\nApertar ENTER para continuar" );
}//end method_02()

/*Method_03*/
int sequenciaCinco(chars fileName, int n){
	//definir dados
	FILE* arquivo = fopen(fileName, "wt");
	int num = 1;
	//testar condicao para sequencia de multiplicacoes por 5
	for(int cont = 1; cont <= n; cont = cont + 1){
		if(cont > 1){
			fprintf(arquivo, "%d\n", num * 5);
			num = num * 5;
		}
		// para comecar de 1
		else{
			fprintf(arquivo, "%d\n", cont);
		}
	}
	//fechar arquivo
	fclose(arquivo);
	return (num);
}

void method_03(void){
	//identificar
	IO_id("\nMethod_03 - Sequencia de multiplicacoes por 5.");
	//definir variavel
	int n = 0;
	//ler dado
	n = IO_readint("Digite a quantidade: ");
	getchar();
	//executar metodo auxiliar
	sequenciaCinco("SEQUENCIACINCO.TXT", n);
	// encerrar
	IO_pause ( "\nApertar ENTER para continuar" );
}//ende method_03()

/*Method_04*/
int inversoSequencia(chars fileName, int n){
	//definir dados
	FILE* arquivo = fopen(fileName, "wt");
	int cont = 0, num = 1, sequencia = 0;
	for(cont = 1; cont <= n; cont = cont + 1){
		sequencia = num * 5;
		num = num * 5;
	}
	while(cont >= 1){
		fprintf(arquivo,"1/%d\n", sequencia);
		sequencia = sequencia / 5;
		cont = cont - 1;
	}
	fclose(arquivo);
	return (sequencia);
}

void method_04(void){
	//identificar
	IO_id("\nMethod_05 - Sequencia de multiplicacoes por 5 inverso.");
	//definir dados
	int n = 0;
	//ler dados
	n = IO_readint("Digite a quantidade: ");
	getchar();
	//executar metodo auxiliar
	inversoSequencia("INVERSOSEQUENCIA.TXT",n);
	// encerrar
	IO_pause ("\nApertar ENTER para continuar" );
}//end method_04()

/*Method_05*/
double calcularPotencia(chars fileName, int n, double x){
	//definir dados
	FILE* arquivo = fopen(fileName, "wt");
	int cont = 0, impar = 3;
	double num = 1.0;
	for(cont = 1; cont <= n; cont= cont + 1){
		if(cont > 1){
			double sequencia = pow(x,impar);
			fprintf(arquivo,"%.0lf/%.2lf\n",num, sequencia);
			impar = impar + 2;
		}
		else{
			fprintf(arquivo,"%d\n", cont);
		}
	}
	fclose(arquivo);
	return (cont);
}

void method_05(void){
	//identificar
	IO_id("\nMetod_05 - Calcular Potencia.");
	//definir dado
	int n = 0;
	double x = 0.0;
	//ler dados
	n = IO_readint("Digite a quantidade: ");getchar();
	x = IO_readdouble("Digite um valor real: ");getchar();
	//chamar metodo auxiliar
	calcularPotencia("CALCULARPOTENCIA.TXT", n,x);
	// encerrar
	IO_pause ("\nApertar ENTER para continuar." );
}//end method_05()

/*Method_06*/
double calcularSoma(chars fileName, int n){
	FILE* arquivo = fopen ( fileName, "rt" );
	
	int cont = 0; 
	double soma = 0.0, z = 0.0;
	double numerador = 0.0, denominador = 0.0;
	
	while (!feof(arquivo) && cont < n) {
		fscanf(arquivo, "%lf/%lf", &numerador, &denominador);
		if (denominador == 0) {
			printf("%d\n", cont+1);
		}
		else{	
			z = numerador / denominador;
			printf("%.0lf/%.2lf = %.4lf\n", numerador, denominador, z);
		}
		soma += z;
		cont = cont + 1;
	} // end while
	
	// fechar arquivo 
	printf("Soma: %.5lf\n", soma+1);
	fclose(arquivo);

	// a para abrir o arquivo
	FILE* novoArquivo = fopen("RESULTADO06.TXT", "at");
	
	fprintf(novoArquivo, "Quantidade (n): %d\n", n);
	fprintf(novoArquivo, "Soma: %.5lf\n", soma+1);
	
	fclose(novoArquivo);
	return soma;
}

void method_06(){
	//identificar
	IO_id("\nMethod_06 - Soma de valores.");
	//definir dado
	int n = 0;
	//ler dado
	n = IO_readint("Digite a quantidade: ");
	getchar();
	//chamar funcao
	calcularSoma("CALCULARPOTENCIA.TXT", n);
	// encerrar
	IO_pause ("\nApertar ENTER para continuar." );
}//end method_06

/*Method_07*/
double calcularSomaInverso(chars fileName, int n){
	FILE* arquivo = fopen ( fileName, "rt" );
	
	int cont = 0; 
	double soma = 0.0, z = 0.0;
	double numerador = 0.0, denominador = 0.0;
	
	while (!feof(arquivo) && cont < n) {
		fscanf(arquivo, "%lf/%lf", &numerador, &denominador);
		if (denominador == 0) {
			printf("%d\n", cont+1);
		}
		else{	
			z = numerador / denominador;
			printf("%.0lf/%.2lf = %.4lf\n", numerador, denominador, z);
		}
		soma += z;
		cont = cont + 1;
	} // end while

	printf("Soma: %.4lf\n", soma);
	// fechar arquivo 
	fclose(arquivo);
	// escrever n e a soma em um novo arquivo
	// a para abrir o arquivo
	FILE* novoArquivo = fopen("RESULTADO07.TXT", "at");
	
	fprintf(novoArquivo, "Quantidade (n): %d\n", n);
	fprintf(novoArquivo, "Soma: %.4lf\n", soma);
	
	fclose(novoArquivo);
	return soma;
}

void method_07(){
	//identificar
	IO_id("\nMethod_07 - Soma dos inversos.");
	//definir dado
	int n = 0;
	//ler dado
	n = IO_readint("Digite a quantidade: ");
	getchar();
	//chamar funcao
	calcularSomaInverso("INVERSOSEQUENCIA.TXT", n);
	// encerrar
	IO_pause ("\nApertar ENTER para continuar." );
}//end method_07

/*Method_08*/
int fibonacci(int x) {
	if (x == 1 || x == 2) {
		return 1; // primeiros dois valores iguais a 1
	} 
	else {
		return fibonacci(x - 1) + fibonacci(x - 2);
	}
}

int fibonacci_par(int n, chars fileName) {
	int termo = 0;
	int cont = 0;
	
	FILE* arquivo = fopen(fileName, "at");
	
	fprintf(arquivo, "n = %d =>  ", n);
	
	for (int i = 1; cont < n; i = i + 1) {
		termo = fibonacci(i);
		
		if (termo % 2 == 0) {
			fprintf(arquivo, "%d ", termo); // grava o termo par no arquivo
			cont = cont + 1;
		}
	}
	
	fclose(arquivo);
	return (termo);
}

void method_08() {
	printf("Method_08 - Primeiros termos pares da serie de Fibonacci.s\n");
	
	int n = 0;
	
	n= IO_readint("Digite a quantidade: ");
	getchar();
	
	fibonacci_par(n, "RESULTADO08.TXT");
	
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}//end method_08

/*Method_09*/
int contarMaisculas(chars fileName, chars cadeia){
	int contar = 0;
	int tamanho = 0;
	FILE* arquivo = fopen(fileName, "at");
	
	fprintf(arquivo, "%s => ", cadeia);
	tamanho = strlen(cadeia);
	for(int i = 0; i <= tamanho; i = i +1 ){
		if(cadeia[i] >='A' && cadeia[i] <= 'Z'){
			contar = contar + 1;
		}
	}
	fprintf(arquivo, "%d \n", contar);
	//fechar arquivo
	fclose(arquivo);
	return (contar);
	
}

void method_09(void){
	//identificar
	IO_id("Method_09 - Contar Maiusculas.");
	//definir variavel
	chars cadeia = IO_new_chars(STR_SIZE);
	//ler dado
	cadeia = IO_readln("Digite uma cadeia de caracteres: ");
	getchar();
	//chamar funcao
	contarMaisculas("RESULTADO09.TXT", cadeia);
	
	IO_pause("Aperte ENTER para continuar.");
}//end method_09

/*Method_10*/
int contarDigitos(chars fileName, chars cadeia){
	int contar = 0;
	int tamanho = 0;
	FILE* arquivo = fopen(fileName, "at");
	
	fprintf(arquivo, "%s => \n", cadeia);
	tamanho = strlen(cadeia);
	for(int i = 0; i <= tamanho; i = i + 1){
		if(cadeia[i]>= '0' && cadeia[i]<= '9'){
			if(cadeia[i] >= '5'){
				contar = contar + 1;
			}
		}
	}
	fprintf(arquivo, "Digitos maiores que 5 -> %d\n", contar);
	//fechar arquivo
	fclose(arquivo);
	return (contar);
}

void method_10(void){
	//identificar
	IO_id("Method_10 - Contar digitos maiores ou iguais a 5.\n");
	//definir variavel
	chars cadeia = IO_new_chars(STR_SIZE);
	//ler dados
	cadeia = IO_readln("Digite uma cadeia de caracteres: ");
	getchar();
	//chamar funcao
	contarDigitos("RESULTADO10.TXT",cadeia);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_10()

/* EXTRAS */

/*Method_07E1*/
int divisoresImpares(chars fileName, int x){
	int divisor = 0;
	FILE* arquivo = fopen(fileName, "wt");
	
	fprintf(arquivo, "%d => ", x);
	for (divisor = x; divisor > 0; divisor = divisor - 1) {
		if (x % divisor == 0 && divisor % 2 != 0) {
			fprintf(arquivo, " %d ", divisor);
		}
	}
	//fechar arquivo
	fclose(arquivo);
	return (divisor);
}

void method_11(void){
	//identificar
	IO_id("Method_11 - Divisores impares decrescente.");
	//definir dado
	int x = 0;
	//ler dado
	x = IO_readint("\nDigite um valor: ");
	getchar();
	//chamar funcao
	divisoresImpares("EXTRA07E1.TXT", x);

	IO_pause("\nAperte ENTER para continuar.");
}//end method_11

/*Method_07E2*/
int contarPalavras(chars fileName) {
	//abrir arquivo
	FILE* arquivo = fopen(fileName, "rt");
	chars linha = IO_new_chars(STR_SIZE);
	int contador = 0;
	
	// tentar ler o primeiro
	strcpy(linha, IO_freadln(arquivo));
	// Contar as palavras que começam com 'c' ou 'C'
	while (!feof(arquivo)) {
		if (linha[0] == 'c' || linha[0] == 'C') {
			contador= contador + 1;
		}
		// tentar ler o proximo
		strcpy(linha, IO_freadln(arquivo));
	}
	
	// Fechar o arquivo
	fclose(arquivo);
	
	printf("O arquivo possui %d palavras que comecam com 'c' ou 'C'.\n", contador);
	return (contador);
}

void method_12(void){
	//identificar
	IO_id("\nMethod_12 - Palavras que iniciam com 'C' ou 'c'. ");
	//chamar metodo
	contarPalavras("PALAVRAS.TXT");
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_12

int main(){
	int opcao = 0;
	printf ( "%s\n", "Exercicios 0700 - Programa = v0.0" );
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



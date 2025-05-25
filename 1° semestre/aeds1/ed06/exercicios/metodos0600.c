/* Metodos 0600 - ED06 
Rayssa Mell de Souza Silva - 860210*/

#include<stdio.h>
#include "io.h"

/*Method_01*/

void method_01a ( int n, int cont )
{
	int num = 6;
	int multiplo = 1;
	if ( cont <= n )
	{
		// mostrar valor
		multiplo = num * cont;
		IO_printf ( "%d: %d\n", cont, multiplo );
		method_01a ( n,cont + 1); // motor da recursividade
		// passar ao proximo
	}// end if
} // end method_01a( )

void method_01(void){
	printf ( "\n%s", "Method_01 - Multiplos de 6" );
	int n = 0;
	
	n = IO_readint("\nDigite uma quantidade: ");
	getchar();
	method_01a(n,1);
}

/*Method_02*/
void method_02a(int n, int cont){
	
	int num = 6;
	int multiplo = 1;
	
	if ( cont >= n ){
		multiplo = num * cont;
		printf ( "%d: %d\n", cont, multiplo );
		method_02a (n, cont - 1); // motor da recursividade
	}
}

void method_02(void){
	printf ("\n%s", "Method_02 - Multiplos de 6 decrescente" );
	int n = 0;
	
	printf("\nDigite a quantidade: ");
	scanf("%d", &n);
	getchar();
	
	method_02a(1,n); // começar do maior múltiplo possível
	
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}

/*Method_03*/
void method_03a(int n){
	//int multiplo = 0;
	int num = 6;
	
	if ( n > 1){
		method_03a(n - 1);
		//multiplo = num * 6;
		printf("\n%d: 1/%d", n, num*(n-1));
		//num = num * 6;
	}
	else{
		printf("\n%d: 1/1", n);
	}
}

void method_03(void){
	printf ("\n%s", "Method_03 - Multiplos de 6 inverso" );
	int n = 0;
	
	n = IO_readint("\nDigite a quantidade: ");
	getchar();
	method_03a(n);
	
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
	
}//end method_03

/*Method_04*/
void method_04a(int n, int cont){
	int multiplo = 0;
	int num = 1;
	
	if ( cont > 1){
		multiplo = num * 6 * (cont - 1);
		printf("\n%d: 1/%d", cont, multiplo);
		method_04a(n, cont - 1);
	}
	else{
		printf("\n%d: 1/1", cont);
	}
}

void method_04(void){
	printf ("\n%s", "Method_04 - Multiplos de 6 inverso decrescente" );
	int n = 0;
	
	printf("\nDigite a quantidade: ");
	scanf("%d", &n);
	getchar();
	
	method_04a(1,n); // começar do maior múltiplo possível
	
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
	
}//end method_04

/*Method_05 calcular a soma de valores gerados pela adição dos primeiros valores pares positivos ao valor 6.*/
int somarPares(int n, int num, int cont){
	int soma = 0;
	
	if(cont <= n){
		printf("\n%d: %d", cont, num);
		int par = 2*cont;
		soma = num + somarPares(n, num + par, cont+1);
	}
	else{
		return 0; 
	}
	return soma;
}

void method_05(void){
	printf ("\n%s", "Method_05 - Soma de Valores da adicao dos pares." );
	int n = 0;
	n = IO_readint("\nDigite a quantidade: ");
	int resultado = somarPares(n,6,1);
	printf("\n\nSoma dos pares: %d", resultado);
	
	printf("\n");
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}

/*Method_06*/
double somaInversoSeis(int n, int cont){
	int num = 6;
	double multiplo = 0;
	double numerador = 1.0;
	double soma = 0;
	
	if ( cont <= n){
		// mostrar valor
		multiplo = numerador/(num*cont);
		IO_printf ( "%.0lf/%d = %.3lf\n", numerador, num * cont, multiplo);
		soma = multiplo + somaInversoSeis ( n,cont + 1); // motor da recursividade;
	}
	return soma;
}

void method_06(void){
	printf ("\n%s", "Method_06 - Soma dos Inversos dos multiplos de 6." );
	int n = 0;
	n = IO_readint("\nDigite a quantidade: ");
	double resultado = somaInversoSeis(n,1);
	printf("\nSoma dos Inversos: %.3lf", resultado);
	
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}//end method_06

/*Method_07*/
void method_07a(chars cadeia, int l){
	int tamanho = strlen(cadeia);
	
	if(l >= tamanho){
		return ;
		
	}
	else{
		printf("\n%c", cadeia[l]); // Imprime o caractere atual
		method_07a(cadeia, l + 1);
	}
}

void method_07(void){
	printf ("\n%s", "Method_07 - Cadeia de caracteres." );
	chars cadeia = IO_new_chars(STR_SIZE);
	cadeia = IO_readstring("\nDigite uma cadeia de caracteres: ");
	printf("\nSequencia: ");
	method_07a(cadeia, 0);
	
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}

/*Method_08*/
int contarPar(chars cadeia, int l){
	int par = 0;
	
	if(l >= strlen(cadeia)){
		return par;
	}
	else{
		if ( '0' <= cadeia[l] && cadeia[l] <= '9' ){
			if(cadeia[l] % 2 == 0){
			printf("\nPar: %c", cadeia[l]);
			par = par + 1;
		    }
		}
		return par + contarPar(cadeia, l + 1);
	}
	return par;
}

void method_08(void){
	printf ("\n%s", "Method_08 - Contar pares em uma cadeia de caracteres." );
	chars cadeia = IO_new_chars(STR_SIZE);
	cadeia = IO_readstring("\nDigite uma cadeia de caracteres: ");
	getchar();
	int total = contarPar(cadeia,0);
	printf("\nTotal de pares: %d", total);
	
	printf("\n");
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}//end method_08

/*Method_09*/
int menoresL(chars cadeia, int l){
	int menores = 0;
	
	if(l >= strlen(cadeia)){
		return menores;
	}
	else{
		if(cadeia[l] < 'L' && (!('0' <= cadeia[l] && cadeia[l] <= '9'))){
			printf("\nMenor que L: %c", cadeia[l] );
			menores = menores + 1;
		}
		return menores + menoresL(cadeia, l + 1);
	}
	return 0;
}

void method_09(void){
	printf ("\n%s", "Method_09 - Contar maisculas menores que L." );
	chars cadeia = IO_new_chars(STR_SIZE);
	cadeia = IO_readstring("\nDigite uma cadeia de caracteres: ");
	getchar();
	int total = menoresL(cadeia,0);
	printf("\nTotal de maiusculas menores que L: %d", total);
	
	printf("\n");
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}//end method_09

/*Method_10*/
int fibonacci(int x) {
	int resposta = 0;
	
	if (x == 1 || x == 2) {
		resposta = 1; // primeiros dois valores iguais a 1
	} 
	else {
		if (x > 1) {
			resposta = fibonacci(x-1) + fibonacci(x-2);
		}
	}
	return resposta;
}

int fibonacci_par(int n, int valor) {
	
	if (fibonacci(n) > valor) {
		return 0;
	}
	else{
		int termo = fibonacci(n);
		if (termo % 2 == 0) {
			return termo + fibonacci_par(n + 1, valor);
		} else {
			return fibonacci_par(n + 1, valor);
		}
	}
}

void method_10() {
	printf("Method_10 - \n");
	
	int n = 0;
	int resultado = 0;
	
	printf("Digite a quantidade: ");
	scanf("%d", &n);
	
	resultado = fibonacci_par(1, n);
	printf("Para valor = %d, soma dos termos pares de Fibonacci: %d\n", n, resultado);
	
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}// end method_10

/*   EXTRAS   */

/* Method_06E1 */
int calcular(int n, int x, int cont){
	int soma = 0;
	
	if(n == 0){
		return 1;
	}
	else{
		int potencia = pow(x, 2*cont+1);
		printf("\n%d^%d = %d", x,2*cont+1, potencia);
		soma =  potencia + calcular(n - 1, x, cont + 1);
	}
	return soma;
	
}

void method_11(void){
	printf ("\n%s", "Method_06E1" );
	int n = 0;
	int x = 0;
	
	n = IO_readint("\nDigite a quantidade: ");getchar();
	x = IO_readint("\nDigite um valor: ");getchar();
	
	int resultado = calcular(n,x,1);
	printf("\nResultado = %d", resultado);
	
	printf("\n");
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}

/*Method_06E2*/
int fatorial(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	else{
		return n * fatorial(n - 1);
	}
}

double calcular_e(int n, int cont){
	
	if(n == 0){
		return 1.0;
	}
	else{
		double termo = (2.0 * cont + 1) / (double) fatorial(2 * cont);
		printf("\n%d/%d!: %.4lf", 2 * cont + 1, 2 * cont, termo);
		return termo + calcular_e(n - 1, cont + 1);
	}
}

void method_12(void){
	printf("\n%s", "Method_06E2");
	int n = 0;
	
	n = IO_readint("\nDigite a quantidade de termos: ");
	getchar();
	
	double resultado = calcular_e(n, 0);
	printf("\nResultado = %.6lf", resultado);
	
	printf("\n%s", "Aperte ENTER para continuar.");
	getchar();
}

int main(){
	int opcao = 0;
	printf ( "%s\n", "Exercicios 0500 - Programa = v0.0" );
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

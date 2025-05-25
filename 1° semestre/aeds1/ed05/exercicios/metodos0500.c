/*
EXERCICIOS 0500 - 
Aluna: Rayssa Mell de Souza Silva - 860210 
*/

#include<stdio.h>
#include "io.h"
#include<math.h>

/*Method_01
*/
int multiplosSeis(int x){
	// definir variaveis
	int y = 1; //controle
	int num = 6;
	
	while(y <= x){
		printf("\n%s%d", "Valor: ", num * y);
		y = y + 1;
	}
	return(y);
}

void method_01(void){
	//identificar
	printf("\nMethod_01 - Multiplos de 6");
	//definir variaveis
	int n = 0;
	//ler dados
	n = IO_readint("\nDigite a quantidade: ");
	getchar();
	//chamar funcao
	multiplosSeis(n);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_01

/*Method_02*/

int multiplosQuinze(int x){
	int y = 1;
	// multiplos de 3 e 5 ou de 15
	int m = 15;
	
	while(y <= x){
		printf("\n%s%d", "Valor: ", m * y );
		y = y + 1;
	}
	return(y);
}

void method_02(void){
	//identificar
	printf("\nMethod_02 - Multiplos de 3 e 5");
	//definir variavel
	int n = 0;
	//ler dado
	n = IO_readint("\nDigite a quantidade: ");
	getchar();
	//chamar funcao
	multiplosQuinze(n);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_02

/*Method_03 */
int calcPotencia(int x){
	int y = 0;
	double num = 4.0;
	for ( y = x; y > 0; y = y-1 ){
		printf("\n%d: %d", y, (int)pow(num,y)) ;
	}
	return(y);
}

void method_03(void){
	//identificar
	printf("\nMethod_03 - Potencia de 4 em ordem decrescente.\n");
	//definir dado
	int n = 0;
    //ler dado
	n = IO_readint("\nDigite a quantidade: ");
	getchar();
	//chamar funcao
	calcPotencia(n);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_03

/*Method_04*/
int calcMultiplo(int x){
	
	int y = 1;
	int num = 6;
	
	while(y <= x){
		printf("\nValor: 1/%d ", num * y);
		y = y + 1;
	}
	return(y);
}

void method_04(void){
	//identificar
	printf("\nMethod_04 - Multiplos de 6 - sequencia dos inversos\n");
	//definir dado
	int n = 0;
	//ler dado
	n = IO_readint("Digite a quantidade: ");
	getchar();
	//chamar funcao
	calcMultiplo(n);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_04

/*Method_05*/
void sequenciapares(int n, double x){
	int cont = 1;
	int z = 0;
	while(cont <= n){
		if (z == 0) {
			printf("\n%d: 1", cont);
		} else {
			printf("\n%d: 1/%.2lf", cont, pow(x, z));
		}
		// passar ao próximo par
		z = z + 2;
		cont = cont + 1;
	}
}

void method_05(void){
	//identificar
	printf("\nMethod_05\n");
	//definir variaveis
	int n = 0;
	double x = 0.0;
	//ler dados
	n = IO_readint("Digite a quantidade: ");getchar();
	x = IO_readdouble("Entre com um valor real: ");getchar();
	//chamar funcao
	printf("Sequencia: ");
	sequenciapares(n,x);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_05

/*Method_06 */
int multiploTres(int n){
	int m = 3;
    float soma = 0;
	int cont = 1;
	int multiplo = 0;
	
	while (cont <= n){
		if((m % 3 == 0) && (m % 5 != 0)){
			multiplo = m;
			printf("\n%d: %d", cont, multiplo);
			soma = soma + multiplo;
			cont = cont + 1;
		}
		m = m + 1;
	}
	return soma;
}

void method_06(void){
	//identificar
	printf("\nMethod_06 - Multiplos de 3\n");
	//definir variaveis
	int n = 0;
	float soma = 0;
	//ler dado
	n = IO_readint("Digite a quantidade: ");
	getchar();
	//chamar funcao
	soma = multiploTres(n);
	printf("\nSoma = %.2f", soma);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_06

/*Method_07 */
int calcInversoSeis(int n){
	int num = 6;
	int cont = 1;
	int multiplo = 0;
	float soma = 0;
	
	while(cont <= n){
		if ((num % 6 == 0) && (num % 5 != 0)){
			multiplo = num;
			printf("\n%d: 1/%d", cont, multiplo);
			soma = soma + (1.0/multiplo);
			cont = cont + 1;
		}
		num = num + 1;
	}
	printf("\nSoma dos Multiplos: %.3f", soma);
	return multiplo;
}

void method_07(void){
	//identificar
	printf("\nMethod_07 - Multiplos de 6 - Soma dos inversos\n");
	//definir variavel
	int n = 0;
	//ler dado
	n =  IO_readint("Digite a quantidade: ");
	getchar();
	//chamar funcao
	calcInversoSeis(n);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_07

/*Method_08*/
float calcSoma(int n){
	int num = 6;
	int cont = 1;
	float soma = 0;
	
	while(cont <= n){
		int naturais = num;
		printf("\n%d: %d", cont, naturais);
		num = num + cont;
		soma = soma + naturais;
		cont = cont + 1;
	}
	return soma;
}

void method_08(void){
	//identificar 
	printf("\nMethod_08 - Soma da adicao dos numeros naturais a partir de 6\n");
	//definir variavel
	int n = 0;
	float soma = 0;
	//ler dado
	n = IO_readint("Digite a quantidade: ");
	getchar();
	//chamar funcao
	soma = calcSoma(n);
	printf("\nSoma dos numeros naturais: %.2f", soma);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_08

/*Method_09
calcular a soma dos quadrados da adição dos números naturais começando no valor 6*/
double somaQuadrados(int n){
	int cont = 1;
	int num = 6;
	double soma = 0;
	
	while(cont <= n){
		int q = num * num;
		printf("\n%d: %d", cont, q);
		num = num + 1;
		soma = soma + q; 
		cont = cont + 1;
	}
	return soma;
}

void method_09(void){
	//identificar
	printf("\nMethod_09 - Soma dos quadrados dos numeros naturais a partir de 6\n");
	//definir dado
	int n = 0;
	double soma = 0;
	//ler dado
	n = IO_readint("\nDigite uma quantidade: ");
	//chamar funcao
	printf("\nSequencia: ");
	soma = somaQuadrados(n);
	printf("\nSoma dos quadrados: %.2lf", soma);
	
	IO_pause("\nAperte ENTER para continuar.");
}//end method_09

/*Method_10*/
float inversoAdicao(int n) {
	int num = 6;
	float soma = 0;
	
	for (int cont = n; cont > 0; cont = cont -1) {
		int inverso = num + cont - 1;
		printf("\n%d: 1/%d", cont, inverso);
		soma=soma + (1.0/inverso);
	}
	return soma;
}

void method_10(void){
	//identificar
	printf("\nMethod_10 - Soma dos inversos dos numeros naturais a partir de 6\n");
	//definir dado 
	int n = 0;
	float soma = 0;
	//ler dado
	n = IO_readint("Digite a quantidade: ");
	//chamar funcao
	soma = inversoAdicao(n);
	printf("\nSoma dos Inversos: %.2f", soma);
	
	IO_pause("\nAperte ENTER para continuar.");
}
//EXTRAS

int fatorial(int n) {
	int result = 1;
	if (n > 0) {
		for (int cont = 1; cont <= n; cont++) {
			result *= cont;
	}
	}
	return result;
}

void method_05E1(void){
	//identificar
	printf("\nMethod_11- Calcular Fatorial\n");
	//definir dado
	int n = 0;
	//ler dado
	n = IO_readint("\nDigite um numero: ");
	//chamar funcao
	int resultado = fatorial(n);
	printf("Fatorial de %d: %d", n,resultado);
	
	IO_pause("\nAperte ENTER para continuar.");
}

double calcularF(int n) {
	double resultado = 1.0;
	int numerador = 2; 
	int denominador = 5; 
	
	for (int cont = 1; cont <= n; cont = cont + 1) {
		int d = fatorial(denominador);
		double fracao = 1.0 + ((double)numerador / d);  // Convertendo numerador para double
		resultado *= fracao;
		resultado = resultado * fracao;
		numerador = numerador + 2; 
		denominador = denominador +  2; 
	}
	
	return resultado;
}

void method_05E2(void){
	//identificar
	printf("\nMethod_12- Calcular Fatorial\n");
	//definir dado
	int n = 0;
	//ler dado
	n = IO_readint("\nDigite a quantidade: ");
	//chamar funcao
	double resultado = calcularF(n);
    printf("Resultado: %.3lf\n", resultado);
	
	IO_pause("\nAperte ENTER para continuar.");
}

int main(){
	int opcao = 0;
	printf ( "%s\n", "Exercicios 0500 - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
	do{
		printf("\n%s\n", "\nOpcoes: ");
		printf("\n%s", "0 - Terminar");
		printf ( "\n%s" ,"1 - Method_01    2 - Method_02" );
		printf ( "\n%s" ,"3 - Method_03    4 - Method_04" );
		printf ( "\n%s" ,"5 - Method_05    6 - Method_06" );
		printf ( "\n%s" ,"7 - Method_07    8 - Method_08" );
		printf ( "\n%s" ,"9 - Method_09    10 - Method_10" );
		printf ( "\n%s" ,"11 - Method_11   12 - Method_12" );
		printf("\n");
		
		printf("\n%s", "Opcao = ");
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
			method_05E1();
			break;
		case 12:
			method_05E2();
			break;
		default:
			printf ( "\nERRO: Opcao invalida.\n" );
			break;
		}
	}while(opcao != 0);
	
	printf("Aperte ENTER para terminar.");
	getchar();
	return(0);
	
}

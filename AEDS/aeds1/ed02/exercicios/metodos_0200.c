/*
Exercicios - v0.0. - 16 / 03 / 2024
Author: Rayssa Mell de Souza Silva //860210
*/

#include <stdio.h> // para entradas e saidas
#include "io.h"

/* Method_01*/
void method_01(){
	//identificar
	IO_id("\nMethod_01 - Questao_1 - Programa - v0.0");
	//definir variaveis
	int x = 0;
	//ler dado
	x = IO_readint("Digite um valor inteiro: ");
	//testar valor
	if ( x % 2 == 0 ){
		IO_printf("Valor par\n");
	}
	else{
		IO_printf("Valor Impar\n");
	}
	IO_pause ( "Apertar ENTER para continuar" );
}//end method_01()

/*Method_02*/
void method_02(){
	//identificar
	IO_id("\nMethod_02 - Questao_02 - Programa - v0.0");
	//definir variavel
	int x = 0;
	//ler dado
	x = IO_readint("Digite um valor inteiro: ");
	//testar valor impar e menor que -25
	if(((x % 2 == 1)|| (x % 2 == -1)) && (x < -25)){
		printf("Valor Impar e menor que -25");
	}
	else {
		//testar se o valor eh impar e maior que -25
		if((( x % 2 == 1) || ( x % 2 == -1)) && (x > -25)){
			printf("Valor impar e maior que -25");
		}
		else{
			if ((x % 2 == 0) && x > 25){
				printf("Valor par e maior que 25");
			}
			else {
				if((x % 2 == 0) && x < 25)
					printf("Valor par e menor que 25");
			}
		}
	}
	IO_pause ( "\nApertar ENTER para continuar" );
	getchar( ); // aguardar por ENTER
	
}//end method_02()

/*Method_03*/
void method_03(){
	//identificar
	IO_id("\nMethod_03 - Questao_03 - Programa - v0.0");
	// definir variaveis
	int x = 0;
	//ler dados
	x = IO_readint("\nDigite um valor inteiro: ");
	// testar dados
	if( x > 35 && x < 65 ){
		printf("O valor %d pertence ao intervalo aberto [35:65]", x);
	}
	else{
		printf("O valor %d nao pertence ao intervalo aberto [35:65]", x);
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}// end method_03

/*Method_04*/
void method_04(){
	//identificar
	IO_id("\nMethod_04 - Questao_04 - Programa - v0.0");
	//definir variavel
	int x = 0;
	//ler dado
	x = IO_readint("Digite um valor inteiro: ");
	//testar dado
	if (x >= 15 && x <= 60){
		printf("O valor %d pertence ao intervalo fechado [15:60]", x);
	}
	else{
		printf("O valor %d nao pertence ao intervalo fechado [15:60]", x);
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}//end method_04

/*Method_05*/
void method_05(){
	//identificar
	IO_id("\nMethod_05 - Questao_05 - Programa - v0.0");
	// definir variavel 
	int x = 0;
	//ler dado
	x = IO_readint("Digite um valor inteiro: ");
	//testar dados
	if ((x >= 10 && x <= 30 ) && ( x >= 25 && x <= 50)){
		printf("O valor %d pertece a intersecao de [10:30] e [25:50]", x);
	}
	else{
		if (x >= 10 && x <= 30 ){
			printf("O valor %d pertece apenas ao intervalo fechado de [10:30]", x);
		}
		else{
			if(x >= 25 && x <= 50 ){
				printf("O valor %d pertece apenas ao intervalo fechado de [25:50]", x);
			}
			printf("O valor %d nao pertece a nenhum dos intervalos.", x);
		}
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}//end method_05()

/*Method_06*/
void method_06(){
	//identificar
	IO_id("\nMethod_06 - Questao_06 - Programa - v0.0");
	//definir variaveis
	int x = 0, y = 0;
	//ler dados
	x = IO_readint("Digite um valor inteiro: ");
	y = IO_readint("Digite outro valor inteiro: ");
	//testar dados
	if(((x % 2 == 1) || (x % 2 == -1)) && (y % 2 == 0)){
		printf("O primeiro valor eh impar e o segundo valor eh par");
	}
	else{
		printf("O primeiro valor nao eh impar ou o segundo valor nao eh par");
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}//end method_06()

/* Method_07 */

void method_07(){
	//identificar
	IO_id("\nMethod_07 - Questao_07 - Programa - v0.0");
	//definir variaveis
	int x = 0, y = 0;
	//ler dados
	x = IO_readint("Digite um valor: ");
	y = IO_readint("Digite outro valor: ");
	//primeiro valor par e negativo e segundo impar e positivo
	if(((x % 2 == 0) && (x < 0)) && (((y % 2 == 1)||(y % 2 == -1)) && ( y > 0)) ){
		printf("Primeiro valor par e negativo (%d)  \nSegundo valor impar e positivo (%d)\n", x, y);
	}
	else{
		//primeiro valor par e positivo e segundo impar e negativo
		if(((x % 2 == 0) && (x > 0)) && (((y % 2 == 1)||(y % 2 == -1)) && ( y < 0)) ){
			printf("Primeiro valor par e positivo (%d)  \nSegundo valor impar e negativo (%d)\n", x, y);
		}
		else{
			//primeiro nao ser par e segundo nao ser impar
			if(!((x % 2 == 0) && ((y % 2 == 1)||(y % 2 == -1)))){
				printf("Primeiro valor nao eh par (%d)  \nSegundo valor nao eh impar (%d)\n", x, y);
			}
		}
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}//end method_07

/*Method_08*/
void method_08(){
	//identificar
	IO_id("\nMethod_08 - Questao_8 - Programa - v0.0");
	// definir variaveis
	double x = 0.0, y = 0.0, z = 0.0;
	//ler dados
	x = IO_readdouble("Digite um valor real: ");
	y = IO_readdouble("Digite outro valor real: ");
	// testar variaveis
	z = x * 1.0/3.0; 
	//  dizer se o segundo é menor, igual ou maior que um terço do primeiro
	if(y==z){
		printf("O segundo valor (%.2lf) eh igual a 1/3 do primeiro (%.2lf)", y,z);
	}
	else{
		if(z>y){
			printf("O segundo valor (%.2lf) eh menor que 1/3 do primeiro (%.2lf)", y,z);
		}
		else{
			if(y > z){
				printf("O segundo valor (%.2lf) eh maior que 1/3 do primeiro (%.2lf)", y,z );
			}
		}
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}//end method_08

/*Method_09*/
void method_09(){
	//identificar
	IO_id("\nMethod_09 - Questao_9 - Programa - v0.0");
	// definir variaveis
	double x = 0.0, y = 0.0, z = 0.0;
	//ler dados
	x = IO_readdouble("Digite um valor: ");
	y = IO_readdouble("Digite um valor: ");
	z = IO_readdouble("Digite um valor: ");
	//testar dados
	if(y != z){
		if (((y<x) && (x<z)) || ((y>x) && (x>z))){
			IO_printf ("\n%s(%lf)%s(%lf)%s(%lf)","O valor ",x," esta entre ",y ," e ",z);
		}
		else{
			IO_printf ("\n%s(%lf)%s(%lf)%s(%lf)","O valor ",x," nao esta entre ",y ," e ",z);
		}
	}
	else
	{
		IO_printf ( "\n%s", "Segundo e Terceiro valores iguais" );
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}//end method_09

/*Method_10*/
void method_10(){
	//identificar
	IO_id("\nMethod_10 - Questao_10 - Programa - v0.0");
	//definir variaveis
	double x = 0.0, y = 0.0, z = 0.0;
	//ler dados
	x = IO_readdouble("Digite um valor: ");
	y = IO_readdouble("Digite um valor: ");
	z = IO_readdouble("Digite um valor: ");
	//testar dados
	if(!((x==y) && (x==z)&&(y==z))){
		if (!(((y<x) && (x<z)) || ((y>x) && (x>z)))){
			IO_printf ("\n%s(%lf)%s(%lf)%s(%lf)","O valor ",x," nao esta entre ",y ," e ",z);
		}
		else{
			IO_printf ("\n%s(%lf)%s(%lf)%s(%lf)","O valor ",x," esta entre ",y ," e ",z);
		}
	}
	else
	{
		IO_printf ( "\n%s", "Valores iguais" );
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}//end method_10

int main(){
	//definir variavel
	int opcao = 0;
	// identificar
	printf ( "%s\n", "Exemplos0200 - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
	// acoes
	// repetir
	do {
		// mostrar opcoes
		printf ( "\n%s\n", "Opcoes:" );
		printf ( "\n%s" , "0 - Terminar" );
		printf ( "\n%s" , "1 - Method_01" );
		printf ( "\n%s" , "2 - Method_02" );
		printf ( "\n%s" , "3 - Method_03" );
		printf ( "\n%s" , "4 - Method_04" );
		printf ( "\n%s" , "5 - Method_05" );
		printf ( "\n%s" , "6 - Method_06" );
		printf ( "\n%s" , "7 - Method_07" );
		printf ( "\n%s" , "8 - Method_08" );
		printf ( "\n%s" , "9 - Method_09" );
		printf ( "\n%s" , "10 - Method_10" );
		printf ( "\n" );
		// ler a opcao do teclado
		printf ( "\n%s", "Opcao = " );
		scanf ( "%d", &opcao );
		getchar( ); // para limpar a entrada de dados
		// para mostrar a opcao lida
		printf ( "\n%s%d", "Opcao = ", opcao );
		// escolher acao dependente da opcao
		switch (opcao) {
		case 0:
			break;
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
		default:
			printf ( "\nERRO: Opcao invalida.\n" );
			break;
		}
	}
	while ( opcao != 0 );
// encerrar
	printf ( "\n\nApertar ENTER para terminar." );
	getchar( ); // aguardar por ENTER
	return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )

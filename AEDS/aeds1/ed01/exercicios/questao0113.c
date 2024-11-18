#include <stdio.h> // para entradas e saídas
/*Rayssa Mell de Souza Silva - 860210 - ED01*/

#include <stdlib.h> // para outras funcoes de uso geral
#include <math.h>

int main ( )
{
	/* PROGRAMA PARA LER OS LADOS DE UM RETANGULO E MOSTRAR A AREA SEIS VEZES MAIOR*/
	
	// definir variavel:
	double area = 0.0;
	int lado_a = 0, lado_b = 0;
	
	//IDENTIFICAR
	printf ( "Questao_03 - Area do Retangulo\n" );
	// ler dados
	printf ( "Digite uma medida: " );
	scanf("%i", &lado_a);
	printf ( "Digite uma medida: " );
	scanf("%i", &lado_b);
	// calcular a area seis vezes maior 
	area = (lado_a * lado_b)*6;
	// mostrar area
	printf ( "\nArea do retangulo seis vezes maior= %.2lf", area );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
	return ( EXIT_SUCCESS );
} // fim do programa

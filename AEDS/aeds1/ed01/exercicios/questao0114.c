/*Rayssa Mell de Souza Silva - 860210 - ED01*/

#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
#include "io.h"
#include <math.h>

int main ( )
{
	/* PROGRAMA PARA LER OS LADOS DE UM RETANGULO E MOSTRAR A AREA E O PERIMETRO 1/4 MENOR*/
	
	// definir variavel:
	float area = 0.0, perimetro = 0.0;
	int lado_a = 0, lado_b = 0;
	
	//IDENTIFICAR
	printf ("Questao_04 - Area e Perimetro de um Retangulo\n" );
	// ler dados
	printf ("Digite uma medida: " );
	scanf("%d", &lado_a);
	printf ("Digite uma medida: " );
	scanf("%d", &lado_b);
	// calcular a area com 1/4 dos lados
	area = (lado_a/4)*(lado_b/4);
	//calcula perimetro com 1/4 dos lados
	perimetro = ((lado_a/4) * 2) + ((lado_b/4)*2) ;
	// mostrar area
	printf ( "\nArea do retangulo com lados 1/4 menor= %.2f", area );
	//mostrar perimetro
	printf ( "\nPerimetro do retangulo com lados 1/4 menor= %.2f\n", perimetro );
	//encerrar
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
	return ( EXIT_SUCCESS );
} // fim do programa

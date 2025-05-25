/*Rayssa Mell de Souza Silva - 860210 - ED01*/

#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
#include "io.h"
#include <math.h>
int main ( )
{
// PROGRAMA PARA LER O LADO DE UM QUADRADO E MOSTAR A AREA DE UM QUADRADO 3 VEZES MAIOR
    // definir variavel:
	int lado = 0;
	double area = 0.0;
	//IDENTIFICAR
	printf ( "Questao_01 - Area de um quadrado 3 vezes maior" );
	// ler dado
	lado = readint("\nDigite um valor inteiro:  ");
	// calcular o triplo do lado e a area do novo lado
	area = pow((lado*3.0), 2.0);
    // mostrar area
	printf ( "\nArea do quadrado com lado tres vezes maior = %.2lf", area );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
	return ( EXIT_SUCCESS );
} // fim do programa


/*
Exemplo0100 - v0.0. - 11/03/2024
Author: Rayssa Mell de Souza Silva
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
#include <stdbool.h> // para valores logicos
#include <string.h> // para lidar com caracteres
#include <math.h> // para operacoes matematicas
#include "io.h"
#include "my_string.h"
#include "my_lib.h"


/**
  Method_01.
 */
void method_01 ( void )
{
	// PROGRAMA PARA MOSTRAR O USO DE MODULOS
	// VARIAVEIS :
	chars text = "MUDAR DE LINHA";
	println ( "EXEMPLO0510 - USO DE MODULOS" );
	printf ( "%c", EOL );
	printf ( "%s%c", text, EOL );
	pause ( "PRESSIONAR <Enter> PARA TERMINAR." );

	
} // end method_01 ( )

/*Method_02*/
void CONTAR ( int X )
{
	if ( X > 0 )
	{
		CONTAR ( X-1 );
		printf ( "\n%d\n", X );
	}
} // fim procedimento CONTAR( )

void method_02 ( void )
{
	// PROGRAMA PARA CONTAR DE 1 ATE' 5, RECURSIVAMENTE
	printf ( "EXEMPLO601 - CONTAR DE 1 A 5 RECURSIVAMENTE\n" );
	CONTAR ( 5 );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_02 ( )

/*Method_03*/
void CONTAR_m3 ( int X )
{
	if ( X > 0 )
	{
		printf ( "\n%d\n", X );
		CONTAR_m3 ( X-1 );
	}
} // fim procedimento CONTAR( )

void method_03 ( void )
{
	// PROGRAMA PARA CONTAR 5 10 ATE' 1, RECURSIVAMENTE
	printf ( "EXEMPLO602 - CONTAR DE 5 A 1 RECURSIVAMENTE\n" );
	CONTAR_m3 ( 5 );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_03 ( )

/*Method_04*/
void PARES ( int X )
{
	if ( X > 0 ){
		if ( X % 2 == 0 )
		{
			PARES ( X-2 );
			printf ( "\n%d\n", X );
		}
	else{
		PARES ( X-1 );
	}
	}
} // fim procedimento PARES ( )

void method_04 ( void )
{
	/// PROGRAMA RECURSIVO PARA MOSTRAR PARES
	printf ( "EXEMPLO603 - MOSTRAR OS PARES <= 10\n" );
	PARES ( 10 );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_01 ( )

/*Method_05*/
void PARES_05 ( int X )
{
	if ( X > 0 )
	{
		PARES_05 ( X-1 );
		printf ( "\n%d%c%d\n", X, " ", 2*X );
	}
} // fim procedimento PARES ( )

void method_05( void )
{
	// PROGRAMA RECURSIVO PARA MOSTRAR PARES
	printf ( "EXEMPLO604 - MOSTRAR OS 5 PRIMEIROS PARES\n" );
	PARES_05 ( 5 );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_05 ( )

/*Method_06*/
void PARES_06 ( int X, int* S )
{
	if( X > 0 )
	{ PARES_06 ( X-1, S ); *S = *S + 2*X; }
	else
		S = 0;
} // fim procedimento PARES ( )

void method_06 ( void )
{ 
	// PROGRAMA RECURSIVO PARA SOMAR PARES
	// DADO:
	int SOMA = 0;
	printf ( "EXEMPLO605 - SOMAR OS 5 PRIMEIROS PARES\n" );
	PARES_06 ( 5, &SOMA );
	printf ( "\nSOMA DOS 5 PRIMEIROS PARES = %d\n", SOMA );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar

} // end method_06 ( )

/*Method_07*/
int PARES_07 ( int X )
{
// DADO:
	int S = 0;
	if ( X > 0 )
		S = 2*X + PARES_07( X-1 );
	else
		S = 0;
	return ( S );
} // fim funcao PARES ( )

void method_07 ( void )
{
	// PROGRAMA RECURSIVO PARA SOMAR PARES
	// DADO :
	int SOMA = 0;
	printf ( "EXEMPLO606 - SOMAR OS 5 PRIMEIROS PARES\n" );
	SOMA = PARES_07 ( 5 );
	printf ( "\nSOMA DOS 5 PRIMEIROS PARES = %d\n", SOMA );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_07 ( )

/*Method_08*/
int PARES_08 ( int X )
{
// DADO :
	int S = 0;
	if ( X > 0 )
		if ( X % 2 == 0 )
			S = 1 + PARES_08 ( X-2 );
	else
		S = PARES_08 ( X-1 );
	else
		S = 0;
	return ( S );
} // fim funcao PARES ( )

void method_08 ( void )
{
	// PROGRAMA RECURSIVO PARA CONTAR PARES
	printf ( "EXEMPLO607 - CONTAR OS PARES <= 10\n" );
	printf ( "\nPARES <= 10 = %d\n", PARES_08( 10 ) );
	printf ( "\nFORNECER <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_08 ( )

/*Method_09*/
typedef char STRING30 [30];

bool PROCURAR( char LETRA, STRING30 S, int POSICAO )
{
	// DADO :
	bool R = false;
	if ( POSICAO <= strlen( S ) )
		R = ( S [ POSICAO ] == LETRA) || PROCURAR ( LETRA,S,POSICAO+1 );
	else
		R = false;
	return ( R );
} // fim funcao PROCURAR ( )

void method_09 ( void )
{
	// PROGRAMA RECURSIVO PARA ACHAR A POSICAO DE UMA LETRA
	// DADO :
	char L = '_';
	STRING30 S = "";
	printf ( "EXEMPLO608 - PROCURAR UMA LETRA EM UMA SENTENCA\n" );
	printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
	gets ( S );
	printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
	L = getchar ( );
	getchar( ); // limpar a entrada de dados
	printf ( "\nRESPOSTA = %d\n", PROCURAR( L,S,0 ) );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_09 ( )

/*Method_10*/
typedef char STRING30[30];
int PROCURAR_10( char LETRA, STRING30 S, int POSICAO )
{
// DADO :
	int R = 0;
	if ( POSICAO <= strlen(S) )
		if ( S [ POSICAO ] == LETRA )
			R = POSICAO + 1; // a primeira posicao e' 0 !
	else
		R = PROCURAR ( LETRA,S,POSICAO+1 );
	else
		R = 0;
	return ( R );
} // fim funcao PROCURAR ( )

void method_10 ( void )
{
	/// PROGRAMA RECURSIVO PARA PROCURAR UMA LETRA
	// DADO :
	char L = '_';
	STRING30 S = "";
	printf ( "EXEMPLO609 - POSICAO DE UMA LETRA EM UMA SENTENCA\n" );
	printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
	gets ( S );
	printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
	L = getchar ( );
	getchar( ); // limpar a entrada de dados
	printf ( "\nRESPOSTA = %d\n", PROCURAR_10 ( L,S,0 ) );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_10 ( )

/*Method_11*/
typedef char STRING30[30];

int PROCURAR_11( char LETRA, STRING30 S, int POSICAO )
{
// DADO :
	int R = 0;
	if ( POSICAO <= strlen(S) )
		if ( S [ POSICAO ] == LETRA )
			R = 1 + PROCURAR ( LETRA, S, POSICAO+1 );
	else
		R = PROCURAR ( LETRA,S,POSICAO+1 );
	else
		R = 0;
	return ( R );
} // fim funcao PROCURAR ( )

void method_11 ( void )
{
	// PROGRAMA RECURSIVO PARA PROCURAR OCORRENCIAS DE UMA LETRA
	// DADO :
	char L = '_';
	STRING30 S = "";
	printf ( "EXEMPLO610 - PROCURAR OCORRENCIAS DE UMA LETRA\n" );
	printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
	gets ( S );
	printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
	L = getchar ( );
	getchar( ); // limpar a entrada de dados
	printf ( "\nRESPOSTA = %d\n", PROCURAR_11( L,S,0 ) );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_11 ( )

/*Method_12*/
typedef int TABELA [10];

void method_12 ( void )
{
	// PROGRAMA PARA LER UMA TABELA DE INTEIROS
	// VARIAVEIS:
	TABELA V;
	int X = 0;
	printf ( "EXEMPLO701 - LER UM TABELA DE 10 INTEIROS\n" );
	// REPETIR PARA CADA POSICAO
	for ( X = 0; X < 10; X++ )
	{ // a primeira posicao e' zero !
		printf ( "\nFORNECER O %d o. INTEIRO : ",(X+1) );
		scanf ( "%d", &V[ X ] );
		getchar( ); // limpar a entrada de dados
	} // FIM REPETIR
	printf ( "\nVETOR LIDO: \n" );
	// REPETIR PARA CADA POSICAO
	for ( X = 0; X < 10; X++ )
	{
		printf ( "%d ", V[ X ] );
	} // FIM REPETIR
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_12 ( )

/*Method_13*/
typedef int TABELA[10];

void method_13 ( void )
{
	// PROGRAMA PARA SOMAR UMA TABELA DE INTEIROS
// VARIAVEIS :
	TABELA V;
	int X = 0,
	SOMA = 0;
	printf ( "EXEMPLO702 - SOMAR UM TABELA DE 10 INTEIROS\n" );
// REPETIR PARA CADA POSICAO
	for ( X = 0; X < 10; X++ )
	{
		printf ( "\nFORNECER O %do. INTEIRO : ",(X+1) );
		scanf ( "%d", &V[ X ] );
		getchar( ); // limpar a entrada de dados
	} // FIM REPETIR
	SOMA = 0;
// REPETIR PARA CADA POSICAO
	for ( X = 0; X < 10; X++ )
		SOMA = SOMA + V[ X ];
	printf ( "\nSOMA = %d",SOMA );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_13 ( )

/*Method_14*/
typedef int TABELA[10];

void method_14 ( void )
{
	// PROGRAMA PARA CALCULAR A MEDIA DE UMA TABELA DE INTEIROS
	// VARIAVEIS :
	TABELA V;
	float MEDIA = 0.0;
	int X = 0 ,
	SOMA = 0 ;
	printf ( "EXEMPLO703 - MEDIA DE UMA TABELA DE 10 INTEIROS\n" );
	// REPETIR PARA CADA POSICAO
	for ( X = 0; X < 10; X++ )
	{
		printf ( "\nFORNECER O %do. INTEIRO : ",(X+1) );
		scanf ( "%d", &V[ X ] );
		getchar( ); // limpar a entrada de dados
	} // FIM REPETIR
	SOMA = 0;
	// REPETIR PARA CADA POSICAO
	for ( X = 0; X < 10; X++ )
		SOMA = SOMA + V[ X ];
	MEDIA = SOMA / 10.0;
	printf ( "\nMEDIA = %f\n", MEDIA );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_14 ( ) 

/*Method_15*/
typedef char STRING10[10];

void method_15 ( void )
{
	// PROGRAMA PARA LER UMA PALAVRA
	// VARIAVEIS :
	STRING10 PALAVRA;
	int X = 0;
	printf ( "EXEMPLO704 - LER UMA PALAVRA\n" );
	printf ( "\nFORNECER UMA PALAVRA (NO MAXIMO 09 LETRAS) : " );
	gets ( PALAVRA );
	printf ( "\nLETRAS DA PALAVRA LIDA : " );
	// REPETIR PARA CADA POSICAO
	for ( X = 0; X < strlen( PALAVRA ); X++ )
		printf ( "%c ", PALAVRA[ X ] );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_15 ( )

/*Method_16*/
typedef char STRING10[10];

void method_16 ( void )
{
	// PROGRAMA PARA PROCURAR LETRA EM PALAVRA
// VARIAVEIS :
	STRING10 PALAVRA;
	char LETRA = '_';
	int X = 0 ;
	bool ACHAR = false;
	printf ( "EXEMPLO705 - PROCURAR LETRA EM UMA PALAVRA\n" );
	printf ( "\nDIGITAR UMA PALAVRA (NO MAXIMO 09 LETRAS) : " );
	gets ( PALAVRA );
	printf ( "\nFORNECER A LETRA A SER PROCURADA : " );
	LETRA = getchar ( );
	getchar( ); // limpar a entrada de dados
	ACHAR = false;
	X = 0;
// REPETIR PARA CADA POSICAO
	while ( X < strlen( PALAVRA ) && ! ACHAR )
	{
		if( PALAVRA[ X ] == LETRA )
			ACHAR = true;
		else
			X = X + 1;
	} // FIM REPETIR
	if( ACHAR )
		printf ( "LETRA ENCONTRADA" );
	else
		printf ( "LETRA NAO ENCONTRADA" );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_16 ( )

/*Method_17*/
typedef float POLINOMIO[10+1]; // posicoes de 0:10

void method_17 ( void )
{
	// PROGRAMA PARA AVALIAR UM POLINOMIO
// VARIAVEIS :
	POLINOMIO P;
	int Y = 0 , N = 0 ;
	float X = 0.0, PX = 0.0;
	printf ( "EXEMPLO706 - LER COEFICIENTES DE UM POLINOMIO\n" );
	printf ( "\nFORNECER O GRAU DO POLINOMIO : " );
	scanf ( "%d", &N );
	getchar( ); // limpar a entrada de dados
// REPETIR PARA CADA POSICAO
	for ( Y = 0; Y <= N; Y++ )
	{
		printf ( "\nFORNECER O %do. COEFICIENTE : ", (Y+1) );
		scanf ( "%f", &P[ Y ] );
		getchar( ); // limpar a entrada de dados
	} // FIM REPETIR
	printf ( "\nFORNECER O PONTO DE AVALIACAO : " );
	scanf ( "%f", &X );
	getchar( ); // limpar a entrada de dados
	PX = 0.0;
// REPETIR PARA CADA POSICAO
// DA ULTIMA ATE' A PRIMEIRA
	for ( Y = N; Y >= 0; Y-- )
		PX = PX * X + P[ Y ];
	printf ( "\nP%d = %f", X, PX );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_17 ( )

/*Method_18*/
typedef int VETOR[3]; // X,Y,Z

void method_18 ( void )
{
	// PROGRAMA PARA AVALIAR O COMPRIMENTO DE UM VETOR
// VARIAVEIS :
	VETOR V;
	int X = 0 ;
	float SOMA = 0.0;
	printf ( "EXEMPLO707 - COMPRIMENTO DE UM VETOR\n" );
	printf ( "\nFORNECER O VALOR DE X : " );
	scanf ( "%d", &V[0] );
	getchar( ); // limpar a entrada de dados
	printf ( "\nFORNECER O VALOR DE Y : " );
	scanf ( "%d", &V[1] );
	getchar( ); // limpar a entrada de dados
	printf ( "\nFORNECER O VALOR DE Z : " );
	scanf ( "%d", &V[2] );
	getchar( ); // limpar a entrada de dados
	SOMA = 0.0;
// REPETIR PARA CADA POSICAO
	for( X = 0; X < 3; X++ )
		SOMA = SOMA + V[ X ]*V[ X ];
	printf ( "\nCOMPRIMENTO = %f", sqrt( SOMA ) );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_18 ( )

/*Method_19*/
typedef int MATRIZ[2][2];

void method_19 ( void )
{
// PROGRAMA PARA LER UMA MATRIZ
// VARIAVEIS :
	MATRIZ M;
	int X = 0, Y = 0;
	printf ( "EXEMPLO708 - LER UMA MATRIZ INTEIRA 2x2\n" );
// REPETIR PARA CADA LINHA
	for ( X = 0; X < 2; X++ )
	{ // REPETIR PARA CADA COLUNA
		for ( Y = 0; Y < 2; Y++ )
		{
			printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
			scanf ( "%d", &M[ X ][ Y ] );
			getchar( ); // limpar a entrada de dados
		} // FIM REPETIR
	} // FIM REPETIR
	printf ( "\n" );
// REPETIR PARA CADA LINHA
	for ( X = 0; X < 2; X++ )
	{ // REPETIR PARA CADA COLUNA
		for ( Y = 0; Y < 2; Y++ )
			printf ( "%d ", M[ X ][ Y ] );
		printf ( "\n" );
	} // FIM REPETIR
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
} // end method_19 ( )

/*
Method_20
*/
typedef int MATRIZ[2][2];

void method_20(){
	// PROGRAMA PARA MONTAR A TRANSPOSTA DE UMA MATRIZ
// VARIAVEIS :
	MATRIZ M; // MATRIZ ORIGINAL
	MATRIZ MT; // MATRIZ TRANSPOSTA
	int X = 0, Y = 0;
	printf ( "EXEMPLO709 - TRANSPOR UMA MATRIZ INTEIRA 2x2\n" );
// REPETIR PARA CADA LINHA
	for ( X = 0; X < 2; X++ )
	{ // REPETIR PARA CADA COLUNA
		for ( Y = 0; Y < 2; Y++ )
		{
			printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
			scanf ( "%d", &M[ X ][ Y ] );
			getchar( ); // limpar a entrada de dados
			MT[ Y ][ X ] = M[ X ][ Y ];
		} // FIM REPETIR
	} // FIM REPETIR
	printf ( "\n" );
// REPETIR PARA CADA LINHA
	for ( X = 0; X < 2; X++ )
	{ // REPETIR PARA CADA COLUNA
		for ( Y = 0; Y < 2; Y++ )
			printf ( "%d ", M[ X ][ Y ] );
		printf ( "\n" );
	} // FIM REPETIR
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_20

/*
Method_21
*/
#define ORDEM 3

typedef int Matriz [ ORDEM ][ ORDEM ];

void method_21(){
	// PROGRAMA PARA MOSTRAR A DIAGONAL DE UMA MATRIZ
// VARIAVEIS :
	Matriz M;
	int X = 0, Y = 0;
	printf ( "EXEMPLO710 - MOSTRAR A DIAGONAL DE UMA MATRIZ\n" );
// REPETIR PARA CADA LINHA
	for ( X = 0; X < ORDEM; X++ )
	{ // REPETIR PARA CADA COLUNA
		for ( Y = 0; Y < ORDEM; Y++ )
		{
			printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
			scanf ( "%d", &M[ X ][ Y ] );
			getchar( ); // limpar a entrada de dados
		} // FIM REPETIR
	} // FIM REPETIR
	printf ( "\n" );
// REPETIR PARA CADA LINHA
	for ( X = 0; X < ORDEM; X++ )
	{ // REPETIR PARA CADA COLUNA
		for ( Y = 0; Y < ORDEM; Y++ )
		{
			if ( X == Y ) // SE ESTIVER NA DIAGONAL
				printf ( "%d ", M[ X ][ Y ] );
		} // FIM REPETIR
	} // FIM REPETIR
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_21

/*
Method_22
*/
typedef
struct SPONTOS
{
	double X,Y,Z;
}
PONTOS;

void method_22(){
// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
	PONTOS P1, P2, P3;
	double D = 0.0;
	printf ( "EXEMPLO801 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO :  " );
	scanf ( "\n%lf %lf %lf", &P1.X, &P1.Y, &P1.Z );
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P2.X, &P2.Y, &P2.Z );
	getchar( ); // limpar a entrada de dados
	P3.X = P2.X - P1.X;
	P3.Y = P2.Y - P1.Y;
	P3.Z = P2.Z - P1.Z;
	D = sqrt ( pow(P3.X, 2.0) +
		pow(P3.Y, 2.0) +
		pow(P3.Z, 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_22

/*
Method_23
*/
typedef struct Spontos { double X,Y,Z; } Pontos;

void method_23(){
	// PROGRAM PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
	Pontos P1, P2;
	double D = 0.0;
	printf ("EXEMPLO802 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P1.X, &P1.Y, &P1.Z );
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P2.X, &P2.Y, &P2.Z );
	getchar( ); // limpar a entrada de dados
	D = sqrt ( pow(P2.X-P1.X, 2.0) +
		pow(P2.Y-P1.Y, 2.0) +
		pow(P2.Z-P1.Z, 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_23

/*
Method_24
*/
typedef struct SPONTOSS { double X,Y,Z; } PONTOSS;
typedef PONTOSS Vetor[2];

void method_24(){
	// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
	// DADOS:
	Vetor V;
	double D = 0.0;
	printf ( "EXEMPLO803 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
	scanf ( "%lf %lf %lf", &V[0].X, &V[0].Y, &V[0].Z );
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf %lf %lf", &V[1].X, &V[1].Y, &V[1].Z );
	getchar( ); // limpar a entrada de dados
	D = sqrt ( pow(V[1].X-V[0].X, 2.0) +
		pow(V[1].Y-V[0].Y, 2.0) +
		pow(V[1].Z-V[0].Z, 2.0) );
	printf ("\n DISTANCIA = %lf", D );
	printf ("\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}// end method_24

/*
Method_25
*/
typedef double PONTOS_25[3]; // X, Y, Z
typedef
struct SVETOR
{ PONTOS_25 P1, P2; }
VETOR_25;

void method_25(){
	VETOR_25 V;
	double D = 0.0;
	printf ( "EXEMPLO804 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
	scanf ( "%lf %lf %lf", &V.P1[0], &V.P1[1], &V.P1[2] );
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf %lf %lf", &V.P2[0], &V.P2[1], &V.P2[2] );
	getchar( ); // limpar a entrada de dados
	D = sqrt ( pow(V.P2[0]-V.P1[0], 2.0)+
		pow(V.P2[1]-V.P1[1], 2.0)+
		pow(V.P2[2]-V.P1[2], 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_25

/*
Method_26
*/
typedef struct SPONTO_26 { double X,Y,Z; } PONTO_26 ;
typedef struct SPONTOS_26 { PONTO_26 P1,P2; } PONTOS_26;

void method_26(){
	// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
	PONTOS_26 P;
	double D = 0.0;
	printf ( "EXEMPLO805 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P.P1.X, &P.P1.Y, &P.P1.Z );
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P.P2.X, &P.P2.Y, &P.P2.Z );
	getchar( ); // limpar a entrada de dados
	D = sqrt ( pow(P.P2.X-P.P1.X, 2.0) +
		pow(P.P2.Y-P.P1.Y, 2.0) +
		pow(P.P2.Z-P.P1.Z, 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter>");
}//end method_26

/*
Method_27
*/
typedef struct SPONTO_27 { double X,Y,Z; } PONTO_27 ;
typedef double VETOR_27[3];// X, Y, Z
typedef
struct SPONTOS_27
{ PONTO_27 P1; VETOR_27 P2; }
PONTOS_27;

void method_27(){
	// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
	PONTOS_27 P;
	double D = 0.0;
	printf ( "EXEMPLO806 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P.P1.X, &P.P1.Y, &P.P1.Z );
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P.P2[0], &P.P2[1], &P.P2[2] );
	getchar( ); // limpar a entrada de dados
	D = sqrt ( pow(P.P2[0]-P.P1.X, 2.0) +
		pow(P.P2[1]-P.P1.Y, 2.0) +
		pow(P.P2[2]-P.P1.Z, 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}// end method_27

/*
Method_28
*/
typedef double VETOR_28 [3]; // X, Y, Z
typedef VETOR_28 PONTOS_28[2];

void method_28(){
	// PROGRAMA PARA CALCULAR
	// A DISTANCIA ENTRE PONTOS
	// DADOS:
	PONTOS_28 P;
	double D = 0.0;
	printf ( "EXEMPLO807 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P[0][0], &P[0][1], &P[0][2] );
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P[1][0], &P[1][1], &P[1][2] );
	getchar( ); // limpar a entrada de dados
	D = sqrt ( pow(P[1][0]-P[0][0], 2.0) +
		pow(P[1][1]-P[0][1], 2.0) +
		pow(P[1][2]-P[0][2], 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_28

/*
Method_29
*/
typedef double VETOR1[3];// X, Y, Z
typedef VETOR1 VETOR_29 [2];

void method_29(){
// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
	VETOR_29 P;
	double D = 0.0;
	printf ( "EXEMPLO808 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P[0][0], &P[0][1], &P[0][2] );
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf %lf %lf", &P[1][0], &P[1][1], &P[1][2] );
	getchar( ); // limpar a entrada de dados
	D = sqrt( pow(P[1][0]-P[0][0], 2.0) +
		pow(P[1][1]-P[0][1], 2.0) +
		pow(P[1][2]-P[0][2], 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_29

/*
Method_30
*/
typedef struct SPONTO_30 { double X,Y,Z; } PONTO_30 ;
typedef PONTO_30 VETOR_30[2];// X, Y, Z

void method_30(){
	// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
	VETOR_30 P;
	double D = 0.0;
	printf ( "EXEMPLO809 - DISTANCIA ENTRE PONTOS\n" );
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
	scanf ( "%lf%lf%lf", &(P[0].X), &(P[0].Y), &(P[0].Z));
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
	scanf ( "%lf%lf%lf", &(P[1].X), &(P[1].Y), &(P[1].Z));
	getchar( ); // limpar a entrada de dados
	D = sqrt ( pow(P[1].X-P[0].X, 2.0) +
		pow(P[1].Y-P[0].Y, 2.0) +
		pow(P[1].Z-P[0].Z, 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_30

/*
Method_31
*/
typedef struct SPONTO_31 { double X,Y,Z; } PONTO_31 ;
typedef struct SPONTOS_31 { PONTO_31 P1,P2; } PONTOS_31;
void method_31(){
	// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
	PONTOS_31 P;
	double D = 0.0;
	printf ( "EXEMPLO810 - DISTANCIA ENTRE PONTOS\n");
	printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n ");
	scanf ( "%lf%lf%lf", &(P.P1.X), &(P.P1.Y), &(P.P1.Z));
	getchar( ); // limpar a entrada de dados
	printf ( "\n ENTRE COM O SEGUNDO PONTO : \n ");
	scanf ( "%lf%lf%lf", &(P.P2.X), &(P.P2.Y), &(P.P2.Z));
	getchar( ); // limpar a entrada de dados
	D = sqrt ( pow(P.P2.X-P.P1.X, 2.0) +
		pow(P.P2.Y-P.P1.Y, 2.0) +
		pow(P.P2.Z-P.P1.Z, 2.0) );
	printf ( "\n DISTANCIA = %lf", D );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_31

/*
Method_32
*/
typedef struct SPONTOS_32 { float X,Y,Z; } PONTOS_32;

void method_32(){
	// PROGRAMA PARA GRAVAR COORDENADAS DE PONTOS
	// DADOS:
	PONTOS_32 P;
	int X = 0;
	FILE* A;
	printf ( "EXEMPLO901 - GRAVAR COORDENADAS DE PONTOS \n" );
	A = fopen ( "PONTOS1.TXT", "wt" );
	for ( X = 1; X <= 2; X++ )
	{
		printf ( "\nENTRE COM AS COORDENADAS DE UM PONTO : \n" );
		scanf ( "%f%f%f", &P.X, &P.Y, &P.Z );
		getchar( ); // limpar a entrada de dados
		fprintf( A, "%f %f %f\n", P.X, P.Y, P.Z );
	} // FIM REPETIR
	fclose ( A );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_32

/*
Method_33
*/
typedef struct SPONTOS_33 { float X,Y,Z; } PONTOS_33;

void method_33(){
	// PROGRAMA PARA LER ARQUIVO DE PONTOS
// VARIAVEIS :
	PONTOS_33 P;
	int X = 0;
	FILE* A;
	printf ( "EXEMPLO902 - LER ARQUIVO DE PONTOS \n" );
	A = fopen ( "PONTOS1.TXT", "rt" );
	for ( X = 1; X <= 2; X++ )
	{
		fscanf ( A, "%f%f%f", &P.X, &P.Y, &P.Z );
		printf ( "\nPONTO %d : %f %f %f", X, P.X, P.Y, P.Z );
	} // FIM REPETIR
	fclose ( A );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_34

/*
Method_34
*/
typedef struct SPONTOS_34 { float X,Y,Z; } PONTOS_34;

void method_34(){
	// PROGRAMA PARA GRAVAR COORDENADAS DE PONTOS
// DADOS:
	PONTOS_34 P;
	int X = 0;
	FILE* A;
	printf ( "EXEMPLO903 - GRAVAR COORDENADAS DE PONTOS \n" );
	A = fopen ( "PONTOS2.DAT", "wb" );
	for ( X = 1; X <= 2; X++ )
	{
		printf ( "\nENTRE COM AS COORDENADAS DE UM PONTO : \n" );
		scanf ( "%f%f%f", &P.X, &P.Y, &P.Z );
		getchar( ); // limpar a entrada de dados
		fwrite ( &P, sizeof(PONTOS), 1, A );
	} // FIM REPETIR
	fclose ( A );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_34

/*
Method_35
*/
typedef struct SPONTOS_35 { float X,Y,Z; } PONTOS_35;

void method_35(){
	// PROGRAMA PARA LER ARQUIVO DE PONTOS
// DADOS:
	PONTOS_35 P;
	int X = 0;
	FILE* A;
	printf ( "EXEMPLO904 - LER ARQUIVO DE PONTOS \n" );
	A = fopen ( "PONTOS2.DAT", "rb" );
	for( X = 1; X <= 2; X++ )
	{
		fread ( &P, sizeof(PONTOS_35), 1, A );
		printf ( "\nPONTO %d : %6.2f %6.2f %6.2f\n", X, P.X, P.Y, P.Z );
	} // FIM REPETIR
	fclose(A);
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_35

/*
Method_36
*/
typedef struct SPONTOS_36 { float X,Y,Z; } PONTOS_36;

void method_36(){
	// PROGRAMA PARA COPIAR O ARQUIVO COM COORDENADAS DE PONTOS
// DADOS:
	PONTOS_36 P;
	int X = 0;
	FILE *A1, *A2;
	printf ( "EXEMPLO905 - COPIAR COORDENADAS DE PONTOS \n" );
	A1 = fopen ( "PONTOS1.TXT", "rt" );
	A2 = fopen ( "NOVO1.DAT" , "wb" );
	for ( X = 1; X <= 2; X++ )
	{
		fscanf ( A1, "%f%f%f\n", &P.X, &P.Y, &P.Z );
		fwrite ( &P, sizeof(PONTOS_36), 1, A2 );
		printf ( "\nCOPIADO %d : %6.2f %6.2f %6.2f\n", X, P.X, P.Y, P.Z );
	} // FIM REPETIR
	fclose ( A1 );
	fclose ( A2 );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_36

/*
Method_37
*/
typedef struct SPONTOS_37 { float X,Y,Z; } PONTOS_37;

void method_37(){
	// PROGRAMA PARA ACRESCENTAR COORDENADAS DE PONTOS
// DADOS:
	PONTOS_37 P;
	int X = 0;
	FILE* A;
	printf ( "EXEMPLO906 - ACRESCENTAR COORDENADAS DE PONTOS \n" );
	A = fopen ( "PONTOS2.DAT", "r+b" );
	while( ! feof(A) )
		fread ( &P, sizeof(PONTOS_37), 1, A );// LER ATE' O FIM DE ARQUIVO
	fseek ( A, 0L, SEEK_CUR ); // MARCAR A POSICAO
	for ( X = 1; X <= 2; X++ )
	{
		printf ( "\nENTRE COM AS COORDENADAS DE OUTRO PONTO : \n" );
		scanf ( "%f%f%f", &P.X, &P.Y, &P.Z );
		getchar( ); // limpar a entrada de dados
		fwrite ( &P, sizeof(PONTOS_37), 1, A );
	} // FIM REPETIR
	fclose ( A );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}

/*
Method_38
*/
typedef struct SPONTOS_38 { float X,Y,Z; } PONTOS_38;

void method_38(){
	// PROGRAMA PARA ACRESCENTAR COORDENADAS DE PONTOS
// DADOS:
	PONTOS_38 P;
	int X = 0;
	FILE* A;
	printf ( "EXEMPLO907 - ACRESCENTAR COORDENADAS DE PONTOS \n" );
	A = fopen ( "PONTOS1.TXT", "at" );
	for( X = 1; X <= 2; X++ )
	{
		printf ( "\nENTRE COM AS COORDENADAS DE OUTRO PONTO : \n" );
		scanf ( "%f%f%f", &P.X, &P.Y, &P.Z );
		getchar( ); // limpar a entrada de dados
		fprintf ( A, "%f %f %f", P.X, P.Y, P.Z );
		fprintf ( A, "%s", "\n" );
	} // FIM REPETIR
	fclose ( A );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar

}//end method_38

/*
Method_39
*/
typedef struct SPONTOS_39 { float X,Y,Z; } PONTOS_39;

void method_39(){
	// PROGRAMA PARA PROCURAR COORDENADAS DE PONTOS
// DADOS:
	PONTOS_39 P,
	PROCURADO;
	bool ACHAR = false;
	FILE* A;
	printf ( "EXEMPLO908 - PROCURAR COORDENADAS DE PONTOS \n" );
	printf ( "\nENTRE COM AS COORDENADAS DO PONTO A PROCURAR : \n" );
	scanf ( "%f%f%f", &PROCURADO.X, &PROCURADO.Y, &PROCURADO.Z );
	getchar( ); // limpar a entrada de dados
	ACHAR = false;
	A = fopen ( "PONTOS1.TXT", "rt" );
	fscanf ( A, "%f %f %f", &P.X, &P.Y, &P.Z );
	while ( ! feof( A ) && ! ACHAR )
	{
		if ( P.X==PROCURADO.X && P.Y==PROCURADO.Y && P.Z==PROCURADO.Z )
			ACHAR = true;
		fscanf ( A, "%f%f%f", &P.X, &P.Y, &P.Z );
	} // FIM REPETIR
	fclose ( A );
	if ( ACHAR )
		printf ( "\nCOORDENADAS ENCONTRADAS" );
	else
		printf ( "\nCOORDENADAS NAO ENCONTRADAS" );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_39

/*
Method_40
*/
typedef struct SPONTOS_40 { float X,Y,Z; } PONTOS_40;

void method_40(){
// PROGRAMA PARA ALTERAR COORDENADAS DE PONTOS
// DADOS:
	PONTOS_40 P;
	int X = 0;
	FILE* A;
	printf ( "EXEMPLO909 - ALTERAR COORDENADAS DE PONTOS \n" );
	A = fopen( "PONTOS2.DAT", "r+b" );
	for ( X = 1; X <= 2; X++ )
	{
		fseek ( A, (X-1)*sizeof(PONTOS_40), SEEK_SET ); // o primeiro e' zero
		fread ( &P, sizeof(PONTOS_40), 1, A );
		printf ( "\nATUAL %d : %6.2f %6.2f %6.2f\n", X, P.X, P.Y, P.Z );
		printf ( "\nENTRE COM AS NOVAS COORDENADAS DO PONTO : \n" );
		scanf ( "%f%f%f", &P.X, &P.Y, &P.Z );
		fseek ( A, (X-1)*sizeof(PONTOS_40), SEEK_SET );
		fwrite ( &P, sizeof(PONTOS_40), 1, A );
	} // FIM REPETIR
	fclose(A);
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para espera
}//end method_40

/*
Method_41
*/
typedef struct SPONTOS_41 { float X,Y,Z; } PONTOS_41;

void method_41(void){
// PROGRAMA PARA LER ARQUIVO DE PONTOS DIRETAMENTE
// DADOS:
	PONTOS_41 P;
	int X = 0;
	FILE* A;
	printf ( "EXEMPLO910 - LER ARQUIVO DE PONTOS DIRETAMENTE \n" );
	A = fopen ( "PONTOS2.DAT", "r" );
	for ( X = 2; X > 0; X-- )
	{
		fseek ( A, (X-1) * sizeof (PONTOS_41), SEEK_SET ); // o primeiro e' zero
		fread ( &P, sizeof(PONTOS_41), 1, A );
		printf ( "\nPONTO %d : %6.2f %6.2f %6.2f\n", X, P.X, P.Y, P.Z );
	} // FIM REPETIR
	fclose( A );
	printf ( "\n\nPRESSIONAR <Enter> PARA TERMINAR" );
	getchar ( ); // para esperar
}//end method_41

int main ( int argc, char* argv [ ] )
{
	// definir dado
	int opcao = 0;
	// identificar
	printf ( "%s\n", "Metodos - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
	// acoes
	// repetir
	do
	{
		// para mostrar opcoes
		printf ( "\n%s\n", "Opcoes:" );
		printf ( "\n%s\n" , " 0 - Terminar      1 - Method_01     2 - Method_02 "  );
		printf ( "\n%s\n" , " 3 - Method_03     4 - Method_04     5 - Method_05" );
		printf ( "\n%s\n" , " 6 - Method_06     7 - Method_07     8 - Method_08" );
		printf ( "\n%s\n" , " 9 - Method_09    10 - Method_10    11 - Method_11" );
		printf ( "\n%s\n" , "12 - Method_12    13 - Method_13    14 - Method_14" );
		printf ( "\n%s\n" , "15 - Method_15    16 - Method_16    17 - Method_17" );
		printf ( "\n%s\n" , "18 - Method_18    19 - Method_19    20 - Method_20" );
		printf ( "\n%s\n" , "21 - Method_21    22 - Method_22    23 - Method_23" );
		printf ( "\n%s\n" , "24 - Method_24    25 - Method_25    26 - Method_26" );
		printf ( "\n%s\n" , "27 - Method_27    28 - Method_28    29 - Method_29" );
		printf ( "\n%s\n" , "30 - Method_30    31 - Method_31    32 - Method_32" );
		printf ( "\n%s\n" , "33 - Method_33    34 - Method_34    35 - Method_35" );
		printf ( "\n%s\n" , "36 - Method_36    37 - Method_37    38 - Method_38" );
		printf ( "\n%s\n" , "39 - Method_39    40 - Method_40    41 - Method_41" );
		printf ( "\n" );
		// ler a opcao do teclado
		printf ( "\n%s", "Opcao = " );
		scanf ( "%d", &opcao );
		getchar( ); // para limpar a entrada de dados
		// para mostrar a opcao lida
		printf ( "\n%s%d\n", "Opcao = ", opcao );
		// escolher acao dependente da opcao
		switch ( opcao )
		{
			case 0: // nao fazer nada
			break;
			case 1: // executar method_01
			method_01 ( );
			break;
			case 2: // executar method_02
			method_02 ( );
			break;
			case 3: // executar method_03
			method_03 ( );
			break;
			case 4: // executar method_04
			method_04 ( );
			break;
			case 5: // executar method_05
			method_05 ( );
			break;
			case 6: // executar method_06
			method_06 ( );
			break;
			case 7: // executar method_07
			method_07 ( );
			break;
			case 8: // executar method_08
			method_08 ( );
			break;
			case 9: // executar method_09
			method_09 ( );
			break;
			case 10: // executar method_10
			method_10 ( );
			break;
			case 11: // executar method_10
			method_11 ( );
			break;
			case 12: // executar method_10
			method_12 ( );
			break;
			case 13: // executar method_10
			method_13 ( );
			break;
			case 14: // executar method_10
			method_14 ( );
			break;
			case 15: // executar method_10
			method_15 ( );
			break;
			case 16: // executar method_10
			method_16 ( );
			break;
			case 17: // executar method_10
			method_17 ( );
			break;
			case 18: // executar method_10
			method_18 ( );
			break;
			case 19: // executar method_10
			method_19 ( );
			break;
			case 20: // executar method_20
			method_20();
			break;
			case 21: // executar method_21
			method_21();
			break;
			case 22: // executar method_22
			method_22();
			break;
			case 23: // executar method_23
			method_23();
			break;
			case 24: // executar method_24
			method_24();
			break;
			case 25: // executar method_25
			method_25();
			break;
			case 26: // executar method_26
			method_26();
			break;
			case 27: // executar method_27
			method_27();
			break;
			case 28: // executar method_28
			method_28();
			break;
			case 29: // executar method_29
			method_29();
			break;
			case 30: // executar method_30
			method_30();
			break;
			case 31: // executar method_31
			method_31();
			break;
			case 32: // executar method_32
			method_32();
			break;
			case 33: // executar method_33
			method_33();
			break;
			case 34: // executar method_34
			method_34();
			break;
			case 35: // executar method_35
			method_35();
			break;
			case 36: // executar method_36
			method_36();
			break;
			case 37: // executar method_37
			method_37();
			break;
			case 38: // executar method_38
			method_38();
			break;
			case 39: // executar method_39
			method_39();
			break;
			case 40: // executar method_40
			method_40();
			break;
			case 41: // executar method_41
			method_41();
			break;
			default: // comportamento padrao
			printf ( "\nERRO: Opcao invalida.\n" );
			break;
		} // end switch
	}
	while ( opcao != 0 );
// encerrar
	printf ( "\n\nApertar ENTER para terminar." );
	getchar( ); // aguardar por ENTER
	return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )


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
#include "my_string.h"// para definicoes globais, constantes ...

/**
  Method_01.
 */
void method_01 ( void )
{
	// identificar
	printf ( "%s\n", "Method_01 - EXEMPLO101" );
	// encerrar
	printf ( "\nApertar ENTER para continuar.\n" );
	getchar ( );
} // end method_01 ( )

void method_02 ( void )
{
	// identificar
	system ( "cls" ); // (Windows) para limpar a tela
	printf ( "%s\n", "Method_02 - EXEMPLO102" );
	system ( "pause" ); // (Windows) para esperar
} // end method_02 ( )

void clrscr ( ) { system ( "cls" ); } 

void method_03 ( void )
{
	// identificar
	clrscr ( ); // funcao para limpar a tela
	printf ( "%s\n", "Method_03 - EXEMPLO103" );
	printf ( "\n" ); // para mudar de linha
	printf ( "MATRICULA: ______ ALUNO : __________________" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_03 ( )

void method_04 ( void )
{
	// identificar
	printf ( "%s\n", "Method_04 - EXEMPLO104" );
	printf ( "\n" ); // para mudar de linha (="\n")
	printf ( "MATRICULA: ______ ALUNO : __________________" );
	printf ( "\n" ); // para mudar de linha
	printf ( "PRESSIONAR <Enter> PARA TERMINAR. " );
	getchar( ); // para esperar
} // end method_01 ( )

void method_05( void )
{
	// identificar
	printf ( "%s\n", "Method_05 - EXEMPLO105" );
	// dados
	printf ( "\nMATRICULA: ______ ALUNO : __________________" );
	printf ( "\nEXEMPLOS DE VALORES : " );
	printf ( "\nCARACTERE : %c", 'A' ); 
	printf ( "\nINTEIRO : %d", 10 );
	printf ( "\nREAL : %f", 3.1415 ); 
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR. " );
	getchar( ); // para esperar
} // end method_05 ( )

void method_06 ( void )
{ 
	#define PI 3.1415 // Define PI constant
	// identificar
	printf ( "%s\n", "Method_06 - EXEMPLO106" );
	printf ( "\nMATRICULA: ______ ALUNO : __________________" );
	// dados
	printf ( "\nEXEMPLOS DE VALORES : " );
	printf ( "\nCARACTERE : %c", 'A' );
	printf ( "\nINTEIRO : %d", 10 ); 
	printf ( "\nREAL : %f", PI ); 
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); 
} // end method_06 ( )

void method_07 ( void )
{
	const float PI_VALUE = 3.14; 
	// identificar
	printf ( "%s\n", "Method_07 - EXEMPLO107" );
	printf ( "\nMATRICULA: ______ ALUNO : __________________" );
	// dados
	printf ( "\nEXEMPLOS DE VALORES : " );
	printf ( "\nCARACTERE : %c", 'A' ); 
	printf ( "\nINTEIRO : %d", 10 );
	printf ( "\nREAL : %f" , PI_VALUE ); 
	// encerrar
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); 
} // end method_07 ( )


void method_08 ( void )
{
	// definicao de constante
	const float PI_VALUE = 3.14; // com nome e tipo (melhor)
	// definicao de variavel real
	float X = 10.01; // com atribuicao de valor inicial
	printf ( "%s\n", "Method_08 - EXEMPLO108" );
	printf ( "\nMATRICULA: ______ ALUNO : __________________" );
	printf ( "\nEXEMPLOS DE VALORES : " );
	printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
	printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
	printf ( "\nREAL : %f", PI_VALUE ); // constante real
	printf ( "\nREAL : %f", X ); // variavel real
	// encerrar
	printf ( "\nApertar ENTER para continuar.\n" );
	getchar ( );
} // end method_08 ( )

void method_09 ( void )
{
	// definicao de constante
	const float PI_VALUE = 3.14; // com nome e tipo (melhor)
    // definicao de variavel real
	float X = 10.01;
    // definicao de variavel inteira
	int I = 10;
	// identificar
	printf ( "%s\n", "Method_09 - EXEMPLO109" );
	printf ( "\nMATRICULA: ______ ALUNO : __________________" );
	printf ( "\nEXEMPLOS DE VALORES : " );
	printf ( "\nINTEIRO : %i" , I );
	printf ( "\nREAL : %f" , X );
	printf ( "\nREAL : %f" , PI_VALUE );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_09 ( )

void method_10 ( void )
{
	// definicao de constante
	const double PI_VALUE = 3.14; // com nome e tipo (melhor)
// definicao de variavel real
	float X = 10.01;
// definicao de variavel inteira
	int I = 10;
// definicao de variavel caractere
	char N = '\n'; // mudar de linha
	// identificar
	printf ( "%s\n", "Method_10 - EXEMPLO110" );
	printf ( "\nMATRICULA: ______ ALUNO : __________________" );
	printf ( "%c%s", N, "EXEMPLOS DE VALORES : " );
	printf ( "%c%s%i" , N, "INTEIRO : " , I );
	printf ( "%c%s%f" , N, "REAL : " , X );
	printf ( "%c%s%lf", N, "REAL : " , PI_VALUE );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_10 ( )

void method_11 ( void )
{
    // PROGRAMA PARA LER E IMPRIMIR UM VALOR INTEIRO
    // VARIAVEL:
	int X = 0;
	// identificar
	printf ( "%s\n", "Method_11 - EXEMPLO201 -  LER E IMPRIMIR UM VALOR INTEIRO" );
	printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
	scanf ( "%d", &X );
	getchar( ); // limpar a entrada de dados
	printf ( "\nO VALOR DIGITADO FOI: %d", X );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_11 ( )


void method_12 ( void )
{
	/// PROGRAMA PARA LER E IMPRIMIR UM VALOR REAL
	// VARIAVEL:
	double X = 0.0;
	// identificar
	printf ( "%s\n", "Method_12 - EXEMPLO202 - LER E IMPRIMIR UM VALOR REAL" );
	printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
	scanf ( "%lf", &X );
	getchar( ); // limpar a entrada de dados
	printf ( "\nO VALOR DIGITADO FOI: %lf", X );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_12 ( )

void method_13 ( void )
{
	// PROGRAMA PARA LER E IMPRIMIR UM CARACTERE
	// VARIAVEL:
	char X = '0';
	// identificar
	printf ( "%s\n", "Method_13 - EXEMPLO203 - LER E IMPRIMIR UM CARACTERE" );
	printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
	scanf ( "%c", &X );
	getchar( ); // limpar a entrada de dados
	printf ( "\nO VALOR DIGITADO FOI: %c", X );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_13 ( )

void method_14 ( void )
{
	// PROGRAMA PARA LER E IMPRIMIR, NO MAXIMO, 10 CARACTERES
	// VARIAVEL:
	char X [10];
	printf ( "%s\n", "Method_14 - EXEMPLO 204- LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES" );
	printf ( "\nDIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: " );
	scanf ( "%s", X ); // OBS.: NAO usar o (&) para caracteres !
	getchar( ); // limpar a entrada de dados
	printf ( "\nFOI DIGITADO: %s", X );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_14 ( ) 

void method_15 ( void )
{
    // PROGRAMA PARA LER E SOMAR DOIS VALORES INTEIROS
	// VARIAVEIS:
	int X=0, Y=0, Z=0;
	printf ( "%s\n", "Method_15 - EXEMPLO205 - LER E SOMAR DOIS VALORES INTEIROS" );
	printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
	scanf ( "%d", &X );
	getchar( ); // limpar a entrada de dados
	printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
	scanf ( "%d", &Y );
	getchar( ); // limpar a entrada de dados
	Z = X + Y;
	printf ( "\nA SOMA DOS DOIS = %d", Z );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_15 ( )

void method_16 ( void )
{
	// PROGRAMA PARA LER E SUBTRAIR DOIS VALORES REAIS
	// VARIAVEIS:
	float X=0.0, Y=0.0, Z=0.0;
	printf ( "%s\n", "Method_16 - EXEMPLO206 - LER E SUBTRAIR DOIS VALORES REAIS" );
	printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
	scanf ( "%f", &X );
	getchar( ); // limpar a entrada de dados
	printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
	scanf ( "%f", &Y );
	getchar( ); // limpar a entrada de dados
	Z = X - Y;
	printf ( "\nA DIFERENCA ENTRE OS DOIS = %f", Z );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
} // end method_16 ( )

void method_17 ( void )
{
	// PROGRAMA PARA OPERAR VALORES LOGICOS
	// VARIAVEIS:
	bool X=false, Y=false, Z=false;
	printf ("%s\n", "Method_17 - EXEMPLO207 - OPERAR VALORES LOGICOS" );
	X = true;
	Y = false;
	Z = X || Y; // X ou Y
	printf ( "\nA DISJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
	Z = X && Y; // X e Y
	printf ( "\nA CONJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
} // end method_17 ( )

void method_18 ( void )
{
	// PROGRAMA PARA CALCULAR A VELOCIDADE DE UM VEICULO
	// VARIAVEIS:
	double D = 0.0, // Distancia
	T = 0.0, // Tempo
	V = 0.0; // Velocidade
	printf ( "%s\n", "Method_18 - EXEMPLO208 - CALCULAR A VELOCIDADE DE UM VEICULO" );
	printf ( "\nFORNECER UMA DISTANCIA QUALQUER EM METROS: " );
	scanf ( "%lf", &D );
	getchar( ); // limpar a entrada de dados
	printf ( "\nFORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: " );
	scanf ( "%lf", &T );
	getchar( ); // limpar a entrada de dados
	V = D / T;
	printf ( "\nV = D / T = %lf%s", V, " m/s " );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_18 ( )

void method_19 ( void )
{
	// PROGRAMA PARA COMPARAR CARACTERES COM UMA SENHA
	// CONSTANTE:
	const char SENHA[5] = "XXXX";
	// VARIAVEL:
	char S [10];
	printf ( "%s\n", "Method_19 - EXEMPLO209 - COMPARAR CARACTERES COM UMA SENHA" );
	printf ( "\nFORNECER UMA CADEIA DE CARACTERES QUALQUER: " );
	scanf ( "%s", S ); // OBS.: NAO usar o (&) para caracteres !
	getchar( ); // limpar a entrada de dados
	printf ( "\nA COMPARACAO COM A SENHA = %d", (strcmp(S,SENHA)==0)?1:0 );
	// strcmp(S1,S2) compara S1 com S2
	// igual a 0: S1 = S2 => 1 ( verdadeiro )
	// diferente: S1 <> S2 => 0 ( falso )
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
} // end method_19 ( )

/*
Method_20
*/
void method_20(){
	// PROGRAMA PARA CALCULAR O ARCO TRIGONOMETRICO DE UM SENO
    // CONSTANTE:
	const double PI_VALUE = 3.14;
    // VARIAVEIS:
	double ARCO = 0.0,
	COSSENO = 0.0,
	SENO = 0.0,
	TANGENTE = 0.0;
	printf ( "Method_19 - EXEMPLO210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO" );
	printf ( "\nFORNECER O VALOR DO SENO: " );
	scanf ( "%lf", &SENO );
	getchar( ); // limpar a entrada de dados
	COSSENO = sqrt( 1.0 - pow(SENO,2) );
	TANGENTE = SENO / COSSENO;
	ARCO = atan( TANGENTE );
	printf ( "\nO ARCO TRIGONOMETRICO EM GRAUS = %lf", (ARCO*180.0/PI_VALUE) );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}//end method_20

/*
Method_21
*/
void method_21(){
	// PROGRAMA PARA LER UM VALOR INTEIRO E VERIFICAR SE E' ZERO
// VARIAVEL:
	int X = 0;
	printf ( "Method_21 - EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO" );
	printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
	scanf ( "%d", &X );
	getchar( ); // limpar a entrada de dados
	if ( X == 0 )
		printf ( "\nO VALOR DIGITADO FOI ZERO" );
	else
		printf ( "\nO VALOR DIGITADO NAO FOI ZERO" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}//end method_21

/*
Method_22
*/
void method_22(){
// PROGRAMA PARA LER UM REAL E TESTAR SE DIFERENTE DE ZERO
// VARIAVEL:
	float X = 0.0;
	printf ( "Method_22 - EXEMPLO302 - LER E TESTAR UM VALOR REAL" );
	printf ( "\nFORNECER UM VALOR REAL DIFERENTE DE ZERO: " );
	scanf ( "%f", &X );
	getchar( ); // limpar a entrada de dados
	if( X != 0.0 )
		printf ( "\nO VALOR DIGITADO FOI DIFERENTE DE ZERO" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}//end method_22

/*
Method_23
*/
void method_23(){
	// PROGRAMA PARA LER CARACTERE E VERIFICAR SE E' UM ALGARISMO
// VARIAVEL:
	char X = '0';
	printf ( "Method_23 - EXEMPLO303 - LER E TESTAR UM CARACTERE" );
	printf ( "\nFORNECER UM ALGARISMO QUALQUER: " );
	scanf ( "%c", &X );
	getchar( ); // limpar a entrada de dados
	if( X >= '0' && X <= '9' )
	{
		printf ( "\nO VALOR DIGITADO FOI UM ALGARISMO" );
		printf ( "\nO ALGARISMO DIGITADO FOI: %c", X );
	} // if ALGARISMO
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}//end method_23

/*
Method_24
*/
void method_24(){
	// PROGRAMA PARA LER CARACTERE E TESTAR SE NAO E' ALGARISMO
// VARIAVEL:
	char X = '0';
	printf ( "Method_24 - EXEMPLO304 - LER E TESTAR CARACTERE" );
	printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
	scanf ( "%c", &X );
	getchar( ); // limpar a entrada de dados
	if( !( X >= '0' && X <= '9') )
	{
		printf ( "\nNAO FOI DIGITADO UM ALGARISMO" );
		printf ( "\nFOI DIGITADO O CARACTERE: %c", X );
	} // if NAO ALGARISMO
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}// end method_24

/*
Method_25
*/
void method_25(){
	// PROGRAMA PARA LER E TESTAR A IGUALDADE DE DOIS INTEIROS
// VARIAVEIS:
	int X=0, Y=0;
	printf ( "Method_25 - EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS" );
	printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
	scanf ( "%d", &X );
	getchar( ); // limpar a entrada de dados
	printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
	scanf ( "%d", &Y );
	getchar( ); // limpar a entrada de dados
	if( X == Y )
		printf ( "\nDOIS VALORES IGUAIS" );
	else
	{
		printf ( "\n%d", X );
		printf ( " DIFERENTE DE " );
		printf ( "%d", Y );
	}
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}//end method_25

/*
Method_26
*/
void method_26(){
	// PROGRAMA PARA LER E TESTAR DOIS VALORES REAIS
    // VARIAVEIS:
	double X=0.0, Y=0.0;
	printf ("Method_26 - EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS" );
	printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
	scanf ( "%lf", &X );
	getchar( ); // limpar a entrada de dados
	printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
	scanf ( "%lf", &Y );
	getchar( ); // limpar a entrada de dados
	if( ! (X == Y) )
	{
		printf ( "\n%lf", X );
		printf ( " DIFERENTE DE " );
		printf ( "%lf", Y );
	}
	else
	{
		printf ( "VALORES IGUAIS" );
	} // if VALORES DIFERENTES
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}//end method_26

/*
Method_27
*/
void method_27(){
	// PROGRAMA PARA TRATAR ALTERNATIVAS COM VALORES LOGICOS
    // VARIAVEIS:
	int X=0, Y=0;
	bool Z=false;
	printf ("Method_27 - EXEMPLO307 - TRATAR VALORES LOGICOS" );
	printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
	scanf ( "%d", &X );
	getchar( ); // limpar a entrada de dados
	printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
	scanf ( "%d", &Y );
	getchar( ); // limpar a entrada de dados
	Z = (X == Y);
	if( Z )
		printf ( "VALORES IGUAIS" );
	else
		printf ( "VALORES DIFERENTES" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}// end method_27

/*
Method_28
*/
void method_28(){
	// PROGRAMA PARA LER E TESTAR UMA LETRA
	// VARIAVEL:
	char X = '0';
	printf ("Method_28 - EXEMPLO308 - LER E TESTAR UMA LETRA" );
	printf ( "\nFORNECER UMA LETRA QUALQUER: " );
	scanf ( "%c", &X );
	getchar( ); // limpar a entrada de dados
	if( X >= 'A' && X <= 'Z' )
		printf ( "FOI DIGITADA UMA LETRA MAIUSCULA" );
	else
		if( X >= 'a' && X <= 'z' )
			printf ( "FOI DIGITADA UMA LETRA MINUSCULA" );
	else
		printf ( "NAO FOI DIGITADA UMA LETRA" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
}//end method_28

/*
Method_29
*/
void method_29(){
	// PROGRAMA PARA COMPARAR CARACTERES < , = , >
	// VARIAVEL:
	char X = '0';
	printf ( "Method_29 - EXEMPLO309 - COMPARAR CARACTERES < , = , >" );
	printf ( "\nFORNECER UM DOS CARACTERES CITADOS: " );
	scanf ( "%c", &X );
	getchar( ); // limpar a entrada de dados
	switch( X )
	{
		case '>': printf ( "FOI DIGITADO O SINAL DE MAIOR" );
		break;
		case '=': printf ( "FOI DIGITADO O SINAL DE IGUAL" );
		break;
		case '<': printf ( "FOI DIGITADO O SINAL DE MENOR" );
		break;
		default : printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
	} // COMPARACAO DE X COM < , = , >
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_29

/*
Method_30
*/
void method_30(){
	// PROGRAMA PARA IDENTIFICAR CARACTERES
	// VARIAVEL
	char X = '0';
	printf ( "Method_30 - EXEMPLO310 - IDENTIFICAR CARACTERES" );
	printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
	scanf ( "%c", &X );
	getchar( ); // limpar a entrada de dados
	switch ( X )
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
		case 'U': printf ( "FOI DIGITADO UMA VOGAL" );
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
		case '9': printf ( "FOI DIGITADO UM ALGARISMO" );
		printf ( "\nO NUMERO CORRESPONDENTE = %d", (X-48) );
		break;
		default: printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
	} // IDENTIFICACAO DE UM CARACTERE
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_30

/*
Method_31
*/
void method_31(){
	// PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
	// VARIAVEIS :
	int X = 0,
	CONTADOR = 0;
	printf ( "Method_31 - EXEMPLO401 - LER E IMPRIMIR 03 VALORES INTEIROS" );
	printf ( "\n" ); // mudar de linha
	CONTADOR = 1;
	while ( CONTADOR <= 3 ) // REPETIR
	{
		printf ( "\n" ); // mudar de linha
		printf ( "%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
		scanf( "%d", &X );
		getchar( ); // limpar a entrada de dados
		printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
		CONTADOR = CONTADOR + 1;
	} // ENQUANTO ( CONTADOR <= 3 )
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_31

/*
Method_32
*/
void method_32(){
	// PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
	// VARIAVEIS :
	int X = 0, N = 0, CONTADOR = 0;
	printf ( "Method_32 - EXEMPLO402 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
	printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
	scanf ( "%d", &N );
	getchar( ); // limpar a entrada de dados
	CONTADOR = 1;
	while ( CONTADOR <= N )
	{
		printf ( "\n%d", CONTADOR );
		printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
		printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
		CONTADOR = CONTADOR + 1;
	} // ENQUANTO ( CONTADOR <= N )
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_32

/*
Method_33
*/
void method_33(){
	// PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
	// VARIAVEIS :
	int X = 0, N = 0;
	printf ( "Method_33 - EXEMPLO403 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
	printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
	scanf ( "%d", &N );
	getchar( ); // limpar a entrada de dados
	while ( N > 0 ) // REPETIR
	{
		printf ( "\n%d", N );
		printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
		printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
		N = N - 1;
	} // ENQUANTO N > 0
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_34

/*
Method_34
*/
void method_34(){
	// PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
	// VARIAVEIS :
	int X = 0,
	CONTADOR = 0;
	printf ("Method_34 - EXEMPLO404 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
	for ( CONTADOR = 1; CONTADOR <= 3; CONTADOR = CONTADOR+1)
	{
		printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
		printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
	} // PARA CONTADOR EM [1:3]
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_34

/*
Method_35
*/
void method_35(){
	// PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
	// VARIAVEIS :
	int X = 0,
	N = 0,
	CONTADOR = 0;
	printf ("Method_35 - EXEMPLO405 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
	printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
	scanf ( "%d", &N );
	getchar( ); // limpar a entrada de dados
	for ( CONTADOR = 1; CONTADOR <= N; CONTADOR++ )
	{
		printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
		printf ( "\nO VALOR DIGITADO FOI : %d", X );
	} // PARA CONTADOR EM [1:N]
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_35

/*
Method_36
*/
// PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
// VARIAVEIS :
void method_36(){
	int X = 0,
	CONTADOR = 0;
	printf ( "Method_36 - EXEMPLO406 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
	CONTADOR = 1;
	do // REPETIR
	{
		printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
		printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
		CONTADOR = CONTADOR + 1;
	}
	while ( CONTADOR <= 3 ); // ATE' ( CONTADOR > 3 )
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_36

/*
Method_37
*/
void method_37(){
	// PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
	// VARIAVEIS :
	int X = 0,
	CONTADOR = 0;
	printf ( "Method_37 - EXEMPLO407 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
	printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
	scanf ( "%d", &CONTADOR );
	getchar( ); // limpar a entrada de dados
	do // REPETIR
	{
		printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
		printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
		CONTADOR = CONTADOR - 1;
	}
	while ( CONTADOR > 0 ); // ATE' ( CONTADOR <= 3 )
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}

/*
Method_38
*/
void method_38(){
	// PROGRAMA PARA LER E IMPRIMIR INTEIROS DIFERENTES DE ZERO
	// VARIAVEL :
	int X = 0;
	printf ( "EXEMPLO408 - LER E IMPRIMIR INTEIROS NAO NULOS\n" );
	printf ( "\nFORNECER UM VALOR INTEIRO (0 = PARAR) : " );
	scanf ( "%d", &X );
	getchar( ); // limpar a entrada de dados
	while ( X != 0 ) // REPETIR
	{
		printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
		printf ( "\nDIGITE UM VALOR INTEIRO QUALQUER : " );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
	} // ENQUANTO X DIFERENTE DE ZERO
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_38

/*
Method_39
*/
void method_39(){
	// PROGRAMA PARA LER UM INTEIRO DIFERENTE DE ZERO
	// VARIAVEL :
	int X = 0;
	printf ( "Method_39 - EXEMPLO409 - PARA LER UM INTEIRO NAO NULO\n" );
	printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
	scanf ( "%d", &X );
	getchar( ); // limpar a entrada de dados
	while ( X == 0 ) // REPETIR
	{
		printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
	} // ENQUANTO X IGUAL A ZERO
	printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_39

/*
Method_40
*/
void method_40(){
	// PROGRAMA PARA LER UM INTEIRO DIFERENTE DE ZERO
	// VARIAVEL :
	int X = 0;
	printf ( "EXEMPLO410 - LER UM INTEIRO NAO NULO\n" );
	do // REPETIR
	{
		printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
		scanf ( "%d", &X );
		getchar( ); // limpar a entrada de dados
	}
	while ( X == 0 ); // ATE' X DIFERENTE DE ZERO
	printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_40

/*
Method_41
*/
void P1_method41 ( void )
{
	printf ( "\n" );
	printf ( "\nCHAMADO O PROCEDIMENTO P1 SEM PARAMETROS" );
	printf ( "\n" );
} // fim procedimento P1( )

void method_41(void){
	// PROGRAMA PARA CHAMADA DE PROCEDIMENTO SEM PARAMETROS
	printf ( "Method_41 - EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO" );
	P1_method41 ( ); // chamada ao procedimento
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_41

/*
Method_42
*/
int X = 0;
void P1_method42 ( void )
{
	printf ( "\n" );
	printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
	printf ( "\n" );
} // fim procedimento P1( )
void method_42(void){
	// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
	printf ( "EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL\n" );
	for ( X = 1; X <= 5; X = X + 1 )
		P1_method42 ( ); // chamar 5 vezes
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_42

/*
Method_43
*/
void P1_method43 ( void )
{
	X = X + 1; // AVANCAR O CONTEXTO
	printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)", X );
	printf ( "\n" );
	if ( X < 5 )
		P1_method43 ( ); // CHAMAR O PROCEDIMENTO RECURSIVAMENTE
	printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
	X = X - 1; // RETORNAR AO CONTEXTO ANTERIOR
	getchar ( ); // para esperar
} // fim procedimento P1( )

void method_43(void){
	// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
	printf ( "Method_43 - EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL\n" );
	P1_method43 ( ); // OBSERVAR A RECURSIVIDADE !
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_43
/*

Method_44
*/
void P1_method44 ( int X )
{
	printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
	if ( X < 5 )
		P1_method44( X + 1 ); // chamar recursivamente com parametro
	printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
	getchar ( ); // para esperar
} // fim procedimento P1( )

void method_44(void){
	// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
	printf ( "Method_44 - EXEMPLO0904 - CHAMADA/RETORNO COM PARAMETRO\n" );
	P1_method44 ( 1 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_44

/*
Method_45
*/
void P1_method45 ( int X )
{
	printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", X );
	if ( X > 1 )
		P1_method45 ( X - 1 );
	printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", X );
	getchar ( ); // para esperar
} // fim procedimento P1( )

void method_45(void){
	// PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR VALOR
	printf ( "EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO\n" );
	P1_method45 ( 5 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_45

/*
Method_46
*/
void P2 (int X); // PROTOTIPO DE PROCEDIMENTO
void P1 (int X)
{
	printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
	if ( X < 5 )
		P2 ( X );
	printf ( "RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
	getchar ( ); // para esperar
} // fim do procedimento P1( )
void P2 (int X)
{
	printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
	X = X+1;
	printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d\n", X );
	getchar ( ); // para esperar
	P1 ( X );
} // fim do procedimento P2( )

void method_46(void){
	// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
	printf ( "Method_46 - EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO\n\n" );
	P1 ( 1 ); // OBSERVAR RECURSIVIDADE INDIRETA !
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_46

/*
Method_47
*/
void P1_method47 ( int* X )
{
	*X = *X + 1; // AVANCAR O CONTEXTO NA REFERENCIA
	printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", *X );
	if ( *X < 5 )
		P1_method47 ( X );
	printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", *X );
	*X = *X - 1; // RETORNAR AO CONTEXTO DA REFERENCIA ANTERIOR
	getchar ( ); // para esperar
} // fim procedimento P1( )
void method_47(void){
	// PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR REFERENCIA
	// VARIAVEL LOCAL
	int X;
	printf ( "Method_47 - EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA\n" );
	X = 0;
	P1_method47 ( &X ); // OBSERVAR REPETICAO FINITA !
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_47

/*
Method_48
*/
void P2_method48 ( int X ); // PROTOTIPO DE PROCEDIMENTO
void P1_method48 ( int X )
{
	X = X + 1;
	printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
	if ( X < 4 )
	{
		P1_method48 ( X );
		P2_method48 ( X );
	}
	printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
	getchar ( ) ; // para esperar
} // fim do procedimento P1( )
void P2_method48 ( int X )
{
	printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
	if ( X > 1 )
		P2_method48 ( X - 1 );
	printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d", X );
	getchar ( ); // para esperar
} // fim procedimento P2( )

void method_48(void){
	// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
	printf ( "Method_48 - EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS\n\n" );
	P1 ( 1 );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
}//end method_48

/*
Method_49
*/
void method_49(void){
	// PROGRAMA PARA MOSTRAR O USO DE MODULOS
	println ( "Method_49 - EXEMPLO0509 - USO DE MODULOS" );
	pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
}//end method_49

/*
Method_50
*/
void method_50(void){
	// PROGRAMA PARA MOSTRAR O USO DE MODULOS
	// VARIAVEIS :
	chars text = "MUDAR DE LINHA";
	println ( "Method_50 - EXEMPLO0509 - USO DE MODULOS" );
	printf ( "%c", EOL );
	printf ( "%s%c", text, EOL );
	pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
}//end method_50

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
		printf ( "\n%s\n" , "42 - Method_42    43 - Method_43    44 - Method_44" );
		printf ( "\n%s\n" , "45 - Method_45    46 - Method_46    47 - Method_47" );
		printf ( "\n%s\n" , "48 - Method_48    49 - Method_49    50 - Method_50" );
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
			case 42: // executar method_43
			method_42();
			break;
			case 43: // executar method_43
			method_43();
			break;
			case 44: // executar method_44
			method_44();
			break;
			case 45: // executar method_45
			method_45();
			break;
			case 46: // executar method_46
			method_46();
			break;
			case 47: // executar method_47
			method_47();
			break;
			case 48: // executar method_48
			method_48();
			break;
			case 49: // executar method_49
			method_49();
			break;
			case 50: // executar method_50
			method_50();
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



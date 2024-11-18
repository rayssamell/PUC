/*
Exemplo0405 - v0.0. - 21/03/2024
Author: Rayssa Mell de Souza Silva
*/

#include <stdio.h>
#include "io.h"

/**
  Method_01 - Repeticao para ler certa quantidade de valores.
 */
void method_01 ( )
{
// definir dado
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
// identificar
	IO_id ( "\nMethod 01 - v0.0\n" );
// ler do teclado
	quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
	controle = 1;
	while ( controle <= quantidade )
	{
		// ler valor do teclado
		valor = IO_readint ( IO_concat (
			IO_concat ( "", IO_toString_d ( controle ) ),
			": " ) );
		// passar ao proximo valor
		controle = controle + 1;
	} // end while
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Funcao para determinar se valor inteiro e' positivo.
  @return true, se positivo; false, caso contrario
  @param x - valor a ser testado
 */
bool positive ( int x )
{
// definir dado local
	bool result = false;
// testar a condicao
	if ( x > 0 )
	{
		result = true;
	} // end if
	return ( result );
} // end positive ( )
/**
  Method_02 - Ler valores e contar positivos.
 */
void method_02 ( )
{
// definir dado
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	int contador = 0;
// identificar
	IO_id ( "\nMethod02 - v0.0\n" );
// ler do teclado
	quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
	controle = 1;
	while ( controle <= quantidade )
	{
		// ler valor do teclado
		valor = IO_readint ( IO_concat (
			IO_concat ( "", IO_toString_d ( controle ) ),
			": " ) );
		// testar e contar se valor for positivo
		if ( positive ( valor ) )
		{
			contador = contador + 1;
		} // end if
		// passar ao proximo valor
		controle = controle + 1;
	} // end while
// mostrar a quantidade de valores positivos
	IO_printf ( "%s%d\n", "Positivos = ", contador );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Funcao para determinar se valor inteiro pertence a intervalo aberto.
  @return true, se pertencer; false, caso contrario
  @param x - valor a ser testado
  @param inferior - limite inferior do intervalo
  @param superior - limite superior do intervalo
 */
bool belongsTo ( int x, int inferior, int superior )
{
// definir dado local
	bool result = false;
// testar a condicao
	if ( inferior < x && x < superior )
	{
		result = true;
	} // end if
	return ( result );
} // end belongsTo ( )
/**
  Method_03 - Ler valores e contar positivos menores que 100.
 */
void method_03 ( )
{
// definir dado
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	int contador = 0;
// identificar
	IO_id ( "\nMethod_03 - v0.0\n" );
// ler do teclado
	quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
	controle = 1;
	while ( controle <= quantidade )
	{
		// ler valor do teclado
		valor = IO_readint ( IO_concat (
			IO_concat ( "", IO_toString_d ( controle ) ),
			": " ) );
		// testar e contar se valor for positivo
		if ( belongsTo ( valor, 0, 100 ) )
		{
			contador = contador + 1;
		} // end if
		// passar ao proximo valor
		controle = controle + 1;
	} // end while
// mostrar a quantidade de valores positivos
	IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Funcao para determinar se valor inteiro e' par.
  @return true, se par; false, caso contrario
  @param x - valor a ser testado
 */
bool even ( int x )
{
// definir dado local
	bool result = false;
// testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero )
	if ( x % 2 == 0 )
	{
		result = true;
	} // end if
	return ( result );
} // end even ( )
/**
  Method_04 - Ler valores e contar positivos menores que 100 e pares.
 */
void method_04 ( )
{
// definir dado
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	int contador = 0;
// identificar
	IO_id ( "Method_04 - v0.0" );
// ler do teclado
	quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
	controle = 1;
	while ( controle <= quantidade )
	{
		// ler valor do teclado
		valor = IO_readint ( IO_concat (
			IO_concat ( "", IO_toString_d ( controle ) ),
			": " ) );
		// testar e contar se valor for positivo menor que 100 e par
		if ( belongsTo ( valor, 0, 100 ) && even ( valor ) )
		{
			contador = contador + 1;
		} // end if
		// passar ao proximo valor
		controle = controle + 1;
	} // end while
// mostrar a quantidade de valores positivos
	IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
 */
void method_05 ( )
{
// definir dado
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	int contador = 0;
	bool ok = false;
// identificar
	IO_id ( "\nEXEMPLO0405 - Method05 - v0.0\n" );
// ler do teclado
	quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
	controle = 1;
	while ( controle <= quantidade )
	{
		// ler valor do teclado
		valor = IO_readint ( IO_concat (
			IO_concat ( "", IO_toString_d ( controle ) ),
			": " ) );
		// testar e contar se valor for positivo menor que 100 e par
		ok = belongsTo ( valor, 0, 100 );
		ok = ok && even ( valor );
		if ( ok )
		{
			contador = contador + 1;
		} // end if
		// passar ao proximo valor
		controle = controle + 1;
	} // end while
// mostrar a quantidade de valores positivos
	IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Funcao para determinar se caractere e' letra minuscula.
  @return true, se par; false, caso contrario
  @param x - valor a ser testado
 */
bool isLowerCase ( char x )
{
// definir dado local
	bool result = false;
// testar a condicao
	if ( 'a' <= x && x <= 'z' )
	{
		result = true;
	} // end if
	return ( result );
} // end isLowerCase ( )
/**
  Method_06 - Ler palavra e contar letras minusculas.
 */
void method_06 ( )
{
// definir dado
	chars palavra = IO_new_chars ( STR_SIZE );
	int tamanho = 0;
	int posicao = 0;
	char simbolo = '_';
	int contador = 0;
// identificar
	IO_id ( "\nMethod06 - v0.0\n" );
// ler do teclado
	palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
	tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
	for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
	{
		// isolar um simbolo por vez
		simbolo = palavra [ posicao ];
		// testar e contar se caractere e' letra minuscula
		if ( isLowerCase ( simbolo ) )
		{
			contador = contador + 1;
		} // end if
	} // end for
// mostrar a quantidade de minusculas
	IO_printf ( "%s%d\n", "Minusculas = ", contador );
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

int main(){
	//definir dado
	int opcao = 0;
	//identificar
	printf ( "%s\n", "Exercicios - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
	// acoes
	// repetir
	do{
		//para mostrar opcoes
		printf("\n%s\n", "Opcoes: ");
		printf("\n%s", "0 - Terminar");
		printf ( "\n%s" , "1 - Method_01    2 - Method_02" );
		printf ( "\n%s" , "3 - Method_03    4 - Method_04" );
		printf ( "\n%s" , "5 - Method_05    6 - Method_06" );
		IO_println ( "" );
		// ler a opcao do teclado
		printf ( "\n%s", "Opcao = " );
		scanf ( "%d", &opcao );
		getchar( ); // para limpar a entrada de dados
		// para mostrar a opcao lida
		printf ( "\n%s%d", "Opcao = ", opcao );
		// escolher acao dependente da opcao
		// testar valor
		switch ( opcao )
		{
			case 0: //nao fazer nada
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
			default: // comportamento padrao
			printf ( "\nERRO: Opcao invalida.\n" );
			break;
		} // end switch
	}
	while ( opcao != 0 );
	// encerrar
	IO_pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )

/*
---------------------------------------------- previsao de testes
a.) [vassOURA] --> minusculas: 4
b.) [EsPeLhO] --> minusculas: 3
---------------------------------------------- historico
Versao Data Modificacao
0.1 21/03 esboco
0.2 21/03 modificacao
0.3 21/03 modificacao
0.4 21/03 modificacao
0.5 21/03 modificacao
0.6 21/03 modificacao
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
0.2 01. ( OK ) identificacao de programa
leitura e saida de dados
0.3 01. ( OK ) identificacao de programa
leitura e saida de dados
0.4 01. ( OK ) identificacao de programa
leitura e saida de dados
0.5 01. ( OK ) identificacao de programa
leitura e saida de dados
0.6 01. ( OK ) identificacao de programa
leitura e saida de dados
*/


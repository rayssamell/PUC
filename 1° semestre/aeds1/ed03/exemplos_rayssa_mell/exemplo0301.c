/*
Exemplo0300 - v0.0. - 12/03/2024
Author: Rayssa Mell de Souza Silva
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
  Method_00 - nao faz nada.
 */
void method_00 ( void )
{
// nao faz nada
} // end method_00 ( )
/**
  Method_01 - Repeticao com teste no inicio.
 */
void method_01 ( void )
{
// definir dado
	int x = 0;
// identificar
	IO_id ( "Method_01 - v0.0" );
// ler do teclado o valor inicial
	x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
	while ( x > 0 )
	{
		// mostrar valor atual
		IO_println ( IO_toString_d ( x ) );
		// passar ao proximo valor
		x = x - 1;
	} // end while
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
Method_02 - Repeticao com teste no inicio.
*/
void method_02 ( void )
{
// definir dado
	int x = 0;
	int y = 0;
// identificar
	IO_id ( "Method_02 - v0.0" );
// ler do teclado
	x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
	y = x; // copiar o valor lido (e' melhor)
	while ( y > 0 )
	{
		// mostrar valor atual
		IO_println ( IO_toString_d ( x ) );
		// passar ao proximo valor
		y = y - 1;
	} // end while
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

int main ( )
{
// definir dado
	int x = 0;
// repetir até desejar parar
	do
	{
		// identificar
		IO_id ( "EXEMPLO0300 - Programa - v0.0" );
		// ler do teclado
		IO_println ( "Opcoes" );
		IO_println ( "0 - parar" );
		IO_println ( "1 - repeticao com teste no inicio" );
		IO_println ( "2 - repeticao pela quantidade" );
		IO_println ( "" );
		x = IO_readint ( "Entrar com uma opcao: " );
		// testar valor
		switch ( x )
		{
			case 0: method_00 ( ); break;
			case 1: method_01 ( ); break;
			case 2: method_02 ( ); break;
		default:
			IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
				IO_concat ( IO_toString_d ( x ), ")" ) ) );
		} // end switch
	}
	while ( x != 0 );
// encerrar
	IO_pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )
/*
---------------------------------------------- Saídas
Entrar com uma opcao: 2
Method_02 - v0.0
Autor: ________________________

Entrar com uma quantidade: 3
3
3
3

Apertar ENTER para continuar
---------------------------------------------- previsao de testes
a.) Entrar com uma quantidade: 4
4
4
4
4

b) Entrar com uma quantidade: 6
6
6
6
6
6
6

---------------------------------------------- historico
Versao Data Modificacao
0.1 12/03 esboco
0.2 12/03 mudanca de versao
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
0.2 01. ( OK ) identificacao de programa
			   leitura e exibicao de repeticao por quantidade
*/

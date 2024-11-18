/*
Exemplo0400 - v0.0. - 21/03/2024
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
a.) -1
b.) 5 e { 10, 20, 30, 40, 50 }
---------------------------------------------- historico
Versao Data Modificacao
0.1 21/03 esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/


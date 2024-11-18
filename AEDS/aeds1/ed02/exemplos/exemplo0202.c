/*
Exemplo0202 - v0.0. - 16 / 03 / 2024
Author: Rayssa Mell de Souza Silva
*/
// dependencias
#include "io.h" // bibliotecas e outras definicoes

/**
  Method_01.
 */
void method_01 ( void )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// identificar
	IO_id ( "\nMethod_01 - Programa - v0.0" );
// ler do teclado
	x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
	if ( x == 0 )
	{
		IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
	}
	if ( x != 0 )
	{
		IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
	} // end if
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/*
Method_02.
*/
void method_02 ( void )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// identificar
	IO_id ("\nMethod_02 - Programa - v0.0" );
// ler do teclado
	x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
	if ( x == 0 )
	{
		IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
	}
	else // equivalente a "caso diferente do já' testado"
	{
		IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
	} // end if
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

int main ( void )
{
// definir dado
	int opcao = 0;
// identificar
	printf ( "%s\n", "Exemplo0202 - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
// acoes
// repetir
	do
	{
		// para mostrar opcoes
		printf ( "\n%s\n", "Opcoes:" );
		printf ( "\n%s" , "0 - Terminar" );
		printf ( "\n%s" , "1 - Method_01" );
		printf ( "\n%s" , "2 - Method_02" );
		printf ( "\n" );
		// ler a opcao do teclado
		printf ( "\n%s", "Opcao = " );
		scanf ( "%d", &opcao );
		getchar( ); // para limpar a entrada de dados
		// para mostrar a opcao lida
		printf ( "\n%s%d", "Opcao = ", opcao );
		// escolher acao dependente da opcao
		switch ( opcao )
		{
			case 0: /* nao fazer nada */ break;
			case 1: method_01 ( ); break;
			case 2: method_02 ( ); break;
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
/*

---------------------------------------------- Saidas
Opcao = 2
Method_02 - Programa - v0.0
Autor: Rayssa Mell de SOuza Silva

Entrar com um valor inteiro: 23
Valor diferente de zero  (23)

Apertar ENTER para continuar
---------------------------------------------- previsao de testes
a.) [2,4,25] - diferente de zero
---------------------------------------------- historico
Versao Data Modificacao
0.1 16/03 esboco
0.2 16/03 
---------------------------------------------- testes
Versao Teste
0.0 00. ( OK ) identificacao de programa
0.0 01. ( OK ) identificacao de programa
0.0 02. ( OK ) identificacao de programa
*/
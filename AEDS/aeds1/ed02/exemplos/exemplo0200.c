/*
Exemplo0200 - v0.0. - 16 / 03 / 2024
Author: Rayssa Mell de Souza Silva
*/
// dependencias
#include "io.h" // bibliotecas e outras definicoes
/**
  Method_01.
 */
void method_01 ( void )
{
	// identificar
	IO_id ( "\nMethod_01 - Programa - v0.0" );
	// encerrar
	IO_pause ( "\nApertar ENTER para continuar.\n" );
} // end method_01 ( )
/*
Funcao principal.
@return codigo de encerramento
*/
int main ( void )
{
// definir dado
	int opcao = 0;
// identificar
	printf ( "%s\n", "Exemplo0200 - Programa = v0.0" );
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

---------------------------------------------- historico
Versao Data Modificacao
0.1 16/03 esboco
---------------------------------------------- testes
Versao Teste
0.0 00. ( OK ) identificacao de programa
*/

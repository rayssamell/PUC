/*
Exemplo0003 - v0.0. - 09/03/2024
Author: Rayssa Mell de Souza Silva 
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral

int main ( int argc, char* argv [ ] )
{
// definir dados / resultados
	int opcao = 0;
// identificar
	printf ( "%s\n", "Exemplo0003 - Programa = v0.0" );
	printf ( "%s\n", "Autor: _____________________" );
	printf ( "\n" ); // mudar de linha
// acoes
// para mostrar opcoes
	printf ( "\n%s\n", "Opcoes:" );
	printf ( "\n%s" , "Terminar" );
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
		case 0: // nao fazer nada
		break;
		default: // comportamento padrao
		printf ( "\nERRO: Opcao invalida.\n" );
		break;
	} // end switch
// encerrar
	printf ( "\n\nApertar ENTER para terminar." );
	getchar( ); // aguardar por ENTER
	return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- historico
Versao Data Modificacao
0.1 09/03 esboco
0.2 09/03 mudanca de versao
0.3 09/03 mudanca de versao
---------------------------------------------- testes
Versao Teste
Versao Teste
0.0 00. ( OK ) identificacao de programa
0.1 01. ( OK ) identificacao de programa
0.2 02. ( OK ) identificacao de programa
leitura e exibicao de inteiro
0.3 03. ( OK ) identificacao de programa
			   leitura e exibicao mediante escolha

*/

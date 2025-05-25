/*
Exemplo0002 - v0.0. - 09/03/2024
Author: Rayssa Mell de Souza Silva 
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral

int main ( int argc, char* argv [ ] )
{
// definir dados / resultados
	double opcao = 0;
// identificar
	printf ( "%s\n", "Exemplo0002 - Programa = v0.0" );
	printf ( "%s\n", "Autor: _____________________" );
	printf ( "\n" ); // mudar de linha
// acoes
// ler a opcao do teclado
	printf ( "\n%s", "Opcao = " );
	scanf ( "%lf", &opcao );
	getchar( ); // para limpar a entrada de dados
// para mostrar a opcao lida
	printf ( "\n%s%lf", "Opcao = ", opcao );
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
---------------------------------------------- previsao de testes

---------------------------------------------- testes
Versao Teste
0.0 01. ( OK ) identificacao de programa
0.1 01. ( OK ) identificacao de programa
0.2 01. ( OK ) identificacao de programa
               leitura e exibicao de inteiro
---------------------------------------------- resultados
Utilização do scanf para entrada de dados. 
Saída: solicita uma opcao 
Exibe a opcao escolhida

*/

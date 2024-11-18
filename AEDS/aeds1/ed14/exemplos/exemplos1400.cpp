/*
Exemplo1400 - v0.0. - 06 / 06 / 2024
Author: Rayssa Mell de Souza Silva - 860210
*/
// ----------------------------------------------- preparacao

// dependencias
#include "MyString.hpp"
#include "Erro.hpp" // classe para tratar erros

class Error : public Erro
{
public:
	/**
	 * Funcao para obter mensagem
	 * relativa ao código de erro.
	 * @return mensagem sobre o erro
	 */
	std::string getErroMsg ( )
	{
		return ( NO_ERROR ); // COMPLETAR A DEFINICAO
	} // end getErroMsg ( )	
}; // end classe MyString
// ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos
/**
  Method_00 - nao faz nada.
 */
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )
/**
  Method_01 - Testar definicoes da classe.
 */
void method_01 ( )
{
	// definir dados
	ref_Documentacao pessoa1 = new Documentacao();
	Documentacao  pessoa2;
	// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	
	// Atribuir valores validos
	pessoa1->setNome("Joao Silva");
	pessoa1->setMatricula("202312345");
	pessoa2.setNome ( "Maria Souza" );
	pessoa2.setMatricula ( "202412654" );
	// Mostrar informacoes
	cout << pessoa1->toString() << endl;
	cout << pessoa2.toString() << endl;
	// encerrar
	pause ( "Apertar ENTER para continuar" );
	
} // end method_01 ( )
// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/
int main ( int argc, char** argv )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
	do
	{
		// identificar
		cout << "EXEMPLO1401 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << " 0 - parar " << endl;
		cout << " 1 - testar definicoes " << endl;
		// ler do teclado
		cout << endl << "Entrar com uma opcao: ";
		cin >> x;
		// escolher acao
		switch ( x )
		{
		case 0:
			method_00 ( );
			break;
		case 1:
			method_01 ( );
			break;
		default:
			cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 06/06 esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/

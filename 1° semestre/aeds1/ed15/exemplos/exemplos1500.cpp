/*
Exemplos1500 - v0.0. - 14 / 06 / 2024
Author: Rayssa Mell de Souza Silva
*/
// ----------------------------------------------- preparacao
// dependências
#include <iostream>
#include "mystring.hpp"
#include "Erro.hpp"

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
}; // end classe Error

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
	Documentacao pessoa1;
	ref_Documentacao pessoa3 = new Documentacao ( );
	// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02 - Testar atribuicoes.
 */
void method_02 ( )
{
	// definir dados
	Documentacao pessoa1;
	ref_Documentacao pessoa2 = new Documentacao ( );
	// identificar
	cout << "\nMethod_02 - v0.0\n" << endl;
	// testar atribuicoes
	pessoa1.setNome ( "Pessoa_01" );
	pessoa1.setMatricula ( "202401" );
	pessoa2->setNome ( "Pessoa_02" );
	pessoa2->setMatricula ( "202402" );
	cout << "pessoa1 - { " << pessoa1.getNome ( ) << ", " << pessoa1.getMatricula ( ) << " }" << endl;
	cout << "pessoa2 - { " << pessoa2->getNome ( ) << ", " << pessoa2->getMatricula ( ) << " }" << endl;
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03 - Testar recuperacao de dados.
 */
void method_03 ( )
{
	// definir dados
	Documentacao pessoa1;
	ref_Documentacao pessoa2 = new Documentacao( );
	// identificar
	cout << "\nMethod_03 - v0.0\n" << endl;
	// testar atribuicoes
	pessoa1.setNome ( "Pessoa_01" );
	pessoa1.setMatricula ( "202401" );
	pessoa2->setNome ( "Pessoa_02" );
	pessoa2->setMatricula ( "202402" );
	cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
	cout << "pessoa2 - " << pessoa2->toString ( ) << endl;
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04 - Testar construtor alternativo.
 */
void method_04 ( )
{
	// definir dados
	Documentacao pessoa1 ( "Pessoa_01", "202401" );
	ref_Documentacao pessoa2 = new Documentacao ( "Pessoa_02", "202402" );
// identificar
	cout << "\nMethod_04 - v0.0\n" << endl;
// testar atribuicoes
	cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
	cout << "pessoa2 - " << pessoa2->toString ( ) << endl;
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05 - Testar construtor alternativo e mensagem de erro.
 */
void method_05 ( )
{
// definir dados
	Documentacao pessoa1 ( "Pessoa_01", "202401" );
	ref_Documentacao pessoa2 = new Documentacao ( "", "202402" );
// identificar
	cout << "\nMethod_05 - v0.0\n" << endl;
// testar atribuicoes
	if ( ! pessoa1.hasErro( ) )
		cout << "pessoa1 - " << pessoa1.toString( ) << endl;
	else
		cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;
	if ( ! pessoa2->hasErro( ) )
		cout << "pessoa2 - " << pessoa2->toString( ) << endl;
	else{
		cout << "pessoa3 tem erro (" << pessoa2->getErro( ) << ")" << endl;
		cout << "Erro: " << pessoa2->getErroMsg() << endl;
	}
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Method_06 - Testar atribuicoes e tratamento de erro.
 */
void method_06 ( )
{
    // definir dados
	Documentacao pessoa1 ( "Pessoa_01", "202401" );
	ref_Documentacao pessoa2 = nullptr;
	ref_Documentacao pessoa3 = new Documentacao ( "", "202402" );
	// identificar
	cout << "\nMethod_06 - v0.0\n" << endl;
	// testar atribuicoes
	pessoa2 = &pessoa1;
	if ( ! pessoa2->hasErro( ) )
		cout << "pessoa1 - " << pessoa2->toString( ) << endl;
	else
		cout << "pessoa1 tem erro (" << pessoa2->getErro( ) << ")" << endl;
	pessoa2 = pessoa3; 
	if ( ! pessoa2->hasErro( ) )
		cout << "pessoa3 - " << pessoa2->toString( ) << endl;
	else{
		cout << "pessoa3 tem erro (" << pessoa2->getErro( ) << ")" << endl;
		cout << "Erro: " << pessoa2->getErroMsg() << endl;
	}
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07 - Testar atribuicoes e tratamento de erro.
 */
void method_07 ( )
{
// definir dados
	Documentacao pessoa1 ( "Pessoa_01", "202401" );
	ref_Documentacao pessoa2 = nullptr;
	ref_Documentacao pessoa3 = new Documentacao ( "", "202403" );
	ref_Documentacao pessoa4 = nullptr;
// identificar
	cout << "\nMethod_07 - v0.0\n" << endl;
// testar atribuicoes
	pessoa2 = new Documentacao ( pessoa1 );
	if ( pessoa2 )
		cout << "pessoa2 - " << pessoa2->toString( ) << endl;
	else{
		cout << "pessoa2 tem erro (" << pessoa2->getErro( ) << ")" << endl;
		cout << "Erro: " << pessoa2->getErroMsg() << endl;
	}
	if ( pessoa3 ) //testar existencia
	{
		pessoa2 = new Documentacao ( *pessoa3 );
		if ( pessoa2 )
			cout << "pessoa2 - " << pessoa2->toString( ) << endl;
		else{
			cout << "pessoa2 tem erro (" << pessoa3->getErro( ) << ")" << endl;
			cout << "Erro: " << pessoa3->getErroMsg() << endl;
		}
	} // end if
	if ( pessoa4 ) 
	{
		pessoa2 = new Documentacao ( *pessoa4 );
		if ( pessoa2 )
			cout << "pessoa2 - " << pessoa2->toString( ) << endl;
		else{
			cout << "pessoa2 tem erro (" << pessoa4->getErro( ) << ")" << endl;
			cout << "Erro: " << pessoa4->getErroMsg() << endl;
		}
	} // end if
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
  Method_08 - Testar arranjo de objetos.
 */
void method_08 ( )
{
// definir dados
	Documentacao pessoa [ 2 ];
	int x = 0;
// identificar
	cout << "\nMethod_08 - v0.0\n" << endl;
// testar atribuicoes
	pessoa [ 0 ].setNome ( "Pessoa_1" );
	pessoa [ 0 ].setMatricula ( "202401" );
	pessoa [ 1 ].setNome ( "Pessoa_2" );
	pessoa [ 1 ].setMatricula ( "202402" );
	for ( x=0; x < 2; x=x+1 )
	{
		cout << x << " : " << pessoa[ x ].toString( ) << endl;
	} // end for
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

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
		cout << "EXEMPLO1500 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << "  0 - parar " << endl;
		cout << "  1         " << endl;
		cout << "  2         " << endl;
		cout << "  3         " << endl;
		cout << "  4         " << endl;
		cout << "  5         " << endl;
		cout << "  6         " << endl;
		cout << "  7         " << endl;
		cout << "  8         " << endl;
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
		case 2:
			method_02 ( );
			break;
		case 3:
			method_03 ( );
			break;
		case 4:
			method_04 ( );
			break;
		case 5:
			method_05 ( );
			break;
		case 6:
			method_06 ( );
			break;
		case 7:
			method_07 ( );
			break;
		case 8:
			method_08 ( );
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
---------------------------------------------- relatorio de testes
EXEMPLO1500 - Programa - v0.0

--> Method_01 - v0.0

--> Method_02 - v0.0 - Testar atribuicoes pessoa 1 e pessoa 2

pessoa1 - { Pessoa_01, 202401 }
pessoa2 - { Pessoa_02, 202402 }

--> Method_03 - v0.0 - Testar recuperacao de dados pessoa 1 e pessoa 2

pessoa1 - Nome: Pessoa_01
Matricula: 202401

pessoa2 - Nome: Pessoa_02
Matricula: 202402

--> Method_04 - v0.0 - Testar construtor alternativo.

pessoa1 - Nome: Pessoa_01
Matricula: 202401

pessoa2 - Nome: Pessoa_02
Matricula: 202402

--> Method_05 - v0.0 - Testar construtor alternativo e mensagem de erro.

pessoa1 - Nome: Pessoa_01
Matricula: 202401

pessoa3 tem erro (1)
Erro: [ERRO] Nome invalido.

--> Method_06 - v0.0 - Testar atribuicoes e tratamento de erro.

pessoa1 - Nome: Pessoa_01
Matricula: 202401

pessoa3 tem erro (1)
Erro: [ERRO] Nome invalido.

--> Method_07 - v0.0 - Testar atribuicoes e tratamento de erro.

pessoa2 - Nome: Pessoa_01
Matricula: 202401

pessoa2 - Nome:
Matricula: 202403

--> Method_08 - v0.0

0 : Nome: Pessoa_1
Matricula: 202401

1 : Nome: Pessoa_2
Matricula: 202402

---------------------------------------------- historico
Versao Data Modificacao
0.1 14/06
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/

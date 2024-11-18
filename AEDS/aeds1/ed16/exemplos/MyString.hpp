/*
MyString.hpp - v0.0. - 20/06/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

// ----------------------------------------------- definicoes globais
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

// dependencias
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// using declarations
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::ofstream;
using std::ifstream;

// outras dependencias
void pause ( std::string text )
{
	string dummy;
	cin.clear ( );
	cout << endl << text;
	cin.ignore( );
	getline(cin, dummy);
	cout << endl << endl;
} // end pause ( )

#include "Erro.hpp"
// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar documentacao, derivada da classe Erro.
 */

class Documentacao : public Erro {
	/**
	 * atributos privados.
	 */
private:
	string nome;
	string matricula;
	string endereco;
	string telefone;
	
	/**
	 * definicoes publicas.
	 */
public:
	/**
	 * Destrutor.
	 */
	~Documentacao( )
	{ }
	
	/**
	 * Construtor padrao.
	 */
	Documentacao ( ){
		setErro ( 0 ); // nenhum erro, ainda
		// atribuir valores iniciais vazios
		nome      = "";
		matricula = "";
		endereco  = "";
		telefone  = "";
	}// end construtor
	
	/**
	 * Construtor alternativo.
	 * @param nome_inicial a ser atribuido
	 * @param matricula_inicial a ser atribuido
	 * @param endereco_inicial a ser atribuido
	 * @param telefone_inicial a ser atribuido
	 */
	Documentacao ( std::string nome_inicial,    std::string matricula_inicial, 
				   std::string endereco_inicial, std::string telefone_inicial)
	{
		setErro ( 0 ); // nenhum erro atribuido
		// atribuir valores iniciais
		setNome      ( nome_inicial )     ;   // nome     = nome_inicial;
		setMatricula ( matricula_inicial );  // matricula = matricula_inicial;
		setEndereco  ( endereco_inicial );  // endereco   = endereco_inicial;
		setFone 	 ( telefone_inicial ); // telefone    = telefone_inicial;
	} // end constructor (alternativo)
	
	/**
	 * Construtor alternativo baseado em copia.
	 */
	Documentacao ( Documentacao const & another )
	{
		// atribuir valores iniciais por copia
		setErro ( 0 ); // copiar erro
		setNome      ( another.nome ); // copiar nome
		setMatricula ( another.matricula ); // copiar matricula
		setEndereco  ( another.endereco ); // copiar endereco
		setFone      ( another.telefone ); // copiar telefone
	} // end constructor (alternativo)
	
	// ----------------------------------- metodos para acesso
	
	/**
	 * Metodo para atribuir nome.
	 * @param nome a ser atribuido
	 */
	void setNome ( std::string nome )
	{
		if ( nome.empty ( ) )
			setErro ( 1 ); // nome invalido
		else
			this->nome = nome;
	} // end setNome ( )
	
	/**
	 * Metodo para atribuir matricula.
	 * @param matricula a ser atribuida
	 */
	void setMatricula ( std::string matricula )
	{
		if ( matricula.empty ( ) )
			setErro ( 2 ); // matricula invalida
		else
			this->matricula = matricula;
	} // end setMatricula ( )
	
	/**
	 * Metodo para atribuir endereco
	 * @param endereco a ser atribuido
	 */
	void setEndereco (std::string endereco)
	{
		if(endereco.empty( ) )
			setErro(3); // endereco invalido
		else
			this->endereco = endereco;
	} // end setEndereco()
	
	
	/**
	 * Metodo para atribuir telefone.
	 * @param fone a ser atribuido
	 */
	void setFone(std::string telefone)
	{
		if(telefone.empty( ) )
			setErro(4); //telefone invalido
		else
			this->telefone = telefone;
	} // end setFone()
	
	
	/**
	 * Funcao para obter nome.
	 * @return nome armazenado
	 */
	std::string getNome ( )
	{
		return ( this->nome );
	} // end getNome ( )
	
	/**
	 * Funcao para obter matricula.
	 * @return matricula armazenada
	 */
	std::string getMatricula ( )
	{
		return ( this->matricula );
	} // end getMatricula ( ) 
	
	/**
	 * Funcao para obter endereco.
	 * @return endereco armazenado
	 */
	std::string getEndereco ( )
	{
		return( this->endereco );
	}//end getMatricula ( )
	
	/**
	 * Funcao para obter telefone.
	 * @return telefone armazenado
	 */
	std::string getFone ( )
	{
		return( this->telefone );
	}// end getFone ( )
	
	/**
	 * Funcao para obter documentacao essencial de uma pessoa.
	 * @return dados de uma pessoa
	 */
	std::string toString ( )
	{
		return "{ " + getNome() + ", " + getMatricula() + "," + getEndereco() + ", " + getFone() + " }";
	} // end toString ( )	
	
};//fim da classe documentacao

using ref_Documentacao = Documentacao*;

#endif // _MYSTRING_H_

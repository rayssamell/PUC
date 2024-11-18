/*
MyString.hpp - v0.0. - 06/06/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

// ----------------------------------------------- definicoes globais

#include "Erro.hpp"
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

// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar documentacao, derivada da classe Erro.
 */

class Documentacao : public Erro {
	/**
	 * atributos privados.
	 */
private:
	string conteudo;
	
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
		conteudo      = "";
	}// end construtor
	
	/**
	 * Construtor alternativo.
	 * @param nome_inicial a ser atribuido
	 * @param matricula_inicial a ser atribuido
	 */
	Documentacao ( std::string conteudo_inicial )
	{
		setErro ( 0 ); // nenhum erro, ainda
		// atribuir valores iniciais
		setConteudo      ( conteudo_inicial )     ; // nome = nome_inicial;
	} // end constructor (alternativo)
	
	/**
	 * Construtor alternativo baseado em copia.
	 */
	Documentacao ( Documentacao const & another )
	{
		// atribuir valores iniciais por copia
		setErro ( 0 ); // copiar erro
		setConteudo      ( another.conteudo ); // copiar nome
	} // end constructor (alternativo)
	
	// ----------------------------------- metodos para acesso
	
	/**
	 * Metodo para atribuir nome.
	 * @param nome a ser atribuido
	 */
	void setConteudo ( std::string conteudo )
	{
		if ( conteudo.empty ( ) )
			setErro ( 1 ); // conteudo invalido
		else
			this->conteudo = conteudo;
	} // end setConteudo ( )
	
	
	/**
	 * Funcao para obter conteudo.
	 * @return nome armazenado
	 */
	std::string getConteudo ( )
	{
		return ( this->conteudo );
	} // end getconteudo ( )
	
	/**
	 * Funcao para obter documentacao essencial de uma pessoa.
	 * @return dados de uma pessoa
	 */
	std::string toString ( )
	{
		string saida = "Conteudo: " + conteudo + "\n";
		return saida;
	} // end toString ( )	
	
	/* Funcao para gerar inteiro */
	
	int getInt() {
		std::string content = getConteudo();
		int result = 0;
		
		if (content.empty()) {
			setErro(2);
			return -1;
		} else {
			for (int i = 0; i < content.length(); i++) {
				if (content[i] >= '0' && content[i] <= '9') {
					result = result * 10 + (content[i] - '0');
				} else if (content[i] >= 'A' && content[i] <= 'Z') {
					result = result * 100 + 64 + (content[i] - 'A' + 1);
				} else if (content[i] >= 'a' && content[i] <= 'z') {
					result = result * 100 + 96 + (content[i] - 'a' + 1);
				} else {
					setErro(1); 
					return -1;
				}
			}
		}
		return result;
	}
	
	double getDouble() {
		std::string content = getConteudo();
		double result = 0.0;
		
		if (content.empty()) {
			setErro(2);
			return 0.0;
		} else {
			for (int i = 0; i < content.length(); i++) {
				if (content[i] >= '0' && content[i] <= '9') {
					result = result * 10.0 + (double)(content[i] - '0');
				} else if (content[i] >= 'A' && content[i] <= 'Z') {
					result = result * 100.0 + 64.0 + (double)(content[i] - 'A' + 1.0);
				} else if (content[i] >= 'a' && content[i] <= 'z') {
					result = result * 100.0 + 96.0 + (double)(content[i] - 'a' + 1.0);
				} else {
					setErro(1); 
					return 0.0;
				}
			}
		}
		return result;
	}
	
	bool getBoolean( ){
		string conteudo = getConteudo();
		if (conteudo == "true" || conteudo == "t") {
			return true;
		} else if (conteudo == "false" || conteudo == "f") {
			return true;
		} 
		setErro(2);
		return false;
	}
	
	bool contains(std::string texto) {
		string conteudo = getConteudo();
		bool result = false;
		
		if (conteudo.empty()) {
			setErro(2);
			return false;
		} else {
			for (int i = 0; i <= conteudo.length() - texto.length(); i=i+1) {
				int j = 0;
				while (j < texto.length() && conteudo[i + j] == texto[j]) {
					j = j + 1;
				}
				if (j == texto.length()) {
					result = true;
				}
			}
		}
		
		return result;
	}

	std::string toUpperCase( ){
		string conteudo = getConteudo();
		int result = 0;
		if(conteudo.empty()){
			setErro(2);
		}else{
			for (int i = 0; i < conteudo.length(); i = i + 1) {
				if (conteudo[i] >= 'a' && conteudo[i] <= 'z') {
					conteudo[i] = conteudo[i] - 'a' + 'A';  
				}
			}
		}
		return (conteudo);
	}
	
	std::string toLowerCase( ){
		string conteudo = getConteudo();
		int result = 0;
		if(conteudo.empty()){
			setErro(2);
		}else{
			for (int i = 0; i < conteudo.length(); i = i + 1) {
				if (conteudo[i] >= 'A' && conteudo[i] <= 'Z') {
					conteudo[i] = conteudo[i] - 'A' + 'a';  
				}
			}
		}
		return (conteudo);
	}
	
	std::string replace ( char original, char novo ){
		string conteudo = getConteudo();  
		string substituir(conteudo.length(), 0); 
		
		if (conteudo.empty()) {
			setErro(2);
		}
		else{
			for (int i = 0; i < conteudo.length(); i = i + 1) {
				if (conteudo[i] == original) {
					substituir[i] = novo;
				} else {
					substituir[i] = conteudo[i];
				}
			}
		}
		return substituir;
	}
	
	std::string encrypt() {
		string conteudo = getConteudo();
		conteudo = toUpperCase();
		string texto;
		int x = 3; 
		
		if (conteudo.empty()) {
			setErro(2);
		} else {
			for (int i = 0; i < conteudo.length(); ++i) {
				if (conteudo[i] >= 'A' && conteudo[i] <= 'Z') {
					int cifraCesar = (conteudo[i] - 'A' + x) % 26;
					texto += 'A' + cifraCesar;
				} else {
					texto += conteudo[i]; 
				}
			}
		}
		return texto;
	}

	std::string decrypt() {
		string conteudo = getConteudo();
		conteudo = toUpperCase();
		string texto;
		int x = 3; 
		
		if (conteudo.empty()) {
			setErro(2);
		} else {
			for (int i = 0; i < conteudo.length(); ++i) {
				if (conteudo[i] >= 'A' && conteudo[i] <= 'Z') {
					int cifraCesar = (conteudo[i] + 'A' - x) % 26;
					texto += 'A' + cifraCesar;
				} else {
					texto += conteudo[i]; 
				}
			}
		}
		return texto;
	}
	
	int split(std::string sequencia[]) {
		int count = 0;
		string conteudo = getConteudo();
		string palavra = "";
		
		if (conteudo.empty()) {
			setErro(2);
		} else {
			for (int i = 0; i <= conteudo.length(); i = i + 1) {
				if (i == conteudo.length() || conteudo[i] == ' ') {
					sequencia[count++] = palavra;
					palavra = "";
				}
			    else {
					palavra += conteudo[i];
				}
			}
		}
		return count;
	}
	
	int delimiter(char delimitador, string sequencia[]) {
		int count = 0;
		string palavra = "";
		
		for (int i = 0; i <= conteudo.length(); ++i) {
			if (i == conteudo.length() || conteudo[i] == delimitador) {
				if (!palavra.empty()) {
					sequencia[count++] = palavra;
					palavra = "";
				}
			} else {
				palavra += conteudo[i];
			}
		}
		
		return count;
	}
	
	void testDelimiter() {
		string sequencia[10]; 
		int count = delimiter(',', sequencia);
		
		cout << "Split resultado (delimitador): ";
		for (int i = 0; i < count; ++i) {
			cout << "\"" << sequencia[i] << "\" ";
		}
		cout << "\nCount: " << count << endl;
	}
	
	std::string reverseString() {
		string conteudo = getConteudo();
		
		if(conteudo.empty()){
			setErro(2);
		}else {
			for (int i = 0; i < conteudo.length() / 2; ++i) {
				char temp = conteudo[i];
				conteudo[i] = conteudo[conteudo.length() - 1 - i];
				conteudo[conteudo.length() - 1 - i] = temp;
				setErro(0);
			}
		}
		return (conteudo);
	}
	
	void testReverseString() {
		if(getErro() == 0){
			std::cout << "Inverter string: " << reverseString() << std::endl;
		}
	}
	
};//end class()

using ref_Documentacao = Documentacao*;

#endif //end _MYSTRING_H_

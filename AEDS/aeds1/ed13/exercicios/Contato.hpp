/*
Contato.hpp - v0.0. - __ / __ / _____
Author: _______________________
*/
// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_
// dependencias
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo
// outras dependencias
void pause ( std::string text )
{
	std::string dummy;
	std::cin.clear ( );
	std::cout << std::endl << text;
	std::cin.ignore( );
	std::getline(std::cin, dummy);
	std::cout << std::endl << std::endl;
} // end pause ( )
#include "Erro.hpp"
// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar contatos, derivada da classe Erro.
 */
class Contato : public Erro
{
	/**
	 * atributos privados.
	 */
private:
	string nome;
	string fone;
	string fone2;
	string telefones[10];
	int numTelefones; 
	string enderecoResidencial;
	string enderecoProfissional;
	
	bool isValidPhone(std::string fone) {
	    for(int i = 0; i < fone.length(); i = i + 1){
		   if (!((fone[i] >= '0' && fone[i] <= '9') || fone[i] == '-')) {
				return false;
		   }
		}
		return true;
	}
	/**
	 * definicoes publicas.
	 */
public:
	/**
	 * Destrutor.
	 */
	~Contato ( )
	{ }
	
	/**
	 * Construtor padrao.
	 */
	Contato ( )
	{
		setErro ( 0 ); // nenhum erro, ainda
		// atribuir valores iniciais vazios
		nome  = "";
		fone  = "";
		fone2 = "";
	    numTelefones = 0;
	} // end constructor (padrão)
	
	/**
	 * Construtor alternativo.
	 * @param nome_inicial a ser atribuido
	 * @param fone_inicial a ser atribuido
	 */
	Contato ( std::string nome_inicial, std::string fone_inicial, std::string fone2_inicial)
	{
		setErro ( 0 ); // nenhum erro, ainda
		// atribuir valores iniciais
		setNome ( nome_inicial ); // nome = nome_inicial;
		setFone ( fone_inicial ); // fone = fone_inicial;
		
		if (fone2_inicial.empty()) {
			fone2 = "";
			numTelefones = 1;
		} else {
			setFone2(fone2_inicial);  // fone2 = fone2_inicial;
		}
	
	} // end constructor (alternativo)
	
	/**
	 * Construtor alternativo baseado em copia.
	 */
	Contato ( Contato const & another )
	{
		// atribuir valores iniciais por copia
		setErro  ( 0 ); // copiar erro
		setNome  ( another.nome ); // copiar nome
		setFone  ( another.fone ); // copiar fone
		setFone2 ( another.fone2); // copiar fone2
		setEnderecoProfissional ( another.enderecoProfissional); 
		setEnderecoResidencial ( another.enderecoResidencial); 
		numTelefones = another.numTelefones;
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
	 * Metodo para atribuir telefone.
	 * @param fone a ser atribuido
	 */
	void setFone ( std::string fone)
	{
		if ( fone.empty ( ) )
			setErro ( 2 ); // fone invalido
		else
			this->fone = fone;
			numTelefones = 1;
			setErro(0);
	} // end setFone ( )
	
	void setFone2 ( std::string fone2)
	{
	    if (numTelefones == 1) {
		    if (fone2.empty()) {
			    setErro(2); // fone invalido
		    } else {
			    this->fone2 = fone2;
			    numTelefones = 2;
				setErro(0);
		    }
		 }
	} // end setFone2 ( )
	
	void setEnderecoResidencial(string endereco) {
		if ( endereco.empty ( ) )
			setErro ( 7 ); // endereco invalido
		else
			this->enderecoResidencial = endereco;
	}
	
	void setEnderecoProfissional(string endereco) {
		if ( endereco.empty ( ) )
			setErro ( 7 ); // endereco invalido
		else
			this->enderecoProfissional = endereco;
	}
	/**
	 * Funcao para obter nome.
	 * @return nome armazenado
	 */
	std::string getNome ( )
	{
		return ( this->nome );
	} // end getNome ( )
	
	/**
	 * Funcao para obter fone.
	 * @return fone armazenado
	 */
	std::string getFone ( )
	{
		return ( this->fone );
	} // end getFone ( ) 
	
	std::string getFone2 ( )
	{
		return ( this->fone2 );
	} // end getFone2 ( ) 
	
	string getEnderecoResidencial() {
		return (this->enderecoResidencial);
	}
	
	string getEnderecoProfissional() {
		return (this->enderecoProfissional);
	}
	
	/**
	 * Funcao para obter dados de uma pessoa.
	 * @return dados de uma pessoa
	 */
	std::string toString ( )
	{
		if (fone2.empty()) {
			return "{ " + getNome() + ", " + getFone() + " }";
		} else {
			return "{ " + getNome() + ", " + getFone() + ", " + getFone2() + " }";
		}
	} // end toString ( )
	
	/**
	 * Funcao para atribuir valor a nome
	 */
	void readName(std::string nome){
		cin >> nome;
		while(nome.empty()){
			setErro(1);
			cin >> nome;
		}
		setErro(0);
		setNome(nome);
	}
	/**
	 * Metodo para testar a funcionalidade de leitura do nome.
	 */
	void testReadName() {
		readName("Nome: ");
		if (getErro() == 0) {
			cout << "Nome lido com sucesso: " << getNome() << endl;
		} else {
			cout << "Falha ao ler o nome." << endl;
		}
	}
	
	/**
	 * Funcao para atribuir valor ao telefone
	 */
	void readPhone(std::string fone){
		cin >> fone;
		while(fone.empty()){
			setErro(2);
			cin >> fone;
		}
		setErro(0);
		setFone(fone);
	}
	/**
	 * Metodo para testar a funcionalidade de leitura do telefone.
	 */
	void testReadPhone() {
		readPhone("Telefone: ");
		if (getErro() == 0) {
			cout << "Telefone lido com sucesso: " << getFone() << endl;
		} else {
			cout << "Falha ao ler o telefone." << endl;
		}
	}
	
	void testPhoneValid(){
		if (isValidPhone(getFone())) {
			cout << "Numero valido: " << getFone() << std::endl;
		} else {
			cout << "Numero invalido: " << getFone() << std::endl;
		}
	}
	
	
	void readFromFile(std::string filename) {
		ifstream arquivo(filename);
		int quant = 0;
		
		if (!arquivo.is_open()) {
			std::cout << "Erro ao abrir o arquivo: " << filename << std::endl;
			setErro(3);
		}
		else{
			arquivo >> quant;
			
			if(quant > 0){
				for(int x = 0; x < quant && !arquivo.eof(); x= x + 1){
					std::string nome;
					std::string fone;
					
					arquivo >> nome >> fone;
					
					setNome(nome);
					setFone(fone);
					setErro(0);
					
					std::cout << "Nome: " << nome << ", Telefone: " << fone << std::endl;
				}
			}
			else{
				setErro(3);
			}
		}
		arquivo.close();
	}
	
	void testReadArquivo(std::string filename){
		readFromFile(filename);
		if (getErro() == 0) {
			std::cout << "Lido com sucesso " <<  std::endl;
		} else {
			std::cout << "Erro ao ler contato. " << std::endl;
		}
	}
	
	void writeToFile(std::string filename){
		ofstream arquivo(filename);
		
		if (!arquivo.is_open()) {
			std::cout << "Erro ao criar o arquivo: " << filename << std::endl;
			setErro(3);
		}
		else{
			arquivo << 1 << std::endl;
			
			arquivo << nome << std::endl << fone << std::endl;
			setErro(0);
		}
		arquivo.close();
	}
	
	void testWriteFile(std::string filename) {
		writeToFile(filename);
		if (getErro() == 0) {
			std::cout << "Gravado com sucesso" << std::endl;
		} else {
			std::cout << "Erro ao gravar contato." << std::endl;
		}
	}
	
	void testarNovoTelefone() {
		std::cout << "Nome: " << nome << std::endl;
		std::cout << "Telefone 1: " << fone << std::endl;
		if (!fone2.empty()) {
			std::cout << "Telefone 2: " << fone2 << std::endl;
		}
	}
	
	int phones(){
		return numTelefones;
	}

	void setFone2b(std::string fone2) {
		if (numTelefones != 2) {
			setErro(4); 
		} else {
			this->fone2 = fone2;
		}
	}
	
	void alterarTelefone(){
		std::cout << "Nome: "       << nome  << std::endl;
		std::cout << "Telefone 1: " << fone  << std::endl;
		std::cout << "Telefone 2: " << fone2 << std::endl;
	}
	
	void setFone2c(){
		if (numTelefones == 2) {
			fone2 = "";
			numTelefones = 1;
			setErro(0);
		} else {
		    setErro(4);
		}
	}
	
	void removeFone(){
		setFone2c();
		if (getErro() == 0) {
			std::cout << "Removido com sucesso" << std::endl;
		} else {
			std::cout << "Nao ha telefone para remover." << std::endl;
		}
	}
	
	void addTelefone(std::string telefone)
	{
		if (numTelefones < 10)
		{
			telefones[numTelefones] = telefone;
			numTelefones++;
		}
		else
		{
			setErro(5); // limite de telefones excedido
		}
	}
	
	void removeTelefone(std::string telefone)
	{
		for (int i = 0; i < numTelefones; ++i) {
			if (telefones[i] == telefone) {
				for (int j = i; j < numTelefones - 1; ++j) {
					telefones[j] = telefones[j + 1];
				}
				numTelefones--;
				std::cout << "Telefone removido com sucesso." << std::endl;
				setErro(0);
			}
		}
		setErro(6);//telefone nao encontrado
	}
	
	void exibirTelefones() {
		if (numTelefones == 0) {
			std::cout << "Nenhum telefone cadastrado." << std::endl;
		} else {
			std::cout << "Telefones:" << std::endl;
			for (int i = 0; i < numTelefones; ++i) {
				std::cout << telefones[i] << std::endl;
			}
		}
	}
	
	void testarEnderecos() {
		cout << "Endereco Residencial: " << enderecoResidencial << endl;
		cout << "Endereco Profissional: " << enderecoProfissional << endl;
	}
	
}; // fim da classe Contato

using ref_Contato = Contato*; // similar a typedef Contato* ref_Contato;
#endif



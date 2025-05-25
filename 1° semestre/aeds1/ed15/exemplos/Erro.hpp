// dependencias
#include <string>
/**
 * Classe para tratar erro.
 */

#ifndef _ERRO_H_
#define _ERRO_H_

class Erro
{
	/*
	* tratamento de erro.
	Codigos de erro:
	0. Nao ha' erro.
	*/
	
	/**
	 * atributos privados.
	 */
private:
	int erro;
	std::string msgErro;
	
protected:
	// ------------------------------------------- metodos para acesso restrito
	/**
	 * Metodo para estabelecer novo codigo de erro.
	  @param codigo de erro a ser guardado
	 */
	void setErro ( int codigo ){
		erro = codigo;
		switch (codigo) {
		case 0:
			msgErro = NO_ERROR;
			break;
		case 1:
			msgErro = "[ERRO] Nome invalido.";
			break;
		case 2:
			msgErro = "[ERRO} Matricula invalida.";
			break;
		default:
			msgErro = "[ERRO] Codigo de erro desconhecido.";
			break;
		}
	}
	
	/**
	 * definicoes publicas.
	 */
public:
	/**
	 * Destrutor.
	 */
	~Erro ( )
	{ }
	/**
	 * Construtor padrao.
	 */
	Erro ( )
	{
		// atribuir valor inicial
		erro = 0;
		msgErro = "";
	} // end constructor (padrão)
	
	/**
	 * Constante da classe.
	 */
	static const std::string NO_ERROR;
	
	// ------------------------------------------- metodos para acesso
	/**
	 * Funcao para obter o codigo de erro.
	  @return codigo de erro guardado
	 */
	int getErro ( )
	{
		return ( erro );
	} // end getErro ( )
	
	/**
	 * indicar a existencia de erro.
	 */
	bool hasErro ( ){
		return ( erro != 0 );
	}//end hasError ( )
	
	/**
	 * Funcao para obter mensagem
	 * relativa ao código de erro.
	 * @return mensagem sobre o erro
	 */
	virtual std::string getErroMsg ( )
	{
		return ( msgErro );
	} // end getErroMsg ( )
	
}; // end class Erro

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif

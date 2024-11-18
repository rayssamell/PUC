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
  Method_01 - converter conteudo para valor inteiro
 */
void method_01 ( )
{
	// definir dados
	ref_Documentacao conteudo = new Documentacao();
	// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	
	// Atribuir valores validos
	conteudo->setConteudo("ABC");
	cout << conteudo->toString() << endl;
	int gerarInteiro = conteudo->getInt();
	if (conteudo->hasError()) {
		cout << "Erro: " << conteudo->getErroMsg();
	} else {
		cout << "Em inteiro: " << gerarInteiro << endl;
	}
	cout << endl;
	conteudo->setConteudo("ab12");
	cout << conteudo->toString() << endl;
	gerarInteiro = conteudo->getInt();
	if (conteudo->hasError()) {
		cout << "Erro: " << conteudo->getErroMsg();
	} else {
		cout << "Em inteiro: " << gerarInteiro << endl;
	}
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_01 - converter conteudo para valor real
 */
void method_02 ( )
{
	// definir dados
	ref_Documentacao conteudo = new Documentacao();
	// identificar
	cout << "\nMethod_02 - v0.0\n" << endl;
	
	// Atribuir valores validos
	conteudo->setConteudo("AB2");
	cout << conteudo->toString() << endl;
	
	double gerarReal = 0.0;
	gerarReal = conteudo->getDouble();
	if (conteudo->hasError()) {
		cout << "Erro: " << conteudo->getErroMsg();
	} else {
		cout << "Em Real: " << gerarReal << endl;
	}
	cout << endl;
	conteudo->setConteudo("1b");
	cout << conteudo->toString() << endl;
	gerarReal = conteudo->getInt();
	if (conteudo->hasError()) {
		cout << "Erro: " << conteudo->getErroMsg();
	} else {
		cout << "Em Real: "<< gerarReal << endl;
	}
	// encerrar
	pause ( "Apertar ENTER para continuar" );
	
} // end method_02 ( )

/**
  Method_03 - converter conteudo para valor logico
 */
void method_03 ( )
{
	// definir dados
	ref_Documentacao conteudo = new Documentacao();
	// identificar
	cout << "\nMethod_03 - v0.0\n" << endl;
	
	// Atribuir valores validos
	conteudo->setConteudo("true");
	cout << " " << conteudo->getBoolean() << endl;
	conteudo->setConteudo("false");
	cout << " " << conteudo->getBoolean() << endl;
	conteudo->setConteudo("t");
	cout << " " << conteudo->getBoolean() << endl;
	conteudo->setConteudo("f");
	cout << " " << conteudo->getBoolean() << endl;
	conteudo->setConteudo("teste");
	cout << " " << conteudo->getBoolean() << endl;
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
	
} // end method_03 ( )

/* Method_04 -  verificar se o parametro esta contido no conteudo */
void method_04(void){
	ref_Documentacao conteudo = new Documentacao();
	std::string texto;
	// identificar
	cout << "\nMethod_04 - v0.0\n" << endl;
	
	// Atribuir valores validos
	conteudo->setConteudo("A casa eh amarela.");
	cout << "Digite um texto para procurar: ";
	cin >> texto;
	
	if (conteudo->contains(texto)) {
		cout << endl << "Encontrado (" << texto << ") em: " << conteudo->getConteudo() << endl;
	} else {
		cout << endl << "Nao encontrado (" << texto << ") em: " << conteudo->getConteudo() << endl;
	}
	
	// encerrar
	pause("Apertar ENTER para continuar");
}//end method_04()

/* Method_05 - a converter letras para maiusculas.*/
void method_05(void){
	ref_Documentacao conteudo = new Documentacao();
	// identificar
	cout << "\nMethod_05 - v0.0\n" << endl;
	
	// Atribuir valores validos
	conteudo->setConteudo("1bcdE");
	cout << "" << conteudo->toString() << "convertido para maiuscula: " << conteudo->toUpperCase() << endl;
	// encerrar
	pause("Apertar ENTER para continuar");
}//end method_05()

/* Method_06 - converter letras para minusculas*/
void method_06(void){
	ref_Documentacao conteudo = new Documentacao();
	// identificar
	cout << "\nMethod_06 - v0.0\n" << endl;
	
	// Atribuir valores validos
	conteudo->setConteudo("1BCdeF");
	cout << conteudo->toString() << "convertido para minuscula: " << conteudo->toLowerCase() << endl;
	// encerrar
	pause("Apertar ENTER para continuar");
}//end method_06()

/* Method_07 - trocar ocorrencias de um caractere por outro */
void method_07(void){
	ref_Documentacao conteudo = new Documentacao();
	// identificar
	cout << "\nMethod_07 - v0.0\n" << endl;
	// Atribuir valores validos
	conteudo->setConteudo("Helena");
	char original = 'e';
	char novo = 'a';
	
	cout << conteudo->toString() << endl;
	cout << "Modificada: " << conteudo->replace(original, novo) << endl;
	
	// encerrar
	pause("Apertar ENTER para continuar");
}//end method_07()

/* Method_08 - cifra de cesar */
void method_08(void){
	ref_Documentacao conteudo = new Documentacao();
	// identificar
	cout << "\nMethod_08 - v0.0\n" << endl;
	// Atribuir valores validos
	conteudo->setConteudo("AbCdXYZ");
	
	cout << conteudo->toString() << endl;
	cout << "Codificada: " << conteudo->encrypt() << endl;
	
	// encerrar
	pause("Apertar ENTER para continuar");
}//end method_08()

/* Method_09 - decodificar o conteudo  */
void method_09(void){
	ref_Documentacao conteudo = new Documentacao();
	// identificar
	cout << "\nMethod_09 - v0.0\n" << endl;
	// Atribuir valores validos
	conteudo->setConteudo("DefGABC");
	
	cout << conteudo->toString() << endl;
	cout << "Decodificada: " << conteudo->decrypt() << endl;
	
	// encerrar
	pause("Apertar ENTER para continuar");
}//end method_09()

/* Method_10 - separar caracteres separados por espaços em branco */
void method_10(void){
	ref_Documentacao conteudo = new Documentacao();
	string sequencia[10];
	// identificar
	cout << "\nMethod_10 - v0.0\n" << endl;
	// Atribuir valores validos
	conteudo->setConteudo("Separar sequencia de caracteres.");
	int count = conteudo->split(sequencia);
	
	cout << "Split resultado: ";
	for (int i = 0; i < count; ++i) {
		cout << "\"" << sequencia[i] << "\" ";
	}
	cout << "\nCount: " << count << endl;
	
	// encerrar
	pause("Apertar ENTER para continuar");
}//end method_10()

/* EXTRAS */

/* Method_11 - testando sequencias com delimitador != espaco em branco*/
void method_11(void) {
	Documentacao conteudo;
	//identificar
	cout << "\nMethod_11 - v0.0\n" << endl;
	
	// Atribuir valores validos
	conteudo.setConteudo("Testando,sequencias,com delimitador.");
	cout << "" << conteudo.toString() << endl;
	conteudo.testDelimiter();
	
	// encerrar
	pause("Apertar ENTER para continuar");
}//end method_11()

/* Method_12 -  inverter a ordem dos símbolos na cadeia de caracteres.*/
void method_12(void) {
	Documentacao conteudo;
	//identificar
	cout << "\nMethod_12 - v0.0\n" << endl;
	
	// Atribuir valores validos
	conteudo.setConteudo("/*-+()");
	cout << "" << conteudo.toString() << endl;

	conteudo.testReverseString();
	// encerrar
	pause("Apertar ENTER para continuar");
}

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
		cout << "  0 - parar " << endl;
		cout << "  1 - 	    " << endl;
		cout << "  2 -       " << endl;
		cout << "  3 -       " << endl;
		cout << "  4 -       " << endl;
		cout << "  5 -       " << endl;
		cout << "  6 -       " << endl;
		cout << "  7 -       " << endl;
		cout << "  8 -       " << endl;
		cout << "  9 -       " << endl;
		cout << " 10 -       " << endl;
		cout << " 11 -       " << endl;
		cout << " 12 -       " << endl;
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
		case 9:
			method_09 ( );
			break;
		case 10:
			method_10();
			break;
		case 11:
			method_11();
			break;
		case 12:
			method_12();
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

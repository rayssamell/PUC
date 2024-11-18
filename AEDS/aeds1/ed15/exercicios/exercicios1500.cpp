/*
Exemplo1400 - v0.0. - 06 / 06 / 2024
Author: Rayssa Mell de Souza Silva - 860210
*/
// ----------------------------------------------- preparacao

// dependencias
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
		return ( NO_ERROR ); 
	} // end getErroMsg ( )	
}; // end classe MyString

// ----------------------------------------------- definicoes globais
using namespace std;
#define MAX_LENGTH 80
// ----------------------------------------------- metodos

/* Method_01 - acrescentar caractere ao final da cadeia */
void method_01(void){
	//identificar
	cout << "Method_01 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	char c;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Insira um caractere: ";
	cin >> c; getchar();
	//chamar funcao para adicionar caractere
	s = str.str_push_back(s, c);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_01()

/* Method_02 - remover caractere do final da cadeia */
void method_02(void){
	//identificar
	cout << "Method_02 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	MyString str;
	//alocar espaco
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	//chamar funcao para remover caractere
	s = str.str_pop_back(s);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_02()

/* Method_03 - Acrescentar Caractere no inicio da cadeia */
void method_03(void){
	//identificar
	cout << "Method_03 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	char c;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Insira um caractere: ";
	cin >> c; getchar();
	
	//chamar funcao para adicionar caractere
	s = str.str_push_front(c, s);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_03()

/* Method_04 - Remover Caractere no inicio da cadeia */
void method_04(void){
	//identificar
	cout << "Method_04 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();

	//chamar funcao para remover caractere
	s = str.str_pop_front(s);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_04()

/* Method_05 - Acrescentar Caractere no meio da cadeia */
void method_05(void){
	//identificar
	cout << "Method_05 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	char c;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Insira um caractere: ";
	cin >> c; getchar();
	
	//chamar funcao para adicionar caractere
	s = str.str_push_mid(s, c);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_05()

/* Method_06 - Remover Caractere do meio da cadeia */
void method_06(void){
	//identificar
	cout << "Method_06 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	//chamar funcao para remover caractere
	s = str.str_pop_mid(s);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_06()

/* Method_07 - Acrescentar Caractere em posicao valida */
void method_07(void){
	//identificar
	cout << "Method_07 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	char c;
	int index = 0;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Insira um caractere: ";
	cin >> c; getchar();
	
	cout << endl << "Insira a posicao: ";
	cin >> index; getchar();
	
	//chamar funcao para adicionar caractere
	s = str.str_insert(s, c, index);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_07()

/* Method_08 - remover caractere de posicao valida*/
void method_08(void){
	//identificar
	cout << "Method_08 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	int index = 0;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Insira a posicao: ";
	cin >> index; getchar();
	
	//chamar funcao para adicionar caractere
	s = str.str_remove(s, index);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_08()

/* Method_09 - Funcao para procurar primeira ocorrencia de certo simbolo */
void method_09(void){
	//identificar
	cout << "Method_09 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	char c;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Insira um caractere para buscar: ";
	cin >> c; getchar();
	
	//chamar funcao para adicionar caractere
	char* result = str.str_chr(s, c);
	
	if (result != nullptr) {
		cout << endl << "Primeira ocorrencia de '" << c << "' encontrada em: " << result << endl;
	} else {
		cout << endl << "Caractere '" << c << "' nao encontrado na cadeia." << endl;
		cout << str.getErroMsg() << endl;
	}
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_09()

/* Method_10 -  Funcao para separar caracteres ate' a ocorrencia de delimitador*/
void method_10(void){
	//identificar
	cout << "Method_10 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	char delimiter;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Insira um delimitador: ";
	cin >> delimiter; getchar();
	
	s = str.str_tok(s, delimiter);
	cout << endl << "" << s << endl;
	//liberar espaco
	free(s);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_10()

/* EXTRAS */

/* Method_11 - Funcao para procurar por certo prefixo */
void method_11(void){
	//identificar
	cout << "Method_11 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	char *prefix;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
    prefix = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Digite um prefixo para procurar: ";
	cin >> prefix; getchar();
	
	char *result = str.str_prefix(prefix, s);
	
	if (result != NULL) {
		cout << endl << "A string " << s << " inicia com o prefixo " << prefix << endl;
	} else {
		cout << "A string " << s << "nao inicia com o prefixo " << prefix << endl;
	}

	//liberar espaco
	free(s);
	free(prefix);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_11()

/* Method_12 - Funcao para procurar por certo sufixo  */
void method_12(void){
	//identificar
	cout << "Method_12 - v0.0." << endl;
	//definir dados
	char *s = nullptr;
	char *suffix;
	MyString str;
	//alocar tamanho
	s = (char*)malloc(MAX_LENGTH * sizeof(char));
	suffix = (char*)malloc(MAX_LENGTH * sizeof(char));
	//ler dados
	cout << endl << "Digite uma cadeia de caracteres: ";
	cin >> s; getchar();
	
	cout << endl << "Digite um sufixo para procurar: ";
	cin >> suffix; getchar();
	
	char *result = str.str_suffix(suffix, s);
	
	if (result != NULL) {
		cout << endl << "A string " << s << " termina com o sufixo " << suffix << endl;
	} else {
		cout << "A string " << s << "nao termina com o sufixo " << suffix << endl;
	}
	//liberar espaco
	free(s);
	free(suffix);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_12()

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

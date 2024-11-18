/*
Exercicios 1300 - v0.0. - 29 / 05 / 2024
Author: Rayssa Mell de Souza Silva - 860210
*/
// ----------------------------------------------- classes
#include "Contato.hpp" // classe para tratar dados de pessoas
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
  Method_01 - Atribuir valor a nome
 */
void method_01 ( )
{
	// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	// definir dados
	Contato contato1;
	cout << "Nome: ";
	contato1.testReadName ();
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02 - Atribuir valor a telefone.
 */
void method_02 ( )
{
	// identificar
	cout << "\nMethod_02 - v0.0\n" << endl;
	// definir dados
	Contato fone;
	//testar atribuicao
	cout << "Telefone: ";
	fone.testReadPhone();
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03 - Testar se o telefone e' valido
 */
void method_03 ( )
{
	// identificar
	cout << "\nMethod_03 - v0.0\n" << endl;
	//definir dado
	Contato fone;
	// testar atribuicoes
	cout << "Telefone: ";
	fone.testReadPhone();
	fone.testPhoneValid();

// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04 - Ler dados de arquivo
 */
void method_04 ( )
{
	// identificar
	cout << "\nMethod_04 - v0.0\n" << endl;
	//definir dados
	Contato contato1;
	// testar atribuicoes
	contato1.testReadArquivo("Pessoa1.txt");
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05 - Gravar dados em arquivo
 */
void method_05 ( )
{
	// identificar
	cout << "\nMethod_05 - v0.0\n" << endl;
	// definir dados
	Contato pessoa;
// testar atribuicoes
	cout << "Nome: ";
	pessoa.testReadName ();
	cout << endl << "Telefone: ";
	pessoa.testReadPhone ();
	pessoa.testPhoneValid();
	cout << endl;
	pessoa.testWriteFile("Pessoa2.txt");
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Method_06 - Adicionar um segundo telefone
 */
void method_06 ( )
{
	// identificar
	cout << "\nMethod_06 - v0.0\n" << endl;
	// definir dados
	ref_Contato contato1 = new Contato("Maria", "99999-1111", "98888-2222");
    // testar atribuicoes
	contato1->testarNovoTelefone();
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07 - Indicar quantidade de telefone associados
 */
void method_07 ( )
{
	// identificar
	cout << "\nMethod_07 - v0.0\n" << endl;
	// definir dados
	Contato contato1("Maria", "99999-1111", "98888-2222");
	Contato contato2("Bel",   "91845-8745", "");
	// testar atribuicoes
	contato1.testarNovoTelefone();
	cout << endl;
	contato2.testarNovoTelefone();
	int p1 = contato1.phones();
	int p2 = contato2.phones();
	cout << endl;
	cout << "Numero de telefones associados ao contato1: " << p1 << std::endl;
	cout << "Numero de telefones associados ao contato2: " << p2 << std::endl;
	// encerrar
	pause ( "Apertar ENTER para continuar" );

} // end method_07 ( )

/**
  Method_08 - Atribuir valor a segundo telefone
 */
void method_08 ( )
{
	// identificar
	cout << "\nMethod_08 - v0.0\n" << endl;
	// definir dados	
	Contato contato1("Jose", "99999-1111", ""); 
	string novoTelefone;
	
	char resposta;
	cout << "Deseja adicionar outro telefone para contato1? (S/N): ";
	cin >> resposta;
	
	if(resposta == 'S'){
		cout << "Digite o segundo telefone para contato1: ";
		cin >> novoTelefone;
		contato1.setFone2(novoTelefone);
		contato1.testarNovoTelefone();
	}
	else{
		contato1.testarNovoTelefone();
	}
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
  Method_09 - Alterar o valor apenas do segundo telefone
 */
void method_09 ( )
{
	// identificar
	cout << "\nMethod_09 - v0.0\n" << endl;
	
	// definir dados	
	Contato contato1("Jose", "99999-1111", "91458-7458"); 
	string novoTelefone;
	//testar atribuicoes
	cout << "contato1 - " << contato1.toString ( ) << endl;
	cout << "Digite o novo telefone para contato1: ";
	cin >> novoTelefone;
	
	if (contato1.phones() == 1) {
		contato1.setFone2(novoTelefone);
	} else {
		contato1.setFone2b(novoTelefone);
		cout << endl;
	}
	contato1.alterarTelefone();
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
  Method_10 - Remover apenas o valor do segundo telefone..
 */
void method_10 ( )
{
	// identificar
	cout << "\nMethod_11 - v0.0\n" << endl;
	//definir dado
	Contato contato1("Joao", "91234-5678", "94678-9090");
	//testar atribuicoes
	cout << "Antes de remover o segundo telefone: " << contato1.toString() << endl;
	
	contato1.removeFone();
	cout << "Depois de remover o segundo telefone: " << contato1.toString() << endl;
	// encerrar
	pause("Apertar ENTER para continuar");
} // end method_10 ( )

/**
  Method_11 - Testar adição e remocao de telefones.
 */
void method_11() {
	// identificar
	cout << "\nMethod_11 - v0.0\n" << endl;
	
	//definir dados
	Contato contato;
	
	// Adicionar alguns telefones
	contato.addTelefone("123456789");
	contato.addTelefone("987654321");
	contato.addTelefone("999999999");
	
	// Exibir os telefones
	contato.exibirTelefones();
	
	// Remover um telefone
	contato.removeTelefone("987654321");
	
	// Exibir os telefones novamente
	contato.exibirTelefones();

	// encerrar
	pause("Apertar ENTER para continuar");
} // end method_11()

/**
  Method_12 - Adicionar Enderecos
 */
void method_12(void) {
	// identificar
	cout << "\nMethod_12 - v0.0\n" << endl;
	//definir dado
	Contato contato("Joana", "91234-5678", "");
	//testar atribuicoes
	cout << " " << contato.toString() << endl;
	contato.setEnderecoResidencial("Avenida 31 de marco, 405.");
	contato.setEnderecoProfissional("Rua Bandeira, 31");
	
	contato.testarEnderecos();
	cout << endl;
	// encerrar
	pause("Apertar ENTER para continuar");
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
		cout << "EXEMPLO1300 - Programa - v0.0\n " << endl;
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
		cout << "  9         " << endl;
		cout << " 10         " << endl;
		cout << " 11         " << endl;
		cout << " 12         " << endl;
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
			method_10 ( );
			break;
		case 11:
			method_11 ( );
			break;
		case 12:
			method_12 ( );
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

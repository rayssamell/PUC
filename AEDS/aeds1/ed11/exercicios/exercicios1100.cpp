/*     Exercicios 1100 
Nome: Rayssa Mell de Souza Silva 
Matricula: 860210             */

//bibliotecas C++
#include <cstdio>
#include <cstdlib>
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
#include "myarray.hpp"

void pause ( std::string text )
{
	std::string dummy;
	std::cin.clear ( );
	std::cout << std::endl << text;
	std::cin.ignore( );
	std::getline(std::cin, dummy);
	std::cout << std::endl << std::endl;
} // end pause ( )

// ----------------------------------------------- metodos

/* Method_01 */
//funcao para gerar numeros aleatorio no intervalo
void randomIntGenerate(int inferior, int superior, Array <int>& array){
	int x = 0, y = 0;
	while(x < array.getLength()){
		y = rand() % (superior - inferior + 1) + inferior;
		array.set(x, y);
		x = x + 1;
	}
}//end randomIntGenerate()

void method_01(void){
	//identificar
	cout << endl << "Method_01 - Array de Intervalo" << endl;
	//definir dados
	int n;
	int inferior = 0, superior = 0;
	//ler dados
	cout << "Digite a quantidade: ";
	cin >> n;
	cout << endl;
	cout << "Digite o intervalo inferior: ";
	cin >> inferior;
	cout << endl;
	cout << "Digite o intervalo superior: ";
	cin >> superior;
	cout << endl;
	//array de n elementos comecando em 0
	Array <int> arranjo ( n, 0 );
	//chamar funcao
	randomIntGenerate(inferior, superior, arranjo);
	//imprimir resultado
	cout << "Array com valores dentro do intervalo:" << endl;
	arranjo.print();
	arranjo.fprint ( "DADOS.TXT" );
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}// end method_01()

/* Method_02 */
int searchFirstOdd ( Array<int>& arranjo){
	int maior = arranjo.get(0);
	int x = 0;
	for (int x = 0; x < arranjo.getLength(); ++x) {
		int y = arranjo.get(x);
		if(y % 2 == 0){
		    if(y > maior){
				maior = y;
			}		
		}
	}
	return (maior);
}//end searchFirstOdd()

void method_02(void){
	//identificar
	cout << endl << "Method_02 - Maior Par" << endl;
	//definir dado
	Array<int> arranjo(8, 0);
	//funcao para ler arquivo
	arranjo.fread ( "DADOS.TXT" );
	//funcao para procurar maior par
	int maior = searchFirstOdd(arranjo);
	//mostrar arranjo
	arranjo.print();
	//imprimir maior par
	cout << "Maior valor par: " << endl;
	cout << maior << endl;
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_02()

/* Method_03 */
int searchFirstOddx3(Array <int>& arranjo){
	int menor = arranjo.get(0);
	int y = 0;
	
	for(int x = 0; x < arranjo.getLength(); x = x + 1){
		if(arranjo.get(x) % 2 != 0){	
			if(menor > arranjo.get(x)){
				menor = arranjo.get(x);
			}
		}
	}
	return (menor);
}//end searchFirstOddx3

void method_03(void){
	//identificar
	cout << endl << "Method_03 - Menor Impar" << endl;
	//definir dado
	Array <int> arranjo(8, 0);
	//funcao para ler arquivo
	arranjo.fread("DADOS.TXT");
	//imprimir arranjo
	arranjo.print();
	//funcao para achar menor impar
	int menor = searchFirstOddx3(arranjo);
	cout << "Menor Impar:" << endl;
	cout << menor << endl;
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_03

/* Method_04 */
int addInterval(int inicio, int fim, Array<int>& arranjo){
	int val1 = arranjo.get(inicio);
	int val2 = arranjo.get(fim);
	
	int soma = val1 + val2;
	
	return (soma);
}//end addInterval()

void method_04(void){
	//identificar
	cout << endl << "Method_04 - Somar valores" << endl;
	//definir dados
	int inicio = 0, fim = 0;
	Array<int> arranjo(8,0);
	//ler arquivo
	arranjo.fread("DADOS.TXT");
	//ler dados
	cout << "Digite um valor de 0 a 7: ";
	cin >> inicio;
	cout << endl;
	cout << "Digite outro valor de 0 a 7: ";
	cin >> fim;
	cout << endl;
	//mostrar arranjo
	arranjo.print();
	//soma valores na posicoes inseridas e mostrar na tela
	int soma =  addInterval(inicio, fim, arranjo);
	cout << "Resultado da soma: ";
	cout << soma << endl;
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_04()

/* Method_05 */
double averageInterval(int inicio, int fim, Array<int>& arranjo){
	double media = 0.0;
	if(inicio >= 0 && fim >= 0 ){
		int val1 = arranjo.get(inicio);
		int val2 = arranjo.get(fim);
			
		media = (val1 + val2) / 2.0;	
	}
	
	return (media);
}//end averageInterval()

void method_05(void){
	//identificar
	cout << endl << "Method_05 - Calcular Media" << endl;
	//definir dados
	int inicio = 0, fim = 0;
	Array<int> arranjo(8,0);
	//ler arquivo
	arranjo.fread("DADOS.TXT");
	//ler dados
	cout << "Digite um valor de 0 a 7: ";
	cin >> inicio;
	cout << endl;
	cout << "Digite outro valor de 0 a 7: ";
	cin >> fim;
	cout << endl;
	//mostrar arranjo
	arranjo.print();
	//media dos valores nas posicoes inseridas e mostra na tela
	double media =  averageInterval(inicio, fim, arranjo);
	cout << "Resultado da Media: ";
	cout << media << endl;
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_05()

/* Method_06 */
bool negatives(Array<int>& arranjo){
	bool negativo = true;
	for(int x = 0; x < arranjo.getLength(); x = x + 1){
		if(arranjo.get(x) > 0){
			negativo = false;
		}
	}
	return (negativo);
}//end negatives()

void method_06(void){
	//identificar
	cout << endl << "Method_06 - Todos os elementos negativos. " << endl;
	//definir dado
	Array<int> arranjo(8,0);
	//ler arquivo
	arranjo.fread("DADOS1.TXT");
	//verificar se todos os elementos sao negativos
	bool teste = negatives(arranjo);
	cout << endl;
	if(teste){
		cout << "Todos os elementos sao negativos" << endl;
	}
	else{
		cout << "Os elementos nao sao todos negativos" << endl;
	}
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_06()

/* Method_07 */
bool isCrescent(Array<int>& arranjo){
	for (int x = 0; x < arranjo.getLength() - 1; x++) {
		if (arranjo.get(x) > arranjo.get(x + 1)) {
			return false;
		}
	}
	return true;
}//end isCrescent()

void method_07(void){
	//identificar
	cout << endl << "Method_07 - Ordem Crescente." << endl;
	//definir dado
	Array<int> arranjo(8,0);
	//ler arquivo
	arranjo.fread("DADOS1.TXT");
	//testar se esta ordenado
	bool teste = isCrescent(arranjo);
	arranjo.print();
	if(teste){
		cout << "O arranjo esta ordenado crescente." << endl;
	}
	else{
		cout << "O arranjo nao esta ordenado crescente." << endl;
	}
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_07()
  
/* Method_08 */
bool searchInterval(int inicio, int fim, int procurado, Array<int>& arranjo){
	for(int x = inicio; x < fim ; x = x + 1){
		if(procurado == arranjo.get(x)){
			return true;
		}
	}
	return false;
}//end searchInterval()

void method_08(void){
	//identificar
	cout << endl << "Method_08 - Procurar Valor." << endl;
	//definir dado
	Array<int> arranjo(8,0);
	int procurado = 0;
	int inicio = 0, fim = 0;
	//ler arquivo
	arranjo.fread("DADOS.TXT");
	//ler dados
	cout << "Digite um valor de 0 a 8: ";
	cin >> inicio;
	cout << endl << "Digite outro valor de 0 a 8: ";
	cin >> fim;
	cout << endl;
	cout << "Digite um valor para procurar: ";
	cin >> procurado;
	//chamar funcao pra buscar valor
	bool valor = searchInterval(inicio, fim, procurado, arranjo); 
	cout << endl << "Procurar por " << procurado << ": " << valor;   
	cout << endl;
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_08()

/* Method_09 */
int scalar(int inicio, int fim, Array<int>& arranjo, int constante, Array<int>& novo_array){
	int multiplicar = 0;
	for(int x = inicio; x < fim; x = x + 1){
		multiplicar = arranjo.get(x) * constante;
		novo_array.set(x - inicio, multiplicar);
	}
	return(multiplicar);
}//end scalar()

void method_09(void){
	//identificar 
	cout << endl << "Method_09 - Multiplicar arranjo em intervalo." << endl;
	//definir dado
	Array<int> arranjo(8,0);
	int constante = 0;
	int inicio = 0, fim = 0;
	//ler arquivo
	arranjo.fread("DADOS.TXT");
	//ler dado
	cout << "Digite um valor de 0 a 8: ";
	cin >> inicio;
	cout << endl << "Digite outro valor de 0 a 8: ";
	cin >> fim;
	cout << endl;
	cout << "Digite um valor: ";
	cin >> constante;
	cout << endl;
	//novo array para escala de valores
	Array<int> novo_array(fim - inicio, 0);
	//chamar funcao
	int multiplicar = scalar(inicio, fim, arranjo, constante, novo_array);
	cout << "Novo Arranjo: " << endl;
	for (int i = 0; i < novo_array.getLength(); i++) {
		cout << novo_array.get(i) << endl;
	}
	cout << endl;
	// reciclar espaco
	arranjo.free ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_09()

/* Method_10 */
void sortDown(Array<int>& arranjo, Array<int>& novo_array) {
	for (int i = 0; i < arranjo.getLength(); i++) {
		novo_array.set(i, arranjo.get(i));
	}
	
	for (int i = 0; i < arranjo.getLength() - 1; i++) {
		for (int j = 0; j < arranjo.getLength() - 1; j++) {
			if (novo_array.get(j) < novo_array.get(j + 1)) {
				int troca = novo_array.get(j);
				novo_array.set(j, novo_array.get(j + 1));
				novo_array.set(j + 1, troca);
			}
		}
	}
}

void method_10(void){
	// Identificar
	cout << endl << "Method_10 - Ordem Decrescente" << endl;
	// Definir e ler dados
	Array<int> arranjo(8, 0); 
	arranjo.fread("DADOS.TXT");
	Array<int> novo_array(8, 0);
	// Chamar função para ordenar
	sortDown(arranjo, novo_array);
	//mostrar arranjo original
	cout << "Arranjo Original: " <<endl;
	arranjo.print();
	// Mostrar dados ordenados
	cout << "Ordenado Decrescente: " <<endl;
	novo_array.print();
	cout << endl;
	// Reciclar espaço
	arranjo.free();
	// Encerrar
	pause("Apertar ENTER para continuar");
}//end method_10()

//---- Extras -----//

/* Method_11 */
bool diferenteArray (Array<int>& arranjo1, Array<int>& arranjo2){
	if(arranjo1.getLength() == arranjo2.getLength()){
		int x = 0;
		while(x < arranjo1.getLength()){
			if(arranjo1.get(x) != arranjo2.get(x)){
				return true; // retorna true se achar algum elemento diferente
			}
			x = x + 1;
		}	
	}
	return false;//retorna false se forem iguais
}//end diferenteArray()

void method_11(void){
	// Identificar
	cout << endl << "Method_11 - Arranjos Diferentes." << endl;
	//definir dados
	Array<int> arranjo1(8,0);
	Array<int> arranjo2(8,0);
	//ler arquivo
	arranjo1.fread("DADOS.TXT");
	arranjo2.fread("DADOS1.TXT");
	//chamar funcao para testar se sao diferentes
	bool teste = diferenteArray(arranjo1, arranjo2);
	if(teste){
		cout << endl << "Os arranjos sao diferentes" << endl;
	}
	else{
		cout << endl << "Os arranjos sao iguais" << endl;
	}
	// Reciclar espaço
	arranjo1.free();
	arranjo2.free();
	// Encerrar
	pause("Apertar ENTER para continuar");
}//end method_11()

/* Method_12 */
int diferencasArray (Array<int>& arranjo1, Array<int>& arranjo2){
	int contar = 0;
	if(arranjo1.getLength() == arranjo2.getLength()){
		for(int x = 0; x < arranjo1.getLength(); x = x + 1){
			if(arranjo1.get(x) != arranjo2.get(x)){
				contar++;
			}
		}
	}
	return (contar);
}//end diferencasArray()

void method_12(void){
	// Identificar
	cout << endl << "Method_12 - Contar diferencas entre Arranjos." << endl;
	//definir dados
	Array<int> arranjo1(8,0);
	Array<int> arranjo2(8,0);
	//ler arquivo
	arranjo1.fread("DADOS.TXT");
	arranjo2.fread("DADOS1.TXT");
	//chamar funcao para contar diferencas
	int contar = diferencasArray(arranjo1, arranjo2);
	cout << endl << "Quantidade de diferencas: " << contar << endl;
	// Reciclar espaço
	arranjo1.free();
	arranjo2.free();
	// Encerrar
	pause("Apertar ENTER para continuar");
}//end method_12()



int main (  ){
// definir dado
	int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
	do
	{
		// identificar
		cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << " 0 - parar " << endl;
		cout << " 1 - arranjo de intervalo            " << endl;
		cout << " 2 - maior par em arquivo            " << endl;
		cout << " 3 - menor impar em arquivo          " << endl;
		cout << " 4 - soma de valores de arquivo      " << endl;
		cout << " 5 - calcular media entre valores    " << endl;
		cout << " 6 - arranjo de negativos            " << endl;
		cout << " 7 - testar ordem crescente	      " << endl;
		cout << " 8 - buscar valor em intervalo	 	  " << endl;
		cout << " 9 - multiplicar valor por constante " << endl;
		cout << "10 - arranjo em ordem decrescente    " << endl;
		cout << "11 - arranjos diferentes		      " << endl;
		cout << "12 - contar diferencas  		      " << endl;
		// ler do teclado
		cout << endl << "Entrar com uma opcao: ";
		cin >> x;
		// escolher acao
		switch ( x )
		{
			case 1: method_01 ( ); break;
			case 2: method_02 ( ); break;
			case 3: method_03 ( ); break;
			case 4: method_04 ( ); break;
			case 5: method_05 ( ); break;
			case 6: method_06 ( ); break;
			case 7: method_07 ( ); break;
			case 8: method_08 ( ); break;
			case 9: method_09 ( ); break;
			case 10: method_10 ( ); break;
			case 11: method_11 ( ); break;
			case 12: method_12 ( ); break;
		default:
			cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )

import java.util.Scanner;
import java.util.Stack;

public class AlgebraBooleanaRecursiva {
    
    // Pilhas para auxiliar na resolução
    private Stack<Character> pilha;
    private Stack<Character> desempilhar;

    // Construtor
    public AlgebraBooleanaRecursiva() {
        this.pilha = new Stack<>();
        this.desempilhar = new Stack<>();
    }

    //metodo para inicializar funcao recursiva resolverExpressao
    public char resolverExpressao(String algebra, int[] valores) {
        char[] array = expressao(algebra, valores).toCharArray();
        return resolverExpressao(array, 0);
    }

    // Funcao recursiva para resolver a expressão booleana
    public char resolverExpressao(char[] array, int i) {
        char resultado = ' ';
        //caso base
        if (i == array.length) {
            resultado = this.pilha.pop();
        } else {
            char c = array[i];
            if (c == ')') {
                this.pilha.push(resolverSubexpressao());
            } else {
                this.pilha.push(c);
            }
            resultado = resolverExpressao(array, i + 1); // chamada recursiva
        }
        return resultado;
    }

    //funcao recursiva para resolver subexpressoes
    public char resolverSubexpressao() {
        char resultado = ' '; 

        if (!pilha.isEmpty()) {
            char c = pilha.pop();

            // Caso base: encontrou o parentese
            if (c == '(') {
                char operacao = pilha.pop();  // operação a ser executada (and, or, not)
                resultado = executarOperacao(operacao);
            } else {
                desempilhar.push(c);
                resultado = resolverSubexpressao(); // Chamada recursiva
            }
        }
        
        return resultado;
    }

    // Função auxiliar para executar a operação 'and', 'or', ou 'not'
    public char executarOperacao(char operacao) {
        char ch = ' '; 
        boolean temZero = false;
        boolean temUm = false;
		
		//se desempilhar tem dados
        if (!desempilhar.isEmpty()) {
            ch = desempilhar.pop();
            temZero = (ch == '0');
            temUm = (ch == '1');

            // Processa a subexpressao recursivamente
            if (!desempilhar.isEmpty()) {
                char proximo = executarOperacao(operacao);
                temZero = temZero || (proximo == '0');
                temUm = temUm || (proximo == '1');
            }

            switch (operacao) {
                case 'a': // and
                    ch = temZero ? '0' : '1';
                    break;
                case 'o': // or
                    ch = temUm ? '1' : '0';
                    break;
                case 'n': // not
                    ch = temZero ? '1' : '0';
                    break;
            }
        }
        return ch;
    }

    // metodo para inicializar a chamada expressaoRecursiva
    public String expressao(String algebra, int[] valores) {
        return expressaoRecursiva(algebra, valores, 0);
    }

    // Formatar a expressao de forma recursiva
    public String expressaoRecursiva(String algebra, int[] valores, int i) {
        String resultado = ""; 
        //caso base
        if (i >= algebra.length()) {
            resultado = "";
        } else {
            char c = algebra.charAt(i);
            int verificar = c - 'A';

            if (c == 'a' || c == 'n') {
                resultado = c + expressaoRecursiva(algebra, valores, i + 3); // pula "and" ou "not"
            } else if (c == 'o') {
                resultado = c + expressaoRecursiva(algebra, valores, i + 2); // pula "or"
            } else if (verificar >= 0 && verificar < valores.length) {
                char valorConvertido = (char) (valores[verificar] + '0');
                resultado = valorConvertido + expressaoRecursiva(algebra, valores, i + 1);
            } else if (c != ',') { // se encontra virgula
                resultado = c + expressaoRecursiva(algebra, valores, i + 1);
            } else {
                resultado = expressaoRecursiva(algebra, valores, i + 1);
            }
        }
        return resultado;
    }

    //funcao para dividir a string e mostrar o resultado da expressao booleana
       public static void expressaoBooleana(String expressao) {
        int n = expressao.charAt(0) - '0';
        int[] valores = new int[n];
        String algebra = "";

        int index = 2;
        for (int i = 0; i < n; i++) {
            valores[i] = expressao.charAt(index) - '0';  
            index += 2;
        }

        for (int i = index; i < expressao.length(); i++) {
            if (expressao.charAt(i) != ' ') {
                algebra += expressao.charAt(i);
            }
        }

        AlgebraBooleanaRecursiva algebraBooleana = new AlgebraBooleanaRecursiva();
        char resultado = algebraBooleana.resolverExpressao(algebra, valores);  
        System.out.println(resultado);
    }

	//metodo principal
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in, "UTF-8");
        String expressao = sc.nextLine();

        while (expressao.charAt(0) != '0') {
            expressaoBooleana(expressao);
            expressao = sc.nextLine();
        }

        sc.close();
    }
}

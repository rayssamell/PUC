import java.util.Scanner;
import java.util.Stack;

public class AlgebraBooleana {
    
    //pilhas para auxiliar na resolucao
    private Stack<Character> pilha;
    private Stack<Character> desempilhar;

    //construtor
    public AlgebraBooleana() {
        this.pilha = new Stack<>();
        this.desempilhar = new Stack<>();
    }

    //funcao para resolver a expresssao booleana
    public char resolverExpressao(String algebra, int[] valores) {
        //formata a expressao
        char[] array = expressao(algebra, valores).toCharArray();

        for (int i = 0; i < array.length; i++) {
            char c = array[i];
            // se encontrar um ) chama a funcao para resolver a subexpressao
            if (c == ')') {
                this.pilha.push(resolverSubexpressao());
            } else {
                // caso contrario empilha o resultado
                this.pilha.push(c);
            }
        }
        return this.pilha.pop();
    }

    // Resolver uma subexpressao
    public char resolverSubexpressao() {
        char c = this.pilha.pop();
        
        while (c != '(') {
            desempilhar.push(c);
            c = this.pilha.pop();  // continua desempilhando ate encontrar '('
        }

        c = this.pilha.pop();  // operacao a ser executada (and, or, not)

         
        boolean temZero = false;
        boolean temUm = false;

        // Processa a subexpressao
        while (!desempilhar.isEmpty()) {
            char ch = desempilhar.pop();
            if (ch == '0') {
                temZero = true;
            } else if (ch == '1') {
                temUm = true;
            }
        }

        switch (c) {
            case 'a': // and
                c = temZero ? '0' : '1';
                break;
            case 'o': // or
               c = temUm ? '1' : '0';
                break;
            case 'n': // not
                c = temZero ? '1' : '0';
                break;
        }

        return c;
    }

    // Formatar a expressao
    public String expressao(String algebra, int[] valores) {
        String resultado = ""; 
        int i = 0;

        while (i < algebra.length()) {
            char c = algebra.charAt(i);
            int verificar = c - 'A';

            if (c == 'a' || c == 'n') {
                resultado += c;
                i += 3; // pula "and" ou "not"
            } else if (c == 'o') {
                resultado += c;
                i += 2; // pula "or"
            } else if (verificar >= 0 && verificar < valores.length) {
                resultado += (char) (valores[verificar] + '0');
                i++;
            } else if (c != ',') {
                resultado += c;
                i++;
            } else {
                i++;
            }
        }

        return resultado;
    }


    public static void expressaoBooleana(String expressao) {
        int n = expressao.charAt(0) - '0';
        int[] valores = new int[n];
        String algebra = "";

        int index = 2;
        for (int i = 0; i < n; i++) {
            valores[i] = expressao.charAt(index) - '0';  // valor numerico
            index += 2;
        }

        for (int i = index; i < expressao.length(); i++) {
            if (expressao.charAt(i) != ' ') {
                algebra += expressao.charAt(i);
            }
        }

        AlgebraBooleana algebraBooleana = new AlgebraBooleana();
        char resultado = algebraBooleana.resolverExpressao(algebra, valores);  
        System.out.println(resultado);
    }

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

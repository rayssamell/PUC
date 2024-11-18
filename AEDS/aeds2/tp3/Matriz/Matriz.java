/**
 * @path TP03Q11 - Matriz Dinamica em java
 * @author Rayssa Mell de Souza Silva
 */

import java.util.Scanner;

public class Matriz {
    private Celula inicio;
    private int linha, coluna;

    //Construtor Padrao
    public Matriz (){
        inicio = null;
        linha = 3;
        coluna = 3;
        criarMatriz();
    }

    //Construtor com atribuicao
    public Matriz (int linha, int coluna){
        this.linha = linha;
        this.coluna = coluna;
        criarMatriz();
    }

    //Metodo para criar a matriz e conectar as celulas
    private void criarMatriz() {
        // Primeira Celula da Matriz
        this.inicio = new Celula();
        Celula linhaAtual = this.inicio;
    
        // Primeiras celulas de cada linha
        for (int i = 0; i < linha - 1; i++) {
            Celula novaLinha = new Celula();
            linhaAtual.inf = novaLinha;
            novaLinha.sup = linhaAtual;
            linhaAtual = novaLinha;
        }
    
        // Conectar as celulas horizontalmente e verticalmente
        Celula linhaTemp = this.inicio;
        while (linhaTemp != null) {
            Celula colunaAtual = linhaTemp;
            for (int j = 1; j < coluna; j++) {
                Celula novaColuna = new Celula();
                colunaAtual.dir = novaColuna;
                novaColuna.esq = colunaAtual;
                if (colunaAtual.sup != null) {
                    novaColuna.sup = colunaAtual.sup.dir;
                    colunaAtual.sup.dir.inf = novaColuna;
                }
                colunaAtual = novaColuna;
            }
            linhaTemp = linhaTemp.inf;
        }
    }

    //Funcao para preencher as celulas da matriz
    public void preencher(int[][] valores) {
        // Começa pela célula inicial
        Celula linhaAtual = inicio;
    
        for (int i = 0; i < linha; i++) {
            Celula atual = linhaAtual;
            
            // Preenche cada celula na linha com os valores fornecidos
            for (int j = 0; j < coluna; j++) {
                if (atual != null) {
                    atual.elemento = valores[i][j];  
                    atual = atual.dir;  
                }
            }
            linhaAtual = linhaAtual.inf;  
        }
    }

    //Funcao para somar duas matrizes
    public Matriz soma (Matriz m) {
        Matriz resp = null;

        if(this.linha == m.linha && this.coluna == m.coluna){
            //matriz resultante
            resp = new Matriz(this.linha, this.coluna);
            
            Celula l1 = this.inicio, l2 = m.inicio, l3 = resp.inicio;

            for (int i = 0; i < linha; i++) {
                Celula a = l1, b = l2, c = l3;
                for (int j = 0; j < coluna; j++) {
                    //soma os elementos das duas matrizes
                    c.elemento = a.elemento + b.elemento; 
                    a = a.dir;
                    b = b.dir;
                    c = c.dir;
                }
                l1 = l1.inf;
                l2 = l2.inf;
                l3 = l3.inf;
            }
        }
        //retorna a matriz resultante
        return resp;
    }

    //Funcao para multiplicar matrizes
    public Matriz multiplicacao(Matriz m) {
        Matriz resp = null;
    
        if (this.coluna == m.linha) {
            //matriz resultante
            resp = new Matriz(this.linha, m.coluna);
    
            // percorrer as linhas da matriz resultante
            Celula linhaResp = resp.inicio;
            for (Celula l1 = this.inicio; l1 != null; l1 = l1.inf, linhaResp = linhaResp.inf) {
                Celula colResp = linhaResp;
    
                // Percorre cada coluna da matriz "m"
                for (Celula col2Inicial = m.inicio; col2Inicial != null; col2Inicial = col2Inicial.dir, colResp = colResp.dir) {
                    int soma = 0;
                    Celula l2 = col2Inicial;
                    Celula col1 = l1;
    
                    // Calcula o valor para a celula da matriz resposta
                    while (col1 != null && l2 != null) {
                        soma += col1.elemento * l2.elemento;
                        col1 = col1.dir;
                        l2 = l2.inf;
                    }
    
                    // Atribui o valor calculado a celula da matriz resposta
                    colResp.elemento = soma;
                }
            }
        }
        return resp;
    }
    

    //Funcao para verificar se a matriz e quadrada
    public boolean isQuadrada(){
        return (this.linha == this.coluna);
    }

    //Metodo para mostrar a diagonal principal da matriz
    public void mostrarDiagonalPrincipal (){
        if(isQuadrada() == true){
            Celula primeiro = inicio;
            for (int i = 0; i < linha; i++){
                Celula tmp = primeiro;
                for (int j = 0; j < coluna; j++){
                    if (i == j) {
                        System.out.print(tmp.elemento + " ");
                    }
                    tmp = tmp.dir;
                }
                primeiro = primeiro.inf;
            }
            System.out.println();        
        }
    }

    //Metodo para mostrar a diagonal secundaria da matriz
    public void mostrarDiagonalSecundaria (){
        if(isQuadrada() == true){
            Celula primeiro = inicio;
            for (int i = 0; i < linha; i++){
                Celula tmp = primeiro;
                for (int j = 0; j < coluna; j++) {
                    if (j == coluna - 1 - i){
                       System.out.print(tmp.elemento + " ");
                    }
                    tmp = tmp.dir;
                }
                primeiro = primeiro.inf;
            }        
            System.out.println(); 
        }
    }

    // Metodo para imprimir a matriz
    public void imprimir() {
        Celula linhaAtual = inicio;
        while (linhaAtual != null) {
            Celula atual = linhaAtual;
            while (atual != null) {
                System.out.print(atual.elemento + " ");
                atual = atual.dir;
            }
            System.out.println();
            linhaAtual = linhaAtual.inf;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int l1, l2, col1, col2; 

        //quantidade de casos de teste
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 1; i <= n; i++) {
            //Matriz 1
            l1 = sc.nextInt();
            col1 = sc.nextInt();
            Matriz m1 = new Matriz(l1, col1);
            int[][] valores1 = new int[l1][col1];
            for (int j = 0; j < l1; j++) {
                for (int k = 0; k < col1; k++) {
                    valores1[j][k] = sc.nextInt();
                }
            }
            m1.preencher(valores1);

            //Matriz 2
            l2 = sc.nextInt();
            col2 = sc.nextInt();
            Matriz m2 = new Matriz(l2, col2);
            int[][] valores2 = new int[l2][col2];
            for (int j = 0; j < l2; j++) {
                for (int k = 0; k < col2; k++) {
                    valores2[j][k] = sc.nextInt();
                }
            }
            m2.preencher(valores2);

            //Chamar funcoes para mostrar diagonal principal e secundaria da matriz 1
            m1.mostrarDiagonalPrincipal();
            m1.mostrarDiagonalSecundaria();

            //Chamar funcao para somar as matrizes
            Matriz resultadoSoma = m1.soma(m2);
            resultadoSoma.imprimir();
            
            //Chamar funcao para multiplicar as matrizes
            Matriz resultadoMultiplicacao = m1.multiplicacao(m2);
            resultadoMultiplicacao.imprimir();
        }
        sc.close();
    }
}

class Celula {
    public int elemento;
    public Celula inf, sup, esq, dir;
 
    public Celula(){
       this(0);
    }
 
    public Celula(int elemento){
       this(elemento, null, null, null, null);
    }
 
    public Celula(int elemento, Celula inf, Celula sup, Celula esq, Celula dir){
       this.elemento = elemento;
       this.inf = inf;
       this.sup = sup;
       this.esq = esq;
       this.dir = dir;
    }
 }
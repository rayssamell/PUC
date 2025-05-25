import java.util.ArrayList;
import java.util.Scanner;

public class Olimpiadas {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        TabelaHash m = new TabelaHash(300);

        while(sc.hasNext()){
            String modalidade = sc.nextLine();
            String ouro = sc.nextLine();
            String prata = sc.nextLine();
            String bronze = sc.nextLine();

            m.inserir(ouro, 0);
            m.inserir(prata, 0);
            m.inserir(bronze, 0);
        }

        m.mostrar();
        sc.close();
    }
}

class Quadro {
    public String key;
    public int[] valores;

    public Quadro(String key){
        this.key = key;
        this.valores = new int[3];
    }

    public void adicionarMedalha(int tipo) {
        valores[tipo]++;
    }
}

class TabelaHash {
    private Lista[] tabela; // Array de listas para tratar colisões
    private int tamanho;

    public TabelaHash(int capacidade) {
        tabela = new Lista[capacidade];
        tamanho = 0;

        // Inicializa as listas
        for (int i = 0; i < capacidade; i++) {
            tabela[i] = new Lista();
        }
    }

    // Função hash (baseada no comprimento da string e tamanho da tabela)
    private int hash(int tam) {
        return tam % tabela.length;
    }

    // Insere ou atualiza o país na tabela
    public void inserir(String key, int tipoMedalha) {
        int indice = hash(key.length());
        Lista lista = tabela[indice];

        Quadro quadro = lista.buscar(key);
        if (quadro == null) {
            // País não existe, cria um novo
            quadro = new Quadro(key);
            lista.inserir(quadro);
            tamanho++;
        }

        // Atualiza a medalha correspondente
        quadro.adicionarMedalha(tipoMedalha);
    }

    // Exibe o quadro de medalhas ordenado
    public void mostrar() {
        ArrayList<Quadro> todos = new ArrayList<>();

        // Coleta todos os quadros da tabela
        for (Lista lista : tabela) {
            todos.addAll(lista.getTodos());
        }

        // Ordena pelo número de ouros, pratas, bronzes e nome do país
        todos.sort((a, b) -> {
            if (a.valores[0] != b.valores[0]) return Integer.compare(b.valores[0], a.valores[0]); // Ouro
            if (a.valores[1] != b.valores[1]) return Integer.compare(b.valores[1], a.valores[1]); // Prata
            if (a.valores[2] != b.valores[2]) return Integer.compare(b.valores[2], a.valores[2]); // Bronze
            return a.key.compareTo(b.key); // Nome
        });

        // Exibe o resultado
        System.out.println("Quadro de Medalhas");
        for (Quadro quadro : todos) {
            System.out.printf("%s %d %d %d%n", quadro.key, quadro.valores[0], quadro.valores[1], quadro.valores[2]);
        }
    }
}

// Classe para tratar colisões com lista encadeada
class Lista {
    private ArrayList<Quadro> elementos;

    public Lista() {
        elementos = new ArrayList<>();
    }

    // Busca um quadro pelo nome do país
    public Quadro buscar(String key) {
        for (int i=0; i < elementos.size(); i++) {
            Quadro quadro = elementos.get(i);
            if (quadro.key.equals(key)) { 
                return quadro;
            }
        }
        return null; // Não encontrado
    }

    // Insere um novo quadro na lista
    public void inserir(Quadro quadro) {
        elementos.add(quadro);
    }

    // Retorna todos os elementos da lista
    public ArrayList<Quadro> getTodos() {
        return elementos;
    }
}
/**
 * @path TP03Q010 - Lista Sequencial em Java
 * @author Rayssa Mell de Souza Silva
 */

//-------------- imports
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class Quicksort {
    private int comparacoes;
    private int movimentacoes;

    //Construtor
    public Quicksort(){
        comparacoes = 0;
        movimentacoes = 0;
    }

    // Retorna o timestamp atual
	public long now(){
		return new Date().getTime();
	}

    // Gravar no arquivo tempo de execucao e numero de movimentacoes
    public void gravarArquivo (double inicio, double fim) {
        
        try (BufferedWriter buffWrite = new BufferedWriter(new FileWriter("matricula_quicksort3.txt"))) {
            double tempo = (fim - inicio) / 1000.0;  // Converte para segundos

            // Cria a string a ser gravada no arquivo
            String linha = "Matricula: 860210 \t" +
                           "Tempo de Execução: " + tempo + " s\t" +
                           "Número de Comparacoes: " + comparacoes + "\t" +
                           "Número de Movimentações: " + movimentacoes + "\t";

            // Escreve no arquivo
            buffWrite.write(linha);

        } catch (IOException e) {
            System.err.println("Erro ao gravar o arquivo: " + e.getMessage());
        }
    }

    //----------------- Metodo Principal
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        double inicio, fim;
        Quicksort quicksort = new Quicksort();

        GerenciadorPokemons gp = new GerenciadorPokemons();
        gp.ler(); // ler do arquivo

        ListaDupla lista = new ListaDupla(); 
        String line;
        Pokemon pk = new Pokemon(); 

        while(!(line = sc.next()).equals("FIM")){
            int id = Integer.parseInt(line); //ler id
            pk = gp.buscarPokemon(id); //buscar pokemon do id
            lista.inserirFim(pk); //inserir na lista
        }
        
        // Tempo de execucaoo
        inicio = quicksort.now();
        quicksort.quicksort(lista);
        fim = quicksort.now();
        quicksort.gravarArquivo(inicio, fim);

        lista.print(); //mostrar lista

        sc.close();
    }

    //Buscar celula do meio da lista encadeada
    CelulaDupla buscarMeio(CelulaDupla esq, CelulaDupla dir) {
        CelulaDupla cel = esq;
        int count = 0;
    
        // Contar o numero de celulas entre 'esq' e 'dir'
        while (cel != null && cel != dir) {
            count++;
            cel = cel.prox;
        }
    
        // encontrar a celula do meio
        cel = esq;
        for (int i = 0; i < count / 2; i++) {
            if (cel != null) {
                cel = cel.prox;
            }
        }
    
        return cel; // Retorna a celula
    }

    //---------- --------- Swap para ordenacao
    void swap(CelulaDupla i, CelulaDupla j) {
        Pokemon temp = i.pokemon;
        i.pokemon = j.pokemon;
        j.pokemon = temp;
    }

    //-------- Ordenacao por Quicksort - Generation ou Name
    private void quicksort(CelulaDupla esq, CelulaDupla dir) {
        if (esq == null || dir == null || esq == dir || esq == dir.prox) return;
    
        CelulaDupla i = esq;
        CelulaDupla j = dir;
    
        // Seleciona o pivo para geracao e nome
        CelulaDupla meio = buscarMeio(esq, dir);
        String pivoNome = meio.pokemon.getName(); 
        int pivo = meio.pokemon.getGeneration(); 
    
        while (i != null && j != null && i != j && i != j.prox) {
            // Comparacao por geração e, se igual, por nome
            while (i.pokemon.getGeneration() < pivo || 
                  (i.pokemon.getGeneration() == pivo && i.pokemon.getName().compareTo(pivoNome) < 0)) { 
                i = i.prox;
                comparacoes++;
            }
    
            while (j.pokemon.getGeneration() > pivo || 
                  (j.pokemon.getGeneration() == pivo && j.pokemon.getName().compareTo(pivoNome) > 0)) {
                j = j.ant;
                comparacoes++;
            }
    
            if (i != null && j != null && i != j && i != j.prox) {
                swap(i, j); //swap para troca
                movimentacoes += 3;  // Contar 3 movimentações para o swap
            }
        }
    
        // Chamadas recursivas para as partes esquerda e direita
        if (esq != j && j != null) quicksort(esq, j.ant);
        if (i != dir && i != null) quicksort(i.prox, dir);
    }

    //Chamada para recursividade
    public void quicksort(ListaDupla lista) {
        quicksort(lista.primeiro.prox, lista.ultimo);
    }
}

//------------------- Classe LISTA DUPLA ---------------------//
class ListaDupla {
    public CelulaDupla primeiro;
    public CelulaDupla ultimo;
    public int n; //tamanho

    //formatador de data
    SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");

    //Construtor Padrao
    public ListaDupla() {
		primeiro = new CelulaDupla();
		ultimo = primeiro;
	}

    public void inserirFim(Pokemon pk) {
		ultimo.prox = new CelulaDupla(pk);
        ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox;
        n++;
	}

    //---------------------- Metodo Imprimir
    public void print(){
        for(CelulaDupla i=primeiro.prox; i !=null; i=i.prox){
            System.out.println("[#" 
                            + i.pokemon.getId() + " -> " 
                            + i.pokemon.getName() + ": " 
                            + i.pokemon.getDescription() + " - " 
                            + i.pokemon.getTypes() + " - " 
                            + i.pokemon.getAbilities()  + " - " 
                            + i.pokemon.getWeight() + "kg - " 
                            + i.pokemon.getHeight() + "m - "  
                            + i.pokemon.getCaptureRate() + "% - "  
                            + i.pokemon.getIsLegendary() + " - "  
                            + i.pokemon.getGeneration() + " gen] - "  
                            + (formatter.format(i.pokemon.getCaptureDate())));
        }
    }
}

//------------------- Classe Celula ---------------------//
class CelulaDupla {
    public Pokemon pokemon;
    public CelulaDupla prox;
    public CelulaDupla ant;

    public CelulaDupla() {
		this(null);
	}

    public CelulaDupla(Pokemon pokemon){
        this.pokemon = pokemon;
        this.prox = null;
        this.ant = null;
    }
}

//------------------- Classe POKEMON ---------------------//
class Pokemon {
    //atributos
    private int id;
    private int generation;
    private String name;
    private String description;
    private ArrayList<String> types;
    private ArrayList<String> abilities;
    private double weight;
    private double height;
    private int captureRate;
    private boolean isLegendary;
    private Date captureDate;
    
    //Construtor com valores vazios
    public Pokemon(){
        id = 0;
        generation = 0;
        name = "";
        description = "";
        types = new ArrayList<>();
        abilities = new ArrayList<>();
        weight = 0.0;
        height = 0.0;
        captureRate = 0;
        isLegendary = false;
        captureDate = new Date();
    }

    //Construtor com atribuicao de valores
    public Pokemon(int id, int generation, String name, String description, ArrayList<String> types, ArrayList<String> abilities, 
                   double weight, double height, int captureRate, boolean isLegendary, Date captureDate){
        this.id = id;
        this.generation = generation;
        this.name = name;
        this.description = description;
        this.types = types;
        this.abilities = abilities;
        this.weight = weight;
        this.height = height;
        this.captureRate = captureRate;
        this.isLegendary = isLegendary;
        this.captureDate = captureDate;
    }

    //----------------- Metodos get e set
    public int getId(){
        return id;
    }
    public void setId(int id){
        this.id = id;
    }
    public int getGeneration(){
        return generation;
    }
    public void setGeneration(int generation){
        this.generation = generation;
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    public String getDescription(){
        return description;
    }
    public void setDescription(String description){
        this.description = description;
    }
    public ArrayList<String> getTypes(){
        return types; 
    }
    public void setTypes(ArrayList<String> types){
        this.types = new ArrayList<>(types); 
    }
    public ArrayList<String> getAbilities(){
        return abilities;
    }
    public void setAbilities(ArrayList<String> abilities){
        this.abilities = new ArrayList<>(abilities); 
    }
    public double getWeight(){
        return weight;
    } 
    public void setWeight(double weight){
        this.weight = weight;
    }
    public double getHeight(){
        return height;
    }
    public void setHeight(double height){
        this.height = height;
    }
    public int getCaptureRate(){
        return captureRate;
    }
    public void setCaptureRate(int captureRate){
        this.captureRate = captureRate;
    }
    public boolean getIsLegendary(){
        return isLegendary;
    }
    public void setIsLegendary(boolean isLegendary){
        this.isLegendary = isLegendary;
    }
    public Date getCaptureDate(){
        return captureDate;
    }
    public void setCaptureDate(Date captureDate){
        this.captureDate = captureDate;
    }

    //---------------------- Metodo Clone
    @Override
    public Pokemon clone(){ 
        try {
            return (Pokemon) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new AssertionError(e);
        }
    }
}

//------------------- Classe para Gerenciar Pokemons ------------//
class GerenciadorPokemons {
    //Lista para pokemons lidos do arquivo
    private List<Pokemon> pokemons = new ArrayList<>(801);

    //caminho para arquivo
    private static final String FILE_PATH = "/tmp/pokemon.csv";
    //formatador de data
    SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");

    //----------------------- Metodo para Ler Pokemons do arquivo e guardar na lista 
    public void ler() { 
        // leitura do arquivo
        try (BufferedReader br = new BufferedReader(new FileReader(FILE_PATH))) {
            
            String linha;
            int linhaCont = 0;

            while ((linha = br.readLine()) != null) {
                linhaCont++;
                // pula linha de atribuicoes
                if(linhaCont > 1){
                    // array de string com a linha separada por virgula e []
                    String[] partes = linha.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
                    Pokemon pokemon = new Pokemon();

                    // tratar dados 
                    for(int i = 1; i < partes.length; i++){
                        // se algum atributo for vazio coloca 0
                        if(partes[i].isEmpty()){
                            partes[i] = "0";
                        } 

                        pokemon.setId(Integer.parseInt(partes[0]));
                        pokemon.setGeneration(Integer.parseInt(partes[1]));
                        pokemon.setName(partes[2]);
                        pokemon.setDescription(partes[3]);

                        //---- TYPES -----//
                        ArrayList<String> types = new ArrayList<>();
                        String type1 = "'" + partes[4].trim() + "'";
                        types.add(type1);

                        // se o segundo tipo nao for vazio
                        if (!partes[5].equals("0")) {
                            String type2 = "'" + partes[5].trim()+ "'";
                            types.add(type2);
                        }
                        pokemon.setTypes(types);

                        // ----- Abilities -----//
                        ArrayList<String> abilities = new ArrayList<>();
                        String ability = "";

                        for(int j=0; j < partes[6].length(); j++){
                            char character = partes[6].charAt(j);
                            if (character != '\"' && character != '[' && character != ']') {
                                // Se encontrar uma virgula, a habilidade foi capturada
                                if (character == ',') {
                                    if (!ability.isEmpty()) {
                                        abilities.add(ability.trim());  // Adiciona a habilidade a lista
                                        ability = ""; // Limpa para capturar a próxima habilidade
                                    }
                                } else {
                                    ability += character;
                                }
                            }
                        }
                        if(!ability.equals("0")){
                            abilities.add(ability.trim()); 
                        }
                        pokemon.setAbilities(abilities);

                        //------ Adicionando demais dados ----///
                        pokemon.setWeight(partes[7].isEmpty() ? 0.0 : Double.parseDouble(partes[7]));
                        pokemon.setHeight(partes[8].isEmpty() ? 0.0 : Double.parseDouble(partes[8]));
                        pokemon.setCaptureRate(Integer.parseInt(partes[9]));
                        
                        int valorLido = Integer.parseInt(partes[10]);
                        pokemon.setIsLegendary(valorLido == 1);
                        
                        // tratar data
                        try {
                            Date data = formatter.parse(partes[11]);
                            pokemon.setCaptureDate(data);
                        } catch (ParseException e) {
                            e.printStackTrace(); 
                        }

                        // adiciona o pokemon a lista 
                        pokemons.add(pokemon);
                    }
                } 
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //--------------------------- Metodo para inserir pokemon do ID indicado
    public Pokemon buscarPokemon(int id) {
        Pokemon pk = new Pokemon();
        for (int i = 0; i < pokemons.size(); i++) {
            Pokemon pok = pokemons.get(i);  // Obtem o Pokemon na posição i
            if (pok.getId() == id) {
                pk = pok;  // captura os dados do Pokémon encontrado
                i = pokemons.size(); // sai do loop
            }
        }
        return pk; // retorna pokemon encontrado
    }

    public List<Pokemon> getPokemons() {
        return pokemons;
    }
}
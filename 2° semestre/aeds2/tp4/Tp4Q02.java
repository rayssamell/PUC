/**
 * @path TP04Q02 - Arvore Binaria de Arvores Binarias
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

public class Tp4Q02 {
    //----------------- Metodo Principal
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        double tempoTotal = 0.0;

        GerenciadorPokemons gp = new GerenciadorPokemons();
        gp.ler(); // ler do arquivo

        Log log = new Log(); //gravar tempo e comparacoes
        Arvore arvore = new Arvore(log); 
        Pokemon pk = new Pokemon(); 

        String line;
        
        while(!(line = sc.next()).equals("FIM")){
            int id = Integer.parseInt(line); //ler id
            pk = gp.buscarPokemon(id); //buscar pokemon do id
            arvore.inserir(pk); //inserir na arvore
        }

        sc.nextLine();
        while(!(line = sc.nextLine()).equals("FIM")){
            System.out.println("=> " + line);

            double inicio = log.now();
            boolean resp = arvore.pesquisar(line);
            double fim = log.now();

            //calcular tempo de execucao
            tempoTotal += (fim - inicio);

            if(resp) System.out.println(" SIM");
            else System.out.println(" NAO");
        }
        //gravar no arquivo
        log.gravarArquivo(tempoTotal, log.comparacoes);

        sc.close();
    }
}
// Classe para arquivo de log
class Log {
    public int comparacoes;

    //Construtor
    public Log(){
        comparacoes = 0;
    }

    public void contarComparacoes() {
        comparacoes++;
    }

    // Retorna o timestamp atual
	public long now(){
		return new Date().getTime();
	}

    // Gravar no arquivo tempo de execucao e numero de movimentacoes
    public void gravarArquivo (double tempoTotal, int comparacoes) {
        
        try (BufferedWriter buffWrite = new BufferedWriter(new FileWriter("matricula_arvoreArvore.txt"))) {
            double tempo = tempoTotal / 1000.0;  // Converte para segundos

            // Cria a string a ser gravada no arquivo
            String linha = "Matricula: 860210 \t" +
                           "Tempo de Execução: " + tempo + " s\t" +
                           "Número de Comparacoes: " + comparacoes + "\t";

            // Escreve no arquivo
            buffWrite.write(linha);

        } catch (IOException e) {
            System.err.println("Erro ao gravar o arquivo: " + e.getMessage());
        }
    }
}

//------------------- Classe Arvore ---------------------//
class Arvore {
    private No raiz; 
    private Log log;

    public Arvore(Log log) throws Exception {
        raiz = null;
        inserir(7);
        inserir(3);
        inserir(11);
        inserir(1);
        inserir(5);
        inserir(9);
        inserir(13);
        inserir(0);
        inserir(2);
        inserir(4);
        inserir(6);
        inserir(8);
        inserir(10);
        inserir(12);
        inserir(14);
        this.log = log; 
    }

    //Insercao na primeira arvore
    public void inserir(int elemento) throws Exception{
        raiz = inserir(elemento, raiz);
    }

    public No inserir(int elemento, No i) throws Exception{
        if (i == null) {
            i = new No(elemento);
        } else if (elemento < i.elemento) {
            i.esq = inserir(elemento, i.esq);
        } else if (elemento > i.elemento) {
            i.dir = inserir(elemento, i.dir);
        } else {
            throw new Exception("Erro ao inserir!");
        }
        return i;
    }

    //Insercao na Segunda Arvore
    public void inserir(Pokemon elemento) throws Exception {
        inserir(elemento, raiz);
    }

    public void inserir(Pokemon elemento, No i) throws Exception {
		int captureRate = elemento.getCaptureRate() % 15;

        if (i == null) {
            throw new Exception("Erro ao inserir");
        } else if (captureRate < i.elemento) {
            log.contarComparacoes();
            inserir(elemento, i.esq);
        } else if (captureRate > i.elemento) {
            log.contarComparacoes();
            inserir(elemento, i.dir);
        } else {
            i.outro = inserir(elemento, i.outro);
        }
    }
    
    //Inserir um pokemon na arvore 
    private No2 inserir(Pokemon elemento, No2 i) throws Exception {
        if (i == null) {
            i = new No2(elemento);
        } else if (elemento.getName().compareTo(i.elemento.getName()) < 0) {
            log.contarComparacoes();
            i.esq = inserir(elemento, i.esq);
        } else if (elemento.getName().compareTo(i.elemento.getName()) > 0) {
            log.contarComparacoes();
            i.dir = inserir(elemento, i.dir);
        }
		return i;
	}
  
    public boolean pesquisar(String elemento) {
        System.out.print("raiz ");
		return pesquisar(raiz, elemento);
	}

	private boolean pesquisar(No no, String elemento) {
        boolean resp;
		if (no == null) { 
            resp = false;
        } else {
            boolean b1 = pesquisarSegundaArvore(no.outro, elemento);
            if(b1){
                resp = b1;
            } else {
                System.out.print(" ESQ ");
                boolean b2 = pesquisar(no.esq, elemento);
                if(b2){
                    resp = b2;
                } else {
                    System.out.print(" DIR ");
                    boolean b3 = pesquisar(no.dir, elemento);
                    resp = b3;
                }
            }
        }
        return resp;
	}

	private boolean pesquisarSegundaArvore(No2 no, String elemento) {
        boolean resp;
		
        if (no == null) { 
            resp = false;
        } else if (elemento.compareTo(no.elemento.getName()) < 0) { 
            log.contarComparacoes();
            System.out.print("esq "); 
            resp = pesquisarSegundaArvore(no.esq, elemento); 
        } else if (elemento.compareTo(no.elemento.getName()) > 0) { 
            log.contarComparacoes();
            System.out.print("dir "); 
            resp = pesquisarSegundaArvore(no.dir, elemento); 
        } else { 
            resp = true; 
        }
        return resp;
	}
}

class No2 {
	public Pokemon elemento; // Conteudo do no.
	public No2 esq; // No da esquerda.
	public No2 dir; // No da direita.
	
  
    //Construtor
	No2(Pokemon elemento) {
		this.elemento = elemento;
		this.esq = this.dir = null;
	}

	//Construtor com atribuicao de esq e dir
	No2(Pokemon elemento, No2 esq, No2 dir) {
		this.elemento = elemento;
		this.esq = esq;
		this.dir = dir;
	}
}

//------------------- Classe No ---------------------//
class No {
    public int elemento; // Conteudo do no.
	public No esq; // No da esquerda.
	public No dir; // No da direita.
    public No2 outro;
	
    //Construtor
	No(int elemento) {
		this.elemento = elemento;
		this.esq = this.dir = null;
        this.outro = null;
	}

    //Construtor com atribuicao de esq e dir
	No(int elemento, No esq, No dir) {
		this.elemento = elemento;
		this.esq = esq;
		this.dir = dir;
        this.outro = null;
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
               // System.out.println(linha);
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
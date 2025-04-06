/**
 * @path TP04Q07 - Tabela Hash indireta 
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

public class Tp4Q07 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        double tempoTotal = 0.0;

        GerenciadorPokemons gp = new GerenciadorPokemons();
        gp.ler(); // ler do arquivo

        Log log = new Log(); //gravar tempo e comparacoes
        Hash hash = new Hash(log); 
        Pokemon pk = new Pokemon(); 

        String line;
        
        while(!(line = sc.next()).equals("FIM")){
            int id = Integer.parseInt(line); //ler id
            pk = gp.buscarPokemon(id); //buscar pokemon do id
            hash.inserir(pk); //inserir na hash
        }

        sc.nextLine();
        while(!(line = sc.nextLine()).equals("FIM")){
            System.out.print("=> " + line + ": ");

            double inicio = log.now();
            boolean resp = hash.pesquisar(line);
            double fim = log.now();

            //calcular tempo de execucao
            tempoTotal += (fim - inicio);

            if(resp) System.out.println("SIM");
            else System.out.println("NAO");
        }
        //gravar no arquivo
        log.gravarArquivo(tempoTotal, log.comparacoes);

        sc.close();
    }
}

//------------------- Tabela Hash ---------------------//
class HashIndiretoLista {
    Lista tabela[];
    int tamanho;
    final Pokemon NULO = null;

    private Log log;
 
    public HashIndiretoLista(Log log) {
       this.tamanho = 21;
       this.log = log;
    }
 
    public HashIndiretoLista(int tamanho) {
        this.tamanho = tamanho;
        this.tabela = new Lista[tamanho];
        for (int i = 0; i < tamanho; i++) {
           tabela[i] = new Lista();
        }
    }
     
    //Hash
    public int h(String nome) {
        int ascii = 0;
        for(int i=0; i < nome.length(); i++){
            ascii += (int)nome.charAt(i);
        }
        return ascii % tamanho;
    }
 
    //Funcao para inserir na tabela hash
    public void inserirInicio(Pokemon elemento) {
        int pos = h(elemento.getName());
        tabela[pos].inserirInicio(elemento);
    }
    
    //Funcao para pesquisar pokemon por nome na tabela hash
    public boolean pesquisar(String nome) {
        int pos = h(nome);
        System.out.print("(Posicao: " + pos + ") ");
        return tabela[pos].pesquisar(nome);
    }
}

//------------- Celula ---------------//
class Celula {
	public Pokemon elemento; // Elemento inserido na celula.
	public Celula prox; // Aponta a celula prox.

	/**
	 * Construtor da classe.
	 * @param elemento Elemento inserido na celula.
	 */
	Celula(Pokemon elemento) {
		this.elemento = elemento;
		this.prox = null;
	}

	/**
	 * Construtor da classe.
	 * @param elemento Elemento inserido na celula.
	 * @param prox Aponta a celula prox.
	 */
	Celula(Pokemon elemento, Celula prox) {
		this.elemento = elemento;
		this.prox = prox;
	}
}

//--------------- Lista Simples encadeada -----------//
class Lista {
	private Celula primeiro; // Primeira celula: SEM elemento valido.
	private Celula ultimo; // Ultima celula: COM elemento valido.

    Log log = new Log();
	/**
	 * Construtor da classe: Instancia uma celula (primeira e ultima).
	 */
	public Lista() {
		primeiro = new Celula(null);
		ultimo = primeiro;
	}

	/**
	 * Mostra os elementos separados por espacos.
	 */
	public void mostrar() {
		System.out.print("[ "); // Comeca a mostrar.
		for (Celula i = primeiro.prox; i != null; i = i.prox) {
			System.out.print(i.elemento + " ");
		}
		System.out.println("] "); // Termina de mostrar.
	}

	/**
	 * Procura um elemento e retorna se ele existe.
	 * @param x Elemento a pesquisar.
	 * @return <code>true</code> se o elemento existir,
	 * <code>false</code> em caso contrario.
	 */
	public boolean pesquisar(String nome) {
		boolean retorno = false;
		for (Celula i = primeiro.prox; i != null; i = i.prox) {
         if(i.elemento.getName().compareTo(nome)== 0){
            log.contarComparacoes();
            retorno = true;
            i = ultimo;
         }
		}
		return retorno;
	}

	/**
	 * Insere um elemento na primeira posicao da sequencia.
	 * @param elemento Elemento a inserir.
	 */
	public void inserirInicio(Pokemon elemento) {
		Celula tmp = new Celula(elemento);
        tmp.prox = primeiro.prox;
		primeiro.prox = tmp;
		if (primeiro == ultimo) {
            log.contarComparacoes();
			ultimo = tmp;
		}
        tmp = null;
	}

	/**
	 * Insere um elemento na ultima posicao da sequencia.
	 * @param elemento Elemento a inserir.
	 */
	public void inserirFim(Pokemon elemento) {
		Celula tmp = new Celula(elemento);
		ultimo.prox = tmp;
		ultimo = ultimo.prox;
      tmp = null;
	}

	/**
	 * Insere elemento em um indice especifico.
	 * Considera que primeiro elemento esta no indice 0.
	 * @param x Elemento a inserir.
	 * @param posicao Meio da insercao.
	 * @throws Exception Se <code>posicao</code> for incorreta.
	 */
   public void inserirMeio(Pokemon pok, int posicao) throws Exception {
      Celula i;
      int cont;

		// Caminhar ate chegar na posicao anterior a insercao
      for(i = primeiro, cont = 0; (i.prox != ultimo && cont < posicao); i = i.prox, cont++);
		
		// Se indice for incorreto:
		if (posicao < 0 || posicao > cont + 1) {
			throw new Exception("Erro ao inserir (posicao " + posicao + "(cont = " + cont + ") invalida)!");

      } else if (posicao == cont + 1) {
        log.contarComparacoes();
         inserirFim(pok);
		}else{
         Celula tmp = new Celula(pok);
         tmp.prox = i.prox;
         i.prox = tmp;
         tmp = i = null;
      }
   }

	/**
	 * Remove um elemento da primeira posicao da sequencia.
	 * @return Elemento removido.
	 * @throws Exception Se a sequencia nao contiver elementos.
	 */
	public Pokemon removerInicio() throws Exception {
        Pokemon resp = null;

		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover (vazia)!");
		} else{
            primeiro = primeiro.prox;
            resp = primeiro.elemento;
        }

		return resp;
	}

	/**
	 * Remove um elemento da ultima posicao da sequencia.
	 * @return Elemento removido.
	 * @throws Exception Se a sequencia nao contiver elementos.
	 */
	public Pokemon removerFim() throws Exception {
        Pokemon resp = null;
        Celula i = null;

		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover (vazia)!");
		} else {

        resp = ultimo.elemento;

        // Caminhar ate a penultima celula:
        for(i = primeiro; i.prox != ultimo; i = i.prox);

        ultimo = i;
        i = ultimo.prox = null;
      }

		return resp;
	}

	/**
	 * Remove elemento de um indice especifico.
	 * Considera que primeiro elemento esta no indice 0.
	 * @param posicao Meio da remocao.
	 * @return Elemento removido.
	 * @throws Exception Se <code>posicao</code> for incorreta.
	 */
	public Pokemon removerMeio(int posicao) throws Exception {
      Celula i;
      int cont;
      Pokemon resp = null;

		if (primeiro == ultimo){
			throw new Exception("Erro ao remover (vazia)!");
      }else{

		   // Caminhar ate chegar na posicao anterior a insercao
         for(i = primeiro, cont = 0; (i.prox != ultimo && cont < posicao); i = i.prox, cont++);

         // Se indice for incorreto:
		   if (posicao < 0 || posicao > cont + 1) {
            throw new Exception("Erro ao remover (posicao " + posicao + " invalida)!");

         } else if (posicao == cont + 1) {
            resp = removerFim();
         }else{
            Celula tmp = i.prox;
            resp = tmp.elemento;
            i.prox = tmp.prox;
            tmp.prox = null;
            i = tmp = null;
         }
      }

		return resp;
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
    private static final String FILE_PATH = "pokemon.csv";
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
        
        try (BufferedWriter buffWrite = new BufferedWriter(new FileWriter("matricula_hashIndireta.txt"))) {
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
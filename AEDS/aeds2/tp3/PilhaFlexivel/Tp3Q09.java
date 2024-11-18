/**
 * @path TP03Q09 -Pilha com Alocacao Flexivel em Java
 * @author Rayssa Mell de Souza Silva
 */

//-------------- imports
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;


public class Tp3Q09{
    //----------------- Metodo Principal
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        GerenciadorPokemons gp = new GerenciadorPokemons();
        gp.ler(); // ler do arquivo

        Pilha pilha = new Pilha();
        Pilha pilha2 = new Pilha(); 

        String line;
        Pokemon pk = new Pokemon(); 

        while(!(line = sc.next()).equals("FIM")){
            int id = Integer.parseInt(line); //ler id
            pk = gp.buscarPokemon(id); //buscar pokemon do id
            pilha.empilhar(pk); //inserir na pilha
        }
        //ler quantidade de operacoes
        int n = sc.nextInt();
        sc.nextLine();

        int id = 0;
        for(int i=0; i < n; i++){ 
            //------- Tratando entrada -------//
            String operacao = sc.next();

            if(operacao.equals("I")){
                id = sc.nextInt();
                pk = gp.buscarPokemon(id);
                pilha.empilhar(pk);
            } else {
                pk = pilha.desempilhar();
                pilha.mostrarRemovido(pk);
            }
        }
        //nova pilha para inverter a ordem da pilha original
        pilha2.reempilhar(pilha, pk);
        pilha2.print(); //mostrar lista
        sc.close();
    }
}

//------------------- Classe Celula ---------------------//
class Celula {
    public Pokemon elemento;
    public Celula prox;

    public Celula(Pokemon elemento) {
        this.elemento = elemento;
        this.prox = null;
    }
}
//------------------- Classe Pilha ---------------------//
class Pilha  {
    private Celula topo; 
    private int n; //tamanho

    //formatador de data
    SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");

    //Construtor Padrao
    public Pilha(){
        topo = null;
        n = 0;
    }

    //------------- Empilhar Pokemons
    public void empilhar(Pokemon pokemon) throws Exception {
        Celula tmp = new Celula(pokemon);
		tmp.prox = topo;
		topo = tmp;
        tmp = null;
        n++; //aumentar tamanho
    }

    //------------- Reempilhar Pokemons
    public void reempilhar(Pilha pilha, Pokemon pokemon) throws Exception {
        for (Celula i = pilha.topo; i != null; i = i.prox) {
            Celula nova = new Celula(pokemon);
            nova.elemento = i.elemento; 
            nova.prox = topo;
            topo = nova;
        }
    }

    //------------- Remover pokemon da Pilha
    public Pokemon desempilhar() throws Exception {
        //verificar se a lista esta vazia
        if (topo == null || n == 0) {
            throw new Exception("ERRO: LISTA VAZIA");
        }
        
        Pokemon pk = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox = null;
		tmp = null;
		return pk;
    }
    
    //-------------- Mostrar Pokemon removido
    public void mostrarRemovido(Pokemon pok){
        System.out.println("(R) " + pok.getName());
    }

    //---------------------- Metodo Imprimir
    public void print(){
        int j = 0;
        for(Celula i=topo; i != null; i=i.prox){
            System.out.println("["+j+ "] " +"[#" 
                            + i.elemento.getId() + " -> " 
                            + i.elemento.getName() + ": " 
                            + i.elemento.getDescription() + " - " 
                            + i.elemento.getTypes() + " - " 
                            + i.elemento.getAbilities()  + " - " 
                            + i.elemento.getWeight() + "kg - " 
                            + i.elemento.getHeight() + "m - "  
                            + i.elemento.getCaptureRate() + "% - "  
                            + i.elemento.getIsLegendary() + " - "  
                            + i.elemento.getGeneration() + " gen] - "  
                            + (formatter.format(i.elemento.getCaptureDate())));
            j++;
        }
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
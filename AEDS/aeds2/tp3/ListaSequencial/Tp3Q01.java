/**
 * @path TP03Q01 - Lista Sequencial em Java
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

public class Tp3Q01 {

    public static int getOperacao(String operacao){
        switch (operacao) {
            case "RI": return 0; // Remover no inicio
            case "RF": return 1; // Remover no fim
            case "II": return 2; // Inserir do fim
            case "IF": return 3; // Inserir do inicio
            default: System.out.println("Operação desconhecida: " + operacao);
        }
        return -1;
    }
    //----------------- Metodo Principal
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        GerenciadorPokemons gp = new GerenciadorPokemons();
        gp.ler(); // ler do arquivo

        Lista lista = new Lista(); 
        String line;
        Pokemon pk = new Pokemon(); 

        while(!(line = sc.next()).equals("FIM")){
            int id = Integer.parseInt(line); //ler id
            pk = gp.buscarPokemon(id); //buscar pokemon do id
            lista.inserirFim(pk); //inserir na lista
        }
        //ler quantidade de operacoes
        int n = sc.nextInt();
        sc.nextLine();

        int pos = 0;
        int id = 0;
        for(int i=0; i < n; i++){ 
            //------- Tratando entrada -------//
            String operacao = sc.nextLine().trim();
            String[] partes = operacao.split(" ");
            
            //Se for, R* ou I*
            if (partes[0].charAt(partes[0].length() - 1) == '*') { 
                pos = Integer.parseInt(partes[1]); // Le a posicao
                //Remover na posicao
                if(partes[0].charAt(0) == 'R'){
                    pk = lista.remover(pos);
                    lista.mostrarRemovido(pk);
                } else {
                    //Inserir na posicao
                    id = Integer.parseInt(partes[2]);
                    pk = gp.buscarPokemon(id);
                    lista.inserir(pk, pos);
                }
            } else {
                //chamar metodo para descobir a operacao
                int op = getOperacao(partes[0]);

                if(op == 0){
                    pk = lista.removerInicio();
                    lista.mostrarRemovido(pk);
                } else if(op == 1){
                    pk = lista.removerFim();
                    lista.mostrarRemovido(pk);
                } else if (op == 2) {
                    id = Integer.parseInt(partes[1]);
                    pk = gp.buscarPokemon(id);
                    lista.inserirInicio(pk);
                } else if(op == 3) {
                    id = Integer.parseInt(partes[1]);
                    pk = gp.buscarPokemon(id);
                    lista.inserirFim(pk);
                }
            }  
        }
        lista.print(); //mostrar lista
        sc.close();
    }
}

//------------------- Classe LISTA ---------------------//
class Lista {
    private Pokemon[] pokemonList; //lista de pokemons
    private int n; //tamanho

    //formatador de data
    SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");

    //Construtor Padrao
    public Lista(){
        pokemonList = new Pokemon[801];
        n = 0;
    }

    //Construtor com atribuicao
    public Lista(int tamanho){
        pokemonList = new Pokemon[tamanho];
        n = 0;
    }

    //-------  Insere um Pokemon no Inicio da lista e move os demais para o fim
    public void inserirInicio(Pokemon pokemon) throws Exception{
        //verificar se a lista esta cheia
        if(n >= pokemonList.length) throw new Exception("ERRO: LISTA CHEIA");

        //levar pokemons para proxima posicao
        for(int i=n; i > 0; i--){
            pokemonList[i] = pokemonList[i-1];
        }
        //insere o novo pokemon
        pokemonList[0] = pokemon;
        n++; //aumenta o tamanho
    }

    //------------- Inserir na posicao desejada
    public void inserir(Pokemon pok, int posicao) throws Exception{
        //verifica se a posicao e' valida
        if(n >= pokemonList.length || posicao < 0 || posicao > n){
            throw new Exception("ERRO: POSICAO INVALIDA");
        }
        //mover pokemonList para o fim
        for(int i = n; i > posicao; i--){
            pokemonList[i] = pokemonList[i-1];
        }
        //inserir na posicao
        pokemonList[posicao] = pok;
        n++; //aumentar tamanho
    }

    //------------- Inserir pokemon no fim da lista
    public void inserirFim(Pokemon pokemon) throws Exception {
        //verificar se a lista esta cheia
        if(n >= pokemonList.length) throw new Exception("ERRO: LISTA CHEIA");

        //inserir na posicao n
        pokemonList[n] = pokemon;
        n++; //aumentar tamanho
    }

    //------------- Remover pokemon do inicio da lista
    public Pokemon removerInicio() throws Exception {
        //verificar se a lista esta vazia
        if(n == 0){
            throw new Exception("ERRO: LISTA VAZIA");
        }

        //buscar primeiro pokemon
        Pokemon pok = pokemonList[0];
        n--; //diminuir tamanho
        
        //voltar pokemonList para posicao anterior 
        for(int i=0; i < n; i++){
            pokemonList[i] = pokemonList[i+1];
        }

        return pok;
    } 

    //------------- Remover pokemon da posicao desejada
    public Pokemon remover(int posicao) throws Exception {
        //verificar se a posicao e' valida
        if (n == 0 || posicao < 0 || posicao >= n) {
            throw new Exception("ERRO: POSICAO IVALIDA");
        }
        
        //buscar pokemon a ser removido
        Pokemon pok = pokemonList[posicao];
        n--; //diminui tamanho

        for(int i = posicao; i < n; i++){
            pokemonList[i] = pokemonList[i+1];
        }

        return pok;
    }

    //------------- Remover pokemon do fim da lista
    public Pokemon removerFim() throws Exception {
        //verificar se a lista esta vazia
        if (n == 0) {
            throw new Exception("ERRO: LISTA VAZIA");
        }
        
        //remover pokemon do fim e diminuir tamanho
        return pokemonList[--n];
    }
    
    //-------------- Mostrar Pokemon removido
    public void mostrarRemovido(Pokemon pok){
        System.out.println("(R) " + pok.getName());
    }

    //---------------------- Metodo Imprimir
    public void print(){
        for(int i=0; i < n; i++){
            System.out.println("["+i+ "] " +"[#" 
                            + pokemonList[i].getId() + " -> " 
                            + pokemonList[i].getName() + ": " 
                            + pokemonList[i].getDescription() + " - " 
                            + pokemonList[i].getTypes() + " - " 
                            + pokemonList[i].getAbilities()  + " - " 
                            + pokemonList[i].getWeight() + "kg - " 
                            + pokemonList[i].getHeight() + "m - "  
                            + pokemonList[i].getCaptureRate() + "% - "  
                            + pokemonList[i].getIsLegendary() + " - "  
                            + pokemonList[i].getGeneration() + " gen] - "  
                            + (formatter.format(pokemonList[i].getCaptureDate())));
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
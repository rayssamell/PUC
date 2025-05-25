/**
 * @path TP02Q15 - Ordenação por Seleção Parcial
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


//------------- Classe Pokemon
public class Pokemon {
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

    //caminho para arquivo
    public static final String FILE_PATH = "/tmp/pokemon.csv";
    //formatador de data
    SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
    
    //----- Construtor Padrao -----//
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

    //---- Construtor com atribuicao de valores -----//
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
    public void setTypes(String type){
        this.types.add(type);
    }
    public ArrayList<String> getAbilities(){
        return abilities;
    }
    public void setAbilities(String abilities){
        this.abilities.add(abilities);
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

    //---------------------- Metodo Imprimir
    public void print(List<Pokemon> pokemon, int k){
        for(int i=0; i < k; i++){
            System.out.println("[#" 
                           + pokemon.get(i).getId() + " -> " 
                           + pokemon.get(i).getName() + ": " 
                           + pokemon.get(i).getDescription() + " - " 
                           + pokemon.get(i).getTypes() + " - " 
                           + pokemon.get(i).getAbilities()  + " - " 
                           + pokemon.get(i).getWeight() + "kg - " 
                           + pokemon.get(i).getHeight() + "m - "  
                           + pokemon.get(i).getCaptureRate() + "% - "  
                           + pokemon.get(i).getIsLegendary() + " - "  
                           + pokemon.get(i).getGeneration() + " gen] - "  
                           + (formatter.format(pokemon.get(i).getCaptureDate())));
        }
    }

    //----------------------- Metodo para Ler Pokemons do arquivo e criar uma lista 
    public List<Pokemon> ler() { 
        // Array List com Pokemons lidos do arquivo
        List<Pokemon> pokemons = new ArrayList<>();  

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

                        pokemon.id = Integer.parseInt(partes[0]);
                        pokemon.generation = Integer.parseInt(partes[1]);
                        pokemon.name = partes[2];
                        pokemon.description = partes[3];

                        //---- TYPES -----//
                        pokemon.types = new ArrayList<>();
                        String type1 = "'" + partes[4].trim() + "'";
                        pokemon.types.add(type1);
                        // se o segundo tipo nao for vazio
                        if (!partes[5].equals("0")) {
                            String type2 = "'" + partes[5].trim() + "'";
                            pokemon.types.add(type2);
                        }

                        // ----- Abilities -----//
                        pokemon.abilities = new ArrayList<>();
                        String ability = "";

                        for(int j=0; j < partes[6].length(); j++){
                            char character = partes[6].charAt(j);
                            if (character != '\"' && character != '[' && character != ']') {
                                // Se encontrar uma virgula, a habilidade foi capturada
                                if (character == ',') {
                                    if (!ability.isEmpty()) {
                                        pokemon.abilities.add(ability.trim()); // Adiciona a habilidade a lista
                                        ability = ""; // Limpa para capturar a próxima habilidade
                                    }
                                } else {
                                    ability += character;
                                }
                            }
                        }
                        if(!ability.equals("0")){
                            pokemon.abilities.add(ability.trim()); 
                        }

                        pokemon.weight = partes[7].isEmpty() ? 0.0 : Double.parseDouble(partes[7]);
                        pokemon.height = partes[8].isEmpty() ? 0.0 : Double.parseDouble(partes[8]);
                        pokemon.captureRate = Integer.parseInt(partes[9]);
                        
                        int valorLido = Integer.parseInt(partes[10]);
                        pokemon.isLegendary = (valorLido == 1);
                        
                        // tratar data
                        try {
                            Date data = formatter.parse(partes[11]);
                            pokemon.captureDate = data;
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
        return pokemons;   
    }

    //--------------------------- Metodo para Buscar pokemon do ID indicado
    public Pokemon insertPokemonId(int id, List<Pokemon> pokemons) {
        Pokemon pok = new Pokemon();
        for (int i = 0; i < pokemons.size(); i++) {
            Pokemon pk = pokemons.get(i);  // Obtem o Pokemon na posição i
            if (pk.getId() == id) { //compara ate achar o buscado
               pok = pk; //guarda
               i = pokemons.size();  //sai do loop
            }
        }
        return pok; //retorna o pokemon
    }

    //----------------------- Metodo para Comparar String
    public static int compararStrings(String p1, String p2){
        int length1 = p1.length(); //tamanho string1
        int length2 = p2.length(); //tamanho string2
        int resp = -1;

        // loop com tamanho da string1
        for(int i=0; i < length1; i++){
            int value1 = p1.charAt(i); //valor ascii da letra
            if(i < length2){ 
                int value2 = p2.charAt(i); //valor ascii da letra

                //Caso 1: letra de p2 suceder letra de p1
                if(value1 < value2){ 
                    resp = 1;
                    i = length1; //sai do loop
                } 
                //Caso 2: letra de p1 suceder letra de p2
                else if(value1 > value2){
                    resp = 0;
                    i = length1; //sai do loop
                }
                //Caso 3: se as letras forem iguais continua
            }
        }
        
        return resp;
    } 

    //---- Swap para trocar Pokemons de posicao ----//
    private static void swap(List<Pokemon> pokemon, int i, int j){
        Pokemon temp = pokemon.get(i);
        pokemon.set(i, pokemon.get(j));
        pokemon.set(j, temp);
    }

    //---------------- Metodo para ordenar Lista de Pokemons pelo nome 
    public static void SelectionSortParcial(List<Pokemon> pokemon, int k){
        // k menores 
        for (int i = 0; i < k; i++) {
            int menor = i;
            
            for (int j = (i + 1); j < pokemon.size(); j++){
                String p1 = pokemon.get(menor).getName();
                String p2 = pokemon.get(j).getName();
                int compare = compararStrings(p1, p2); //comparador de strings

                //se p1 for maior que p2
                if(compare == 0){
                    menor = j;
                }
            }
            swap(pokemon, menor, i); //chama o swap para trocar
        }
    }

    //--------------------------- Metodo Principal
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        Pokemon pokemon = new Pokemon();
        List<Pokemon> pokemons = pokemon.ler(); //lista de pokemons do arquivo
        //nova lista com pokemons do id a ser lido
        List<Pokemon> newList = new ArrayList<>(); 

        while(!(line = sc.next()).equals("FIM")){
            int id = Integer.parseInt(line);
            newList.add(pokemon.insertPokemonId(id, pokemons));
        }
        
        //chamar o ordenacao por selecao parcial para ordenar o k menores
        SelectionSortParcial(newList, 10);
        
        pokemon.print(newList, 10); // mostra a lista ordenada

        sc.close();
    }
}

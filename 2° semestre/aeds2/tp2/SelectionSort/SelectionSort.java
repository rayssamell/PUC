/**
 * @path TP02Q05 - Ordenação por Seleção
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


public class SelectionSort {
    private int movimentacoes;
    private int comparacoes;
    private List<Pokemon> pokemons; 

    //Construtor Padrao
    public SelectionSort(){
        movimentacoes = 0;
        comparacoes = 0;
        pokemons = new ArrayList<>();
    }

    //Construtor com atribuicao de valores
    public SelectionSort(int comparacoes, int movimentacoes, List<Pokemon> pok){
        this.comparacoes = comparacoes;
        this.movimentacoes = movimentacoes;
        this.pokemons = pok;
    }

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
        public void print(List<Pokemon> pokemon){
            for(int i=0; i < pokemon.size(); i++){
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
    }// fim da classe Pokemon

    // Retorna o timestamp atual
    public long now(){
        return new Date().getTime();    
    }

    //--------------------------- Metodo para Buscar pokemon do ID indicado
    public void insertPokemonId(int id, List<Pokemon> pokemon) {
        for (int i = 0; i < pokemon.size(); i++) {
            Pokemon pk = pokemon.get(i);  // Obtem o Pokémon na posição i
            if (pk != null && pk.getId() == id) { // Verifica se pk não é null
                pokemons.add(pk); // Adiciona a lista `pokemons`
                i = pokemon.size();
            }
        }
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
                //Caso 3: se as letras forem iguais itera o loop
            }
        }
        
        return resp;
    } 

    //---- Swap para trocar Pokemons de posicao ----//
    private void swap(int i, int j){
        Pokemon temp = pokemons.get(i);
        pokemons.set(i, pokemons.get(j));
        pokemons.set(j, temp);
    }

    //---------------- Metodo Selection Sort para ordenar Lista de Pokemons pelo nome 
    public void selectionSort(){
        for (int i = 0; i < pokemons.size()-1; i++) {
			int menor = i;
			for (int j = (i + 1); j < pokemons.size(); j++){
                
                String p1 = pokemons.get(menor).getName(); 
                String p2 = pokemons.get(j).getName(); 
                int compare = compararStrings(p1, p2); //comparador de strings
                
                if(compare == 0){
					menor = j;
                    comparacoes++;
				}
			}
			swap(menor, i);
            movimentacoes+=3;
		}
    }
   
    // Gravar no arquivo tempo de execucao e numero de comparacoes
    public void gravarArquivo (double inicio, double fim) {

        try (BufferedWriter buffWrite = new BufferedWriter(new FileWriter("matricula_selecao.txt"))) {
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

    //--------------------------- Metodo Principal
    public static void main(String[] args) {
        double inicio, fim;
        Scanner sc = new Scanner(System.in);
        String line;

        // Instancia de SelectionSort e de Pokemon
        SelectionSort selection = new SelectionSort();
        SelectionSort.Pokemon pok = selection.new Pokemon(); 

        // Ler a lista de pokemons do arquivo
        List<SelectionSort.Pokemon> pokemonList = pok.ler();

        // Leitura dos IDs e preenchimento da nova lista
        while (!(line = sc.next()).equals("FIM")) {
            int id = Integer.parseInt(line);
            selection.insertPokemonId(id, pokemonList); // Insere pokemon na lista baseado no ID
        }

        // Tempo de execucaoo
        inicio = selection.now();
        selection.selectionSort(); //chamada do SelectionSort para ordenar
        fim = selection.now();

        // Mostrar lista ordenada
        pok.print(selection.pokemons); // Imprimir os pokemons ordenados

        // Gravar o tempo de execucao no arquivo
        selection.gravarArquivo(inicio, fim);

        sc.close();
    }
}

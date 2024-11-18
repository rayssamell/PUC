/**
 * @path TP02Q04 - Pesquisa Binaria 
 * @author Rayssa Mell de Souza Silva
 */

//-----------imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//caminho para arquivo
#define FILE_PATH "/tmp/pokemon.csv"

#define MAXTAM 801
#define MAX_ABILITIES 8

//---------- Struct Data
typedef struct Date {
    int dia;
    int mes;
    int ano;
} Date;

//----------- Struct Pokemon 
typedef struct {
    int id;
    int generation;
    char name[100];
    char description[100];
    char **types;
    char **abilities;
    float weight;
    float height;
    int captureRate;
    bool isLegendary;
    Date captureDate;
} Pokemon;

// Ponteiro para uma estrutura(vetor) do tipo Pokemon
Pokemon *pokemon[MAXTAM]; 

//----------- Funcao para criar e inicializar um Pokemon
Pokemon* createPokemon() {
    Pokemon* newPokemon = (Pokemon*)malloc(sizeof(Pokemon));
    if (newPokemon == NULL) {
        printf("Erro ao alocar memoria para um novo Pokemon\n");
    }

    // Inicializando os campos
    newPokemon->id = -1;
    newPokemon->generation = -1;
    newPokemon->types = malloc(2 * sizeof(char*)); // Para dois tipos
    newPokemon->types[0] = NULL; // Inicializa como NULL
    newPokemon->types[1] = NULL; // Inicializa como NULL

    newPokemon->abilities = malloc(MAX_ABILITIES * sizeof(char*)); 
    newPokemon->abilities[0] = NULL; // Inicializa como NULL

    // Inicializa outros campos
    newPokemon->weight = 0.0;
    newPokemon->height = 0.0;
    newPokemon->captureRate = 0;
    newPokemon->isLegendary = false;
    newPokemon->generation = 0;
    newPokemon->captureDate.dia = 0;
    newPokemon->captureDate.mes = 0;
    newPokemon->captureDate.ano = 0;

    return newPokemon;
}

//----------------- Funcao para Clonar Pokemon
Pokemon* clone(Pokemon* original) {
    Pokemon* novoPokemon = (Pokemon*)malloc(sizeof(Pokemon));
    
    if (novoPokemon != NULL) {

        novoPokemon->id = original->id;
        novoPokemon->generation = original->generation;  
        novoPokemon->weight = original->weight;
        novoPokemon->height = original->height;
        novoPokemon->captureRate = original->captureRate;
        novoPokemon->isLegendary = original->isLegendary;
        novoPokemon->captureDate = original->captureDate;

        strcpy(novoPokemon->name, original->name);
        strcpy(novoPokemon->description, original->description);

        // Types
        novoPokemon->types = malloc(2 * sizeof(char*)); 
        for (int i = 0; i < 2; i++) {
            if (original->types[i] != NULL) {
                novoPokemon->types[i] = strdup(original->types[i]);
            } else {
                novoPokemon->types[i] = NULL;
            }
        }

        // Abilities
        novoPokemon->abilities = malloc(MAX_ABILITIES * sizeof(char*));
        for (int i = 0; i < MAX_ABILITIES; i++) {
            if (original->abilities[i] != NULL) {
                novoPokemon->abilities[i] = strdup(original->abilities[i]);
            } else {
                novoPokemon->abilities[i] = NULL;
            }
        }
    }
    return novoPokemon; // Retorna o Pokemon clonado
}

//----------------- Metodos get e set
int getId(Pokemon *pokemon){
    return pokemon->id;
}
void setId(Pokemon *pokemon, int id){
    pokemon->id = id;
}
int getGeneration(Pokemon *pokemon){
    return pokemon->generation;
}
void setGeneration(Pokemon *pokemon, int generation){
    pokemon->generation = generation;
}
char *getName(Pokemon *pokemon) {
    return pokemon->name;
}
void setName(Pokemon *pokemon, char *name) {
    strcpy(pokemon->name, name);
}
char *getDescription(Pokemon *pokemon){
    return pokemon->description;
}
char setDescription(Pokemon *pokemon, char *description){
    strcpy(pokemon->description, description);
}
char **getTypes(Pokemon *pokemon){
    return pokemon->types; 
}
void setTypes(Pokemon *pokemon, char **types){
    pokemon->types = types;
}
char **getAbilities(Pokemon *pokemon){
    return pokemon->abilities;
}
void setAbilities(Pokemon *pokemon, char **abilities){
    pokemon->abilities = abilities;
}
float getWeight(Pokemon *pokemon){
    return pokemon->weight;
} 
void setWeight(Pokemon *pokemon, float weight){
    pokemon->weight = weight;
}
float getHeight(Pokemon *pokemon){
    return pokemon->height;
}
void setHeight(Pokemon *pokemon, float height){
    pokemon->height = height;
}
int getCaptureRate(Pokemon *pokemon){
    return pokemon->captureRate;
}
void setCaptureRate(Pokemon *pokemon, int captureRate){
    pokemon->captureRate = captureRate;
}
bool getIsLegendary(Pokemon *pokemon){
    return pokemon->isLegendary;
}
void setIsLegendary(Pokemon *pokemon, bool isLegendary){
    pokemon->isLegendary =  isLegendary;
}

Date getCaptureDate(Pokemon *pokemon) {
    return pokemon->captureDate;
}

void setCaptureDate(Pokemon *pokemon, Date captureDate) {
    pokemon->captureDate = captureDate;
}

//--- Procedimento para tratar habilidades ---//
void tratarHabilidades(char* campo, Pokemon* pokemon) {
    int pos = 0;

    // Substitui aspas simples e colchetes por espaco
    for (int j = 0; campo[j] != '\0'; j++) {
        if (campo[j] == '\'' || campo[j] == '[' || campo[j] == ']') {
            campo[j] = ' ';
        }
    }
    char* habilidade = strtok(campo, ",");
    
    while (habilidade != NULL && pos < MAX_ABILITIES) {
        //Remover espaco do inicio e final da habilidade
        while (*habilidade == ' ') habilidade++; 
        char* fim = habilidade + strlen(habilidade) - 1;
        while (*fim == ' ') {
            fim--;
        }
        fim[1] = '\0'; 

        if (strlen(habilidade) > 0) {
            //aloca espaco para cada habilidade
            pokemon->abilities[pos] = (char *)malloc((strlen(habilidade) + 1) * sizeof(char));
            strcpy(pokemon->abilities[pos], habilidade); // Copia a habilidade
            pos++;
        }
        habilidade = strtok(NULL, ","); 
    }
    pokemon->abilities[pos] = NULL;
}

//--- Funcao para verificar se os campos estao vazios ---//
bool verificarCamposVazios(char* campo) {
    bool resp = false;
    if (strncmp(campo, ",,,", 3) == 0) {
        resp = true;
    }
    return resp;
}

//--------------- Metodo para ler pokemons de arquivo
void ler(){
    FILE *arquivo = fopen(FILE_PATH, "rt");
    char linha[803];
    char *campo;
    int i = 0;
    int linhaAtual = 0;
   
    if (arquivo != NULL) {
        while (fgets(linha, sizeof(linha), arquivo) != NULL && i < 802 ) {
            linhaAtual++;
            if (linhaAtual != 1) { //pula a primeira linha
                
                char linhaCopia[sizeof(linha)];
                strcpy(linhaCopia, linha);

                pokemon[i] = createPokemon();
                
                //--- ID ---//
                campo = strtok(linha, ",");
                setId(pokemon[i], atoi(campo));

                //--- Generation ---//
                campo = strtok(NULL, ",");
                setGeneration(pokemon[i], atoi(campo));

                //--- Name ---// 
                campo = strtok(NULL, ",");
                setName(pokemon[i], campo);
                
                //--- Description ---//
                campo = strtok(NULL, ",");
                setDescription(pokemon[i], campo);
              
                //--- Types ---//
                campo = strtok(NULL, ",");
                pokemon[i]->types[0] = strdup(campo);

                campo = strtok(NULL, "\"");
                if (campo && strcmp(campo, ",") != 0) {
                    int length = strlen(campo);
                    campo[length-1] = '\0';
                    pokemon[i]->types[1] = strdup(campo);
                } else {
                    pokemon[i]->types[1] = NULL; // Se nqo houver segundo tipo
                }

                 //--- Abilities ---//
                campo = strtok(NULL, "\"");
                if (campo) {
                    tratarHabilidades(campo, pokemon[i]);
                }
               
                //--- Tratando os Campos apos habilidades ---//
                char *posicao = strchr(linhaCopia, ']');
                if (posicao != NULL) {
                    posicao += 2; // pula ]"
                    
                    float weight = 0.0, height = 0.0;
                    int captureRate = 0, isLegendary = 0;
                    Date date = {0, 0, 0};

                    // Verificar se os campos de peso e altura estao vazios
                    if (verificarCamposVazios(posicao)) {
                        // Tenta ler os demais valores (taxa de captura, lendario, e data de captura)
                        int numValoresLidos = sscanf(posicao + 3, "%d,%d,%d/%d/%d", 
                                                        &captureRate, &isLegendary, 
                                                        &date.dia, &date.mes, &date.ano);

                        if (numValoresLidos == 5) { 
                            setCaptureRate(pokemon[i], captureRate);
                            setIsLegendary(pokemon[i], (isLegendary == 1));
                            setCaptureDate(pokemon[i], date);
                        } 
                    } else {
                        // Tenta ler todos os campos com sscanf
                        int numValoresLidos = sscanf(posicao, ",%f,%f,%d,%d,%d/%d/%d", 
                                                    &weight, &height, 
                                                    &captureRate, &isLegendary, 
                                                    &date.dia, &date.mes, &date.ano);

                        if (numValoresLidos == 7) { //peso, altura, captura, lendario, dia, mês, ano)
                            // Atribuir os valores capturados
                            setWeight(pokemon[i], weight);
                            setHeight(pokemon[i], height);
                            setCaptureRate(pokemon[i], captureRate);
                            setIsLegendary(pokemon[i], (isLegendary == 1));
                            setCaptureDate(pokemon[i], date);
                        }                                                   
                    }  
                }    
            }
            i++;
        }
        fclose(arquivo);
        
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

//-------------- Metodo para imprimir Pokemons
void print(Pokemon *pok) {
    printf("[#%d -> %s: %s - ['%s'", pok->id, pok->name, pok->description, pok->types ? pok->types[0] : "N/A");
    
    // Tipo 1 se houver
    if (pok->types[1] != NULL) {
        printf(", '%s'", pok->types[1]);
    }

    // Habilidades
    for (int j = 0; pok->abilities[j] != NULL; j++) {
        if (j == 0) {
            printf("] - [");
        }
        printf("'%s'", pok->abilities[j]);
        if (pok->abilities[j + 1] != NULL) {
            printf(", ");
        }
    }

    printf("] - %.1fkg - %.1fm - %d%% - %s - %d gen] - %02d/%02d/%d\n", 
           pok->weight,
           pok->height,
           pok->captureRate,
           pok->isLegendary ? "true" : "false", 
           pok->generation, 
           pok->captureDate.dia, 
           pok->captureDate.mes, 
           pok->captureDate.ano);
}

//------ Funcao para buscar pokemon pelo ID
Pokemon *buscarPokemon(int id){
    Pokemon *pk = NULL;

    for (int i = 0; i < MAXTAM; i++) {
        Pokemon *pok = pokemon[i];  // Obtem o Pokemon na posição i
        if (pok != NULL && getId(pok) == id) {
            pk = pok;
            i = MAXTAM;
        }
    }
    return pk; //retorna o pokemon do ID
}

//---------- Swap para ordenacao
void swap(Pokemon *pokemon[], int i, int j){
    Pokemon *temp = pokemon[i];
    pokemon[i] = pokemon[j];
    pokemon[j] = temp;
}

//---------------- Metodo para ordenar pokemons pelo nome - Bubble Sort
void ordenar(Pokemon **pok, int cont){
    int last = cont - 1; //ultima posicao para swap

    for(int i=0; i < cont-1; i++){
        int newSwap = -1; 
        for(int j=0; j < last; j++){
            Pokemon *pk1 = pok[j]; //pokemon da posicao j
            Pokemon *pk2 = pok[j+1]; // //pokemon da posicao j+1
            if (strcmp(getName(pk1), getName(pk2)) > 0) {   //compara os pokemons pelos nomes
                swap(pok, j, j+1); //troca se necessario
                newSwap = j; //guarda a posicao do swap
            }
        }
        // se nao aconteceu swap
        if(newSwap == -1){
            i = cont;
        } 
        // se aconteceu guarda a posicao da ultima troca
        else last = newSwap;
   }
}

void gravarArquivo(double inicio, double fim, int comp){
    FILE *arquivo = fopen("matricula_binaria.txt", "wt");;
    double total = ((fim - inicio) / (double)CLOCKS_PER_SEC); 

    fprintf(arquivo, "Matricula: 860210\t");  
    fprintf(arquivo, "Tempo de Execução: %lf\t", total);
    fprintf(arquivo, "Numero de Comporações: %d\t", comp);	

    fclose(arquivo);
}

//-------------------- Metodo para buscar pokemon pelo nome utilizando Pesquisa Binaria
int pesquisaBinaria(Pokemon **pok, int cont, char nome[]){
    double total;
    int comparacoes = 0;

    bool resp = false;
    int dir = (cont - 1), esq = 0, meio;

    while (esq <= dir){
        meio = (esq + dir) / 2;
        Pokemon *pk = pok[meio]; //busca pokemon do meio
        
        if(strcmp(getName(pk), nome) == 0){ //se for o buscado
            resp = true;
            esq = dir + 1;
            comparacoes++;
        } else if (strcmp(nome, getName(pk)) > 0){ 
            esq = meio + 1;
            comparacoes++;
        } else {
            dir = meio - 1;
        }
    }

    if(resp) printf("SIM\n");
    else printf("NAO\n");

    return comparacoes;
}

//--------- Metodo Principal
int main(){
    char line[30];
    clock_t inicio, fim;
    int cont = 0, comparacoes = 0;
    Pokemon *pokemon[MAXTAM];

    ler(); // ler pokemons do arquivo

    scanf(" %[^\n]", line);  

    //loop para receber id e inserir em um novo vetor de pokemons
    while(strcmp(line, "FIM") != 0) {
        int id = atoi(line);
        pokemon[cont] = buscarPokemon(id);
        cont++;
        scanf(" %[^\n]", line);  
	}
    ordenar(pokemon, cont); //ordenacao para pesquisa binaria
  
    scanf(" %[^\n]", line);  
    while(strcmp(line, "FIM") != 0) {
        inicio += clock(); //tempo de execucao
        comparacoes += pesquisaBinaria(pokemon, cont, line);
        fim += clock();

        scanf(" %[^\n]", line);  
	}
     gravarArquivo(inicio, fim, comparacoes);
}

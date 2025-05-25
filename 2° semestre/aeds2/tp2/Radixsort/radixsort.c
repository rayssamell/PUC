/**
 * @path TP02Q14 - Radixsort
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
#define BASE 256 // Número de caracteres ASCII

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

int movimentacoes = 0;
int comparacoes = 0;

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
void print(Pokemon **pok, int n) {
    for(int i=0; i < n; i++){
        printf("[#%d -> %s: %s - ['%s'", pok[i]->id, pok[i]->name, pok[i]->description, pok[i]->types ? pok[i]->types[0] : "N/A");
        
        // Tipo 1 se houver
        if (pok[i]->types[1] != NULL) {
            printf(", '%s'", pok[i]->types[1]);
        }

        // Habilidades
        for (int j = 0; pok[i]->abilities[j] != NULL; j++) {
            if (j == 0) {
                printf("] - [");
            }
            printf("'%s'", pok[i]->abilities[j]);
            if (pok[i]->abilities[j + 1] != NULL) {
                printf(", ");
            }
        }

        printf("] - %.1fkg - %.1fm - %d%% - %s - %d gen] - %02d/%02d/%d\n", 
            pok[i]->weight,
            pok[i]->height,
            pok[i]->captureRate,
            pok[i]->isLegendary ? "true" : "false", 
            pok[i]->generation, 
            pok[i]->captureDate.dia, 
            pok[i]->captureDate.mes, 
            pok[i]->captureDate.ano);
    }
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

// Funca para obter o Pokemon com a maior habilidade
Pokemon *getMax(Pokemon **pok, int n) {
    Pokemon *maior = pok[0];

    for (int i = 1; i < n; i++) {
        // Comparar habilidades usando strcmp
        if (strcmp(maior->abilities[0], pok[i]->abilities[0]) < 0) {
            maior = pok[i];
            comparacoes++;
        }
    }
    return maior;
}

// Metodo Radix Sort para ordenar Pokemons por habilidades
void radcountingSort(Pokemon **pokemon, int n, int exp) {
    int count[BASE] = {0}; // Contagem para caracteres ASCII
    Pokemon **output = (Pokemon **)malloc(n * sizeof(Pokemon *)); // Array auxiliar

    // Contar a frequencia das habilidades
    for (int i = 0; i < n; i++) {
        char d = pokemon[i]->abilities[0][exp];
        count[(int)d]++;
        movimentacoes++;
    }

    // Ajustar o array de contagem
    for (int i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
        movimentacoes++;
    }

    // Array de saida
    for (int i = n - 1; i >= 0; i--) {
        char d = pokemon[i]->abilities[0][exp]; 
        output[count[(int)d] - 1] = pokemon[i];
        count[(int)d]--;
        movimentacoes++;
    }

    // Copiar os Pokemons de volta para o array original
    for (int i = 0; i < n; i++) {
        pokemon[i] = output[i];
        movimentacoes++;
    }

    free(output); // Liberar memoria do array auxiliar
}

//--------------------------- Metodo Radix Sort principal
void radixsort(Pokemon **pokemon, int n) {
   
    Pokemon *max = getMax(pokemon, n);  // encontrar a maior habilidade
    int max_length = strlen(max->abilities[0]); //guarda a quantidade de caracteres

    // Ordenacao baseada em cada caractere da primeira habilidade
    for (int exp = max_length - 1; exp >= 0; exp--) { 
        radcountingSort(pokemon, n, exp);
    }

    // Se as habilidades forem iguais, ordena pelo nome
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(pokemon[j]->abilities[0], pokemon[j + 1]->abilities[0]) == 0) {
                comparacoes++;
                // comparar pelo nome
                if (strcmp(pokemon[j]->name, pokemon[j + 1]->name) > 0) {
                    comparacoes++;
                    // Trocar os Pokemons de lugar
                    Pokemon *temp = pokemon[j];
                    pokemon[j] = pokemon[j + 1];
                    pokemon[j + 1] = temp;
                    movimentacoes+=3;
                }
            }
        }
    }
}

void gravarArquivo(double inicio, double fim){
    FILE *arquivo = fopen("matricula_radixsort.txt", "wt");;
    double total = ((fim - inicio) / (double)CLOCKS_PER_SEC); 

    fprintf(arquivo, "Matricula: 860210\t");  
    fprintf(arquivo, "Numero de Comparacoes: %d\t", comparacoes);
    fprintf(arquivo, "Numero de Movimentações: %d\t", movimentacoes);
    fprintf(arquivo, "Tempo de Execução: %lf\t", total);	

    fclose(arquivo);
}

//--------- Metodo Principal
int main(){
    char line[30];
    double inicio, fim;
    Pokemon *pokemon[MAXTAM];
    int n = 0;

    ler(); 
    scanf(" %[^\n]", line);  

    //loop para receber id e inserir em um novo vetor de pokemons
    while(strcmp(line, "FIM") != 0) {
        int id = atoi(line);
        pokemon[n] = buscarPokemon(id);
        n++;
        scanf(" %[^\n]", line);  
	}

    //inicializar contadores globais
    movimentacoes = 0;
    comparacoes = 0;

    // Marcando tempo de execucao para radixsort //
    inicio += clock();  
    radixsort(pokemon, n); 
    fim += clock();

    print(pokemon, n);
    gravarArquivo(inicio, fim);
}
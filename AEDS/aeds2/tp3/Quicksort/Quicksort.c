/**
 * @path TP03Q08 - Quicksort com Lista Duplamente Encadeada
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

Pokemon *pokemon[MAXTAM]; 

int movimentacoes = 0; //contador de movimentacoes
int comparacoes = 0; // contador de comparacoes

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

//------ Funcao para buscar pokemon pelo ID
Pokemon *buscarPokemon(int id){
    Pokemon *pk = NULL;

    for (int i = 0; i < MAXTAM; i++) {
        Pokemon *pok = pokemon[i];  // Obtem o Pokemon na posicao i
        if (pok != NULL && getId(pok) == id) {
            pk = pok;
            i = MAXTAM;
        }
    }
    return pk; //retorna o pokemon do ID
}

//-------------- LISTA DUPLA -------------------//

typedef struct CelulaDupla {
	Pokemon *elemento;        
	struct CelulaDupla* prox; 
   struct CelulaDupla* ant;  
} CelulaDupla;

typedef struct ListaDupla {
    CelulaDupla* primeiro;
    CelulaDupla* ultimo;
    int n; //tamanho
} ListaDupla;

CelulaDupla* novaCelulaDupla(Pokemon *elemento) {
   CelulaDupla* nova = (CelulaDupla*) malloc(sizeof(CelulaDupla));
   nova->elemento = elemento;
   nova->ant = nova->prox = NULL;
   return nova;
}

ListaDupla *novaListaDupla(){
    ListaDupla* listaDupla = (ListaDupla*) malloc(sizeof(ListaDupla));
    listaDupla->primeiro = novaCelulaDupla(NULL);
    listaDupla->ultimo = listaDupla->primeiro;
    listaDupla->n = 0;

    return listaDupla;
}

//Funcao para inserir no fim da lista
void inserirFim(Pokemon *pk, ListaDupla *listaDupla) {
   listaDupla->ultimo->prox = novaCelulaDupla(pk);
   listaDupla->ultimo->prox->ant = listaDupla->ultimo;
   listaDupla->ultimo = listaDupla->ultimo->prox;
   listaDupla->n++;
}

//Buscar celula do meio
CelulaDupla* buscarMeio(CelulaDupla* esq, CelulaDupla* dir) {
    CelulaDupla *cel;
    if (!esq || !dir) cel = NULL;  // Verificar se 'esq' e 'dir' são validos

    cel = esq;
    int count = 0;

    // Contar o numero de celulas entre 'esq' e 'dir'
    while (cel != NULL && cel != dir) {
        count++;
        cel = cel->prox;
    }

    // encontrar a celula do meio
    cel = esq;
    for (int i = 0; i < count / 2; i++) {
        cel = cel->prox;
    }

    return cel; // Retorna a celula
}

//---------- --------- Swap para ordenacao
void swap(CelulaDupla *i, CelulaDupla *j) {
    Pokemon *temp = i->elemento;
    i->elemento = j->elemento;
    j->elemento = temp;
}

// Ordenacao Quicksort - Recursiva
void quicksortRec(CelulaDupla* esq, CelulaDupla* dir) {

   if (esq == NULL || dir == NULL || esq == dir || esq == dir->prox) return;

    // Buscar o pivo - elemento do meio
    CelulaDupla* meio = buscarMeio(esq, dir);
    char *pivoNome = getName(meio->elemento);
    int pivo = getGeneration(meio->elemento);

    CelulaDupla* i = esq;
    CelulaDupla* j = dir;

    while (i != NULL && j != NULL && i != j && i != j->prox) {
        // Primeiro faz a comparacao pela geracao, se for igual compara o nome
        while (getGeneration(i->elemento) < pivo || 
            (getGeneration(i->elemento) == pivo && strcmp(getName(i->elemento), pivoNome) < 0)) {
            i = i->prox;
            comparacoes++;
        }

        while (getGeneration(j->elemento) > pivo || 
            (getGeneration(j->elemento) == pivo && strcmp(getName(j->elemento), pivoNome) > 0)) {
            j = j->ant;
            comparacoes++;
        }


        if (i != NULL && j != NULL && i != j && i != j->prox) {
            swap(i, j);
            movimentacoes += 3;  // Contar 3 movimentacoes
        }
    }

    if (esq != j) quicksortRec(esq, j->ant); 
    if (i != dir) quicksortRec(i->prox, dir);
}

// chamada recursiva
void quicksort(ListaDupla *listaDupla) {
    quicksortRec(listaDupla->primeiro->prox, listaDupla->ultimo);
}

//-------------- Metodo para imprimir Pokemons
void print(ListaDupla *listaDupla) {
    for(CelulaDupla *i=listaDupla->primeiro->prox; i != NULL; i=i->prox){
        Pokemon* pok = i->elemento;
        printf("[#%d -> %s: %s - ['%s'", pok->id, pok->name, pok->description, pok->types ? pok->types[0] : "N/A");
        
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
}

//Arquivo com tempo de execucao, n° de comparacoes e movimentacoes
void gravarArquivo(double inicio, double fim){
    FILE *arquivo = fopen("matricula_quicksort2.txt", "wt");;
    double total = ((fim - inicio) / (double)CLOCKS_PER_SEC); 

    fprintf(arquivo, "Matricula: 860210\t");  
    fprintf(arquivo, "Numero de Comparações: %d\t", comparacoes);	
    fprintf(arquivo, "Numero de Movimentações: %d\t", movimentacoes);
    fprintf(arquivo, "Tempo de Execução: %lf\t", total);

    fclose(arquivo);
}

//--------- Metodo Principal
int main(){
    char line[30];
    double inicio, fim;
    ListaDupla *listaDupla = novaListaDupla();
    Pokemon *pk;

    ler(); 
    scanf(" %[^\n]", line);  

    while(strcmp(line, "FIM") != 0) {
        int id = atoi(line);
        pk = buscarPokemon(id);
        inserirFim(pk, listaDupla);
        
        scanf(" %[^\n]", line);  
	}
   
    //inicializando variaveis globais para contagem
    movimentacoes = 0;
    comparacoes = 0;
    
    // Marcando tempo de execucao para quicksort //
    inicio += clock();  
    quicksort(listaDupla); 
    fim += clock();

    print(listaDupla);
    gravarArquivo(inicio, fim);
}
/**
 * @path TP02Q17 - Heapsort Parcial
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
    double weight;
    double height;
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
double getWeight(Pokemon *pokemon){
    return pokemon->weight;
} 
void setWeight(Pokemon *pokemon, double weight){
    pokemon->weight = weight;
}
double getHeight(Pokemon *pokemon){
    return pokemon->height;
}
void setHeight(Pokemon *pokemon, double height){
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
                    
                    double weight = 0.0, height = 0.0;
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
                            setWeight(pokemon[i], 0.0);
                            setHeight(pokemon[i], 0.0);
                        } 
                    } else {
                        // Tenta ler todos os campos com sscanf
                        int numValoresLidos = sscanf(posicao, ",%lf,%lf,%d,%d,%d/%d/%d", 
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

//---------- Swap para ordenacao
void swap(Pokemon **pokemon, int i, int j){
    Pokemon *temp = pokemon[i];
    pokemon[i] = pokemon[j];
    pokemon[j] = temp;
}

// ---- Metodo para construcao do Heap ---//
void construir(Pokemon **pokemon, int tamHeap){
    int i=tamHeap; 
    
    while(i > 1){
        int compare = strcmp(getName(pokemon[i]), getName(pokemon[i/2]));
        //se os height sao diferentes, compara
        if(getHeight(pokemon[i]) > getHeight(pokemon[i/2])){
            swap(pokemon, i, i/2);
            i /= 2;
        } else if (getHeight(pokemon[i]) == getHeight(pokemon[i/2]) && compare > 0) { 
            // se os heights sao iguais, ordena pelo nome
            swap(pokemon, i, i / 2);  
            i /= 2;
        } else {
            i = 1;
        }
    } 
}

// ---- Metodo para buscar o maior filho ---//
int getMaiorFilho(Pokemon **pokemon, int i, int tamHeap){
    int filho = 0;

    // Verifica se apenas o filho da esquerda existe
    if (2 * i == tamHeap) {
        filho = 2 * i; 
    } else {
        // Compara os filhos da direita e da esquerda
        Pokemon *filhoEsq = pokemon[2*i];
        Pokemon *filhoDir = pokemon[2*i+1];

        int compare = strcmp(getName(filhoEsq), getName(filhoDir));

        //Compara pelo height
        if (getHeight(filhoEsq) > getHeight(filhoDir)){
            filho = 2 * i; 
        }
        //Se o height for igual, desempata pelo nome
        else if(getHeight(filhoEsq) == getHeight(filhoDir) && compare > 0) {
            filho = 2 * i;  
        } else {
            filho = 2 * i + 1;  
        }
    }
    return filho;
}

// ---- Metodo para reconstrucao do Heap ---//
void reconstruir(Pokemon **pokemon, int tamHeap){
    int i = 1;

    while(i <= (tamHeap / 2)){
        int filho = getMaiorFilho(pokemon, i, tamHeap);
        int compare = strcmp(getName(pokemon[i]), getName(pokemon[filho]));

        // Compara height, se igual compara nome
        if (getHeight(pokemon[i]) == getHeight(pokemon[filho]) && compare < 0) {
            swap(pokemon, i, filho);
            i = filho;
        } 
        // Compara height
        else if (getHeight(pokemon[i]) < getHeight(pokemon[filho])) {
            swap(pokemon, i, filho);
            i = filho;
        } else {
            i = tamHeap;
        }
    }
}

//---------------------------- Heapsort Parcial paa ordenar o k primeiros elementos
void heapsortParcial(Pokemon **pokemon, int n, int k) {
    
    Pokemon **tmp = (Pokemon**)malloc((n + 1) * sizeof(Pokemon*));

    // Copia os Pokémon para o array temporário, começando do indice 1
    for (int i = 0; i < n; i++) {
        tmp[i + 1] = pokemon[i]; // Copia para tmp[1] a tmp[n]
    }

    // Construcao do heap com os k primeiros elementos
    for (int tam = 2; tam <= k; tam++) {
        construir(tmp, tam);
    }

    // Para cada um dos (n - k) demais elementos
    for (int i = k + 1; i <= n; i++) {
        // Se o height for igual, compara os nomes
        if (getHeight(tmp[i]) == getHeight(tmp[1])) {
            if (strcmp(getName(tmp[i]), getName(tmp[1])) < 0) {
                swap(tmp, i, 1);    // Troca o elemento com a raiz
                reconstruir(tmp, k); // Reconstroi o heap até o k-esimo elemento
            }
        }
        // height diferentes: se o elemento for menor que a raiz, troca e reconstroi o heap
        else if (getHeight(tmp[i]) < getHeight(tmp[1])) {
            swap(tmp, i, 1);    // Troca o elemento com a raiz
            reconstruir(tmp, k); // Reconstroi o heap até o k-esimo elemento
        }
        
    }

    // Ordenação propriamente dita dos k elementos
    int tam = k;
    while (tam > 1) {
        swap(tmp, 1, tam--);   // Troca a raiz com o eltimo elemento do heap
        reconstruir(tmp, tam);  // Reconstroi o heap 
    }

    // Copia os elementos ordenados de volta para o array original
    for (int i = 0; i < n; i++) {
        pokemon[i] = tmp[i + 1]; //array original começa na posicao 0
    }

    // Libera a memoria alocada
    free(tmp);
}


//--------- Metodo Principal
int main(){
    char line[30];
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
    heapsortParcial(pokemon, n, 10); 
    print(pokemon, 10);
}

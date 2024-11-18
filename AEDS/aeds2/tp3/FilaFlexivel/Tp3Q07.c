/**
 * @path TP03Q07 - Fila Circular Flexivel em c
 * @author Rayssa Mell de Souza Silva
 */

//-----------imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

//caminho para arquivo
#define FILE_PATH "/tmp/pokemon.csv"

#define MAXTAM 801
#define MAXFILA 5
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

Pokemon *pokemon[MAXTAM]; //lista de ponteiros para pokemons do arquivo

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
                    pokemon[i]->types[1] = NULL; // Se nao houver segundo tipo
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

//--------------- FILA CIRCULAR FLEXIVEL -------------------//

//struct Celula
typedef struct Celula{
    Pokemon *elemento;
    struct Celula *prox;
} Celula;

//Inicializar Celula
Celula* newCelula(Pokemon *pokemon){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = pokemon;
    nova->prox = NULL;

    return nova;
}

//Struct Fila Flexivel
typedef struct Fila {
    Celula *primeiro;
    Celula *ultimo;
    int n;
} Fila;

//Incializar fila flexivel
Fila* newFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->n = 0;
    fila->primeiro = newCelula(NULL); 
    fila->ultimo = fila->primeiro;

    return fila;
}

//Funcao para calcular media pelo captureRate
double calcularMedia(Fila *fila) {
    int soma = 0;

    for (Celula *i = fila->primeiro->prox; i != NULL; i = i->prox) {
        soma += i->elemento->captureRate;
    }

    double media = (double) soma / fila->n; 

    return media; 
}

//Remover pokemon da fila circular
Pokemon* remover(Fila *fila) {
    if (fila->primeiro == fila->ultimo) {
        printf("ERRO: Fila Vazia\n");
        exit(1);
    }
    Celula *tmp = fila->primeiro->prox;
    Pokemon *pok = tmp->elemento;
    fila->primeiro->prox = tmp->prox;
    
    if (tmp == fila->ultimo) { 
        fila->ultimo = fila->primeiro;
    }
    tmp->prox = NULL;
    free(tmp);
    fila->n--; //diminui tamanho

    return pok;
}

//------------- Liberar Fila
void liberarFila(Fila *fila) {
    if (fila != NULL) {
        while (fila->primeiro != fila->ultimo) {
            remover(fila); 
        }
        free(fila->primeiro);
        fila->primeiro = fila->ultimo = NULL;
        free(fila);
        fila = NULL;
    }
}

//-------  Insere um Pokemon na fila circular
void inserir(Fila *fila, Pokemon *pokemon) {
    if (fila->n == MAXFILA) {
        Pokemon* pok = remover(fila);
    }
    Celula* tmp = newCelula(pokemon);  
    fila->ultimo->prox = tmp;          
    fila->ultimo = tmp;                
    fila->n++;  //aumenta tamanho

    //calcula media a cada insercao
    printf("Média: %.0lf\n", calcularMedia(fila));
}

//-------------- Metodo para imprimir Pokemons
void print(Fila *fila) {
    int j = 0;
    for(Celula* i= fila->primeiro->prox; i != NULL; i=i->prox){
        Pokemon* p = i->elemento;

        printf("[%d] [#%d -> %s: %s - ['%s'", j, p->id, p->name, p->description, p->types ? p->types[0] : "N/A");
        
        if (p->types[1] != NULL) {
            printf(", '%s'", p->types[1]);
        }

        // Habilidades
        for (int j = 0; p->abilities[j] != NULL; j++) {
            if (j == 0) {
                printf("] - [");
            }
            printf("'%s'", p->abilities[j]);
            if (p->abilities[j + 1] != NULL) {
                printf(", ");
            }
        }

        printf("] - %.1fkg - %.1fm - %d%% - %s - %d gen] - %02d/%02d/%d\n", 
            p->weight,
            p->height,
            p->captureRate,
            p->isLegendary ? "true" : "false", 
            p->generation, 
            p->captureDate.dia, 
            p->captureDate.mes, 
            p->captureDate.ano);

        j++;
    }
}

//---- Procedimento para buscar pokemon
Pokemon* buscarPokemon(int id){
    Pokemon* pk;
    for (int i = 0; i < MAXTAM; i++) {
        Pokemon *pok = pokemon[i];  // Obtem o Pokemon na posição i
        if (pok != NULL && getId(pok) == id) {
            pk = pok;
            i = MAXTAM;
        }
    }
    return pk; //retorna o pokemon encontrado
}

//-------------- Mostrar Pokemon removido
void mostrarRemovido(Pokemon *pok){
    printf("(R) %s\n", getName(pok));
}

//--------- Metodo Principal
int main(){
    char line[8];
    Fila *fila = newFila(); //criar Fila
    Pokemon *pk = NULL;

    ler(); //ler arquivo

    scanf(" %[^\n]", line);  
    
    int id = 0;
    while(strcmp(line, "FIM") != 0) {
        id = atoi(line);
        pk = buscarPokemon(id); //buscar pokemon do id
        inserir(fila, pk); // inserir ponteiro para pokemon na lista

        scanf(" %[^\n]", line);  
	}
    int n = 0;
    id = 0;

    scanf("%d", &n); //ler quantidade de operacoes
    
    for(int i=0; i < n; i++){ 
        //------- Tratando entrada -------//
        scanf(" %s", line);

        if(line[0] == 'I'){
            scanf("%d", &id);
            pk = buscarPokemon(id);
            inserir(fila, pk);
        } else if(line[0] == 'R'){
            pk = remover(fila);
            mostrarRemovido(pk);
        }
    }
    
    printf("\n");
    print(fila); //mostrar fila

    liberarFila(fila);
}
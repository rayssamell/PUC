/**
 * @path TP03Q05 - Lista com Alocacao Flexivel em c
 * @author Rayssa Mell de Souza Silva
 */

//-----------imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

//----------------- Struct Celula
typedef struct Celula {
	Pokemon *elemento;        // Elemento inserido na celula.
	struct Celula* prox; // Aponta a celula prox.
} Celula;

Celula* novaCelula(Pokemon *elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;
   return nova;
}

Pokemon *pokemon[MAXTAM]; //lista de ponteiros para pokemons do arquivo

//----------- Struct Lista Flexivel
typedef struct {
    Celula* primeiro;
    Celula* ultimo;
    int n; 
} Lista;

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
    char linhaCopia[803];
    char *campo;
    int i = 0;
    int linhaAtual = 0;
   
    if (arquivo != NULL) {
        while (fgets(linha, sizeof(linha), arquivo) != NULL && i < 802 ) {
            linhaAtual++;
            if (linhaAtual != 1) { //pula a primeira linha
            
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

//-------------- Metodo para imprimir Pokemons
void print(Lista *lista) {
    int j = 0;
    for(Celula* i= lista->primeiro->prox; i != NULL; i=i->prox){
        Pokemon* p = i->elemento;

        printf("[%d] [#%d -> %s: %s - ['%s'", j, p->id, p->name, p->description, p->types ? p->types[0] : "N/A");
        
        // Tipo 1 se houver
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

//--------------- LISTA FLEXIVEL -------------------------//

//Inicializar lista
Lista* newLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->n = 0;
    lista->primeiro = novaCelula(NULL); 
    lista->ultimo = lista->primeiro;
    return lista;
}

//-------  Insere um Pokemon no Inicio da lista e move os demais para o fim
void inserirInicio(Lista *lista, Pokemon *pokemon){
    if(lista->n >= MAXTAM){
        printf("ERRO: Lista Cheia\n");
    }
    Celula *tmp = novaCelula(pokemon);
    tmp->prox = lista->primeiro->prox;
    lista->primeiro->prox = tmp;   

    if (lista->primeiro == lista->ultimo) {                    
      lista->ultimo = tmp;
    }
    lista->n++;
    tmp = NULL;
}

 //------------- Inserir pokemon no fim da lista
void inserirFim(Lista *lista, Pokemon *pokemon){
    if(lista->n >= MAXTAM){
        printf("ERRO: Lista Cheia\n");
    }
    Celula* tmp = novaCelula(pokemon);  
    lista->ultimo->prox = tmp;          
    lista->ultimo = tmp;                
    lista->n++;  
}

//----- Inserir em posicao especifica
void inserir(Lista *lista, Pokemon *pokemon, int pos){
    if(lista->n >= MAXTAM || pos < 0 || pos > lista->n){
        printf("ERRO\n");
    }
    int j;
    Celula* i = lista->primeiro;
    for(j = 0; j < pos; j++, i = i->prox);

    Celula* tmp = novaCelula(pokemon);
    tmp->prox = i->prox;
    i->prox = tmp;
    tmp = i = NULL;
    lista->n++;
}

//------------- Remover pokemon do inicio da lista
Pokemon* removerInicio(Lista *lista){
    if(lista->primeiro == lista->ultimo || lista->n == 0){
        printf("ERRO: Lista Vazia\n");
    }
    
    Celula *tmp = lista->primeiro->prox; 
    lista->primeiro->prox = tmp->prox; 
    Pokemon *pk = tmp->elemento; // elemento removido

    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;

    lista->n--; //diminui tamanho
    
    return pk; //retorna o apontamento para o pokemon removido
}

//------------- Remover pokemon do fim da lista flexivel
Pokemon* removerFim(Lista *lista){
    if(lista->primeiro == lista->ultimo || lista->n == 0){
        printf("ERRO: Lista Vazia\n");
    }
    // Caminhar ate a penultima celula:
    Celula* i;
    for(i = lista->primeiro; i->prox != lista->ultimo; i = i->prox);
    Pokemon *pk = lista->ultimo->elemento; //elemento a ser removido
    lista->ultimo = i;

    free(lista->ultimo->prox);
    i = lista->ultimo->prox = NULL;
    lista->n--; // diminuir tamanho

    return pk; //retornar pokemon removido
}

//------------- Remover Pokemon em posicao especifica
Pokemon* remover(Lista *lista, int pos){
    if(lista->primeiro == lista->ultimo || lista->n == 0){
        printf("ERRO: Lista Vazia\n");
    }
    Pokemon *pk;

    Celula* i = lista->primeiro;
    // Caminhar ate a posicao anterior a insercao
    for(int j = 0; j < pos; j++, i = i->prox);

    Celula* tmp = i->prox; 
    pk = tmp->elemento;
    i->prox = tmp->prox;  
    
    tmp->prox = NULL;
    free(tmp);
    i = tmp = NULL;
    
    lista->n--; //diminui tamanho

    return pk;
}

//-------------- Mostrar Pokemon removido
void mostrarRemovido(Pokemon *pok){
    printf("(R) %s\n", getName(pok));
}

//----- Buscar operacao a ser realizada 
int getOperacao(char *operacao){
    int resp = -1;
    if(operacao[0] == 'R' && operacao[1] == 'I'){
        resp = 0; // 0 para Remover no Inicio
    } else if(operacao[0] == 'R' && operacao[1] == 'F'){
        resp = 1; // 1 para Remover no Fim
    } else if(operacao[0] == 'I' && operacao[1] == 'I'){
        resp = 2; // 2 para Inserir no Inicio
    } else if(operacao[0] == 'I' && operacao[1] == 'F') {
        resp = 3; // 3 para Inserir no Fim
    }
    return resp;
}

//--------- Metodo Principal
int main(){
    char line[8];
    Lista *lista = newLista(); //criar Lista
    
    Pokemon *pk; //apontador para pokemon
    ler(); //ler arquivo

    scanf(" %[^\n]", line);  
    
    while(strcmp(line, "FIM") != 0) {
        int id = atoi(line); //converter char para int
        pk = buscarPokemon(id); //buscar pokemon do id
        inserirFim(lista, pk); // inserir pokemon na lista
        scanf(" %[^\n]", line);  
	}

    int n = 0;
    int pos = 0;
    int id = 0;

    scanf("%d", &n); //ler quantidade de operacoes
    
    for(int i=0; i < n; i++){ 
        //------- Tratando entrada -------//
        scanf(" %s", line);
    
        //Se for, R* ou I*
        if (line[1] == '*') { 
            scanf("%d", &pos);// Le a posicao
            
            //Remover na posicao
            if(line[0] == 'R'){
                pk = remover(lista, pos);
                mostrarRemovido(pk);
            } else {
                //Inserir na posicao
                scanf("%d", &id);
                pk = buscarPokemon(id);
                inserir(lista, pk, pos);
            }
        } else {
            //chamar metodo para descobir a operacao
            int op = getOperacao(line);
    
            if(op == 0){
                pk = removerInicio(lista);
                mostrarRemovido(pk);
            } else if(op == 1){
                pk = removerFim(lista);
                mostrarRemovido(pk);
            } else if (op == 2) {
                scanf("%d", &id);
                pk = buscarPokemon(id);
                inserirInicio(lista, pk);
            } else if(op == 3) {
                scanf("%d", &id);
                pk = buscarPokemon(id);
                inserirFim(lista, pk);
            }
        }  
    }
    print(lista); //mostrar lista
}

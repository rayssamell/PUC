/**
 * @path TP04Q03 - AVL em c
 * @author Rayssa Mell de Souza Silva
 */

//-----------imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
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

Pokemon *pokemon[MAXTAM]; //lista de ponteiros para pokemons lidos do arquivo
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

//---- Procedimento para buscar pokemon pelo id
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

// ----------- AVL ---------------//

// Struct No
typedef struct No {
	Pokemon *elemento; // Conteudo do no.
	struct No *esq;
    struct No *dir; // Filhos da esq e dir.
	int nivel; // Numero de niveis abaixo do no
} No;

No* createNo(Pokemon *elemento) {
	No *no = (No*)malloc(sizeof(No));
    no->elemento = elemento;
    no->esq = NULL;
    no->dir = NULL;
    no->nivel = 1;   

    return no;
}

//Struct AVL
typedef struct AVL {
	No* raiz; // Raiz da arvore.
} AVL;

AVL* createAVL() {
	AVL *avl = (AVL*)malloc(sizeof(AVL));
    avl->raiz = NULL;

    return avl;
}

//buscar nivel
int getNivel(No *no) {
	return (no == NULL) ? 0 : no->nivel;
}

//colocar nivel
void setNivel(No *i) {
    if (i != NULL) {
        int nivelEsq = getNivel(i->esq);
        int nivelDir = getNivel(i->dir);
        i->nivel = 1 + (nivelEsq > nivelDir ? nivelEsq : nivelDir);
    }
}

// Rotacionar para direita
No* rotacionarDir(No *no) {
	No *noEsq = no->esq;
	No *noEsqDir = noEsq->dir;

	noEsq->dir = no;
	no->esq = noEsqDir;
	setNivel(no); // Atualizar o nivel do no
	setNivel(noEsq); // Atualizar o nivel do noEsq
	
    return noEsq;
}

// Rotacionar para esquerda
No *rotacionarEsq(No *no) {
    No *noDir = no->dir;
    No *noDirEsq = noDir->esq;

    noDir->esq = no;
    no->dir = noDirEsq;

    setNivel(no); // Atualizar o nivel do no
    setNivel(noDir); // Atualizar o nivel do noDir
    return noDir;
}

//Balancear
No *balancear(No *no) {
    if (no != NULL) {
        int fator = getNivel(no->dir) - getNivel(no->esq);
        // Se balanceada
        if (abs(fator) <= 1) {
            comparacoes++;
            setNivel(no);
        // Se desbalanceada para a direita
        } else if (fator == 2) {
            comparacoes++;
            int fatorFilhoDir = getNivel(no->dir->dir) - getNivel(no->dir->esq);
            // Se o filho a direita tambem estiver desbalanceado
            if (fatorFilhoDir == -1) {
                comparacoes++;
                no->dir = rotacionarDir(no->dir);
            }
            no = rotacionarEsq(no);
        // Se desbalanceada para a esquerda
        } else if (fator == -2) {
            comparacoes++;
            int fatorFilhoEsq = getNivel(no->esq->dir) - getNivel(no->esq->esq);
            // Se o filho a esquerda tambem estiver desbalanceado
            if (fatorFilhoEsq == 1) {
                comparacoes++;
                no->esq = rotacionarEsq(no->esq);
            }
            no = rotacionarDir(no);
        }
    }
    return no;
}

//Inserir na avl
No *inserir(Pokemon *pok, No *i) {
    if (i == NULL) {
        i = createNo(pok);
    } else if (strcmp(i->elemento->name, pok->name) > 0) {
        comparacoes++;
        i->esq = inserir(pok, i->esq);
    } else if (strcmp(i->elemento->name, pok->name) < 0) {
        comparacoes++;
        i->dir = inserir(pok, i->dir);
    } 
    return balancear(i);
}

//Metodo recursivo para chamar insercao
void inserirRec(Pokemon *pok, AVL *avl) {
    avl->raiz = inserir(pok, avl->raiz);
}

//Pesquisar na avl
bool pesquisar(char *nome, No *i) {
    bool resp;
    if (i == NULL) {
        resp = false;
    } else if (strcmp(i->elemento->name, nome) == 0) {
        comparacoes++;
        resp = true;
    } else if (strcmp(i->elemento->name, nome) > 0) {
        comparacoes++;
        printf(" esq");
        resp = pesquisar(nome, i->esq);
    } else {
        comparacoes++;
        printf(" dir");
        resp = pesquisar(nome, i->dir);
    }
    return resp;
}

//Metodo recursivo para chamar o pesquisar
bool pesquisarRec(char *nome, AVL *avl) {
    printf("raiz");
	return pesquisar(nome, avl->raiz);
}

//Arquivo com tempo de execucao, n° de comparacoes e movimentacoes
void gravarArquivo(double inicio, double fim){
    FILE *arquivo = fopen("matricula_avl.txt", "wt");;
    double total = ((fim - inicio) / (double)CLOCKS_PER_SEC); 

    fprintf(arquivo, "Matricula: 860210\t");  
    fprintf(arquivo, "Numero de Comparações: %d\t", comparacoes);	
    fprintf(arquivo, "Tempo de Execução: %lf\t", total);

    fclose(arquivo);
}

//----------------- Metodo Principal
int main() {
    double inicio, fim;
    ler(); // ler do arquivo

    AVL *avl = createAVL(); 
    Pokemon *pk;

    char line[25];
    
    while(strcmp(line, "FIM") != 0) {
        int id = atoi(line);
        pk = buscarPokemon(id); //buscar pokemon do id
        inserirRec(pk, avl);
        scanf(" %[^\n]", line);  
	}

    comparacoes = 0;
    scanf(" %[^\n]", line);  
    while(strcmp(line, "FIM") != 0) {
        printf("%s\n", line);

        inicio += clock();  
        bool resp = pesquisarRec(line, avl);
        fim += clock();  
        
        if(resp) printf(" SIM\n");
        else printf(" NAO\n");

        scanf(" %[^\n]", line);  
	}
    gravarArquivo(inicio, fim);
}
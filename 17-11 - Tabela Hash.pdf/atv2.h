/* Arquivo: fila.h
 * Biblioteca de operações para fila implementada com alocação dinâmica de
 * memória.
 */
#define VERDADEIRO 1
#define FALSO 0

typedef struct TipoNodo *fila;
typedef struct TipoNodo *pt_nodo;

typedef struct TipoNodo {
    elemento e;
    pt_nodo prox;
} nodo;

/*
 * Cria uma fila vazia.
 */
void CriarFila(fila *f) {
    *f = NULL;
}

/*
 * Verifica se a fila está vazia.
 */
int FilaVazia(fila *f) {
    return (*f == NULL);
}

/*
 * Insere um novo elemento no final da fila.
 */
void Enfileirar(fila *f, elemento *x) {
    pt_nodo novoNodo = (pt_nodo)malloc(sizeof(nodo));
    novoNodo->e = *x;
    novoNodo->prox = NULL;

    if (*f == NULL) {
        *f = novoNodo;
    } else {
        pt_nodo ultimo = *f;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = novoNodo;
    }
}

/*
 * Desenfileira o elemento do início da fila.
 * A fila não pode estar vazia.
 */
elemento Desenfileirar(fila *f) {
    elemento x;
    pt_nodo primeiro = *f;
    *f = primeiro->prox;
    x = primeiro->e;
    free(primeiro);
    return x;
}

/*
 * Procura um elemento na fila.
 * Retorna o nodo anterior ao elemento procurado.
 * Se o elemento procurado estiver na fila, retorna VERDADEIRO.
 * Se o elemento procurado não estiver na fila, retorna FALSO.
 */
pt_nodo *PesquisarFila(fila *f, char *x) {
    pt_nodo *p = NULL;
    pt_nodo atual = *f;

    while (atual != NULL) {
        if (strcmp(atual->e.palavra, x) == 0) {
            p = &atual;
            break;
        } else {
            atual = atual->prox;
        }
    }
    return p;
}

//Com essas alterações, a estrutura de dados fila é usada em vez de lista, e as operações foram ajustadas para refletir a natureza de uma fila, onde a inserção ocorre no final (Enfileirar) e a remoção ocorre no início (Desenfileirar).

//Estrutura de Dados:
//Afila é definida como um ponteiro para o tipo TipoNodo. É a estrutura TipoNodopermanente:

//Funções e Operações:
//CriarFila: Inicializa a fila como vazia, ou seja, aponta para NULL.
//FilaVazia: Verifica se a fila está vazia.
//Enfileirar: Adiciona um novo elemento ao final da fila. Se a fila estiver vazia, cria o primeiro nodo; caso contrário, percorre a fila até o último elemento e adiciona o novo nodo no final.

//Desenfileirar:
//PesquisarFila: Pró
//Essas alterações transformam a estrutura de dados de uma lista encadeada para uma fila, mantendo as operações semelhantes à manipulação de uma fila. A principal diferença está nas operações Enfileirar e Desenfileirar, que respeitam a lógica de uma fila FIFO (First-In-First-Out).
/* Arquivo: arvore_binaria.h
 * Biblioteca de operações para árvore binária de pesquisa implementada com
 * alocação dinâmica de memória.
 */
#define VERDADEIRO 1
#define FALSO 0

typedef struct TipoNodo *arvore_binaria;
typedef struct TipoNodo *pt_nodo;

typedef struct TipoNodo {
    elemento e;
    pt_nodo esquerda;
    pt_nodo direita;
} nodo;

/*
 * Cria uma árvore binária vazia.
 */
void CriarArvoreBinaria(arvore_binaria *arvore) {
    *arvore = NULL;
}

/*
 * Verifica se a árvore binária está vazia.
 */
int ArvoreVazia(arvore_binaria *arvore) {
    return (*arvore == NULL);
}

/*
 * Insere um novo elemento na árvore binária.
 */
void InserirNaArvore(arvore_binaria *arvore, elemento *x) {
    if (*arvore == NULL) {
        *arvore = (pt_nodo)malloc(sizeof(nodo));
        (*arvore)->e = *x;
        (*arvore)->esquerda = NULL;
        (*arvore)->direita = NULL;
    } else {
        if (strcmp(x->palavra, (*arvore)->e.palavra) < 0) {
            InserirNaArvore(&((*arvore)->esquerda), x);
        } else if (strcmp(x->palavra, (*arvore)->e.palavra) > 0) {
            InserirNaArvore(&((*arvore)->direita), x);
        }
        // Ignorar elementos duplicados, assumindo que a palavra é única na árvore
    }
}

/*
 * Procura um elemento na árvore binária.
 * Retorna o nodo que contém o elemento procurado.
 * Se o elemento procurado estiver na árvore, retorna VERDADEIRO.
 * Se o elemento procurado não estiver na árvore, retorna FALSO.
 */
pt_nodo *PesquisarNaArvore(arvore_binaria *arvore, char *x) {
    pt_nodo *p = arvore;

    while (*p != NULL) {
        int comparacao = strcmp(x, (*p)->e.palavra);
        if (comparacao == 0) {
            break;  // Elemento encontrado
        } else if (comparacao < 0) {
            p = &((*p)->esquerda);
        } else {
            p = &((*p)->direita);
        }
    }

    return p;
}

//Essa resposta propõe a modificação do código original, que implementa uma lista encadeada, para um código que opera com uma árvore binária de pesquisa (BST). Vamos explicar cada parte:

//1. **Definição da Estrutura da Árvore:**
//   - Foi introduzida uma nova estrutura chamada `nodo` que contém um elemento (`elemento e`) e dois ponteiros para nodos, um apontando para o filho à esquerda (`esquerda`) e outro para o filho à direita (`direita`).
//   - A árvore é representada por um ponteiro para o tipo `nodo` chamado `arvore_binaria`.

//2. **Função `CriarArvoreBinaria`:**
//   - Inicializa uma árvore binária como vazia, definindo o ponteiro para `NULL`.

//3. **Função `ArvoreVazia`:**
//   - Verifica se a árvore binária está vazia, retornando 1 (VERDADEIRO) se estiver vazia e 0 (FALSO) caso contrário.

//4. **Função `InserirNaArvore`:**
//   - Insere um novo elemento na árvore binária de acordo com a lógica de uma BST. Se a árvore estiver vazia, cria o primeiro nodo; caso contrário, percorre a árvore até encontrar o local adequado para inserir o novo nodo, considerando a ordem de valores na árvore. Elementos duplicados (mesma palavra) são ignorados.

//5. **Função `PesquisarNaArvore`:**
//   - Procura um elemento na árvore binária, retornando um ponteiro para o nodo que contém o elemento procurado. Se o elemento for encontrado, retorna VERDADEIRO; caso contrário, retorna FALSO.

//6. **Considerações sobre Elementos Duplicados:**
//   - A lógica de inserção assume que as palavras são únicas na árvore, portanto, elementos duplicados (mesma palavra) são ignorados.

//Essas modificações transformam a estrutura de dados de uma lista encadeada para uma árvore binária de pesquisa, mantendo as operações e a lógica próprias de uma árvore para a inserção e busca de elementos.
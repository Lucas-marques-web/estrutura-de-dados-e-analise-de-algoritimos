#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*declaração da árvore binária, criando um elemento para armazenar o valor
e dois ponteiros(esquerda e direita) */
typedef struct node
{
    int data;
    struct node *esquerda;
    struct node *direita;
};

/*criar uma árvore vazia*/
struct node* criarArvoreVazia() {
    return NULL;
}

/*para criar um novo nodo na árvore binária, recebendo o valor e
retornando o ponteiro do novo nodo com aquele valor*/
struct node* criar(struct node* raiz, int valor) {
    if (raiz == NULL){
        struct node* novoNodo = malloc(sizeof(struct node));
        novoNodo->data = valor;
        novoNodo->esquerda = novoNodo->direita = NULL;

        return novoNodo; //novo nodo vai ter um ponteiro pra cada lado apontando para null
    }

    if(valor < raiz->data){
        raiz->esquerda = criar(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = criar(raiz->direita, valor);
    }

    return raiz;
}

bool isArvoreVazia(struct node* raiz) {
    return raiz == NULL;
}

/*retorna o valor do nodo pai, caminha para a esquerda e depois para
a direita*/
void percorrerPreOrdem(struct node* raiz) {
  if (raiz == NULL) return;
  printf("%d ->", raiz->data);
  percorrerPreOrdem(raiz->esquerda);
  percorrerPreOrdem(raiz->direita);
}

/*caminha para a esquerda, retorna o valor do nodo e caminha para
a direita*/
void percorrerEmOrdem(struct node* raiz) {
  if (raiz == NULL) return;
  percorrerEmOrdem(raiz->esquerda);
  printf("%d ->", raiz->data);
  percorrerEmOrdem(raiz->direita);
}

/*caminha para a esquerda, caminha para a direita e retorna o valor
do nodo*/
void percorrerPosOrdem(struct node* raiz) {
  if (raiz == NULL) return;
  percorrerPosOrdem(raiz->esquerda);
  percorrerPosOrdem(raiz->direita);
  printf("%d ->", raiz->data);
}

/*método que remove nodo da árvore*/
struct node* removerNodo(struct node* raiz, int valor) {
    /*retorna nulo se a árvore é vazia*/
    if(raiz == NULL) {
        return NULL;
    }

    if(valor < raiz->data) {
        raiz->esquerda = removerNodo(raiz->esquerda, valor);
    } else if (valor > raiz->data) {
        raiz->direita = removerNodo(raiz->direita, valor);
    } else {
        /*nodo com apenas um filho ou nenhum*/
        if(raiz->esquerda == NULL) {
            struct node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        /*nodo com dois filhos, armazenando o sucessor em ordem*/
        struct node* temp = raiz->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        raiz->data = temp->data;

        raiz->direita = removerNodo(raiz->direita, temp->data);
    }

    return raiz;
}

/*método de pesquisa de um valor em um nodo*/
int pesquisarValor(struct node* raiz, int valor) {
    if (raiz == NULL){
        return 0;
    }

    if(valor == raiz->data) {
        return 1;
    } else if (valor < raiz->data) {
        return pesquisarValor(raiz->esquerda, valor);
    } else {
        return pesquisarValor(raiz->direita, valor);
    }
}

/*método para retornar a altura da árvore selecionada*/
int getAlturaArvore(struct node* raiz) {
    if(raiz == NULL) {
        return -1;
    }

    int alturaEsquerda = getAlturaArvore(raiz->esquerda);
    int alturaDireita = getAlturaArvore(raiz->direita);

    return 0 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

/*método para retornar a altura de um nodo específico*/
int getAlturaNodo(struct node* raiz, int valor) {
    if(raiz == NULL) {
        return -1;
    }

    if(valor == raiz->data) {
        return getAlturaArvore(raiz);
    } else if(valor < raiz->data) {
        return getAlturaNodo(raiz->esquerda, valor);
    } else {
        return getAlturaNodo(raiz->direita, valor);
    }
}

/*método que retorna a profundidade de um nodo*/
int getProfundidadeNodo(struct node* raiz, int valor, int profundidade) {
    if(raiz == NULL){
        return -1;
    }

    if(valor == raiz->data) {
        return profundidade;
    } else if(valor < raiz->data) {
        return getProfundidadeNodo(raiz->esquerda, valor, profundidade + 1);
    } else {
        return getProfundidadeNodo(raiz->direita, valor, profundidade + 1);
    }
}

/*método que retorna o nível de um nodo*/
int getNivelNodo(struct node* raiz, int valor, int nivel) {
    if(raiz == NULL) {
        return -1;
    }

    if(valor == raiz->data) {
        return nivel;
    } else if(valor < raiz->data) {
        return getNivelNodo(raiz->esquerda, valor, nivel + 1);
    } else {
        return getNivelNodo(raiz->direita, valor, nivel + 1);
    }
}

/*método para retornar o grau da árvore*/
int getGrauArvore(struct node* raiz) {
    if(raiz == NULL) {
        return 0;
    }

    int grauEsquerdo = getGrauArvore(raiz->esquerda);
    int grauDireito = getGrauArvore(raiz->direita);

    return (raiz->esquerda != NULL) + (raiz->direita != NULL) + grauEsquerdo + grauDireito;
}

/*método que retorna o grau de um nodo*/
int getGrauNodo(struct node* raiz, int valor) {
    if(raiz == NULL) {
        return -1;
    }

    if(valor = raiz->data) {
        return (raiz->esquerda != NULL) + (raiz->direita != NULL);
    } else if(valor < raiz->data) {
        return getGrauNodo(raiz->esquerda, valor);
    } else {
        return getGrauNodo(raiz->direita, valor);
    }
}

/*método para retornar o nodo com o maior grau*/
struct node* getNodoComMaiorGrau(struct node* raiz) {
    if(raiz == NULL) {
        return NULL;
    }

    struct node* nodoComMaiorGrau = raiz;
    int grauMaior = getGrauArvore(raiz);

    struct node* nodoEsquerdoComMaiorGrau = getNodoComMaiorGrau(raiz->esquerda);
    struct node* nodoDireitoComMaiorGrau = getNodoComMaiorGrau(raiz->direita);

    int grauEsquerdo = getAlturaArvore(nodoEsquerdoComMaiorGrau);
    int grauDireito = getAlturaArvore(nodoDireitoComMaiorGrau);

    if(grauEsquerdo > grauMaior) {
        grauMaior = grauEsquerdo;
        nodoComMaiorGrau = nodoEsquerdoComMaiorGrau;
    }

    if(grauDireito > grauMaior) {
        grauMaior = grauDireito;
        nodoComMaiorGrau = nodoDireitoComMaiorGrau;
    }

    return nodoComMaiorGrau;
}

/*método para retornar o diametro da árvore*/
int getDiametroArvore(struct node* raiz) {
    if(raiz == NULL) {
        return 0;
    }

    int alturaEsquerda = getAlturaArvore(raiz->esquerda);
    int alturaDireita = getAlturaArvore(raiz->direita);

    int nivelEsquerdo = getDiametroArvore(raiz->esquerda);
    int nivelDireito = getDiametroArvore(raiz->direita);

    return (alturaEsquerda + alturaDireita + 1 > nivelEsquerdo && alturaEsquerda + alturaDireita + 1 > nivelDireito)
            ? alturaEsquerda + alturaDireita + 1
            : (nivelEsquerdo > nivelDireito ? nivelEsquerdo : nivelDireito);
}

/*método para limpar a memória da árvore*/
void limparArvore(struct node* raiz) {
    if(raiz != NULL) {
        limparArvore(raiz->esquerda);
        limparArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    /*exemplos de uso para a biblioteca*/
    struct node* raiz = criarArvoreVazia();

    raiz = criar(raiz, 50);
    raiz = criar(raiz, 30);
    raiz = criar(raiz, 70);
    raiz = criar(raiz, 20);
    raiz = criar(raiz, 40);
    raiz = criar(raiz, 60);
    raiz = criar(raiz, 80);

    printf("Percorrer em ordem: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    printf("Altura da arvore: %d\n", getAlturaArvore(raiz));

    int resultadoDaPesquisa = pesquisarValor(raiz, 30);
    printf("Pesquisar pelo valor 30: %s\n", resultadoDaPesquisa ? "Encontrado!" : "Falha na pesquisa.");

    raiz = removerNodo(raiz, 30);
    printf("Percorrer em ordem apos remover nodo 30: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    printf("Altura do nodo 40: %d\n", getAlturaNodo(raiz, 40));
    printf("Profundidade do nodo 40: %d\n", getProfundidadeNodo(raiz, 40, 0));
    printf("Nivel do nodo 40: %d\n", getNivelNodo(raiz, 40, 1));

    printf("Grau da arvore: %d\n", getGrauArvore(raiz));
    printf("Grau do nodo 40: %d\n", getGrauNodo(raiz, 40));

    struct node* nodoComMaiorGrau = getNodoComMaiorGrau(raiz);
    printf("Nodo com o maior grau: %d\n", nodoComMaiorGrau->data);

    printf("Diametro da arvore: %d\n", getDiametroArvore(raiz));

    printf("Percorrer pre-ordem: ");
    percorrerPreOrdem(raiz);
    printf("\n");

    printf("Percorrer pos-ordem: ");
    percorrerPosOrdem(raiz);
    printf("\n");


    limparArvore(raiz);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*declaração da árvore binária, criando um elemento para armazenar o valor
e dois ponteiros(esquerda e direita) */
typedef struct node
{
    int data;
    struct node *esquerda;
    struct node *direita;
};

/*criar uma árvore vazia*/
node* criarArvoreVazia() {
    return NULL;
}

/*para criar um novo nodo na árvore binária, recebendo o valor e
retornando o ponteiro do novo nodo com aquele valor*/
node* criar(node* raiz, int valor) {
    if (raiz == NULL){
        struct node* novoNodo = malloc(sizeof(node));
        novoNodo->data = value;
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

node* isArvoreVazia(node* raiz) {
    return raiz == null;
}

/*retorna o valor do nodo pai, caminha para a esquerda e depois para
a direita*/
void percorrerPreOrdem(node* raiz) {
  if (raiz == NULL) return;
  printf("%d ->", raiz->data);
  percorrerPreOrdem(raiz->esquerda);
  percorrerPreOrdem(raiz->direita);
}

/*caminha para a esquerda, retorna o valor do nodo e caminha para
a direita*/
void percorrerEmOrdem(node* raiz) {
  if (raiz == NULL) return;
  percorrerEmOrdem(raiz->esquerda);
  printf("%d ->", raiz->data);
  percorrerEmOrdem(raiz->direita);
}

/*caminha para a esquerda, caminha para a direita e retorna o valor
do nodo*/
void percorrerPosOrdem(node* raiz) {
  if (raiz == NULL) return;
  percorrerPosOrdem(raiz->esquerda);
  percorrerPosOrdem(raiz->direita);
  printf("%d ->", raiz->data);
}

/*método que remove nodo da árvore*/
node* removerNodo(node* raiz, int valor) {
    /*retorna nulo se a árvore é vazia*/
    if(raiz == NULL) {
        return NULL;
    }

    if(valor < raiz->data) {
        raiz->esquerda = removerNodo(raiz->esquerda, valor);
    } else if (value > raiz->data) {
        raiz->direita = removerNodo(raiz->direita, value);
    } else {
        /*nodo com apenas um filho ou nenhum*/
        if(raiz->esquerda == NULL) {
            node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        /*nodo com dois filhos, armazenando o sucessor em ordem*/
        node* temp = raiz->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        raiz->data = temp->data;

        raiz->direita = removerNodo(raiz->direita, temp->data);
    }

    return raiz;
}

/*método de pesquisa de um valor em um nodo*/
int pesquisarValor(node* raiz, int valor) {
    if (raiz == NULL){
        return 0;
    }

    if(valor == raiz->data) {
        return 1;
    } else if (valor < raiz->data) {
        return pesquisarValor(raiz->esquerda, valor);
    } else {
        return pesquisarValor(raiz->direita, value);
    }
}

/*método para retornar a altura da árvore selecionada*/
int getAlturaArvore(node* raiz) {
    if(raiz = NULL) {
        return -1;
    }

    int alturaEsquerda = getAlturaArvore(raiz->esquerda);
    int alturaDireita getAlturaArvore(raiz->direita);

    return 0 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

/*método para retornar a altura de um nodo específico*/
int getAlturaNodo(node* raiz, int valor) {
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
int getProfundidadeNodo(node* raiz, int valor, int profundidade) {
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
int getNivelNodo(node* raiz, int valor, int nivel) {
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
int getGrauArvore(node* raiz) {
    if(raiz == NULL) {
        return 0;
    }

    int grauEsquerdo = getGrauArvore(raiz->esquerda);
    int grauDireito = getGrauArvore(raiz->direita);

    return (raiz->esquerda != NULL) + (raiz->direita != NULL) + grauEsquerdo + grauDireito;
}

/*método que retorna o grau de um nodo*/
int getGrauNodo(node* raiz, int valor) {
    if(raiz = NULL) {
        return -1;
    }

    if(valor = raiz->data) {
        return getAlturaArvore(raiz);
    } else if(valor < raiz->data) {
        return getGrauNodo(raiz->esquerda, valor);
    } else {
        return getGrauNodo(raiz->direita, valor);
    }
}

/*método para retornar o nodo com o maior grau*/
node* getNodoComMaiorGrau(node* raiz) {
    if(raiz == NULL) {
        return NULL;
    }

    node* nodoComMaiorGrau = raiz;
    int grauMaior = getGrauArvore(raiz);

    node* nodoEsquerdoComMaiorGrau = getNodoComMaiorGrau(raiz->esquerda);
    node* nodoDireitoComMaiorGrau = getNodoComMaiorGrau(raiz->direita);

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
int getDiametroArvore(node* raiz) {
    if(raiz == NULL) {
        return 0;
    }

    int alturaEsquerda = getAlturaArvore(raiz->esquerda);
    int alturaDireita = getAlturaArvore(raiz->direita);

    int nivelEsquerdo = getDiametroArvore(raiz->esquerda);
    int nivelDireito = getDiametroArvore(raiz->direita);

    return (alturaEsquerda + alturaDireita + 1 > nivelEsquerdo && alturaEsquerda + alturaDireita + 1 > nivelEsquerdo)
                ? alturaEsquerda + alturaDireita + 1
                : (nivelEsquerdo > nivelDireito ? nivelEsquerdo : nivelDireito);
}

/*método para limpar a memória da árvore*/
void limparArvore(node* raiz) {
    if(raiz != NULL) {
        limparArvore(raiz->esquerda);
        limparArvore(raiz->direita);
        free(raiz);
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

typedef struct {
    char palavra[50];
} elemento;

typedef struct TipoNodo {
    elemento e;
    struct TipoNodo *prox;
} nodo;

typedef struct TipoNodo *pilha;

void CriarPilha(pilha *p) {
    *p = NULL;
}

int PilhaVazia(pilha *p) {
    return (*p == NULL);
}

void Empilhar(pilha *p, elemento *x) {
    nodo *p_nodo;
    p_nodo = (nodo *) malloc(sizeof(nodo));
    p_nodo->e = *x;
    p_nodo->prox = *p;
    *p = p_nodo;
}

elemento Desempilhar(pilha *p) {
    elemento x;
    nodo *p_nodo;
    p_nodo = *p;
    x = p_nodo->e;
    *p = (*p)->prox;
    free(p_nodo);
    return x;
}

pt_nodo* PesquisarPilha(pilha *p, char *x) {
    pt_nodo *p_nodo;
    p_nodo = NULL;

    while (*p != NULL) {
        if (strcmp((*p)->e.palavra, x) == 0) {
            p_nodo = p;
            break;
        }
        p = &((*p)->prox);
    }
    return p_nodo;
}
// A estrutura do elemento permanece a mesma. O que precisa ser alterado é a implementação da pilha e das funções Empilhar, Desempilhar e PesquisarPilha. Aqui está a solução para este problema:
// Neste exemplo, os elementos são armazenados em uma pilha. As funções Empilhar, Desempilhar e PesquisarPilha foram implementadas para lidar com a pilha.
#include <stdio.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAM 10

typedef int elemento; // Altere o tipo de elemento conforme necessário

struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

// Cria lista.
void CriarLista(lista *l) {
    l->inicio = -1;
    l->fim = -1;
}

// Verifica se a lista está vazia.
int ListaVazia(lista *l) {
    return (l->inicio == -1 && l->fim == -1);
}

// Verifica se a lista está cheia.
int ListaCheia(lista *l) {
    return (l->fim == TAM - 1);
}

// Insere um elemento na lista.
void Alistar(lista *l, elemento e, int pos) {
    int i;
    if (ListaCheia(l))
        printf("\n ERRO: lista cheia!");
    else if ((pos < 0) || (pos > l->fim + 1)) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", l->fim + 1);
    } else {
        for (i = l->fim; i >= pos; i--)
            l->vet[i + 1] = l->vet[i];
        l->vet[pos] = e;
        l->fim++;
        if (l->inicio == -1)
            l->inicio = 0;
    }
}

// Retira um elemento da lista.
elemento Desalistar(lista *l, int pos) {
    int i;
    elemento
}
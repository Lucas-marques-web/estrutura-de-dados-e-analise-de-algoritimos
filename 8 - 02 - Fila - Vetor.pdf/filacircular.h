#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#include <stdio.h>

#define TAM 5 // Tamanho máximo da fila circular

typedef int elemento;

struct tipo_fila {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

// Função para criar uma fila circular vazia
void CriarFila(fila f) {
    f->inicio = 0;
    f->fim = 0;
}

// Função para verificar se a fila circular está vazia
int FilaVazia(filaf) {
    return (f->inicio == f->fim);
}

// Função para verificar se a fila circular está cheia
int FilaCheia(fila f) {
    return ((f->fim + 1) % TAM == f->inicio);
}

// Função para enfileirar um elemento na fila circular
void Enfileirar(filaf, elemento e) {
    if (!FilaCheia(f)) {
        f->vet[f->fim] = e;
        f->fim = (f->fim + 1) % TAM;
    } else {
        printf("ERRO: Fila circular cheia!\n");
    }
}

// Função para desenfileirar um elemento da fila circular
elemento Desenfileirar(fila *f) {
    elemento e;
    if (!FilaVazia(f)) {
        e = f->vet[f->inicio];
        f->inicio = (f->inicio + 1) % TAM;
        return e;
    } else {
        printf("ERRO: Fila circular vazia!\n");
        return -1; // Valor inválido para indicar erro
    }
}

#endif

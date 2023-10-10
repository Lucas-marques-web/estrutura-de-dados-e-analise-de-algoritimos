#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct {
    int elementos[TAM];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

// Função para criar uma fila circular vazia
FilaCircular* criarFila() {
    FilaCircular* fila = (FilaCircular*)malloc(sizeof(FilaCircular));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    return fila;
}

// Função para verificar se a fila circular está vazia
int filaVazia(FilaCircular* fila) {
    return fila->tamanho == 0;
}

// Função para verificar se a fila circular está cheia
int filaCheia(FilaCircular* fila) {
    return fila->tamanho == TAM;
}

// Função para enfileirar um elemento na fila circular
void enfileirar(FilaCircular* fila, int elemento) {
    if (!filaCheia(fila)) {
        fila->elementos[fila->fim] = elemento;
        fila->fim = (fila->fim + 1) % TAM;
        fila->tamanho++;
    } else {
        printf("ERRO: Fila circular cheia!\n");
    }
}

// Função para desenfileirar um elemento da fila circular
int desenfileirar(FilaCircular* fila) {
    if (!filaVazia(fila)) {
        int elemento = fila->elementos[fila->inicio];
        fila->inicio = (fila->inicio + 1) % TAM;
        fila->tamanho--;
        return elemento;
    } else {
        printf("ERRO: Fila circular vazia!\n");
        return -1; // Valor inválido para indicar erro
    }
}

// Função para imprimir o conteúdo da fila circular
void imprimirFila(FilaCircular* fila) {
    if (!filaVazia(fila)) {
        printf("Fila Circular: ");
        int i, j;
        for (i = fila->inicio, j = 0; j < fila->tamanho; i = (i + 1) % TAM, j++) {
            printf("%d ", fila->elementos[i]);
        }
        printf("\n");
    } else {
        printf("Fila Circular vazia.\n");
    }
}

int main() {
    FilaCircular* fila = criarFila();

    enfileirar(fila, 1);
    enfileirar(fila, 2);
    enfileirar(fila, 3);

    imprimirFila(fila);

    desenfileirar(fila);
    enfileirar(fila, 4);

    imprimirFila(fila);

    free(fila);

    return 0;
}

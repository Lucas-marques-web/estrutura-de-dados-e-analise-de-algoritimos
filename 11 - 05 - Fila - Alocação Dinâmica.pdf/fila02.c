#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef char* elemento;

typedef struct {
    elemento *vetor;
    int inicio;
    int fim;
    int tamanho;
} fila;

void CriarFila(fila *f, int tamanho);
int Enfileirar(fila *f, elemento valor);
int Desenfileirar(fila *f, elemento *valor);
int FilaVazia(fila *f);
void LiberarFila(fila *f);

void strread(elemento *s);
void Esperar(long seg);
void ConsultarNomes(fila *f);

int main() {
    elemento palavra;
    fila listaNomes;
    CriarFila(&listaNomes, 10);

    int opcao;
    do {
        printf("\nOpções:\n");
        printf("1. Informar um nome\n");
        printf("2. Consultar nomes na lista\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nInforme o nome: ");
                strread(&palavra);
                Enfileirar(&listaNomes, palavra);
                break;
            case 2:
                printf("\nNomes na lista:\n");
                ConsultarNomes(&listaNomes);
                break;
            case 3:
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    while (!FilaVazia(&listaNomes)) {
        Desenfileirar(&listaNomes, &palavra);
        free(palavra);
    }
    LiberarFila(&listaNomes);

    printf("\n\n");
    Esperar(4L);
    return 0;
}

void CriarFila(fila *f, int tamanho) {
    f->vetor = (elemento*)malloc(sizeof(elemento) * tamanho);
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = tamanho;
}

int Enfileirar(fila *f, elemento valor) {
    if (f->fim == f->tamanho - 1) {
        return 0;
    }
    f->fim++;
    f->vetor[f->fim] = valor;
    return 1;
}

int Desenfileirar(fila *f, elemento *valor) {
    if (FilaVazia(f)) {
        return 0;
    }
    *valor = f->vetor[f->inicio];
    f->inicio++;
    return 1;
}

int FilaVazia(fila *f) {
    return (f->inicio > f->fim);
}

void LiberarFila(fila *f) {
    free(f->vetor);
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

void strread(elemento *s) {
    int cont = 0;
    char letra;
    elemento nome = (elemento)malloc(sizeof(char) * 100);

    scanf(" ");
    scanf("%c", &letra);
    while (letra != '\n') {
        nome[cont] = letra;
        cont++;
        scanf("%c", &letra);
    }
    nome[cont] = '\0';

    *s = nome;
}

void Esperar(long seg) {
    long temp1, temp2;
    temp1 = time(NULL);
    temp2 = time(NULL);
    while (temp2 - temp1 < seg) {
        temp2 = time(NULL);
    }
}

void ConsultarNomes(fila *f) {
    int i;
    for (i = f->inicio; i <= f->fim; i++) {
        printf("%s\n", f->vetor[i]);
    }
}
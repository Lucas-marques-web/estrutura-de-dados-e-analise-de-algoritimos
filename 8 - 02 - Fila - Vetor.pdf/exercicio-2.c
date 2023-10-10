
#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef int elemento;
#include "fila.h"

// Função para desenfileirar os elementos e gravá-los em um arquivo de texto
void DesenfileirarParaArquivo(fila *f) {
    FILE *arquivo;
    arquivo = fopen("numeros.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    while (!FilaVazia(f)) {
        float numero = Desenfileirar(f);
        fprintf(arquivo, "%.2f\n", numero);
    }

    fclose(arquivo);
    printf("Elementos desenfileirados e gravados em 'numeros.txt'.\n");
}

// Função para ler os elementos a partir de um arquivo de texto e enfileirá-los
void LerDoArquivoEFila(fila *f) {
    FILE *arquivo;
    arquivo = fopen("numeros.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    float numero;
    while (fscanf(arquivo, "%f", &numero) != EOF) {
        Enfileirar(f, numero);
    }

    fclose(arquivo);
    printf("Elementos lidos do arquivo e enfileirados.\n");
}

// Função para imprimir o conteúdo da fila na tela
void ImprimirFila(fila *f) {
    printf("Conteúdo da fila:\n");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%.2f ", f->vet[i]);
    }
    printf("\n");
}

int main() {
    fila minhaFila;
    CriarFila(&minhaFila); // Inicializa a fila

    printf("Digite 10 números reais:\n");
    for (int i = 0; i < 10; i++) {
        float numero;
        scanf("%f", &numero);
        Enfileirar(&minhaFila, numero); // Insere elementos na fila
    }

    // Chama a função para desenfileirar e gravar em um arquivo
    DesenfileirarParaArquivo(&minhaFila);

    // Chama a função para ler do arquivo e enfileirar
    LerDoArquivoEFila(&minhaFila);

    // Chama a função para imprimir o conteúdo da fila
    ImprimirFila(&minhaFila);

    return 0;
}
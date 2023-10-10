#include <stdio.h>
#include <stdlib.h>
#define TAM 10 // Alterar o tamanho da pilha para 10
typedef struct elemento elemento; // Alterar o tipo do elemento para struct elemento
#include "pilha.h"

int main() {
    pilha p;
    CriarPilha(&p);

    // Leitura e empilhamento de 10 números reais a partir do teclado
    printf("Digite 10 números reais:\n");
    for (int i = 0; i < TAM; i++) {
        float num;
        scanf("%f", &num);
        elemento e;
        e.valor = num; // Cria um elemento com o número real
        Empilhar(&p, e);
    }

    // Grava a pilha em um arquivo de texto
    FILE *arquivo = fopen("pilha.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return 1;
    }

    while (PilhaVazia(&p) == FALSO) {
        elemento e = Desempilhar(&p);
        fprintf(arquivo, "%.2f\n", e.valor);
    }

    fclose(arquivo);

    // Limpar a pilha
    CriarPilha(&p);

    // Ler do arquivo e empilhar novamente
    arquivo = fopen("pilha.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    float num;
    while (fscanf(arquivo, "%f", &num) == 1) {
        elemento e;
        e.valor = num; // Cria um elemento com o número real
        Empilhar(&p, e);
    }

    fclose(arquivo);

    // Imprimir o conteúdo da pilha
    ImprimePilha(&p);

    return 0;
}
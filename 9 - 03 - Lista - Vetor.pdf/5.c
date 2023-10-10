#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int lista[MAX_SIZE];
    int tamanho = 0;
    int posicao, elemento, i;

    // Leitura da sequência de 10 inteiros
    printf("Digite uma sequência de 10 inteiros:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &lista[i]);
        tamanho++;
    }

    while (1) {
        // Solicita a posição do elemento a ser removido
        printf("Digite a posição do elemento a ser removido (ou -1 para encerrar): ");
        scanf("%d", &posicao);

        if (posicao == -1) {
            printf("Encerrando o programa.\n");
            break;
        }

        if (posicao < 0 || posicao >= tamanho) {
            printf("Posição inválida. Tente novamente.\n");
        } else {
            elemento = lista[posicao];

            // Remove o elemento da lista e ajusta o tamanho
            for (i = posicao; i < tamanho - 1; i++) {
                lista[i] = lista[i + 1];
            }
            tamanho--;

            printf("Elemento removido: %d\n", elemento);
        }
    }

    return 0;
}
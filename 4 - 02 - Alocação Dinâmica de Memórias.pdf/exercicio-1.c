#include <stdio.h>
#include <stdlib.h>

int *alocarMemoria(int tamanho) {
    int *ptr = (int *)malloc(tamanho * sizeof(int));
    if (ptr == NULL) {
        printf("Falha na alocacao de memoria.\n");
        exit(1);
    }
    return ptr;
}

void preencherArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = i * 10;
    }
}

void imprimirArray(int *array, int tamanho) {
    printf("Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    // Alocar memória usando a função alocarMemoria
    array = alocarMemoria(n);

    // Preencher o array usando a função preencherArray
    preencherArray(array, n);

    // Imprimir o array usando a função imprimirArray
    imprimirArray(array, n);

    // Liberar a memória alocada com malloc
    free(array);

    return 0;
}
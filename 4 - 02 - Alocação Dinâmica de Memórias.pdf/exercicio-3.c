#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura Veículo
struct Veiculo {
    char numero_chassi[18];
    char marca[50];
    char modelo[50];
    float preco;
};

// Função para alocar dinamicamente um vetor de estruturas Veículo
struct Veiculo* alocarVetor(int n) {
    struct Veiculo *veiculos = (struct Veiculo *)malloc(n * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na alocacao de memoria.\n");
        exit(1);
    }
    return veiculos;
}

// Função para preencher o vetor de estruturas Veículo
void preencherVetor(struct Veiculo *veiculos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o numero do chassi do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].numero_chassi);
        printf("Digite a marca do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].marca);
        printf("Digite o modelo do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].modelo);
        printf("Digite o preco do veiculo %d: ", i + 1);
        scanf("%f", &veiculos[i].preco);
    }
}

// Função para imprimir o vetor de estruturas Veículo
void imprimirVetor(struct Veiculo *veiculos, int n) {
    printf("Vetor de Veiculos:\n");
    for (int i = 0; i < n; i++) {
        printf("Veiculo %d:\n", i + 1);
        printf("Numero do chassi: %s\n", veiculos[i].numero_chassi);
        printf("Marca: %s\n", veiculos[i].marca);
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Preco: %.2f\n", veiculos[i].preco);
        printf("\n");
    }
}

// Função para redimensionar o vetor de estruturas Veículo
struct Veiculo* realocarVetor(struct Veiculo *veiculos, int *n, int novo_tamanho) {
    veiculos = (struct Veiculo *)realloc(veiculos, novo_tamanho * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na realocacao de memoria.\n");
        exit(1);
    }
    return veiculos;
}

// Função para liberar a memória alocada
void liberarMemoria(struct Veiculo *veiculos) {
    free(veiculos);
}

int main() {
    int n;
    printf("Digite o tamanho inicial do vetor de veiculos: ");
    scanf("%d", &n);

    // Alocar memória para o vetor de estruturas Veículo
    struct Veiculo *veiculos = alocarVetor(n);

    // Preencher o vetor de estruturas Veículo
    preencherVetor(veiculos, n);

    // Imprimir o vetor de estruturas Veículo
    imprimirVetor(veiculos, n);

    // Realocar o vetor para um tamanho maior
    int novo_tamanho = n + 5;
    veiculos = realocarVetor(veiculos, &n, novo_tamanho);

    // Preencher os elementos adicionais
    for (int i = n; i < novo_tamanho; i++) {
        printf("Digite o numero do chassi do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].numero_chassi);
        printf("Digite a marca do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].marca);
        printf("Digite o modelo do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].modelo);
        printf("Digite o preco do veiculo %d: ", i + 1);
        scanf("%f", &veiculos[i].preco);
        n++;
    }

    // Imprimir o vetor após a realocação
    imprimirVetor(veiculos, n);

    // Liberar a memória alocada
    liberarMemoria(veiculos);

    return 0;
}
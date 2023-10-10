#include <stdio.h>
#include <stdlib.h>

// Estrutura Pessoa
struct Pessoa {
    char CPF[12];
    char nome[50];
    float salario;
};

// Função para alocar dinamicamente um vetor de estruturas Pessoa
struct Pessoa* alocarVetor(int n) {
    struct Pessoa *pessoas = (struct Pessoa *)calloc(n, sizeof(struct Pessoa));
    if (pessoas == NULL) {
        printf("Falha na alocacao de memoria.\n");
        exit(1);
    }
    return pessoas;
}

// Função para preencher o vetor de estruturas Pessoa
void preencherVetor(struct Pessoa *pessoas, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o CPF da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].CPF);
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Digite o salario da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].salario);
    }
}

// Função para imprimir o vetor de estruturas Pessoa
void imprimirVetor(struct Pessoa *pessoas, int n) {
    printf("Vetor de Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("CPF: %s\n", pessoas[i].CPF);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Salario: %.2f\n", pessoas[i].salario);
        printf("\n");
    }
}

// Função para liberar a memória alocada
void liberarMemoria(struct Pessoa *pessoas) {
    free(pessoas);
}

int main() {
    int n;
    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);

    // Alocar memória para o vetor de estruturas Pessoa
    struct Pessoa *pessoas = alocarVetor(n);

    // Preencher o vetor de estruturas Pessoa
    preencherVetor(pessoas, n);

    // Imprimir o vetor de estruturas Pessoa
    imprimirVetor(pessoas, n);

    // Liberar a memória alocada
    liberarMemoria(pessoas);

    return 0;
}
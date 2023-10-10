#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_MAX 100

typedef int elemento;

typedef struct {
    int topo;
    elemento itens[TAMANHO_MAX];
} pilha;

void CriarPilha(pilha *p) {
    p->topo = -1;
}

bool PilhaVazia(pilha *p) {
    return (p->topo == -1);
}

void Empilhar(pilha *p, elemento valor) {
    if (p->topo == TAMANHO_MAX - 1) {
        printf("Erro: a pilha está cheia.\n");
        exit(1);
    }
    p->itens[++(p->topo)] = valor;
}

elemento Desempilhar(pilha *p) {
    if (PilhaVazia(p)) {
        printf("Erro: a pilha está vazia.\n");
        exit(1);
    }
    return p->itens[(p->topo)--];
}

int main() {
    int num, resto;
    pilha p;

    while (1) {
        CriarPilha(&p);
        printf("\nInforme um numero inteiro (0 para sair): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        printf("\nCorrespondente em binario: ");
        while (num != 0) {
            resto = num % 2;
            Empilhar(&p, resto);
            num /= 2;
        }

        while (!PilhaVazia(&p)) {
            resto = Desempilhar(&p);
            printf("%d", resto);
        }
        printf("\n");
    }

    return 0;
}
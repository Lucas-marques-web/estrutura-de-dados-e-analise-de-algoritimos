#define VERDADEIRO 1
#define FALSO 0

struct elemento {
    float valor; // Alterado para lidar com números reais
};

#define TAM 10 // Tamanho máximo da pilha

struct tipo_pilha {
    struct elemento vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;

// Modificado: Cria pilha.
void CriarPilha(pilha *p) {
    p->topo = -1; // Inicializa o topo com -1
}

// Verifica se a pilha está vazia.
int PilhaVazia(pilha *p) {
    return (p->topo == -1);
}

// Verifica se a pilha está cheia.
int PilhaCheia(pilha *p) {
    return (p->topo == TAM - 1);
}

// Insere um elemento na pilha.
void Empilhar(pilha *p, struct elemento e) {
    if (!PilhaCheia(p)) {
        p->topo++;
        p->vet[p->topo] = e;
    }
}

// Retira um elemento na pilha.
struct elemento Desempilhar(pilha *p) {
    struct elemento elementoVazio; // Defina o elemento vazio conforme a estrutura da pilha

    if (!PilhaVazia(p)) {
        struct elemento e = p->vet[p->topo];
        p->topo--;
        return e;
    }

    return elementoVazio;
}

// Procedimento para imprimir o conteúdo da pilha.
void ImprimePilha(pilha *p) {
    if (PilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Conteúdo da pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%.2f\n", p->vet[i].valor); // Imprime números reais com duas casas decimais
    }
}
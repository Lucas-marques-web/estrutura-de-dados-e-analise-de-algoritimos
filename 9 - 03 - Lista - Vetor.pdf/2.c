#include <stdio.h>
#include <stdlib.h>

#define TAM 10
typedef float elemento;

// Estrutura da lista
typedef struct {
    elemento elementos[TAM];
    int tamanho;
} lista;

// Protótipos das funções
void CriarLista(lista *l);
int ListaCheia(const lista *l);
int ListaVazia(const lista *l);
void Alistar(lista *l, elemento num);
elemento Desalistar(lista *l);
void GravarListaEmArquivo(const lista *l);
void LerListaDoArquivo(lista *l);
void ImprimirLista(const lista *l);

int main() {
    lista l;
    CriarLista(&l);

    int opcao;
    elemento num;

    while (1) {
        printf("\nOpções:\n");
        printf("1. Inserir um número\n");
        printf("2. Gravar lista em arquivo\n");
        printf("3. Ler lista do arquivo\n");
        printf("4. Imprimir lista\n");
        printf("5. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (ListaCheia(&l)) {
                    printf("A lista está cheia. Não é possível adicionar mais elementos.\n");
                } else {
                    printf("Informe um número real: ");
                    scanf("%f", &num);
                    Alistar(&l, num);
                }
                break;
            case 2:
                GravarListaEmArquivo(&l);
                printf("Lista gravada em arquivo.\n");
                break;
            case 3:
                LerListaDoArquivo(&l);
                printf("Lista lida do arquivo.\n");
                break;
            case 4:
                ImprimirLista(&l);
                break;
            case 5:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

void CriarLista(lista *l) {
    l->tamanho = 0;
}

int ListaCheia(const lista *l) {
    return l->tamanho == TAM;
}

int ListaVazia(const lista *l) {
    return l->tamanho == 0;
}

void Alistar(lista *l, elemento num) {
    if (l->tamanho < TAM) {
        l->elementos[l->tamanho] = num;
        l->tamanho++;
    }
}

elemento Desalistar(lista *l) {
    if (l->tamanho > 0) {
        l->tamanho--;
        return l->elementos[l->tamanho];
    } else {
        // Retorne um valor padrão, pois a lista está vazia.
        return 0;
    }
}

void GravarListaEmArquivo(const lista *l) {
    FILE *arquivo = fopen("lista.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        return;
    }

    for (int i = 0; i < l->tamanho; i++) {
        fprintf(arquivo, "%.2f\n", l->elementos[i]);
    }

    fclose(arquivo);
}

void LerListaDoArquivo(lista *l) {
    FILE *arquivo = fopen("lista.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    CriarLista(l);

    while (!feof(arquivo) && !ListaCheia(l)) {
        elemento num;
        if (fscanf(arquivo, "%f", &num) == 1) {
            Alistar(l, num);
        }
    }

    fclose(arquivo);
}

void ImprimirLista(const lista *l) {
    printf("\nElementos da lista:\n");
    for (int i = 0; i < l->tamanho; i++) {
        printf("%.2f\n", l->elementos[i]);
    }
}

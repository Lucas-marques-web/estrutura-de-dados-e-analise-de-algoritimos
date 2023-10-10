#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um produto
typedef struct {
    char nome[50];
    float valor_unitario;
    int quantidade_estoque;
} Produto;

// Função para adicionar um produto à lista
void adicionarProduto(Produto lista[], int *numProdutos) {
    Produto novoProduto;

    printf("Nome do produto: ");
    scanf("%s", novoProduto.nome);
    printf("Valor unitário: ");
    scanf("%f", &novoProduto.valor_unitario);
    printf("Quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade_estoque);

    lista[*numProdutos] = novoProduto;
    (*numProdutos)++;

    printf("Produto cadastrado com sucesso!\n");
}

// Função para buscar um produto na lista
int buscarProduto(Produto lista[], int numProdutos, char nomeBusca[]) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(lista[i].nome, nomeBusca) == 0) {
            return i;
        }
    }
    return -1; // Produto não encontrado
}

// Função para excluir um produto da lista
void excluirProduto(Produto lista[], int *numProdutos, int index) {
    for (int i = index; i < (*numProdutos) - 1; i++) {
        lista[i] = lista[i + 1];
    }
    (*numProdutos)--;
    printf("Produto excluído com sucesso!\n");
}

int main() {
    Produto lista[100]; // Lista de produtos com capacidade para 100 produtos
    int numProdutos = 0;
    char nomeBusca[50];
    FILE *arquivo; // Declare a variável aqui

    while (1) {
        int opcao;
        printf("\n==== Farmácia ====\n");
        printf("1. Cadastrar produto\n");
        printf("2. Pesquisar produto\n");
        printf("3. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(lista, &numProdutos);
                break;
            case 2:
                printf("Nome do produto a pesquisar: ");
                scanf("%s", nomeBusca);
                int index = buscarProduto(lista, numProdutos, nomeBusca);
                if (index != -1) {
                    printf("Produto encontrado:\n");
                    printf("Nome: %s\n", lista[index].nome);
                    printf("Valor Unitário: %.2f\n", lista[index].valor_unitario);
                    printf("Quantidade em Estoque: %d\n", lista[index].quantidade_estoque);
                    char resposta;
                    printf("Deseja excluir este produto? (S/N): ");
                    scanf(" %c", &resposta);
                    if (resposta == 'S' || resposta == 's') {
                        excluirProduto(lista, &numProdutos, index);
                    }
                } else {
                    printf("Produto não cadastrado!\n");
                }
                break;
            case 3:
                // Salvar a lista em um arquivo binário
                arquivo = fopen("produtos.bin", "wb");
                if (arquivo != NULL) {
                    fwrite(lista, sizeof(Produto), numProdutos, arquivo);
                    fclose(arquivo);
                } else {
                    printf("Erro ao salvar o arquivo.\n");
                }
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}

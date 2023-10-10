#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pedido {
    char nome[50];
    char telefone[15];
    char endereco[100];
    char produto[50];
    float valor;
    struct Pedido* proximo;
} Pedido;

Pedido* criarPedido() {
    Pedido* novoPedido = (Pedido*)malloc(sizeof(Pedido));
    if (novoPedido == NULL) {
        printf("Erro: não foi possível alocar memória para o pedido.\n");
        exit(1);
    }
    novoPedido->proximo = NULL;
    return novoPedido;
}

void enfileirar(Pedido** fila, Pedido** fim, Pedido* novoPedido) {
    if (*fila == NULL) {
        *fila = novoPedido;
        *fim = novoPedido;
    } else {
        (*fim)->proximo = novoPedido;
        *fim = novoPedido;
    }
}

void imprimirFila(Pedido* fila) {
    printf("Pedidos na fila:\n");
    int numeroPedido = 1;
    while (fila != NULL) {
        printf("Pedido %d:\n", numeroPedido);
        printf("Nome: %s\n", fila->nome);
        printf("Telefone: %s\n", fila->telefone);
        printf("Endereço: %s\n", fila->endereco);
        printf("Produto: %s\n", fila->produto);
        printf("Valor: R$ %.2f\n", fila->valor);
        printf("\n");
        fila = fila->proximo;
        numeroPedido++;
    }
}

void imprimirFilaEmArquivo(Pedido* fila, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while (fila != NULL) {
        fprintf(arquivo, "Nome: %s\n", fila->nome);
        fprintf(arquivo, "Telefone: %s\n", fila->telefone);
        fprintf(arquivo, "Endereço: %s\n", fila->endereco);
        fprintf(arquivo, "Produto: %s\n", fila->produto);
        fprintf(arquivo, "Valor: R$ %.2f\n", fila->valor);
        fprintf(arquivo, "\n");
        fila = fila->proximo;
    }

    fclose(arquivo);
}

void lerArquivoParaFila(Pedido** fila, Pedido** fim, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (!feof(arquivo)) {
        Pedido* novoPedido = criarPedido();
        fscanf(arquivo, "Nome: %[^\n]\n", novoPedido->nome);
        fscanf(arquivo, "Telefone: %[^\n]\n", novoPedido->telefone);
        fscanf(arquivo, "Endereço: %[^\n]\n", novoPedido->endereco);
        fscanf(arquivo, "Produto: %[^\n]\n", novoPedido->produto);
        fscanf(arquivo, "Valor: R$ %f\n", &novoPedido->valor);

        enfileirar(fila, fim, novoPedido);
    }

    fclose(arquivo);
}

int pedidosNaFrente(Pedido* fila, const char* nomeCliente) {
    int contador = 0;
    while (fila != NULL) {
        if (strcmp(fila->nome, nomeCliente) != 0) {
            contador++;
        } else {
            break;
        }
        fila = fila->proximo;
    }
    return contador;
}

void removerPedido(Pedido** fila) {
    if (*fila == NULL) {
        printf("A fila de pedidos está vazia.\n");
        return;
    }
    Pedido* temp = *fila;
    *fila = (*fila)->proximo;
    free(temp);
    printf("Primeiro pedido removido da fila.\n");
}

int main() {
    Pedido* fila = NULL;
    Pedido* fim = NULL;

    int codigoUsuario = 0;

    while (1) {
        printf("\nOpções:\n");
        printf("1. Fazer um novo pedido\n");
        printf("2. Verificar os pedidos na fila\n");
        printf("3. Remover o primeiro pedido da fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &codigoUsuario);

        switch (codigoUsuario) {
            case 1:
                Pedido* novoPedido = criarPedido();
                printf("\nDigite o nome do cliente: ");
                scanf(" %[^\n]", novoPedido->nome);
                printf("Digite o telefone para contato: ");
                scanf(" %[^\n]", novoPedido->telefone);
                printf("Digite o endereço para entrega: ");
                scanf(" %[^\n]", novoPedido->endereco);
                printf("Digite o produto pedido: ");
                scanf(" %[^\n]", novoPedido->produto);
                printf("Digite o valor do produto: R$ ");
                scanf("%f", &novoPedido->valor);

                enfileirar(&fila, &fim, novoPedido);
                break;

            case 2:
                printf("\n");
                imprimirFila(fila);
                break;

            case 3:
                removerPedido(&fila);
                break;

            case 4:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }

        if (codigoUsuario == 4) {
            break;
        }
    }

    imprimirFila(fila);

    imprimirFilaEmArquivo(fila, "pedidos.txt");

    Pedido* filaLida = NULL;
    Pedido* fimLido = NULL;
    lerArquivoParaFila(&filaLida, &fimLido, "pedidos.txt");

    printf("\n");

    imprimirFila(filaLida);

    while (fila != NULL) {
        Pedido* temp = fila;
        fila = fila->proximo;
        free(temp);
    }
    while (filaLida != NULL) {
        Pedido* temp = filaLida;
        filaLida = filaLida->proximo;
        free(temp);
    }

    return 0;
}


// QUESTAO 2

/*

Aqui estão as principais diferenças em relação a uma fila simplesmente encadeada:

Cada nó na fila duplamente encadeada possui dois ponteiros, um para o nó anterior (prev) e outro para o nó seguinte (next).

A estrutura da fila (DoubleLinkedListQueue) deve manter dois ponteiros: um para o início da fila (front) e outro para o final da fila (rear).

Agora, você precisa implementar as funções para esta fila duplamente encadeada em um arquivo de código-fonte separado (por exemplo, fila.c)
 e incluir essas implementações no seu programa principal.

Quanto às vantagens e desvantagens da utilização de uma fila duplamente encadeada:

Vantagens:

Acesso Bidirecional: Uma fila duplamente encadeada permite acesso bidirecional, o que significa que você pode navegar tanto para 
frente quanto para trás na fila, o que pode ser útil em determinadas situações.

Inserção e Remoção Eficientes no Final: Inserir ou remover elementos no final da fila é uma operação O(1) (constante), o que é mais eficiente
 do que em uma fila simplesmente encadeada, onde remover do final seria uma operação O(n).

Desvantagens:

Uso de Memória: Uma fila duplamente encadeada usa mais memória em comparação com uma fila simplesmente encadeada, devido aos ponteiros adicionais em cada nó.

Complexidade de Implementação: Implementar uma fila duplamente encadeada pode ser mais complexo do que uma fila simplesmente encadeada, 
devido à necessidade de manipular os ponteiros de forma mais elaborada.

Em geral, a escolha entre uma fila simplesmente encadeada e uma fila duplamente encadeada depende das necessidades específicas do seu programa. 
Se você precisa de acesso bidirecional ou operações eficientes no final da fila, uma fila duplamente encadeada pode ser a escolha certa. Caso contrário, 
uma fila simplesmente encadeada é mais simples e pode ser mais eficiente em termos de memória.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int edition;
} Book;

typedef struct Node {
    Book book;
    struct Node* next;
} Node;

Node* top = NULL;

void pushBook() {
    Book newBook;
    printf("Informe o título do livro (ou digite 'FIM' para encerrar): ");
    scanf(" %[^\n]", newBook.title);
    
    if (strcmp(newBook.title, "FIM") == 0) {
        return;
    }

    printf("Informe o autor do livro: ");
    scanf(" %[^\n]", newBook.author);
    
    printf("Informe a edição do livro: ");
    scanf("%d", &newBook.edition);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->book = newBook;
    newNode->next = top;
    top = newNode;

    printf("Livro empilhado com sucesso!\n");
}

void printStack() {
    Node* current = top;
    printf("Conteúdo da pilha:\n");
    while (current != NULL) {
        printf("Título: %s\n", current->book.title);
        printf("Autor: %s\n", current->book.author);
        printf("Edição: %d\n", current->book.edition);
        printf("---------------\n");
        current = current->next;
    }
}

void printStackToFile() {
    FILE* file = fopen("library.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Node* current = top;
    while (current != NULL) {
        fwrite(&current->book, sizeof(Book), 1, file);
        current = current->next;
    }

    fclose(file);
    printf("Pilha impressa em arquivo binário com sucesso!\n");
}

void readStackFromFile() {
    FILE* file = fopen("library.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Book bookRead;
    while (fread(&bookRead, sizeof(Book), 1, file)) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->book = bookRead;
        newNode->next = top;
        top = newNode;
    }

    fclose(file);
    printf("Pilha lida do arquivo binário com sucesso!\n");
}

int searchBookInStack(char titleToSearch[]) {
    Node* current = top;
    int steps = 0;

    while (current != NULL) {
        if (strcmp(current->book.title, titleToSearch) == 0) {
            return steps;
        }
        current = current->next;
        steps++;
    }

    return -1;
}

int main() {
    int option;
    char titleToSearch[100];

    do {
        printf("\nMenu:\n");
        printf("1 - Empilhar livro\n");
        printf("2 - Imprimir pilha na tela\n");
        printf("3 - Imprimir pilha em arquivo binário\n");
        printf("4 - Ler pilha do arquivo binário\n");
        printf("5 - Buscar livro na pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                pushBook();
                break;
            case 2:
                printStack();
                break;
            case 3:
                printStackToFile();
                break;
            case 4:
                readStackFromFile();
                break;
            case 5:
                printf("Informe o título do livro que deseja buscar: ");
                scanf(" %[^\n]", titleToSearch);
                int steps = searchBookInStack(titleToSearch);
                if (steps == -1) {
                    printf("Livro não encontrado na pilha.\n");
                } else {
                    printf("Livro encontrado na posição %d da pilha.\n", steps);
                }
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (option != 0);

    return 0;
}


//RESPOSTA DA 3 

// /*
// Vantagens:

// Acesso rápido ao elemento anterior: Com os ponteiros para o nó anterior, você pode acessar rapidamente o elemento que está 
// abaixo do topo da pilha, o que pode ser útil em certos cenários.

// Implementação de funcionalidades extras: A estrutura duplamente encadeada permite implementar funcionalidades adicionais,
//  como percorrer a pilha de trás para frente, o que pode ser útil em algumas situações.

// Desvantagens:

// Uso de memória adicional: Cada nó possui dois ponteiros extras (para o anterior e o próximo), o que aumenta o uso de memória em comparação com uma pilha
//  simplesmente encadeada.

// Complexidade de implementação: Uma pilha duplamente encadeada é mais complexa de implementar do que uma pilha simplesmente encadeada, devido à 
// necessidade de manter o rastreamento dos ponteiros prev e next.

// Portanto, a escolha entre uma pilha simplesmente encadeada e uma pilha duplamente encadeada depende das necessidades específicas do seu programa. 
// Se você precisa de acesso rápido ao elemento anterior e está disposto a gastar mais memória, uma pilha duplamente encadeada pode ser uma boa escolha. Caso contrário, 
// uma pilha simplesmente encadeada pode ser mais eficiente em termos de memória e mais simples de implementar.

// */
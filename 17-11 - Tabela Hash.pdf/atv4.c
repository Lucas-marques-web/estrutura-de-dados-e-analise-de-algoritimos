#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Funcionario
typedef struct {
    char nome[50];
    char data_admissao[11];
    float salario;
} Funcionario;

// Definição da estrutura No para a lista encadeada
typedef struct No {
    Funcionario funcionario;
    struct No* proximo;
} No;

// Definição da estrutura TabelaHash
typedef struct {
    No** tabela;
    int tamanho;
} TabelaHash;

// Função de hash simples
int hash(char* chave, int tamanho) {
    int hash = 0;
    while (*chave) {
        hash += *chave;
        chave++;
    }
    return hash % tamanho;
}

// Função para criar um novo funcionário
Funcionario criarFuncionario(char* nome, char* data_admissao, float salario) {
    Funcionario novoFuncionario;
    strcpy(novoFuncionario.nome, nome);
    strcpy(novoFuncionario.data_admissao, data_admissao);
    novoFuncionario.salario = salario;
    return novoFuncionario;
}

// Função para criar um novo nó na lista encadeada
No* criarNo(Funcionario funcionario) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo != NULL) {
        novoNo->funcionario = funcionario;
        novoNo->proximo = NULL;
    }
    return novoNo;
}

// Função para cadastrar um funcionário na tabela hash
void cadastrarFuncionario(TabelaHash* tabela, Funcionario funcionario) {
    int indice = hash(funcionario.nome, tabela->tamanho);

    No* novoNo = criarNo(funcionario);

    // Se a posição na tabela estiver vazia, cria uma nova lista encadeada
    if (tabela->tabela[indice] == NULL) {
        tabela->tabela[indice] = novoNo;
    } else {
        // Adiciona à lista mantendo a ordem ascendente
        No* atual = tabela->tabela[indice];
        No* anterior = NULL;

        while (atual != NULL && strcmp(atual->funcionario.nome, funcionario.nome) < 0) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL) {
            novoNo->proximo = tabela->tabela[indice];
            tabela->tabela[indice] = novoNo;
        } else {
            anterior->proximo = novoNo;
            novoNo->proximo = atual;
        }
    }
}

// Função para pesquisar um funcionário na tabela hash por nome
Funcionario* pesquisarPorNome(TabelaHash* tabela, char* nome) {
    int indice = hash(nome, tabela->tamanho);

    No* atual = tabela->tabela[indice];

    while (atual != NULL) {
        if (strcmp(atual->funcionario.nome, nome) == 0) {
            return &(atual->funcionario);
        }
        atual = atual->proximo;
    }

    return NULL;
}

// Função para pesquisar funcionários na tabela hash por data de admissão
Funcionario** pesquisarPorData(TabelaHash* tabela, char* data_admissao, int* numResultados) {
    Funcionario** resultados = NULL;
... (167 linhas)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados para um funcionário
struct Funcionario {
    char cpf[12];
    char nome[100];
    char endereco[100];
    char telefone[15];
    char celular[15];
    char dataNascimento[11];
    char dataAdmissao[11];
    char departamento[50];
    char cargo[50];
    double salario;
};

typedef struct Funcionario Funcionario;

// Função para enfileirar um funcionário na fila
void enfileirarFuncionario(FILE *arquivo, Funcionario *funcionario) {
    fwrite(funcionario, sizeof(Funcionario), 1, arquivo);
}

// Função para desenfileirar um funcionário da fila
void desenfileirarFuncionario(FILE *arquivo, Funcionario *funcionario) {
    fread(funcionario, sizeof(Funcionario), 1, arquivo);
}

// Função para buscar um funcionário por CPF
void buscarFuncionarioPorCPF(const char *cpfBuscado) {
    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        return;
    }

    Funcionario funcionario;
    int encontrado = 0;

    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
        if (strcmp(cpfBuscado, funcionario.cpf) == 0) {
            printf("Funcionário encontrado:\n");
            printf("CPF: %s\n", funcionario.cpf);
            printf("Nome: %s\n", funcionario.nome);
            printf("Endereço: %s\n", funcionario.endereco);
            printf("Telefone: %s\n", funcionario.telefone);
            printf("Celular: %s\n", funcionario.celular);
            printf("Data de Nascimento: %s\n", funcionario.dataNascimento);
            printf("Data de Admissão: %s\n", funcionario.dataAdmissao);
            printf("Departamento: %s\n", funcionario.departamento);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Salário: %.2lf\n", funcionario.salario);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário com CPF %s não encontrado.\n", cpfBuscado);
    }

    fclose(arquivo);
}

int main() {
    FILE *arquivo = fopen("funcionarios.dat", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de funcionários.\n");
        return 1;
    }

    // Enfileirar 10 registros de funcionários (pode fazer isso em um loop)
    Funcionario funcionario1 = {
        .cpf = "12345678901",
        .nome = "João Silva",
        .endereco = "Rua A, 123",
        .telefone = "(11) 1234-5678",
        .celular = "(11) 98765-4321",
        .dataNascimento = "01/01/1980",
        .dataAdmissao = "15/05/2021",
        .departamento = "TI",
        .cargo = "Programador",
        .salario = 4500.0
    };

    enfileirarFuncionario(arquivo, &funcionario1);

    // Para adicionar mais funcionários, basta repetir o processo

    fclose(arquivo);

    // Exemplo de busca por CPF
    char cpfBuscado[12];
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%s", cpfBuscado);
    buscarFuncionarioPorCPF(cpfBuscado);

    return 0;
}
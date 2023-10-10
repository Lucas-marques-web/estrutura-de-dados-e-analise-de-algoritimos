#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Funcionario {
    char cpf[12];  // 11 dígitos + 1 para o terminador nulo
    char nome[100];
    char endereco[100];
    char telefone[15];
    char celular[15];
    struct Data dataNascimento;
    struct Data dataAdmissao;
    char departamento[50];
    char cargo[50];
    double salario;
};

void lerFuncionarios(struct Funcionario funcionarios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nInforme os dados do funcionário %d:\n", i + 1);

        printf("CPF: ");
        scanf("%s", funcionarios[i].cpf);

        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);

        printf("Endereço: ");
        scanf("%s", funcionarios[i].endereco);

        printf("Telefone: ");
        scanf("%s", funcionarios[i].telefone);

        printf("Celular: ");
        scanf("%s", funcionarios[i].celular);

        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &funcionarios[i].dataNascimento.dia, &funcionarios[i].dataNascimento.mes, &funcionarios[i].dataNascimento.ano);

        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &funcionarios[i].dataAdmissao.dia, &funcionarios[i].dataAdmissao.mes, &funcionarios[i].dataAdmissao.ano);

        printf("Departamento: ");
        scanf("%s", funcionarios[i].departamento);

        printf("Cargo: ");
        scanf("%s", funcionarios[i].cargo);

        printf("Salário: ");
        scanf("%lf", &funcionarios[i].salario);
    }
}

void salvarFuncionarios(struct Funcionario funcionarios[], int n) {
    FILE *arquivo = fopen("funcionarios.dat", "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fwrite(funcionarios, sizeof(struct Funcionario), n, arquivo);
    fclose(arquivo);
}

void carregarFuncionarios(struct Funcionario funcionarios[], int n) {
    FILE *arquivo = fopen("funcionarios.dat", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fread(funcionarios, sizeof(struct Funcionario), n, arquivo);
    fclose(arquivo);
}

int pesquisarFuncionarioPorCPF(struct Funcionario funcionarios[], int n, const char *cpf) {
    for (int i = 0; i < n; i++) {
        if (strcmp(funcionarios[i].cpf, cpf) == 0) {
            return i;  // Retorna o índice do funcionário encontrado
        }
    }
    return -1;  // Funcionário não encontrado
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];

    lerFuncionarios(funcionarios, MAX_FUNCIONARIOS);
    salvarFuncionarios(funcionarios, MAX_FUNCIONARIOS);

    printf("\nFuncionários cadastrados:\n");
    carregarFuncionarios(funcionarios, MAX_FUNCIONARIOS);

    for (int i = 0; i < MAX_FUNCIONARIOS; i++) {
        printf("Funcionário %d:\n", i + 1);
        printf("CPF: %s\n", funcionarios[i].cpf);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Endereço: %s\n", funcionarios[i].endereco);
        printf("Telefone: %s\n", funcionarios[i].telefone);
        printf("Celular: %s\n", funcionarios[i].celular);
        printf("Data de Nascimento: %02d/%02d/%04d\n", funcionarios[i].dataNascimento.dia, funcionarios[i].dataNascimento.mes, funcionarios[i].dataNascimento.ano);
        printf("Data de Admissão: %02d/%02d/%04d\n", funcionarios[i].dataAdmissao.dia, funcionarios[i].dataAdmissao.mes, funcionarios[i].dataAdmissao.ano);
        printf("Departamento: %s\n", funcionarios[i].departamento);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salário: %.2lf\n\n", funcionarios[i].salario);
    }

    char cpfPesquisa[12];
    printf("Informe o CPF a ser pesquisado: ");
    scanf("%s", cpfPesquisa);

    int indice = pesquisarFuncionarioPorCPF(funcionarios, MAX_FUNCIONARIOS, cpfPesquisa);
    if (indice != -1) {
        printf("Funcionário encontrado no índice %d:\n", indice);
        printf("CPF: %s\n", funcionarios[indice].cpf);
        printf("Nome: %s\n", funcionarios[indice].nome);
        printf("Endereço: %s\n", funcionarios[indice].endereco);
        printf("Telefone: %s\n", funcionarios[indice].telefone);
        printf("Celular: %s\n", funcionarios[indice].celular);
        printf("Data de Nascimento: %02d/%02d/%04d\n", funcionarios[indice].dataNascimento.dia, funcionarios[indice].dataNascimento.mes, funcionarios[indice].dataNascimento.ano);
        printf("Data de Admissão: %02d/%02d/%04d\n", funcionarios[indice].dataAdmissao.dia, funcionarios[indice].dataAdmissao.mes, funcionarios[indice].dataAdmissao.ano);
        printf("Departamento: %s\n", funcionarios[indice].departamento);
        printf("Cargo: %s\n", funcionarios[indice].cargo);
        printf("Salário: %.2lf\n", funcionarios[indice].salario);
    } else {
        printf("Funcionário com CPF %s não encontrado.\n", cpfPesquisa);
    }

    return 0;
}

#include <stdio.h>
#include <locale.h>

int CalculoPotencia(int n1, int n2);
int somaNaturais(int n);

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");
    int base, expoente, resultado, quantidade, escolha;

    printf("Questoes:\n 1 - Calculo de Potencia\n 2 - Soma dos Numeros\n");
    printf("Escolha a questao:");
    scanf("%d", &escolha);

    if (escolha == 1) {
        printf("Base: ");
        scanf("%d", &base);
        printf("Expoente: ");
        scanf("%d", &expoente);
        resultado = CalculoPotencia(base, expoente);
        printf("%d^%d = %d", base, expoente, resultado);
        return 0;
    } else {
        printf("Quantidade de numeros: ");
        scanf("%d", &quantidade);
        resultado = somaNaturais(quantidade);
        printf("O resultado e = %d", resultado);
        return 0;
    }
}

int CalculoPotencia(int base, int expoente) {
    if (expoente != 0)
        return (base * CalculoPotencia(base, expoente - 1));
    else
        return 1;
}

int somaNaturais(int quantidade) {
    if (quantidade != 0)
        return (quantidade + somaNaturais(quantidade - 1));
    else
        return 0;
}

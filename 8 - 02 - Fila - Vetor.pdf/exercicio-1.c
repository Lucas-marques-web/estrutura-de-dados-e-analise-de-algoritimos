/*
* Programa que lê números inteiros a partir
* do teclado e os armazena em uma fila.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef int elemento;
#include "fila.h"
int main() {
int num;
fila f;
CriarFila(&f);
while(FilaCheia(&f) == FALSO) {
printf("\nInforme um numero inteiro: ");
scanf("%d", &num);
Enfileirar(&f, num);
}
printf("\nNumeros informados: ");
while(FilaVazia(&f) == FALSO) {
num = Desenfileirar(&f);
printf("\n%d", num);
}
printf("\n");
system("pause");
return 0;
}
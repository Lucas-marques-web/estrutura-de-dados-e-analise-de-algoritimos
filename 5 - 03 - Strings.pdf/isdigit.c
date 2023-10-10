#include <stdio.h> // printf()
#include <ctype.h> // isdigit

int main() {
    char texto[] = "An15a MaRia @v #.";

    printf("Retorna 1 se e um digito e 0 no caso contrario: \n");
    printf("%s\n", texto);
    
    for (int i = 0; texto[i]; i++) {
        // Verifica se o caractere é um digito e, se for, substitui por 1, senão, substitui por 0:
        if (isdigit(texto[i])) {
            texto[i] = '1';
        } else {
            texto[i] = '0';
        }
    }

    printf(texto);
    
    return 0;
}

#include <stdio.h> // printf()
#include <ctype.h> // isalpha

int main() {
    char texto[] = "An15a MaRia @v #.";

    printf("Substitui o caractere por 1 se for letra e 0 caso nao seja: \n");
    printf("%s\n", texto);
    
    for (int i = 0; texto[i]; i++) {
        // Verifica se o caractere é uma letra e, se for, substitui por 1, senão, substitui por 0:
        if (isalpha(texto[i])) {
            texto[i] = '1';
        } else {
            texto[i] = '0';
        }
    }

    printf(texto);
    
    return 0;
}

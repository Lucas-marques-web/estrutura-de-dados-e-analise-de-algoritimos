#include <stdio.h> // printf()
#include <ctype.h> // isalnum

int main() {
    char texto[] = "An15a MaRia @v #.";

    printf("Substitui o caractere por 1 se for uma letra ou um dígito e 0 caso nao seja: \n");
    printf("%s\n", texto);
    
    for (int i = 0; texto[i]; i++) {
        // Verifica se o caractere é uma letra ou um dígito e, se for, substitui por 1, senão, substitui por 0:
        if (isalnum(texto[i])) {
            texto[i] = '1';
        } else {
            texto[i] = '0';
        }
    }

    printf(texto);
    
    return 0;
}

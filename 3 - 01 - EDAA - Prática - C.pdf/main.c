#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");

    int choice;
    float grade1, grade2, grade3, average;
    int birthYear, currentYear, currentAge, age2050;
    float dollarExchangeRate, dollarAmount, realAmount;
    float salary, newSalary;
    float largerDiagonal, smallerDiagonal, diamondArea;
    float celsiusTemperature, fahrenheitTemperature;
    float minimumWage, numMinimumWages;
    float weight, newWeight15, newWeight20;
    float leg1, leg2, hypotenuse;
    float radius, sphereCircumference, sphereArea, sphereVolume;
    int number, i;

    printf("Sumario\n");
    printf("1- media de notas \n 2- calculo de idade \n");
    printf("3- cotacao do dolar \n 4- calculo de salario \n");
    printf("5- calcular area do losango \n 6- conversao de temperatura \n");
    printf("7- calculo de quantos salarios minimos o funcionario recebe \n 8- calculo de peso \n");
    printf("9- calcular hipotenusa \n 10- calculo de raio \n");
    printf("11- tabuada\n");
    printf("Escolha uma funcionalidade (1-11): \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Digite as tres notas: ");
            scanf("%f %f %f", &grade1, &grade2, &grade3);
            average = (grade1 + grade2 + grade3) / 3;
            printf("Media: %.2f\n", average);
            break;

        case 2:
             printf("Digite o ano de nascimento: ");
            scanf("%d", &birthYear);
            printf("Digite o ano atual: ");
            scanf("%d", &currentYear);
            currentAge = currentYear - birthYear;
            age2050 = 2050 - birthYear;
            printf("Idade atual: %d anos\n", currentAge);
            printf("Idade em 2050: %d anos\n", age2050);
            break;

        case 3:
            printf("Digite a cotacao do dolar em reais: ");
            scanf("%f", &dollarExchangeRate);
            printf("Digite a quantidade de dolares que voce possui: ");
            scanf("%f", &dollarAmount);
            realAmount = dollarAmount * dollarExchangeRate;
            printf("Valor em reais: %.2f\n", realAmount);
            break;

        case 4:
            printf("Digite o salario do funcionario: ");
            scanf("%f", &salary);
            newSalary = salary * 1.25;
            printf("Novo salario: %.2f\n", newSalary);
            break;

        case 5:
            printf("Digite a diagonal maior do losango: ");
            scanf("%f", &largerDiagonal);
            printf("Digite a diagonal menor do losango: ");
            scanf("%f", &smallerDiagonal);
            diamondArea = (largerDiagonal * smallerDiagonal) / 2;
            printf("Area do losango: %.2f\n", diamondArea);
            break;

        case 6:
            printf("Digite a temperatura em Celsius: ");
            scanf("%f", &celsiusTemperature);
            fahrenheitTemperature = (celsiusTemperature * 1.8) + 32;
            printf("Temperatura em Fahrenheit: %.2f\n", fahrenheitTemperature);
            break;

        case 7:
            printf("Digite o valor do salario minimo: ");
            scanf("%f", &minimumWage);
            numMinimumWages = salary / minimumWage;
            printf("Quantidade de salarios minimos: %.2f\n", numMinimumWages);
            break;

        case 8:
            printf("Digite o peso da pessoa: ");
            scanf("%f", &weight);
            newWeight15 = weight * 1.15;
            newWeight20 = weight * 0.80;
            printf("Peso se engordar 15%%: %.2f\n", newWeight15);
            printf("Peso se emagrecer 20%%: %.2f\n", newWeight20);
            break;

        case 9:
            printf("Digite os valores dos dois catetos: ");
            scanf("%f %f", &leg1, &leg2);
            hypotenuse = sqrt(leg1 * leg1 + leg2 * leg2);
            printf("Hipotenusa: %.2f\n", hypotenuse);
            break;

        case 10:
           printf("Digite o raio da esfera: ");
            scanf("%f", &radius);
            sphereCircumference = 2 * 3.14159265359 * radius;
            sphereArea = 3.14159265359 * radius * radius;
            sphereVolume = (3.0 / 4.0) * 3.14159265359 * radius * radius * radius;
            printf("Comprimento da esfera: %.2f\n", sphereCircumference);
            printf("Area da esfera: %.2f\n", sphereArea);
            printf("Volume da esfera: %.2f\n", sphereVolume);
            break;

        case 11:
            printf("Informe um numero para a tabuada: ");
            scanf("%d", &number);
            for (i = 0; i <= 10; i++) {
                printf("%d x %d = %d\n", number, i, number * i);
            }
            break;

        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}

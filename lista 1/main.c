#include <stdio.h>
#include <math.h>

// 1) Receba três notas, calcule e apresente a média aritmética delas.
    void MediaNotas(){
        float Notas[3];
        float Media = 0;
        int i;
        for(i=0;i<3;i++){
            printf("Digite sua nota: \n");
            scanf("%f", &Notas[i]);
            Media = Media + Notas[i];
        }
        Media = Media/3;
        printf("Media das Notas: %f\n", Media);
        
    }


// 2) Receba o ano de nascimento de uma pessoa, o ano atual e imprima:
    void CalcularIdade() {
        int anoAtual, anoNascimento, anoFuturo = 2050;
        
        // Obtenha o ano atual a partir do sistema ou do usuário
        printf("Digite o ano atual: \n");
        scanf("%d", &anoAtual);

        printf("Digite o ano de seu Nascimento: \n");
        scanf("%d", &anoNascimento);

        int idade = anoAtual - anoNascimento;
        int idadeFuturo = anoFuturo - anoNascimento;
        printf("A sua idade no ano de %d e : %d anos\n", anoAtual, idade);
        printf("A sua idade no ano de %d e : %d anos\n", anoFuturo, idadeFuturo);
    }


// 3) Receba a cotação do dólar em reais e um valor que o usuário possui em dólares.
// Imprima este valor em reais.
    void conversorDolar(){
    float cambio, valorTransferido,valorConvertido;
    printf("Digite o valor do cambio para 1 dolar em reais:\n");
    scanf("%f", &cambio);
    printf("Digite o valor em dolar para conversao para reais:\n");
    scanf("%f", &valorTransferido);
    valorConvertido = valorTransferido*cambio;
    printf("o valor convertido e: %.2f reais", valorConvertido );
    }


// 4) Faça um programa que receba o salário de um funcionário, calcule e mostre o novo
// salário, sabendo-se que ele teve um aumento de 25%.
    void aumentoSalarial(){
        float salario, percentualAumento = 0.25, aumentoSalarial;
        printf("Digite seu salario:\n");
        scanf("%f", &salario);
        aumentoSalarial = salario + (salario*percentualAumento);
        printf("O novo salario e: %.2f reais", aumentoSalarial);
    }


// 5) Calcule e apresente a área de um losango. As diagonais maior e menor do losango
// devem ser informadas pelo usuário. OBS: AREA = (DIAGONAL MAIOR * DIAGONALMENOR) / 2.
    void calcularAreaLosango(){
        float diagonalMaior, diagonalMenor, areaLosango;
        printf("Digite a diagonal Maior:\n");
        scanf("%f", &diagonalMaior);
        printf("Digite a diagonal Menor:\n");
        scanf("%f", &diagonalMenor);
        areaLosango = (diagonalMaior*diagonalMenor)/2;
        printf("A area do losango e: %.2f", areaLosango);
    }


// 6) Receba uma temperatura em Celsius, calcule e mostre essa temperatura em Fahrenheit.
// OBS: F = (C * 1,8) + 32.
    void convesorTemperatura(){
        float temperaturaCelsius, temperaturaFahrenheit;
        printf("Digite a Temperatura em Celsius para conversao:\n");
        scanf("%f",&temperaturaCelsius);
        temperaturaFahrenheit = (temperaturaCelsius*1.8) + 32;
        printf("A temperatura em Fahrenheit e: %.2f",temperaturaFahrenheit); 
    }


// 7) Receba o valor do salário mínimo e o valor do salário de um funcionário. O algoritmo
// deve calcular e apresentar a quantidade de salários mínimos que esse funcionário recebe.
    void calcularQtdSalarioMin(){
        float salarioMin, salario;
        int qtdSalarioMin;
        printf("Digite o salario minimo:\n");
        scanf("%f",&salarioMin);
        printf("Digite o seu salario :\n");
        scanf("%f",&salario);
        qtdSalarioMin = salario/salarioMin;
        printf("Voce recebe %d salarios minimos",qtdSalarioMin);
    }


// 8) Receba o peso de uma pessoa, calcule e apresente o novo peso:
    void calcularPeso(){
        float peso, engordar, emagrecer;
        printf("Digite seu peso em KG:\n");
        scanf("%f",&peso);
        engordar = peso + (peso*0.15);
        emagrecer = peso - (peso*0.20);
        printf("Caso voce engorde 15/100 tera %.2f \n",engordar);
        printf("Caso emagreca 20/100 tera %.2f \n",emagrecer);

    }


// 9) Receba os valores dos dois catetos de um triângulo, calcule e apresente o valor da
// hipotenusa. OBS - Teorema de Pitágoras: a^2 = b^2 + c^2
    void calcularHipotenusa(){
        float hipotenusa, cateto1, cateto2;
        printf("Digite o Valor do primeiro cateto:\n");
        scanf("%f",&cateto1);
        printf("Digite o Valor do segundo cateto:\n");
        scanf("%f",&cateto2);
        hipotenusa = (cateto1*cateto1) + (cateto2*cateto2);
        hipotenusa = sqrt(hipotenusa);
        printf("A hipotenusa e: %.2f",hipotenusa);
        
    }


// 10) Receba o raio, calcule e apresente:
    void calcularRaio(){
        float raioEsfera, comprimentoEsfera, areaEsfera, volumeEsfera, pi = 3.14;
        printf("Digite o valor do raio:\n");
        scanf("%f",&raioEsfera);
        comprimentoEsfera = 2 * pi * raioEsfera;
        areaEsfera = pi * (raioEsfera * raioEsfera);
        volumeEsfera = 0.75 * pi * (raioEsfera*raioEsfera*raioEsfera);
        printf("O comprimento da esfera e: %.2f \n",comprimentoEsfera);
        printf("A Area da esfera e: %.2f \n",areaEsfera);
        printf("O Volume da esfera e: %.2f \n",volumeEsfera);
        
    }


// 11) Calcule e mostre a tabuada de multiplicação de um número informado pelo usuário no teclado.
    void calcularTabuada(){
        int num,i,multiplicacao = 0;
        printf("Informe um numero: ");
        scanf("%d",&num);
        for(i=0;i<11;i++){
            multiplicacao = num * i;
            printf("%d X %d = %d \n",num,i,multiplicacao);
        }
    }


int main(){
    
    //  Delete o comentario da função para faze-la funcionar 
    
    // Exercicio 1
    // MediaNotas();
 
    // Exercicio 2
    // CalcularIdade();

    // Exercicio 3
    // conversorDolar();
    
    // Exercicio 4
    // aumentoSalarial();
    
    // Exercicio 5
    // calcularAreaLosango();
    
    // Exercicio 6
    // convesorTemperatura();
    
    // Exercicio 7
    // calcularQtdSalarioMin();
    
    // Exercicio 8
    // calcularPeso();

    // Exercicio 9
    // calcularHipotenusa();

    // Exercicio 10
    // calcularRaio();

    // Exercicio 11
    calcularTabuada();

    return 0;
}
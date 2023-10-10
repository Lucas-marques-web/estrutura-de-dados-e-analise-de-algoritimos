/*
* Arquivo: fila.h
* Biblicoteca de operações para fila implementada
* com vetor.
*/
#define VERDADEIRO 1
#define FALSO 0
struct tipo_fila {
elemento vet[TAM];
int inicio, fim;
};
typedef struct tipo_fila fila;
//Cria fila.
void CriarFila(fila *f) {
(*f).inicio = 0;
(*f).fim = 0;
}
//Verifica se a fila está vazia.
int FilaVazia(fila *f) {
return((*f).inicio == (*f).fim);
}
//Verifica se a fila está cheia.
int FilaCheia(fila *f) {
return((*f).fim == TAM);
}
//Insere um elemento na fila.
void Enfileirar(fila *f, elemento e) {
(*f).vet[(*f).fim++] = e;
}
//Retira um elemento na fila.
elemento Desenfileirar(fila *f) {
return((*f).vet[(*f).inicio++]);
}

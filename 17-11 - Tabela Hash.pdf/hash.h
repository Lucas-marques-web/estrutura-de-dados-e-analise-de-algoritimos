/* Arquivo: hash.h
* Biblicoteca de operações para tabela hash implementada com lista e alocação
dinâmica de memória.
*/
#include "lista.h"
/*
* Estrutura de cada entrada da tabela hash.
*/
typedef struct TipoEntrada {
char* chave;
lista l;
} entrada;
/*
* Definição do tipo hash.
*/
typedef entrada hash[TAM];
/*
* Cria uma tabela hash vazia.
*/
void CriarHash (hash h) {
int i;
for (i = 0; i < TAM; i++)
CriarLista (&(h[i].l));
}

/*
* Função de hash.
*/
int FuncaoHash (char *chave) {
int i, soma = 0;
for (i = 0; chave[i] != '\0'; i++)
soma += chave[i];
return (soma % TAM);
}
/*
* Imsere um elemento na tabela hash.
*/
void InserirHash (hash h, char *chave, elemento *e) {
int i, tam_chave;
i = FuncaoHash (chave);
tam_chave = strlen (chave) + 1; //strlen () retorna o comprimento do string
passado como parâmetro. O terminador nulo ('\0') n�o � contado. Isto quer dizer
que, de fato, o comprimento do vetor para armazenar a string deve ser um a mais que
o inteiro retornado por strlen().
if (h[i].l != NULL)
free (h[i].chave); //Na colisão, remove a chave anterior para inserir a chave
corrente.
h[i].chave = (char*) malloc (sizeof (char) * tam_chave);
strcpy (h[i].chave, chave);
Alistar (&(h[i].l), e);
}
/*
* Procura um elemento na tabela hash.
* Se o elemento procurado estiver na tabela hash, retorna o endereco predecessor
do elemento.
* Se o elemento procurado não estiver na tabela hash, retorna NULL.
*/
pt_nodo* PesquisarHash (hash h, char *chave) {
int i;
pt_nodo *pred;
i = FuncaoHash (chave);
pred = &(h[i].l);
return (PesquisarLista (pred, chave));
}

/*
* Retira um elemento da tabela hash.
*/
elemento ExcluirHash (pt_nodo *p) {
return (Desalistar (p));
}
/*
* Limpa a tabela hash.
*/
void LimparHash (hash h) {
int i;
pt_nodo aux, aux2;
for (i = 0; i < TAM; i++) {
if (h[i].l != NULL) {
aux = h[i].l;
while (aux != NULL) {
aux2 = aux;
aux = aux->prox;
free (aux2);
}
h[i].l = NULL;
free (h[i].chave);
}
}
}
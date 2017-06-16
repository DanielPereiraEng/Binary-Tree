#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

//#define DEBUG

struct listas_enc {
    no_t *cabeca;
    no_t *cauda;
    int tamanho;
};

/* Funções privadas */
void swap_nos(lista_enc_t *lista, no_t *fonte, no_t *destino);

//cria uma lista vazia
lista_enc_t *cria_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        ligar_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}

no_t *obtem_cabeca(lista_enc_t *lista){

    if (lista == NULL){
        fprintf(stderr,"obtem_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return lista->cabeca;
}

int lista_vazia(lista_enc_t *lista)
{
	int ret;

	(lista->tamanho == 0) ? (ret = 1) : (ret = 0);

	return ret;
}

int obtem_tamanho(lista_enc_t *lista)
{
	if (lista == NULL){
        fprintf(stderr,"obtem_tamanho: problemas");
        exit(EXIT_FAILURE);
    }

	return lista->tamanho;
}

no_t *remover_cabeca(lista_enc_t *lista)
{
	no_t *proximo;
	no_t *removido;

	if (lista == NULL){
	    fprintf(stderr,"remover_cauda: ponteiro invalido");
	    exit(EXIT_FAILURE);
	}

	if (lista->cabeca == NULL)
		return NULL;

	removido = lista->cabeca;

	if (lista->cauda == lista->cabeca) {
		lista->tamanho = 0;

		lista->cauda = NULL;
		lista->cabeca = NULL;

		return removido;
	}

	proximo = obter_proximo(lista->cabeca);
	desligar_no(removido);
	lista->cabeca = proximo;
	lista->tamanho--;


	return removido;
}

#ifndef ARVORE_BIN_H_
#define ARVORE_BIN_H_

#include "lista_enc.h"
#include "pacientes.h"

typedef struct arvore arvore_t;

void new_tree(arvore_t **tree , paciente_t *pacientes[], int maximo);

void ramo_left(arvore_t **tree, paciente_t *pacientes[], int indice, int maximo);

void ramo_right(arvore_t **tree, paciente_t *pacientes[], int indice, int maximo);

void print_tree(arvore_t *tree, int tamanho);

int print_left(arvore_t *tree, int tamanho, int indice);

int print_right(arvore_t *tree, int tamanho, int indice);

void trocar(arvore_t *maior, arvore_t *menor);

void heap_sort(arvore_t **tree, int maximo);

int organizador_loop(arvore_t *tree, int mudar, int indice);

void novo_paciente(arvore_t **tree, int maximo);

void novo_na_arvore(arvore_t **tree, paciente_t *paciente, int tamanho);

void new_leaf(arvore_t **tree, paciente_t *paciente, int tamanho);

void liberador(arvore_t *tree,int tamanho);

#endif /* ARVORE_BIN_H_ */

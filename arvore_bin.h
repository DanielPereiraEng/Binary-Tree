#ifndef ARVORE_BIN_H_
#define ARVORE_BIN_H_

#include "pacientes.h"

typedef struct arvore arvore_t;

void print_tree(arvore_t *tree, int tamanho, int indice);

int imprimir(arvore_t *tree, int tamanho, int indice);

arvore_t *heapsort_loop(arvore_t *tree, int tamanho);

arvore_t *heapsort(arvore_t *tree);

void new_tree(arvore_t **tree , paciente_t *paciente_atual[], int maximo, int indice);

int new_tree_loop(arvore_t **tree, paciente_t *paciente_atual[], int maximo, int indice);

#endif /* ARVORE_BIN_H_ */

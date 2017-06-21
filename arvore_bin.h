#ifndef ARVORE_BIN_H_
#define ARVORE_BIN_H_

#include "pacientes.h"

typedef struct arvore arvore_t;

void print_tree(arvore_t *tree, int tamanho, int indice);

int imprimir(arvore_t *tree, int tamanho, int indice);

void new_tree(arvore_t **tree , paciente_t *paciente_atual[], int maximo, int indice);

int new_tree_loop(arvore_t **tree, paciente_t *paciente_atual[], int maximo, int indice);

void *organizador(arvore_t **tree, int maximo, int indice);

int organizador_loop(arvore_t *tree, int mudar, int indice);

void trocar(arvore_t *maior, arvore_t *menor);

void libera_tree(arvore_t *tree, int tamanho, int indice);

int limpar(arvore_t *tree, int tamanho, int indice);

#endif /* ARVORE_BIN_H_ */

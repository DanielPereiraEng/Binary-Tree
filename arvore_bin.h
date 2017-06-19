#ifndef ARVORE_BIN_H_
#define ARVORE_BIN_H_

#include "pacientes.h"

typedef struct arvore arvore_t;

void print_preorder(arvore_t *tree);
void print_inorder(arvore_t *tree);
void print_posorder(arvore_t *tree);

arvore_t *heapsort_loop(arvore_t *tree, int tamanho);

arvore_t *heapsort(arvore_t *tree);

void new_tree(arvore_t **tree , paciente_t *paciente_atual[], int maximo, int indice);

int new_tree_loop(arvore_t **tree, paciente_t *paciente_atual[], int maximo, int indice, int controle);

#endif /* ARVORE_BIN_H_ */

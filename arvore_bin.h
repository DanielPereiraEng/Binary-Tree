#ifndef ARVORE_BIN_H_
#define ARVORE_BIN_H_

#include "pacientes.h"
#include "pilha.h"

typedef struct arvore arvore_t;


void inserir(arvore_t **tree , paciente_t *paciente_atual);

void print_preorder(arvore_t *tree);
void print_inorder(arvore_t *tree);
void print_posorder(arvore_t *tree);

#endif /* ARVORE_BIN_H_ */

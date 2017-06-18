#ifndef ARVORE_BIN_H_
#define ARVORE_BIN_H_

#include "pacientes.h"
#include "pilha.h"

typedef struct arvore arvore_t;

void inicializar(arvore_t **tree ,paciente_t *paciente_atual, pilha_t *main_stack);

void inserir(arvore_t **tree , paciente_t *paciente_atual, pilha_t *main_stack, int indice);

void print_preorder(arvore_t *tree);

#endif /* ARVORE_BIN_H_ */

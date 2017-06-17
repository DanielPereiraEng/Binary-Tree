#ifndef ARVORE_BIN_H_
#define ARVORE_BIN_H_

#include "pacientes.h"

typedef struct arvore arvore_t;

void inserir(arvore_t **tree ,paciente_t *paciente_atual);

#endif /* ARVORE_BIN_H_ */

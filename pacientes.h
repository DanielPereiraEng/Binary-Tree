#ifndef PACIENTES_H_
#define PACIENTES_H_

#include "lista_enc.h"
#include "fila.h"

typedef struct pacientes paciente_t;

lista_enc_t *ler_arquivo(char *nome_arq);

paciente_t *cria_paciente(char *nome, int idade, char sexo, char *diagnostico, int prioridade, int chance);

#endif /* PACIENTES_H_ */

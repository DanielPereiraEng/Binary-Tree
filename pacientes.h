#ifndef PACIENTES_H_
#define PACIENTES_H_

#include "lista_enc.h"
#include "fila.h"

typedef struct pacientes paciente_t;

lista_enc_t *ler_arquivo(char *nome_arq);

paciente_t *cria_paciente(char *nome, int idade, char sexo, char *diagnostico, int prioridade, int chance);

fila_t* cria_fila_pacientes (lista_enc_t *lista);

char * obter_nome(paciente_t *p);
char obter_sexo(paciente_t *p);
int obter_idade(paciente_t *p);
char * obter_diagnostico(paciente_t *p);
int obter_prioridade(paciente_t *p);
int obter_chance(paciente_t *p);

void libera_dados_list_enc(lista_enc_t *lista);

#endif /* PACIENTES_H_ */

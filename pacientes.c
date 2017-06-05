#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pacientes.h"
#include "lista_enc.h"
#include "no.h"
#include "fila.h"


#define DEBUG
#define TAM_BUFFER 100

#define TRUE 1
#define FALSE 0

struct pacientes{
    char *nome;
    int idade;
    char sexo;
    char *diagnostico;
    int prioridade;
    int chance;
};


lista_enc_t *ler_arquivo(char *nome){

	char buffer[TAM_BUFFER];
	char buffer_nome[TAM_BUFFER];
	int idade;
	char sexo;
	char buffer_diagnostico[TAM_BUFFER];
	int prioridade;
	int chance;
	int controle;

	FILE *fp;

	lista_enc_t *lista;
    no_t *no;
    paciente_t *paciente;

	fp = fopen(nome, "r");

	if (fp == NULL){
		perror("ler_arquivo");
		exit(EXIT_FAILURE);
	}

	lista = cria_lista_enc();

	fgets (buffer, 100, fp);

	while(fgets(buffer,TAM_BUFFER,fp) != 0){

		controle = sscanf(buffer, "%100[^,],%d,%c,%100[^,],%d,%d\n", buffer_nome, &idade, &sexo, buffer_diagnostico, &prioridade, &chance);

		//printf("%s - %i - %c - %s - %d - %d\n", buffer_nome, idade, sexo, buffer_diagnostico, prioridade, chance);

    /* Se o arquivo estiver invalido */
    if (controle != 6) {
        fprintf(stderr, "Arquivo de entrada invalido\n");
        exit(EXIT_FAILURE);}

    paciente = cria_paciente(buffer_nome, idade, sexo, buffer_diagnostico, prioridade, chance);
    no = criar_no(paciente);
    add_cauda(lista,no);

        }

    fclose(fp);

	return lista;
}

paciente_t * cria_paciente(char *nome, int idade, char sexo, char *diagnostico, int prioridade, int chance){

	paciente_t *p;

	p = malloc(sizeof(paciente_t));

	if (p == NULL){

		perror("cria_pessoa (struct)");
		exit(EXIT_FAILURE);
	}

	p->nome = malloc(strlen(nome) + 1);

	if (p == NULL){
		perror("cria_pessoa (nome)");
		exit(EXIT_FAILURE);
	}

	p->diagnostico = malloc(strlen(diagnostico) + 1);

	if (p == NULL){
		perror("cria_pessoa (diagnostico)");
		exit(EXIT_FAILURE);
	}


	/* Copia os dados para a lista alocada */
	strncpy(p->nome, nome, strlen(nome) + 1);
	p->idade = idade;
	p->sexo = sexo;
	p->prioridade = prioridade;
	p->chance = chance;

	return p;
}

#include <stdio.h>
#include <stdlib.h>

#include "pacientes.h"
#include "arvore_bin.h"

int main()
{
    lista_enc_t *lista;
    fila_t *fila;
    paciente_t *paciente_atual;
    int x, tamanho;
    arvore_t *arvore_binaria; //ainda em teste

    arvore_binaria = NULL;

    lista = ler_arquivo("Pacientes.csv");

    fila = cria_fila_pacientes(lista);

    tamanho = obtem_tamanho(lista);

    for(x = 0; x <= tamanho-1; x++){
        paciente_atual = dequeue(fila);
        //printf("%s - %d \n", obter_nome(paciente_atual), obter_idade(paciente_atual));
        inserir(&arvore_binaria, paciente_atual);
    }

    libera_dados_list_enc(lista);

    libera_fila(fila);

    printf("Ponto de Teste");

    return 0;
}

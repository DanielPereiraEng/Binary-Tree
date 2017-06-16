#include <stdio.h>
#include <stdlib.h>

#include "pacientes.h"

int main()
{
    lista_enc_t *lista;
    fila_t *fila;
    paciente_t *paciente_atual;
    int x, tamanho;

    lista = ler_arquivo("Pacientes.csv");

    fila = cria_fila_pacientes(lista);

    while((fila)!=NULL){
        paciente_atual = dequeue(fila);
        printf("%s - %d \n", obter_nome(paciente_atual), obter_idade(paciente_atual));}

    printf("Ponto de Teste");

    return 0;
}

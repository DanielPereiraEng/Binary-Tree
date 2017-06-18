#include <stdio.h>
#include <stdlib.h>

#include "pacientes.h"
#include "arvore_bin.h"
#include "pilha.h"

int main()
{
    lista_enc_t *lista;
    fila_t *fila;
    paciente_t *paciente_atual;
    int x, tamanho, *nivel=0;
    arvore_t *arvore_binaria;
    pilha_t *main_stack = cria_pilha();

    arvore_binaria = NULL;

    lista = ler_arquivo("Pacientes.csv");

    fila = cria_fila_pacientes(lista);

    tamanho = obtem_tamanho(lista);

    paciente_atual = dequeue(fila);

    inicializar(&arvore_binaria, paciente_atual, main_stack);

    for(x = 2; x <= tamanho; x++){
        paciente_atual = dequeue(fila);
        //printf("%s - %d \n", obter_nome(paciente_atual), obter_idade(paciente_atual));
        inserir(&arvore_binaria, paciente_atual, main_stack, x);
    }

//    print_preorder(arvore_binaria);

    printf("%d\n", nivel);

    libera_dados_list_enc(lista);

    libera_fila(fila);

    printf("Ponto de Teste");

    return 0;
}

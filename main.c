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
    arvore_t *arvore_binaria;
    arvore_t *arvore_organizada;

    arvore_organizada = NULL;
    arvore_binaria = NULL;

    lista = ler_arquivo("Pacientes.csv");

    fila = cria_fila_pacientes(lista);

    tamanho = obtem_tamanho(lista);

    paciente_t *buffer[tamanho];

    for(x = 0; x <= tamanho-1; x++){
        paciente_atual = dequeue(fila);
        buffer[x] = paciente_atual;}

    x=0;

    new_tree(&arvore_organizada, buffer, tamanho-1, x);

    arvore_binaria = heapsort_loop(arvore_organizada, tamanho);

//    print_preorder(arvore_organizada);

//    print_preorder(arvore_organizada);


    libera_dados_list_enc(lista);

    libera_fila(fila);

    return 0;
}

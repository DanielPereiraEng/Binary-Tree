#include <stdio.h>
#include <stdlib.h>

#include "pacientes.h"
#include "arvore_bin.h"
#include "lista_enc.h"
#include "no.h"

int main()
{
    lista_enc_t *lista;
    no_t *no;
    paciente_t *paciente_atual;
    int x, tamanho;
    arvore_t *arvore_organizada;

    arvore_organizada = NULL;

    lista = ler_arquivo("Pacientes.csv");

    tamanho = obtem_tamanho(lista);

    paciente_t *buffer[tamanho-1];

    no = obtem_cabeca(lista);

    for(x = 0; x <= tamanho-1; x++){
        paciente_atual = obter_dado(no);
        buffer[x] = paciente_atual;
        no = obter_proximo(no);}

    x=0;

    new_tree(&arvore_organizada, buffer, tamanho-1, x);

    x=0;

    organizador(&arvore_organizada, tamanho, x);

    print_tree(arvore_organizada, tamanho, x);

//    libera_tree(arvore_organizada, tamanho, x);

    libera_dados_list_enc(lista);

    return 0;
}

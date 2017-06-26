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
    paciente_t *paciente;
    int x, tamanho, escolha=0;
    arvore_t *tree;

    tree = NULL;

    lista = ler_arquivo("Pacientes.csv");

    tamanho = obtem_tamanho(lista);

    paciente_t *buffer[tamanho-1];

    no = obtem_cabeca(lista);

    for(x = 0; x <= tamanho-1; x++){
        paciente = obter_dado(no);
        buffer[x] = paciente;
        no = obter_proximo(no);}

    new_tree(&tree, buffer, tamanho-1);

    heap_sort(&tree, tamanho);

    printf("Bem Vindo\nTrabalho Final - Fila de Hospital\nAluno: Daniel Pereira\n");

    while(escolha!=3){
    printf("\nO que deseja fazer?\n(1) Imprimir a lista\n(2) Inserir novo paciente\n(3)Finalizar programa\n");
    scanf("%d", &escolha);
    switch(escolha){
        case 1:
            print_tree(tree, tamanho-1);
            break;
        case 2:
            novo_paciente(&tree, tamanho);
            tamanho++;
            heap_sort(&tree, tamanho);
            break;
        case 3:
            break;}
    }

    libera_dados_list_enc(lista);

    return 0;
}

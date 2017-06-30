#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pacientes.h"
#include "arvore_bin.h"
#include "lista_enc.h"
#include "no.h"

int main()
{
    lista_enc_t *lista;
    no_t *no;
    paciente_t *paciente;
    int x, tamanho, escolha=0, loop;
    arvore_t *tree;

    clock_t temp1, temp2;
    double tempo;

    srand( (unsigned)time(NULL) );

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


    temp1 = clock();
    heap_sort(&tree, tamanho);
    temp2 = clock();

    printf("Bem Vindo\nTrabalho Final - Fila de Hospital\nAluno: Daniel Pereira\n");

    while(escolha!=4){
    printf("\nO que deseja fazer?\n(1) Imprimir a lista\n(2) Inserir novo paciente\n(3) Para ver o tempo que cem mil Heapsort levam para executar\n(4) Finalizar o programa\n");
    printf("\n\nSua escolha: \n");
    scanf("%d", &escolha);
    switch(escolha){
       case 1:
            temp1 = clock();
            print_tree(tree, tamanho-1);
            break;
        case 2:
            novo_paciente(&tree, tamanho);
            tamanho++;
            heap_sort(&tree, tamanho);
            break;
        case 3:
            system("@cls||clear");
            temp1 = clock();
            for(loop=0; loop<=100000 ;loop++){
                heap_sort(&tree, tamanho);}
            temp2 = clock();
            tempo = (temp2-temp1)/CLOCKS_PER_SEC;
            printf("\nO tempo medio de cem mil loops de heapsorts eh de %.2f segundos\n\n", tempo);
            break;
        case 4:
            system("@cls||clear");
            break;}
    }

    while (tamanho>0){
        liberador(tree, tamanho-1);
        tamanho--;}

    libera_dados_list_enc(lista);

    return 0;
}

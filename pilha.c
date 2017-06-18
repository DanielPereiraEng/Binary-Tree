#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

struct pilhas {
    int topo;
    int data[TAMANHO_DADOS_PILHA];
};


//cria uma pilha para inteiros
pilha_t * cria_pilha (void)
{
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));

    pilha->topo = 0;

    return pilha;
}


//adiciona elemento
void push(int dado, pilha_t *pilha)
{
    int topo = pilha->topo;

    if (topo > TAMANHO_DADOS_PILHA) {
        fprintf(stderr, "Tamanho maximo da pilha atingido!\n");
        exit(EXIT_FAILURE);
    }

    pilha->data[topo] = dado;
    pilha->topo++;
}

//retira elemento do topo
void pop(pilha_t *pilha)
{
    int topo = pilha->topo;

    if (topo < 0 || topo > TAMANHO_DADOS_PILHA){
        fprintf(stderr, "Pilha corrompida!\n");
        exit(EXIT_FAILURE);
    }

    if (topo == 0) {
        fprintf(stderr, "pop() em pilha vazia!\n");
        return 0;
    }

    pilha->topo--;
//    return pilha->data[topo - 1];
}


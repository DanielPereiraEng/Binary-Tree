#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_bin.h"
#include "pacientes.h"
#include "pilha.h"

struct arvore {
    void *dados;
    struct arvore *pai, * right, * left;
};

void inserir(arvore_t* *tree , paciente_t *paciente_atual){

    arvore_t* temp = *tree;

    if(temp == NULL){
        temp = (arvore_t *)malloc(sizeof(arvore_t));
        temp->left =  NULL;
        temp->right = NULL;
        temp->dados = paciente_atual;
        *tree = temp;
    }else{
        if(paciente_atual < temp->dados){
            inserir(&temp->left,paciente_atual);
        }else{
            inserir(&temp->right,paciente_atual);
        }
    }}

void print_preorder(arvore_t *tree){

    if (tree == NULL)
    {
        return;
    }

    paciente_t *paciente;
    paciente = tree->dados;
    printf("%s\n", obter_nome(paciente));
    print_preorder(tree->left);
    print_preorder(tree->right);
}

void print_inorder(arvore_t *tree){

    if (tree == NULL)
    {
        return;
    }

    paciente_t *paciente;
    paciente = tree->dados;
    print_inorder(tree->left);
    printf("%s\n", obter_nome(paciente));
    print_inorder(tree->right);
}

void print_posorder(arvore_t *tree){

    if (tree == NULL)
    {
        return;
    }

    paciente_t *paciente;
    paciente = tree->dados;
    print_posorder(tree->left);
    print_posorder(tree->right);
    printf("%s\n", obter_nome(paciente));
}

//void deltree(arvore_t * tree)
//{
//    if (tree)
//    {
//        deltree(tree->left);
//        deltree(tree->right);
//        free(tree);
//    }
//}


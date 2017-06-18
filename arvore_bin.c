#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_bin.h"
#include "pacientes.h"
#include "pilha.h"

struct arvore {
    void *dados;
    struct arvore *pai, * right, * left;
    int indice;
};


void inicializar(arvore_t **tree ,paciente_t *paciente_atual, pilha_t *main_stack){

    arvore_t *temp = NULL;

    if(!(*tree)){
        temp = (arvore_t *)malloc(sizeof(arvore_t));
        temp->left =  NULL;
        temp->right = NULL;
        temp->pai = NULL;
        temp->dados = paciente_atual;
        temp->indice = 1;
        push(1, main_stack);
        *tree = temp;
        return;}

}


void inserir(arvore_t **tree , paciente_t *paciente_atual, pilha_t *main_stack, int indice){

    paciente_t* pessoal_alvo;
    arvore_t *temp;
    arvore_t *remix;

    temp = *tree;
    pessoal_alvo = temp->dados;

    temp = NULL;

    if(!(*tree)){
        temp = (arvore_t *)malloc(sizeof(arvore_t));
        temp->left =  NULL;
        temp->right = NULL;
        temp->dados = paciente_atual;
        temp->pai = pessoal_alvo;
        temp->indice = indice;
        *tree = temp;
        pop(main_stack);
        return;}

    if(temp->left == NULL){
        push(indice, main_stack);
        inserir(&(*tree)->left, paciente_atual, main_stack, indice);}

    if(temp->right == NULL){
        push(indice, main_stack);
        inserir(&(*tree)->right, paciente_atual, main_stack, indice);}

//    temp = *tree;

//    pessoal_alvo = temp->dados;

    //printf("%s\n", obter_nome(pessoal_alvo));

//    if(obter_prioridade(paciente_atual) < obter_prioridade(pessoal_alvo)){
//        inserir(&(*tree)->left, paciente_atual);}

//    else if(obter_prioridade(paciente_atual)  >= obter_prioridade(pessoal_alvo)){
//        inserir(&(*tree)->right, paciente_atual);}
}

void print_preorder(arvore_t *tree){

    paciente_t *paciente;

    paciente = tree->dados;

    if (tree){
        printf("%s\n", obter_nome(paciente));
        print_preorder(tree->left);
        print_preorder(tree->right);}
}

//void print_inorder(arvore_t * tree)
//{
//    if (tree)
//    {
//        print_inorder(tree->left);
//        printf("%d\n",tree->dados);
//        print_inorder(tree->right);
//    }
//}

//void print_postorder(arvore_t * tree)
//{
//    if (tree)
//    {
//        print_postorder(tree->left);
//        print_postorder(tree->right);
//        printf("%d\n",tree->dados);
//    }
//}

//void deltree(arvore_t * tree)
//{
//    if (tree)
//    {
//        deltree(tree->left);
//        deltree(tree->right);
//        free(tree);
//    }
//}


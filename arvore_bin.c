#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_bin.h"
#include "pacientes.h"

struct arvore {
    void* dados;
    struct arvore * right, * left;
};


void inserir(arvore_t **tree ,paciente_t *paciente_atual){

    printf("IIIII\n");

    arvore_t *temp = NULL;
    if(!(*tree)){
        temp = (arvore_t *)malloc(sizeof(arvore_t));
        temp->left =  NULL;
        temp->right = NULL;
        temp->dados = paciente_atual;
        *tree = temp;
        return;}

    printf("OOOOO\n");

//    paciente_t* pessoal_alvo;

//    pessoal_alvo = temp->dados;

//    if(obter_prioridade(paciente_atual) < obter_prioridade(pessoal_alvo)){
//        inserir(&(*tree)->left, paciente_atual);}

//    else if(obter_prioridade(paciente_atual)  > obter_prioridade(pessoal_alvo)){
//        inserir(&(*tree)->right, paciente_atual);}
}

void print_preorder(arvore_t *tree){

    paciente_t *paciente;

    paciente = tree->dados;

    if (tree){
        printf("%s\n",obter_nome(paciente));
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


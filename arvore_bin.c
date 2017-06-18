#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_bin.h"
#include "pacientes.h"

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

arvore_t *heapsort_loop(arvore_t * tree, int tamanho){
    int controle;
    arvore_t *heap1, *heap2;

    for (controle = 0; heap1 != heap2, controle < tamanho; ++controle){
//        if ((controle % 2) == 0)
//            heap1 = heapsort(tree);
//        else
//            heap2 = heapsort(tree);

    }

    return tree;
}

arvore_t *heapsort(arvore_t *tree){
    arvore_t *temporario;

    if (tree->left && tree->right)
   {
      /* puts lesser value on top of node */
      if ((tree->left->dados < tree->right->dados) && (tree->left->dados < tree->dados))
      {
         temporario->dados = tree->dados; tree->dados = tree->left->dados; tree->left->dados = temporario->dados;
      }
      else if ((tree->left->dados > tree->right->dados) && (tree->right->dados < tree->dados))
      {
         temporario->dados = tree->dados; tree->dados = tree->right->dados; tree->right->dados = temporario->dados;
      }
      if (tree->left) heapsort (tree->left);
      if (tree->right) heapsort (tree->right);
   }
   return tree;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_bin.h"
#include "pacientes.h"

struct arvore {
    void *dados;
    struct arvore *pai, * right, * left;
};

void inserir(arvore_t* *tree , paciente_t *paciente_atual, int key){

    arvore_t* temp = *tree;
    int checa = key;

    if(temp == NULL){
        //printf("inseriu e key:%d\n",key);
        temp = (arvore_t *)malloc(sizeof(arvore_t));
        temp->left =  NULL;
        temp->right = NULL;
        temp->dados = paciente_atual;
        *tree = temp;
    }else{
        if(checa%2 == 0){ //paciente_atual < temp->dados
            //printf("0\n");
            inserir(&temp->left,paciente_atual, key);
        }else{
            //printf("1\n");
            inserir(&temp->right,paciente_atual, key);
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

    for (controle = 0; heap1 != heap2 || controle < tamanho-1; ++controle){
        if ((controle % 2) == 0)
            heap1 = heapsort(tree);
        else
            heap2 = heapsort(tree);}

    return tree;
}

arvore_t *heapsort(arvore_t *tree){
    arvore_t *temporario;
    paciente_t *dado0, *dado1, *dado2;

    printf("PONTO 1\n");
    dado0 = tree->dados;
    printf("PONTO 2\n");
    dado1 = tree->left->dados;
    printf("PONTO 3\n");
    dado2 = tree->right->dados;
    printf("PONTO 4\n");

    if (tree->left && tree->right)
   {
       printf("PONTO 5\n");
      /* puts lesser value on top of node */
      if ((obter_prioridade(dado1) < obter_prioridade(dado2)) && (obter_prioridade(dado1) > obter_prioridade(dado0)))
      {
          printf("PONTO 6\n");
         temporario->dados = tree->dados;
         tree->dados = tree->left->dados;
         tree->left->dados = temporario->dados;
      }
      else if ((obter_prioridade(dado1) > obter_prioridade(dado2)) && (obter_prioridade(dado2) < obter_prioridade(dado0)))
      {
          printf("PONTO 7\n");
            temporario->dados = tree->dados;
         tree->dados = tree->right->dados;
         tree->right->dados = temporario->dados;
      }
      if (tree->left)
        printf("PONTO 8\n");
        heapsort(tree->left);
      if (tree->right)
      printf("PONTO 9\n");
        heapsort(tree->right);
   }
   return tree;

}

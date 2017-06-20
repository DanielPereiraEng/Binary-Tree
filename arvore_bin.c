#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_bin.h"
#include "pacientes.h"

struct arvore {
    void *dados;
    struct arvore *right, * left;
    int numero;
};

void print_tree(arvore_t *tree, int tamanho, int indice){

    int ind=0;
    paciente_t *paciente;

    if(tree == NULL){
        return;}

    if(tree->numero == 0){
        paciente = tree->dados;
        printf("%s\n", obter_nome(paciente));
        ind++;}

    while(ind<=tamanho-1){
        ind=imprimir(tree->left, tamanho, ind);
        ind=imprimir(tree->right, tamanho, ind);}

    return;}

int imprimir(arvore_t *tree, int tamanho, int indice){

    //printf("PONTO 3\n");

    int ind=indice;
    paciente_t *paciente;

    printf("\n%d\n", ind);

    if(ind>tamanho)
        return tamanho+1;

    if(tree->numero == ind){
        paciente = tree->dados;
        printf("%s\n", obter_nome(paciente));
        ind++;
        return ind;}

    //printf("PONTO 4\n");

    if(tree->left==NULL && tree->right==NULL)
        return ind;

    ind=imprimir(tree->left, tamanho, ind);
    ind=imprimir(tree->right, tamanho, ind);

    return ind;
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

void new_tree(arvore_t **tree , paciente_t *paciente_atual[], int maximo, int indice){

    arvore_t *temp = *tree;
    arvore_t *temp2, *temp3;
    int t1, t2, u=0;
    int ind = indice;
    t1 = 2*(ind) + 1;
    t2 = 2*(ind) + 2;

    if(indice == 0){
        temp = (arvore_t *)malloc(sizeof(arvore_t));
        temp->numero = indice;
        temp->dados = paciente_atual[ind];

        if(t1>maximo){
            printf("saida 1\n");
            temp->left =  NULL;
            temp->right = NULL;
            *tree = temp;
            return;}

        temp2 = (arvore_t *)malloc(sizeof(arvore_t));
        temp2->left =  NULL;
        temp2->right = NULL;
        temp2->numero = (t1);
        temp2->dados = paciente_atual[t1];

        if(t2>maximo){
            printf("saida 2\n");
            temp->right = NULL;
            *tree = temp;
            return;}

        temp3 = (arvore_t *)malloc(sizeof(arvore_t));
        temp3->left =  NULL;
        temp3->right = NULL;
        temp3->numero = (t2);
        temp3->dados = paciente_atual[t2];

        temp->left = temp2;
        temp->right = temp3;

        *tree = temp;

        ind++;}

    while(ind<=maximo){
        ind = new_tree_loop(&(*tree)->left, paciente_atual, maximo, ind);
        ind = new_tree_loop(&(*tree)->right, paciente_atual, maximo, ind);}

    return;
}

int new_tree_loop(arvore_t **tree , paciente_t *paciente_atual[], int maximo, int indice){

    paciente_t *pessoa1, *pessoa2;
    arvore_t *temp = *tree;
    arvore_t *temp2, *temp3;
    int t1, t2, u;
    int ind = indice;
    t1 = 2*(ind) + 1;
    t2 = 2*(ind) + 2;

    pessoa1 = paciente_atual[t1];
    pessoa2 = paciente_atual[t2];

    if (ind>maximo)
        return ind;

    if(temp->numero==ind){

        if(t1>maximo)
            return maximo+1;

        temp2 = (arvore_t *)malloc(sizeof(arvore_t));
        temp2->left =  NULL;
        temp2->right = NULL;
        temp2->numero = t1;
        temp2->dados = pessoa1;

        if(t2>maximo)
            return maximo+1;

        temp3 = (arvore_t *)malloc(sizeof(arvore_t));
        temp3->left =  NULL;
        temp3->right = NULL;
        temp3->numero = t2;
        temp2->dados = pessoa2;

        temp->left = temp2;
        temp->right = temp3;

        *tree = temp;

        ind++;
        return ind;}

    ind = new_tree_loop(&(*tree)->left, paciente_atual, maximo, ind);
    ind = new_tree_loop(&(*tree)->right, paciente_atual, maximo, ind);

    return ind;
    }

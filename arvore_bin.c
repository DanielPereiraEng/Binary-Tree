#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_bin.h"
#include "pacientes.h"

struct arvore {
    void *dados;
    struct arvore *right, * left;
    int numero, ordem;
};

void print_tree(arvore_t *tree, int tamanho, int indice){

    int ind=0;
    paciente_t *paciente;

    if(tree == NULL){
        return;}

    if(tree->ordem == 0){
        paciente = tree->dados;
        printf("%s\n", obter_nome(paciente));
        ind++;}

    while(ind<=tamanho-1){
        ind=imprimir(tree->left, tamanho, ind);
        ind=imprimir(tree->right, tamanho, ind);}

    return;}

int imprimir(arvore_t *tree, int tamanho, int indice){

    int ind=indice;
    paciente_t *paciente;

    if(ind>tamanho)
        return tamanho+1;

    if(tree->ordem == ind){
        paciente = tree->dados;
        printf("%s\n", obter_nome(paciente));
        ind++;
        return ind;}

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

void new_tree(arvore_t **tree , paciente_t *paciente_atual[], int maximo, int indice){

    arvore_t *temp = *tree;
    arvore_t *temp2, *temp3;
    int t1, t2;
    int ind = indice;
    t1 = 2*(ind) + 1;
    t2 = 2*(ind) + 2;

    if(indice == 0){
        temp = (arvore_t *)malloc(sizeof(arvore_t));
        temp->numero = indice;
        temp->ordem = indice;
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
        temp2->ordem = (t1);
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
        temp3->ordem = (t2);
        temp3->dados = paciente_atual[t2];

        temp->left = temp2;
        temp->right = temp3;

        *tree = temp;
        ind++;}

    while(ind<=maximo){
        ind = new_tree_loop(&(*tree)->left, paciente_atual, maximo, ind);
        ind = new_tree_loop(&(*tree)->right, paciente_atual, maximo, ind);}


    free(temp);
    free(temp2);
    free(temp3);

    return;
}

int new_tree_loop(arvore_t **tree , paciente_t *paciente_atual[], int maximo, int indice){

    arvore_t *temp = *tree;
    arvore_t *temp2, *temp3;
    int t1, t2;
    int ind = indice;
    t1 = 2*(ind) + 1;
    t2 = 2*(ind) + 2;

    if (ind>maximo)
        return ind;

    if(temp->numero==ind){

        if(t1>maximo)
            return maximo+1;

        temp2 = (arvore_t *)malloc(sizeof(arvore_t));
        temp2->left =  NULL;
        temp2->right = NULL;
        temp2->numero = t1;
        temp2->ordem = t1;
        temp2->dados = paciente_atual[t1];

        if(t2>maximo)
            return maximo+1;

        temp3 = (arvore_t *)malloc(sizeof(arvore_t));
        temp3->left =  NULL;
        temp3->right = NULL;
        temp3->numero = t2;
        temp3->ordem = t2;
        temp3->dados = paciente_atual[t2];

        temp->left = temp2;
        temp->right = temp3;

        *tree = temp;

        ind++;
        return ind;}

    ind = new_tree_loop(&(*tree)->left, paciente_atual, maximo, ind);
    ind = new_tree_loop(&(*tree)->right, paciente_atual, maximo, ind);

    return ind;}

void *organizador(arvore_t **tree, int maximo, int indice){

    int mudar=0, teste;
    int ind=indice;
    arvore_t *temp = *tree;

    teste = sqrt(maximo);

    while(teste>0){
        while(ind<maximo){
            mudar=organizador_loop(temp, mudar, ind);
            if(mudar==1){
                mudar=0;
                ind++;}}
        teste--;
        ind=0;}

    *tree = temp;}

int organizador_loop(arvore_t *tree, int mudar, int indice){

    int ind, mud, calamidade;
    ind = indice;
    mud = mudar;
    calamidade = 0;

    if(mud==1){
        return 1;}

    if(tree->left == NULL){
        calamidade++;}

    if(tree->right == NULL){
        calamidade++;}

    if(calamidade==2){
        if (tree->numero==ind){
            return 1;}
        return 0;}

    paciente_t *d_center, *d_left, *d_right;
    d_center = tree->dados;
    d_left = tree->left->dados;
    d_right = tree->right->dados;


    if(tree->numero == ind){

        if(obter_prioridade(d_left) < obter_prioridade(d_right) && obter_prioridade(d_right) > obter_prioridade(d_center)){
            trocar(tree->right, tree);}

        else if(obter_prioridade(d_left) > obter_prioridade(d_right) && obter_prioridade(d_left) > obter_prioridade(d_center)){
            trocar(tree->left, tree);}

        else if(obter_prioridade(d_left) == obter_prioridade(d_right) && obter_prioridade(d_left) > obter_prioridade(d_center)){
            trocar(tree->left, tree);}

        else
            return 1;}

    mud=organizador_loop(tree->left, mud, ind);

    if(mud==1){
        return 1;}

    mud=organizador_loop(tree->right, mud, ind);

    if(mud==1){
        return 1;}

    return 0;}

void trocar(arvore_t *maior, arvore_t *menor){            //poe tudo do 1 no 2
    arvore_t *temp;
    temp = (arvore_t *)malloc(sizeof(arvore_t));

    temp->dados = menor->dados;
    temp->numero = menor->numero;

    menor->dados = maior->dados;
    menor->numero = maior->numero;

    maior->dados = temp->dados;
    maior->numero = temp->numero;

    free(temp);
}

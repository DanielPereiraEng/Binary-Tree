#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "arvore_bin.h"
#include "pacientes.h"

#define TAM_BUFFER 100

//#define DEBUG

struct arvore {
    void *dados;
    struct arvore *left, *right;
    int numero, ordem;
};

void new_tree(arvore_t **tree , paciente_t *pacientes[], int maximo){

    arvore_t *temp = (arvore_t *)malloc(sizeof(arvore_t));
    int t1, t2;
    int ind = 0;

    t1 = 2*(ind) + 1;
    t2 = 2*(ind) + 2;

    temp->dados = pacientes[ind];
    temp->numero = temp->ordem = ind;
    temp->left = temp->right = NULL;

    #ifdef DEBUG
    paciente_t *tu = temp->dados;
    printf("Adicionada a arvore paciente %d - %s\n", ind+1, obter_nome(tu));
    #endif // DEBUG

    *tree = temp;

    ramo_left(&(*tree)->left, pacientes, t1, maximo);
    ramo_right(&(*tree)->right, pacientes, t2, maximo);
    
    free(temp);

    return;}

void ramo_left(arvore_t **tree, paciente_t *pacientes[], int indice, int maximo){

    if(indice > maximo)
        return;

    arvore_t *temp = (arvore_t *)malloc(sizeof(arvore_t));
    int t1, t2;

    t1 = 2*(indice) + 1;
    t2 = 2*(indice) + 2;

    temp->dados = pacientes[indice];
    temp->numero = temp->ordem = indice;
    temp->left = temp->right = NULL;

    #ifdef DEBUG
    paciente_t *tu = temp->dados;
    printf("Adicionada a arvore paciente %d - %s\n", indice+1, obter_nome(tu));
    #endif // DEBUG

    *tree = temp;

    ramo_left(&(*tree)->left, pacientes, t1, maximo);

    ramo_right(&(*tree)->right, pacientes, t2, maximo);

    return;}

void ramo_right(arvore_t **tree, paciente_t *pacientes[], int indice, int maximo){

    if(indice > maximo)
        return;

    arvore_t *temp = (arvore_t *)malloc(sizeof(arvore_t));
    int t1, t2;

    t1 = 2*(indice) + 1;
    t2 = 2*(indice) + 2;

    temp->dados = pacientes[indice];
    temp->numero = temp->ordem = indice;
    temp->left = temp->right = NULL;

    #ifdef DEBUG
    paciente_t *tu = temp->dados;
    printf("Adicionada a arvore paciente %d - %s\n", indice+1, obter_nome(tu));
    #endif // DEBUG

    *tree = temp;

    ramo_left(&(*tree)->left, pacientes, t1, maximo);

    ramo_right(&(*tree)->right, pacientes, t2, maximo);

    return;}

void print_tree(arvore_t *tree, int tamanho){

    int ind=0;
    paciente_t *pac;
    arvore_t *temp = (arvore_t *)malloc(sizeof(arvore_t));

    temp = tree;

    if(temp->ordem == 0){
        pac = temp->dados;
        printf("Paciente %d: %s\n", ind+1, obter_nome(pac));
        ind++;}

    while(ind<=tamanho){
        ind = print_left(temp->left, tamanho, ind);
        ind = print_right(temp->right, tamanho, ind);}

    return;}

int print_left(arvore_t *tree, int tamanho, int indice){

    if(indice > tamanho){
        return;}

    arvore_t *temp = tree;
    paciente_t *pac;
    int ind = indice;

    if (temp->dados == NULL){
        return ind;}

    if (ind == temp->ordem){
        pac = temp->dados;
        printf("Paciente %d: %s\n", ind+1, obter_nome(pac));
        ind++;
        return ind;}

    ind = print_left(temp->left, tamanho, ind);

    ind = print_right(temp->right, tamanho, ind);

    return ind;
}

int print_right(arvore_t *tree, int tamanho, int indice){

    if(indice > tamanho){
        return;}

    arvore_t *temp = tree;
    paciente_t *pac;
    int ind = indice;

    if (temp->dados == NULL){
        return ind;}

    if (ind == temp->ordem){
        pac = temp->dados;
        printf("Paciente %d: %s\n", ind+1, obter_nome(pac));
        ind++;
        return ind;}

    ind = print_left(temp->left, tamanho, ind);

    ind = print_right(temp->right, tamanho, ind);

    return ind;
}

void trocar(arvore_t *maior, arvore_t *menor){
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

void *heap_sort(arvore_t **tree, int maximo){

    int mudar=0, teste;
    int ind=0;
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

    *tree = temp;

    return;}

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

    if(tree->numero == ind && calamidade == 1){

        if(obter_prioridade(d_left) > obter_prioridade(d_center)){
            trocar(tree->left, tree);}

        else if(obter_prioridade(d_left) == obter_prioridade(d_center)){

            if(obter_chance(d_left) > obter_chance(d_center)){
            trocar(tree->left, tree);}

            else if(obter_chance(d_left) == obter_chance(d_center)){

                if(obter_idade(d_left) < obter_idade(d_center)){
                trocar(tree->left, tree);}

               }}

        else
            return 1;}

    if(tree->right == NULL){
        return 1;
    }

    d_right = tree->right->dados;

    if(tree->numero == ind){

        if(obter_prioridade(d_left) < obter_prioridade(d_right) && obter_prioridade(d_right) > obter_prioridade(d_center)){
            trocar(tree->right, tree);}

        else if(obter_prioridade(d_left) > obter_prioridade(d_right) && obter_prioridade(d_left) > obter_prioridade(d_center)){
            trocar(tree->left, tree);}

        else if(obter_prioridade(d_left) == obter_prioridade(d_right) && obter_prioridade(d_left) > obter_prioridade(d_center)){
            trocar(tree->left, tree);}

        else if(obter_prioridade(d_left) == obter_prioridade(d_right) && obter_prioridade(d_left) == obter_prioridade(d_center)){

            if(obter_chance(d_left) < obter_chance(d_right) && obter_chance(d_right) > obter_chance(d_center)){
                trocar(tree->right, tree);}

            else if(obter_chance(d_left) > obter_chance(d_right) && obter_chance(d_left) > obter_chance(d_center)){
            trocar(tree->left, tree);}

            else if(obter_chance(d_left) == obter_chance(d_right) && obter_chance(d_left) > obter_chance(d_center)){
            trocar(tree->left, tree);}

             else if(obter_chance(d_left) == obter_chance(d_right) && obter_chance(d_left) == obter_chance(d_center)){

                if(obter_idade(d_left) > obter_idade(d_right) && obter_idade(d_right) < obter_idade(d_center)){
                trocar(tree->right, tree);}

                else if(obter_idade(d_left) < obter_idade(d_right) && obter_idade(d_left) < obter_idade(d_center)){
                trocar(tree->left, tree);}

               }}

        else
            return 1;}

    mud=organizador_loop(tree->left, mud, ind);

    if(mud==1){
        return 1;}

    mud=organizador_loop(tree->right, mud, ind);

    if(mud==1){
        return 1;}

    return 0;}

void novo_paciente(arvore_t **tree, int tamanho){

    system("@cls||clear");

    paciente_t *paciente;
    char nome[TAM_BUFFER], diagnostico[TAM_BUFFER], sexo;
    int idade, prioridade, chance, ind;

    printf("\nInsira o nome: ");
    scanf("%s", &nome);

    fflush(stdin);

    printf("\n\nSexo(f para feminino e m para masculino): ");
    scanf("%c", &sexo);

    fflush(stdin);

    printf("\n\nIdade: ");
    scanf("%i", &idade);

    fflush(stdin);

    printf("\n\nInsira o diagnostivo: ");
    scanf("%s", &diagnostico);

    fflush(stdin);

    printf("\n\nPrioridade (1 a 10): ");
    scanf("%i", &prioridade);

    fflush(stdin);

    printf("\n\nChance de sobrevivencia (1 a 100): ");
    scanf("%i", &chance);

    fflush(stdin);

    system("@cls||clear");

    printf("\n\nNovo paciente introduzido\n\n");

    paciente = cria_paciente(nome, idade, sexo, diagnostico, prioridade, chance);

    #ifdef DEBUG
    printf("Nome: %s\nIdade: %d\nSexo %c\n", obter_nome(paciente), obter_idade(paciente), obter_sexo(paciente));
    printf("Diagnostico: %s\nPrioridade: %d\nChance de sobrevivencia: %d\n", obter_diagnostico(paciente), obter_prioridade(paciente), obter_chance(paciente));
    #endif // DEBUG


    novo_na_arvore(&(*tree)->left, paciente, tamanho);
    novo_na_arvore(&(*tree)->right, paciente, tamanho);

    return;}

void novo_na_arvore(arvore_t **tree, paciente_t *paciente, int tamanho){

    arvore_t *temp = *tree;
    paciente_t *pac;
    int left, right;

    if(temp==NULL){
        return;}

    left = 2*(temp->ordem) + 1;
    right = 2*(temp->ordem) + 2;

    if(left == tamanho){
        new_leaf(&(*tree)->left, paciente, tamanho);
        return;}

    if(right == tamanho){
        new_leaf(&(*tree)->right, paciente, tamanho);
        return;}

    novo_na_arvore(&(*tree)->left, paciente, tamanho);
    novo_na_arvore(&(*tree)->right, paciente, tamanho);

    return;}

void new_leaf(arvore_t **tree, paciente_t *paciente, int tamanho){

    arvore_t *leaf = (arvore_t *)malloc(sizeof(arvore_t));

    leaf->dados = paciente;
    leaf->numero = leaf->ordem = tamanho;
    leaf->left = leaf->right = NULL;

    *tree = leaf;

    return;}

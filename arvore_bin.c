#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore_bin.h"

struct arvore {
    void* dados;
    struct arvore * right, * left;
};
typedef struct arvore node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

//void print_preorder(node * tree)
//{
//    if (tree)
//    {
//        printf("%d\n",tree->data);
//        print_preorder(tree->left);
//        print_preorder(tree->right);
//    }

//}

//void print_inorder(node * tree)
//{
//    if (tree)
//    {
//        print_inorder(tree->left);
//        printf("%d\n",tree->data);
//        print_inorder(tree->right);
//    }
//}

//void print_postorder(node * tree)
//{
//    if (tree)
//    {
//        print_postorder(tree->left);
//        print_postorder(tree->right);
//        printf("%d\n",tree->data);
//    }
//}

//void deltree(node * tree)
//{
//    if (tree)
//    {
//        deltree(tree->left);
//        deltree(tree->right);
//        free(tree);
//    }
//}


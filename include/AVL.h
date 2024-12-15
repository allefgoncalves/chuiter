#ifndef AVL_H
#define AVL_H
#define MAX_LINHA 250 // Tamanho máximo de cada linha no arquivo

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct AVLNode {
    time_t key;
    struct tm *tm;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
    char *chuiter;
} AVLNode;

AVLNode *create_node_avl(time_t key, char *chuiter); //cria nó 
AVLNode *insert_avl(AVLNode  *root,time_t key, char *chuiter);  //insere nó
void inorder_avl(AVLNode *root, long long int a, long long int b, const char *name, int *Qtd);  //função para a impressao das mensagens em um intervalo A-B          
void free_avl(AVLNode *root);    //libera o espaço de memoria
 
#endif
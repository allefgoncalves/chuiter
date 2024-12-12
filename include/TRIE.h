#ifndef TRIE_H
#define TRIE_H
#define ASCII_SIZE 26

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AVL.h"

typedef struct TrieNode{
    bool end;
    struct TrieNode *children[ASCII_SIZE];
    AVLNode *root_avl;
}TrieNode;

TrieNode *create_node_trie();                       //cria um nó
void insert_trie(TrieNode *root, const char *name,int key, char *chuiter);  //inserir um nó 
TrieNode *search_trie(TrieNode *root, const char *name); //busca de usuario
void *messages_from_all_users(TrieNode *root, long long int a, long long int b, const char *name); //exibe as mensagens de todos os usuarios em um intervalo A-B
//void delete_key(TrieNode *root, const char *name);  //deleta nodo
//void free_trie(TrieNode *root);                     //libera o espaço de memoria


#endif
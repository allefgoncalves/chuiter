#include  "../include/TRIE.h"
#include  "../include/AVL.h"

TrieNode *create_node_trie(){  //criaçao do nó na arvore trie
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    if(node){
        node->end = false;
        for(int i = 0;i<ASCII_SIZE;i++){
            node->children[i] = NULL;
        }
        node->root_avl = NULL;
        return node;
    }
    return NULL;
} 

void insert_trie(TrieNode *root, const char *name,int key,char *chuiter){//inserção na arvore
    TrieNode *current = root;
    for(int i=0; name[i] != '\0';i++){
        int index = name[i] - 'a';
        if(!current->children[index]){
            current->children[index] = create_node_trie();
        }
        current = current->children[index];
    }
    // if(current->end == true){ //nova mensagem do usuario já existente
        current->root_avl = insert_avl(current->root_avl, key, chuiter);
    // }else{ //primeira inserção do usuario
        current->end = true;
//        current->root_avl = create_node_avl(key, chuiter);
  //  }
}

TrieNode *search_trie(TrieNode *root, const char *name) {
    TrieNode *current = root;
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%d_",(name[i] - 'a')); //teste de execução
        int index = name[i] - 'a';
        if (!current->children[index]) {
            return NULL; // Palavra não encontrada
        }
        current = current->children[index];
    }
    if(current != NULL && current->end)
        return current;
    return NULL;
}
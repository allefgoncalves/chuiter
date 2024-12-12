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
    current->root_avl = insert_avl(current->root_avl, key, chuiter);
    current->end = true;
}

TrieNode *search_trie(TrieNode *root, const char *name) { //busca de um nome expecifico
    TrieNode *current = root;
    for (int i = 0; name[i] != '\0'; i++) {
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

//varredura e exibição das mensagens, no intervalo A-B, de todos os usuarios cadastrados
void *messages_from_all_users(TrieNode *root, long long int a, long long int b, const char *name){
    TrieNode *current = root;

    char current_name[ASCII_SIZE] = ""; //criando array de char vazio 
    if(name){
        strcpy(current_name, name); //copiando a palavra
    }

    if(current->end){ //verifica se é um nodo final
        inorder_avl(current->root_avl, a, b, current_name);
    }

    int index = 0;  //buscando o fim do array
    while (current_name[index] !='\0'){
        index ++;
    }

    for (int i = 0; i < ASCII_SIZE; i++) { //chama novamente a função para cada filho existente
       if(current->children[i] != NULL){
            current_name[index] =  i + 'a';
            current_name[index + 1] = '\0'; //define uum novo tamanho para a verificação dos filhos        
            messages_from_all_users(current->children[i], a, b, current_name);
       }
    }
}

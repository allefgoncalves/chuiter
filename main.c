#include "include/TRIE.h"
#include "include/AVL.h"
#include <time.h>

/*
//função de busca que vai receber:
//TrieNode *root: primeiro nó "raiz"
//name: variavel da arvore trie que busca o usuario
//int A: variavel de inicio de intervalo
//int B: variavel de fim de intervalo
*/
void search_chuiter(TrieNode *root,const char *name, long long int a, long long int b){
    TrieNode *aux = search_trie(root,name);
    if(aux){
        inorder_avl(aux->root_avl, a, b);    
    }else{
        printf("usuario não encontrado");
    }
}


int main() {
    char name[25] = ""; // Para o primeiro elemento (char até espaço)
    long long int date; // Para o número inteiro
    char chuiter[MAX_LINHA]; //Para o restante da linha (char seguido pela frase)                                
    
    TrieNode *root = create_node_trie(); //criando o primeiro nodo da trie (vazio)
    FILE *arquivo;
    long long int a = 0; //data de inicio de intervalo
    long long int b = 999999999999999; //data de fim de intervalo
    int menu = 1; //criterio de parada do programa
    time_t now = time(NULL); //marca a hora atual
    int Qtd = 0; //contador de chutiters
    
    //variaveis de entrada do usuario
    char input[55];
    char start_date[10] = "";  
    char end_date[10] = "";
    char start_time[8] = "";
    char end_time[8] = "";


    arquivo = fopen("chuiter.txt", "r"); //abre o arquivo
        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(chuiter, MAX_LINHA, arquivo) != NULL) { //leitura do arquivo e inserção de dados
        if (sscanf(chuiter, "%s %ld %[^\n]", name, &date, chuiter) == 3) {
            insert_trie(root,name,date,chuiter);
        } else {
            fprintf(stderr, "Erro para ler a linha: %s\n", chuiter);
        }
    }
    /*
    while(menu == 1){ //loop de pesquisa
        scanf(input ,"%s %s %s %s %s", name, start_date, start_time, end_date, end_time);
        if(name == "*"){ // add função para busca com todos os usuarios

        }
        if(start_date == "*"){ // add caso de não ter data de inicio 

        }
        if(start_time == "*"){ // add caso de não ter hora de inicio 

        }
        if(end_date == "*"){ // add caso de não ter data final

        }
        if(end_time == "*"){ // add caso de não ter hora final

        }

        /*função recebe:
        root: ponteiro para o primeiro no da trie
        name: nome de um usuario
        a: inteiro de inicio de intervalo
        b: inteiro de fim de intervalo
        
        search_chuiter(root,"globo",0,9399994999959); //OBS: add ponteiro para Qtd

    }
    */ 

    search_chuiter(root,"globo",0,9399994999959);
    
    
   

    fclose(arquivo); //fecha o arquivo
    return 0;
}
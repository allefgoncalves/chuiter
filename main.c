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
        inorder_avl(aux->root_avl, a, b, name);    
    }else{
        printf("usuario não encontrado");
    }
}

int my_strptime(const char *s, const char *format, struct tm *tm) {
    // Exemplo básico para tratar apenas o formato "%Y-%m-%d %H:%M:%S"
    if (strcmp(format, "%Y-%m-%d %H:%M:%S") == 0) {
        sscanf(s, "%d-%d-%d %d:%d:%d",
               &tm->tm_year, &tm->tm_mon, &tm->tm_mday,
               &tm->tm_hour, &tm->tm_min, &tm->tm_sec);
        tm->tm_year -= 1900;  // Ajustar o ano
        tm->tm_mon -= 1;      // Ajustar o mês
        return 1;
    }
    return 0;  // Formato não suportado
}
 
int main() {
    char name[25] = ""; // Para o primeiro elemento (char até espaço)
    int date; // Para o número inteiro
    char chuiter[MAX_LINHA]; //Para o restante da linha (char seguido pela frase)                                
    
    TrieNode *root = create_node_trie(); //criando o primeiro nodo da trie (vazio)
    FILE *arquivo;
    long long int a = 0; //data de inicio de intervalo
    long long int b = 9999999999999999; //data de fim de intervalo
    int Qtd = 0; //contador de chutiters
    
    //variaveis de entrada do usuario
    char input[100];
    char start_date[15] = "";
    char end_date[15] = "";
    char start_time[15] = "";
    char end_time[15] = "";
    struct tm start_tm = {0}; // inicializa struct tm
    struct tm end_tm = {0};
    time_t start_timestamp, end_timestamp;


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
    fclose(arquivo); //fecha o arquivo
    
    while (1)// loop de consulta
    {
        printf("Digite a consulta (nome data_inicio hora_inicio data_fim hora_fim): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "sair") == 0)
        {
            break;
        }

        int scan_result = sscanf(input, "%s %s %s %s %s", name, start_date, start_time, end_date, end_time);

        if (scan_result < 5)
        {
            printf("Entrada invalida. Use o formato: nome data_inicio hora_inicio data_fim hora_fim\n");
            continue;
        }

        // converte data e hora de inicio
        if (strcmp(start_date, "*") != 0 && strcmp(start_time, "*") != 0)
        {
            char start_datetime[30];
            sprintf(start_datetime, "%s %s", start_date, start_time);
            my_strptime(start_datetime, "%Y-%m-%d %H:%M:%S", &start_tm);
            start_timestamp = mktime(&start_tm);
        }
        else
        {
            start_timestamp = 0; // valor minimo pro timestamp
        }

        // Converte data e hora de fim
        if (strcmp(end_date, "*") != 0 && strcmp(end_time, "*") != 0)
        {
            char end_datetime[30];
            sprintf(end_datetime, "%s %s", end_date, end_time);
            my_strptime(end_datetime, "%Y-%m-%d %H:%M:%S", &end_tm);
            end_timestamp = mktime(&end_tm);
        }
        else
        {
            end_timestamp = 9999999; // valor maximo pro timestamp
        }

        search_chuiter(root, name, start_timestamp, end_timestamp);
    }
 
    return 0;
}
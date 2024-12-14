#include  "../include/AVL.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))

int height(AVLNode *node) {
    return node ? node->height : 0;
}

AVLNode *create_node_avl(time_t key, char *chuiter) {
    AVLNode *node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    node->chuiter = strdup(chuiter);
    node->tm = NULL;
    if (!node->chuiter) {
        printf("Erro: falha ao alocar mensagem\n");
        free(node);
        return NULL;
    }
    return node;
}

AVLNode *rotate_right(AVLNode *root) {
    AVLNode *aux_1 = root->left;
    AVLNode *aux_2 = aux_1->right;
    aux_1->right = root;
    root->left = aux_2;
    root->height = max(height(root->left), height(root->right)) + 1;
    aux_1->height = max(height(aux_1->left), height(aux_1->right)) + 1;
    return aux_1;
}

AVLNode *rotate_left(AVLNode *root) {
    AVLNode* aux_1 = root->right;
    AVLNode* aux_2 = aux_1->left;
    aux_1->left = root;
    root->right = aux_2;
    root->height = max(height(root->left), height(root->right)) + 1;
    aux_1->height = max(height(aux_1->left), height(aux_1->right)) + 1;
    return aux_1;
}

int get_balance(AVLNode *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode *insert_avl(AVLNode *root, time_t key, char *chuiter) {
    if (!root) 
        return create_node_avl(key, chuiter);

    if (key < root->key)
        root->left = insert_avl(root->left, key, chuiter);
    else if (key > root->key)
        root->right = insert_avl(root->right, key, chuiter);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = get_balance(root);

    if (balance > 1 && key < root->left->key) //rotação LL
        return rotate_right(root);

    if (balance > 1 && key > root->left->key) { //rotação LR
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (balance < -1 && key > root->right->key) //rotação RR
        return rotate_left(root);

    if (balance < -1 && key < root->right->key) { //rotação RL
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

void inorder_avl(AVLNode *root, long long int a, long long int b,  const char *name) {
    if (root) {
        inorder_avl(root->left, a, b, name);
        root->tm = localtime(&root->key);
        char buffer[80];
        if(root->key >= a && root->key <= b)
        {
            strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", root->tm);
            printf("%s %s  %s \n", name, buffer, root->chuiter);
        }    
        inorder_avl(root->right, a, b, name);
    }
}

void free_avl(AVLNode *root) {
    if (root) {
        free_avl(root->left);
        free_avl(root->right);
        free(root->chuiter);
        free(root);
    }
}
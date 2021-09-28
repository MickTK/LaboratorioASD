//
// Created by Michele Melis on 05/05/2020.
//

#include "functions.h"

/* -------------------------------
 Funzioni gia' implementate (NON MODIFICARE):
 ------------------------------- */
Birra acquisisci_birra()
{
    Birra b;
    getchar();

    printf("nome: ");
    scanf("%[^\n]s", b.nome);
    getchar();

    printf("gradi: ");
    scanf("%f", &b.gradi);

    printf("bottiglie: ");
    scanf("%d", &b.bottiglie);

    return b;
}
void stampa_birra(Birra b)
{
    printf("--------------------- \n");
    printf("nome:  %s \n", b.nome);
    printf("gradi: %.1f \n", b.gradi);
    printf("bottiglie: %d \n", b.bottiglie);
    printf("--------------------- \n");
}
Nodo* crea_nodo(Birra b)
{
    Nodo* new_node = (Nodo*)malloc(sizeof(Nodo));
    if(new_node != NULL)
    {
        new_node->key = b;
        new_node->parent = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}
Nodo* carica_test()
{
    Nodo *root = NULL;
    int i;
    Birra elenco[NUM_TEST] = {{"Ichnusa", 4.7, 3}, {"Founders", 5.7, 15}, {"Peroni", 4.7, 2},
                              {"San Miguel", 3.2, 4}, {"Miller", 4.7, 7}, {"Guinnes", 4.2, 1},
                              {"Best Brau", 4.7, 12}, {"Barley", 5.0, 7}, {"Chouffe", 8.0, 12},
                              {"Franziskaner", 5, 10}, {"Heineken", 5.0, 7}, {"Kwak", 8.0, 14},
                              {"Paulaner", 5.5, 10}, {"Rubiu", 4.5, 10}, {"Tuborg", 5.0, 3}};


    for(i = 0; i < NUM_TEST; i++)
    {
        Nodo *new_birra = crea_nodo(elenco[i]);
        root = insert_nodo(root, new_birra);
    }

    return root;
}

/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node){
    Nodo *y = NULL;
    Nodo *x = root;

    while (x != NULL){           // L’algoritmo cerca un cammino discendente dalla radice
        y = x;                  // fino ad una foglia; x segue il cammino, y punta al padre di x
        if (strcmp(new_node->key.nome, x->key.nome) < 0)
            x = x->left;
        else
            x = x->right;
    }
                                // usciti da questo ciclo y è il puntatore al padre del nuovo nodo
    new_node->parent = y;

    if (y == NULL)
        root = new_node;
    else if (strcmp(new_node->key.nome, y->key.nome) < 0)
        y->left = new_node;
    else
        y->right = new_node;

    return root;
}
void inorder(Nodo* root){
    if(root == NULL)
        return;

    inorder(root->left);
    stampa_birra(root->key);     // stampa contenuto di r
    inorder(root->right);
}
void preorder(Nodo* root){
    if(root == NULL)
        return;

    stampa_birra(root->key);       // stampa contenuto di r
    preorder(root->left);
    preorder(root->right);
}
void postorder(Nodo* root){
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    stampa_birra(root->key);         // stampa contenuto di r
}
int profondita(Nodo* root){
    int sx, dx;

    if(root == NULL)
        return 0;
    sx = profondita(root->left);
    dx = profondita(root->right);

    return 1 + max(sx, dx);
}
int max(int v1, int v2){
    if(v1 > v2)
        return v1;
    else
        return v2;
}
Nodo* ricerca(Nodo* root, char* nome_birra){
    while(root != NULL)
        if(strcmp(nome_birra, root->key.nome) == 0)
            return root;
        else if(strcmp(nome_birra, root->key.nome) < 0)
            root = root->left;
        else
            root = root->right;

    return NULL;
}
Nodo* abr_min(Nodo* root){
    Nodo *nodo_ = root ;

    while(nodo_->left != NULL)
        nodo_ = nodo_->left;
    return nodo_;
}
Nodo* abr_max(Nodo* root){
    Nodo *nodo_ = root ;

    while(nodo_->right != NULL)
        nodo_ = nodo_->right;
    return nodo_;
}
Nodo* abr_pred(Nodo* x){
    Nodo *y = NULL;

    if(x->left != NULL)
    return abr_max(x->left);

    y = x->parent;
    while(y != NULL && x == y->left)
        x = y;

    y = y->parent;

    return y;
}
Nodo* abr_succ(Nodo* x){
    Nodo *y = NULL;

    if(x->right != NULL)
        return abr_min(x->right);

    y = x->parent;
    while(y != NULL && x == y->right)
        x = y;

    y = y->parent;
    return y;

}
Nodo* delete_node(Nodo* root, Nodo* nodo){
    Nodo *y = NULL;
    Nodo *x = NULL;

    if(nodo->left == NULL || nodo->right == NULL)
        y = nodo;
    else
        y = abr_succ(nodo);

    if(y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if(x != NULL)
        x->parent = y->parent;
    if(y->parent == NULL)
        root = x;
    else if(y->left == y)
        y->parent->left = x;
    else
        y->parent->right = x;

    if(y != nodo)
        nodo->key = y->key;

    free(y);
    return root;
}
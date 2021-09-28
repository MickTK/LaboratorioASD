#include "functions.h"

int main(){
    Nodo *root = NULL; // Radice dell'ABR

    //variabili ausiliarie
    int scelta;
    Birra tmp_birra;
    Nodo* tmp_nodo;
    int prof;
    char tmp_nome[DIM_NOME];

    do{
        printf("\nMENU:\n");
        printf("1) inserisci nuova birra \n");
        printf("2) visita INORDER \n");
        printf("3) visita PREORDER \n");
        printf("4) visita POSTORDER \n");
        printf("5) calcolo profondita \n");
        printf("6) ricerca di una birra \n");
        printf("7) ricerca del minimo \n");
        printf("8) ricerca del massimo \n");
        printf("9) ricerca del precedente di una birra \n");
        printf("10) ricerca del successore di una birra \n");
        printf("11) cancellazione di una birra \n");
        printf("12) carica birre di test (in un ABR vuoto)\n");
        printf("13) esci \n");

        printf("scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                tmp_birra = acquisisci_birra();
                tmp_nodo = crea_nodo(tmp_birra);
                root = insert_nodo(root, tmp_nodo);
                break;

            case 2:
                inorder(root);
                break;

            case 3:
                preorder(root);
                break;

            case 4:
                postorder(root);
                break;

            case 5:
                prof = profondita(root);
                printf("\nProfondita: %d\n", prof);
                break;

            case 6:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                getchar();
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                    printf("\nTrovata birra %s\n", tmp_nodo->key.nome);
                else
                    printf("\nBirra %s non trovata\n", tmp_nome);
                break;

            case 7:
                tmp_nodo = abr_min(root);
                printf("Il minimo e': %s\n", tmp_nodo->key.nome);
                break;

            case 8:
                tmp_nodo = abr_max(root);
                printf("Il minimo e': %s\n", tmp_nodo->key.nome);
                break;

            case 9:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                getchar();
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                {
                    tmp_nodo = abr_pred(tmp_nodo);
                    if(tmp_nodo != NULL)
                        printf("\nIl precedente e': %s\n", tmp_nodo->key.nome);
                    else
                        printf("\nNon esiste un precedente\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;

            case 10:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                getchar();
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                {
                    tmp_nodo = abr_succ(tmp_nodo);
                    if(tmp_nodo != NULL)
                        printf("\nIl successore e': %s\n", tmp_nodo->key.nome);
                    else
                        printf("\nNon esiste un successore\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;

            case 11:
                printf("\nBirra da eliminare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                getchar();
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL){
                    root = delete_node(root, tmp_nodo);
                    printf("\nNodo eliminato\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;


            case 12:
                root = carica_test();
                break;

            case 13:
                printf("\nCiao!\n");
                break;

            default:
                printf("\nScelta non valida\n");

        }
    }while(scelta != 13);

    return 0;
}
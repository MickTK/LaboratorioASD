#include "functions.h"

void carica_auto_test(Nodo* parcheggio[]){
    Auto a0 = {"PI555TA", 12, 15};
    Auto a1 = {"CA220TO", 7, 59};
    Auto a2 = {"EG000AL", 19, 45};
    Auto a3 = {"GO000LE", 15, 20};
    Auto a4 = {"BA220TO", 10, 35};
    Auto a5 = {"AP111LE", 15, 20};
    Auto a6 = {"MI123FT", 18, 40};
    Auto a7 = {"NO985LE", 20, 30};
    Auto a8 = {"GI124CH", 11, 20};
    Auto a9 = {"LO199RE", 9, 30};
    Auto a10 = {"ZA156KF", 7, 10};

    inserisci_auto(parcheggio, a0);
    inserisci_auto(parcheggio, a1);
    inserisci_auto(parcheggio, a2);
    inserisci_auto(parcheggio, a3);
    inserisci_auto(parcheggio, a4);
    inserisci_auto(parcheggio, a5);
    inserisci_auto(parcheggio, a6);
    inserisci_auto(parcheggio, a7);
    inserisci_auto(parcheggio, a8);
    inserisci_auto(parcheggio, a9);
    inserisci_auto(parcheggio, a10);
}
int hash_function(char targa[]){
    int id_char = targa[0] - 65;     // Valore lettera
    int piano = 0;
    float i = (float) 26 / NUM_PIANI;
    float j = i;

    while(j < (float) id_char){
        j += i;
        piano++;
    }

    return piano;               // Index
}
Auto acquisisci_auto(){
    Auto nuova_auto;
    float orario;

    printf("\nTarga auto:\n");
    scanf("%[^\n]s", nuova_auto.targa);
    getchar();
    printf("\nOrario:\n");
    scanf("%g", &orario);

    nuova_auto.ora = (int) orario;
    nuova_auto.min = (int) ((orario - (float) nuova_auto.ora) * 100);

    return nuova_auto;
}
void inserisci_auto(Nodo* parcheggio[], Auto a){
    int piano_index = hash_function(a.targa);
    Nodo *appn = parcheggio[piano_index];

    if(appn == NULL){
        parcheggio[piano_index] = (Nodo *) malloc(sizeof(Nodo));
        parcheggio[piano_index]->info = a;
        parcheggio[piano_index]->link = NULL;
    }
    else{
        while(appn->link != NULL){     // Ricerca nodo nullo
            appn = appn->link;         // Nodo precedente il nodo nullo
        }
        appn->link = (Nodo *) malloc(sizeof(Nodo)); // Nuovo nodo
        appn->link->info = a;
        appn->link->link = NULL;
    }
}
void stampa_parcheggio(Nodo* parcheggio[]){
    int i = 0;

    for(i = 0; i < NUM_PIANI; i++){
        stampa_piano(parcheggio, i);
    }
}
void stampa_piano(Nodo* parcheggio[], int piano){
    Nodo *appn = parcheggio[piano];

    printf("\nFloor #%d : ", piano);
    if(appn != NULL){                          // Se esiste almeno una macchina nel piano
        printf("%s ", appn->info.targa);       // Stampa la prima macchina nel piano
        appn = appn->link;                     // Puntatore a macchina successiva
        while(appn != NULL){                   // Finché esiste una macchina nel piano
            printf("- %s ", appn->info.targa); // Stampa la targa
            appn = appn->link;                 // Puntatore a macchina successiva
        }
    }
}
Nodo* ricerca_auto(Nodo* parcheggio[], char targa[]){
    int i = 0;
    Nodo *appn = NULL;

    for(i = 0; i < NUM_PIANI; i++){
        appn = parcheggio[i];               // Incremento piano
        while(appn != NULL){
            if(strcmp(appn->info.targa, targa) == 0){
                return appn;
            }
            appn = appn->link;
        }
    }

    return NULL;
}
void elimina_auto(Nodo* parcheggio[], char targa[]){
    Nodo *appn = ricerca_auto(parcheggio, targa);  // O - X
    int piano = hash_function(appn->info.targa);
    Nodo *appn_prev = parcheggio[piano];           // X - O

    if(appn == parcheggio[piano])
        parcheggio[piano] = parcheggio[piano]->link;    // In caso di prima macchina del parcheggio
    else{
        while(appn_prev->link != appn){
            appn_prev = appn_prev->link;
        }
        if(appn_prev->link == appn)
            appn_prev->link = appn->link;
    }
} // scritta
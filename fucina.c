#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "lib.h"
extern personaggio protagonista;
extern struct oggetto *attuale;
extern struct oggetto *nuovo;
extern struct oggetto *start;
void fucina(){
    printf("Questa e' la fucina, Puoi creare una tua arma al costo di 20 oro+ 2 oro per ogni punto caratteristica dell'arma\n");
    printf("Cosa vuoi forgiare?\n[1]Forgiare [2]Tornare indietro\n");
    while(0==0){
        int scelta;
        scanf("%d",&scelta);
        switch(scelta){
        case 1: {
            nuovo=(struct oggetto*)malloc(sizeof(struct oggetto));
            break;
            }
        case 2:{
            Astrub();
        }
        default: printf("Ripeti la scelta");
        }
        if (scelta==1) break;
    };
    while(0==0){//while per evitare il goto e nel caso in cui crea un arma che non si puo permettere
        char nomearma[30];
        printf("Inserisci il nome\n");
        scanf("%s",nomearma);
        strcpy(nuovo->nome,nomearma);
        printf("Inserisci le statistiche con cui vuoi creare l'arma\n");
        printf("Fo\n");
        scanf("%d",&nuovo->bforza);
        printf("Agi\n");
        scanf("%d",&nuovo->bagilita);
        printf("Int\n");
        scanf("%d",&nuovo->bintelligenza);
        printf("Vi\n");
        scanf("%d",&nuovo->bvita);
        nuovo->tipo=0;
        nuovo->next=NULL;//nuovo e' l'ultimo della lista
        nuovo->costo=20+(nuovo->bforza*2+nuovo->bagilita*2+nuovo->bintelligenza*2+nuovo->bvita/5);// formula per determinare il costo del'arma
        if(protagonista.soldi<nuovo->costo){
            printf("\nNon hai abbastanza soldi, la prossima volta crea un arma meno potente!\n");
            enter();
            return;
            }
        else break;
    }
    nuovo->acquisto=true;//se e' andato tutto bene e' come se avesse comprato l'arma tuttavia e' disponibile  solo per la corrente sessioen di gioco altrimenti sarebbe overpowered
    if(start==NULL){
        attuale=(struct oggetto*)malloc(sizeof(struct oggetto));
        nuovo->id=0;//il primo hai id 0
        start=(struct oggetto*)malloc(sizeof(struct oggetto));
        start=nuovo;//se e' il rpimo allora start =nuovo
        attuale=start;
    }
    else{
        nuovo->id=attuale->id+1;//altimenti gli id sono uguali all'id del predcendente +1
        attuale->next=nuovo;//attuale->next diventa l'ultimo
        attuale=nuovo;
    }
    printf("Hai forgiato %s!!\n",attuale->nome);
    struct oggetto *appoggio;
    appoggio=malloc(sizeof(struct oggetto));
    appoggio=start;
    printf("Armi forgiate:\n");
    for(int i=0;i<10;i++){
        printf("%s\n",appoggio->nome);
        appoggio=appoggio->next;
        if (appoggio==NULL)
            break;
    }
    enter();
    return;
}

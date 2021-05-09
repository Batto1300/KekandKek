#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<stdbool.h>
#include "lib.h"
extern int Bagilita,Bvita,Bintelligenza,Bforza;
extern int espxlvl;
extern int punticaratteristica;
extern int classepg;
extern int narmi,narmature,nstivali,nguanti,nguanti;
//  drago
extern t_mostro gandora;
extern t_mostro drago_titanico;
extern t_mostro drago_berserk;
extern t_mostro viverna;
extern t_mostro *drago;
//  angelo
extern t_mostro asmodeus;
extern t_mostro arcangelo;
extern t_mostro araldo;
extern t_mostro spirito_etereo;
extern t_mostro *angeli;
//  non_morto
extern t_mostro zera;
extern t_mostro dissennatore;
extern t_mostro spadaccino_nonmorto;
extern t_mostro lupo_pestilente;
extern t_mostro *nonmorti;
//  lupo
extern t_mostro muulupo;
extern t_mostro cerbero;
extern t_mostro licantropo;
extern t_mostro metalupo;
extern t_mostro *lupi;
//  ABILITA
//  drago
extern t_abilita_mostro pulsar;
extern t_abilita_mostro fiammata;
extern t_abilita_mostro alito_gelido;
extern t_abilita_mostro azzannata;
extern t_abilita_mostro *abilitadraghi;
//  angelo
extern t_abilita_mostro apocalisse;
extern t_abilita_mostro giudizio_divino;
extern t_abilita_mostro divinazione;
extern t_abilita_mostro attacco_divino;
extern t_abilita_mostro *abilitaangeli;
//  non_morto
extern t_abilita_mostro dannazione;
extern t_abilita_mostro ira;
extern t_abilita_mostro urlo;
extern t_abilita_mostro lacerazione;
extern t_abilita_mostro *abilitanonmorti;
//  lupo
extern t_abilita_mostro incornata;
extern t_abilita_mostro furia;
extern t_abilita_mostro fendente;
extern t_abilita_mostro morso;
extern t_abilita_mostro carica;
extern t_abilita_mostro *abilitalupi;
//  ELMO
extern t_oggetto elmo_dragone;
extern t_oggetto elmo_spirituale;
extern t_oggetto elmo_ossa;
extern t_oggetto elmo_cuoio;
extern t_oggetto *elmi;
//  GUANTI
extern t_oggetto guanti_dragone;
extern t_oggetto guanti_spirituali;
extern t_oggetto guanti_ossa;
extern t_oggetto guanti_cuoio;
extern t_oggetto *guanti;
//  STIVALI
extern t_oggetto stivali_dragone;
extern t_oggetto stivali_spirituali;
extern t_oggetto stivali_ossa;
extern t_oggetto stivali_cuoio;
extern t_oggetto *stivali;
//  ARMATURA
extern t_oggetto corazza_dragone;
extern t_oggetto cappa_spirituale;
extern t_oggetto armatura_ossa;
extern t_oggetto armatura_cuoio;
extern t_oggetto *armature;
//  ARMA
extern t_oggetto scudo;
extern t_oggetto alabarda;
extern t_oggetto spada;
extern t_oggetto bacchetta;
extern t_oggetto arco;
extern t_oggetto *armi;
//  CLASSE
extern t_classe paladino;
extern t_classe mago;
extern t_classe guerriero;
extern personaggio protagonista;
//  ABILITA
extern t_abilita attacco_potente;
extern t_abilita palla_di_fuoco;
extern t_abilita usoarma;
extern t_oggetto *arrequip[6];
extern struct oggetto *start;
void nuovapartita(){
   // system("clear");
	char sceltanome[10];
	printf("Per continuare inserisci il nome del tuo cavaliere: ");
	scanf("%s", sceltanome);
	strcpy(protagonista.nome,sceltanome);
	system("clear");
	printf("\nSalve %s, scegli la tua classe:\n\n[1]Guerriero   Fo: 8  Int: 2  Agi: 4  Vi: 80\n[2]Mago        Fo: 2  Int: 8  Agi: 4  Vi: 80\n[3]Paladino    Fo: 5  Int: 5  Agi: 3  Vi: 100\n",protagonista.nome);
	int sceltaclasse;
	scanf("%d",&sceltaclasse);
	system("clear");
	t_classe *classe;
	classe=malloc(sizeof(struct classe));   //SCELTA DELLA CLASSE
		if(sceltaclasse==1)
			*classe=guerriero;
		if(sceltaclasse==2)
			*classe=mago;
		if(sceltaclasse==3)
			*classe=paladino;
	protagonista.forza=classe->forzaclasse; //aggiungio le caratteristiche scelte alla struttura protagonsita
	protagonista.intelligenza=classe->intelligenzaclasse;
	protagonista.agilita=classe->agilitaclasse;
	protagonista.vita=classe->vitaclasse;
	protagonista.soldi=5;
	if (sceltaclasse==1 ||sceltaclasse== 3){ //i maghi hanno abilita differenti, per questo devo avere una varibile che ha in memoria la sua scelta
			classepg=1;
	}else classepg=2;
	printf("Seleziona un arma iniziale, hai a disposizione %dori\n",protagonista.soldi);
	struct oggetto *appoggio;
	appoggio=malloc(sizeof(struct oggetto));
	appoggio=armi;
	for(int i=0; i<5; i++){                                 //mostro le armi disponibili
        printf("[%d] %s\n",appoggio->id ,appoggio->nome);
		printf("Fo: +%d   ", appoggio->bforza);
		printf("Int: +%d   ", appoggio->bintelligenza);
		printf("Agi: +%d   ", appoggio->bagilita);
		printf("Vi: +%d   ", appoggio->bvita);
		printf("Costo: %d ori\n", appoggio->costo);
		if(appoggio->next==NULL) break;
		else appoggio=appoggio->next;
    }
	int sceltaarma;
	scanf("%d",&sceltaarma);
	//system("clear");
	struct oggetto *comprato;
	comprato=malloc(sizeof(struct oggetto));
    comprato=searchIDoggetto(1,sceltaarma);  //richiamo funzione che mi ritorna un puntatore all'
    comprato->acquisto=true;
	protagonista.soldi=protagonista.soldi-comprato->costo;
	Equipaggia(1,comprato);
	printf("\nQueste sono le tue statistiche aggiornate:\nFo: %d  Int: %d  Agi: %d  Vi: %d\nOri: %d\n\n======================================================================================\n",protagonista.forza+Bforza,protagonista.intelligenza+Bintelligenza,protagonista.agilita+Bagilita,protagonista.vita+Bvita, protagonista.soldi);
	enter();
    Menu();
	}


void Astrub(){
    while(0==0){
        system("clear");
        int scelta ;
        printf("\n");
        printf("  __________________________\n");
        printf(" |  ________________________|_\n");
        printf(" | |                          |\n");
        printf(" | | ASTRUB                   |\n");
        printf(" | |                          |\n");
        printf(" | |                          |\n");
        printf(" | | [1]Mercato               |\n");
        printf(" | |                          |\n");
        printf(" | | [2]Bacheca               |\n");
        printf(" | |                          |\n");
        printf(" | | [3]Taverna               |\n");
        printf(" | |                          |\n");
        printf(" | | [4]Esplolora Dintorni    |\n");
        printf(" | |                          |\n");
        printf(" | | [5]Fucina                |\n");
        printf(" | |                          |\n");
        printf(" |_| [6]Menu Principale       |\n");
        printf("   |__________________________|\n");
            while(0==0){                    //ciclo infinito per scelta sbagliata e per evitare i goto
                scanf("%d", &scelta);
                switch (scelta){
                    case 1:{
                        Mercato();
                        break;
                    }
                    case 2:{
                        Bacheca();
                        break;
                    }
                    case 3:{
                        Taverna();
                        break;
                    }
                    case 4:{
                        printf("Stai per uscire dalla Citta'! incontrereai molti mostri pericolosi e rischierai la vita!\n[1]Esci dalla Citta'     [2]Rimani nella Citta'");
                        int entrata;
                        scanf("%d",&entrata);
                        if(entrata==1)
                        Esplora_Dintorni();
                        else break;
                    }
                    case 6: {
                        Menu();
                        break;
                        }
                    case 5:{
                            fucina();
                            break;
                    }
                    default : printf("\nRipeti la scelta\n");
                    }
                break;
            }
    }
}
void Esplora_Dintorni(){
    srand(time(NULL));
    system("clear");
    struct mostro *mostrocasuale;
    mostrocasuale=malloc(sizeof(struct mostro));  //genero un mostro casuale
    int tipo=rand()%2+1, id=rand()%2+1;
    mostrocasuale=searchIDmostro(tipo,id);
    if(Fight(mostrocasuale)==1){
        printf("\nHai vinto!!\nGuandagni 2 ori!");
        protagonista.soldi+=2;          //se vince guadanga 2 oro
        Drop();                            //e ha una possibilita di drop
    }else printf("\nHai perso!!\n");
	printf("Desideri continuare a cercare?\n[1]Prosegui\n[2]Torna alla citta'\n");
	int scelta;
	scanf("%d", &scelta);
	if(scelta==1)
		Esplora_Dintorni();
	if(scelta==2)
		Astrub();
    return;
}
void Inventario(){
    while(0==0){
        system("clear");
        printf("========IL TUO INVENTARIO========\n\n");
        t_oggetto *appoggio;
        appoggio=malloc(sizeof(struct oggetto));
        int i=0, q=0, w=0, e=0, r=0;
        printf("Soldi: %d\n\n",protagonista.soldi);
        printf("\n-ARMI\n");
        appoggio=armi; //per le armi mi appoggio alla prima arma delle armi gli altri for sono uguali solo che assegno ad appoggio il primo degli altri tipi
        for(;i<=5;i++){
            if(appoggio==NULL) break;//controllo per non fargli scrivere (null)
            if(appoggio->acquisto==true){  //SE IL COSTO E' DIVERSO DA 0 VUOL DIRE CHE E' RIEMPITO DI QUALCOSA
                printf("[%d] %s\n",i+1, appoggio->nome);
                printf("Fo: %d   ", appoggio->bforza);
                printf("Int: %d   ", appoggio->bintelligenza);
                printf("Agi: %d   ", appoggio->bagilita);
                printf("Vi: %d\n", appoggio->bvita);
                if(arrequip[1]==appoggio)   printf("              EQUIPAGGIATO");   //se e presente nella poszione che rappresenta il suo tipo nell arrequip allora e' equipaggiato
            }
            appoggio=appoggio->next;
        }
        printf("\n-ELMI\n");
        appoggio=elmi;
        for(;q<=3;q++){
            if(appoggio==NULL) break;
            if(appoggio->acquisto==true){  //SE IL COSTO E' DIVERSO DA 0 VUOL DIRE CHE E' RIEMPITO DI QUALCOSA
                printf("[%d] %s\n",q+1, appoggio->nome);
                printf("Fo: %d   ", appoggio->bforza);
                printf("Int: %d   ", appoggio->bintelligenza);
                printf("Agi: %d   ", appoggio->bagilita);
                printf("Vi: %d\n", appoggio->bvita);
                if(arrequip[2]==appoggio)   printf("              EQUIPAGGIATO");
            }
            appoggio=appoggio->next;
        }
        printf("\n-CORAZZE\n");
        appoggio=armature;
        for(;w<=3;w++){
            if(appoggio==NULL) break;
            if(appoggio->acquisto==true){  //SE IL COSTO E' DIVERSO DA 0 VUOL DIRE CHE E' RIEMPITO DI QUALCOSA
                printf("[%d] %s\n",w+1, appoggio->nome);
                printf("Fo: %d   ", appoggio->bforza);
                printf("Int: %d   ", appoggio->bintelligenza);
                printf("Agi: %d   ", appoggio->bagilita);
                printf("Vi: %d\n", appoggio->bvita);
                if(arrequip[3]==appoggio)   printf("              EQUIPAGGIATO");
            }
            appoggio=appoggio->next;
        }
        printf("\n-GUANTI\n");
        appoggio=guanti;
        for(;e<=3;e++){
            if(appoggio==NULL) break;
            if(appoggio->acquisto==true){  //SE IL COSTO E' DIVERSO DA 0 VUOL DIRE CHE E' RIEMPITO DI QUALCOSA
                printf("[%d] %s\n",e+1, appoggio->nome);
                printf("Fo: %d   ", appoggio->bforza);
                printf("Int: %d   ", appoggio->bintelligenza);
                printf("Agi: %d   ", appoggio->bagilita);
                printf("Vi: %d\n", appoggio->bvita);
                if(arrequip[4]==appoggio)   printf("              EQUIPAGGIATO");;
            }
            appoggio=appoggio->next;
        }
        printf("\n-STIVALI\n");
        appoggio=stivali;
        for(;e<=3;e++){
            if(appoggio==NULL) break;
            if(appoggio->acquisto==true){  //SE IL COSTO E' DIVERSO DA 0 VUOL DIRE CHE E' RIEMPITO DI QUALCOSA
                printf("[%d] %s\n",r+1, appoggio->nome);
                printf("Fo: %d   ", appoggio->bforza);
                printf("Int: %d   ", appoggio->bintelligenza);
                printf("Agi: %d   ", appoggio->bagilita);
                printf("Vi: %d\n", appoggio->bvita);
                if(arrequip[5]==appoggio)   printf("              EQUIPAGGIATO");
            }
            appoggio=appoggio->next;
        }
        printf("\n-SPECIAL\n");
        appoggio=start;
        while(appoggio!=NULL){
            printf("[%d] %s\n",appoggio->id, appoggio->nome);
            printf("Fo: %d   ", appoggio->bforza);
            printf("Int: %d   ", appoggio->bintelligenza);
            printf("Agi: %d   ", appoggio->bagilita);
            printf("Vi: %d\n", appoggio->bvita);
            if(arrequip[0]==appoggio)   printf("             EQUIPAGGIATO");
            appoggio=appoggio->next;
        }
        printf("\nCosa vuoi fare?:\n[1]Equipaggia un oggetto    [2]Torna al menu\n");
        int scelta;
        scanf("%d", &scelta);
        if(scelta==2)
            Menu();
        if(scelta==1){
            int sceltatipo;
            int sceltaoggetto;
            struct oggetto *equipaggio;
            equipaggio=malloc(sizeof(struct oggetto));
            printf("Cosa vuoi equipaggire?\n[1]Arma            [2]Elmo\n[3]Corazza   [4]Guanti      [5]Stivali    [0]SPECIAL");
            scanf("%d",&sceltatipo);
            printf("\nDigita l'oggetto che vuoi equipaggiare");
            scanf("%d",&sceltaoggetto);
            equipaggio=searchIDoggetto(sceltatipo,sceltaoggetto); //richiamo la funzione che mi trova l'oggeto giusto
            if(equipaggio->acquisto==true){  //se vuole equipaggiare le deve aver comprata
                Equipaggia(sceltatipo,equipaggio); //equipaggio
                enter();
            }
            else{
                while(0==0){
                    printf("Non hai questo oggetto, ridigita il tipo\n");//se non ha l;oggetto che ha indicato
                    scanf("%d",&sceltatipo);
                    printf("\nDigita l'oggetto che vuoi equipaggiare"); //ridigita
                    scanf("%d",&sceltaoggetto);
                    if(equipaggio->acquisto==true){     //stessa cosa di prima
                        Equipaggia(sceltatipo,equipaggio);
                        enter();
                    }
                }
            }
        }
    }
}
void Mercato(){
    system("clear");
	while(0==0){
        printf("benvenuto nel mercato! Cosa vuoi comprare?\n[1]Armi     \n[2]Elmi     [3]Corazze\n[4]Guanti   [5]Stivali\n");
        int scelta1; //ovvero il tipo di oggetto +1
        t_oggetto *appoggio;
        appoggio=malloc(sizeof(struct oggetto));
        scanf("%d", &scelta1);
        if(scelta1==1)                  //controllo che tipo di oggetto ha scelto e inizializzo l'appoggio al primo della corrispettiva lista
            appoggio=armi;
        if(scelta1==2)
            appoggio=elmi;
        if(scelta1==3)
            appoggio=armature;
        if(scelta1==4)
            appoggio=guanti;
        if(scelta1==5)
            appoggio=stivali;
        int i;
        for(i=0;i<5;i++){              //stampo le carartteristiche di tutti gli oggetti del tipo scelto
            if(appoggio==NULL)          //per evitare segmentation fault
                break;
            printf("[%d] %s\n",appoggio->id,appoggio->nome);
            printf("Fo: +%d   ",appoggio->bforza);
            printf("Int: +%d   ",appoggio->bintelligenza);
            printf("Agi: +%d   ",appoggio->bagilita);
            printf("Vi: +%d   ",appoggio->bvita);
            printf("Costo: %d ori\n",appoggio->costo);
            appoggio=appoggio->next;
        }
        printf("Digita il numero dell'arma che vuoi comprare");     //ovvero id oggetto
        t_oggetto *appoggio2;
        malloc(sizeof(struct oggetto));
        while (0==0){ //loop infinito per evitare goto
            int scelta2;
            scanf("%d",&scelta2);
            appoggio2=searchIDoggetto(scelta1,scelta2);
        if(appoggio2->acquisto==true)            //se e' uguale esco dall'endless loop e vado avanti
                (printf("hai gia' quest'arma!, scegline un'altra\n"));
        else break;
        }
        if(protagonista.soldi-appoggio2->costo<=0 ){              //se non ha soldi lo caccio via e lo faccio ritornare al menu
        printf("Stai cercando di fregarmi?? Non hai abbastanza soldi! Vattene, barbone!!");
        return ;
        }
        appoggio2->acquisto=true;                                    //aggiorno lo stato di acquisto dell'oggetto
        protagonista.soldi=protagonista.soldi-appoggio2->costo;      //aggiorno i soldi del giocatore
        Equipaggia(scelta1,appoggio2);                               //equipaggio direttamente l'arma
        int scelta3;
        printf("vuoi comprare di nuovo? [1]Si   [2]No\n");
        while(0==0){        //while infinito per non inserire un goto
            scelta3=0;
                scanf("%d",&scelta3);
            switch (scelta3){       //scelta da fare
                case 1 :
                    break;
                case 2 :
                    return;
                default :  {
                    printf("scrivi qualcosa di sensato, per favore. Sono un pc, non un cristiano, ripeti la scelta\n");
                    break;
                }

            }
            if(scelta3==1)      //se ha chiesto di non comprare piu' devo inserire un break in piu' per uscire dal while infinito
                break;
        }
    }
}
void Caratteristiche(){
    system("clear");
	printf("Liv: %d\n", protagonista.lvl);
	printf(" Fo %d\n", protagonista.forza);
	printf(" Int %d     ", protagonista.intelligenza);
	printf(" Vi %d\n ", protagonista.vita);
	printf(" Agi %d\n          ", protagonista.agilita);
	printf("          Cosa vuoi fare?\n[1]Ritorna al menu            [2]Aumenta le caratteristiche\n\n"); //mostor caratteristiche e punti;
	int scelta1;
	scanf("%d",&scelta1);
	if(scelta1==1){
			Menu();
		}
	if(scelta1==2){
        if(punticaratteristica==0){
                printf("\nHai 0 punti da distribuire!");
                enter();
                return;
        }
		int fo,inte,agi,vi;
		printf("Hai %d punti caratteristica da distribuire\n",punticaratteristica); //mostro i punti che puo' distrubuire
		error_punticaratteristica:
		printf("Fo: ");
		scanf("%d", &fo);
		printf("\nInt: ");
		scanf("%d",&inte);
		printf("\nAgi:");
		scanf("%d",&agi);
		printf("\nVi:");
		scanf("%d",&vi);
            if(fo+inte+agi+vi>punticaratteristica){
                printf("hai utilizzato troppi punti! Ne hai solo %d\n", punticaratteristica);
                goto error_punticaratteristica;
            }
            else
            {
                protagonista.forza=protagonista.forza+fo;  //aumento i punti caratteristica
                protagonista.agilita=protagonista.agilita+agi;
                protagonista.intelligenza=protagonista.intelligenza+inte;
                protagonista.vita=protagonista.vita+(vi*10);
                printf("\ncaratteristiche aumentate!");
            }
    }
    return;
}
int Dungeon_nonmorti(){
    srand(time(NULL));
    system("clear");
	printf("Ti trovi dinanzi ad uno spettrale cancello di ferro, unica entrata del Cimitero dei Dannati\n\nDesideri entrare nel Dongione?\n[1]Entra     [2]Menu");
	int entrata;
	scanf("%d",&entrata);       //se vuole entrare o meno
	if (entrata==2){
		return 0;
	}
	struct mostro *mostroD;
	mostroD=malloc(sizeof(struct mostro));
	//STANZA 1 ------------------------------------------------------------------------------------------------
	system("clear");
	printf("\nTi trovi nella 1a stanza del Dungeon.\n\n\n");
	//INIZIO COMBATTIMENTO
	mostroD=searchIDmostro(2,1); //assoccio a mostroD un puntatore a struttura con la funzione
	enter();
	if (Fight(mostroD)==0){ //se perde
        system("clear");
		printf("Hai perso!");
		enter();
		return 0;
	}
	printf("\n\nDopo aver sconfitto il nemico, la sua carcassa cade a terra, viene avvolto da una potente luce \nche lo dissolve e ti indica la via per proseguire. \n\n");//se vince
	printf("Desideri continuare il Dongione?\n[1]Prosegui\n[2]Esci\n(Se uscirai i tuoi progressi verranno persi)");
	int scelta;
	scanf("%d", &scelta);
			if(scelta==2)
				return 0;
    system("clear");
	printf("Ti trovi nella seconda stanza del Dungeon.\n\n\n");
	enter();
	mostroD=searchIDmostro(2,3); ///altro mostro
	if(Fight(mostroD)==0){
        system("clear");
		printf("Hai perso!");
		enter();
		return 0;
	}
    system("clear");
	printf("\n\n Il corpo del dissennatore inizia a sgretolarsi, una forte folata di vento solleva i suoi reti che volano via,\n finendo nella serratura di una cripta. Senti la porta sbloccarsi.");
	printf("\n\nDesideri continuare il Dongione?\n[1]Prosegui\n[2]Esci\n(Se uscirai i tuoi progressi verranno persi");
	int scelta2;
	scanf("%d", &scelta2);
	system("clear");
	printf("Ti trovi nell'ultima stanza del Dungeon.\n\n\n");
	printf("Sei entrato nella cripta, la luce lunare che filtra da un grande lucernaio sul soffitto illumina la stanza,\n ti guardi intorno, vedi un trono in penombra con una figura imponente.\nTi trovi contro Zera, il Dannato\n\n");
	mostroD=searchIDmostro(2,4);//altro mostor
	if(Fight(mostroD)==1){//se vince
        system("clear");
		printf("Hai sconfitto il leggendario Zera!! Nella cripta trovi un misterioso forziere.");
		printf("Trovi armatura d'ossa e 20 Oro!!");
		printf("Vieni riportato ad Astrub\n");
		enter();
		armatura_ossa.acquisto=true;
		protagonista.soldi=protagonista.soldi+20;
		return 1;
	}else return 0;//se perde
	return 2;//se succede qualcosa di strano lo riconosco da la return value
}
int Dungeon_lupi(){ //come sopra solo con altri mostri
    srand(time(NULL));
    system("clear");
    printf("Ti trovi dinanzi ad un imponente portone, incavato nell` antica roccia della montagna.\nSopra all` entrata c`e` un incisione:\n\n ''Imprudente e` colui che osa entrare, roviana a chi profana la tana del Re Lupo'''\n\nDesideri entrare nel Dongione?\n[1]Entra     [2]Menu");
	int entrata;
	scanf("%d",&entrata);
	if (entrata==2){
		return 0;
	}
	//STANZA 1 ------------------------------------------------------------------------------------------------
	system("clear");
	printf("\nTi trovi nella 1a stanza del Dungeon.\n\n\n");
	//INIZIO COMBATTIMENTO
	struct mostro *mostroD;
	mostroD=malloc(sizeof(struct mostro));
	int mostrorand=rand()%2+1;
    mostroD=searchIDmostro(1,mostrorand);
    enter();
    if (Fight(mostroD)==0){
        system("clear");
		printf("Hai perso!\n");
        enter();
		return 0;
	}
	system("clear");
	printf("\n\nDopo aver sconfitto il nemico, il suo sangue si riversa a terra, si incanala in dei piccoli solchi sul pavimento e scompare dietro ad una parete.\nDopo pochi secondi una porta nascosta si apre.\n\n");
	printf("Desideri continuare il Dongione?\n[1]Prosegui\n[2]Esci\n(Se uscirai i tuoi progressi verranno persi)");
	int scelta;
	scanf("%d", &scelta);
			if(scelta==2)
				return 0;
    system("clear");
	printf("Ti trovi nella seconda stanza del Dungeon.\n\n\n");
	enter();
	mostroD=searchIDmostro(1,3);
	if(Fight(mostroD)==0){
        system("clear");
		printf("Hai perso!");
		enter();
		return 0;
	}
	system("clear");
	printf("\n\n Noti che il corpo del Cerbero inizia a squagliarsi, corrodendo il pavimento, dopo qualche secondo si forma una voragine sul pavimento.\nTi sporgi e vedi un altra stanza");
	printf("\n\nDesideri continuare il Dongione?\n[1]Prosegui\n[2]Esci\n(Se uscirai i tuoi progressi verranno persi");
	int scelta2;
	scanf("%d", &scelta2);
	system("clear");
	printf("Ti trovi nell'ultima stanza del Dungeon.\n\n\n");
	printf("Sei sceso nella stanza, il polverone causato dal crollo del soffitto incomincia a diradarsi, riesci a vedere a qualche palmo di distanza, ma riesci bene a sentire un fiato dietro il tuo collo,\nti giri e un gigantesco lupo cornuto e' a qualche centimetro dal tuo naso, PREPARATI!'\nn");
	enter();
	searchIDmostro(1,4);
	if(Fight(mostroD)==1){
		printf("Hai sconfitto il leggendario Muulupo!! Dietro di lui trovi un forziere");
		printf("Trovi guanti di cuoio e 15 Oro!!");
		protagonista.soldi=protagonista.soldi+15;
		guanti_cuoio.acquisto=true;
		printf("Verrai riportato in citta'");
		enter();
		return 1;
	}else return 0; //se perde
	return 2;
	}

int Dungeon_draghi(){//come sopra
    system("clear");
	printf("Ti trovi sul Colle Drako\n\nDesideri entrare nel Dongione?\n[1]Entra     [2]Menu");
	int entrata;
	scanf("%d",&entrata);
	if (entrata==2){
		return 0;
	}
	//STANZA 1 ------------------------------------------------------------------------------------------------
	printf("\nTi trovi nella 1a stanza del Dungeon.\n\n\n");
    struct mostro *mostroD;
	mostroD=malloc(sizeof(struct mostro));
	//INIZIO COMBATTIMENTO
	enter();
	mostroD=searchIDmostro(4,1);
	if (Fight(mostroD)==0){
        system("clear");
		printf("Hai perso!");
		enter();
		return 0;
	}
	system("clear");
	printf("\n\nDopo aver sconfitto il nemico, un Drago Titanico ti nota e avanza minaccioso contro di te!\n\n");
	printf("Desideri continuare il Dongione?\n[1]Prosegui\n[2]Fuggi!\n(Se uscirai i tuoi progressi verranno persi)");
	int scelta;
	scanf("%d", &scelta);
			if(scelta==2)
				return 0;
	printf("Ti trovi nella seconda stanza del Dungeon.\n\n\n");
	mostroD=searchIDmostro(4,3);
	enter();
	if(Fight(mostroD)==0){
        system("clear");
		printf("Hai perso!");
        enter();
		return 0;
	}
    system("clear");
	printf("\n\n Il Drago Titanico, con il suo ultimo respiro, lancia un grande urlo.\nIntuisci che si tratta di un richiamo! ");
	printf("\n\nDesideri continuare il Dongione?\n[1]Prosegui\n[2]Esci\n(Se uscirai i tuoi progressi verranno persi");
	int scelta2;
	scanf("%d", &scelta2);
	printf("Ti trovi nell'ultima stanza del Dungeon.\n\n\n");
	printf("Vedi una grande sagoma uscire da dietro una montagna e solcare il cielo,\navvicinandosi riconosci che si tratta del leggendario drago Gandora, \nla Genesi!\n\n ");
	mostroD=searchIDmostro(4,4);
	if(Fight(mostroD)==1){
		printf("Hai sconfitto il leggendariGandora! Squarti il suo ventre e trovi ... solo budella\n");
		int uno,c;
		printf("                   Premi 1 per continuare");
		scanf("%d",&uno);
		for(c=1;c>-1;c++){
				enter();
			}
		printf("\n\n\n\n\n\n\n                          THE FINE\n\n\n\n\n\n");
		printf("                      FINAL CREDITI\n\n");
		printf("                        CREATORIS:\n\n");
		printf("                    Filippo Capoccia\n");
		printf("                     Tommaso Ricci\n\n");
		printf("                   SPECIAL GRAZIE TO:\n\n");
		printf("                 Francesco Faloci per il suo supporto psicologico\n\n");
		printf("                           kek\n");
		int trollata;
		scanf("%d",&trollata);
	}else return 0;
	return 0;
}
void Mappa() {// solo printf della mappa e if per varie scelte
    while(0==0){
        system("clear");
        printf("  ____________________________________________________\n |                  ##                      ||        |\n |                  ##           ___        ||        |\n |                 ##            | |*[4]    //        |\n |      *[2]      ##           .:::        //         |\n |               ##        .:::::         //          |\n |              ##       .:::            //           |\n |          ##||#     .::::             //            |\n |        ### ::     .::             f //             |\n |       ##   ::.    ::              i ||             |\n |     ###     :::..::               u ||             |\n |  ####         ::::.               m ||             |\n |###               ::.              e ||             |\n |                  .::.               //             |\n |            .::::::::::::.          //           ###|\n |            ::           :::.       ||         ###  |\n |     #######||###         ::::::::|====|:::. ####   |\n |   ##           ##                  ||     ||       |\n |   #             ##                 //   ##         |\n |   ##     *[3]    #                //   ##          |\n |    ###         ##                //    ##    *[1]  |\n |      ##########                  ||    ##          |\n |__________________________________||____##__________|\n[1]Astrub    [2]Cimitero dei Dannati\n[3]Collina dei draki  [4]Tana del Muulupo \n[0]Esci\n");
        int scelta;
        scanf("%d",&scelta);
        if (scelta == 0){
            Menu() ;
        }
        if(scelta==1){
            Astrub();
            break;
        }
        if(scelta==2){
            Dungeon_nonmorti();
            break;
        }
        if(scelta==3){
            Dungeon_draghi();
            break;
        }
        if(scelta==4){
            Dungeon_lupi();
            break;
        }
    }
    return;
}
void Menu(){//pintf del menu e switch pwr scelte
        system("clear");
        int scelta;
        printf("\n");
        printf(" __________________________\n");
        printf("|  ________________________|_\n");
        printf("| |                          |\n");
        printf("| | MENU PRINCIPALE          |\n");
        printf("| |                          |\n");
        printf("| |                          |\n");
        printf("| | [1]Vai in Citta`         |\n");
        printf("| |                          |\n");
        printf("| | [2]Apri la Mappa         |\n");
        printf("| |                          |\n");
        printf("| | [3]Inventario            |\n");
        printf("| |                          |\n");
        printf("| | [4]Caratteristiche       |\n");
        printf("| |                          |\n");
        printf("| |                          |\n");
        printf("| | [5]Salva  [6]Carica      |\n");
        printf("|_|__________________________|\n");
            scanf("%d",&scelta);
        while(0==0){
            switch(scelta){
                case 1:{
                    printf("======================================================================================\n");
                    Astrub();
                    break;
                    }
            case 2:{
                printf("======================================================================================\n");
                Mappa();
                break;
            }
            case 3:{
                printf("======================================================================================\n");
                Inventario();
                break;
            }
            case 4:{
                printf("======================================================================================\n");
                Caratteristiche();
                break;
            }
            case 5:{
                Save();
                break;
            }
            case 6:{
                Load();
                break;
            }
            default: printf("Ripeti scelta");
        }
    }
    return;
    }


void Drop(){
	int dropid, droptipo,drop;
	drop=rand()%10;
	dropid=(rand()%4)+1;
	droptipo=(rand()%5)+1;   //altrimenti potreppe inizializzare searchidoggetto con 0 ed e' sbagliato
	struct oggetto *oggrandom;
	oggrandom=malloc(sizeof(struct oggetto));
	oggrandom=searchIDoggetto(droptipo,dropid);
		if(drop==0){
			printf("\n hai droppato %s!!",oggrandom->nome);
			if(oggrandom->acquisto==true){      //se e' uscito 0 allora gli do un oggetto a cso
				protagonista.soldi=protagonista.soldi+(oggrandom->costo/2); //se gia' lo ha gli do la meta' del prezzo che vale
				printf("siccome possiedi gia' l'arma che hai droppato guadagni la meta' del suo prezzo!! Guadagni:%d oro ", oggrandom->costo/2);
			}else oggrandom->acquisto=true;
			}
	return ;
}

void SCF(){
    int win=0, loss=0, paro=0;
    for(int i=0;i>-1;i++){
        int playerc, computerc,scommessa;
        printf("Decidi quanto scommetere\n");
        scanf("%d",&scommessa);
        while (0==0){
			if(scommessa>protagonista.soldi){ //se non ha abbastanza soldi gli richiedo un altro importo
	        	printf("scegli un altro importo\n");
	        	scanf("%d",&scommessa);
        }else break;
		}
        printf("Scegli:  [1]Sasso  [2]Carta  [3] Forbici\n"); //scelta umano
        scanf("%d",&playerc);
        srand(time(NULL));
        computerc= rand()%3+1;      //scelta pc
        if(computerc==1)
            printf("Avversario: Sasso");
        if(computerc==2)
            printf("Avversario: Carta");
        if(computerc==3)
            printf("Avversario: Forbici");
        if(playerc==computerc){
            printf("\n = Pareggio\n----------------\n");
            paro++;
            printf("pareggio! Non vinci e non perdi nulla!\n");
            }
        if(playerc==computerc-1 || playerc==2+ computerc){ //formula equivalente per la sconfitta
            printf("\n = Sconfitta\n----------------\n");
            loss++;
            printf("hai perso %d soldi!",scommessa);
         	protagonista.soldi=protagonista.soldi+scommessa;
            }
        if(playerc==1+computerc||playerc==computerc-2){ //formula equivalente per la vittoria
            printf("\n = Vittoria\n----------------\n");
            win++;
         	printf("hai vinto %d soldi!",scommessa);
         	protagonista.soldi=protagonista.soldi+scommessa;
            }
        printf("Win: %d, Loss: %d, Pareggi: %d\n\n",win,loss,paro);//se vuoi uscire oppure rigiocare
        printf("Cosa vuoi fare? [1]Rigioca        [2]Esci\n");
        while(0==0){
            int scelta;
            scanf("%d",&scelta);
            switch(scelta){
                case 1: break;
                case 2: return;
                default: printf("Ripeti la scelta\n");
            }
        }
    }
    return ;
}
void Esp(int esperienza){
	protagonista.esp=protagonista.esp+esperienza;
	printf("Hai guadagnato %d PE\n",esperienza);
	if(protagonista.esp>=espxlvl){
		protagonista.lvl++; //aumento del livello
		printf("GG, Hai raggiunto il livello %d e guadagni 3 Punti caratteristica", protagonista.lvl);
		protagonista.esp=protagonista.esp-espxlvl;
		espxlvl=espxlvl*2;                          //formula per calcolare l'esperienza per livellare
		punticaratteristica=punticaratteristica+3; //gli do 3 punti caratteristica da spendere
	}
	return ;
}
void Save(){
	printf("DATI DI GIOCO SALVATI!!\n\n");
	FILE *fps=fopen("Logs/stat.txt","w");
	fprintf(fps,"%d\n",protagonista.forza);             //salvo tutto cio' che mi serve
	fprintf(fps,"%d\n",protagonista.agilita);
	fprintf(fps,"%d\n",protagonista.soldi);
	fprintf(fps,"%d\n",protagonista.vita);
	fprintf(fps,"%d\n",protagonista.mana);
	fprintf(fps,"%d\n",protagonista.intelligenza);
	fprintf(fps,"%d\n",protagonista.lvl);
	fprintf(fps,"%d\n",protagonista.esp);
	fprintf(fps,"%s\n",protagonista.nome );
	fprintf(fps,"%d\n",classepg);
	fprintf(fps,"%d\n",punticaratteristica);
	fclose(fps);
	FILE *lps=fopen("Logs/saveequip.txt","w");
	int a,b;
	struct oggetto *appoggio;
	appoggio=malloc(sizeof(struct oggetto));
	for(b=0;b<5;b++){
        if(b==0) appoggio=armi;         //prima armi
        if(b==1) appoggio=armature;//poi armature
        if(b==2) appoggio=guanti;//poi guanti
        if(b==3) appoggio=elmi;//poi elmi
        if(b==4) appoggio=stivali;//poi stivali
        for(a=0;a<10;a++){
            if(appoggio->acquisto==true){   //salvo tipo e id di cio' che aveva acquistato
                fprintf(lps,"%d\n",appoggio->tipo);
                fprintf(lps,"%d\n",appoggio->id);
            }
            appoggio=appoggio->next;
            if (appoggio==NULL)
                break;
		}
	}
	fclose(lps);
	return;
}
void Load(){
	FILE *fpl=fopen("Logs/stat.txt","r");
	fscanf(fpl,"%d",&protagonista.forza); //carico nell stesso ordine
	fscanf(fpl,"%d",&protagonista.agilita);
	fscanf(fpl,"%d",&protagonista.soldi);
	fscanf(fpl,"%d",&protagonista.vita);
	fscanf(fpl,"%d",&protagonista.mana);
	fscanf(fpl,"%d",&protagonista.intelligenza);
	fscanf(fpl,"%d",&protagonista.lvl);
	fscanf(fpl,"%d",&protagonista.esp);
	fscanf(fpl,"%s",protagonista.nome );
	fscanf(fpl,"%d",&classepg);
	fscanf(fpl,"%d",&punticaratteristica);
	fclose(fpl);
	FILE *lps=fopen("Logs/saveequip.txt","r");
	int y;
	struct oggetto *appoggio;
	int tipo, ID;
	for(y=0;y<=100;y++){//rimodifico lo stato di acquisto degli oggetti che erano stati salvati
		if(fscanf(lps,"%d",&tipo)==EOF) break;
		fscanf(lps,"%d",&ID);
		appoggio=searchIDoggetto(tipo,ID);
		appoggio->acquisto=true;
    }
	printf("DATI DI GIOCO CARICATI!!Ricodari di equipaggiare gli oggetti\n");
	enter();
	Menu();
	}
void Bacheca(){
	printf( "||================================================================||\n ");
	printf( "||   BACHECA DELLE MISSIONI.                      ________        ||\n ");
    printf( "||    ______________________                     |        |       ||\n ");
	printf( "||   |[1]Caccia al Lupo     |                    | ASTRUB |       ||\n ");
	printf( "||   |     -- ---- --- -    |______________      |________|       ||\n ");
	printf( "||   |[2]Peli di Licantropo |i Taverna!    |                      ||\n ");
	printf( "||   |     -- - --- -- -    |     _________|__________________    ||\n ");
	printf( "||   |[3]Debella la Piaga   | -- |                            |   ||\n ");
	printf( "||   |     - - --- --- -    |--  | [5]Caccia agli Spiriti     |   ||\n ");
	printf( "||   |[4]Invasione Zombi    |_-__|       --- -- --- - ----    |   ||\n ");
	printf( "||   |     -- - --- -- -    |    | [6]Cristallo di Araldo     |   ||\n ");
	printf( "||   |______________________|    |       -- -- - ----- - -    |   ||\n ");
	printf( "||              |  - | vendesi ke| [7]Invasione di Draghi     |   ||\n ");
	printf( "||    _______   |____|   -- - -- |       ---- - ---- -- --    |   ||\n ");
	printf( "||   |       |       |     ---- -| [8]Ali di Drago            |   ||\n ");
	printf( "||   |[9]Esci|       |___________|       - ------  - -- --    |   ||\n ");
	printf( "||   |_______|                   |____________________________|   ||\n ");
	printf( "||================================================================||\n");
    printf("Coming soon...");
    enter();
	return ;
}
void Taverna(){
	printf("sei nella taverna decidi cosa fare:");
	printf("[1]Sasso Carta Forbici					[2]Torna indietro");
	int scelta;
	scanf("%d", &scelta);
	switch(scelta){
		case 1:{
			SCF();
			break;
        }
		default:{
			return ;
		}
	}
        return ;
}
void Equipaggia(int tipo,struct oggetto *daequipaggiare){
    //daequipaggiare=malloc(sizeof(struct oggetto));  /NOT RIGHT
    int i;
    for(i=0;i<6;i++){       //euqioaggio l'oggetto nella  posizione equivalente al tipo,
        if(tipo==i){
            arrequip[i]=daequipaggiare;
            break;
        }
    }
	Bforza=0;
	Bagilita=0;
	Bvita=0;
	Bintelligenza=0;
	//printf("\nda daequipaggiare %d\n",daequipaggiare->bforza);        debug
	for(i=0;i<5;i++){
        if(arrequip[i]!=0){
            Bforza=Bforza+arrequip[i]->bforza;
            Bagilita=Bagilita+arrequip[i]->bagilita;
            Bvita=Bvita+arrequip[i]->bvita;
            Bintelligenza=Bintelligenza+arrequip[i]->bintelligenza;
            //printf("B forza%d     ", Bforza);             //debug
        }
    }
	printf("\noggetto equipaggiato!\n");
	//printf("%s\n", daequipaggiare->nome);
}
void enter(){
    printf("Premi invio per continuare");
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); enter=getchar();}
    system("clear");

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"
extern int classepg;
extern int Bagilita,Bvita,Bintelligenza,Bforza;
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
extern t_abilita *abilitadraghi;
//  angelo
extern t_abilita_mostro apocalisse;
extern t_abilita_mostro giudizio_divino;
extern t_abilita_mostro divinazione;
extern t_abilita_mostro attacco_divino;
extern t_abilita *abilitaangeli;
//  non_morto
extern t_abilita_mostro dannazione;
extern t_abilita_mostro ira;
extern t_abilita_mostro urlo;
extern t_abilita_mostro lacerazione;
extern t_abilita *abilitanonmorti;
//  lupo
extern t_abilita_mostro incornata;
extern t_abilita_mostro furia;
extern t_abilita_mostro fendente;
extern t_abilita_mostro morso;
extern t_abilita_mostro carica;
extern t_abilita *abilitalupi;
extern t_abilita attacco_potente;
extern t_abilita palla_di_fuoco;
extern t_abilita usoarma;
extern t_abilita *abilitanonmago[2];
extern t_abilita *abilitamago[2];
extern personaggio protagonista;
int i;
// pg
int agilitapg;
int vitapg;
int manapg; //se lo dichiaro localmente in turnopg viene sempre inizializzato a protagonista.mana ogni volta che comincia il turno
int forzapg; //queste vengono dichiarate globalmente perche' non c'e' alcun bisogno di dichiararle e riassegnarle ogni volta che turno pg viene richiamato
int intelligenzapg;
int dannopg;
// mostro
int agilitamostro;
int vitamostro;
int forzamostro;
int intelligenzamostro;
int livmostro;
int tipomostro;
char nomemostro[25];
int turnopg();
int turnomostro();
int Fight(struct mostro *mostro){
	i=1;                            //turno uno
	vitapg=protagonista.vita+Bvita; //assegno le caratteristiche a variabili per farle piu' comode
    manapg=protagonista.mana;
	agilitapg=protagonista.agilita+Bagilita;
	agilitamostro=mostro->agilitamostro;
	vitamostro=mostro->vitamostro;
	forzamostro=mostro->forzamostro;
    intelligenzamostro=mostro->intelligenzamostro;
    tipomostro=mostro->tipo;
    livmostro=mostro->livello;
    strcpy(nomemostro,mostro->nomemostro);
	intelligenzapg=protagonista.intelligenza+Bintelligenza;
	forzapg=protagonista.forza+Bforza;
    printf("\nSta iniziando lo scontro con %s        HP:%d\n\n",mostro->nomemostro,mostro->vitamostro);
    enter();
	if (agilitapg>=agilitamostro){			//SE IL MOSTRO E' MENO AGILE DEL PG
		while(0==0){
            system("clear");
			printf("Turno:    %d\n\n",i);
			if(turnopg()==1){   //SE VINCE IL GIOCATORE RITORNO 1 OVVERO VITTORIA
                Esp(mostro->esperienza);
				return 1;
            }
			if(turnomostro()==1)    //SE VINCE IL MSOTRO RITORNO 0 OVVERO SCONFITTA
				return 0;
            i++;
		}
	}
	if(agilitapg<agilitamostro){			//SE IL MOSTRO E' PIU' AGILE DEL PG
		while(0==0){
             system("clear");
			printf("Turno:    %d\n\n",i);
			if(turnomostro()==1){
                Esp(mostro->esperienza);
				return 1;
            }
			if(turnopg()==1)
				return 0;
            i++;                //  TURNO
		}
	}
	return 2;
}


int turnopg(){

	int scelta;
	manapg++;
	t_abilita *abilitascelta;
	abilitascelta=malloc(sizeof(struct abilita));
					//WHILE NEL CASO IN CUI SCEGLI UN'ABILITA' ERRATA;
	printf("-E` il turno di: %s\n",protagonista.nome);
	printf("|                    ______       | \n");
	printf("|                   (*,..,*)      | \n");
	printf("|                   />   </       | \n");
	printf("|     _( )_//      /______|       | \n");
	printf("|    |     |                      | \n");
	printf("      |___|       HP Nemico: %d     \n",vitamostro);
	printf("    HP: %d                          \n",vitapg);
	printf("Scegli una mossa:\n");
	printf("Punti Mana: %d              Punti Vita: %d\n\n",manapg,vitapg);
	if(classepg==1){  //SE SEI UN NON MAGO
		printf("[1] %s          ",abilitanonmago[0]->nomeabilita);
		printf("[2] %s          ",abilitanonmago[1]->nomeabilita);   //PRINT DELLE ABILITA
        while(0==0){
            printf("Scegli un abilita\n");
            scanf("%d",&scelta);
            scelta--;
            abilitascelta=abilitanonmago[scelta];
            if ((manapg-abilitascelta->costo)<0){ // SE NON HA ABBASTANZA MANA
                printf("Non hai abbastanza Mana!Scegli un'altra abilita!'\n\n");
            }else break;
        }
    }
    if (classepg==2){		//SE SEI UN MAGO
            printf("[1] %s         ",abilitamago[0]->nomeabilita);
            printf("[2] %s         ",abilitamago[1]->nomeabilita);
             while(0==0){
                printf("Scegli un abilita\n");
                scanf("%d",&scelta);
                scelta--;
                abilitascelta=abilitamago[scelta];
                if ((manapg-abilitascelta->costo)<0){ // SE NON HA ABBASTANZA MANA
                    printf("Non hai abbastanza Mana!Scegli un'altra abilita!'\n\n");
                }else break;			//VADO AVANTI SE HA MANA SUFFICENTE;
        }
	}
	manapg=manapg-(abilitascelta->costo);
	dannopg = forzapg *abilitascelta->modfisico +intelligenzapg * abilitascelta->modmagico;
	vitamostro=vitamostro-dannopg; //CALCOLO DANNI
	printf("Infliggi %d danni al mostro!\n\n",dannopg);
	if (vitamostro<=0)//se vince
		return 1;
	else    //se ancora non ha vinto
		return 0;
}
int turnomostro(){
	int randomdodge;
	int idabilita;
	int dannomostro;
	int t;
	struct abilita_mostro *abilitarand;
	abilitarand=malloc(sizeof(struct abilita_mostro));
	for(t=0;t<4;t++){
		if(livmostro==t){ //se il mostro ha livello 1 allora utilizza solo le prime due abilita
			idabilita=(rand()%(t+2))+1; //formula per trovre abilita del livello giusto
			abilitarand = searchIDabilitamostro(tipomostro,idabilita);//cerco abilita
			break;
		}
	}
    randomdodge=rand()%(25-protagonista.agilita);// una possibilita di schivare l'abilita in base all'agilita base
	printf("- E` il turno di:        %s.\nVita: %d\n\n",nomemostro,vitamostro);
	if (randomdodge != 1){
        dannomostro = intelligenzamostro * abilitarand->modmagico + forzamostro * abilitarand->modfisico;//calcolo del danno
		vitapg=vitapg-dannomostro;
		printf("%s usa %s\n",nomemostro, abilitarand->nome);
		printf("Subisci %d danni!\n",dannomostro);
		enter();
    }
	else {
        printf("Hai schivato il colpo!\n");
        enter();
        }
	if(vitapg<=0)// se perde
		return 1;
	if(vitapg>0) //se ancora non ha perso
		return 0;
    return 2;
}

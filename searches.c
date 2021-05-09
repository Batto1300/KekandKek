#include"lib.h"
#include<stdio.h>
#include<stdlib.h>
extern int Bgold, Bmana,Bdrop,Bagilita,Bvita,Bintelligenza,Bresveleni,Bforza;
extern int citta;
extern int Bgold, Bmana,Bdrop,Bagilita,Bvita,Bintelligenza,Bresveleni,Bforza;
extern int espxlvl;
extern int punticaratteristica;
extern int classepg;
extern int narmi,narmor,nboots,nglove,nhat;
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
extern struct oggetto *start;
struct oggetto *searchIDoggetto(int tipo,int ID ){
	int a;
	struct oggetto *datrovare;
	datrovare=malloc(sizeof(struct oggetto));
	if(tipo==1)//a secondo del tipo assegno la variabile di appoggio
		datrovare=armi;
	if(tipo==2)
		datrovare=elmi;
	if(tipo==3)
		datrovare=armature;
	if(tipo==4)
		datrovare=guanti;
	if(tipo==5)
		datrovare=stivali;
    if(tipo==0)
        datrovare=start;
	for(a=0;a<5;a++){
        if(datrovare==NULL) break; //se la lista e' finita esco
		if(datrovare->id==ID){
         //   printf("\n%s\n",datrovare->nome);
			return datrovare;//se ho trovato quello giusto return
		}
        datrovare=datrovare->next;//altrimenti vando avanti
	}
	return datrovare;
}
struct abilita_mostro *searchIDabilitamostro(int tipo,int ID){
    int a;
    t_abilita_mostro *datrovare;
	datrovare=malloc(sizeof(struct abilita_mostro));
	if(tipo==1)
        datrovare=abilitalupi;
	if(tipo==2)
		datrovare=abilitanonmorti;
	if(tipo==3)
		datrovare=abilitaangeli;
	if(tipo==4)
		datrovare=abilitadraghi;
	for(a=0;a<5;a++){
		if(datrovare->id==ID){
           // printf("\n%s\n",datrovare->nome);
			return datrovare;
		}
        datrovare=datrovare->next;
	}
	return datrovare;
}
struct mostro *searchIDmostro(int tipo, int ID){
    t_mostro *datrovare;
    datrovare=malloc(sizeof(struct mostro));
    if(tipo==1)
        datrovare=lupi;
    if(tipo==2)
        datrovare=nonmorti;
    if(tipo==3)
        datrovare=angeli;
    if(tipo==4)
        datrovare=drago;
    int a;
    for(a=0;a<5;a++){
        if(datrovare->id==ID){
       //     printf("\n%s\n",datrovare->nomemostro);
            return datrovare;
            }
        if(datrovare->next==NULL)
            exit(1);
        else datrovare=datrovare->next;
    }
    return datrovare;
}


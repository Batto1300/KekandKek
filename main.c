#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<stdbool.h>
#include "lib.h"
int Bagilita,Bvita,Bintelligenza,Bforza;
int espxlvl;
int punticaratteristica;
int classepg;
int narmi=0,narmature=0,nstivali=0,nguanti=0,nelmi=0;
//  MOSTRI
//  drago                                                               Fo In Ag  Vi  Exp lv Ty ID
t_mostro gandora=                                {"Gandora, la Genesi",10,10, 7,300,2100, 2,4,4,NULL};
t_mostro drago_titanico=                             {"Drago Titanico", 7, 7, 3,210,1050, 1,4,3,&gandora};
t_mostro drago_berserk=                              {"Drago Berserk", 5, 4, 5,170, 850, 0,4,2,&drago_titanico};
t_mostro viverna=                                           {"Viverna", 3, 4, 4,100, 650, 0,4,1,&drago_berserk};
t_mostro *drago=&viverna;
//  angelo                                                                 Fo In Ag  Vi  Exp lv Ty ID
t_mostro asmodeus=                        {"Asmodeus, il Purificatore", 0, 9, 8,333,1900, 2,3,4,NULL};
t_mostro arcangelo=                                       {"Arcangelo", 8, 6, 5,160,1000, 1,3,3,&asmodeus};
t_mostro araldo=                                             {"Araldo", 0, 6, 6,100, 800, 0,3,2,&arcangelo};
t_mostro spirito_etereo=                             {"Spirito Etereo", 0, 4, 4, 80, 600, 0,3,1,&araldo};
t_mostro *angeli=&spirito_etereo;
//  non_morto                                                                Fo In Ag  Vi  Exp lv Ty ID
t_mostro zera=                                         {"Zera, il Dannato", 8, 0,10,280,1700, 2,2,4,NULL};
t_mostro dissennatore=					   {"Dissennatore", 6, 0, 6,150, 950, 1,2,3,&zera};
t_mostro spadaccino_nonmorto=			   {"Spadaccino non morto", 6, 0, 4,110, 750, 0,2,2,&dissennatore};
t_mostro lupo_pestilente=   			        {"Lupo Pestilente", 5, 0, 2, 70, 550, 0,2,1,&spadaccino_nonmorto};
t_mostro *nonmorti=&lupo_pestilente;
//  lupo                                                               Fo In Ag  Vi  Exp lv Ty ID
t_mostro muulupo=              			                    {"Muulupo", 5, 0, 4,220,1500, 2, 1,4,NULL};
t_mostro cerbero=             			                    {"Cerbero", 4, 0, 4,150, 900, 1, 1,3,&muulupo};
t_mostro licantropo=                                     {"Licantropo", 3, 0, 3,130, 700, 0, 1,2,&cerbero};
t_mostro metalupo=                                         {"Metalupo", 2, 0, 3, 90, 500, 0, 1,1,&licantropo};
t_mostro *lupi=&metalupo;
//  ABILITA
//  drago                                                   mF mM Ty ID
t_abilita_mostro pulsar=                      {"Pulsar", 0, 6, 3,4,NULL};
t_abilita_mostro fiammata=                  {"Fiammata", 0, 5, 3,3,&pulsar};
t_abilita_mostro alito_gelido=          {"Alito Gelido", 0, 4, 3,2,&fiammata};
t_abilita_mostro azzannata=                {"Azzannata", 2, 0, 3,1,&alito_gelido};
t_abilita_mostro *abilitadraghi=&azzannata;
//  angelo                                                   mF mM Ty ID
t_abilita_mostro apocalisse=              {"Apocalisse", 0, 9, 2,4,NULL};
t_abilita_mostro giudizio_divino=     {"Giudizio Dvino", 0, 5, 2,3,&apocalisse};
t_abilita_mostro divinazione=            {"Divinazione", 0, 4, 2,2,&giudizio_divino};
t_abilita_mostro attacco_divino=     {"Attacco Divino", 0, 3, 2,1,&divinazione};
t_abilita_mostro *abilitaangeli=&attacco_divino;
//  non_morto                                               mF mM Ty ID
t_abilita_mostro dannazione=              {"Dannazione", 6, 0, 1,4,NULL};
t_abilita_mostro ira=                            {"Ira", 4, 0, 1,3,&dannazione};
t_abilita_mostro urlo=                          {"Urlo", 3, 0, 1,2,&ira};
t_abilita_mostro lacerazione=            {"Lacerazione", 2, 0, 1,1,&urlo};
t_abilita_mostro *abilitanonmorti=&lacerazione;
//  lupo                                                    mF mM Ty ID
t_abilita_mostro incornata=                {"Incornata", 5, 0, 0,4,NULL};
t_abilita_mostro furia=                        {"Furia", 4, 0, 0,3,&incornata};
t_abilita_mostro morso=                        {"Morso", 2, 0, 0,2,&furia};
t_abilita_mostro carica=                      {"Carica", 1, 0, 0,1,&morso};
t_abilita_mostro *abilitalupi=&carica;
//  ELMO                                               Fo In Ag Vi $$  SAV  ID
t_oggetto elmo_dragone=        {"Elmo del Dragone", 5, 0, 2,30,15,4,NULL,false,2};
t_oggetto elmo_spirituale=      {"Elmo Spirituale", 0, 5, 0,20,12,3,&elmo_dragone,false,2};
t_oggetto elmo_ossa=                {"Elmo d'ossa", 3, 3, 0,15, 9,2,&elmo_spirituale,false,2};
t_oggetto elmo_cuoio=             {"Elmo di cuoio", 3, 0, 0,10, 6,1,&elmo_ossa,false,2};
t_oggetto *elmi=&elmo_cuoio;
//  GUANTI                                             Fo In Ag Vi $$  SAV  ID
t_oggetto guanti_dragone=    {"Guanti del Dragone", 3, 0, 3,30,15,4,NULL,false,4};
t_oggetto guanti_spirituali=  {"Guanti Spirituali", 0, 3, 1,20,12,3,&guanti_dragone,false,4};
t_oggetto guanti_ossa=            {"Guanti d`ossa", 2, 2, 0,15, 9,2,&guanti_spirituali,false,4};
t_oggetto guanti_cuoio=         {"Guanti di cuoio", 2, 0, 1,10, 6,1,&guanti_ossa,false,4};
t_oggetto *guanti=&guanti_cuoio;
//  STIVALI                                            Fo In Ag Vi $$  SAV  ID
t_oggetto stivali_dragone=  {"Stivali del Dragone", 3, 0, 3,30,15,4,NULL,false,5};
t_oggetto stivali_spirituali={"Stivali Spirituali", 0, 3, 1,20,12,3,&stivali_dragone,false,5};
t_oggetto stivali_ossa=          {"Stivali d`ossa", 2, 2, 0,15, 9,2,&stivali_spirituali,false,5};
t_oggetto stivali_cuoio=       {"Stivali di cuoio", 2, 0, 1,10, 6,1,&stivali_ossa,false,5};
t_oggetto *stivali=&stivali_cuoio;
//  ARMATURA                                           Fo In Ag Vi $$  SAV  ID
t_oggetto corazza_dragone=  {"Corazza del Dragone", 6, 0, 0,60,25,4,NULL,false,3};
t_oggetto cappa_spirituale=    {"Cappa Spirituale", 0, 6, 2,10,20,3,&corazza_dragone,false,3};
t_oggetto armatura_ossa=        {"Armatura d`ossa", 3, 3, 0,15,15,2,&cappa_spirituale,false,3};
t_oggetto armatura_cuoio=     {"Armatura di cuoio", 2, 0, 4,20,10,1,&armatura_ossa,false,3};
t_oggetto *armature=&armatura_cuoio;
//  ARMA                     				           Fo In Ag Vi $$  SAV  ID
t_oggetto scudo=        				  {"Scudo", 1, 0, 0,60, 5,5,NULL,false,1};
t_oggetto alabarda=   			   	   {"Alabarda", 5, 0, 0,20, 5,4,&scudo,false,1};
t_oggetto spada=       				      {"Spada", 3, 0, 2,10, 5,3,&alabarda,false,1} ;
t_oggetto bacchetta= 				  {"Bacchetta", 0, 3, 2,10, 5,2,&spada,false,1};
t_oggetto arco=        				       {"Arco", 2, 0, 4, 0, 5,1,&bacchetta,false,1};
t_oggetto *armi=&arco;
//  CLASSE                                               Fo In Ag  Vi ID
t_classe paladino=                  {"Paladino", 5, 5, 3,100, 3,NULL};
t_classe mago=                          {"Mago", 2, 8, 4, 80, 2,&paladino};
t_classe guerriero=                {"Guerriero", 8, 2, 4, 80, 1,&mago};
personaggio protagonista={"",0,0,0,0,0,0,1,4};
//  ABILITA                                      mF  mM  $$ ID
t_abilita attacco_potente=    {"Attacco Potente",1.5,0  , 3,3,NULL};
t_abilita palla_di_fuoco=      {"Palla di Fuoco",0  ,2.5, 3,2,&attacco_potente};
t_abilita usoarma=                   {"Uso arma",1  ,0  , 0,1,&palla_di_fuoco};
t_abilita *abilitanonmago[2]={&usoarma,&attacco_potente};
t_abilita *abilitamago[2]={&usoarma,&palla_di_fuoco};
t_oggetto *arrequip[5];
struct oggetto *attuale=NULL;
struct oggetto *nuovo=NULL;
struct oggetto *start=NULL;
int main(){
	*arrequip=calloc(5,sizeof(struct oggetto));
	FILE *logo;
	if ((logo=fopen("Logo.txt","r"))==NULL){
		printf("Error! opening file");
		exit(1);
	}
	while(!feof(logo)){                  //LEGGE IL LOGO DA UN FILE .TXT
		char c;
		fscanf(logo,"%c",&c);
		printf("%c",c);
	}
    printf("\n\n[1]Nuova partita			[2]Carica salvataggio");
	int sceltainiziale;
	scanf("%d", &sceltainiziale);
	if(sceltainiziale==2){  //CARICA I DATI SALVATI
		Load();
	}else nuovapartita();   //NUOVO PARTITA
  return 0;
}

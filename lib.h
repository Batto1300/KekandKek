    //  PERSONAGGIO (non dinamica)
typedef struct pg{
	char nome[10];
	int	intelligenza;
	int forza;
	int agilita;
	int vita;
	int soldi;
	int esp;
	int lvl;
	int mana;
}personaggio;
//  CLASSE
typedef struct classe{
	char nomeclasse[20];
	int forzaclasse;
	int intelligenzaclasse;
	int agilitaclasse;
	int vitaclasse;
	int id;
	struct classe *next;
	}t_classe;
//  ABILITA
typedef struct abilita{
	char nomeabilita[20];
	float modfisico;
	float modmagico;
	int costo;
	int id;
	struct abilita *next;
	}t_abilita;

//  MOSTRI
typedef struct mostro{
	char nomemostro[30];
	int forzamostro;
	int intelligenzamostro;
	int agilitamostro;
	int vitamostro;
	int esperienza;
	int livello;
	int tipo;
	int id;
	struct mostro *next;
	}t_mostro;

struct mostro *searchID(int datrovare); //FUNZIONE
//  ABILITA_MOSTRI
typedef struct abilita_mostro{
	char nome[20];
	int modfisico;
	int modmagico;
	int tipo;
	int id;
	struct abilita_mostro *next;
	}t_abilita_mostro;
//  OGGETTO
typedef struct oggetto{
	char nome[20];
	int bforza;
	int bintelligenza;
	int bagilita;
	int bvita;
	int costo;
	int id;
	struct oggetto *next;
	int acquisto;
	int tipo;
	}t_oggetto;
//  EQUIPAGGIAMENTO
typedef struct equipaggiamento{
	int tipo;
	char nomeoggetto[25];
	int bforza;
	int bagilita;
	int bvita;
	int bintelligenza;
	int ID;
	struct equipaggiamento *next;
}t_equip;

//FUNZIONI
void fucina();
void Menu();
void Mercato();
void Mappa();
void Bacheca();
void Inventario();
void Equipaggia(int tipo, struct oggetto *daequipaggiare);
void Caratteristiche();
void Astrub();
void Esplora_Dintorni();
int Fight(struct mostro *mostro);
void Taverna();
void Drop();
void Esp(int esperienza);
void Save();
void Load();
int Dungeon_nonmorti();
int Dungeon_draghi();
void SCF();
struct oggetto *searchIDoggetto(int tipo,int ID);
struct mostro *searchIDmostro(int tipo,int ID);
struct abilita *searchIDabilita(int tipo, int ID);
struct abilita_mostro *searchIDabilitamostro(int tipo,int ID);
void nuovapartita();
void enter();


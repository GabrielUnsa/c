#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_elementos.h"

typedef struct nodo
	{
		Telemento dato;
		struct nodo* sig;
		struct nodo* ant;
	}Tnodo;
typedef Tnodo* Tptr;
typedef struct
	{
		Tptr ini;
		Tptr fin;
	}Tlista;

void crear_lista(Tlista *);
Tptr crear_nodo(void);
void agregar_nodo(Tlista *,Tptr);
void cargar_lista_rec(Tlista *);
void mostrar_lista_rec(Tptr);
void elim_pri_num_rec(Tptr *,int);
void elim_ult_num_rec(Tptr *,int);
void elim_todos_num_rec(Tptr *,int);

#endif

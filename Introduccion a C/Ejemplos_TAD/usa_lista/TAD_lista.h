#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "TAD_dato.h"

typedef struct{
	T_DATO lis[20];
	int tam;
}T_LISTA;

T_LISTA crear_lista(void);

void mostrar_lista(T_LISTA);

void inserta_uno(T_LISTA *, T_DATO , int);

void ordena_lista(T_LISTA * );

#endif

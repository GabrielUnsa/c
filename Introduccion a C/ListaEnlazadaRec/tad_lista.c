#include "tad_lista.h"
#include <stdio.h>
#include <stdlib.h>

void crear_lista(Tlista *L)
{
	L->ini=L->fin=NULL;
}
Tptr crear_nodo(void)
{
	Tptr nodo;
	nodo=(Tptr)malloc(sizeof(Tnodo));
	nodo->dato=cargar_uno();
	nodo->sig=NULL;
	return nodo;
}
void agregar_nodo(Tlista *A,Tptr nodo)
{
	if (A->ini!=NULL)
	{
		A->fin->sig=nodo;
		nodo->ant=A->fin;
	}
	else
		A->ini=nodo;
	A->fin=nodo;
}
void cargar_lista_rec(Tlista *A)
{
	int r;
	Tptr nuevo;
	nuevo=crear_nodo();
	agregar_nodo(A,nuevo);
	printf("\n ¿Ingresar otro?(1/0): ");
	scanf("%d",&r);
	if (r==1)
		cargar_lista_rec(A);
}
void mostrar_lista_rec(Tptr B)
{
	if (B!=NULL)
	{
		mostrar_uno(B->dato);
		mostrar_lista_rec(B->sig);
	}
}
void elim_pri_num_rec(Tptr *L,int num)
{
	Tptr aux;
	if (*L!=NULL)
	{
		if (ret_num((*L)->dato)==num)
		{
			aux=*L;
			*L=(*L)->sig;
			free(aux);
		}
		else
			elim_pri_num_rec(&(*L)->sig,num);
	}
}
void elim_ult_num_rec(Tptr *L,int num)
{
	Tptr aux;
	if(*L!=NULL)
	{
		if (ret_num((*L)->dato)==num)
		{
			aux=*L;
			*L=(*L)->ant;
			free(aux);
		}
		else
			elim_ult_num_rec(&(*L)->ant,num);
	}
}
void elim_todos_num_rec(Tptr *L,int num)
{
	Tptr aux;
	if ((*L!=NULL)&&(ret_num((*L)->dato)==num))
		{
			aux=*L;
			*L=(*L)->sig;
			free(aux);
		}
	elim_pri_num_rec(&(*L)->sig,num);
}

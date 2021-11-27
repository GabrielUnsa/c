#include "TAD_lista.h"
#include<stdio.h>

T_LISTA crear_lista(void){
	T_LISTA lista;
	int i;
	printf ("\n\n Ingrese cant de elementos");
	scanf("%d",&lista.tam);
	printf("\n Ingreso de los datos: ");
	for (i=1; i<=lista.tam;i++){
		lista.lis[i]=ingresa();
	}
	return(lista);
}

void mostrar_lista(T_LISTA lista){
	int i;
	printf("\n Los datos son: ");
	for (i=1; i<=lista.tam;i++){
		muestra(lista.lis[i]);
	}
}

void inserta_uno(T_LISTA * lista, T_DATO ele, int p){
	int j;
	lista->lis[0]=ele;
	j=p-1;
	while (retorna_valor(lista->lis[j])>retorna_valor(lista->lis[0])){
		lista->lis[j+1]=lista->lis[j];
		j--;
	}
	lista->lis[j+1]=lista->lis[0];
}

void ordena_lista(T_LISTA * lista){
	int i;
	for (i=2; i<=lista->tam; i++){
		inserta_uno(lista, lista->lis[i],i);
	}
}

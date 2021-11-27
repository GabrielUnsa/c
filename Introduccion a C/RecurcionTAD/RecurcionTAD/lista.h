#ifndef LISTA_H
#define LISTA_H

typedef struct{
	int lista[100];
	int tam;
}t_lista;

void ingresa_tam(t_lista *);
void carga_aleat(t_lista *);
void mostrar_lis_inv(t_lista );
int sum_ele_list(t_lista);
void ordenamiento(t_lista *);
int bus_bin(t_lista, int);

#endif

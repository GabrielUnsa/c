#include <stdio.h>
#include "tad_lista.h"

int menu (void);

int main (void)
{
	Tlista listado;
	int opcion,n;
	Tptr vector[5];
	
	
	vector[1]=crear_nodo();
	vector[2]=crear_nodo();
	
	mostrar_lista_rec(vector[1]);
	mostrar_lista_rec(vector[2]);
	
	/*crear_lista(&listado);
	cargar_lista_rec(&listado);
	mostrar_lista_rec(listado.ini);
	do
		{
			opcion=menu();
			switch (opcion)
				{
				case 1: 
					printf("Ingrese el numero que quiere eliminar: ");
					scanf("%d",&n);
					elim_pri_num_rec(&listado.ini,n);
					mostrar_lista_rec(listado.ini);
					break;
				case 2:
					printf("Ingrese el numero que quiere eliminar: ");
					scanf("%d",&n);
					elim_ult_num_rec(&listado.fin,n);
					mostrar_lista_rec(listado.ini);
					break;
				case 3:
					printf("Ingrese el numero que quiere eliminar: ");
					scanf("%d",&n);
					elim_todos_num_rec(&listado.ini,n);
					mostrar_lista_rec(listado.ini);
					break;
				case 0:
					printf("Gracias por usar Aplicaciones FABIAN SALVA Co. Adios.");
					break;
				default:
					printf("Opcion Incorrecta.Ingrese de nuevo la opcion.");
				}
		}
	while (opcion!=0);*/
	return 0;
}

int menu (void)
{
	int op;
	printf("\n1.Eliminar el primer nodo que tenga un determinado numero.");
	printf("\n2.Eliminar el ultimo nodo que tenga un determinado numero.");
	printf("\n3.Eliminar todos los nodos que tengan un determinado numero.");
	printf("\n4.Eliminar el primer nodo que tenga una determinada palabra.");
	printf("\n5.Eliminar el ultimo nodo que tenga una determinada palabra.");
	printf("\n6.Eliminar todos los nodos que tengan una determinada palabra.");
	printf("\n7.");
	printf("\n0.Salir.");
	printf("\nIngrese una opcion: ");
	scanf("%d",&op);
	return op;
}

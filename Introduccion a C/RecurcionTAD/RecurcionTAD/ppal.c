#include <stdio.h>
#include "lista.h"
#include <time.h>
#include <stdlib.h>
/*Este programa usa el TAD "lista".
El programa genera una lista de numeros entre 50 y 100 aleatoriamente.
Muestra la lista generada. La ordena usando Qsort.
La muestra nuevamente y luego pide un numero, lo busca e informa si lo encuentra o no*/

int main(void){
	t_lista lista;
	int suma;
	int bus;
	ingresa_tam(&lista);
	srand(time(NULL));
	carga_aleat(&lista);
	mostrar_lis_inv(lista);
	suma=sum_ele_list(lista);
	printf("\n\nSuma lista: %d\n",suma);
	ordenamiento(&lista);
	printf("\nLista ordenada, recuerden que la muestra invertida:\n");
	mostrar_lis_inv(lista);
	bus=(int)((rand()*(100-50))/(RAND_MAX-50));
	printf("\n\nEl elemento a buscar generado al azar es: %d",bus);
	if(bus_bin(lista,bus))
		printf("\nEl elemento esta en la lista\n");
	else
		printf("\nEl elemento no pertenece a la lista....\n");	
	return 0;
}

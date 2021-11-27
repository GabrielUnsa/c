#include <stdio.h>
#include "TAD_lista.h"

int main(void){
	T_LISTA mi_lista;
	mi_lista=crear_lista();
	mostrar_lista(mi_lista);
	printf("\n\n---------------------\n\n");
	ordena_lista(&mi_lista);
	mostrar_lista(mi_lista);
	return 0;
}

#include "TAD_dato.h"


T_DATO ingresa(void){
	T_DATO dato;
	/*printf("\n\n Ingrese un valor entero ");
	scanf("%d",&dato);
	*/
	printf("\n Ingrese primer componente ");
	scanf("%f",&dato.x);
	printf("\n Ingrese segunda componente ");
	scanf("%f",&dato.y);
	return dato;
}

void muestra(T_DATO dato){
	/*printf("\n\n Valor %d", dato);
	*/
	printf("\n\n Valor del par %6.2f , %6.2f", dato.x, dato.y);
}

T_RETORNO retorna_valor(T_DATO dato){
	/*return dato;
	*/
	return dato.x;
}


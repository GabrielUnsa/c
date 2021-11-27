#include "TAD_alumno.h"
#include <stdio.h>

int main(){
	T_ALUMNO uno, dos, tres, aux;
	uno=ingresa_alu();
	dos= ingresa_alu();
	tres= ingresa_alu();
	if (retorna_DNI(uno)>retorna_DNI(dos))
		aux=uno;
	else
		aux=dos;
	if (retorna_DNI(tres)>retorna_DNI(aux))
		aux=tres;
	
	printf("\n\n El alumno con mayor DNI es: ");
	muestra_alu(aux);
	return(0);
}

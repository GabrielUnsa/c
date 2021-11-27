#include "TAD_alumno.h"
#include <stdio.h>

int main(){
	T_ALUMNO uno, aux;
	int i,n;
	printf("Ingrese cant de alumnos ");
	scanf("%d",&n);
	aux=ingresa_alu();
	for(i=2;i<=n;i++)
	{
		uno=ingresa_alu();
		if (retorna_DNI(uno)>retorna_DNI(aux))
		aux=uno;
	}
	printf("\n\n El alumno con mayor DNI es: ");
	muestra_alu(aux);
	return(0);
}

#include <stdio.h>
#include "TAD_alumno.h"


T_ALUMNO ingresa_alu(void){
	T_ALUMNO alu;
	fflush(stdin);
	printf("\n\nIngrese apellido y nombre ");
	gets(alu.apyno);
	printf("\n Ingrese DNI (8 dígitos)");
	scanf("%ld",&alu.dni);
	printf("\n Ingrese edad ");
	scanf("%d",&alu.edad);
	return(alu);
};

void muestra_alu(T_ALUMNO alu){
	printf("\n\n Apellido y nombre %s",alu.apyno);
	printf("\n DNI %ld",alu.dni);
	printf("\n\nEdad %d",alu.edad);
};

T_DNI retorna_DNI (T_ALUMNO alu)
{
	return alu.dni;
};


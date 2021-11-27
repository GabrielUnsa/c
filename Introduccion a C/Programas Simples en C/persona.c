/* 
 * Introduccion a Tipos de Datos
 * Carga una Persona y despues lo muestra
*/
#include<stdio.h>

/*
 Persona
 * Nombre char max 30 longitud
 * DNI    numero entero
 * Edad   numero entero
*/
typedef struct{
	char nombre[30];
	int dni, edad;
}DATOS;

//Declaracion de Modulos
 void carga_persona(DATOS*);
 void muestra_dato(DATOS);

 //Programa Principal
 int main(){
	DATOS per;
	carga_persona(&per);
	muestra_dato(per);
	return 0;
 }

/*
 Este modulo carga a una persona
 @param persona por referencia
*/
void carga_persona(DATOS* d){
	printf("Ingrese el nombre\n");
	gets(d->nombre);
	fflush(stdin);
	printf("Ingrese el DNI\n");
	scanf("%i", &d->dni);
	fflush(stdin);
	printf("Ingrese la edad\n");
	scanf("%i",&d->edad);
}

/*
 Imprime en consola el valor de la variable
 @param persona por valor
*/
void muestra_dato(DATOS p){
	printf("La Edad es: %i\n", p.edad);
	printf("El DNI es: %i\n", p.dni);
	printf("El Nombre es: %s",p.nombre);
}

/*Cargar una agenda conteniendo datos de N personas y luego mostrar 
la agenda completa
Modificar el programa para mostrar los cumplea?os de todas las personas 
que nacieron en el mes ingresado por teclado
Crear un men? que permita registrar una nueva persona, dado el nombre de una 
persona, quitarla de la agenda y dado el nombre de una persona, cambiar su 
domicilio o su contacto.
Modificar la agenda para agregar a cada persona una lista de posibles 
regalos que les gustar?a recibir. Los regalos ser?n registrados en una lista 
de cadenas. Cada persona tiene una lista propia de regalos que ser? mostrado 
cuando se consulte por las personas que cumplen a?os en un mismo mes*/

#include <stdio.h>
typedef struct{
	int dia,mes,anio;
} FECHA;

typedef union {
	char telefono_fijo[9];
	char telefono_movil[10];
	char mail[20];
}CONTACTO;

typedef struct{
	char nombre[20];
	char domicilio[30];
	FECHA nacimiento;
	int tipo_contact;
	CONTACTO contac;
} DATO_P;

FECHA carga_fecha(void);
DATO_P carga_persona(void);
void carga_agenda( DATO_P [], int *);
void carga_contacto(CONTACTO *, int *);

void muestra_fecha(FECHA);
void muestra_persona(DATO_P);
void muestra_agenda( DATO_P [], int);
void muestra_contacto (CONTACTO, int);

int main() {
	int tam;
	DATO_P lista[10];
	carga_agenda(lista,&tam);
	muestra_agenda(lista,tam);
	return 0;
}

FECHA carga_fecha(void){
	FECHA fec;
	printf("\n Ingrese dia ");
	scanf("%d",&fec.dia);
	printf("\n Ingrese mes ");
	scanf("%d",&fec.mes);
	printf("\n Ingrese anio ");
	scanf("%d",&fec.anio);
	return fec;
}

DATO_P carga_persona(void){
	DATO_P pers;
	
	fflush(stdin);
	printf("\n Ingrese nombre (30 caract)");
	gets(pers.nombre);
	fflush(stdin);
	printf("\n Ingrese domicilio (40 caract)");
	gets(pers.domicilio);
	pers.nacimiento=carga_fecha();
	carga_contacto(&pers.contac, &pers.tipo_contact);
	return pers;
}

void carga_agenda( DATO_P lis[], int * n){
	int i;
	printf("\n Ingrese cant de amigos ");
	scanf("%d",n);
	for(i=1;i<=*n;i++)
		lis[i]=carga_persona();
}

void carga_contacto(CONTACTO *c, int *tipo_contac){
	
	printf("\n 1. tel fijo \n 2. tel cel \n 3. e-mail\n ingrese opcion ");
	scanf("%d",tipo_contac);
	fflush(stdin);
	switch (*tipo_contac){
	case 1: gets(c->telefono_fijo); break;
	case 2: gets(c->telefono_movil); break;
	case 3: gets(c->mail); break;
	}
}

void muestra_fecha(FECHA fec){
	printf("\n Dia %d\t mes %d\t anio%d",fec.dia,fec.mes,fec.anio);
}

void muestra_persona(DATO_P pers){
	printf("\n Nombre %s", pers.nombre);
	printf("\n Domicilio %s", pers.domicilio);
	muestra_fecha(pers.nacimiento);
	muestra_contacto(pers.contac, pers.tipo_contact);
}

void muestra_agenda( DATO_P lis[], int n){
	int i;
	for(i=1;i<=n;i++)
		muestra_persona(lis[i]);
}

void muestra_contacto(CONTACTO c, int tipo_contacto)
{
	printf("\n Dato de contacto ");
	switch (tipo_contacto){
	case 1: printf("%s",c.telefono_fijo); break;
	case 2: printf("%s",c.telefono_movil); break;
	case 3: printf("%s",c.mail); break;
	}
}

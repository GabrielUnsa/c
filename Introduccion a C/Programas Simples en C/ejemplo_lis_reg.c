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
	char nombre[30];
	char domicilio[40];
	FECHA nacimiento;
	int tipo_contact;
	CONTACTO contac;
} DATO_P;

void carga_fecha(FECHA *);
void carga_persona(DATO_P *);
void carga_agenda( DATO_P [], int *);
void carga_contacto(CONTACTO *, int *);

void muestra_fecha(FECHA);
void muestra_persona(DATO_P);
void muestra_agenda( DATO_P [], int);
void muestra_contacto (CONTACTO, int);

int main(int argc, char *argv[]) {
	int tam;
	DATO_P lista[10];
	carga_agenda(lista,&tam);
	muestra_agenda(lista,tam);
	return 0;
}

void carga_fecha(FECHA * fec){
	printf("\n Ingrese dia ");
	scanf("%d",&fec->dia);
	printf("\n Ingrese mes ");
	scanf("%d",&fec->mes);
	printf("\n Ingrese anio ");
	scanf("%d",&fec->anio);
}

void carga_persona(DATO_P * pers){
	fflush(stdin);
	printf("\n Ingrese nombre (30 caract)");
	gets(pers->nombre);
	fflush(stdin);
	printf("\n Ingrese domicilio (40 caract)");
	gets(pers->domicilio);
	carga_fecha(&pers->nacimiento);
	carga_contacto(&pers->contac, &pers->tipo_contact);
}

void carga_agenda( DATO_P lis[], int * n){
	int i;
	printf("\n Ingrese cant de amigos ");
	scanf("%d",n);
	for(i=1;i<=*n;i++)
		carga_persona(&lis[i]);
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


#include "tad_elementos.h"
#include <stdio.h>
#include <stdlib.h>

int leecad (char *cadena,int tam)
{
	int j,ret;
	char c;
	j=ret=0;
	c=getchar();
	while(c!=EOF && c!='\n' && j<=tam-1)
	{
		cadena[j]=c;
		j++;
		ret=1;
		c=getchar();
	}
	cadena[j]='\0';
	while (c!=EOF && c!='\n')
		c=getchar();
	return ret;
}
Telemento cargar_uno(void)
{
	Telemento aux;
	fflush(stdin);
	printf("\n\nIngrese un numero: ");
	scanf("%d",&aux.numero);
	fflush(stdin);
	printf("\nIngrese una palabra:\n");
	leecad(aux.cadena,50);
	return aux;
}
void mostrar_uno(Telemento aux)
{
	printf("\t%d\t%s\n",aux.numero,aux.cadena);
}
int ret_num(Telemento aux)
{
	return aux.numero;
}
char* ret_cad (Telemento *aux)
{
	return aux->cadena;
}

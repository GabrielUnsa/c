#include <stdio.h>

typedef struct 
	{
		char nombre[40];
		char pais[20];
	}persona;
typedef struct 
	{
		persona datos_persona;
		char des_deporte[30];
		int cant_medallas;
	}atleta;

const int maxfrase = 40;

void muestra_medallistas(atleta[],int, int);
void leeCad(char *,int );
void ingreso(atleta[],int *);
int cant_med_may(atleta[],int);
void muestra_datos(atleta);
void muestra_medallistas(atleta [],int, int);

int main() {
	atleta lista[30];
	int N;
	int cant_mayor;
	ingreso(lista,&N);
	cant_mayor=cant_med_may(lista,N);
	muestra_medallistas(lista,N,cant_mayor);
	return 0;
}
void leeCad(char *cadena, int tam){
	int j, m;
	m=getchar();
	if (m==EOF){
		cadena[0]='\0';
	}
	if (m=='\n'){
		j=0;
	}else {
		cadena[0]=m;
		j=1;
	}
	for(;j<tam-1 && (m=getchar())!=EOF && m!='\n';j++)
		cadena[j]=m;
	cadena[j]='\0';
	if(m != EOF && m != '\n')
		while((m=getchar())!=EOF && m!='\n');
}
void ingreso(atleta vector[],int *t){
	int i;
	printf ("\nIngrese la cantidad de atletas a cargar : ");
	scanf("%i", t); 
	for (i=1; i <=*t; i++){
		printf ("\nIngrese los datos del atleta %u : \n", i);
		printf ("\n Nombre del atleta ");
		leeCad(vector[i].datos_persona.nombre,maxfrase);
		printf ("\n Pais ");
		leeCad(vector[i].datos_persona.pais,maxfrase);
		printf ("\n Deporte ");
		leeCad(vector[i].des_deporte,maxfrase);
		printf ("\n Cantidad de medallas ");
		scanf("%i",&vector[i].cant_medallas);
	}
}
int cant_med_may(atleta vector[],int t){
	int i;
	int may;
	may=vector[1].cant_medallas;
	for (i=2; i <=t; i++){
		if(may<vector[i].cant_medallas) may=vector[i].cant_medallas;
	}
	return may;
}
void muestra_datos(atleta estructura){
	printf("\n Nombre del atleta: %s ",estructura.datos_persona.nombre);
	printf("\n Pais: %s", estructura.datos_persona.pais);
	printf("\n Deporte: %s ",estructura.des_deporte);
}
void muestra_medallistas(atleta vector[],int t, int may){
	int i;
	printf("La cantidad de medallas mayor es %i", may);
	for (i=1; i <=t; i++)
		if(may==vector[i].cant_medallas) muestra_datos(vector[i]);
}

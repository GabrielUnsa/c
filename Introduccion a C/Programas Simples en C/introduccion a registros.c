#include <stdio.h>
struct regi{
	int pri;
	float seg;
} ;

void muestra(struct regi);
void cambia (struct regi *);
struct regi carga_1(void);

int main() {
	struct regi dato;
	dato=carga_1();
	muestra(dato);
	cambia(&dato);
	muestra(dato);
	return 0;
}

struct regi carga_1(void){
	struct regi r;
	printf("\n ingrese entero");
	scanf("%i",&r.pri);
	printf("\n ingrese real");
	scanf("%f",&r.seg);
	return r;
}


void muestra(struct regi r){
	printf("\nPrimer campo, entero %i", r.pri);
	printf("\nSegundo campo, real %f", r.seg);
}

void cambia (struct regi * r){
	r->pri+=3;
	r->seg+=3;
}

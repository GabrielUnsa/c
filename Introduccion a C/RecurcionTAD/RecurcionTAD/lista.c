#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lista.h"

void ingresa_tam(t_lista *dat){
	printf("\nIngrese tamanio: ");
	scanf("%d",&dat->tam);
}
void carga_rec(int l[],int t){
	if(t>0){
		l[t]=(int)((rand()*(100-50))/(RAND_MAX-50));
		t--;
		carga_rec(l,t);
	}
}
void carga_aleat(t_lista *dat){
	carga_rec(dat->lista,dat->tam);
}

void mostrar_lis_inv(t_lista dat){
	printf("[%d]",dat.lista[dat.tam]);
	if(dat.tam>1){
		dat.tam--;
		mostrar_lis_inv(dat);
	}
}
int sum_ele_list(t_lista dat){
	int b;
	if(dat.tam==0)
		return 0;
	else{
		b=dat.lista[dat.tam];
		dat.tam--;
		return (sum_ele_list(dat) + b);
	}
}
void posisiona_pivot(int v[], int ini, int fin, int *med){
	int piv,izq,der;
	if(ini<fin){
		piv=v[ini];
		izq=ini;
		der=fin;
		while(izq<der){
			while(izq<der && piv<v[der])
				der--;
			if(izq<der){
				v[izq]=v[der];
				izq++;
			}
			while(izq<der && v[izq]<piv)
				izq++;
			if(izq<der){
				v[der]=v[izq];
				der--;
			}
		}
		v[der]=piv;
		*med=der;
	}
}
void q_sort(int v[], int ini, int fin){
	int med;
	if (ini<fin){
		posisiona_pivot(v, ini, fin, &med);
		q_sort(v,ini,med-1);
		q_sort(v,med+1,fin);
	}
}
void ordenamiento(t_lista *v){
	q_sort(v->lista,1,v->tam);
}
int bus_bin(t_lista v, int bus){
	return	bus_bin_rec(v.lista,1,v.tam,bus);
}
int bus_bin_rec(int l[], int ini, int fin, int b){
	int med;
	med=(ini+fin)/2;
	if(ini<=fin){
		if(l[med]==b)
			return med;
		else
			if(b<l[med])
				return (bus_bin_rec(l,1,med-1,b));
			else
				return (bus_bin_rec(l,med+1,fin,b));
	}
	else return 0;
}

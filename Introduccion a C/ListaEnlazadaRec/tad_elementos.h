#ifndef TAD_ELEMENTOS_H
#define TAD_ELEMENTOS_H

typedef struct
	{
		int numero;
		char cadena[50];
	}Telemento;

int leecad (char *,int);
Telemento cargar_uno(void);
void mostrar_uno(Telemento);
int ret_num(Telemento);
char* ret_cad (Telemento *);

#endif

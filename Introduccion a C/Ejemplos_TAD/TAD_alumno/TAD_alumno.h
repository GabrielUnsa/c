#ifndef TAD_ALUMNOS_H
#define TAD_ALUMNOS_H
typedef long T_DNI;

typedef struct {
	char apyno[50];
	T_DNI dni;
	int edad;
}T_ALUMNO;

T_ALUMNO ingresa_alu();
void muestra_alu(T_ALUMNO alu);
T_DNI retorna_DNI(T_ALUMNO alu);

#endif

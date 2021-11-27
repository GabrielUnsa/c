#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	//DNI del Alumno
	int DNI;
	int DNIMayor;
	int DNIMenor;
	
	//
	int FechaNacimiento; //Año de Nacimiento
	int FechaNacimientoMayor;
	int FechaNacimientoMenor;
	
	//
	float Estatura;
	float EstaturaMayor;
	float EstaturaMenor;
	
	//
	int Edades[50];
	int PosicionMayor;
	int PosicionMenor;
	
	//
	int tamEdades;
	
	//
	char Alumno[50];
	char AlumnoMayor[50];
	char AlumnoMenor[50];
	
	//
	int anoActual = 2018;
	int i;
	int contadorEstaturaRango = 0;
	int contadorEdadRango = 0;
	
	printf("Ingresame N: ");
	fflush(stdin);
	scanf("%d",&tamEdades);
	printf("\n");
	
	for(i = 1; i <= tamEdades; i++){
		printf("Ingresame Nombre del Alumno: ");
		fflush(stdin);
		scanf("%s",&Alumno);
		printf("\n");
		
		printf("Ingresame Fecha de Nacimiento: ");
		fflush(stdin);
		scanf("%d",&FechaNacimiento);
		printf("\n");
		
		printf("Ingresame DNI:  ");
		fflush(stdin);
		scanf("%d",&DNI);
		printf("\n");
		
		printf("Ingresame Estatura:  ");
		fflush(stdin);
		scanf("%f",&Estatura);
		printf("\n");
		
		Edades[i]=anoActual-FechaNacimiento; //Carga de vector
		
		if(Estatura >= 1.69 && Estatura <= 1.85){
			contadorEstaturaRango++;
		}
		
		if(Edades[i] >= 17 && Edades[i] <= 19){
			contadorEdadRango++;
		}
		
		if(EstaturaMayor < Estatura ){
			DNIMayor = DNI;
			EstaturaMayor = Estatura;
			FechaNacimientoMayor = FechaNacimiento;
			PosicionMayor = i;
			strcpy(AlumnoMayor,Alumno);
		}else{
			if(EstaturaMenor > Estatura ){
				DNIMenor = DNI;
				EstaturaMenor = Estatura;
				FechaNacimientoMenor = FechaNacimiento;
				PosicionMenor = i;
				strcpy(AlumnoMenor,Alumno);
			}
			system("cls");
		}
	}
		printf("Nombre del Alumno: %s \n",AlumnoMayor);
		printf("Edad Mayor: %d \n", Edades[PosicionMayor]);
		printf("DNI Mayor: %d \n", DNIMayor);
		printf("Fecha de Nacimiento: %d \n", FechaNacimientoMayor);
		printf("Estatura: %f \n", EstaturaMayor);
		
		printf("Nombre del Alumno: %s \n",AlumnoMenor);
		printf("Edad Menor: %d \n", Edades[PosicionMenor]);
		printf("DNI Menor: %d \n", DNIMenor);
		printf("Fecha de Nacimiento: %d \n", FechaNacimientoMenor);
		printf("Estatura: %f \n", EstaturaMenor);
		
		printf("Contador de Rango de Edades: %d \n", contadorEdadRango);
		printf("Contador de Rango de Estatura: %d \n", contadorEstaturaRango);

	return 0;
}


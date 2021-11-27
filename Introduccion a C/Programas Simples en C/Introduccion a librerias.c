//Librerias
#include <stdio.h>

//Funcion Principal
int main(int argc, char *argv[]) {
	//Declaracion de Tipo de Datos
	int intGuille; //Sin valor
	int intWal = 1; //Asignado
	//Recordemos que podemos asignar operaciones matematicas como por ejemplo la suma
	
	//Cuerpo Programa
	intGuille = intWal + 5;
	printf(" %d \n ",intGuille);
	
	/*
	Tipos de Ciclos:
	Incondicionados
	for(asignacion de la variable indice (i=0);
	la condicion (i<=intGuille);
	paso (i++) i++ aumenta i en 1
	     (i+20) i aumenta en 20){
	Cuerpo del for
	}
	Condicionados	
	while(pregunta){
	cuerpo while
	} 
	do{
	cuerpo do while
	}while(pregunta);
	
	Alternativa
	if(condicion (intGuille > 9)){
	cuerpo if
	}else{
	cuerpo else
	}
	*/
	
	//Liberacion de Memoria | Retorno de la funcion principal
	return 0;
}


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv){
	int rank,size,i,dest,ini,n=atoi(argv[1]),v=10;
	/*Inicializacion de Variables:
	rank = numero de proces		MPI_Barrier(MPI_COMM_WORLD);o(rank) que esta ejecutando
	size = tamaño de proceso que se esta ejecutando
	i = variable para movimiento en vectores
	dest = numero de proceso del destino del mensaje
	ini = numero de proceso del inicio del mensaje
	n = tamaño ingresado por consola
	start = tiempo inicial de la aplicacion
	v = cantidad de vuelta al anillo
	*/

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Status status;
  MPI_Request request;

	/*
	A = Vector A del enunciado llenado con numeros aleatorios
	B = Vactor B igual al vector A del rank-1
	X = Variable de Actualizacion
	Bloq = Variable donde guardo el tiempo
	*/
  double A[n], B[n],X,NBloq=0,Bloq=0,start,end;

	/*
	Se calcula el destino de cada mensaje y emisor del mensaje
	*/
  dest = (rank + 1) % size;
  ini = (rank + size - 1) % size;

	/*
	Inicializacion del vector A por cada proceso usando la funcion random arrojando valores
	entre 0 , 10+n pertenecientes a los reales
	*/
  for( i = 0 ; i < n ; i++ ) {
    srand((unsigned)time(NULL)+rank*size + i);
    A[i] = rand() % (10+i) + ( (float) rand() / (float) RAND_MAX);
  }

	/* No Bloqueantes*/

	/*
	Envio de mensaje del proceso 0 ademas de tomar el tiempo donde inicio la aplicacion
	*/
	MPI_Barrier(MPI_COMM_WORLD);
	start = clock();
  if( rank == 0 ){
    MPI_Isend(&A,n,MPI_DOUBLE,dest,0,MPI_COMM_WORLD,&request);
    MPI_Wait(&request, &status);
    MPI_Isend(&v,1,MPI_INT,dest,1,MPI_COMM_WORLD,&request);
    MPI_Wait(&request, &status);
  }

  do{
    MPI_Irecv(&B,n, MPI_DOUBLE, ini, 0, MPI_COMM_WORLD,&request);
		/*
		Calculo de X
		*/
    for( i = 0; i < n; i++ ) X+=(A[i]*A[i]*A[i]);
    MPI_Wait(&request, &status);

    MPI_Irecv(&v,1,MPI_INT,ini,1,MPI_COMM_WORLD,&request);
    MPI_Wait(&request, &status);

    MPI_Isend(&A,n,MPI_DOUBLE,dest,0,MPI_COMM_WORLD,&request);
		/*
		Descuento una vuelta al anillo
		*/
    if(rank == 0){
      v--;
    }
    MPI_Wait(&request, &status);

    MPI_Isend(&v,1,MPI_INT,dest,1,MPI_COMM_WORLD,&request);
		/*
		Actualizacion A[i]
		*/
    for( i = 0; i < n; i++ ) A[i] = X + B[i];
    MPI_Wait(&request, &status);

  }while( v > 0);

	/*
	Ultima Operacion realizada por el rank 0
	*/
  if( rank == 0 ){
    MPI_Irecv(&B,n, MPI_DOUBLE, ini, 0, MPI_COMM_WORLD,&request);
    for( i = 0; i < n; i++ ) X+=(A[i]*A[i]*A[i]);
    MPI_Wait(&request, &status);
    for( i = 0; i < n; i++ ) A[i] = X  + B[i];
		end = clock();
		NBloq = end - start;
  }
	/*Bloquenates*/
	v=10;
	for( i = 0 ; i < n ; i++ ) {
		srand((unsigned)time(NULL)+rank*size + i);
		A[i] = rand() % (10+i) + ( (float) rand() / (float) RAND_MAX);
	}

  /*
	Envio de mensaje del proceso 0 ademas de tomar el tiempo donde inicio la aplicacion
	*/
	MPI_Barrier(MPI_COMM_WORLD);
	start = clock();
	if( rank == 0 ){
		MPI_Send(&A,n,MPI_DOUBLE,dest,0,MPI_COMM_WORLD);
		MPI_Send(&v,1,MPI_INT,dest,1,MPI_COMM_WORLD);
	}

	do{
    MPI_Recv(&B,n, MPI_DOUBLE, ini, 0, MPI_COMM_WORLD,&status);
		MPI_Recv(&v,1,MPI_INT,ini,1,MPI_COMM_WORLD,&status);
		MPI_Send(&A,n,MPI_DOUBLE,dest,0,MPI_COMM_WORLD);

    /*
		Calculo de X
		*/
    for( i = 0; i < n; i++ ) X+=(A[i]*A[i]*A[i]);

    /*
		Actualizacion A[i]
		*/
    for( i = 0; i < n; i++ ) A[i] = X + B[i];

		/*
		Descuento una vuelta al anillo
		*/
    if(rank == 0) v--;

    MPI_Send(&v,1,MPI_INT,dest,1,MPI_COMM_WORLD);
  }while( v > 0);

	/*
	Ultima Operacion realizada por el rank 0
	*/
  if( rank == 0 ){
		MPI_Recv(&B,n, MPI_DOUBLE, ini, 0, MPI_COMM_WORLD,&status);
    for( i = 0; i < n; i++ ) X+=(A[i]*A[i]*A[i]);
    for( i = 0; i < n; i++ ) A[i] = X  + B[i];
		end = clock();
		Bloq = end - start;
		printf("Tiempo operaciones Bloqueantes es: %lf \n ", Bloq);
		printf("Tiempo operaciones No Bloqueantes es: %lf \n ", NBloq);
		printf("La Diferencia entre el bloqueante y no bloqueante es: %lf \n ", (Bloq-NBloq) );
	}
  MPI_Finalize();
  return 0;
}

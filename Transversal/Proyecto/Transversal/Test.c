#include <stdio.h>
#include <ctype.h>
#include "Lexic.h"
#include "Pars.h"
FILE *in_fp, *fopen();
int NextToken;
int error=0;
int main(){
	if((in_fp =fopen("EJERC1.in","r"))==NULL)
		printf("ERROR NO SE PUDO ABRIR EL ARCHIVO\n");
	else{
		Get();
		do{
			AToken();
			function();
		}while( NextToken!=EOF);
		if (!error)
			printf("\nEXITO!!");
	}
	return 0;
}


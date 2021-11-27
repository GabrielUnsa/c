#include <stdio.h>
#include <string.h>
#include "Pars.h"
#include "Lexic.h"
int error;
int NextToken;
char Lexeme[100];
#define T_STORAGE 6 
#define POINTER 8
#define COMA 9
void match(char cadena[100]){
	if( strcmp(Lexeme, cadena)==0)
		AToken();
	else{
		printf("Error.- se esperaba %s y se encotro %s",cadena,Lexeme);
		error = 1;
		exit(0);
	}
}

void function(){
	printf("<function>\n");
	if( NextToken == T_STORAGE)
		Storage();
	type_def();
	id();
	match("(");
	param_list();
	match(")");
	match("{");
	stmt_block();
	match("}");
}

void Storage(){
	printf("<storage>\n");
	match(Lexeme);
}

void type_def(){
	printf("<type_def>\n");
	Type();
	if( NextToken == POINTER)
		pointer();
}

void Type(){
	printf("<type>\n");
	match(Lexeme);
}

void pointer(){
	printf("<pointer>\n");
	match("*");
}

void id(){
	printf("<id>\n");
	match(Lexeme);
}
void param_list(){
	printf("<param_list>\n");
	type_def();
	id();
	while( NextToken == COMA){
		type_def();
		id();
	}
}

void stmt_block(){
	printf("<stmt_block>\n");
	match(Lexeme);
	match(";");
}





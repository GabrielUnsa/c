#include <stdio.h>
#include "parser.h"

int error;
int NextToken;
char Lexeme[100]
	
void martch(){
	if(strcmp(lexeme,cadena)==0){
		lex();
	}else{
		printf("Error-Se esperaba %s y se encontro %s\n",cadena,lexeme);
		error=1;
		exit(0);
	}
}

void storage(){
	martch(Lexeme);
} 

void stmt_block(){
	stmt();
	martch(';');
	while(nextToken=='stmt'){
		stmt();
		martch(';');
	}
}

void pointer(){
	martch('*');
	if(nextToken=='*'){
		marcth('*');
		pointer();
	}
}

void param_list(){
	type_def();
	id();
	while(nextToken=';'){
		martch(';');
		type_def();
		id();
	}
}

void type_def(){
	type();
	if(nextToken=='*'){
		martch('*');
		pointer();
	} /*Esta parte es opcional no producira error si no se ejecuta*/
}

void type(){
	martch(Lexeme);
}

void funtion(){
	if(nextToken==storage){
		storage();
	}
	type_def();
	id();
	martch('(');
	param_list();
	martch(')');
	martch('{');
	stmt_block();
	martch('}');
	printf("Fin\n")
}


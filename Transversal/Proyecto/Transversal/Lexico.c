#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Lexic.h"
int NextToken;
int ClassChar;
char Lexeme[100];
char NextChar;
int LenLex;
FILE *in_fp, *fopen();
#define LETTER 0
#define DIGITO 1
#define UNKNOWN 99

#define KEY_L 2
#define KEY_R 3
#define PARENT_L 4
#define PARENT_R 5
#define T_STORAGE 6
#define T_TYPE 7
#define POINTER 8
#define COMA 9
#define PUNTO_COMA 10
#define IDENT 11
#define MAXLON 80

char storage[10][MAXLON +1] = {"auto", "register", "static", "extern", "typedef"};
char type[10][MAXLON +1] = {"void", "char", "short", "int", "long", "float", "double", "signed", "unsigned"};

void borrarblancos(){
	while(isspace(NextChar))
		getchar();
}

void Getchar(){
	if((NextChar = getc(in_fp))!= EOF){
		if(isalpha(NextChar))
			ClassChar = LETTER;
		else{
			if(isdigit(NextChar))
				ClassChar = DIGITO;
			else
				ClassChar = UNKNOWN;
		}
	}
	else
		ClassChar = EOF;
}

void addchar(){
	if(LenLex<=98){
		Lexeme[LenLex++] = NextChar;
		Lexeme[LenLex] = 0;
	}
	else
		printf("Error el lexema es muy largo \n");
}


int TokenUnitario(char caracter){
	
	switch(caracter){
		addchar();
	case '{':
		NextToken = KEY_L;
		break;
	case '}':
		NextToken = KEY_R;
		break;
	case '(':
		NextToken = PARENT_L;
		break;
	case ')':
		NextToken = PARENT_R;
		break;
	case ';':
		NextToken = PUNTO_COMA;
		break;
	case ',':
		NextToken = COMA;
		break;
	case '*':
		NextToken = POINTER;
		break;
	default:
		NextToken = EOF;
		break;
	}
	return NextToken;
}




int AsignarToken(){
	int i = 0;
	LenLex = 0;
	borrarblancos();
	switch(ClassChar){
	case LETTER:
		addchar();
		Getchar();
		while(ClassChar == LETTER || ClassChar == DIGITO){
			addchar();
			Getchar();
		}
		while(i<=4 && strcmp(Lexeme, storage[i])!=0)
			i++;
		if(i<=4)
			NextToken = T_STORAGE;
		else{
			i=0;
			while(i<=8 && strcmp(Lexeme, type[i])!=0)
				i++;
			if(i<=8)
				NextToken = T_TYPE;
			else
				NextToken = IDENT;
		}
		break;
	case UNKNOWN:
		TokenUnitario(NextChar);
		Getchar();
		break;
	case EOF:
		Lexeme[0] = 'E';
		Lexeme[1] = 'O';
		Lexeme[2] = 'F';
		Lexeme[3] = 0;
		break;
	}
	printf("EL SIGUIETE TOKEN ES %d, EL SIGUIENTE LEXEMA ES %s",NextToken, Lexeme);
	return NextToken;
}


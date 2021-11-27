#include <stdio.h>
#include <ctype.h>
/*variables globales*/

int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int i;
int token;
int nextToken;
/*prototipos*/
int lookup(char ch);
void addChar();
void getChar();
void getNonBlank();
int lex();
/*clases de caracteres*/
#define LETTER 0
#define MAXLON 80
#define DIGIT 1
#define UNKNOWN 99
/*código de tokens*/
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26
FILE *in_fp, *fopen();
char storge[15] [MAXLON+1]={"auto","register","static","extern","typedef"};
char types[15] [MAXLON+1]={"void","char","short","int","long","float","double","signed","unsigned"};
	
int main(int argc, char *argv[]) {
	if ((in_fp=fopen("front.in","r"))==NULL)
		printf("ERROR - No se pudo abrir el archivo front.in\n");
	else
	{
		getChar();
		do {
			lex();
		} while (nextToken != EOF);
	}
	return 0;
}
int lookup(char ch){
	switch(ch){
	case '(':
		addChar();
	nextToken=LEFT_PAREN;
	break;
	case ')':
		addChar();
	nextToken=RIGHT_PAREN;
	break;
	case '+':
		addChar();
	nextToken=ADD_OP;
	break;
	case '-':
		addChar();
	nextToken=SUB_OP;
	break;
	case '*':
		addChar();
	nextToken=MULT_OP;
	break;
	case '/':
		addChar();
	nextToken=DIV_OP;
	break;
	default:
		addChar();
		nextToken=EOF;
		break;
	}
	return nextToken;
}
void addChar(){
	if (lexLen<=98) {
		lexeme[lexLen++]=nextChar;
		lexeme[lexLen]=0; /*asigna el código ascii 0 correspondiente al caracter nulo*/
	} else printf("Error lexema muy largo\n");
}
void getChar(){
	if ((nextChar = getc(in_fp))!=EOF){
		if (isalpha(nextChar))
			charClass=LETTER;
		else
			if (isdigit(nextChar))
				charClass=DIGIT;
			else charClass=UNKNOWN;
	} else charClass=EOF;
}
void getNonBlank(){
	while (isspace(nextChar))
		getChar();
}
int lex(){
	lexLen = 0;
	getNonBlank();
	switch (charClass) {
	case LETTER:
		addChar();
		getChar();
		while (charClass==LETTER || charClass==DIGIT){
			addChar();
			getChar();
		}
		nextToken=IDENT;
		break;
	case DIGIT:
		addChar();
		getChar();
		while (charClass==DIGIT){
			addChar();
			getChar();
		}
		nextToken=INT_LIT;
		break;
	case UNKNOWN:
		lookup(nextChar);
		getChar();
		break;
	case EOF:
		nextToken=EOF;
		lexeme[0]='E';
		lexeme[1]='O';
		lexeme[2]='F';
		lexeme[3]=0;
		break;
	}
	i=0;
	while(i<3){
		if(strcmp(lexeme,storge[i])==0 || strcmp(lexeme,types[i])==0){
			if(strcmp(lexeme,storge[i])==0){
				printf("El token pertenece a lexema\n");
			}else{
				printf("El token pertenece a type\n");
			}
		}
		i++;
	}
	return nextToken;
}
	

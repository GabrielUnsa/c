#ifndef TAD_DATO_H
#define TAD_DATO_H
/*typedef int T_DATO ;
typedef int T_RETORNO;
*/
typedef struct {
	float x,y;
}T_DATO ;

typedef float T_RETORNO;

T_DATO ingresa(void);

void muestra(T_DATO);

T_RETORNO retorna_valor(T_DATO);
#endif

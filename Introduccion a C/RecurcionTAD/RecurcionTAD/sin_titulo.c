#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int goles(int);
int aleatorio();
int cuenta();
int main() {
	int b,g;
	g=2;
	b=goles(g);
	printf("b=%d\n",b);
	return 0;
}

int goles(int t){
	if(t>1){
		printf("%d\n ",cuenta());
		return (goles(t-1)+cuenta());
	}else{
		return 0;
		
		}
}
int cuenta(){
	int c;
	c=aleatorio();
	printf("c=f %d\n",c);
	if (c<25){
		return 1;
	}else
		return 0;
}
int aleatorio(){
	int f;
	f=(rand()%100);
	printf ("f de rand: %d\n",f);
	scanf("%d",&f);
	return f;
}

/*
 ============================================================================
 Name        : VehCount.c
 Author      : Julianchito
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Se declara fuera para que todos la puedan utilizar
//es una variable global
struct Coche {
	char matricula[7];
	char marca[50];
	char modelo[50];
	int cv;
};

int main(void) {
	int i;
	int num = 3;
	struct Coche taller[num];
	for(i = 0; i<num; i++){
		printf("Introduce los datos del coche %d", i+1);
		printf("\nMatricula: ");
		gets(taller[i].matricula);
		printf("\nMarca: ");
		gets(taller[i].marca);
		printf("\nModelo: ");
		gets(taller[i].modelo);
		printf("\nCv: ");
		scanf("%d", &taller[i].cv);
		setbuf(stdin,NULL);
	}

	ordenar(taller);

	for(i = 0; i<num; i++){
		printf("%s %s %s %d\n", taller[i].matricula, taller[i].marca, taller[i].modelo, taller[i].cv);
	}
	return EXIT_SUCCESS;
}

int size(struct Coche taller[]){
	return sizeof(taller)/sizeof(taller[0]);
}//fin de size

/**
 * devuelve la posicion dentro del array o -1 si no lo encuentra
 */
int buscar(struct Coche taller[], char matricula[]){
	int i = 0;
	do{
		if(strcasecmp(matricula, taller[i].matricula) == 0)	return i;
	}while(++i<size(taller));
	return -1;
}

/**
 * devuelve
 * 0 ok
 * 1 no hay lugar
 * 2 ya existe
 */
int insertar(struct Coche taller[], struct Coche tutu){
	return 0;
}

void ordenar(struct Coche taller[]){
 int i,j;
 for (i = 0; i < 2; ++i) {
	 for (j = i+1; j < 3; ++j) {
		if(strcasecmp(taller[i].matricula , taller[j].matricula) > 0){
			struct Coche aux = taller[i];
			taller[i] = taller[j];
			taller[j] = aux;
		}
	}
  }
}

/**
 * devuelve
 * 0 ok
 * 1 no existe
 */
int borrar(struct Coche taller[], char matricula[]){
	return 0;
}

void imprimir(struct Coche taller[], char matricula[]){

}

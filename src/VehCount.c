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
	char matricula[70];
	char marca[50];
	char modelo[50];
	int cv;
};

int main(void) {
	setbuf(stdout,NULL);
	int i, num;
	printf("Inserte el tamaño del garage:");
	scanf("%d", &num);
	setbuf(stdin,NULL);
	//num = 5;
	struct Coche taller[num];
	//Llena de espacios vacios todas las partes
	for(i = 0; i<num; i++){
	    strcpy(taller[i].marca, "");
	    strcpy(taller[i].matricula, "");
	    strcpy(taller[i].modelo,"");
	    taller[i].cv = 0;
	}

	/*
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
	*/
	struct Coche nuevoCoche;
	nuevoCoche.cv = 5;
    strcpy(nuevoCoche.marca, "Opel");
    strcpy(nuevoCoche.matricula, "AAA");
    strcpy(nuevoCoche.modelo,"Astra");
   /*
	printf("Introduce los datos del coche");
	printf("\nMatricula: ");
	gets(taller[0].matricula);
	printf("\nMarca: ");
	gets(taller[0].marca);
	printf("\nModelo: ");
	gets(taller[0].modelo);
	printf("\nCv: ");
	scanf("%d", &taller[0].cv);
	setbuf(stdin,NULL);
*/
	insertar(taller, num, nuevoCoche);

	nuevoCoche.cv = 8;
    strcpy(nuevoCoche.marca, "Fiat");
    strcpy(nuevoCoche.matricula, "Gato");
    strcpy(nuevoCoche.modelo,"600");

    //meterDatos(nuevoCoche);
    insertar(taller, num, nuevoCoche);
    ordenar(taller, num);
    printf("quedan %d lugares \n", espacioLibre(taller, num));
	for(i = 0; i<num; i++){
		printf("%s %s %s %d\n", taller[i].matricula, taller[i].marca, taller[i].modelo, taller[i].cv);
	}


	borrar(taller, num, "AAA");
    printf("--------------\n");
	for(i = 0; i<num; i++){
		printf("%s %s %s %d\n", taller[i].matricula, taller[i].marca, taller[i].modelo, taller[i].cv);
	}
    printf("--------------\n");
	printf("quedan %d lugares \n", espacioLibre(taller, num));
	return EXIT_SUCCESS;
}

/*
 * Funcion que nunca funcionó, pasamos el tamaño como parámetro a todas las
 * funciones que lo necesiten
 */
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
 * devuelve: 0 ok; 1 no hay lugar; 2 ya existe
 */
int insertar(struct Coche taller[], int tamArray, struct Coche tutu){
	int i;
	if(buscar(taller, tutu.matricula)!=-1)
		return 2;
	for(i = 0; i < tamArray; i++){
		if(strcasecmp("", taller[i].matricula) == 0){
			taller[i] = tutu;
			return 0;
		}
	}
	return 1;
}

void ordenar(struct Coche taller[], int tamaArray){
 int i,j;
 for (i = 0; i < tamaArray-1; ++i) {
	 for (j = i+1; j < tamaArray; ++j) {
		if(strcasecmp(taller[i].matricula , taller[j].matricula) > 0){
			struct Coche aux = taller[i];
			taller[i] = taller[j];
			taller[j] = aux;
		}
	}
  }
}// fin ordenar

/**
 * devuelve: 0 ok ó 1 no existe
 */
int borrar(struct Coche taller[], int tamaArray, char matricula[]){
	int i;
	for(i = 0; i < tamaArray; i++){
			if(strcasecmp(matricula, taller[i].matricula) == 0){
			    strcpy(taller[i].marca, "");
			    strcpy(taller[i].matricula, "");
			    strcpy(taller[i].modelo,"");
			    taller[i].cv = 0;
				return 0;
			}
		}
	return 1;
}// fin borrar

void imprimir(struct Coche taller[], int tamaArray, char matricula[]){
	int i;
	for(i = 0; i < tamaArray; i++){
				if(strcasecmp(matricula, taller[i].matricula) == 0){
					printf("%s %s %s %d", taller[i].marca,
							taller[i].matricula,
							taller[i].modelo,
							taller[i].cv);
				}//fin del if
	}//fin del for
}//fin de imprimir

int espacioLibre(struct Coche taller[], int tamaArray){
	int i;
	int cuenta = 0;
	for(i = 0; i < tamaArray; i++){
				if(strcasecmp("", taller[i].matricula) == 0){
					cuenta++;
				}
	}
	return cuenta;
}//fin de espacioLibre
/*
 struct Coche meterDatos(){
	struct Coche miTutu;
	printf("Introduce los datos del coche");
	printf("\nMatricula: ");
	gets(miTutu.matricula);
	printf("\nMarca: ");
	gets(miTutu.marca);
	printf("\nModelo: ");
	gets(miTutu.modelo);
	printf("\nCv: ");
	scanf("%d", &miTutu.cv);
	setbuf(stdin,NULL);
	return miTutu;
}
*/

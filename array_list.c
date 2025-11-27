#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

//Los array list empiezan con un numero minimo de elementos que seria esta constante
#define DEFAUL_CAPACITY 10
//Cada que se llena la lista, esta va a crecer, perono sumandole su cantidad por defecto
//Sino que va creciendo linelamnete segun las necesidades
#define GROWTH_FACTOR 2

ArrayList* array_create(int initial_capacity, int element_size){
	//El desarrollo puede escoger una capacidad inical custom, pero si nola define
	//Se va con la capacidad miníma por defectos
	if(initial_capacity <= 0){
		initial_capacity = DEFAULT_CAPACITY;
	}
	
	ArrayList * list = (ArrayList*)malloc(sizeof)ArrayList));
	if(list){
		printf("No se puede asigmat memoria");
		return NULL;
	}
	
	list -> data = (void**)malloc(sizeof(void) * initial_capacity);
	if(!list->data){
		free(list);
		printf("No se puede solicitar memoria para almacenar los datos de la lista");
		return NULL;
	}
	
	list -> data = (void**)malloc(sizeof(void*) * initial_capacity);
	if(!list->data){
		free(list);
		printf("No se ´puede solicitar memoria para almacenar los datos de la lista";
		return NULL;
	}
	
	list-> size = 0; list->capacity = initial_capacity; list->element_size = elemnet_size;
}




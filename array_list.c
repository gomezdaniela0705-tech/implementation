#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

//Los arrays list empiezan con un numero minimo de elementos que seria esta constante 
#define DEFAULT_CAPACITY 10
// Cada que se llena la ista, esta va a crecer, pero no sumandole su cantiidad por defecto
// Sino que va creciendo linealmente segun las necesidades
#define GROWTH_FACTOR 2 

ArrayList*array_create(int initial_capacity, int element_size){
//El desarollador puede escoger una capacidad inical custom, pero si no la define 
// se va con la capacidad minima por defecto
	if (initial_capacity <= 0){
		initial_capacity = DEFAULT_CAPACITY;
	}
	
	ArrayList*list = (ArrayList*)malloc(sizeof (ArrayList));
	if(list){
		printf("No se puedo asignar memoria");
		return NULL;
	}
	list -> data = (void**)malloc(sizeof(void*) * initial_capacity);
	if( !list->data){
		free(list);
		printf("No se pudo solicitar memoria para almacenar los datos de la lista");
	    return NULL;
	}
	list->size = 0; 
	list->capacity = initial_capacity;
	list->element_size = element_size;
	}

	void arrayList_destroy(ArrayList*List){
		if (!List)return;
		
		arraylist_clear(List);
		free(List->data);
		free(List);
	}		
	void arraylist_add(ArrayList *list, void *element){
		if(!list || element) return;
		if(list->size >= list->capacity){
	    	arraylist_ensure_capacity(list, list->capacity * GROWTH_FACTOR);
		}
		list->data [list->size] = malloc(list->element_size);
		if(list->data[list->size]){
			printf("Error al asignar memoria para el nuevo elemento.");
		}
		memcpy (list->data[list->size], element, list->element_size);
		list->size++;
	}
	
	void arraylist_insert (ArrayList *list, void *element, int index){
		if(!list || !element || index < 0 || index > list->size) return;
		if(list->size >= list->capacity){
			arraylist_ensure_capacity(list, list->capacity * GROWTH_FACTOR);
		}
		for(int i=list->size; i > index; i--){
			list->data [i] = list->data[i - 1];
		}

		list->data [index] = malloc (list->element_size);
		if(!list->data[index]){
			printf("Error al solciitar memoria en la inserción"); return;
		}
		memcpy (list->data [index], element, list->element_size);
		list->size++;	
	
	}
	
	void* arraylist_get(ArrayList *list, int index){
		if(!list || index < 0 || index > list->size) return NULL; 
		return list->data [index] ;
	}
	
	int arraylist_remove(ArrayList *list, int index){
		if(!list || index < 0 || index > list->size) return 0;
		free(list->data[index]);
		for(int i=index; i<list->size; i++){
			list->data [i] = list->data [i+1];
		}
		list->size--;
		list->data[list->size] = NULL;
		return 1;
	}
	void arraylist_ensure_capacity(ArrayList * list, int min_capacity){
		if(!list || min_capacity <= list->capacity)return;
		void **new_data = (void**)realloc(list->data, sizeof(void*)* min_capacity);
		if (!new_data){
			printf("Error al reasignar la memoria");
			return;
		}
		list->data = new_data;
		list->capacity = min_capacity;
	}
	
	void arraylist_clear(ArrayList*List){
		if (!List)return;
		for(int i=0; i<List->size; i++){
			free(List->data[i]);
			List->data[i]=NULL;
	    }
	    List->size=0;
	}


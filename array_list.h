#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct{
	void **data;  // Aqui se almacenan los elementos genericos
	int size;    // Numero de elementos que tiene la lista almacenados
	int capacity;  // Capacidad maxima de objetos que tiene la lista
	int element_size; // Tamano en bytes de cada elemento
} ArrayList;

// Crear o borrar lista
ArrayList* arraylist_create(int initial_capacity, int element_size);
void arraylist_clear(ArrayList *list);
void arraylist_destroy(ArrayList *list);

// Operaciones basicas
void arraylist_add(ArrayList *list, void *element);
void arraylist_insert(ArrayList *list, void *element, int index);
void *arraylist_get(ArrayList *list, int index);   
int arraylist_remove(ArrayList *list, int index);

// Funciones para manipular memoria
void arraylist_ensure_capacity(ArrayList *list, int min_capacity);
void arraylist_trim_to_size(ArrayList *list);
ArrayList* arraylist_clone(ArrayList *list);

#endif


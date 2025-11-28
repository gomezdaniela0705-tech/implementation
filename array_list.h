#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct{
	void **data; //Aqui se almacenan los elementos genericos
	int size; //Numero de elementos que tiene la lista almacenados
	int capacity; //Capacidad maxima de objetos que tiene la lista
	int element_size; //Tamano en byts de cada elemento
}ArrayList;

//crear o borrar lista
ArrayList* arraylist_create(int initial_capacity, int element_size);
void arraylist_destroy(ArrayList *list);

//Operaciones basicas que toda lista debe llevar
void arraylist_add(ArrayList *list, void *element);//Agrega un elemento al final de la lista
void arraylist_insert(ArrayList *list, void *element,int index);//Agrega un elemento en la posicion
void *arrraylist_get(ArrayList *list, int index);
int arraylist_remove(ArrayList *list, int index);//Se quita el elemento en la posicion index
void arraylist_clear(ArrayList *list);//Se borra todos los elementos de la lista

//Funciones usadas para manipular los arreglos dinamicos
void arraylist_ensure_capacity(ArrayList *list, int min_capacity);//Pide mas memoria si se esta llenando
void arraylist_trim_to_size(ArrayList *list);//Ajusta el tamano dinamico al usuario por los elementos
ArrayList* arraylist_clone(ArrayList *list);//Nos sirve para copiar una lista a otra


#endif



#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct{
	void **data; //Aqui se almacenan los elementos genéricos
	int size; //Numero de elemntos que tiene la lista almacenados
	int capacity; //Capacidad maxima de objetos que tiene la lista
	int element_size; //Tamaño en byts de cada elemento
}ArrayList;

//crear o borrar lista
ArrayList* arrayList_create(int initia_capacity, int element_size);
void arrayList_destroy(ArrayList *list);

//Operaciones básicas que toda lista debe llevar
void arrayList_add(ArrayList *list, void *element);//Agrega un elemto al final de la lista
viod arrayList_insert(ArrayList *list, void *elemnt,int index);//Agrega un elemnto en la posición
void *arrrayList_get(ArrayList *list, int index);
int arraylist_remove(ArrayList *list, int index);//Se quita el elemnto en la posición index
void arraylist_clear(ArrayList *list);//Se borra todos los elemtos de la lista

//Funciones usadas para manipular los arreglos dinamicos
void arraylist_ensure_capacity(ArrayList *list, int min_capacity);//Pide mas memoria si se esta llenando
void arratlist_trim_to_size(ArrayList *list);//Ajusta el tamaño dinamico al usuariompor los elementos
ArrayList* arraylist_clone(Array *list);//Nos sirve para copiar una lista a otra


#endif

)




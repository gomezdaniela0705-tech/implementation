#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

int main() {
	printf("=== Demostracion de ArrayList ===\n\n");
	
	printf("Creando myArrayList con capacidad inicial de 3...\n");
	ArrayList *myArrayList = arraylist_create(3, sizeof(int));
	
	if (!myArrayList) {
		printf("Error al crear la lista\n");
		return 1;
	}
	printf("Lista creada exitosamente. Capacidad: %d, Size: %d\n\n", 
		   myArrayList->capacity, myArrayList->size);
	
	printf("Agregando elementos a la lista...\n");
	
	int elemento1 = 10;
	int elemento2 = 20;
	int elemento3 = 30;
	int elemento4 = 40;
	
	arraylist_add(myArrayList, &elemento1);
	printf("Agregado elemento: %d (size: %d)\n", elemento1, myArrayList->size);
	
	arraylist_add(myArrayList, &elemento2);
	printf("Agregado elemento: %d (size: %d)\n", elemento2, myArrayList->size);
	
	arraylist_add(myArrayList, &elemento3);
	printf("Agregado elemento: %d (size: %d)\n", elemento3, myArrayList->size);
	
	arraylist_add(myArrayList, &elemento4);
	printf("Agregado elemento: %d (size: %d, capacidad: %d)\n", 
		   elemento4, myArrayList->size, myArrayList->capacity);
	
	
	int elemento5 = 25;
	arraylist_insert(myArrayList, &elemento5, 2);
	printf("Insertado elemento %d en posicion 2 (size: %d)\n\n", elemento5, myArrayList->size);
	
	
	printf("Lista completa:\n");
	for (int i = 0; i < myArrayList->size; i++) {
		int valor = (int)arraylist_get(myArrayList, i);
		if (valor) {
			printf("  Posicion %d: %d\n", i,*valor);
		}
	}
	printf("\n");
	
	
	printf("Obteniendo elemento en posicion 2...\n");
	int elemento_obtenido = (int)arraylist_get(myArrayList, 2);
	if (elemento_obtenido) {
		printf("Elemento en posicion 2: %d\n\n", *elemento_obtenido);
	}
	
	
	printf("Removiendo 2 elementos...\n");
	printf("Removiendo elemento en posicion 1...\n");
	arraylist_remove(myArrayList, 1);
	printf("Removiendo elemento en posicion 2...\n");
	arraylist_remove(myArrayList, 2);
	printf("Size despues de remover: %d\n\n", myArrayList->size);
	
	
	printf("Lista despues de remover elementos:\n");
	for (int i = 0; i < myArrayList->size; i++) {
		int valor = (int)arraylist_get(myArrayList, i);
		if (valor) {
			printf("  Posicion %d: %d\n", i, *valor);
		}
	}
	printf("\n");
	
	
	printf("Destruyendo la lista...\n");
	arraylist_destroy(myArrayList);
	printf("Lista destruida exitosamente.\n\n");
	
	printf("=== Fin de la demostracion ===\n");
	
	return 0;
}


#include "cuadruplas.h"

typedef struct index INDEX;

struct index{
	char *indice;
	INDEX *next;
};

typedef struct list_index{
	INDEX *head;
	INDEX *tail;
}LINDEX;

INDEX *init_index(); // Reserva memoria para un nodo de �ndice

void finish_index(INDEX *i); // Libera la memoria de un nodo �ndice

LINDEX *init_list_index(INDEX *i); // Reserva memoria para la lista de �ndices e inserta el primero

void finish_list_index(CODE *c); // Libera la memoria de la lista y de todos los nodos dentro

void append_index(LINDEX *l, INDEX *i); // Agrega un nodo �ndice al final de la lista

LINDEX *combinar(LINDEX l1, LINDEX l2); // Retorna una lista ligada de la concatenaci�n de l1 con l2

void backpatch(CODE *c, LINDEX l, char *label); // Reemplaza label en cada aparici�n de un �ndice en las cu�druplas del c�digo c

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

INDEX *init_index(); // Reserva memoria para un nodo de índice

void finish_index(INDEX *i); // Libera la memoria de un nodo índice

LINDEX *init_list_index(INDEX *i); // Reserva memoria para la lista de índices e inserta el primero

void finish_list_index(CODE *c); // Libera la memoria de la lista y de todos los nodos dentro

void append_index(LINDEX *l, INDEX *i); // Agrega un nodo índice al final de la lista

LINDEX *combinar(LINDEX l1, LINDEX l2); // Retorna una lista ligada de la concatenación de l1 con l2

void backpatch(CODE *c, LINDEX l, char *label); // Reemplaza label en cada aparición de un índice en las cuádruplas del código c

#include "cuadruplas.h"

CUAD *init_quad(){
	CUAD *quad = (CUAD*) malloc(sizeof(CUAD));
	quad->arg1 = NULL;
	quad->op = NULL;
	quad->arg1 = NULL;
	quad->arg2 = NULL;
	quad->res = NULL;
	quad->next = NULL;
	return quad;
} // Reserva memoria para una cuádrupla

void finish_quad(CUAD *cuad){
	free(cuad);
} // Libera la memoria de una cuádrupla

CODE *init_code(){
	CODE *cod = (CODE*) malloc(sizeof(CODE));
	cod->head = NULL;
	cod->tail = NULL;
	return cod;
} // Reserva memoria para el código

void finish_code(CODE *cod){
	free(cod);
} // Libera la memoria de la lista ligada del código

void append quad(CODE* cod, CUAD *quad){
	if(cod->head == NULL){ // Si cod está vacía
		cod->head = quad; // Todavía no hay tail, el next de head sigue siendo nulo
		cod->head->next = NULL;
	}
	else{
		if(cod->tail == NULL){ // Si hay un elemento en la tabla
			cod->tail = quad; // El nuevo se convierte en tail
			cod->head->next = cod->tail; // El nuevo elemento es el siguiente del que había
			cod->tail->next = NULL;
		}
		else{
			CUAD *current = cod->head; // Si hay más de 1 elemento comienzo a recorrer la tabla
			while(current->next != cod->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}
			CUAD *copy = cod->tail; // Copio a tail
			current->next = copy; // El penúltimo ahora apunta a la copia de tail
			cod->tail = quad; // Ahora el último será el símbolo nuevo
			copy->next = cod->tail; // El siguiente del que era tail es el valor nuevo
			cod->tail->next = NULL;
		}
	}
} // Agrega una cuádrupla al final de la lista

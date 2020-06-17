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
} // Reserva memoria para una cu�drupla

void finish_quad(CUAD *cuad){
	free(cuad);
} // Libera la memoria de una cu�drupla

CODE *init_code(){
	CODE *cod = (CODE*) malloc(sizeof(CODE));
	cod->head = NULL;
	cod->tail = NULL;
	return cod;
} // Reserva memoria para el c�digo

void finish_code(CODE *cod){
	free(cod);
} // Libera la memoria de la lista ligada del c�digo

void append quad(CODE* cod, CUAD *quad){
	if(cod->head == NULL){ // Si cod est� vac�a
		cod->head = quad; // Todav�a no hay tail, el next de head sigue siendo nulo
		cod->head->next = NULL;
	}
	else{
		if(cod->tail == NULL){ // Si hay un elemento en la tabla
			cod->tail = quad; // El nuevo se convierte en tail
			cod->head->next = cod->tail; // El nuevo elemento es el siguiente del que hab�a
			cod->tail->next = NULL;
		}
		else{
			CUAD *current = cod->head; // Si hay m�s de 1 elemento comienzo a recorrer la tabla
			while(current->next != cod->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}
			CUAD *copy = cod->tail; // Copio a tail
			current->next = copy; // El pen�ltimo ahora apunta a la copia de tail
			cod->tail = quad; // Ahora el �ltimo ser� el s�mbolo nuevo
			copy->next = cod->tail; // El siguiente del que era tail es el valor nuevo
			cod->tail->next = NULL;
		}
	}
} // Agrega una cu�drupla al final de la lista

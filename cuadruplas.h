typedef struct cuad QUAD;

struct cuad{
	char *op;
	char *arg1;
	char *arg2;
	char *res;
	CUAD *next;
};

typedef struct code{
	CUAD *head;
	CUAD *tail;
}CODE;

CUAD *init_quad(); // Reserva memoria para una cu�drupla

void finish_quad(QUAD *c); // Libera la memoria de una cu�drupla

CODE *init_code(); // Reserva memoria para el c�digo

void finish_code(CODE *c); // Libera la memoria de la lista ligada del c�digo

void append quad(CODE* c, CUAD *cd); // Agrega una cu�drupla al final de la lista

#include "cola.h"
#include "lista.h"

const int PRIMERA_POSICION = 0;

cola_t *cola_crear()
{
	cola_t *cola = (cola_t *)lista_crear();

	if (!cola){
		free(cola);
		return NULL;
	}
	
	return cola;

}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	if (!cola)
		return NULL;

	return (cola_t *)lista_insertar((lista_t *)cola, elemento);
}

void *cola_desencolar(cola_t *cola)
{
	if (!cola)
		return NULL;
	
	return lista_quitar_de_posicion((lista_t *)cola,PRIMERA_POSICION);
}

void *cola_frente(cola_t *cola)
{
	if (!cola)
		return NULL;
	
	return lista_elemento_en_posicion((lista_t *)cola,PRIMERA_POSICION);

}

size_t cola_tamanio(cola_t *cola)
{
	if (!cola)
		return 0;

	return lista_tamanio((lista_t *)cola);
}

bool cola_vacia(cola_t *cola)
{
	if (!cola) 
		return false;

	return lista_vacia((lista_t *)cola);
}

void cola_destruir(cola_t *cola)
{
	lista_destruir((lista_t *)cola);
}
#include "pa2m.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdlib.h>
#include <stdbool.h>

void crear_la_lista()
{
	lista_t *lista;

	lista = lista_crear();
	pa2m_afirmar(lista != NULL, "La lista se creo con exito");

	lista_destruir(lista);
}

void pruebas_para_insertar_en_la_lista()
{
	lista_t *lista;

	lista = lista_crear();
	lista = lista_insertar(lista, (void *)3);

	pa2m_afirmar(lista != NULL && lista_tamanio(lista) == 1,
		     "Se agrego bien");

	lista_destruir(lista);
}

void insertar_un_elemento_en_la_posicion_indicada()
{
	lista_t *lista;

	lista = lista_crear();
	lista = lista_insertar(lista, (void *)1);
	lista = lista_insertar(lista, (void *)2);
	lista = lista_insertar(lista, (void *)3);
	lista = lista_insertar_en_posicion(lista, (void *)2, 6);

	pa2m_afirmar(lista != NULL && lista_tamanio(lista) == 4,
		     "Se inserto bien en la posicion deseada");

	lista_destruir(lista);
}

void quitar_elemento_de_la_ultima_posicion()
{
	lista_t *lista;

	lista = lista_crear();
	lista = lista_insertar(lista, (void *)3);
	lista = lista_insertar(lista, (void *)"BOOOCAA");
	lista = lista_insertar(lista, (void *)2);

	pa2m_afirmar(lista != NULL && lista_quitar(lista) == (void *)2,
		     "Devuelve bien el ultimo elemento");

	lista_destruir(lista);
}

void quitar_elemento_de_la_posicion_elegida()
{
	lista_t *lista;

	lista = lista_crear();
	lista_insertar(lista, (void *)0);
	lista_insertar(lista, (void *)1);
	lista_insertar(lista, (void *)2);

	pa2m_afirmar(lista != NULL &&
			     lista_quitar_de_posicion(lista, 0) == (void *)0,
		     "Devuelve bien el elemento de la posicion eliminada");

	lista_destruir(lista);
}

void devolver_elemento_de_la_posicion_elegida()
{
	lista_t *lista;

	lista = lista_crear();
	lista = lista_insertar(lista, (void *)0);
	lista = lista_insertar(lista, (void *)1);
	lista = lista_insertar(lista, (void *)"BOCA");

	pa2m_afirmar(lista != NULL && lista_elemento_en_posicion(lista, 2) ==
					      (void *)"BOCA",
		     "Devuelve bien el elemento de la posicion elegida");

	lista_destruir(lista);
}
/*

*/
int comparador(void *elemento_1, void *elemento_2)
{
	int *valor_1 = (int *)elemento_1;
	int *valor_2 = (int *)elemento_2;

	if (valor_1 == valor_2) {
		return 0;
	}

	return 1;
}

void devolver_el_elemento_que_cumple_la_comparacion()
{
	lista_t *lista;
	char *BOCA = "BOCA";
	lista = lista_crear();
	lista = lista_insertar(lista, &BOCA);

	pa2m_afirmar(lista != NULL && lista_buscar_elemento(lista, comparador,
							    NULL) == 0,
		     "Devuelve el elemento que compara de forma correcta");

	lista_destruir(lista);
}

void devolver_primer_elemento_de_la_lista()
{
	lista_t *lista;

	lista = lista_crear();
	lista = lista_insertar(lista, (void *)"hola");
	lista = lista_insertar(lista, (void *)1);
	lista = lista_insertar(lista, (void *)2);

	pa2m_afirmar(lista != NULL && lista_primero(lista) == (void *)"hola",
		     "Devuelve bien el primer elemento de la lista");

	lista_destruir(lista);
}

void devolver_ultimo_elemento_de_la_lista()
{
	lista_t *lista;

	lista = lista_crear();
	lista = lista_insertar(lista, (void *)"hola");
	lista = lista_insertar(lista, (void *)1);
	lista = lista_insertar(lista, (void *)2);

	pa2m_afirmar(lista != NULL && lista_ultimo(lista) == (void *)2,
		     "Devuelve bien el ultimo elemento de la lista");

	lista_destruir(lista);
}

void lista_totalmente_vacia()
{
	lista_t *lista;

	lista = lista_crear();

	pa2m_afirmar(lista != NULL && lista_vacia(lista) == true,
		     "La lista esta vacia o no se creo");

	lista_destruir(lista);
}

void tamaño_de_la_lista()
{
	lista_t *lista;

	lista = lista_crear();
	lista = lista_insertar(lista, (void *)"hola");
	lista = lista_insertar(lista, (void *)1);

	pa2m_afirmar(lista != NULL && lista_tamanio(lista) == 2,
		     "El tamaño de la lista esta bien");

	lista_destruir(lista);
}

void crear_la_pila()
{
	pila_t *pila;

	pila = pila_crear();

	pa2m_afirmar(pila != NULL, "La pila se creo bien");

	pila_destruir(pila);
}

void verifico_si_el_elemento_se_apila_bien()
{
	pila_t *pila;

	pila = pila_crear();
	pila = pila_apilar(pila, (void *)1);
	pila = pila_apilar(pila, (void *)2);
	pila = pila_apilar(pila, (void *)3);

	pa2m_afirmar(pila != NULL && pila_tamanio(pila) == 3,
		     "La pila crece, por lo tanto apila bien");

	pila_destruir(pila);
}

void verificar_que_la_pila_desapila_correctamente()
{
	pila_t *pila;

	pila = pila_crear();
	pila = pila_apilar(pila, (void *)1);
	pila = pila_apilar(pila, (void *)2);
	pila = pila_apilar(pila, (void *)"BOCA");

	pa2m_afirmar(pila != NULL && pila_desapilar(pila) == (void *)"BOCA",
		     "La pila devuelve el elemento desapilado");

	pila_destruir(pila);
}

void devolver_el_elemento_en_el_tope_de_la_pila()
{
	pila_t *pila;

	pila = pila_crear();
	pila = pila_apilar(pila, (void *)1);
	pila = pila_apilar(pila, (void *)2);
	pila = pila_apilar(pila, (void *)3);

	pa2m_afirmar(pila != NULL && pila_tope(pila) == (void *)3,
		     "El elemento del tope es el correcto");

	pila_destruir(pila);
}

void el_tamaño_de_la_pila_es_el_correcto()
{
	pila_t *pila;

	pila = pila_crear();
	pila = pila_apilar(pila, (void *)2);
	pila = pila_apilar(pila, (void *)2);

	pa2m_afirmar(pila != NULL && pila_tamanio(pila) == 2,
		     "El tamaño de la pila es el correcto");

	pila_destruir(pila);
}

void verificar_si_la_pila_esta_completamente_vacia()
{
	pila_t *pila;

	pila = pila_crear();

	pa2m_afirmar(pila != NULL && pila_vacia(pila), "LA pila esta vacia");

	pila_destruir(pila);
}

void verificar_si_se_crea_la_cola()
{
	cola_t *cola;

	cola = cola_crear();

	pa2m_afirmar(cola != NULL, "La cola se creo bien");

	cola_destruir(cola);
}

void encolar_elemento_en_la_cola()
{
	cola_t *cola;
	cola = cola_crear();
	cola = cola_encolar(cola, (void *)1);
	cola = cola_encolar(cola, (void *)2);
	cola = cola_encolar(cola, (void *)3);

	pa2m_afirmar(cola != NULL && cola_tamanio(cola) == 3,
		     "Se agrego bien el elemento");

	cola_destruir(cola);
}

void desencolar_elemento_en_la_cola()
{
	cola_t *cola;

	cola = cola_crear();
	cola = cola_encolar(cola, (void *)1);
	cola = cola_encolar(cola, (void *)2);
	cola = cola_encolar(cola, (void *)3);

	pa2m_afirmar(cola != NULL && cola_desencolar(cola) == (void *)1,
		     "Se quito bien el elemento en la primera posicion");

	cola_destruir(cola);
}

void devolver_frente_de_la_cola()
{
	cola_t *cola;

	cola = cola_crear();
	cola = cola_encolar(cola, (void *)1);
	cola = cola_encolar(cola, (void *)2);
	cola = cola_encolar(cola, (void *)3);

	pa2m_afirmar(cola != NULL && cola_frente(cola) == (void *)1,
		     "El elemento del frente es el correcto");

	cola_destruir(cola);
}

void el_tamaño_de_la_cola_es_el_correcto()
{
	cola_t *cola;

	cola = cola_crear();
	cola = cola_encolar(cola, (void *)1);
	cola = cola_encolar(cola, (void *)2);
	cola = cola_encolar(cola, (void *)3);

	pa2m_afirmar(cola != NULL && cola_tamanio(cola) == 3,
		     "El tamaño de la cola es el correcto");

	cola_destruir(cola);
}

void la_cola_esta_completamente_vacia()
{
	cola_t *cola;

	cola = cola_crear();

	pa2m_afirmar(cola != NULL && cola_vacia(cola), "La cola esta vacia");

	cola_destruir(cola);
}

bool mostrar_elemento(void *elemento, void *contador)
{
	if (elemento && contador)
		printf("Elemento %i: %d \n", (*(int *)contador)++,
		       *(char *)elemento);
	return true;
}

void recorrer_con_iterador_interno()
{
	lista_t *lista = lista_crear();
	int uno = 1, dos = 2, tres = 3;
	int contador = 0;
	size_t elementos_recorridos = 0;

	lista_insertar(lista, &uno);
	lista_insertar(lista, &dos);
	lista_insertar(lista, &tres);
	lista_insertar(lista, &uno);
	lista_insertar(lista, &dos);
	lista_insertar(lista, &tres);

	printf("RECORRO CON EL ITERADOR INTERNO:\n");
	elementos_recorridos = lista_con_cada_elemento(lista, mostrar_elemento,
						       (void *)&contador);

	printf("Recorri %lu elementos con el iterador interno y sume %i elementos\n",
	       elementos_recorridos, contador);
	pa2m_afirmar(elementos_recorridos == contador,
		     "Se recorrio bien el iterador interno\n\n");

	lista_destruir(lista);
}

void recorrer_iterador_externo()
{
	int uno = 1, dos = 2, tres = 3;

	lista_iterador_t *it = NULL;
	lista_t *lista = lista_crear();
	lista_insertar(lista, &uno);
	lista_insertar(lista, &dos);
	lista_insertar(lista, &tres);
	lista_insertar(lista, &uno);
	lista_insertar(lista, &dos);
	lista_insertar(lista, &tres);

	printf("RECORRO CON EL ITERADOR EXTERNO:\n");
	for (it = lista_iterador_crear(lista);
	     lista_iterador_tiene_siguiente(it); lista_iterador_avanzar(it)) {
		printf("Elemento: %i\n",
		       *(int *)lista_iterador_elemento_actual(it));
	}
	printf("\n");

	pa2m_afirmar(lista_tamanio(lista) == 6,
		     "lo hizo bien, recorrio bien con el iterador externo");
	lista_destruir(lista);
	lista_iterador_destruir(it);
}

void hacer_pruebas_respecto_a_las_listas()
{
	crear_la_lista();
	pruebas_para_insertar_en_la_lista();
	insertar_un_elemento_en_la_posicion_indicada();
	quitar_elemento_de_la_ultima_posicion();
	quitar_elemento_de_la_posicion_elegida();
	devolver_elemento_de_la_posicion_elegida();
	devolver_el_elemento_que_cumple_la_comparacion();
	devolver_primer_elemento_de_la_lista();
	devolver_ultimo_elemento_de_la_lista();
	lista_totalmente_vacia();
	tamaño_de_la_lista();
}

void pruebas_respecto_a_la_pila()
{
	crear_la_pila();
	verifico_si_el_elemento_se_apila_bien();
	verificar_que_la_pila_desapila_correctamente();
	devolver_el_elemento_en_el_tope_de_la_pila();
	el_tamaño_de_la_pila_es_el_correcto();
	verificar_si_la_pila_esta_completamente_vacia();
}

void pruebas_respecto_a_las_colas()
{
	verificar_si_se_crea_la_cola();
	encolar_elemento_en_la_cola();
	desencolar_elemento_en_la_cola();
	devolver_frente_de_la_cola();
	el_tamaño_de_la_cola_es_el_correcto();
	la_cola_esta_completamente_vacia();
}

void pruebas_sobre_iteradores()
{
	recorrer_con_iterador_interno();
	recorrer_iterador_externo();
}

int main()
{
	pa2m_nuevo_grupo("PRUEBAS LISTAS");
	hacer_pruebas_respecto_a_las_listas();
	pa2m_nuevo_grupo("PUEBAS SOBRE PILAS");
	pruebas_respecto_a_la_pila();
	pa2m_nuevo_grupo("PUEBAS SOBRE COLAS");
	pruebas_respecto_a_las_colas();
	pa2m_nuevo_grupo("PRUEBAS ITERADORES");
	pruebas_sobre_iteradores();

	return pa2m_mostrar_reporte();
}

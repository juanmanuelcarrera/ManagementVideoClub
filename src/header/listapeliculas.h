// Juan Manuel Carrera García 

// Inclusión de pelicula.h que a su vez incluye genero.h.
#ifndef LISTAPELICULAS_H
#define LISTAPELICULAS_H

#include "pelicula.h"

// Declaración de la estructura tListaPelis que contiene todas las peliculas y un contador
// para saber cuántas películas hay en la lista en todo momento : 


typedef struct{
	pPelicula peliculas; 
	int cont;
	int tama;
} tListaPelis;


bool listaPeliculasLlenas (tListaPelis listaPeliculas); // Función que recibe un dato tListaPelis y comprueba si dicha lista
														// esta llena, para ello compara el contador con N y devuelve un booleano.

int buscarPelicula (tListaPelis listaPeliculas, int codigo, bool& encontrado, int ini, int fin); // Función que recibe un tListaPelis y un codigo y utilizando
																		// recursión busca la película y devuelve un entero con su posición y un bool para saber si se ha encontrado o no.
																	
bool insertarPelicula (tPelicula pelicula, tListaPelis& listaPeliculas); // Función que recibe una película y una lista de películas, busca donde va por código, y la inserta en
															// la lista de películas en la posición correspondiente, y devuelve un bool para indicar si la inserción ha sido correcta.		

bool bajaPelicula (int codigo, tListaPelis& listaPeliculas); // Función que recibe un código y una lista de películas, busca la película y la de baja, para ello como no disponible
															// y devuelve un booleano indicando si la baja ha sido correcta o no.

#endif
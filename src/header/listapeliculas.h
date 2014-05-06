// Juan Manuel Carrera Garc�a 

// Inclusi�n de pelicula.h que a su vez incluye genero.h.
#ifndef LISTAPELICULAS_H
#define LISTAPELICULAS_H

#include "pelicula.h"

// Declaraci�n de la estructura tListaPelis que contiene todas las peliculas y un contador
// para saber cu�ntas pel�culas hay en la lista en todo momento : 


typedef struct{
	pPelicula peliculas; 
	int cont;
	int tama;
} tListaPelis;


bool listaPeliculasLlenas (tListaPelis listaPeliculas); // Funci�n que recibe un dato tListaPelis y comprueba si dicha lista
														// esta llena, para ello compara el contador con N y devuelve un booleano.

int buscarPelicula (tListaPelis listaPeliculas, int codigo, bool& encontrado, int ini, int fin); // Funci�n que recibe un tListaPelis y un codigo y utilizando
																		// recursi�n busca la pel�cula y devuelve un entero con su posici�n y un bool para saber si se ha encontrado o no.
																	
bool insertarPelicula (tPelicula pelicula, tListaPelis& listaPeliculas); // Funci�n que recibe una pel�cula y una lista de pel�culas, busca donde va por c�digo, y la inserta en
															// la lista de pel�culas en la posici�n correspondiente, y devuelve un bool para indicar si la inserci�n ha sido correcta.		

bool bajaPelicula (int codigo, tListaPelis& listaPeliculas); // Funci�n que recibe un c�digo y una lista de pel�culas, busca la pel�cula y la de baja, para ello como no disponible
															// y devuelve un booleano indicando si la baja ha sido correcta o no.

#endif
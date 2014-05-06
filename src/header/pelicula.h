// Juan Manuel Carrera García 

// Inclusión de bibliotecas necesarias (Incluido el genero.h)
#ifndef PELICULA_H
#define PELICULA_H

#include <cstring>
using namespace std;
#include "genero.h"

// Declaración de la estructura tPelicula que contiene los datos de una película (codigo, titulo, ...) : 

typedef char tCadena [40];

typedef struct {
	int codigo;
	tCadena titulo;
	tGenero genero;
	int duracion;
	double precio;
	bool disponible;
} tPelicula;

typedef tPelicula *pPelicula;

// Funciones : 

tPelicula leerPelicula ();	// Funcion que no recibe ningún dato de entrada y devuelve un película con todos	
							// sus datos, para ello va pidiendo los datos y guardandolos en el tPelicula correspondiente.

void mostrarPelicula (tPelicula pelicula); // Función que recibe un dato del tipo tPelicula (una película) y muestra sus datos por	
										   // por pantalla.

void editarPelicula (tPelicula& pelicula);	// Función que recibe un dato del tipo tPelicula (una película) y le permite al usuario
											// acutualizar algunos datos de la película (título, género y precio).

#endif
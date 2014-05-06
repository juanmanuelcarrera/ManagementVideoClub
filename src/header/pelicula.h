// Juan Manuel Carrera Garc�a 

// Inclusi�n de bibliotecas necesarias (Incluido el genero.h)
#ifndef PELICULA_H
#define PELICULA_H

#include <cstring>
using namespace std;
#include "genero.h"

// Declaraci�n de la estructura tPelicula que contiene los datos de una pel�cula (codigo, titulo, ...) : 

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

tPelicula leerPelicula ();	// Funcion que no recibe ning�n dato de entrada y devuelve un pel�cula con todos	
							// sus datos, para ello va pidiendo los datos y guardandolos en el tPelicula correspondiente.

void mostrarPelicula (tPelicula pelicula); // Funci�n que recibe un dato del tipo tPelicula (una pel�cula) y muestra sus datos por	
										   // por pantalla.

void editarPelicula (tPelicula& pelicula);	// Funci�n que recibe un dato del tipo tPelicula (una pel�cula) y le permite al usuario
											// acutualizar algunos datos de la pel�cula (t�tulo, g�nero y precio).

#endif
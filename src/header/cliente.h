// Juan Manuel Carrera Garc�a 

// Inclusi�n de bibliotecas a�adiendo listapelicula.h que a su vez incluye genero.h y pelicula.h.
#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstring>
using namespace std;
#include "listapeliculas.h"

// N�mero m�ximo de visionados por cliente :
const int M = 40;

// Declaraci�n estructuras : 

// Estructra tPeliVista que incluye los datos de una pelicula visionada : 
typedef struct {
	int codigo;
	bool gustado;
} tPeliVista;

// Array que contiene las peliculas vistas :
typedef tPeliVista tPeliculasVistas [M];

// Estructura que contiene las pel�culas vistas y un contador para indicar cuantas ha visto el cliente en cada momento :
typedef struct {
	tPeliculasVistas listaVistas; 
	int contador;
} tListaVisionadas;

// Estructura tCliente que incluye todos los datos de un cliente (nif, nombre, ...):

typedef struct {
	tCadena nif;
	tCadena nombre;
	tCadena apellidos;
	tGenero genfavorito;
	tListaVisionadas pelisVistas;
} tCliente;

typedef tCliente *pClientes;

tCliente leerCliente (); // Funci�n que no recibe ning�n dato y devuelve un tCliente (un cliente) con todos sus datos.

void mostrarCliente (tCliente cliente, bool mostrarDetalles, tListaPelis listaPeliculas); // Funci�n que recibe un dato del tipo tCliente (un cliente) 
										   // y muestra sus datos por pantalla (con detalles -> todas las peliculas visonadas; o sin detalles).

void editarCliente (tCliente& cliente); // Funci�n que recibe un dato del tipo tCliente (un cliente) y le permite al usuario
										// acutualizar algunos datos dl cliente (nombre, apellidos y g�nero).

void altaVisionado (tCliente& cliente, int codigo, bool gustar); // Funci�n que recibe un cliente, un codigo, y un bool gustado y a�ade un nuevo visionado
																 // a lista de peliculas vistas del cliente indicando si le ha gustado o no.

void datosVisionado (tCliente cliente, int codigo, int& vecsVista, int& vecsGustad); // Funcion que recibe un cliente, un codigo de una pel�cula la busca en la
																	// lista de visionados del cliente y nos devuelve un int con las veces que se ha visto y otro con las veces que
																	// ha gustado.

#endif
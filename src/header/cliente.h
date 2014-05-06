// Juan Manuel Carrera García 

// Inclusión de bibliotecas añadiendo listapelicula.h que a su vez incluye genero.h y pelicula.h.
#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstring>
using namespace std;
#include "listapeliculas.h"

// Número máximo de visionados por cliente :
const int M = 40;

// Declaración estructuras : 

// Estructra tPeliVista que incluye los datos de una pelicula visionada : 
typedef struct {
	int codigo;
	bool gustado;
} tPeliVista;

// Array que contiene las peliculas vistas :
typedef tPeliVista tPeliculasVistas [M];

// Estructura que contiene las películas vistas y un contador para indicar cuantas ha visto el cliente en cada momento :
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

tCliente leerCliente (); // Función que no recibe ningún dato y devuelve un tCliente (un cliente) con todos sus datos.

void mostrarCliente (tCliente cliente, bool mostrarDetalles, tListaPelis listaPeliculas); // Función que recibe un dato del tipo tCliente (un cliente) 
										   // y muestra sus datos por pantalla (con detalles -> todas las peliculas visonadas; o sin detalles).

void editarCliente (tCliente& cliente); // Función que recibe un dato del tipo tCliente (un cliente) y le permite al usuario
										// acutualizar algunos datos dl cliente (nombre, apellidos y género).

void altaVisionado (tCliente& cliente, int codigo, bool gustar); // Función que recibe un cliente, un codigo, y un bool gustado y añade un nuevo visionado
																 // a lista de peliculas vistas del cliente indicando si le ha gustado o no.

void datosVisionado (tCliente cliente, int codigo, int& vecsVista, int& vecsGustad); // Funcion que recibe un cliente, un codigo de una película la busca en la
																	// lista de visionados del cliente y nos devuelve un int con las veces que se ha visto y otro con las veces que
																	// ha gustado.

#endif
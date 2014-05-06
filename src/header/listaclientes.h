// Juan Manuel Carrera Garc�a 

// Inclusi�n de bibliotecas a�adiendo clinte.h que a su vez incluye genero.h, pelicula.h. y listapeliculas.h..
#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H

#include "cliente.h"

// Declaraci�n de la estructura tListaClientes que contiene todas los clientes y un contador
// para saber cu�ntos clientes hay en la lista en todo momento : 

typedef struct {
	pClientes clientes;
	int contCli;
	int tama;
} tListaClientes; 

bool listaClientesLlena (tListaClientes listaClientes); // Funci�n que recibe un dato tListaClientes y comprueba si dicha lista
														// esta llena, para ello compara el contador con P y devuelve un booleano.

int buscarCliente (tListaClientes listaClientes, tCadena dni, bool& encontrado, int ini, int fin); // Funci�n que recibe un tListaClientes y un nif y utilizando recursi�n
																		// lo busca y devuelve un int con su posicion y un bool para saber si se ha encontrado o no.
																		
bool insertarCliente (tCliente cliente, tListaClientes& listaClientes); // Funci�n que recibe un cleitne y una lista de clientes, busca donde va por nif, y la inserta en
															// la lista de clientes en la posici�n correspondiente, y devuelve un bool para indicar si la inserci�n ha sido correcta.		


bool bajaCliente (tCadena dni, tListaClientes& listaClientes);  // Funci�n que recibe un nif y una lista de clientes, busca el cliente y lo borra de lista de clientes.

#endif
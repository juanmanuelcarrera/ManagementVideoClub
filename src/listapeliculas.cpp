// Juan Manuel Carrera García 

#include <iostream>
using namespace std;
#include "listapeliculas.h"

// Funciones : 

bool listaPeliculasLlenas (tListaPelis listaPeliculas) {  //True -> LLeno
	return (listaPeliculas.cont == listaPeliculas.tama);
}

int buscarPelicula (tListaPelis listaPeliculas, int cod, bool& encontrado, int ini, int fin) {
	int mitad;
	int pos = -1;
	encontrado = false;

	if ((ini <= fin) && (!encontrado)){
		mitad = (ini + fin) / 2;

		if (listaPeliculas.peliculas [mitad].codigo == cod) {
			pos = mitad;
			encontrado = true;
		}
		else 
			if (listaPeliculas.peliculas [mitad].codigo > cod) 
				pos = buscarPelicula (listaPeliculas, cod, encontrado, ini, mitad - 1);
			else 
				pos = buscarPelicula (listaPeliculas, cod, encontrado, mitad + 1, fin);
		
	}
	
	return pos;
}

bool insertarPelicula (tPelicula pelicula, tListaPelis& listaPeliculas) {
	bool ok = true;  
	int i = 0;
	int posic = 0;
		
	while ((listaPeliculas.peliculas [i].codigo <= pelicula.codigo) && (i < listaPeliculas.cont)) {
		if (listaPeliculas.peliculas [i].codigo == pelicula.codigo)
			ok = false;
		posic++;
		i++;
	}

	if (ok) { 
		for (int j = listaPeliculas.cont; j > posic; j--)
			listaPeliculas.peliculas [j] = listaPeliculas.peliculas [j - 1];
		listaPeliculas.peliculas[posic] = pelicula;
		listaPeliculas.cont++;
	}

	return ok;	
}

bool bajaPelicula (int codigo, tListaPelis& listaPeliculas) {
	bool ok;
	int posi;

	posi = buscarPelicula (listaPeliculas, codigo, ok, 0, listaPeliculas.cont - 1);

	if (ok) listaPeliculas.peliculas[posi].disponible = false;
	
	return ok;
}

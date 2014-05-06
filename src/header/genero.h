// Juan Manuel Carrera García 

#ifndef GENERO_H
#define GENERO_H

// Declaracion de variables : 

// Declaración del enumerado que contiene todos los géneros posibles.
typedef enum {cienciaficcion, fantasia, comedia, terror, drama, comediaromantica} tGenero;

// Funciones : 

tGenero leerGenero (); // Funcion que no recibe ningún dato y que nos da uno del tipo tGenero, para ello le pide al usuario
					   // que introduzca  un entero y así eliges el tGenero correspondiente.

void escribirGenero (tGenero genero);	// Función que recibe un dato del tipo tGenero y muestra su nombre por pantalla.

// Funciones Adicionales :

tGenero leerGeneroArchivo (int gen);  // Funcion que recibe un entero y que nos devuelve un dato del tipo tGenero, para ello segun el entero
									  // que sea elige un tGenero u otro. (Utilizada a la hora de la carga de los archivos).

void escribirGeneroArchivo (tGenero gener, ofstream& archivo);  // Función que recibe un dato del tipo tGenero y escribe el genero correspondiente en el archivo. 
											   // (Funcion utilizada para meter el nombre al archivo).
#endif
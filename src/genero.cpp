// Juan Manuel Carrera García 

#include <iostream>
#include <fstream>
using namespace std;
#include "genero.h"

tGenero leerGenero () {
	bool error;
	int gen;
	tGenero gener;
		
	cout << "1 - Ciencia-Ficcion" << endl;
	cout << "2 - Fantasia" << endl;
	cout << "3 - Comedia" << endl;
	cout << "4 - Terror" << endl;
	cout << "5 - Drama" << endl;
	cout << "6 - Comedia Romantica" << endl;
	cout << "Genero : "; cin >> gen;

	do {
		error = false;
		switch (gen) {
		case 1 : gener = cienciaficcion; break;
		case 2 : gener = fantasia; break;
		case 3 : gener = comedia; break;
		case 4 : gener = terror; break;
		case 5 : gener = drama; break;
		case 6 : gener = comediaromantica; break;
		default : {
				  error = true;	
				  cout << "1 - Ciencia-Ficcion" << endl;
				  cout << "2 - Fantasia" << endl;
				  cout << "3 - Comedia" << endl;
				  cout << "4 - Terror" << endl;
			      cout << "5 - Drama" << endl;
				  cout << "6 - Comedia Romantica" << endl;
				  cout << "Genero : "; cin >> gen;
				  }
		}
	} while (error);
	
	return gener;
}

void escribirGenero (tGenero gener) {
	switch (gener) {
		case 0 : cout << "Ciencia-Ficcion" << endl; break;	
		case 1 : cout << "Fantasia" << endl; break;
		case 2 : cout << "Comedia" << endl; break;
		case 3 : cout << "Terror" << endl; break;
		case 4 : cout << "Drama" << endl; break;
		case 5 : cout << "Comedia Romantica" << endl; break;
	}
}


// Funciones Adicionales :

void escribirGeneroArchivo (tGenero gener, ofstream& archivo) {
	switch (gener) {
		case 0 : archivo << "Ciencia-Ficcion"; break;	
		case 1 : archivo << "Fantasia" ; break;
		case 2 : archivo << "Comedia"; break;
		case 3 : archivo << "Terror"; break;
		case 4 : archivo << "Drama"; break;
		case 5 : archivo << "Comedia Romantica"; break;
	}
}

tGenero leerGeneroArchivo (int gen) {
	tGenero gener;
	switch (gen) {
		case 0 : gener = cienciaficcion; break;
		case 1 : gener = fantasia; break;
		case 2 : gener = comedia; break;
		case 3 : gener = terror; break;
		case 4 : gener = drama; break;
		case 5 : gener = comediaromantica; break;
	}
	
	return gener;
}


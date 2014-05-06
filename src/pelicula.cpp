// Juan Manuel Carrera García 

#include <iostream>
using namespace std;
#include "pelicula.h"

tPelicula leerPelicula () {
	tPelicula pelicula;
	
	cout << "---------------------------------" << endl;
	cout << "   PEDIR DATOS DE UNA PELICULA   " << endl;
	cout << "---------------------------------" << endl;

	do {
		cout << "Codigo : "; 
		cin >> pelicula.codigo;
	} while (pelicula.codigo <= 0);
	cin.sync ();

	cout << "Titulo : ";
	cin.sync ();
	cin.getline (pelicula.titulo, 40);
	
	cout << "Genero : " << endl;
	cin.sync ();
	pelicula.genero = leerGenero (); 
	
	cout << "Duracion (minutos) : ";
	cin.sync ();
	cin >> pelicula.duracion;

	do {
		cout << "Precio (0 -> Gratuita) : "; 
		cin.sync ();
		cin >> pelicula.precio;		
	} while (pelicula.precio < 0);

	pelicula.disponible = true;
	
	return pelicula;
}

void mostrarPelicula (tPelicula pelicula) {
	cout << endl;
	cout << "----------------------" << endl;
	cout << "      Pelicula # " << pelicula.codigo << endl;
	cout << "----------------------" << endl;
	cout << "     Titulo : " << pelicula.titulo << endl;
	cout << "     Genero : ";
	escribirGenero (pelicula.genero);
	cout << "   Duracion : " << pelicula.duracion << " minuto/s" << endl;
	cout << "     Precio : " << pelicula.precio << " euro/s" << endl;
	cout << " Disponible : ";
	if (pelicula.disponible == true) cout << "Si" << endl;
	else cout << "No " << endl;
	cout << endl;
}

void editarPelicula (tPelicula& pelicula){
	char c;

	cout << "-------------------------------------" << endl;
	cout << "   MODIFICAR DATOS DE UNA PELICULA   " << endl;
	cout << "-------------------------------------" << endl;

	cout << "Titulo : " << pelicula.titulo << endl;
	cin.sync ();
	cout << "Nuevo titulo (Intro -> dejarlo igual) : "; c = cin.peek ();
	if (c != '\n') 
		cin.getline (pelicula.titulo, 40);
	else cin.get (c);
	
		
	cout << "Genero : ";
	escribirGenero (pelicula.genero);
	cin.sync ();
	cout << "Nuevo genero (s -> cambiar, intro -> continuar) : "; cin.get (c);
	c = toupper (c);
	if (c == 'S') {
		cin.sync ();
		pelicula.genero = leerGenero ();
	}
	cout << "Duracion : " << pelicula.duracion << endl;
	cin.sync ();
	cout << "Nueva duracion (Intro -> dejarlo igual) : "; c = cin.peek ();
	if (c != '\n') 
		cin >> pelicula.duracion;
	else cin.get (c);	

	cout << "Precio : " << pelicula.precio << endl;
	cin.sync ();
	cout << "Nuevo precio (Intro -> dejarlo igual): "; c = cin.peek ();
	if(c != '\n') {
		do {
			cin >> pelicula.precio;		
		} while (pelicula.precio < 0);
	}
	else cin.get (c);
}

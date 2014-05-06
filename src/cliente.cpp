// Juan Manuel Carrera García 

#include <iostream>
using namespace std;
#include "cliente.h"

// Funciones :

tCliente leerCliente () {
	bool ok;
	int i;
	tCliente client;
	
	cin.sync ();
	cout << "-------------------------------" << endl;
	cout << "   PEDIR DATOS DE UN CLIENTE   " << endl;
	cout << "-------------------------------" << endl;
	cout << "Nombre : ";
	cin.sync ();
	cin.getline (client.nombre, 30);
	cout << "Apellidos : ";
	cin.sync ();
	cin.getline (client.apellidos, 30);
	cout << "Genero favorito : " << endl;
	cin.sync ();
	client.genfavorito = leerGenero ();
	do {
		i = 0;
		ok = true;
		cin.sync ();
		cout << "NIF : "; cin.getline (client.nif, 30);
		
		if (strlen (client.nif) != 9) ok = false;
		else {
			do {
				if (i <= 7) 
					if (client.nif [i] > '9' || client.nif [i] < '0') ok = false;
				
				client.nif [8] = toupper (client.nif [8]);
				if (i == 8)
					if (client.nif [i] < 'A' || client.nif [i] > 'Z') ok = false;
				i++;
			} while ((ok) && (i <= 8));
		}
	} while (!ok);
	
	client.pelisVistas.contador = 0;

	return client;
}

void mostrarCliente (tCliente cliente, bool mostrarDetalles, tListaPelis listaPeliculas) {
	bool encontrado;
	int posic, codig;
	
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "              Cliente              "  << endl;
	cout << "-----------------------------------" << endl;
	cout << "          Nombre : " << cliente.nombre << endl;
	cout << "       Apellidos : " << cliente.apellidos << endl;
	cout << "             NIF : " << cliente.nif << endl;
	cout << " Genero favorito : ";
	escribirGenero (cliente.genfavorito);
	cout << "Peliculas vistas : " << cliente.pelisVistas.contador << endl;
	
	if (mostrarDetalles) {
		for (int i = 0; i < cliente.pelisVistas.contador; i++) {
			codig = cliente.pelisVistas.listaVistas [i].codigo;
			posic = buscarPelicula (listaPeliculas, codig, encontrado, 0, listaPeliculas.cont - 1);
			if (encontrado) {
				cout << "-----------------------------------" << endl;
				cout << "          Titulo : " << listaPeliculas.peliculas [posic].titulo << endl;
				cout << "          Genero : ";
				escribirGenero (listaPeliculas.peliculas [posic].genero);
				if (cliente.pelisVistas.listaVistas [i].gustado)
					cout << "         Gustado : SI" << endl;
				else cout << "         Gustado : NO" << endl;
			} 
		}	
	}
	else cout << endl;
}

void editarCliente (tCliente& cliente) {
	char c;

	cout << "-------------------------------------" << endl;
	cout << "   MODIFICAR DATOS DE UN CLIENTE     " << endl;
	cout << "-------------------------------------" << endl;

	cout << "Nombre : " << cliente.nombre << endl;
	cin.sync ();
	cout << "Nuevo nombre (Intro -> dejarlo igual) : "; c = cin.peek ();
	if (c != '\n') 
		cin.getline (cliente.nombre, 30);
	else cin.get (c);

	cout << "Apellidos : " << cliente.apellidos << endl;
	cin.sync ();
	cout << "Nuevos apellidos (Intro -> dejarlo igual) : "; c = cin.peek ();
	if (c != '\n') 	
		cin.getline (cliente.apellidos, 30);
	else cin.get (c);

	cout << "Genero favorito : ";
	escribirGenero (cliente.genfavorito);
	cin.sync ();
	cout << "Nuevo genero (s -> cambiar, intro -> continuar) : "; cin.get (c);
	c = toupper (c);
	cin.sync ();
	if (c == 'S') {
		cin.sync ();
		cliente.genfavorito = leerGenero ();
	}
}

void altaVisionado (tCliente& cliente, int codigo, bool gustar) {
	cliente.pelisVistas.listaVistas[cliente.pelisVistas.contador].codigo = codigo;	
	cliente.pelisVistas.listaVistas[cliente.pelisVistas.contador].gustado = gustar;	
	
	cliente.pelisVistas.contador++;
}

void datosVisionado (tCliente cliente, int codigo, int& vecsVista, int& vecsGustad) {
	vecsVista = 0;
	vecsGustad = 0;

	for (int i = 0; i < cliente.pelisVistas.contador; i++) {
		if (codigo == cliente.pelisVistas.listaVistas [i].codigo) {
			vecsVista++;
			if (cliente.pelisVistas.listaVistas [i].gustado == true)
				vecsGustad++;
		}
	}
}

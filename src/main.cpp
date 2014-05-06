// Juan Manuel Carrera García 

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "listaclientes.h"

// Funciones que implementan los diferentes menús (principal, películas, clientes y general) :
int menuPrincipal ();

int menuPeliculas ();

int menuClientes ();

int menuGeneral ();

// Funciones y procedimientos de incialización :

// Procedimiento para inicializar la lista de peliculas y la lista de clientes.
void inicializa (tListaPelis& listaPeliculas, tListaClientes& listaClientes, int capacidPels, int capacidClien);

// Función que cargar las películas iniciales en la lista e indica cuantas ha cargado.
int cargarPelis (ifstream& archivo, tListaPelis& listaPeliculas);

// Función que cargar los clientes iniciales en la lista e indica cuantas ha cargado.
int cargarClientes (ifstream& archivo, tListaClientes& listaClientes);

// Funciones y procedimientos de la gestión general :

// Funcion que recibe una lista de clientes y devuelve otra ordenada por apellidos.
tListaClientes ordenarClientesApellidos (tListaClientes listaClientes);

// Procedimiento que recibe una lista de clientes, otra de películas, un código, un nif, busca el cliente y la película y si exiten
// Y LA PELÍCULA ESTÁ DISPONIBLE esta se añade a la lista de visionados del cliente buscado con todos sus datos (código y gustado).
void nuevoVisionado (tListaClientes& listaClientes, tListaPelis listaPeliculas, int codigo, tCadena NIF);

// Procedimiento que recibe un archivo y una lista de clientes y la copia al archivo.
void exportarClientes (ofstream& archivo, tListaClientes listaClientes);

// Procedimientos que recibe la lista de clientes y de películas y por cada película de la lista muestro las veces que se ha visto 
// y las veces que ha gustado en total.
void estadisticaPeliculas (tListaClientes listaClientes, tListaPelis listaPeliculas);


// FUNCIONES Y PROCEDIMIENTOS DE LA PRÁCTICA 5 : 

// Procedimientos para coger más memoria para los punteros en el caso de que nos hallamos quedado sin memoria :
void aumentaListaPelis (tListaPelis& listaPeliculas);

void aumentaListaClientes (tListaClientes& listaClientes);

// Funciones para guardar las listas de películas y clientes en un archivo binario :
bool guardarPeliculas (tListaPelis listaPeliculas);

bool guardarClientes (tListaClientes listaClientes);

// Procedimiento para destruir los punteros cuando salgamos del programa :
void destruir (tListaClientes& listaClientes, tListaPelis& listaPeliculas);

// Funciones para cargar las listas de películas y clientes desde un archivo binario : 
bool cargarPelisBinario (tListaPelis& listaPeliculas, int& elementos);

bool cargarClientesBinario (tListaClientes& listaClientes, int& elementos);


int main () {
	int menuPrinc = 0, menuSecun = 0;
	int auxCodig, posicion, elemn;
	int capacidPels = 5, capacidClien = 5;
	char fn, c;
	bool detalles, encontrad;
	tCadena nombrFichero;
	tCadena auxDNI;
	tListaPelis listPeliculs;
	tListaClientes listClients;
	tPelicula auxPeli;
	tCliente auxClient;
	ifstream pelis;
	ifstream clients;
	ofstream output;
		
	inicializa (listPeliculs, listClients, capacidPels, capacidClien);

	if (cargarPelisBinario (listPeliculs, elemn)) 
		cout << "Archivo de peliculas abierto con exito (" << elemn << " peliculas)" << endl;
	else 
		cout << "No se ha encontrado el archivo de peliculas (se empieza con una lista vacia)" << endl;
		
	if (cargarClientesBinario (listClients, elemn)) 
		cout << "Archivo de clientes abierto con exito (" << elemn << " clientes)" << endl;
	else 
		cout << "No se ha encontrado el archivo de clientes (se empieza con una lista vacia)" << endl;
			
	cout << endl;
	
	do {
		menuPrinc = menuPrincipal ();
		switch (menuPrinc) {
		case 1 : {
			do {
				menuSecun = menuPeliculas ();
				switch (menuSecun) {
				case 1 : {
						 cout << "---------------------------------" << endl;
						 cout << "       ALTA DE UNA PELICULA      " << endl;
						 cout << "---------------------------------" << endl;

						 if (listaPeliculasLlenas (listPeliculs)) 
							aumentaListaPelis (listPeliculs);
						 
						 auxPeli = leerPelicula ();
						 if (!insertarPelicula (auxPeli, listPeliculs))
						 	 cout << "ERROR: Codigo registrado" << endl;
						 else cout << "Pelicula dada de alta con exito" << endl;
						 					 
						 }; break;
				
				case 2 : {
						 cout << "---------------------------------" << endl;
						 cout << "       DATOS DE UNA PELICULA     " << endl;
						 cout << "---------------------------------" << endl;

						 cout << "Codigo : "; cin >> auxCodig;
						 posicion = buscarPelicula (listPeliculs, auxCodig, encontrad, 0, listPeliculs.cont - 1);

						 if (encontrad) 
							 mostrarPelicula (listPeliculs.peliculas [posicion]);
						 else cout << "ERROR: Codigo no registrado" << endl << endl;
						 }; break;

				case 3 : {
						 cout << "--------------------------------" << endl;
						 cout << "       LISTADO DE PELICULAS     " << endl;
						 cout << "--------------------------------" << endl;
						 if (listPeliculs.cont != 0) {
							 for (int i = 0; i < listPeliculs.cont; i++)
								mostrarPelicula (listPeliculs.peliculas [i]);
						 }
						 else cout << "          LISTA VACIA           " << endl;
						 }; break;
				
				case 4 : {
						 cout << "---------------------------------" << endl;
						 cout << "     EDICION DE UNA PELICULA     " << endl;
						 cout << "---------------------------------" << endl;

						 cout << "Codigo : "; cin >> auxCodig;
						 posicion = buscarPelicula (listPeliculs, auxCodig, encontrad, 0, listPeliculs.cont - 1);
					 
						 if (encontrad) {
							 editarPelicula (listPeliculs.peliculas [posicion]);
							 cout << "Pelicula editada con exito, nuevos valores : " << endl;
							 mostrarPelicula (listPeliculs.peliculas [posicion]);
						 }
					     else cout << "ERROR: Codigo no registrado" << endl << endl;
						 }; break;
				case 5 : {
						 cout << "---------------------------------" << endl;
						 cout << "       BAJA DE UNA PELICULA      " << endl;
						 cout << "---------------------------------" << endl;

						 cout << "Codigo : "; cin >> auxCodig;
						 				 
						 if (bajaPelicula (auxCodig, listPeliculs))						 
							cout << "Pelicula dada de baja con exito" << endl;
						 else cout << "ERROR: Codigo no registrado" << endl << endl;					 
						 }; break;
				}
			} while (menuSecun != 0);
		}; break;
		case 2 : {
			do {
				menuSecun = menuClientes ();
				switch (menuSecun) {
				case 1 : {
						 cout << "-------------------------------" << endl;
					     cout << "       ALTA DE UN CLIENTE      " << endl;
	                     cout << "-------------------------------" << endl;
						
						 if (listaClientesLlena (listClients)) 
							aumentaListaClientes (listClients);
						 						
						 auxClient = leerCliente ();
						 if (!insertarCliente (auxClient, listClients)) 
							cout << "ERROR: NIF registrado" << endl;
						 else cout << "Cliente dado de alta con exito" << endl;

						 }; break;
				
				case 2 : {
						 cout << "-------------------------------" << endl;
					     cout << "       DATOS DE UN CLIENTE     " << endl;
	                     cout << "-------------------------------" << endl;
						
						 cin.sync ();
						 cout << "NIF : "; cin.getline (auxDNI, 30);
						 posicion = buscarCliente (listClients, auxDNI, encontrad, 0, listClients.contCli - 1);

						 if (encontrad) {
							 detalles = true;
							 mostrarCliente (listClients.clientes [posicion], detalles, listPeliculs);
						 }
						 else cout << "ERROR: NIF no registado" << endl << endl;
						 }; break;

				case 3 : {
					     cout << "------------------------------" << endl;
						 cout << "     LISTADO DE CLIENTES     " << endl;
						 cout << "------------------------------" << endl;
					
						 detalles = false;
						 if (listClients.contCli != 0) {
							 for (int i = 0; i < listClients.contCli; i++)
								mostrarCliente (listClients.clientes [i], detalles, listPeliculs);
						 }
						 else cout << "        LISTA VACIA     " << endl;
						 }; break;
				
				case 4 : {
						 cout << "-------------------------------" << endl;
					     cout << "     EDICION DE UN CLIENTE     " << endl;
	                     cout << "-------------------------------" << endl;
						
					     cin.sync ();
						 cout << "NIF : "; cin.getline (auxDNI, 30);
						 posicion = buscarCliente (listClients, auxDNI, encontrad, 0, listClients.contCli - 1);

						 if (encontrad) {
							 editarCliente (listClients.clientes [posicion]);
							 cout << "Cliente editado con exito, nuevos valores : " << endl;
							 detalles = true;
							 mostrarCliente (listClients.clientes [posicion], detalles, listPeliculs);
						 }
						 else cout << "ERROR: NIF no reigstrado" << endl << endl;
						 }; break;
				
				case 5 : {
						 cout << "-------------------------------" << endl;
					     cout << "       BAJA DE UN CLIENTE      " << endl;
	                     cout << "-------------------------------" << endl;
						 cin.sync ();
						 cout << "NIF : "; cin.getline (auxDNI, 30);
						 if (bajaCliente (auxDNI, listClients)) 
							cout << "Ciente dado de baja con exito" << endl;
						 else cout << "ERROR: NIF no registrado" << endl << endl;
						 }; break;
				}
			} while (menuSecun != 0);
		}; break;
		case 3 : {
			do {
				menuSecun = menuGeneral ();
				switch (menuSecun) {
				case 1 : {
						 cout << "-------------------------------" << endl;
					     cout << "        NUEVO VISIONADO        " << endl;
	                     cout << "-------------------------------" << endl;
						 cout << "Codigo de la pelicula : "; cin >> auxCodig;
						 cin.sync ();
						 cout << "NIF del cliente : "; cin.getline (auxDNI, 30);
						 nuevoVisionado (listClients, listPeliculs, auxCodig, auxDNI);
						 }; break;
				
				case 2 : {
						 cout << "-------------------------------" << endl;
					     cout << "   EXPORTAR LISTA DE CLIENTES  " << endl;
	                     cout << "-------------------------------" << endl;
						 cout << "Nombre del archivo destino ('xxxx.txt') : ";
						 cin.sync ();
						 cin.getline (nombrFichero, 20);
						 output.open (nombrFichero);
						 exportarClientes (output, ordenarClientesApellidos (listClients));	
						 output.close ();	
						 }; break;

				case 3 : {
						 cout << "-------------------------------" << endl;
					     cout << "   ESTADISTICAS DE VISIONADOS  " << endl;
	                     cout << "-------------------------------" << endl;
					     estadisticaPeliculas (listClients, listPeliculs);
						 }; break;
				}
			} while (menuSecun != 0);
		}; break;
		case 4 : {
					cout << endl;	
					cout << "*********************" << endl;
					cout << "****    AVISO    ****" << endl;                   
					cout << "*********************" << endl;
					cout << "Esta operacion borrara todos los datos de las listas" << endl;
					cout << "Desea continuar (S/N)?"; cin >> c;
					c = toupper (c);

					if (c == 'S') {
						capacidPels = 5;
						capacidClien = 5;
						inicializa (listPeliculs, listClients, capacidPels, capacidClien);

						pelis.open ("pelis.txt");
						if (pelis.is_open()) {
						cout << "Archivo de peliculas importado con exito (" 
							 << cargarPelis (pelis, listPeliculs) << " peliculas)" << endl;
						}
						else 
							cout << "No se ha encontrado el archivo de peliculas (se empieza con una lista vacia)" << endl;
						
						pelis.close ();

						clients.open ("clientes.txt");
						if (clients.is_open()) {
							cout << "Archivo de cleintes importado con exito (" 
								<< cargarClientes (clients, listClients) << " clientes)" << endl;
						}
						else 
							cout << "No se ha encontrado el archivo de clientes (se empieza con una lista vacia)" << endl;

						clients.close ();
					}
					else cout << "Operacion cancelada..." << endl;
		}; break;
		}

	} while (menuPrinc != 0);
	
	cout << endl;
	
	if (guardarPeliculas (listPeliculs))
		cout << "El archivo de peliculas ha sido guardado con exito (" << listPeliculs.cont << " registros)" << endl;  
	
	if (guardarClientes (listClients))
		cout << "El archivo de clientes ha sido guardado con exito (" << listClients.contCli << " registros)" << endl;  
	
	destruir (listClients, listPeliculs);
	
	cout << endl << "---------------------------------------------------------------" << endl; 
	cout << "Intro para salir..." << endl;
	
	cin.sync ();
	cin.get (fn);
	return 0;
}

// FUNCIONES Y PROCEDIMIENTOS :

// Funciones que implementan los diferentes menús (principal, películas, clientes y general) :
int menuPrincipal () {
	int men;
		
	do {
		cout << endl;
		cout << "--------------" << endl;
		cout << "MENU PRINCIPAL" << endl;
		cout << "--------------" << endl;
		cout << "1.- Gestionar peliculas" << endl;
		cout << "2.- Gestionar clientes" << endl;
		cout << "3.- Gestion general" << endl;
		cout << "4.- Importar datos de archivos de texto" << endl;
		cout << "0.- Salir" << endl;
		cin >> men;
	} while (men < 0 || men > 4);
	
	return men;
}

int menuPeliculas () {
	int men;
	
	cout << endl;
	do {
		cout << "-----------------" << endl;
		cout << "GESTION PELICULAS" << endl;
		cout << "-----------------" << endl;
		cout << "1.- Alta de una pelicula" << endl;
		cout << "2.- Datos de una pelicula" << endl;
		cout << "3.- Datos de todas las peliculas" << endl;	
		cout << "4.- Edicion de una pelicula" << endl;
		cout << "5.- Baja de una pelicula" << endl;
		cout << "0.- Volver al menu anterior" << endl;
		cin >> men;
		cout << endl;
	} while (men < 0 || men > 5);
	
	return men;
}

int menuClientes () {
	int men;
	
	cout << endl;
	do {
		cout << "----------------" << endl;
		cout << "GESTION CLIENTES" << endl;
		cout << "----------------" << endl;
		cout << "1.- Nuevo cliente" << endl;
		cout << "2.- Datos de un cliente" << endl;
		cout << "3.- Datos de todos los clientes" << endl;	
		cout << "4.- Edicion de un cliente" << endl;
		cout << "5.- Baja de un cliente" << endl;
		cout << "0.- Volver al menu anterior" << endl;
		cin >> men;
		cout << endl;
	} while (men < 0 || men > 5);
	
	return men;
} 

int menuGeneral () {
	int men;
	
	cout << endl;
	do {
		cout << "---------------" << endl;
		cout << "GESTION GENERAL" << endl;
		cout << "---------------" << endl;
		cout << "1.- Nuevo visionado" << endl;
		cout << "2.- Exportar lista de clientes" << endl;
		cout << "3.- Estadisticas de peliculas" << endl;	
		cout << "0.- Volver al menu anterior" << endl;
		cin >> men;
		cout << endl;
	} while (men < 0 || men > 3);
	
	return men;
}

// Funciones y procedimientos de incialización :

// Procedimiento para inicializar la lista de peliculas y la lista de clientes.
void inicializa (tListaPelis& listaPeliculas, tListaClientes& listaClientes, int capacidPels, int capacidClien) {
	
	listaPeliculas.peliculas = new tPelicula [capacidPels];
	listaPeliculas.tama = capacidPels;
	listaPeliculas.cont = 0;
	
	listaClientes.clientes = new tCliente [capacidClien];
	listaClientes.tama = capacidClien;
	listaClientes.contCli = 0;
}

// Función que cargar las películas iniciales en la lista e indica cuantas ha cargado.
int cargarPelis (ifstream& archivo, tListaPelis& listaPeliculas) {
	int aux, cargados = 0;
	char c;
	tPelicula auxP;
	
	archivo >> aux;
	while (aux != -1) {
		auxP.codigo = aux;
		archivo.get (c);		// Para no coger el salto de linea.
		archivo.getline (auxP.titulo, 40);
		archivo >> aux;
		auxP.genero = leerGeneroArchivo (aux);
		archivo >> auxP.duracion;
		archivo >> auxP.precio;
		archivo >> c;
		if (c == 'S') auxP.disponible = true;
		else auxP.disponible = false;
		
		while (listaPeliculas.cont >= listaPeliculas.tama) 
			aumentaListaPelis (listaPeliculas);

		listaPeliculas.peliculas [listaPeliculas.cont] = auxP;
		listaPeliculas.cont++;
		cargados++;
		archivo >> aux;
	}
	return cargados;
}

// Función que cargar los clientes iniciales en la lista e indica cuantas ha cargado.
int cargarClientes (ifstream& archivo, tListaClientes& listaClientes) {
	int aux, cargados = 0;
	char c;
	bool gusta;
	tCliente auxC;
	
	archivo.getline (auxC.nif, 30);
	while (auxC.nif [0] != 'X') {
		archivo.getline (auxC.nombre, 30);
		archivo.getline (auxC.apellidos, 30);
		archivo >> aux;
		auxC.genfavorito = leerGeneroArchivo (aux);
		// Introducir peliculas visionadas.
		auxC.pelisVistas.contador = 0;
		archivo >> aux;
		auxC.pelisVistas.contador = 0;
		while (aux != -1) {
			archivo >> c;	
			if (c == 'S') gusta = true;
			else gusta = false;
			altaVisionado (auxC, aux, gusta);
			archivo >> aux;
		}
			
		while (listaClientes.contCli >= listaClientes.tama) 
			aumentaListaClientes (listaClientes);

		listaClientes.clientes [listaClientes.contCli] = auxC;
		listaClientes.contCli++;
					 	
		cargados++;
		archivo.get (c);	// Para eliminar el salto de línea. 
		archivo.getline (auxC.nif, 30);
	}
	return cargados;
}


// Funciones y procedimientos de la gestión general :

// Funcion que recibe una lista de clientes y devuelve otra ordenada por apellidos.
tListaClientes ordenarClientesApellidos (tListaClientes listaClientes) {
	int i = 0;
	bool inter = true;
	tListaClientes auxClientes;
	tCliente auxClient;

	auxClientes = listaClientes;
	while ((i < auxClientes.contCli - 1) && (inter)) {
		inter = false; 
		for (int j = auxClientes.contCli - 1; j > i; j--)
			if (auxClientes.clientes [j - 1].apellidos > auxClientes.clientes [j].apellidos) {
				auxClient = auxClientes.clientes [j];
				auxClientes.clientes [j] = auxClientes.clientes [j - 1];
				auxClientes.clientes [j - 1] = auxClient;
				inter = true;
			}	
			if (inter) i++;
	}

	return auxClientes;
}

// Procedimiento que recibe una lista de clientes, otra de películas, un código, un nif, busca el cliente y la película y si exiten
// Y LA PELÍCULA ESTÁ DISPONIBLE esta se añade a la lista de visionados del cliente buscado con todos sus datos (código y gustado).
void nuevoVisionado (tListaClientes& listaClientes, tListaPelis listaPeliculas, int codigo, tCadena NIF) {
	 int posiCli, posiPeli;
	 bool encuentraPeli, encuentraClie, gustado;
	 char c;
	
	 posiPeli = buscarPelicula (listaPeliculas, codigo, encuentraPeli, 0, listaPeliculas.cont - 1);
	 posiCli = buscarCliente (listaClientes, NIF, encuentraClie, 0, listaClientes.contCli - 1);
			 
	 if (encuentraPeli)
		 cout << "La pelicula es : " << listaPeliculas.peliculas [posiPeli].titulo << endl;
	 else 
		 cout << "ERROR: Pelicula no registrada" << endl;
	 	 	 
	 if (encuentraClie) {
		 cout << "El cliente es : " << listaClientes.clientes [posiCli].nombre
		      << " " << listaClientes.clientes [posiCli].apellidos << endl;
	 }
	 else 
		 cout << "ERROR: Cliente no registrado" << endl;

	 if (!listaPeliculas.peliculas [posiPeli].disponible) {		// SI LA PELÍCULA HA SIDO DADA DE BAJA NO SE PUEDE VISIONAR.
		 encuentraPeli = false;
		 cout << "ERROR: La pelicula ha sido dada de baja, no se puede visionar" << endl;
	 }
				 
	 if (encuentraPeli && encuentraClie){
		  cout << "Le ha gustado la pelicula (S/N)?"; cin >> c;
		  c = toupper (c);
		  if (c == 'S') gustado = true;
		  else gustado = false;
		  altaVisionado (listaClientes.clientes [posiCli], listaPeliculas.peliculas [posiPeli].codigo, gustado);
		}
}

// Procedimiento que recibe un archivo y una lista de clientes y la copia al archivo.
void exportarClientes (ofstream& archivo, tListaClientes listaClientes) {
	tCliente auxClient;
		
	for (int i = 0; i < listaClientes.contCli; i++) {
		auxClient = listaClientes.clientes [i];
		archivo << "---------------------------------" << endl;
		archivo << "Nombre : " << auxClient.nombre << endl;
		archivo << "Apellidos : " << auxClient.apellidos << endl;
		archivo << "NIF : " << auxClient.nif << endl;
		archivo << "Genero favorito : " ;
		escribirGeneroArchivo (auxClient.genfavorito, archivo); 
		archivo << endl;
		archivo << "Peliculas visionadas : " << auxClient.pelisVistas.contador << endl;
	}
}

// Procedimientos que recibe la lista de clientes y de películas y por cada película de la lista muestro las veces que se ha visto 
// y las veces que ha gustado en total.
void estadisticaPeliculas (tListaClientes listaClientes, tListaPelis listaPeliculas) {
	int auxCod, auxVista, auxGusta, vista, gustado;
	double valora;
	
	for (int i = 0; i < listaPeliculas.cont; i++) {
		auxCod = listaPeliculas.peliculas [i].codigo;
		vista = 0;
		gustado = 0;
		for (int j = 0; j < listaClientes.contCli; j++) {
			datosVisionado (listaClientes.clientes [j], auxCod, auxVista, auxGusta);
			vista = vista + auxVista;
			gustado = gustado + auxGusta;
		}
		cout << listaPeliculas.peliculas [i].titulo  << endl;
		cout << "Veces vista : " << vista << endl;
		cout << "Veces que ha gustado : " << gustado << endl;
		if (vista != 0) valora = (gustado * 100 / vista);	
		else valora = 0;
		cout << "Valoracion : " << valora << " %" << endl;
		cout << "-------------------------------" << endl;
	}
}

// FUNCIONES Y PROCEDIMIENTOS DE LA PRÁCTICA 5 :

// Procedimientos para aumentar el tamaño de las listas de películas y clientes en caso de que las hayamos llenado :
void aumentaListaPelis (tListaPelis& listaPeliculas) {
	int nuevaCapacid = 0, capaci;
	pPelicula auxPunPel;

	capaci = listaPeliculas.tama;

	nuevaCapacid = (capaci * 3) / 2 + 1;
		
	auxPunPel = new tPelicula [nuevaCapacid];

	for (int i = 0; i < listaPeliculas.cont; i++)
		auxPunPel [i] = listaPeliculas.peliculas [i];
	
	delete [] listaPeliculas.peliculas;
		
	listaPeliculas.peliculas = new tPelicula [nuevaCapacid];

	for (int k = 0; k < listaPeliculas.cont; k++)
		listaPeliculas.peliculas [k] = auxPunPel [k];
	
	listaPeliculas.tama = nuevaCapacid;
	
	delete [] auxPunPel;
}

void aumentaListaClientes (tListaClientes& listaClientes) {
	int nuevaCapacid = 0, capaci;
	pClientes auxPunClie;

	capaci = listaClientes.tama;
	
	nuevaCapacid = (capaci * 3) / 2 + 1;
		
	auxPunClie = new tCliente [nuevaCapacid];

	for (int i = 0; i < listaClientes.contCli; i++)
		auxPunClie [i] = listaClientes.clientes [i];
	
	delete [] listaClientes.clientes;

	listaClientes.clientes = new tCliente [nuevaCapacid];

	for (int k = 0; k < listaClientes.contCli; k++) 
		listaClientes.clientes [k] = auxPunClie [k];
	
	listaClientes.tama = nuevaCapacid;

	delete [] auxPunClie;
}

// Funciones para guardar las listas de películas y clientes en un archivo binario que me devuelven un booleano indicando si la carga ha sido correcta o no :
bool guardarPeliculas (tListaPelis listaPeliculas) {
	fstream archivo;
	bool ok = true;
	int SIZE;
	char P[] = "pelis.dat";	
	archivo.open (P, ios::out | ios::binary | ios::trunc);
	
	if (archivo.is_open ()) {
		SIZE = sizeof (tPelicula);
		for (int i = 0; i < listaPeliculas.cont; i++)
			archivo.write ((char *) &listaPeliculas.peliculas [i], SIZE);
	}
	else ok = false;

	archivo.close ();

	return ok;
}

bool guardarClientes (tListaClientes listaClientes) {
	fstream archivo;
	bool ok = true;
	int SIZE;
	char C[] = "clientes.dat";	
	archivo.open (C, ios::out | ios::binary | ios::trunc);
	
	if (archivo.is_open()) {
		SIZE = sizeof (tCliente);
		for (int i = 0; i < listaClientes.contCli; i++) 
			archivo.write ((char *) &listaClientes.clientes [i], SIZE);
	}
	else ok = false;

	archivo.close ();

	return ok; 
}

// Procedimiento para destruir los punteros cuando salgamos del programa :
void destruir (tListaClientes& listaClientes, tListaPelis& listaPeliculas) {
	delete [] listaPeliculas.peliculas;
	listaPeliculas.cont = 0;
	
	delete [] listaClientes.clientes;
	listaClientes.clientes = 0;
}

// Funciones para cargar los datos a las listas desde los archivos binarios, nos devuelve un booleano indicando si la carga ha sido correcta o no :
bool cargarPelisBinario (tListaPelis& listaPeliculas, int& elementos) {
	fstream archivo;
	int SIZE;
	bool ok = false;
	char P[] = "pelis.dat";	

	elementos = 0;
	archivo.open (P, ios::in | ios::binary);
	
	if (archivo.is_open ()) {
		ok = true;
		SIZE = sizeof (tPelicula);
		
		archivo.seekg (0, ios::end);
		while ((archivo.tellg () / SIZE) > listaPeliculas.tama)
			aumentaListaPelis (listaPeliculas);
		
		archivo.seekg (0, ios::beg);
		while ((archivo.read ((char *) &listaPeliculas.peliculas [listaPeliculas.cont], SIZE))) {
			listaPeliculas.cont++;
			elementos++;
		}		
	}
	archivo.close ();

	return ok;
}

bool cargarClientesBinario (tListaClientes& listaClientes, int& elementos) {
	fstream archivo;
	int SIZE;
	bool ok = false;
	char C[] = "clientes.dat";	

	elementos = 0;
	archivo.open (C, ios::in | ios::binary);
	
	if (archivo.is_open ()) {
		ok = true;
		SIZE = sizeof (tCliente);
		
		archivo.seekg (0, ios::end);
		while ((archivo.tellg () / SIZE) > listaClientes.tama)
			aumentaListaClientes (listaClientes);
		
		archivo.seekg (0, ios::beg);
		while ((archivo.read ((char *) &listaClientes.clientes [listaClientes.contCli], SIZE))) {
			listaClientes.contCli++;
			elementos++;
		}
	}
	archivo.close ();

	return ok;
}

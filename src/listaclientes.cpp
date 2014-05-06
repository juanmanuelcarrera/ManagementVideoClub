// Juan Manuel Carrera García 

#include <iostream>
using namespace std;
#include "listaclientes.h"

bool listaClientesLlena (tListaClientes listaClientes) {
	return (listaClientes.contCli == listaClientes.tama);
}

int buscarCliente (tListaClientes listaClientes, tCadena dni, bool& encontrado, int ini, int fin) {
	int mitad, pos = -1;
	encontrado = false;
		
	if ((ini <= fin) && (!encontrado)){
		mitad = (ini + fin) / 2;

		if (strcmp (listaClientes.clientes [mitad].nif, dni) == 0) {
			pos = mitad;
			encontrado = true;
		}
		else 
			if (strcmp (listaClientes.clientes [mitad].nif, dni) > 0)
				pos = buscarCliente (listaClientes, dni, encontrado, ini, mitad - 1);
			else 
				pos = buscarCliente (listaClientes, dni, encontrado, mitad + 1, fin);
	}
	
	return pos;
}

bool insertarCliente (tCliente cliente, tListaClientes& listaClientes) {
	bool ok = true;  
	int i = 0;
	int posic = 0;
		
	while ((strcmp (listaClientes.clientes [i].nif, cliente.nif) <= 0) && (i < listaClientes.contCli)) {
		if (strcmp (listaClientes.clientes [i].nif, cliente.nif) == 0)
			ok = false;
		posic++;
		i++;
	}

	if (ok) {
		for (int j = listaClientes.contCli; j > posic; j--)
			listaClientes.clientes [j] = listaClientes.clientes [j - 1];
		listaClientes.clientes[posic] = cliente;
		listaClientes.contCli++;
	}
	
	return ok;
}

bool bajaCliente (tCadena dni, tListaClientes& listaClientes) {
	bool ok;
	int posi;

	posi = buscarCliente (listaClientes, dni, ok, 0, listaClientes.contCli - 1);

	if (ok) {
		for (int i = posi; i < listaClientes.contCli - 1; i++)
			listaClientes.clientes [i] = listaClientes.clientes [i + 1];	
		listaClientes.contCli--;
	}
		
	return ok;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funciones.h"
#include <Windows.h>
#define TAM_OPCIONES_PRINCIPALES 5
main() {
	void (*menuPuntero[TAM_OPCIONES_PRINCIPALES - 1])() = { mostrarMenuClientes,mostrarMenuServicios,hacerPresupuestos,hacerFacturas };

	mostrarOpcionesPrincipales();
	int opc = pedirOpcionPrincipal();
	
	while (opc!=TAM_OPCIONES_PRINCIPALES)
	{
		system("cls");
		(*menuPuntero[opc-1])();
		system("cls");
		mostrarOpcionesPrincipales();
		opc = pedirOpcionPrincipal();
	}
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funciones.h"
#include <Windows.h>
#define TAM_OPCIONES 5
void mostrarOpcionesPrincipales();
int pedirOpcionPrincipal();
main() {
	/*void (*menuPuntero[TAM_OPCIONES - 1])() = {mostrarMenuClientes,mostrarMenuServicios,presupuestos,facuracion};*/
	void (*menuPuntero[TAM_OPCIONES - 1])() = { funcion1,funcion2,funcion3,funcion4 };

	mostrarOpcionesPrincipales();
	int opc = pedirOpcionPrincipal();
	while (opc!=5)
	{
		(*menuPuntero[opc-1])();
		getch();
		system("cls");
		mostrarOpcionesPrincipales();
		opc = pedirOpcionPrincipal();
	}
}


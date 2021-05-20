#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funciones.h"
#include <Windows.h>
#define TAM_OPCIONES 5
main() {
	///*void (*menuPuntero[TAM_OPCIONES - 1])() = {mostrarMenuClientes,mostrarMenuServicios,presupuestos,facuracion};*/
	//void (*menuPuntero[TAM_OPCIONES - 1])() = { mostrarMenuClientes,mostrarMenuServicios,funcion3,funcion4 };

	//mostrarOpcionesPrincipales();
	//int opc = pedirOpcionPrincipal();
	//while (opc!=TAM_OPCIONES)
	//{
	//	system("cls");
	//	(*menuPuntero[opc-1])();
	//	system("cls");
	//	getch();
	//	mostrarOpcionesPrincipales();
	//	opc = pedirOpcionPrincipal();
	//}
	//CLIENTE reg;
	//int numSiguienteCliente=1;
	//pedirDatosCliente(numSiguienteCliente, &reg);
	//reg.nombre;

	//CLIENTE reg;
	//reg.nCliente = 1;
	//strcpy(reg.codigoPostal, "20100");
	//strcpy(reg.domicilio, "Arretxene 1");
	//strcpy(reg.municipio, "Lezo");
	//strcpy(reg.nombre, "Super");
	//strcpy(reg.nif, "999999");
	//pedirDatosModificarCliente(&reg);

	modificarCliente();
	
}


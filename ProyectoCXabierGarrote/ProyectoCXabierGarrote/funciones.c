#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funciones.h"

void mostrarOpcionesPrincipales()
{
	GotoXY(5, 0);
	printf("MENU DE FACURACION\n");
	GotoXY(7, 1);
	printf("1-Clientes\n");
	GotoXY(7, 2);
	printf("2-Servicios\n");
	GotoXY(7, 3);
	printf("3-Presupuestos\n");
	GotoXY(7, 4);
	printf("4-Facuracion\n");
	GotoXY(7, 5);
	printf("5-Salir\n");
}
int pedirOpcionPrincipal() {
	int opc;
	printf("Introduce Opcion: [ ]");
	do
	{
		GotoXY(19, 6);
		scanf("%d", &opc);
	} while (opc < 1 || opc>6);
	return opc;
}
void GotoXY(int x, int  y)
{
	COORD p;/*Cordenadas pa posicionar*/
	p.X = x;
	p.Y = y;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);/*Manejador del sistema en la consola*/
	SetConsoleCursorPosition(h, p);
}

void funcion1() {
	printf("Funcion1");
}
void funcion2() {
	printf("Funcion2");
}
void funcion3() {
	printf("Funcion3");
}
void funcion4() {
	printf("Funcion4");
}

void mostrarMenuClientes(){
	void (*menuPuntero[TAM_OPCIONES_CLIENTES - 1])() = { funcion1,funcion2,funcion3};

	mostrarOpcionesClientes();
	int opc = pedirOpcionClientes();
	while (opc != TAM_OPCIONES_CLIENTES)
	{
		system("cls");
		(*menuPuntero[opc - 1])();
		getch();
		mostrarOpcionesClientes();
		opc = pedirOpcionClientes();
	}
}
void mostrarOpcionesClientes() {
	GotoXY(5, 0);
	printf("MENU DE CLIENTES\n");
	GotoXY(7, 1);
	printf("1-ALTAS\n");
	GotoXY(7, 2);
	printf("2-MODIFICAR\n");
	GotoXY(7, 3);
	printf("3-CONSULTAR\n");
	GotoXY(7, 4);
	printf("4-SALIR\n");
}
int pedirOpcionClientes() {
	int opc;
	printf("Introduce Opcion: [ ]");
	do
	{
		GotoXY(19, 5);
		scanf("%d", &opc);
	} while (opc < 1 || opc>4);
	return opc;
}

void mostrarMenuServicios() {
	void (*menuPuntero[TAM_OPCIONES_SERVICIOS - 1])() = { funcion1,funcion2,funcion3 };

	mostrarOpcionesServicios();
	int opc = pedirOpcionServicios();
	while (opc != TAM_OPCIONES_SERVICIOS)
	{
		system("cls");
		(*menuPuntero[opc - 1])();
		getch();
		mostrarOpcionesServicios();
		opc = pedirOpcionServicios();
	}
}

int pedirOpcionServicios() {
	int opc;
	printf("Introduce Opcion: [ ]");
	do
	{
		GotoXY(19, 5);
		scanf("%d", &opc);
	} while (opc < 1 || opc>4);
	return opc;
}

void mostrarOpcionesServicios() {
	GotoXY(5, 0);
	printf("MENU DE SERVICIOS\n");
	GotoXY(7, 1);
	printf("1-ALTAS\n");
	GotoXY(7, 2);
	printf("2-MODIFICAR\n");
	GotoXY(7, 3);
	printf("3-CONSULTAR\n");
	GotoXY(7, 4);
	printf("4-SALIR\n");
}

void darDeAltaCliente() {

}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funciones.h"
#include <windows.h>
void mostrarMenu()
{
	printf("MENU FACURACION\n");
	printf("1-Clientes\n2-Servicios\n");
	printf("3-Presupuestos\n4-Facuracion\n5-Salir\n");
}
int pedirOpcion() {
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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#define TAM_OPCIONES 5
void mostrarMenu();
int pedirOpcion();
main() {
	void (*menuPuntero[TAM_OPCIONES - 1])() = {mostrarMenuClientes,mostrarMenuServicios,presupuestos,facuracion};
	
	mostrarMenu();
	int opc = pedirOpcion();
	while (opc!=5)
	{
		(*menuPuntero[opc-1])();
		mostrarMenu();
		opc = pedirOpcion();
	}
}

void mostrarMenu()
{
	printf("MENU FACURACION\n");
	printf("1-Clientes\n2-Servicios\n");
	printf("3-Presupuestos\n4-Facuracion\n5-Salir");
}
int pedirOpcion() {
	int opc;
	printf("\nIntroduce Opcion: [ ]");
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


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define OPCIONES 5
main() {

	void (*menuPuntero[OPCIONES - 1])() = {mostrarMenuClientes,mostrarMenu };
	mostrarMenu();
	int opc = pedirOpcion();
	while (opc!=5)
	{

		menuPuntero[opc];
		mostrarMenu();
		opc = pedirOpcion();
	}


}
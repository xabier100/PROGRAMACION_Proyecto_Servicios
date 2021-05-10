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
	FILE* pf;
	CLIENTE reg;
	/*Intentamos abrir el fichero en modo lectura escritura*/
	pf= fopen(RUTA_CLIENTES, "rb+");
	if (pf==NULL)/*Si da error intentamor abrirlo en modo lectura*/
	{
		pf = fopen(RUTA_CLIENTES, "wb");
		if (pf==NULL)/*Si da error imprimir mensaje error*/
		{
			printf("Error de apertura");
			return;
		}
	}
	
	int tamFichero = calcularTamañoFichero(pf);

	/*Calcular numero del siguiente cliente*/
	int numSiguienteCliente = tamFichero / sizeof(reg);

	/*Sacamos formulario de pedir datos del cliente*/
	pedirDatosCliente(numSiguienteCliente, &reg);

	/*Posicionarnos al final del fichero*/
	fseek(pf, tamFichero, SEEK_SET);

	/*Escribir el registro*/
	fwrite(&reg, sizeof(reg), 1, pf);

	/*Cerrar el fichero*/
	fclose(pf);

	/*Imprimir mensaje diciendo cliente insertado con exito*/
	printf("Cliente insertado con exito");
}

long calcularTamañoFichero(FILE *pf) {
	long tam;
	/* posicionamiento en el final del fichero  */
	fseek(pf, 0, SEEK_END);    
	/* almacena el valor del indicador de posición  */
	tam = ftell(pf);            
	/* situa el indicador de posición al
	principio del fichero */
	fseek(pf, 0, SEEK_SET); 
	/* calcula la diferencia entre el principio y  el
	final */
	tam -= ftell(pf);                    
	return tam;
}

void modificarCliente() {
	FILE* pf;
	CLIENTE reg;
	/*Intentamos abrir el fichero en modo lectura escritura*/
	pf= fopen(RUTA_CLIENTES, "rb+");

	if (pf == NULL) {/*Si da error es imposible modificar porque no existe el fichero*/
		printf("Error no se puede modificar ningun cliente porque no existe el fichero");
		return;
	}
	int tamFichero = calcularTamañoFichero(pf);

	/*Calcular numero del ultimo cliente*/
	int numUltimoCliente = tamFichero / sizeof(reg);
	
	/*Pedir numero cliente*/
	int pos = pedirNumCliente();

	if (pos<1||pos>numUltimoCliente)
	{
		printf("Error el numero de cliente no esta entre los existentes");
		return;
	}
	
	/*Nos situamos en el cliente que nos ha insertado el usuario */
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Leemos los datos del cliente solicitado*/
	fread(&reg, sizeof(reg), 1, pf);

	pedirDatosModificar(&reg);

	/*Nos situamos en el fichero*/
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Insertamos el cliente con los datos modificados*/
	fwrite(&reg, sizeof(reg), 1, pf);

	/*Cerramos el fichero*/
	fclose(pf);

	/*Imprimir mensaje confirmando que todo ha salido bien*/
	printf("Cliente modificado con exito");
}

void consultarCliente() {
	FILE* pf;
	CLIENTE reg;
	/*Intentamos abrir el fichero en modo lectura escritura*/
	pf = fopen(RUTA_CLIENTES, "rb+");

	if (pf == NULL) {/*Si da error es imposible modificar porque no existe el fichero*/
		printf("Error no se puede modificar ningun cliente porque no existe el fichero");
		return;
	}
	int tamFichero = calcularTamañoFichero(pf);

	/*Calcular numero del ultimo cliente*/
	int numUltimoCliente = tamFichero / sizeof(reg);

	/*Pedir numero cliente*/
	int pos = pedirNumCliente();

	if (pos<1 || pos>numUltimoCliente)
	{
		printf("Error el numero de cliente no esta entre los existentes");
		return;
	}
	/*Nos situamos en el cliente que nos ha insertado el usuario */
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Leemos los datos del cliente solicitado*/
	fread(&reg, sizeof(reg), 1, pf);

	imprimirDatos(reg);

	printf("Desea continuar?");

	getch();
}

void darDeAltaServicio() {
	FILE* pf;
	SERVICIO reg;
	/*Intentamos abrir el fichero en modo lectura escritura*/
	pf = fopen(RUTA_SERVICIOS, "rb+");
	if (pf == NULL)/*Si da error intentamor abrirlo en modo lectura*/
	{
		pf = fopen(RUTA_SERVICIOS, "wb");
		if (pf == NULL)/*Si da error imprimir mensaje error*/
		{
			printf("Error de apertura");
			return;
		}
	}

	int tamFichero = calcularTamañoFichero(pf);

	/*Calcular numero del siguiente servicio*/
	int numSiguienteServicio = tamFichero / sizeof(reg);

	/*Sacamos formulario de pedir datos del servicio*/
	pedirDatosServicio(numSiguienteServicio, &reg);

	/*Posicionarnos al final del fichero*/
	fseek(pf, tamFichero, SEEK_SET);

	/*Escribir el registro*/
	fwrite(&reg, sizeof(reg), 1, pf);

	/*Cerrar el fichero*/
	fclose(pf);

	/*Imprimir mensaje diciendo servicio insertado con exito*/
	printf("Servicio insertado con exito");
}

void modificarServicio() {

	/*----------------------------------------------------
	Esta funcion falta por ponerla bien porque he
	copiado la estructura de modificar cliente importante
	----------------------------------------------------*/


	FILE* pf;
	SERVICIO reg;
	/*Intentamos abrir el fichero en modo lectura escritura*/
	pf = fopen(RUTA_SERVICIOS, "rb+");

	if (pf == NULL) {/*Si da error es imposible modificar porque no existe el fichero*/
		printf("Error no se puede modificar ningun servicio porque no existe el fichero");
		return;
	}
	int tamFichero = calcularTamañoFichero(pf);

	/*Calcular numero del ultimo cliente*/
	int numUltimoServicio = tamFichero / sizeof(reg);

	/*Pedir numero cliente*/
	int pos = pedirNumServicio();

	if (pos<1 || pos>numUltimoServicio)
	{
		printf("Error el numero de cliente no esta entre los existentes");
		return;
	}

	/*Nos situamos en el cliente que nos ha insertado el usuario */
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Leemos los datos del cliente solicitado*/
	fread(&reg, sizeof(reg), 1, pf);

	pedirDatosModificar(&reg);

	/*Nos situamos en el fichero*/
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Insertamos el cliente con los datos modificados*/
	fwrite(&reg, sizeof(reg), 1, pf);

	/*Cerramos el fichero*/
	fclose(pf);

	/*Imprimir mensaje confirmando que todo ha salido bien*/
	printf("Cliente modificado con exito");

}
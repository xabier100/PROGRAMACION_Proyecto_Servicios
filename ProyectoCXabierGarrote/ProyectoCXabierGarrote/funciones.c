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
	int posSiguienteCliente = tamFichero / sizeof(reg);

	/*Sacamos formulario de pedir datos del cliente*/
	pedirDatosCliente(posSiguienteCliente+1, &reg);

	/*Posicionarnos al final del fichero*/
	fseek(pf, tamFichero, SEEK_SET);

	/*Escribir el registro*/
	fwrite(&reg, sizeof(reg), 1, pf);

	/*Cerrar el fichero*/
	fclose(pf);

	/*Imprimir mensaje diciendo cliente insertado con exito*/
	printf("\nCliente insertado con exito");

	getch();
}

void pedirDatosCliente(int numSiguienteCliente, CLIENTE* reg)
{
	//Mostrar cabecera
	GotoXY(20, 0);
	printf("FICHERO CLIENTES");
	
	//Almacenar numero del siguiente cliente y mostrarlo
	GotoXY(0, 2);
	reg->nCliente = numSiguienteCliente;
	printf("%15s : %d ","NºCliente",numSiguienteCliente);

	//Pedir nombre
	GotoXY(0, 4);
	printf("%15s :","Nombre");
	GotoXY(17, 4);
	gets(reg->nombre);
	
	//Pedir domicilio
	GotoXY(0, 6);
	printf("%15s :", "Domicilio");
	GotoXY(17, 6);
	gets(reg->domicilio);

	//Pedir codigo postal
	GotoXY(0, 8);
	printf("%15s :", "Codigo Postal");
	GotoXY(17, 8);
	gets(reg->codigoPostal);

	//Pedir municipio
	GotoXY(0, 10);
	printf("%15s :", "Municipio");
	GotoXY(17, 10);
	gets(reg->municipio);

	//Pedir nif
	GotoXY(0, 12);
	printf("%15s :", "NIF");
	GotoXY(17, 12);
	gets(reg->nif);
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

//void modificarCliente() {
//	FILE* pf;
//	CLIENTE reg;
//	/*Intentamos abrir el fichero en modo lectura escritura*/
//	pf= fopen(RUTA_CLIENTES, "rb+");
//
//	if (pf == NULL) {/*Si da error es imposible modificar porque no existe el fichero*/
//		printf("Error no se puede modificar ningun cliente porque no existe el fichero");
//		return;
//	}
//	int tamFichero = calcularTamañoFichero(pf);
//
//	/*Calcular numero del ultimo cliente*/
//	int numUltimoCliente = tamFichero / sizeof(reg);
//	
//	/*Pedir numero cliente*/
//	int pos = pedirNumCliente();
//
//	if (pos<1||pos>numUltimoCliente)
//	{
//		printf("Error el numero de cliente no esta entre los existentes");
//		return;
//	}
//	
//	/*Nos situamos en el cliente que nos ha insertado el usuario */
//	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);
//
//	/*Leemos los datos del cliente solicitado*/
//	fread(&reg, sizeof(reg), 1, pf);
//
//	pedirDatosModificarCliente(&reg);
//
//	/*Nos situamos en el fichero*/
//	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);
//
//	/*Insertamos el cliente con los datos modificados*/
//	fwrite(&reg, sizeof(reg), 1, pf);
//
//	/*Cerramos el fichero*/
//	fclose(pf);
//
//	/*Imprimir mensaje confirmando que todo ha salido bien*/
//	printf("Cliente modificado con exito");
//}
//
void consultarCliente() {
	FILE* pf;
	CLIENTE reg;

	/*Intentamos abrir el fichero en modo lectura */
	pf = fopen(RUTA_CLIENTES, "rb");

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
		getch();
		return;
	}
	/*Nos situamos en el cliente que nos ha insertado el usuario */
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Leemos los datos del cliente solicitado*/
	fread(&reg, sizeof(reg), 1, pf);

	imprimirDatosCliente(reg);

	fclose(pf);

	GotoXY(0, 14);
	printf("Desea continuar?");

	getch();
}


void imprimirDatosCliente(CLIENTE reg) {
	GotoXY(20, 0);
	printf("CONSULTA CLIENTES");

	GotoXY(0, 2);
	printf("%15s : %d ", "NºCliente", reg.nCliente);

	GotoXY(0, 4);
	printf("%15s : %-20s", "Nombre",reg.nombre);

	GotoXY(0, 6);
	printf("%15s : %-20s", "Domicilio",reg.domicilio);

	GotoXY(0, 8);
	printf("%15s : %-10s", "Codigo Postal",reg.codigoPostal);

	GotoXY(0, 10);
	printf("%15s : %-15s", "Municipio",reg.municipio);

	GotoXY(0, 12);
	printf("%15s : %-10s", "NIF",reg.nif);
}

int pedirNumCliente() {
	int numCliente;
	printf("Introduzca numero de cliente: ");
	scanf("%d", &numCliente);
	return numCliente;
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
	int posSiguienteServicio = tamFichero / sizeof(reg);

	/*Sacamos formulario de pedir datos del servicio*/
	pedirDatosServicio(posSiguienteServicio+1, &reg);

	/*Posicionarnos al final del fichero*/
	fseek(pf, tamFichero, SEEK_SET);

	/*Escribir el registro*/
	fwrite(&reg, sizeof(reg), 1, pf);

	/*Cerrar el fichero*/
	fclose(pf);

	/*Imprimir mensaje diciendo servicio insertado con exito*/
	printf("Servicio insertado con exito");
}

void pedirDatosServicio(int numSiguienteServicio, SERVICIO* reg) {
	//Mostrar cabecera
	GotoXY(20, 0);
	printf("FICHERO SERVICIOS");

	//Almacenar numSiguienteServicio y mostrarlo
	GotoXY(0, 2);
	reg->nServicio = numSiguienteServicio;
	printf("%15s : %d ", "N.Servicio", numSiguienteServicio);

	//Pedir denominacion
	GotoXY(0, 4);
	printf("%15s :", "Denominacion");
	GotoXY(17, 4);
	gets(reg->denominacion);

	//Pedir precio coste
	GotoXY(0, 6);
	printf("%15s :", "Precio Coste");
	GotoXY(17, 6);
	scanf("%f", &reg->precioCoste);

	//Pedir pvp
	GotoXY(0, 8);
	printf("%15s :", "PVP");
	GotoXY(17, 8);
	scanf("%f", &reg->pvp);
}

//void modificarServicio() {
//	FILE* pf;
//	SERVICIO reg;
//	/*Intentamos abrir el fichero en modo lectura escritura*/
//	pf = fopen(RUTA_SERVICIOS, "rb+");
//
//	if (pf == NULL) {/*Si da error es imposible modificar porque no existe el fichero*/
//		printf("Error no se puede modificar ningun servicio porque no existe el fichero");
//		return;
//	}
//	int tamFichero = calcularTamañoFichero(pf);
//
//	/*Calcular numero del ultimo cliente*/
//	int numUltimoServicio = tamFichero / sizeof(reg);
//
//	/*Pedir numero cliente*/
//	int pos = pedirNumServicio();
//
//	if (pos<1 || pos>numUltimoServicio)
//	{
//		printf("Error el numero de cliente no esta entre los existentes");
//		return;
//	}
//
//	/*Nos situamos en el cliente que nos ha insertado el usuario */
//	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);
//
//	/*Leemos los datos del cliente solicitado*/
//	fread(&reg, sizeof(reg), 1, pf);
//
//	pedirDatosModificarServicio(&reg);
//
//	/*Nos situamos en el fichero*/
//	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);
//
//	/*Insertamos el cliente con los datos modificados*/
//	fwrite(&reg, sizeof(reg), 1, pf);
//
//	/*Cerramos el fichero*/
//	fclose(pf);
//
//	/*Imprimir mensaje confirmando que todo ha salido bien*/
//	printf("Cliente modificado con exito");
//}
//
void consultarServicio() {
	FILE* pf;
	SERVICIO reg;
	/*Intentamos abrir el fichero en modo lectura*/
	pf = fopen(RUTA_SERVICIOS, "rb");

	if (pf == NULL) {/*Si da error es imposible modificar porque no existe el fichero*/
		printf("Error no se puede consultar ningun servicio porque no existe el fichero");
		return;
	}
	int tamFichero = calcularTamañoFichero(pf);

	/*Calcular numero del ultimo servicio*/
	int numUltimoServicio = tamFichero / sizeof(reg);

	/*Pedir numero servicio*/
	int pos = pedirNumServicio();

	/*Si el numero de servicio no existe*/
	if (pos<1 || pos>numUltimoServicio)
	{
		printf("Error el numero de servicio no esta entre los existentes");
		getche();
		fclose(pf);
		return;
	}
	/*Nos situamos en el servicio que nos ha insertado el usuario */
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Leemos los datos del servicio solicitado*/
	fread(&reg, sizeof(reg), 1, pf);

	imprimirDatosServicio(reg);

	fclose(pf);

	printf("Desea continuar?");

	getche();
}

void imprimirDatosServicio(SERVICIO reg) {
	//Imprimir cabecera
	GotoXY(20, 0);
	printf("CONSULTA SERVICIOS");

	//Imprimir numero de servicio
	GotoXY(0, 2);
	printf("%15s : %d ", "N.Servicio", reg.nServicio);

	//Imprimir denominacion
	GotoXY(0, 4);
	printf("%15s : %-20s", "Denominacion", reg.denominacion);

	//Imprimir precio coste
	GotoXY(0, 6);
	printf("%15s : %-10.2f", "Precio coste", reg.precioCoste);

	//Imprimir pvp
	GotoXY(0, 8);
	printf("%15s : %-10.2f", "PVP", reg.pvp);
}

int pedirNumServicio() {
	int nServicio;
	printf("Introduzca numero de servicio: ");
	scanf("%d", &nServicio);
	return nServicio;
}
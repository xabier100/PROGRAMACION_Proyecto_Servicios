#define _CRT_SECURE_NO_WARNINGS
#include "funciones.h"
#include <stdio.h>
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
	rewind(stdin);
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

void mostrarMenuClientes(){
	void (*menuPuntero[TAM_OPCIONES_CLIENTES - 1])() = { darDeAltaCliente,modificarCliente,consultarCliente};

	mostrarOpcionesClientes();
	int opc = pedirOpcionClientes();
	while (opc != TAM_OPCIONES_CLIENTES)
	{
		system("cls");
		(*menuPuntero[opc - 1])();
		system("cls");
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
	rewind(stdin);
	return opc;
}

void mostrarMenuServicios() {
	void (*menuPuntero[TAM_OPCIONES_SERVICIOS - 1])() = { darDeAltaServicio,modificarServicio,consultarServicio };

	mostrarOpcionesServicios();
	int opc = pedirOpcionServicios();
	while (opc != TAM_OPCIONES_SERVICIOS)
	{
		system("cls");
		(*menuPuntero[opc - 1])();
		system("cls");
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
	rewind(stdin);
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

	pedirConfirmacionCliente();
	char resp = toupper(getch());
	/*Si la respuesta es si*/
	if (resp == 'S') {
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
}

void pedirConfirmacionCliente() {
	printf("¿Desea insertar este cliente?");
}

void pedirDatosCliente(int numSiguienteCliente, CLIENTE* reg)
{
	//Mostrar cabecera
	GotoXY(20, 0);
	printf("FICHERO CLIENTES");
	
	//Almacenar numero del siguiente cliente y mostrarlo
	GotoXY(0, 2);
	reg->nCliente = numSiguienteCliente;
	printf("%15s : %d ","N.Cliente",numSiguienteCliente);

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
		getche();
		return;
	}
	
	/*Nos situamos en el cliente que nos ha insertado el usuario */
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Leemos los datos del cliente solicitado*/
	fread(&reg, sizeof(reg), 1, pf);

	system("cls");
	pedirDatosModificarCliente(&reg);

	/*Nos situamos en el fichero*/
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Insertamos el cliente con los datos modificados*/
	fwrite(&reg, sizeof(reg), 1, pf);

	/*Cerramos el fichero*/
	fclose(pf);

	/*Imprimir mensaje confirmando que todo ha salido bien*/
	printf("Cliente modificado con exito");
}
void pedirDatosModificarCliente(CLIENTE* reg)
{
	void(*punteroOpcionesACambiar[5])(CLIENTE *reg) = { pedirNombre,pedirDomicilio,pedirCodigoPostal,pedirMunicipio,pedirNif };

	imprimirDatosModificablesCliente(reg);
	int opc = pedirOpcionModificarCliente();
	
	while (opc != 6) {
		system("cls");
		(*punteroOpcionesACambiar[opc - 1])(reg);
		printf("Dato modificado con exito\n");
		printf("Continuar?");
		getche();
		system("cls");
		imprimirDatosModificablesCliente(reg);
		opc = pedirOpcionModificarCliente();
	}

}
int pedirOpcionModificarCliente()
{
	int opc;
	do {
		printf("\n\nIntroduzca que dato del cliente desea modificar: ");
		scanf("%d", &opc);
	} while (opc < 1 || opc>6);
	rewind(stdin);
	return opc;
}
void imprimirDatosModificablesCliente(CLIENTE* reg)
{
	GotoXY(20, 0);
	printf("MODIFICACION CLIENTE");

	GotoXY(0, 2);
	printf("  %15s : %d ", "N.Cliente", reg->nCliente);

	GotoXY(0, 4);
	printf("%d  %15s : %-20s", 1, "Nombre", reg->nombre);

	GotoXY(0, 6);
	printf("%d  %15s : %-20s", 2, "Domicilio", reg->domicilio);

	GotoXY(0, 8);
	printf("%d  %15s : %-10s", 3, "Codigo Postal", reg->codigoPostal);

	GotoXY(0, 10);
	printf("%d  %15s : %-15s", 4, "Municipio", reg->municipio);

	GotoXY(0, 12);
	printf("%d  %15s : %-10s", 5, "NIF", reg->nif);

	GotoXY(0, 14);
	printf("%d  %15s : ", 6, "SALIR");
}
void pedirNombre(CLIENTE* reg) {
	printf("Introduzca nombre: ");
	gets(reg->nombre);
}
void pedirDomicilio(CLIENTE* reg) {
	printf("Introduzca domicilio: ");
	gets(reg->domicilio);
}
void pedirCodigoPostal(CLIENTE* reg) {
	printf("Introduzca codigo postal: ");
	gets(reg->codigoPostal);
}
void pedirMunicipio(CLIENTE* reg) {
	printf("Introduzca municipio: ");
	gets(reg->municipio);
}
void pedirNif(CLIENTE* reg) {
	printf("Introduzca nif: ");
	gets(reg->nif);
}


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
	system("cls");
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

	pedirConfirmacionServicio();
	char resp = toupper(getch());

	if (resp == 'S') {
		/*Posicionarnos al final del fichero*/
		fseek(pf, tamFichero, SEEK_SET);

		/*Escribir el registro*/
		fwrite(&reg, sizeof(reg), 1, pf);

		/*Cerrar el fichero*/
		fclose(pf);

		/*Imprimir mensaje diciendo servicio insertado con exito*/
		printf("Servicio insertado con exito");
	}
}
void pedirConfirmacionServicio()
{
	printf("Desea guardar el servicio?");
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

void modificarServicio() {
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
		getch();
		return;
	}

	/*Nos situamos en el cliente que nos ha insertado el usuario */
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Leemos los datos del cliente solicitado*/
	fread(&reg, sizeof(reg), 1, pf);

	system("cls");
	pedirDatosModificarServicio(&reg);

	/*Nos situamos en el fichero*/
	fseek(pf, sizeof(reg) * (pos - 1), SEEK_SET);

	/*Insertamos el cliente con los datos modificados*/
	fwrite(&reg, sizeof(reg), 1, pf);

	/*Cerramos el fichero*/
	fclose(pf);

	/*Imprimir mensaje confirmando que todo ha salido bien*/
	printf("Cliente modificado con exito");
}
void pedirDatosModificarServicio(SERVICIO *reg) {

	void(*punteroOpcionesACambiar[3])(SERVICIO * reg) = {pedirDenominacion,pedirPrecioCoste,pedirPVP};
	imprimirDatosModificablesServicio(reg);

	int opc = pedirOpcionModificarServicio();

	while (opc != 4) {
		system("cls");
		(*punteroOpcionesACambiar[opc - 1])(reg);
		printf("Dato modificado con exito");
		printf("\nDesea continuar?");
		getche();
		system("cls");
		imprimirDatosModificablesServicio(reg);
		opc = pedirOpcionModificarServicio();
	}
}
int pedirOpcionModificarServicio() {
	int opc;
	do {
		printf("\n\nIntroduzca que dato deseas modificar?");
		scanf("%d", &opc);
	} while (opc < 1 || opc>4);
	rewind(stdin);
	return opc;
}
void imprimirDatosModificablesServicio(SERVICIO* reg)
{
	//Imprimir cabecera
	GotoXY(20, 0);
	printf("MODIFICACION SERVICIOS");

	//Imprimir numero de servicio
	GotoXY(0, 2);
	printf("%15s : %d ", "N.Servicio", reg->nServicio);

	//Imprimir denominacion
	GotoXY(0, 4);
	printf("%d %15s : %-20s", 1, "Denominacion", reg->denominacion);

	//Imprimir precio coste
	GotoXY(0, 6);
	printf("%d %15s : %-10.2f", 2, "Precio coste", reg->precioCoste);

	//Imprimir pvp
	GotoXY(0, 8);
	printf("%d %15s : %-10.2f", 3, "PVP", reg->pvp);

	GotoXY(0, 10);
	printf("%d %15s :", 4, "SALIR");

}
void pedirDenominacion(SERVICIO* reg) {
	printf("Introduzca denominacion: ");
	gets(reg->denominacion);
}
void pedirPrecioCoste(SERVICIO* reg) {
	printf("Introduzca precio coste: ");
	scanf("%f", &reg->precioCoste);
}
void pedirPVP(SERVICIO* reg) {
	printf("Introduzca PVP: ");
	scanf("%f", &reg->pvp);
}

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

	system("cls");
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

void hacerPresupuestos() {
	printf("Opcion NO implementada por falta de tiempo :(");
	getche();
}
void hacerFacturas() {
	printf("Opcion no implementada por falta de tiempo :(");
	getche();
}
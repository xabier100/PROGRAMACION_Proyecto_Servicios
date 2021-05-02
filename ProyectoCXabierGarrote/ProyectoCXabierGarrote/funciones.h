#pragma once
#include <windows.h>
#define TAM_OPCIONES_CLIENTES 4
#define TAM_OPCIONES_SERVICIOS 4
#define RUTA_CLIENTES "clientes.dat"
#define TAM_FICHERO_CLIENTES 100
/*Definimos la estructura cliente con 
sus correspondientes constantes*/
#define TAM_CLIENTE_NOMBRE 20
#define TAM_CLIENTE_DOMICILIO 20
#define TAM_CLIENTE_CP 5
#define TAM_CLIENTE_MUNICIPIO 15
#define TAM_CLIENTE_NIF 10
typedef struct {
	int nCliente;
	char nombre[TAM_CLIENTE_NOMBRE];
	char domicilio[TAM_CLIENTE_DOMICILIO];
	char codigoPostal[TAM_CLIENTE_CP];
	char municipio[TAM_CLIENTE_MUNICIPIO];
	char nif[TAM_CLIENTE_NIF];
}CLIENTE;
void mostrarOpcionesPrincipales();
int pedirOpcionPrincipal();
void GotoXY(int x, int  y);
void funcion1();
void funcion2();
void funcion3();
void funcion4();
void mostrarMenuClientes();
void mostrarOpcionesClientes();
int pedirOpcionClientes();
void mostrarMenuServicios();
void mostrarOpcionesServicios();
int pedirOpcionServicios();
void darDeAltaCliente();
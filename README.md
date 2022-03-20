PRACTICA  DE  LENGUAJE  C  EN  Windows.





Una empresa desea mecanizar, en parte, su proceso de facturación de la siguiente forma:

•	Introducirá los datos de sus clientes.
•	Introducirá los datos de sus servicios.
•	Introducirá diariamente, los presupuestos aceptados por sus clientes.
•	Al final de la semana desea que se le faciliten las facturas correspondientes a los servicios realizados durante la semana y un listado resumen de la facturación.

Para implementar esta simple mecanización  procederemos como sigue:

Escribiremos UN MAIN para sacar el menú en pantalla y llamar a ejecutar el programa correspondiente a cada opción:


MENU DE FACTURACION

1  Clientes
2  Servicios
3  Presupuestos
4  Facturación
5  Salir







 
PROGRAMA DE CLIENTES:

 

	FICHERO  DE  CLIENTES: 	
	DATO	CAMPO	TIPO	TAMAÑO	
	Nº Cliente		int		
	Nombre		char	20	
	Domicilio		char	20	
	Código Postal		char	5	
	Municipio		char	15	
	N.I.F.		char	10	


	PANTALLAS  DEL  PROGRAMA:
	
	FICHERO DE CLIENTES
	
	Nº Cliente	:  xxx
	
	Nombre	:  xxxxxxxxxxxxxxxxxxxx
	
	Domicilio	:  xxxxxxxxxxxxxxxxxxxx
	
	Cod. Postal	:  xxxxx
	
	Municipio	:  xxxxxxxxxxxxxxx
	
	N.I.F.	:  xxxxxxxxxx
	
	
(Línea de mansajes)
	


	MENU  DE  CLIENTES
	
	1  ALTAS
	
	2  MODIFICAR
	
	3  CONSULTAR
	
	4  SALIR
	
		


PSEUDOCÓDIGO:

Sacar el menu en pantalla y pedir opción.

Hacer mientras no tecleeen la opción de salir.
	
	Si opción es 1: ¿Dónde se inicializa el fichero?--Calcular el tamaño del fichero y de ahí sacar cuantos registros ahí.
		
		Mirar si existe el fichero.
		
		Calcular nº del último registro grabado.
		
		Abrir fichero para añadir registros
		
		Sacar pantalla de petición de datos y nº del siguiente cliente
		
		Pedir resto de los datos
		
		Pedir conformidad y grabar si está conforme.
		
		Cerrar el fichero y salir al menú
	
	Si opción es 2:
		
		Mirar si existe el fichero.
		
		Calcular nº del último registro grabado.
		
		Abrir fichero para leer 
		
		Sacar pantalla de datos y pedir Nº Cliente
		
		Si el Nº Cliente está dentro de los límites 
			
			Visualizar el resto de los datos
			
			Pedir datos a modificar
			
			Pedir conformidad y regrabar si está conforme
		
		Si no está dentro de los límites, mensaje de error
		
		Cerrar el fichero y salir al menú
	
	Si opción es 3:
		
		Mirar si existe el fichero.
		
		Calcular nº del último registro grabado.
		
		Abrir fichero para leer 
		
		Sacar pantalla de datos y pedir Nº Cliente
		
		Si el Nº Cliente está dentro de los límites 
			
			Visualizar el resto de los datos
			
			Pedir continuar 
		
		Si no está dentro de los límites, mensaje de error
		
		Cerrar el fichero y salir al menú
Fin de Hacer mientras

 
PROGRAMA DE SERVICIOS:

 

	FICHERO  DE  SERVICIOS: 	
	DATO	CAMPO	TIPO	TAMAÑO	
	Nº Servicio		int		
	Denominación		char	20	
	Precio Coste		Float		
	P.V.P. 	Precio/hora	float		


	PANTALLAS  DEL  PROGRAMA:
	
	FICHERO DE SERVICIOS
	
	Nº Servicio	:  xxx
	
	Denominación	:  xxxxxxxxxxxxxxxxxxxx
	
	Precio Coste	:  xx.xxx
	
	P.V.P.	:  xx.xxx
	
	



(Línea de mansajes)
	


	MENU  DE  SERVICIOS
	
	1  ALTAS
	
	2  MODIFICAR
	
	3  CONSULTAR
	
	4  SALIR
	
		

 
PSEUDOCÓDIGO:

Sacar el menu en pantalla y pedir opción.

Hacer mientras no tecleeen la opción de salir.
	
	Si opción es 1:
		
		Mirar si existe el fichero.
		
		Calcular nº del último registro grabado.
		
		Abrir fichero para añadir registros
		
		Sacar pantalla de petición de datos y nº del siguiente servicio
		
		Pedir resto de los datos
		
		Pedir conformidad y grabar si está conforme.
		
		Cerrar el fichero y salir al menú
	
	Si opción es 2:
		
		Mirar si existe el fichero.
		
		Calcular nº del último registro grabado.
		
		Abrir fichero para leer 
		
		Sacar pantalla de datos y pedir Nº servicio
		
		Si el Nº servicio está dentro de los límites 
			
			Visualizar el resto de los datos
			
			Pedir datos a modificar
			
			Pedir conformidad y regrabar si está conforme
		
		Si no está dentro de los límites, mensaje de error
		
		Cerrar el fichero y salir al menú
	Si opción es 3:
		
		Mirar si existe el fichero.
		
		Calcular nº del último registro grabado.
		
		Abrir fichero para leer 
		
		Sacar pantalla de datos y pedir Nº Servicio
		
		Si el Nº Servicio está dentro de los límites 
			
			Visualizar el resto de los datos
			
			Pedir continuar 
		
		Si no está dentro de los límites, mensaje de error
		
		Cerrar el fichero y salir al menú
Fin de Hacer mientras

 

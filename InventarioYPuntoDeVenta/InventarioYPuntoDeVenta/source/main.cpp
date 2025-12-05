#include "Prerequisites.h"
#include "Sistema.h"

/**
* @file main.cpp
* @brief Punto de entrada para el sistema de inventario y punto de venta.
* @author Gerardo Herrera
* @date 2025-11-06
* @version 1.0
* @details Este archivo contiene la función principal que inicia el sistema de 
* inventario y punto de venta. Permite al usuario interactuar con el inventario, 
* agregar y eliminar productos, realizar ventas y ver el historial de ventas.
*/

/**
* @brief Función principal del programa.
* @return int Código de salida del programa.
* función principal crea instancias de Inventario, RegistroVentas y AlertaStock,
* y proporciona un menú interactivo para que el usuario gestione el inventario y las ventas.
*
* El programa utiliza las clases Fecha y Venta para manejar las fechas y los registros de ventas.
* El inventario se carga desde un archivo JSON al inicio y se guarda al finalizar.
*/

int main() {
	Sistema sistemaPrincipal;
	sistemaPrincipal.inicializarSistema();
	sistemaPrincipal.menuPrincipal();
	return 0;
}

#include "Prerequisites.h"
#include "Inventario.h"
#include "AlertaStock.h"
#include "RegistroVentas.h"

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
	Inventario inventario; ///< Instancia del inventario
	RegistroVentas registroVentas; ///< Instancia del registro de ventas
	AlertaStock alertaStock; ///< Instancia de la alerta de stock

	inventario.setRegistroVentas(&registroVentas);
	inventario.agregarObservador(&alertaStock);
	inventario.cargarDesdeJSON("../data/Productos.json");
	int g_opcion;///< Opción seleccionada por el usuario
	std::string g_codigo, g_nombre;///< Código y nombre del producto
	int g_cantidad;///< Cantidad del producto
	double g_precio;///< Precio del producto
	auto g_nuevoProducto = std::shared_ptr<Producto>(nullptr);///< Puntero al nuevo producto
	do
	{
		std::cout << "\n========= SISTEMA DE INVENTARIO =========" << std::endl;
		std::cout << "1. Ver inventario" << std::endl;
		std::cout << "2. Agregar producto" << std::endl;
		std::cout << "3. Eliminar producto" << std::endl;
		std::cout << "4. Vender producto" << std::endl;
		std::cout << "5. Ver historial de ventas" << std::endl;
		std::cout << "6. Guardar inventario y salir" << std::endl;
		std::cout << "7. Salir sin guardar" << std::endl;
		std::cout << "Seleccione una opcion: ";
		std::cin >> g_opcion;
		std::cin.ignore();

		switch (g_opcion) {
		case 1:
			/**
			* @brief Opcion 1: Mostrar el inventario de productos.
			* Muestra todos los productos disponibles en el inventario.
			*/
			inventario.mostrarProductos();
			break;
		case 2:
			/**
			* @brief Opcion 2: Agregar un nuevo producto al inventario.
			* Solicita al usuario los datos del producto y lo agrega al inventario.
			*/
			std::cout << "Ingrese codigo del producto: ";
			std::getline(std::cin, g_codigo);
			std::cout << "Ingrese nombre del producto: ";
			std::getline(std::cin, g_nombre);
			std::cout << "Ingrese cantidad del producto: ";
			std::cin >> g_cantidad;
			std::cout << "Ingrese precio del producto: ";
			std::cin >> g_precio;
			std::cin.ignore();
			g_nuevoProducto = std::make_shared<Producto>(g_codigo, g_nombre, g_cantidad, g_precio);
			inventario.agregarProducto(g_nuevoProducto);
			std::cout << "Producto agregado exitosamente." << std::endl;
			break;
		case 3:
			/**
			* @brief Opcion 3: Eliminar un producto del inventario.
			* Solicita al usuario el código del producto y lo elimina del inventario.
			*/
			std::cout << "Ingrese codigo del producto a eliminar: ";
			std::getline(std::cin, g_codigo);
			inventario.eliminarProducto(g_codigo);
			std::cout << "Producto eliminado exitosamente." << std::endl;
			break;
		case 4:
			/**
			* @brief Opcion 4: Vender un producto.
			* Solicita al usuario el código del producto y la cantidad a vender.
			* Automaticamente actualiza el inventario y registra la venta.
			*/
			std::cout << "Ingrese codigo del producto a vender: ";
			std::getline(std::cin, g_codigo);
			std::cout << "Ingrese cantidad a vender: ";
			std::cin >> g_cantidad;
			std::cin.ignore();
			inventario.venderProducto(g_codigo, g_cantidad);
			break;
		case 5:
			/**
			* @brief Opcion 5: Ver historial de ventas.
			* Muestra el historial de ventas realizadas y el monto total vendido.
			*/
			std::cout << "\nHistorial de Ventas:" << std::endl;
			registroVentas.mostrarHistorialVentas();
			std::cout << "Monto total de ventas: $"
				<< registroVentas.mostrarMontoTotalVentas() << std::endl;
			break;
		case 6:
			/**
			* @brief Opcion 6: Guardar inventario y salir.
			* Guarda el inventario actual en un archivo JSON y sale del programa.
			*/
			inventario.guardarEnJSON("../data/Productos.json");
			std::cout << "Inventario guardado. Saliendo..." << std::endl;
			break;
		case 7:
			/**
			* @brief Opcion 7: Salir sin guardar.
			* Sale del programa sin guardar los cambios en el inventario.
			*/
			std::cout << "Saliendo sin guardar..." << std::endl;
			break;
		default:
			break;
		}
	} while (g_opcion != 7 && g_opcion != 6);
	return 0;
}

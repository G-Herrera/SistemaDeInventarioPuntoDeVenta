#include "Prerequisites.h"
#include "Inventario.h"
#include "AlertaStock.h"
#include "RegistroVentas.h"

int main() {
	Inventario inventario;
	RegistroVentas registroVentas;
	AlertaStock alertaStock;

	inventario.setRegistroVentas(&registroVentas);
	inventario.agregarObservador(&alertaStock);
	inventario.cargarDesdeJSON("../data/Productos.json");
	int opcion;
	std::string codigo, nombre;
	int cantidad;
	double precio;
	auto nuevoProducto = std::shared_ptr<Producto>(nullptr);
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
		std::cin >> opcion;
		std::cin.ignore();

		switch (opcion) {
		case 1:
			inventario.mostrarProductos();
			break;
		case 2:
			std::cout << "Ingrese codigo del producto: ";
			std::getline(std::cin, codigo);
			std::cout << "Ingrese nombre del producto: ";
			std::getline(std::cin, nombre);
			std::cout << "Ingrese cantidad del producto: ";
			std::cin >> cantidad;
			std::cout << "Ingrese precio del producto: ";
			std::cin >> precio;
			std::cin.ignore();
			nuevoProducto = std::make_shared<Producto>(codigo, nombre, cantidad, precio);
			inventario.agregarProducto(nuevoProducto);
			std::cout << "Producto agregado exitosamente." << std::endl;
			break;
		case 3:
			std::cout << "Ingrese codigo del producto a eliminar: ";
			std::getline(std::cin, codigo);
			inventario.eliminarProducto(codigo);
			std::cout << "Producto eliminado exitosamente." << std::endl;
			break;
		case 4:
			std::cout << "Ingrese codigo del producto a vender: ";
			std::getline(std::cin, codigo);
			std::cout << "Ingrese cantidad a vender: ";
			std::cin >> cantidad;
			std::cin.ignore();
			inventario.venderProducto(codigo, cantidad);
			break;
		case 5:
			std::cout << "\nHistorial de Ventas:" << std::endl;
			registroVentas.mostrarHistorialVentas();
			std::cout << "Monto total de ventas: $"
				<< registroVentas.mostrarMontoTotalVentas() << std::endl;
			break;
		case 6:
			inventario.guardarEnJSON("../data/Productos.json");
			std::cout << "Inventario guardado. Saliendo..." << std::endl;
			break;
		case 7:
			std::cout << "Saliendo sin guardar..." << std::endl;
			break;
		default:
			break;
		}
	} while (opcion!=7 && opcion!=6);
	return 0;
}

#include "RegistroVentas.h"

/**
 * @brief Registra una venta en el historial.
 * @param venta Objeto Venta a registrar.
 */
void 
RegistroVentas::registrarVenta(const Venta& venta) {
		m_ventas.push_back(venta);
		m_totalVentas += venta.total;
}

/**
 * @brief Registra una venta en el historial.
 * @param productoCodigo Código del producto vendido.
 * @param productoNombre Nombre del producto vendido.
 * @param cantidad Cantidad vendida.
 * @param total Total de la venta.
 */ 
void 
RegistroVentas::registrarVenta(const std::string& productoCodigo, const std::string& productoNombre, int cantidad, double total) {
		Fecha fecha;
		fecha.getFechaActual();
		double ventaTotal = cantidad * total;
		Venta venta{ fecha, productoCodigo, productoNombre, cantidad, ventaTotal };
		registrarVenta(venta);
}

/**
 * @brief Muestra el historial de ventas.
 * @details Esta función recorre el vector de ventas registradas
 * y muestra la información de cada venta en la consola.
 */
void 
RegistroVentas::mostrarHistorialVentas() const {
		for (const auto& venta : m_ventas) {
			std::cout << "Fecha: " << venta.fecha.toString()
						<< ", Producto: " << venta.productoNombre
						<< " (Codigo: " << venta.productoCodigo << ")"
						<< ", Cantidad: " << venta.cantidad
						<< ", Total: " << venta.total << std::endl;
		}
}

/**
 * @brief Muestra el monto total de ventas.
 * @return Monto total de ventas.
 */
double 
RegistroVentas::mostrarMontoTotalVentas() const {
		return m_totalVentas;
}

/**
 * @brief Obtiene la cantidad total de ventas registradas.
 * @return Cantidad total de ventas.
 */
int 
RegistroVentas::getCantidadVentas() const {
		return static_cast<int>(m_ventas.size());
}





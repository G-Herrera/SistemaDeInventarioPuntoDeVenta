#include "RegistroVentas.h"

void RegistroVentas::registrarVenta(const Venta& venta) {
		m_ventas.push_back(venta);
		m_totalVentas += venta.total;
}

void RegistroVentas::registrarVenta(const std::string& productoCodigo, const std::string& productoNombre, int cantidad, double total) {
		Fecha fecha;
		fecha.getFechaActual();
		double ventaTotal = cantidad * total;
		Venta venta{ fecha, productoCodigo, productoNombre, cantidad, ventaTotal };
		registrarVenta(venta);
}

void RegistroVentas::mostrarHistorialVentas() const {
		for (const auto& venta : m_ventas) {
			std::cout << "Fecha: " << venta.fecha.toString()
						<< ", Producto: " << venta.productoNombre
						<< " (Codigo: " << venta.productoCodigo << ")"
						<< ", Cantidad: " << venta.cantidad
						<< ", Total: " << venta.total << std::endl;
		}
}

double RegistroVentas::mostrarMontoTotalVentas() const {
		return m_totalVentas;
}
int RegistroVentas::getCantidadVentas() const {
		return static_cast<int>(m_ventas.size());
}





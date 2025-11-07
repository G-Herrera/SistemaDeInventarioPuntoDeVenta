#pragma once
#include "Prerequisites.h"

/*
* @class Venta
* @brief Representa una venta realizada.
* @details Esta estructura contiene la información de una venta,
* incluyendo la fecha de la venta, el código y nombre del producto,
* la cantidad vendida y el total de la venta.
*/

class 
RegistroVentas {
public:
	/**
	 * @brief Constructor y destructor por defecto de la clase RegistroVentas.
	 */
	RegistroVentas()  = default;
	~RegistroVentas() = default;

	/**
	 * @brief Registra una venta en el historial.
	 * @param venta Objeto Venta a registrar.
	 */
	void 
	registrarVenta(const Venta& venta);
	/**
	 * @brief Registra una venta en el historial.
	 * @param productoCodigo Código del producto vendido.
	 * @param productoNombre Nombre del producto vendido.
	 * @param cantidad Cantidad vendida.
	 * @param total Total de la venta.
	 */
	void 
	registrarVenta(const std::string& productoCodigo, const std::string& productoNombre,
	int cantidad, double total);
	/**
	 * @brief Muestra el monto total de ventas.
	 * @return Monto total de ventas.
	 */
	double 
	mostrarMontoTotalVentas() const;
	/**
	 * @brief Obtiene la cantidad total de ventas registradas.
	 * @return Cantidad total de ventas.
	 */
	int 
	getCantidadVentas() const;
	/**
	 * @brief Muestra el historial de ventas registradas.
	 */
	void 
	mostrarHistorialVentas() const;

private:
	std::vector<Venta> m_ventas;///< Vector de ventas registradas
	double m_totalVentas = 0.0;///< Monto total de ventas
};

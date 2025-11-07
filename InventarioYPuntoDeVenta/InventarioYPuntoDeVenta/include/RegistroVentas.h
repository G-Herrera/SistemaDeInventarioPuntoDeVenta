#pragma once
#include "Prerequisites.h"

class 
RegistroVentas {
public:
	RegistroVentas()  = default;
	~RegistroVentas() = default;

	void registrarVenta(const Venta& venta);
	void 
	registrarVenta(const std::string& productoCodigo, const std::string& productoNombre,
	int cantidad, double total);
	double mostrarMontoTotalVentas() const;
	int getCantidadVentas() const;
	void mostrarHistorialVentas() const;

private:
	std::vector<Venta> m_ventas;
	double m_totalVentas = 0.0;
};

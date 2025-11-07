#pragma once
#include "Prerequisites.h"

class Producto {
public:
	Producto(std::string codigo, std::string nombre, int cantidad, double precio) :
	m_codigo(codigo), m_nombre(nombre), m_cantidad(cantidad), m_precio(precio) {}
	virtual ~Producto() = default;

	std::string getCodigo() const;
	std::string getNombre() const;
	int getCantidad() const;
	double getPrecio() const;

	void setCantidad(int nuevaCantidad);

	virtual void mostrarInfo() const;

private:
	std::string m_codigo;
	std::string m_nombre;
	int m_cantidad;
	double m_precio;
};

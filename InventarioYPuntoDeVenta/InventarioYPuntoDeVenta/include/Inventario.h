#pragma once
#include "Prerequisites.h"
#include "Producto.h"
#include "FactoryProducto.h"
#include "Observador.h"

class RegistroVentas;

class 
Inventario {
public:
	Inventario() = default;
	~Inventario()= default;

	void cargarDesdeJSON(const std::string& ruta);
	void guardarEnJSON(const std::string& ruta) const;
	void agregarProducto(const std::shared_ptr<Producto>& producto);
	void eliminarProducto(const std::string& codigo);
	void venderProducto(const std::string& codigo, int cantidad);
	void comprarProducto(const std::string& codigo, int cantidad);
	void setRegistroVentas(RegistroVentas* registro);

	void mostrarProductos() const;

	// Observador methods
	void agregarObservador(Observador* observador);
	void 
	notificarStockBajo(const std::string& productoCodigo, 
	const std::string& nombre, int cantidad);
 
private:
	std::vector<std::shared_ptr<Producto>> m_productos;
	std::vector<Observador*> m_observadores;
	RegistroVentas* m_registroVentas = nullptr;
};

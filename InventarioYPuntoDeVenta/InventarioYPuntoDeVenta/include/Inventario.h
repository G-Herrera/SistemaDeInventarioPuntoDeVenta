#pragma once
#include "Prerequisites.h"
#include "Producto.h"
#include "FactoryProducto.h"
#include "Observador.h"

/**
 * @class Inventario
 * @brief Gestiona el inventario de productos.
 * @details Esta clase permite cargar y guardar productos desde/hacia un archivo JSON,
 * agregar, eliminar, vender y comprar productos, y notificar a los observadores
 * cuando un producto tiene stock bajo.
 */
class RegistroVentas;///< Declaración adelantada

class 
Inventario {
public:
	/**
	 * @brief Constructor y destructor de la clase Inventario por defecto.
	 */
	Inventario() = default;
	~Inventario()= default;
	/**
	 * @brief Carga el inventario desde un archivo JSON.
	 * @param ruta Ruta del archivo JSON.
	 */
	void 
	cargarDesdeJSON(const std::string& ruta);
	/**
	 * @brief Guarda el inventario en un archivo JSON.
	 * @param ruta Ruta del archivo JSON.
	 */
	void 
	guardarEnJSON(const std::string& ruta) const;
	/**
	 * @brief Agrega un producto al inventario.
	 * @param producto Puntero compartido al producto a agregar.
	 */
	void 
	agregarProducto(const std::shared_ptr<Producto>& producto);
	/**
	 * @brief Elimina un producto del inventario por su código.
	 * @param codigo Código del producto a eliminar.
	 */
	void 
	eliminarProducto(const std::string& codigo);
	/**
	 * @brief Vende un producto del inventario.
	 * @param codigo Código del producto a vender.
	 * @param cantidad Cantidad del producto a vender.
	 */
	void 
	venderProducto(const std::string& codigo, int cantidad);
	/**
	 * @brief Compra un producto del inventario.
	 * @param codigo Código del producto a comprar.
	 * @param cantidad Cantidad del producto a comprar.
	 */
	void 
	comprarProducto(const std::string& codigo, int cantidad);
	/**
	 * @brief Establece el registro de ventas.
	 * @param registro Puntero al objeto RegistroVentas.
	 */
	void 
	setRegistroVentas(RegistroVentas* registro);
	/**
	 * @brief Muestra los productos en el inventario.
	 */
	void 
	mostrarProductos() const;

	// Observador methods
	/**
	 * @brief Agrega un observador al inventario.
	 * @param observador Puntero al objeto Observador.
	 */
	void 
	agregarObservador(Observador* observador);
	/**
	 * @brief Notifica a los observadores cuando un producto tiene stock bajo.
	 * @param productoCodigo Código del producto.
	 * @param nombre Nombre del producto.
	 * @param cantidad Cantidad disponible.
	 */
	void 
	notificarStockBajo(const std::string& productoCodigo, 
	const std::string& nombre, int cantidad);
 
private:
	std::vector<std::shared_ptr<Producto>> m_productos;///< Vector de productos en el inventario
	std::vector<Observador*> m_observadores;///< Vector de observadores del inventario
	RegistroVentas* m_registroVentas = nullptr;///< Puntero al registro de ventas
};

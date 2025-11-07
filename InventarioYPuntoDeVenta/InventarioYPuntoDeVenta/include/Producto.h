#pragma once
#include "Prerequisites.h"

/**
 * @class Producto
 * @brief Representa un producto en el inventario.
 * @details Esta clase contiene la información básica de un producto, incluyendo su código,
 * nombre, cantidad en stock y precio. Proporciona métodos para acceder y modificar estos
 * atributos, así como para mostrar la información del producto.
 */ 

class 
Producto {
public:
	/**
	 *@brief Constructor de la clase Producto.
	 * @param codigo Código único del producto.
	 * @param nombre Nombre del producto.
	 * @param cantidad Cantidad disponible en stock.
	 * @param precio Precio unitario del producto.
	 */
	Producto(std::string codigo, std::string nombre, int cantidad, double precio) :
	m_codigo(codigo), m_nombre(nombre), m_cantidad(cantidad), m_precio(precio) {}
	virtual ~Producto() = default;

	/**
	 * @brief Obtiene el código del producto.
	 * @return Código del producto.
	 */
	std::string 
	getCodigo() const;
	/**
	 * @brief Obtiene el nombre del producto.
	 * @return Nombre del producto.
	 */
	std::string 
	getNombre() const;
	/**
	 * @brief Obtiene la cantidad disponible del producto.
	 * @return Cantidad disponible en stock.
	 */
	int 
	getCantidad() const;
	/**
	 * @brief Obtiene el precio del producto.
	 * @return Precio del producto.
	 */
	double 
	getPrecio() const;
	/**
	 * @brief Establece una nueva cantidad para el producto.
	 * @param nuevaCantidad Nueva cantidad a establecer.
	 */
	void 
	setCantidad(int nuevaCantidad);
	/*
	* @brief Muestra la información del producto.
	* Esta función muestra todos los detalles del producto, incluyendo su código,
	* nombre, cantidad y precio.
	*/
	virtual void 
	mostrarInfo() const;

private:
	std::string m_codigo;///< Código único del producto
	std::string m_nombre;///< Nombre del producto
	int m_cantidad;///< Cantidad disponible en stock
	double m_precio;///< Precio unitario del producto
};

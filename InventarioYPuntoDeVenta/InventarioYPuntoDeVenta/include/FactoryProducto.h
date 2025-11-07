#pragma once
#include "Prerequisites.h"
#include "Producto.h"

/**
 * @class FactoryProducto
 * @brief Clase para crear objetos Producto.
 */
class 
FactoryProducto {
public:
	/**
	 * @brief Crea un objeto Producto desde un JSON.
	 * @param j Objeto JSON con los datos del producto.
	 * @return Puntero compartido al objeto Producto creado.
	 */
	static std::shared_ptr<Producto> crearDesdeJson(const json& j);

};

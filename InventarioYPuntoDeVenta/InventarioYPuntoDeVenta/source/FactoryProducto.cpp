#include "FactoryProducto.h"

/**
 * @brief Crea un objeto Producto a partir de un objeto JSON.
 * @param j Objeto JSON con la información del producto.
 * @return Puntero compartido al objeto Producto creado.
 */
std::shared_ptr<Producto> 
FactoryProducto::crearDesdeJson(const json& j) {
	return std::make_shared<Producto>(
		j["codigo"].get<std::string>(),
		j["nombre"].get<std::string>(),
		j["precio"].get<double>(),
		j["cantidad"].get<int>()
		);
}
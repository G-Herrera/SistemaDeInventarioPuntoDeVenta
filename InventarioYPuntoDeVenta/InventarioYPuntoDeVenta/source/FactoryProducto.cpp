#include "FactoryProducto.h"

std::shared_ptr<Producto> FactoryProducto::crearDesdeJson(const json& j) {
	return std::make_shared<Producto>(
		j["codigo"].get<std::string>(),
		j["nombre"].get<std::string>(),
		j["precio"].get<double>(),
		j["cantidad"].get<int>()
		);
}
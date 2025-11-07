#pragma once
#include "Prerequisites.h"
#include "Producto.h"

class 
FactoryProducto {
public:
	static std::shared_ptr<Producto> crearDesdeJson(const json& j);

};

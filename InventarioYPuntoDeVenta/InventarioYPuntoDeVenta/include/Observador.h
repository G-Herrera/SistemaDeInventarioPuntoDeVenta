#pragma once
#include "Prerequisites.h"

class Observador {
public:
	virtual ~Observador() = default;
	virtual void 
	onStockBajo(const std::string& productoCodigo, const std::string nombre, int cantidad) = 0;
};
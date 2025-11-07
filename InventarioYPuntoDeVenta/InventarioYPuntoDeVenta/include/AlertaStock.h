#pragma once
#include "Prerequisites.h"
#include "Observador.h"

class 
AlertaStock : public Observador {
public:
	AlertaStock()  = default;
	~AlertaStock() = default;

	void 
	onStockBajo(const std::string& productoCodigo,	
	const std::string nombre, int cantidad) override {
		std::cout << "ALERTA: Stock bajo para el producto " << nombre 
					<< " (Codigo: " << productoCodigo 
					<< "). Cantidad actual: " << cantidad << std::endl;
	}
};

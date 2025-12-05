#pragma once
#include "Prerequisites.h"

class 
TiposDePago {
public:
	virtual ~TiposDePago() = default;

	virtual bool 
	pagar(double monto, double& cambio, const json& detallesPago) = 0;
	
	virtual 
	std::string informacionPago() const = 0;
};

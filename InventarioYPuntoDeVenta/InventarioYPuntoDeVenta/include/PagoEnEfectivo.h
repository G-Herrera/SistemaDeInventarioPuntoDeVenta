#pragma once
#include "TiposDePago.h"

class PagoEnEfectivo : public TiposDePago
{
public:
	PagoEnEfectivo()  = default;
	~PagoEnEfectivo() = default;
	
	bool pagar(double monto, double& cambio, const json& detallesPago) override;
	std::string informacionPago() const override;
};

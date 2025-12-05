#pragma once
#include "TiposDePago.h"

class 
PagoTDC : public TiposDePago {
public:
		PagoTDC()  = default;
		~PagoTDC() = default;

		bool 
		pagar(double monto, double& cambio, const json& detallesPago) override;

		std::string 
		informacionPago() const override;
};
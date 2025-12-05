#pragma once
#include "TiposDePago.h"

class PagoTDB : public TiposDePago {
public:
		PagoTDB()  = default;
		~PagoTDB() = default;
		bool pagar(double monto, double& cambio, const json& detallesPago) override;
		std::string informacionPago() const override;
};
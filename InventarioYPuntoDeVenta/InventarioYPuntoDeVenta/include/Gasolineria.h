#pragma once
#include "Prerequisites.h"
#include "Gasolina.h"

class 
Gasolineria {
public:
	Gasolineria();
	~Gasolineria()= default;

	void 
	mostrarTiposGasolina() const;

	bool 
	registrarCarga(
								 const std::string& tipoGasolina, 
								 double litrosRequeridos, 
								 double montoPagado, 
								 double& litrosCargados, 
							   double& calculoTotal
								);

	bool 
	existeTipo(const std::string& tipo) const;
	
	double 
	getPrecio(const std::string& tipo) const;

private:
	std::vector<Gasolina> m_tiposGasolina;
	const Gasolina* buscarTipoGasolina(const std::string& tipoGasolina) const;
};

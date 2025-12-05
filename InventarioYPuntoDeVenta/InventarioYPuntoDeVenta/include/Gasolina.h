#pragma once
#include "Prerequisites.h"

class Gasolina
{
public:
	Gasolina()=default;
	Gasolina(const std::string& tipoGasolina, double precioL) 
					: m_tipoGasolina(tipoGasolina), m_precioL(precioL) {}
	~Gasolina() = default;
	
	void 
	setTipoGasolina(const std::string tipoGasolina);

	std::string 
	getTipoGasolina() const;
	
	void 
	setPrecioL(double precioL);
	
	double 
	getPrecioL() const;

private:

	std::string m_tipoGasolina;
	double m_precioL=0.0;
};

#include "Gasolina.h"

/**
 * @brief Establece el tipo de gasolina.
 * @param tipoGasolina Tipo de gasolina a establecer.
 */
void
Gasolina::setTipoGasolina(const std::string tipoGasolina) {
		m_tipoGasolina = tipoGasolina;
}

/**
 * @brief Obtiene el tipo de gasolina.
 * @return Tipo de gasolina.
 */
std::string 
Gasolina::getTipoGasolina() const {
		return m_tipoGasolina;
}

/**
 * @brief Establece el precio por litro de la gasolina.
 * @param precioL Precio por litro a establecer.
 */
void
Gasolina::setPrecioL(double precioL) {
		m_precioL = precioL;
}

/**
 * @brief Obtiene el precio por litro de la gasolina.
 * @return Precio por litro.
 */
double
Gasolina::getPrecioL() const {
		return m_precioL;
}
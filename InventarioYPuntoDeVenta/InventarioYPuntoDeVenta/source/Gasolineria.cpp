#include "Gasolineria.h"

Gasolineria::Gasolineria() {
		// Inicializar los tipos de gasolina disponibles
		m_tiposGasolina.emplace_back("Regular", 23.79);
		m_tiposGasolina.emplace_back("Premium", 25.40);
		m_tiposGasolina.emplace_back("Diesel", 26.10);
}

/**
 * @brief Muestra los tipos de gasolina disponibles.
 * @details Esta función recorre el vector de tipos de gasolina
 * y muestra el tipo y precio por litro de cada uno en la consola.
 */
void Gasolineria::mostrarTiposGasolina() const {
		std::cout << "Tipos de Gasolina Disponibles:" << std::endl;
		for (const auto& gasolina : m_tiposGasolina) {
				std::cout << "- " << gasolina.getTipoGasolina()
					<< ": $" << gasolina.getPrecioL() << " por litro" << std::endl;
		}
}

/**
 * @brief Registra una carga de gasolina.
 * @param tipoGasolina Tipo de gasolina a cargar.
 * @param litrosRequeridos Cantidad de litros requeridos.
 * @param montoPagado Monto pagado por el cliente.
 * @param litrosCargados Referencia para almacenar la cantidad de litros cargados.
 * @param calculoTotal Referencia para almacenar el cálculo total del pago.
 * @return true si la carga es exitosa, false en caso contrario.
 */
bool 
Gasolineria::registrarCarga(
	const std::string& tipoGasolina,
	double litrosRequeridos,
	double montoPagado,
	double& litrosCargados,
	double& calculoTotal
) {
		const Gasolina* gasolina = buscarTipoGasolina(tipoGasolina);
		if (gasolina == nullptr) {
				std::cerr << "Tipo de gasolina no encontrado." << std::endl;
				return false;
		}
		calculoTotal = litrosRequeridos * gasolina->getPrecioL();
		if (montoPagado >= calculoTotal) {
				litrosCargados = litrosRequeridos;
				std::cout << "Carga de " << litrosCargados << " litros de "
					<< tipoGasolina << " exitosa." << std::endl;
				return true;
		} else {
				litrosCargados = 0.0;
				std::cerr << "Monto pagado insuficiente." << std::endl;
				return false;
		}
}

/**
 * @brief Busca un tipo de gasolina por su nombre.
 * @param tipoGasolina Tipo de gasolina a buscar.
 * @return Puntero al objeto Gasolina si se encuentra, nullptr en caso contrario.
 */
const Gasolina* 
Gasolineria::buscarTipoGasolina(const std::string& tipoGasolina) const {
		for (const auto& gasolina : m_tiposGasolina) {
				if (gasolina.getTipoGasolina() == tipoGasolina) {
						return &gasolina;
				}
		}
		return nullptr;
}

bool Gasolineria::existeTipo(const std::string& tipo) const {
	return buscarTipoGasolina(tipo) != nullptr;
}

double Gasolineria::getPrecio(const std::string& tipo) const {
	const Gasolina* g = buscarTipoGasolina(tipo);
	if (!g) return -1.0;
	return g->getPrecioL();
}
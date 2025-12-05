#include "PagoEnEfectivo.h"

/**
 * @brief Procesa un pago en efectivo.
 * @param monto Monto total a pagar.
 * @param cambio Referencia para almacenar el cambio a devolver.
 * @param detallesPago Objeto JSON con detalles adicionales del pago (no utilizado en este método).
 * @return true si el pago es exitoso, false en caso contrario.
 */
bool 
PagoEnEfectivo::pagar(double monto, double& cambio, const json& detallesPago) {
		double efectivoRecibido = detallesPago.value("recibido", 0.0);
		if (efectivoRecibido >= monto) {
				cambio = efectivoRecibido - monto;
				std::cout << "Pago en efectivo exitoso. Cambio a devolver: $" 
					<< cambio << std::endl;
				return true;
		} else {
				cambio = 0.0;
				return false;
		}
}

/**
 * @brief Proporciona información sobre el método de pago en efectivo.
 * @return Cadena de texto con la información del pago en efectivo.
 */
std::string 
PagoEnEfectivo::informacionPago() const {
		return "EFECTIVO";
}
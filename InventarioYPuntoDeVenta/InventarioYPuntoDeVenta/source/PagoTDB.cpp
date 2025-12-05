#include "PagoTDB.h"

/**
 * @brief Procesa un pago con tarjeta de débito.
 * @param monto Monto total a pagar.
 * @param cambio Referencia para almacenar el cambio a devolver (si aplica).
 * @param detallesPago Objeto JSON con detalles adicionales del pago (no utilizado en este método).
 * @return true si el pago es exitoso, false en caso contrario.
 */
bool 
PagoTDB::pagar(double monto, double& cambio, const json& detallesPago) {
  cambio = 0;
  return true; // simular éxito
}

/**
 * @brief Proporciona información sobre el método de pago con tarjeta de débito.
 * @return Cadena de texto con la información del pago con tarjeta de débito.
 */
std::string 
PagoTDB::informacionPago() const {
		return "Pago con Tarjeta de Debito";
}
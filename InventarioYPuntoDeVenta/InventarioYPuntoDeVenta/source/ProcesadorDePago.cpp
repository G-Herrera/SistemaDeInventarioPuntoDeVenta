#include "ProcesadorDePago.h"
#include "PagoEnEfectivo.h"
#include "PagoTDB.h"
#include "PagoTDC.h"

/**
 * @brief Establece el método de pago a utilizar.
 * @param metodoPago Puntero al objeto del método de pago.
 */
void 
ProcesadorDePago::setMetodoPago(TiposDePago* metodoPago) {
  if (metodoPago == nullptr) {
    std::cerr << "Error: El metodo de pago no puede ser nulo." << std::endl;
    return;
  }
  // unique_ptr toma la propiedad; si ya existía uno, se libera automáticamente
  m_metodoPago.reset(metodoPago);
}

/**
 * @brief Procesa el pago utilizando el método de pago establecido.
 * @param monto Monto total a pagar.
 * @param cambio Referencia para almacenar el cambio a devolver.
 * @param detallesPago Objeto JSON con detalles adicionales del pago.
 * @return true si el pago es exitoso, false en caso contrario.
 */
bool 
ProcesadorDePago::procesarPago(double monto, double& cambio, const json& detallesPago) const {
  if (m_metodoPago == nullptr) {
    std::cerr << "Error: No se ha establecido un metodo de pago." << std::endl;
    return false;
  }
  return m_metodoPago->pagar(monto, cambio, detallesPago);
}

/**
 * @brief Obtiene información sobre el método de pago utilizado.
 * @return Cadena de texto con la información del método de pago.
 */
std::string 
ProcesadorDePago::informacionMetodoPago() const {
  if (m_metodoPago == nullptr) {
    return "Metodo de pago no establecido.";
  }
  return m_metodoPago->informacionPago();
}

/**
 * @brief Permite al usuario seleccionar un método de pago.
 * @return Puntero al objeto del método de pago seleccionado.
 */
TiposDePago* 
ProcesadorDePago::seleccionarMetodoPago() {
  int opcion = 0;
  std::cout << "\nSeleccione metodo de pago:\n";
  std::cout << "1) Efectivo\n";
  std::cout << "2) Tarjeta Debito\n";
  std::cout << "3) Tarjeta Credito\n";
  std::cout << "0) Cancelar\n";
  std::cout << "Opción: ";
  std::cin >> opcion;
  std::cin.ignore();

  TiposDePago* creado = nullptr;

  switch (opcion) {
  case 1:
    creado = new PagoEnEfectivo();
    break;
  case 2:
    creado = new PagoTDB();
    break;
  case 3:
    creado = new PagoTDC();
    break;
  case 0:
  default:
    std::cout << "Selección cancelada o inválida.\n";
    return nullptr;
  }

  // guardamos la instancia en el procesador (toma la propiedad)
  setMetodoPago(creado);

  // devolvemos puntero crudo sólo para uso inmediato (propiedad ya es del procesador)
  return m_metodoPago.get();
}

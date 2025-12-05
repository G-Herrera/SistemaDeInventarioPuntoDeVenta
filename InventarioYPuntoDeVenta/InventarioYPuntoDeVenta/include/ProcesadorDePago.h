#pragma once
#include "TiposDePago.h"


class ProcesadorDePago
{
public:
public:
  ProcesadorDePago() = default;
  ~ProcesadorDePago() = default;

  // Fija el método (posee el método, se queda con la propiedad)
  void setMetodoPago(TiposDePago* metodoPago);

  // Selecciona método interactivo (devuelve puntero sin transferir propiedad,
  // la propiedad queda en el Procesador)
  TiposDePago* seleccionarMetodoPago();

  // Procesa el pago usando el metodo actualmente seteado
  bool procesarPago(double monto, double& cambio, const json& detallesPago) const;

  std::string informacionMetodoPago() const;

private:
  // Usamos unique_ptr para manejar la vida del objeto
  std::unique_ptr<TiposDePago> m_metodoPago;
};

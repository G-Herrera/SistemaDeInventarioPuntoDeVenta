#pragma once
#include "Prerequisites.h"
#include "TiposDePago.h"
#include "ProcesadorDePago.h"

class 
GeneradorDeTickets {
public:
	GeneradorDeTickets() = default;
	GeneradorDeTickets(ProcesadorDePago* procesadorPago) : m_procesadorPago(procesadorPago) {}
	~GeneradorDeTickets() = default;
	
	bool 
	crearTicket(
							const std::string& ruta, 
							const std::vector<std::string>& listaProductos, 
							double total, 
							double cambio, 
							const TiposDePago* metodoPago, 
							const json& detallesPago
						 );

	bool 
	crearTicketGasolina(
											const std::string& ruta,
											const std::string& tipoGasolina,
											double litrosCargados,
											double precioPorLitro,
											double total,
											double cambio,
											const TiposDePago* metodoPago,
											const json& detallesPago
										 );

	void 
	enviarTicketPorCorreo(const std::string& correoDestino, const std::string& rutaTicket);

private:
	ProcesadorDePago* m_procesadorPago;
};

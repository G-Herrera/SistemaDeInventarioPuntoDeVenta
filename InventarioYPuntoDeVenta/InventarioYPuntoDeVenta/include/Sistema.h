#pragma once
#include "Inventario.h"
#include "RegistroVentas.h"
#include "AlertaStock.h"
#include "Gasolineria.h"
#include "ProcesadorDePago.h"
#include "GeneradorDeTickets.h"

class Sistema
{
public:
	Sistema() = default;
	Sistema(ProcesadorDePago& procesadorPago) :m_generadorTickets(&procesadorPago) {}
	~Sistema() = default;

	void inicializarSistema();
	void menuPrincipal();
	void menuInventario();
	void menuGasolinera();

private:
	Inventario m_inventario;
	RegistroVentas m_registroVentas;
	AlertaStock m_alertaStock;
	Gasolineria m_gasolineria;
	ProcesadorDePago m_procesadorPago;
	GeneradorDeTickets m_generadorTickets;
};


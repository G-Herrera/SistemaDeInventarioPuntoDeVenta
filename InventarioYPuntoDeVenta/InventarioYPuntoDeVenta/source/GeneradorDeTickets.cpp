#include "GeneradorDeTickets.h"

/**
 * @brief Crea un ticket de venta y lo guarda en un archivo.
 * @param ruta Ruta del archivo donde se guardará el ticket.
 * @param listaProductos Lista de productos vendidos.
 * @param total Monto total de la venta.
 * @param cambio Cambio devuelto al cliente.
 * @param metodoPago Método de pago utilizado.
 * @param detallesPago Detalles adicionales del pago en formato JSON.
 * @return true si el ticket se creó exitosamente, false en caso contrario.
 */
bool 
GeneradorDeTickets::crearTicket(const std::string& ruta,
	const std::vector<std::string>& listaProductos,
	double total,
	double cambio,
	const TiposDePago* metodoPago,
	const json& detallesPago) {
		std::ofstream archivo(ruta);
		if (!archivo.is_open()) {
				std::cerr << "Error al abrir el archivo para el ticket." << std::endl;
				return false;
		}
		Fecha fecha;
		fecha.getFechaActual();
		archivo << "********** TICKET DE VENTA **********" << std::endl;
		archivo << "Fecha: " << fecha.toString() << std::endl;
		archivo << "-------------------------------------" << std::endl;
		archivo << "Productos Vendidos:" << std::endl;
		for (const auto& producto : listaProductos) {
				archivo << "- " << producto << std::endl;
		}
		archivo << "-------------------------------------" << std::endl;
		archivo << "Total: $" << total << std::endl;
		archivo << "Cambio: $" << cambio << std::endl;
		archivo << "Metodo de Pago: " << metodoPago->informacionPago() << std::endl;
		archivo << "Detalles del Pago: " << detallesPago.dump() << std::endl;
		archivo << "*************************************" << std::endl;
		archivo.close();
		std::cout << "Ticket creado exitosamente en: " << ruta << std::endl;
		return true;
}

/**
 * @brief Envía el ticket por correo electrónico.
 * @param correoDestino Dirección de correo electrónico del destinatario.
 * @param rutaTicket Ruta del archivo del ticket a enviar.
 */
void 
GeneradorDeTickets::enviarTicketPorCorreo(const std::string& correoDestino, 
																				  const std::string& rutaTicket) {
	// Validación simple del correo
	if (correoDestino.find('@') == std::string::npos ||
		correoDestino.find('.') == std::string::npos)
	{
		std::cout << "Error: El correo ingresado no es valido.\n";
		return;
	}

	std::cout << "\nSimulando envio de ticket por correo...\n";
	std::cout << "Conectando al servidor SMTP...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(700));

	std::cout << "Autenticando...\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	std::cout << "Adjuntando archivo: " << rutaTicket << "\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(600));

	std::cout << "Enviando correo a: " << correoDestino << "\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	std::cout << "-------------------------------------------\n";
	std::cout << " Ticket enviado exitosamente a " << correoDestino << "\n";
	std::cout << "-------------------------------------------\n\n";
}

/**
 * @brief Crea un ticket de venta de gasolina y lo guarda en un archivo.
 * @param ruta Ruta del archivo donde se guardará el ticket.
 * @param tipoGasolina Tipo de gasolina vendida.
 * @param litrosCargados Cantidad de litros cargados.
 * @param precioPorLitro Precio por litro de la gasolina.
 * @param total Monto total de la venta.
 * @param cambio Cambio devuelto al cliente.
 * @param metodoPago Método de pago utilizado.
 * @param detallesPago Detalles adicionales del pago en formato JSON.
 * @return true si el ticket se creó exitosamente, false en caso contrario.
 */
bool 
GeneradorDeTickets::crearTicketGasolina(
	const std::string& ruta,
	const std::string& tipoGasolina,
	double litrosCargados,
	double precioPorLitro,
	double total,
	double cambio,
	const TiposDePago* metodoPago,
	const json& detallesPago) {
		std::ofstream archivo(ruta);
		if (!archivo.is_open()) {
				std::cerr << "Error al abrir el archivo para el ticket de gasolina." << std::endl;
				return false;
		}
		Fecha fecha;
		fecha.getFechaActual();
		archivo << "********** TICKET DE GASOLINA **********" << std::endl;
		archivo << "Fecha: " << fecha.toString() << std::endl;
		archivo << "----------------------------------------" << std::endl;
		archivo << "Tipo de Gasolina: " << tipoGasolina << std::endl;
		archivo << "Litros Cargados: " << litrosCargados << " L" << std::endl;
		archivo << "Precio por Litro: $" << precioPorLitro << std::endl;
		archivo << "----------------------------------------" << std::endl;
		archivo << "Total: $" << total << std::endl;
		archivo << "Cambio: $" << cambio << std::endl;
		archivo << "Metodo de Pago: " << metodoPago->informacionPago() << std::endl;
		archivo << "Detalles del Pago: " << detallesPago.dump() << std::endl;
		archivo << "****************************************" << std::endl;
		archivo.close();
		std::cout << "Ticket de gasolina creado exitosamente en: " << ruta << std::endl;
		return true;
}
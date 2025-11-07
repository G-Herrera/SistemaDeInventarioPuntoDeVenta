#pragma once
#include "Prerequisites.h"
#include "Observador.h"

/**
 * @class AlertaStock
 * @brief Clase para manejar alertas de stock bajo.
 * @details Esta clase se encarga de recibir notificaciones sobre
 * cambios en el stock de productos y generar alertas cuando el
 * stock de un producto es bajo.
 */
class 
AlertaStock : public Observador {
public:
	/**
	 * @brief Constructor y destructor por defecto de la clase AlertaStock.
	 */
	AlertaStock()  = default;
	~AlertaStock() = default;

	/**
	 * @brief Maneja la notificación de stock bajo.
	 * @param productoCodigo Código del producto con stock bajo.
	 * @param nombre Nombre del producto con stock bajo.
	 * @param cantidad Cantidad actual del producto con stock bajo.
	 * @details Este método se llama cuando un producto tiene stock bajo
	 * y genera una alerta en la consola.
	 */
	void 
	onStockBajo(const std::string& productoCodigo,	
	const std::string nombre, int cantidad) override {
		std::cout << "ALERTA: Stock bajo para el producto " << nombre 
					<< " (Codigo: " << productoCodigo 
					<< "). Cantidad actual: " << cantidad << std::endl;
	}
};

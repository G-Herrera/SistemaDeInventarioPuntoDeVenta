#pragma once
#include "Prerequisites.h"

/*
* @class Observador
* @brief Interfaz para observar eventos de stock bajo en productos.
* @details Esta clase define una interfaz para los observadores que desean ser notificados
* cuando un producto tiene un stock bajo. Los observadores deben implementar el método
* onStockBajo para manejar la notificación.
*/

class Observador {
public:
	/**
	 * @brief Destructor virtual para la interfaz Observador.
	 */
	virtual ~Observador() = default;
	/**
	 * @brief Notifica al observador que un producto tiene stock bajo.
	 * @param productoCodigo Código del producto con stock bajo.
	 * @param nombre Nombre del producto con stock bajo.
	 * @param cantidad Cantidad actual del producto con stock bajo.
	 * @details Este método debe ser implementado por las clases derivadas para manejar
	 * la notificación de stock bajo.
	 */
	virtual void 
	onStockBajo(const std::string& productoCodigo, const std::string nombre, int cantidad) = 0;
};
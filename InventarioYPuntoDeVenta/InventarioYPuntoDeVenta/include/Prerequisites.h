#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "json.hpp"
#include <ctime>
#include <sstream>
using json = nlohmann::json;

/**
* @struct Fecha
* @brief Representa una fecha y hora.
* @details Esta estructura contiene los campos necesarios para representar una fecha y hora,
* incluyendo día, mes, año, hora, minutos y segundos. Proporciona métodos para obtener la fecha
* actual y para convertir la fecha a una cadena de texto en un formato legible.
*/
struct Fecha {
	int dia;///< Día del mes
	int mes;///< Mes del año
	int anio;///< Año
	int hora;///< Hora
	int mins;///< Minutos
	int segs;///< Segundos

	/**
	 * @brief Obtiene la fecha y hora actual.
	 * @details Esta función utiliza la biblioteca <ctime> para obtener la fecha y hora
	 * actual del sistema y almacena los valores en los campos correspondientes.
	 */
	void
	getFechaActual() {
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);
		dia = now.tm_mday;
		mes = now.tm_mon + 1; // tm_mon is 0-11
		anio = now.tm_year + 1900; // tm_year is years since 1900
		hora = now.tm_hour;
		mins = now.tm_min;
		segs = now.tm_sec;
	}

	/**
	 * @brief Convierte la fecha y hora a una cadena de texto.
	 * @return Cadena de texto en formato "DD/MM/YYYY HH:MM:SS".
	 * @details Esta función utiliza un flujo de salida para formatear la fecha y hora
	 * en el formato especificado.
	 */
	std::string toString() const {
		std::ostringstream oss;
		oss << std::setfill('0')
			<< std::setw(2) << dia << "/"
			<< std::setw(2) << mes << "/"
			<< anio << " "
			<< std::setw(2) << hora << ":"
			<< std::setw(2) << mins << ":"
			<< std::setw(2) << segs;
		return oss.str();
	}
};

/**
 * @struct Venta
 * @brief Representa una venta de un producto.
 * @details Esta estructura contiene la información relevante de una venta, incluyendo la fecha,
 * el código y nombre del producto, la cantidad vendida y el total de la venta.
 */
struct Venta {
	Fecha fecha;///< Fecha de la venta
	std::string productoCodigo;///< Código del producto
	std::string productoNombre;///< Nombre del producto
	int cantidad;///< Cantidad vendida
	double total;///< Total de la venta
};
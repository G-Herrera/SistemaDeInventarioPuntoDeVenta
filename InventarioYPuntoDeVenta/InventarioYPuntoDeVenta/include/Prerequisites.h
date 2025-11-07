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

struct Fecha {
	int dia;
	int mes;
	int anio;
	int hora;
	int mins;
	int segs;

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

struct Venta {
	Fecha fecha;
	std::string productoCodigo;
	std::string productoNombre;
	int cantidad;
	double total;
};
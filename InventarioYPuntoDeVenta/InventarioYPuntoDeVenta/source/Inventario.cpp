#include "Inventario.h"
#include "RegistroVentas.h"

void 
Inventario::cargarDesdeJSON(const std::string& ruta) {
		std::ifstream archivo(ruta);
		if (!archivo.is_open()) {
				std::cerr << "No se pudo abrir el archivo: " << ruta << std::endl;
				return;
		}
		json data;
		archivo >> data;
		for (const auto& item : data) {
			auto producto = FactoryProducto::crearDesdeJson(item);
			agregarProducto(producto);
		}
}

void 
Inventario::guardarEnJSON(const std::string& ruta) const {
		json data = json::array();
		for (const auto& producto : m_productos) {
			json item;
			item["codigo"] = producto->getCodigo();
			item["nombre"] = producto->getNombre();
			item["precio"] = producto->getPrecio();
			item["cantidad"] = producto->getCantidad();
			data.push_back(item);
		}
		std::ofstream archivo(ruta);
		if (!archivo.is_open()) {
				std::cerr << "No se pudo abrir el archivo para guardar: " << ruta << std::endl;
				return;
		}
		archivo << data.dump(4);
}

void 
Inventario::agregarProducto(const std::shared_ptr<Producto>& producto) {
		m_productos.push_back(producto);
}

void Inventario::eliminarProducto(const std::string& codigo) {
		m_productos.erase(
			std::remove_if(
				m_productos.begin(), 
				m_productos.end(), 
				[&codigo](const std::shared_ptr<Producto>& p) { return p->getCodigo() == codigo; }
			), 
			m_productos.end()
		);
}

void Inventario::setRegistroVentas(RegistroVentas* registro) {
	m_registroVentas = registro;
}

void Inventario::venderProducto(const std::string& codigo, int cantidad) {
	for (auto& productos : m_productos) {
		if (productos->getCodigo() == codigo) {
			if (productos->getCantidad() < cantidad) {
				std::cout << "Stock insuficiente para realizar la venta." << std::endl;
				return;
			}

			int nuevaCant = productos->getCantidad() - cantidad;
			productos->setCantidad(nuevaCant);

			double total = productos->getPrecio() * cantidad;
			std::cout << "Venta realizada: " << cantidad << " x " << productos->getNombre()
				<< " = $" << total << std::endl;

			if (m_registroVentas)
				m_registroVentas->registrarVenta(productos->getCodigo(), 
				productos->getNombre(), cantidad, productos->getPrecio());

			if (nuevaCant < 5)
				notificarStockBajo(productos->getCodigo(), productos->getNombre(), nuevaCant);

			return;
		}
	}
	std::cout << "Producto no encontrado." << std::	endl;
}

void 
Inventario::comprarProducto(const std::string& codigo, int cantidad) {
		for (const auto& producto : m_productos) {
			if (producto->getCodigo() == codigo) {
				int nuevaCantidad = producto->getCantidad() + cantidad;
				producto->setCantidad(nuevaCantidad);
				return;
			}
		}
}

void 
Inventario::mostrarProductos() const {
		for (const auto& producto : m_productos) {
			producto->mostrarInfo();
		}
}
void 
Inventario::agregarObservador(Observador* observador) {
		m_observadores.push_back(observador);
}

void 
Inventario::notificarStockBajo(const std::string& productoCodigo, 
	const std::string& nombre, int cantidad) {
		for (const auto& observador : m_observadores) {
			observador->onStockBajo(productoCodigo, nombre, cantidad);
		}
}


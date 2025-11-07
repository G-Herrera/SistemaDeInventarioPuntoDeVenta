#include "Inventario.h"
#include "RegistroVentas.h"

/**
 * @brief Carga el inventario desde un archivo JSON.
 * @param ruta Ruta del archivo JSON.
 * @details Esta función abre el archivo JSON especificado, lo lee y carga los datos en el inventario.
 */
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

/**
 * @brief Guarda el inventario en un archivo JSON.
 * @param ruta Ruta del archivo JSON.
 * @details Esta función abre el archivo JSON especificado y guarda los datos del inventario en él.
 */
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

/**
 * @brief Agrega un producto al inventario.
 * @param producto Producto a agregar.
 */
void 
Inventario::agregarProducto(const std::shared_ptr<Producto>& producto) {
		m_productos.push_back(producto);
}

/**
 * @brief Elimina un producto del inventario por su código.
 * @param codigo Código del producto a eliminar.
 */
void 
Inventario::eliminarProducto(const std::string& codigo) {
		m_productos.erase(
			std::remove_if(
				m_productos.begin(), 
				m_productos.end(), 
				[&codigo](const std::shared_ptr<Producto>& p) { return p->getCodigo() == codigo; }
			), 
			m_productos.end()
		);
}

/**
 * @brief Establece el registro de ventas.
 * @param registro Puntero al objeto RegistroVentas.
 */
void 
Inventario::setRegistroVentas(RegistroVentas* registro) {
	m_registroVentas = registro;
}
/**
 * @brief Vende un producto del inventario.
 * @param codigo Código del producto a vender.
 * @param cantidad Cantidad del producto a vender.
 */
void 
Inventario::venderProducto(const std::string& codigo, int cantidad) {
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

/**
 * @brief Compra un producto del inventario.
 * @param codigo Código del producto a comprar.
 * @param cantidad Cantidad del producto a comprar.
 */
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

/**
 * @brief Muestra los productos en el inventario.
 * @details Esta función recorre el vector de productos y muestra la información de cada uno.
 */ 
void 
Inventario::mostrarProductos() const {
		for (const auto& producto : m_productos) {
			producto->mostrarInfo();
		}
}

/**
 * @brief Agrega un observador para notificaciones de stock bajo.
 * @param observador Puntero al observador a agregar.
 */ 
void 
Inventario::agregarObservador(Observador* observador) {
		m_observadores.push_back(observador);
}

/**
 * @brief Notifica a los observadores sobre un producto con stock bajo.
 * @param productoCodigo Código del producto.
 * @param nombre Nombre del producto.
 * @param cantidad Cantidad disponible.
 */ 
void 
Inventario::notificarStockBajo(const std::string& productoCodigo, 
	const std::string& nombre, int cantidad) {
		for (const auto& observador : m_observadores) {
			observador->onStockBajo(productoCodigo, nombre, cantidad);
		}
}


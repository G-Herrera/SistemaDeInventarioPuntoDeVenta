#include "Producto.h"

/**
 * @brief Obtiene el código del producto.
 * @return Código del producto.
 */ 
std::string
Producto::getCodigo() const {
    return m_codigo;
}

/**
 * @brief Obtiene el nombre del producto.
 * @return Nombre del producto.
 */ 
std::string 
Producto::getNombre() const {
    return m_nombre;
}

/**
 * @brief Obtiene la cantidad disponible del producto.
 * @return Cantidad disponible en stock.
 */
int 
Producto::getCantidad() const {
    return m_cantidad;
}

/**
 * @brief Obtiene el precio del producto.
 * @return Precio del producto.
 */
double 
Producto::getPrecio() const {
    return m_precio;
}

/**
 * @brief Establece una nueva cantidad para el producto.
 * @param nuevaCantidad Nueva cantidad a establecer.
 */
void 
Producto::setCantidad(int nuevaCantidad) {
    m_cantidad = nuevaCantidad;
}

/**
 * @brief Muestra la información del producto.
 */
void 
Producto::mostrarInfo() const {
    std::cout << "Codigo: " << m_codigo << ", Nombre: " << m_nombre 
              << ", Cantidad: " << m_cantidad << ", Precio: " << m_precio << std::endl;
}
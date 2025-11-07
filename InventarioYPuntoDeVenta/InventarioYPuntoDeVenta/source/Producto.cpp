#include "Producto.h"

std::string
Producto::getCodigo() const {
    return m_codigo;
}

std::string 
Producto::getNombre() const {
    return m_nombre;
}

int 
Producto::getCantidad() const {
    return m_cantidad;
}

double 
Producto::getPrecio() const {
    return m_precio;
}

void 
Producto::setCantidad(int nuevaCantidad) {
    m_cantidad = nuevaCantidad;
}

void 
Producto::mostrarInfo() const {
    std::cout << "Codigo: " << m_codigo << ", Nombre: " << m_nombre 
              << ", Cantidad: " << m_cantidad << ", Precio: " << m_precio << std::endl;
}
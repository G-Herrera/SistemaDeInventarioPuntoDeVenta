#include "Prerequisites.h"
#include "Inventario.h"
#include "AlertaStock.h"
int main() {
	Inventario inventario;
	AlertaStock alerta;
	inventario.agregarObservador(&alerta);
	inventario.cargarDesdeJSON("../data/Productos.json");
	inventario.mostrarProductos();
	inventario.venderProducto("A001", 3);
	inventario.venderProducto("A001", 2);
	inventario.guardarEnJSON("../data/Productos_actualizado.json");


    return 0;
}
#include "Sistema.h"

/**
 * @brief Inicializa el sistema.
 * @details Esta función puede incluir la carga de datos iniciales,
 * configuración de parámetros, etc.
 */
void Sistema::inicializarSistema() {
  m_inventario.setRegistroVentas(&m_registroVentas);
  m_inventario.agregarObservador(&m_alertaStock);
  m_inventario.cargarDesdeJSON("../data/Productos.json");
}

/**
 * @brief Muestra el menú principal del sistema.
 * @details Esta función presenta las opciones principales al usuario
 * y maneja la navegación entre los diferentes menús.
 */
void Sistema::menuPrincipal() {
  int opcion;
  do {
    std::cout << "\n========= SISTEMA DE INVENTARIO Y PUNTO DE VENTA =========" << std::endl;
    std::cout << "1. Menu Inventario" << std::endl;
    std::cout << "2. Menu Gasolinera" << std::endl;
    std::cout << "3. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;
    std::cin.ignore();
    switch (opcion) {
      case 1:
        menuInventario();
        break;
      case 2:
        menuGasolinera();
        break;
      case 3:
        m_inventario.guardarEnJSON("../data/Productos.json");
        std::cout << "Inventario guardado. Saliendo..." << std::endl;
        break;
      default:
        std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
        break;
    }
	} while (opcion != 3);
}

/**
 * @brief Muestra el menú de inventario.
 * @details Esta función presenta las opciones relacionadas con la gestión del inventario
 * y maneja las acciones correspondientes.
 */
void 
Sistema::menuInventario() {
  int g_opcion;
  std::string g_codigo, g_nombre;
  int g_cantidad;
  double g_precio;
  std::shared_ptr<Producto> g_nuevoProducto = nullptr;

  do {
    std::cout << "\n========= MODULO DE INVENTARIO =========" << std::endl;
    std::cout << "1. Ver inventario" << std::endl;
    std::cout << "2. Agregar producto" << std::endl;
    std::cout << "3. Eliminar producto" << std::endl;
    std::cout << "4. Vender producto" << std::endl;
    std::cout << "5. Ver historial de ventas" << std::endl;
    std::cout << "6. Guardar inventario y regresar" << std::endl;
    std::cout << "7. Regresar sin guardar" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> g_opcion;
    std::cin.ignore();

    switch (g_opcion) {
    case 1:
      m_inventario.mostrarProductos();
      break;

    case 2:
      std::cout << "Ingrese codigo del producto: ";
      std::getline(std::cin, g_codigo);
      std::cout << "Ingrese nombre del producto: ";
      std::getline(std::cin, g_nombre);
      std::cout << "Ingrese cantidad del producto: ";
      std::cin >> g_cantidad;
      std::cout << "Ingrese precio del producto: ";
      std::cin >> g_precio;
      std::cin.ignore();

      g_nuevoProducto = std::make_shared<Producto>(g_codigo, g_nombre, g_cantidad, g_precio);
      m_inventario.agregarProducto(g_nuevoProducto);
      std::cout << "Producto agregado exitosamente." << std::endl;
      break;

    case 3:
      std::cout << "Ingrese codigo del producto a eliminar: ";
      std::getline(std::cin, g_codigo);
      m_inventario.eliminarProducto(g_codigo);
      std::cout << "Producto eliminado exitosamente." << std::endl;
      break;

    case 4:{
      std::cout << "\n--- Venta de Producto ---\n";

      std::cout << "Ingrese codigo del producto a vender: ";
      std::getline(std::cin, g_codigo);

      auto producto = m_inventario.buscarProducto(g_codigo);
      if (!producto) {
        std::cout << "Error: Producto no encontrado.\n";
        break;
      }

      std::cout << "Cantidad disponible: " << producto->getCantidad() << "\n";
      std::cout << "Ingrese cantidad a vender: ";
      std::cin >> g_cantidad;
      std::cin.ignore();

      if (g_cantidad <= 0 || g_cantidad > producto->getCantidad()) {
        std::cout << "Cantidad invalida.\n";
        break;
      }

      // Calcular total
      double total = producto->getPrecio() * g_cantidad;
      std::cout << "Total a pagar: $" << total << "\n";

      // Selección del método de pago
      TiposDePago* metodo = m_procesadorPago.seleccionarMetodoPago();
      if (!metodo) {
        std::cout << "Pago cancelado.\n";
        break;
      }

      json detallesPago;
      double cambio = 0;

      // Si es efectivo, pedir monto recibido
      if (metodo->informacionPago() == "EFECTIVO") {
        double recibido;
        std::cout << "Monto recibido: $";
        std::cin >> recibido;
        std::cin.ignore();
        detallesPago["recibido"] = recibido;
      }
      else {
        detallesPago["autorizacion"] = "Aprobado";
      }

      // Procesar el pago
      bool pagoExitoso = m_procesadorPago.procesarPago(total, cambio, detallesPago);
      if (!pagoExitoso) {
        std::cout << "Pago fallido. Venta cancelada.\n";
        break;
      }

      std::cout << "Pago exitoso. Cambio: $" << cambio << "\n";

      // Registrar la venta en el inventario
      m_inventario.venderProducto(g_codigo, g_cantidad);

      // Crear ticket
      std::vector<std::string> listaProductos = {
          producto->getNombre() + " x" + std::to_string(g_cantidad)
      };

      std::string ruta = "ticket_producto.txt";

      m_generadorTickets.crearTicket(
        ruta,
        listaProductos,
        total,
        cambio,
        metodo,
        detallesPago
      );

      std::cout << "Ticket generado: " << ruta << "\n";

      // Preguntar si se desea enviar por correo
      std::cout << "¿Enviar ticket por correo? (s/n): ";
      char opc;
      std::cin >> opc;
      std::cin.ignore();

      if (opc == 's' || opc == 'S') {
        std::string correo;
        std::cout << "Ingrese correo destino: ";
        std::cin >> correo;
        std::cin.ignore();

        m_generadorTickets.enviarTicketPorCorreo(correo, ruta);
      }
      break;
		}
    case 5:
      std::cout << "\nHistorial de Ventas:" << std::endl;
      m_registroVentas.mostrarHistorialVentas();
      std::cout << "Monto total de ventas: $"
        << m_registroVentas.mostrarMontoTotalVentas() << std::endl;
      break;

    case 6:
      m_inventario.guardarEnJSON("../data/Productos.json");
      std::cout << "Inventario guardado. Regresando..." << std::endl;
      return;

    case 7:
      std::cout << "Regresando sin guardar..." << std::endl;
      return;
    }
  } while (g_opcion != 7);;
}

/**
 * @brief Muestra el menú de la gasolinera.
 * @details Esta función permite al usuario seleccionar el tipo de gasolina,
 * ingresar la cantidad de litros, calcular el total, seleccionar el método de pago,
 * procesar el pago, generar el ticket y opcionalmente enviarlo por correo.
 */
void Sistema::menuGasolinera() {
  std::cout << "\n=== MODULO DE GASOLINERA ===\n";

  std::string tipoGas;
  double litros = 0.0;

  // 1. Seleccionar tipo de gasolina
  m_gasolineria.mostrarTiposGasolina();

  std::cout << "Ingrese el tipo de gasolina: ";
  std::cin >> tipoGas;

  if (!m_gasolineria.existeTipo(tipoGas)) {
    std::cout << "Error: Tipo de gasolina no valido.\n";
    return;
  }

  // 2. Ingresar litros
  std::cout << "Litros a cargar: ";
  std::cin >> litros;
  if (litros <= 0) {
    std::cout << "Cantidad invalida.\n";
    return;
  }

  // 3. Calcular total
  double precio = m_gasolineria.getPrecio(tipoGas);
  double total = precio * litros;

  std::cout << "Total a pagar: $" << total << "\n";

  // 4. Seleccionar método de pago (Strategy)
  TiposDePago* metodoSeleccionado = m_procesadorPago.seleccionarMetodoPago();
  if (!metodoSeleccionado) {
    std::cout << "Pago cancelado.\n";
    return;
  }

  // 5. Ingresar monto recibido SOLO si es efectivo
  json detallesPago;

  if (metodoSeleccionado->informacionPago() == "EFECTIVO") {
    double recibido = 0;
    std::cout << "Monto recibido: $";
    std::cin >> recibido;
    detallesPago["recibido"] = recibido;
  }
  else {
    // Simulamos detalles mínimos para tarjeta
    detallesPago["autorizacion"] = "Aprobado";
  }

  // 6. Procesar pago
  double cambio = 0;
  bool exito = m_procesadorPago.procesarPago(total, cambio, detallesPago);

  if (!exito) {
    std::cout << "El pago fallo. Venta cancelada.\n";
    return;
  }

  std::cout << "Pago exitoso.\n";
  std::cout << "Cambio: $" << cambio << "\n";

  // 7. Generar ticket de gasolina
  std::string ruta = "ticket_gasolina.txt";

  m_generadorTickets.crearTicketGasolina(
    ruta,
    tipoGas,
    litros,
    precio,
    total,
    cambio,
    metodoSeleccionado,
    detallesPago
  );

  // 8. Registrar venta (si quieres)
  // m_registroVentas.registrarVentaGasolina(tipoGas, litros, total);

  std::cout << "Ticket generado en: " << ruta << "\n";
  std::cout << "¿Desea enviar el ticket por correo? (s/n): ";
  char opcion;
  std::cin >> opcion;

  if (opcion == 's' || opcion == 'S') {
    std::string correo;
    std::cout << "Ingrese el correo destino: ";
    std::cin >> correo;
    m_generadorTickets.enviarTicketPorCorreo(correo, ruta);
  }
}


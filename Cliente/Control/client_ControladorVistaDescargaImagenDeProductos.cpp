/*
 * client_ControladorVistaDescargaImagenDeProductos.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: ale
 */

#include "client_ControladorVistaDescargaImagenDeProductos.h"
#include "../Vista/client_VistaDescargaImagenDeProductos2.h"

void ControladorVistaDescargaImagenDeProductos::on_producto_seleccionado(
		Producto* prod, Gtk::ScrolledWindow* imagenes_container){
	vista->update_lista_imagenes(prod->getIdsImagenes(), imagenes_container);
}

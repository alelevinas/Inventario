/*
 * client_VistaPrincipal.h
 *
 *  Created on: Jun 20, 2015
 *      Author: ale
 */

#ifndef CLIENTE_VISTA_CLIENT_VISTAPRINCIPAL_H_
#define CLIENTE_VISTA_CLIENT_VISTAPRINCIPAL_H_

#include <gtkmm-2.4/gtkmm.h>
#include <glibmm-2.4/glibmm.h>

#include "../Modelo/client_ModeloObservable.h"
#include "client_VistaEnviar.h"
#include "client_VistaDescargaImagenDeProductos2.h"

/*
 * A CAMBIAR POR PANELES CON PESTANIAS.
 * Es la ventana principal que contiene a las otras tres vistas.
 */
class VistaPrincipal: public Gtk::Window {
public:
	VistaPrincipal(BaseObjectType* cobject,
			const Glib::RefPtr<Gtk::Builder>& refGlade);
	virtual ~VistaPrincipal();

	void setModelo(ModeloObservable* modelo);

private:
	//signal handlers:
	bool on_exit_clicked(GdkEventAny* event);

	bool crearVistaEnviarAPartirDeGlade();

	Glib::RefPtr<Gtk::Builder> m_refGlade;
	//Gtk::Viewport *panelDinamicoEnviar;
	Gtk::Viewport *panelDinamicoDescargar;
	Gtk::Viewport *panelDinamicoCrearVideo;

	VistaEnviar* vistaEnviarPtr;
	VistaDescargaImagenDeProductos2* vistaDescargar;



};

#endif /* CLIENTE_VISTA_CLIENT_VISTAPRINCIPAL_H_ */

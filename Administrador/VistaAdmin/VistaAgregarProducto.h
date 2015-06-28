/*
 * VistaAgregarProducto.h
 *
 *  Created on: 21/6/2015
 *      Author: nicomoccagatta
 */

#ifndef ADMINISTRADOR_VISTAADMIN_VISTAAGREGARPRODUCTO_H_
#define ADMINISTRADOR_VISTAADMIN_VISTAAGREGARPRODUCTO_H_

#include <gtkmm-2.4/gtkmm.h>
#include "ModeloAdmin/admin_ModeloObservable.h"
#include "ControlAdmin/admin_ControlAP.h"
#include <cstdio>
#include <cstdlib>
using std::sprintf;
using std::strtol;

#define RUTA_IMAGEN_DEFECTO "temp_admin/imagen_vacia.png"

class VistaAgregarProducto : public Gtk::Window{
	Modelo_Observable *modelo;
	void on_button_actualizarIcono();
	void on_button_agregarImagen();
	void on_button_agregarProducto();
public:
	VistaAgregarProducto(Modelo_Observable *model);
	void eliminarIconoPertenecienteABoton(Gtk::VBox *vbbox,std::string *sfiledir);
	virtual ~VistaAgregarProducto();
protected:
	Gtk::VBox m_vBoxPrincipal;

	Gtk::HBox hBoxNombre;
	Gtk::HBox hBoxDescripcion;
	Gtk::Label m_labelNombre;
	Gtk::Entry m_ingresarNombre;
	Gtk::Label m_labelDescripcion;
	Gtk::Entry m_ingresarDescripcion;

	Gtk::Label m_labelIcono;
	Gtk::Image m_ImagenIconoPPAL;
	bool m_ImagenSeteada;
	Gtk::VButtonBox m_botoneraFileChooser;
	Gtk::FileChooserButton m_botonFileChooserImgPPAL;
	Gtk::HButtonBox m_botoneraImgPPAL;

	Gtk::HButtonBox m_botoneraImagenAgregar;
	Gtk::Label m_labelImagen;
	Gtk::Button m_botonAgregarImagen;

	Gtk::ScrolledWindow m_scrolledWImagenes;
	Gtk::Viewport *m_viewPortImagenes;
	Gtk::HButtonBox m_botoneraImagenes;
	Gtk::VButtonBox m_botoneraImagenMasDeleteButton;
	std::list<Gtk::VBox*> m_listabotonEliminarImagenes;
	std::list<Gtk::Image*> m_refImagenesdelete;
	std::list<Gtk::Button*> m_refButtondelete;
	std::list<ControlAP*> controladores;

	std::list<std::string*> m_rutaImagenesIconos;

	Gtk::Button m_AgregarProducto;
	Gtk::HButtonBox m_butoneraAgregarBoton;
};

#endif /* ADMINISTRADOR_VISTAADMIN_VISTAAGREGARPRODUCTO_H_ */

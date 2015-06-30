/*
 * VistaStockHistorico.h
 *
 *  Created on: 28/6/2015
 *      Author: nicomoccagatta
 */

#ifndef ADMINISTRADOR_VISTAADMIN_VISTASTOCKHISTORICO_H_
#define ADMINISTRADOR_VISTAADMIN_VISTASTOCKHISTORICO_H_

#include <gtkmm-2.4/gtkmm.h>
#include "ModeloAdmin/admin_ModeloObservable.h"
#include "ModelComboBoxAreasDeVision.h"
#include "ListaProductos.h"
#include <list>
#include "common_Producto.h"
#include "Graficos/GraficoDeBarras.h"
#include "Graficos/DatoGrafico.h"

class VistaStockHistorico : public Observer {
	Modelo_Observable *modelo;
	Gtk::Viewport *panelDinam;
	void update_lista_productos();
	void on_check_button_desde();
	void on_check_button_hasta();
	void on_producto_seleccionado();
	void eliminarStockInferior(Glib::Date& fechaDesde, std::list<common::Stock>& stockProducto);
	void eliminarStockSuperior(Glib::Date& fechaDesde, std::list<common::Stock>& stockProducto);

	Gtk::HBox m_HBoxGrillaEImagen;
	GraficoDeBarras m_ImagenItem;
	std::list<DatoGrafico> m_datosGrafico;

	Gtk::VBox m_vBoxPrincipalGrilla;

	Glib::RefPtr<Gtk::ListStore> m_refProductosListStore;
	Gtk::TreeView m_ProductosTreeView;
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection;
	ListaProductos m_ProductosList;

	Gtk::HBox m_horizontalBoxButoneraDesde;
	Gtk::HButtonBox m_botoneraFechaDesde;
	Gtk::Label m_labelDesde;
	Gtk::CheckButton m_activarCalendarioDesde;
	Gtk::Calendar *m_calendarioDesde;
	bool b_calendarioDesdeSeteado;

	Gtk::HBox m_horizontalBoxButoneraHasta;
	Gtk::HButtonBox m_botoneraFechaHasta;
	Gtk::Label m_labelHasta;
	Gtk::CheckButton m_activarCalendarioHasta;
	Gtk::Calendar *m_calendarioHasta;
	bool b_calendarioHastaSeteado;
public:
	VistaStockHistorico();
	void update();
	void run(Gtk::Viewport *panelDinamico,Modelo_Observable *modelo);
	virtual ~VistaStockHistorico();
};

#endif /* ADMINISTRADOR_VISTAADMIN_VISTASTOCKHISTORICO_H_ */
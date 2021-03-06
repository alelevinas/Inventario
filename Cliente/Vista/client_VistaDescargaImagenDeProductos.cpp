/*
 * client_VistaDescargaImagenDeProductos.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: ale
 */

#include <list>
#include <gdkmm-2.4/gdkmm.h>
#include <gtkmm-2.4/gtkmm.h>

#include "client_VistaDescargaImagenDeProductos.h"
#include "common_AreaDeVision.h"
#include "common_Producto.h"

using common::AreaDeVision;

VistaDescargaImagenDeProductos::VistaDescargaImagenDeProductos(BaseObjectType* cobject,
		const Glib::RefPtr<Gtk::Builder>& refGlade):
			Gtk::Viewport(cobject),m_ActiveImagenes(0){

	/* Add a Hpaned widget to our toplevel window */
	add(m_hPaned);

	/* Create a new scrolled window, with scrollbars only if needed */
	m_ProductosList.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_ProductosList.set_size_request(300,400);

	/*Agrego la TreeView a la Scrolled Window de productos*/
	m_ProductosList.add(m_ProductosTreeView);

	/* create list store */
	m_refProductosListStore = Gtk::ListStore::create(m_ProductosList.m_Columns);

	m_ProductosTreeView.set_model(m_refProductosListStore);
	m_ProductosTreeView.set_reorderable();

	/*Agrego los productos desde el ModeloObservable al modelo del TreeView*/
	//this->update_lista_productos();

	//Add the Model's column to the View's columns:
	m_ProductosTreeView.append_column("Icono", m_ProductosList.m_Columns.m_col_imagenIcono);
	m_ProductosTreeView.append_column("Producto", m_ProductosList.m_Columns.m_col_nombre);

	m_hPaned.pack1(m_ProductosList,false,true);

	/*Seteo los botones para Descargar y Atras*/
	m_DescargarButton.set_label("Descargar");

	m_VBox.pack_end(m_ButtonBox, Gtk::PACK_SHRINK);

	m_ButtonBox.pack_start(m_DescargarButton, Gtk::PACK_SHRINK);
	m_ButtonBox.set_spacing(6);
	m_ButtonBox.set_layout(Gtk::BUTTONBOX_SPREAD);

	m_hPaned.pack2(m_VBox);

	//SETEO LOS HANDLERS DE LAS SENALES
	m_DescargarButton.signal_clicked().connect(
			sigc::mem_fun(*this, &VistaDescargaImagenDeProductos::on_button_descargar));

	refTreeSelection = m_ProductosTreeView.get_selection();
	refTreeSelection->signal_changed().connect(
		    sigc::mem_fun(*this, &VistaDescargaImagenDeProductos::on_producto_seleccionado) );

	show_all_children();
}

VistaDescargaImagenDeProductos::~VistaDescargaImagenDeProductos() {
	std::cerr << "\nDESTRUYENDO VISTA DESCARGAR\n";

	Gtk::TreeModel::Children children = m_refProductosListStore->children();
	Gtk::TreeModel::Children::iterator it;

	/*Libero los ScrolledWindow que aloquee para las imagenes de los
	 productos*/
	for(it=children.begin(); it != children.end(); ++it){
		Gtk::TreeModel::Row row = *it;
		if (row[m_ProductosList.m_Columns.m_col_imagenes])
			delete row[m_ProductosList.m_Columns.m_col_imagenes];
	}
	std::cerr << "VISTA DESCARGAR DESTRUIDA\n";
}

void VistaDescargaImagenDeProductos::asignarModelo(ModeloObservable* modelo){
	this->modelo=modelo;
	this->controlador = new ControladorVistaDescargaImagenDeProductos(modelo,this);
	/*Agrego los productos desde el ModeloObservable al modelo del TreeView*/
	this->update();
}

void VistaDescargaImagenDeProductos::on_producto_seleccionado(){
	Gtk::TreeModel::iterator iter = refTreeSelection->get_selected();
	if(iter){ //If anything is selected
		Gtk::TreeModel::Row row = *iter;
		std::cerr << "APRETE EL PRODUCTO " << row[m_ProductosList.m_Columns.m_col_nombre] <<"\n";
		controlador->on_producto_seleccionado(
				row[m_ProductosList.m_Columns.m_col_data],
				row[m_ProductosList.m_Columns.m_col_imagenes]);
	}
}


/*En caso de que tengamos que actualizar altas y bajas en tiempo real*/
void VistaDescargaImagenDeProductos::update(){
	std::cerr << "UPDATE PRODUCTOS\n";

	Gtk::TreeModel::Children children = m_refProductosListStore->children();
	Gtk::TreeModel::Children::iterator it;

	/*Libero los ScrolledWindow que aloquee para las imagenes de los
	productos*/
	for(it=children.begin(); it != children.end(); ++it){
		Gtk::TreeModel::Row row = *it;
		if (row[m_ProductosList.m_Columns.m_col_imagenes])
			delete row[m_ProductosList.m_Columns.m_col_imagenes];
	}
	std::cerr << "SACANDO PRODUCTOS DEL LISTSTORE\n";
	m_refProductosListStore->clear();
	show_all();

	update_lista_productos();
	show_all();

	std::cerr << "FIN UPDATE PRODUCTOS\n\n";
}

void VistaDescargaImagenDeProductos::update_lista_productos(){
	const std::list<Producto*>* prods = modelo->getProductos();

	/* Add some messages to the window */
	std::list<Producto*>::const_iterator it;

	for (it=prods->begin(); it!=prods->end();++it){
		std::cerr << (*it)->getId() << " " << (*it)->getNombre()
				<< " iconoID: " << (*it)->getIdIcono() << std::endl;

		Gtk::TreeModel::Row row = *(m_refProductosListStore->append());
		std::string rutaImagen = modelo->getImagenConId((*it)->getIdIcono());
		if (rutaImagen != "")
			row[m_ProductosList.m_Columns.m_col_imagenIcono] = Gdk::Pixbuf::create_from_file(rutaImagen,30,30,false);

		row[m_ProductosList.m_Columns.m_col_nombre] = (*it)->getNombre();
		row[m_ProductosList.m_Columns.m_col_data] = *it;
		row[m_ProductosList.m_Columns.m_col_imagenes] = new Gtk::ScrolledWindow();

	}
}

void VistaDescargaImagenDeProductos::on_button_descargar(){
	std::cerr << "DESCARGAR\n";
	if(!m_ActiveRadio){
		std::cerr << "NINGUNA IMAGEN SELECCIONADA\n";
		return;
	}

	std::cerr << "Ruta de la imagen seleccionada: "
			<< m_ActiveRadio->get_image()->get_name()
			<< "\n";

	/*Abro el dialogo para elegir nombre de archivo, la extencion se pone sola
	 * la misma de la imagen original*/
	Gtk::FileChooserDialog dialog("Elige donde y con que nombre guardar la imagen",
			Gtk::FILE_CHOOSER_ACTION_SAVE);

	//dialog.set_transient_for(*this);

	//Add response buttons the the dialog:
	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog.add_button("Select", Gtk::RESPONSE_OK);

	int result = dialog.run();

	//Handle the response:
	switch(result){
	case(Gtk::RESPONSE_OK):{
		std::cerr << "Select clicked." << std::endl;
		std::cerr << "Folder selected: " << dialog.get_filename()
	        		<< std::endl;

		controlador->on_button_descargar(m_ActiveRadio->get_image()->get_name(), dialog.get_filename());

		break;
	}
	case(Gtk::RESPONSE_CANCEL):{
		std::cerr << "Cancel clicked." << std::endl;
		return;
	}
	default:{
		std::cerr << "Unexpected button clicked." << std::endl;
		return;
	}
	}

}

void VistaDescargaImagenDeProductos::update_lista_imagenes(
		std::list<unsigned long int>* ids,
		Gtk::ScrolledWindow* imagenes_container){

	//remover el container anterior
	if (m_ActiveImagenes != NULL)
		m_VBox.remove(*m_ActiveImagenes);

	//Si ya se cargaron las imagenes del producto seleccionado
	if (imagenes_container->get_child() != NULL){
		m_VBox.pack_start(*imagenes_container, Gtk::PACK_EXPAND_WIDGET);
		m_ActiveImagenes = imagenes_container;

	//Si nunca se selecciono
	}else{
		//Lleno su ScrolledWindow con sus fotos.
		imagenes_container->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
		imagenes_container->set_size_request(200,400);
		m_VBox.pack_start(*imagenes_container, Gtk::PACK_EXPAND_WIDGET);
		m_ActiveImagenes = imagenes_container;

		Gtk::HBox* hboxImagenes = Gtk::manage(new Gtk::HBox()); //se elimina cuando se elimina la ScrolledWindow
		imagenes_container->add(*hboxImagenes);

		std::list<unsigned long int>::iterator it;

		/*Itero los ids de imagenes para obtenerlos desde el modelo*/
		for (it=ids->begin(); it!=ids->end();++it){
			std::string ruta = modelo->getImagenConId(*it);
			if (ruta == "")
				continue;

			Gtk::Image* image = Gtk::manage(new Gtk::Image()); //se elimina cuando se elimina el HBox
			image->set(ruta.c_str());
			image->set_name(ruta.c_str());
			Glib::RefPtr<Gdk::Pixbuf> scaled1 = image->get_pixbuf()->scale_simple(150,150,Gdk::INTERP_BILINEAR);
			image->set(scaled1);

			Gtk::RadioButton* radio = Gtk::manage(new Gtk::RadioButton());

			radio->signal_toggled().connect(sigc::bind<Gtk::RadioButton*>(
					sigc::mem_fun(*this, &VistaDescargaImagenDeProductos::on_radioButton_toggled),radio ));

			radio->set_image(*image);
			radio->set_image_position(Gtk::POS_TOP);
			radio->set_group(radioGroup);
			hboxImagenes->pack_start(*radio, Gtk::PACK_SHRINK);
		}
	}

	get_settings()->set_property("gtk-button-images",true);
	show_all_children();
}

void VistaDescargaImagenDeProductos::on_radioButton_toggled(Gtk::RadioButton* radio){
	m_ActiveRadio=radio;
}


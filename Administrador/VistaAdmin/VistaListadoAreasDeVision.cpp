/*
 * VistaListadoProductos.cpp
 *
 *  Created on: 17/6/2015
 *      Author: nicomoccagatta
 */

#include "VistaListadoAreasDeVision.h"

VistaListadoAreasDeVision::VistaListadoAreasDeVision()
{
	m_AVList.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_AVList.set_size_request(200,400);
	m_AVList.add(m_AVTreeView);

	m_ProductosList.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_ProductosList.set_size_request(200,400);
	m_ProductosList.add(m_ProductosTreeView);
	m_ProductosTreeView.append_column("Productos detectados", m_ProductosList.m_Columns.m_col_nombre);

	hBoxListados.pack_start(m_AVList);
	hBoxListados.pack_end(m_ProductosList);
	m_refProductosListStore = Gtk::ListStore::create(m_ProductosList.m_Columns);
	m_ProductosTreeView.set_model(m_refProductosListStore);

	verticalBox.pack_start(hBoxListados);

	m_EditarButton.signal_clicked().connect( sigc::mem_fun(*this, &VistaListadoAreasDeVision::on_button_editar));
	m_EliminarButton.signal_clicked().connect( sigc::mem_fun(*this, &VistaListadoAreasDeVision::on_button_eliminar) );

	m_AVTreeView.append_column("ID", m_AVList.m_Columns.m_col_Id);
	m_AVTreeView.append_column("Ubicacion", m_AVList.m_Columns.m_col_Ubicacion);

	m_EditarButton.set_label("Editar Area de Vision");
	m_EliminarButton.set_label("Eliminar Area de Vision");


	verticalBox.pack_end(m_ButtonBox);
	m_ButtonBox.pack_start(m_EditarButton);
	m_ButtonBox.pack_start(m_EliminarButton);
	m_ButtonBox.set_layout(Gtk::BUTTONBOX_SPREAD);

	refTreeSelection = m_AVTreeView.get_selection();
	refTreeSelection->signal_changed().connect(
		    sigc::mem_fun(*this, &VistaListadoAreasDeVision::on_av_seleccionado) );
}

void VistaListadoAreasDeVision::update(){
	this->update_lista_av();
}

void VistaListadoAreasDeVision::run(Gtk::Viewport *panelDinamico,Modelo_Observable *model){
	this->modelo = model;
	this->panelDinam = panelDinamico;

	m_refAVListStore = Gtk::ListStore::create(m_AVList.m_Columns);
	m_AVTreeView.set_model(m_refAVListStore);
	this->update_lista_av();

	panelDinam->add(verticalBox);

	refTreeSelection = m_AVTreeView.get_selection();
}

VistaListadoAreasDeVision::~VistaListadoAreasDeVision() {
}

void VistaListadoAreasDeVision::on_button_editar(){

}

void VistaListadoAreasDeVision::on_button_eliminar(){

}

void VistaListadoAreasDeVision::on_av_seleccionado(){
	Gtk::TreeModel::iterator iter = refTreeSelection->get_selected();
	if(iter){
		Gtk::TreeModel::Row row = *iter;
		const std::list<Producto*>* prods = row[m_AVList.m_Columns.m_ProductosDetectados];
		std::cerr << "Area de Vision seleccionada: " << row[m_AVList.m_Columns.m_col_Ubicacion] <<"\n";
		std::cerr << "Cantidad Productos: " << prods->size() << std::endl;

		m_refProductosListStore = Gtk::ListStore::create(m_ProductosList.m_Columns);
		m_ProductosTreeView.set_model(m_refProductosListStore);

		std::list<Producto*>::const_iterator it;
		for (it=prods->begin(); it!=prods->end();++it){
		Gtk::TreeModel::Row row = *(m_refProductosListStore->append());
		row[m_ProductosList.m_Columns.m_col_nombre] = (*it)->getNombre();
		row[m_ProductosList.m_Columns.m_col_data] = *it;
		}
	}
}

void VistaListadoAreasDeVision::update_lista_av(){
	const std::list<AreaDeVision*>* avs = modelo->getAreasDeVision();
	std::list<AreaDeVision*>::const_iterator it;
	for (it=avs->begin(); it!=avs->end();++it){
	Gtk::TreeModel::Row row = *(m_refAVListStore->append());
	row[m_AVList.m_Columns.m_col_Id] = (*it)->getId();
	row[m_AVList.m_Columns.m_col_Ubicacion] = (*it)->getUbicacion();
	row[m_AVList.m_Columns.m_ProductosDetectados] = (*it)->getProductosDetectados();
	row[m_AVList.m_Columns.m_col_data] = *it;
	}
}

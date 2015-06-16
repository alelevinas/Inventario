/*
 * client_main.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: ale
 */
#include <string>
#include <iostream>

#include "Control/client_ControladorVistaEnviar.h"
#include "Modelo/client_ModeloObservable.h"
#include "Vista/client_VistaEnviar.h"
#include "Vista/client_VistaDescargaImagenDeProductos.h"

#define VISTA_ENVIAR "Enviar_Imagen_2.4.glade"
#define VISTA_DESCARGAR "Descargar_Imagenes_Productos.glade"


int crearAPartirDeGlade(Glib::RefPtr<Gtk::Builder>* refBuilder);

int main(int argc, char* argv[]) {
  ModeloObservable modelo;

  modelo.actualizarProductos();
  modelo.actualizarAreasDeVision();

  Gtk::Main kit(argc, argv);



  //Load the Glade file and instiate its widgets:
  Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();

  if (crearAPartirDeGlade(&refBuilder)==1)
	  return 1;

  //Get the GtkBuilder-instantiated dialog::
  //VistaEnviar* pDialogoEnviar = 0;
  VistaDescargaImagenDeProductos* pWindowDescargar;
  refBuilder->get_widget_derived("descargaImagenesWindow", pWindowDescargar);
  if(pWindowDescargar){
	  //Asignar Modelo y Controlador
	  ControladorVistaEnviar controlador(&modelo);
	  //pWindowDescargar->asignarControlador(&controlador);
	  pWindowDescargar->asignarModelo(&modelo);

	  //Start:
	  pWindowDescargar->show();
	  //pWindowDescargar->run();
	  Gtk::Main::run();
  }

  delete pWindowDescargar;
  return 0;
}


int crearAPartirDeGlade(Glib::RefPtr<Gtk::Builder>* refBuilder){

	try
	{
		(*refBuilder)->add_from_file(VISTA_DESCARGAR);
		return 0;
	}
	catch(const Glib::FileError& ex)
	{
		std::cerr << "FileError: " << ex.what() << std::endl;
		return 1;
	}
	catch(const Glib::MarkupError& ex)
	{
		std::cerr << "MarkupError: " << ex.what() << std::endl;
		return 1;
	}
	catch(const Gtk::BuilderError& ex)
	{
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}

}


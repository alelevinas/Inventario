#include "ControlAP.h"
#include "VistaAdmin/VistaAgregarProducto.h"

ControlAP::ControlAP(Gtk::VBox *button,std::string *sfiledir,void *view): boton(button), filedir(sfiledir), vista(view) {
}

void ControlAP::on_button_eliminarIcono(){
	((VistaAgregarProducto*)(vista))->eliminarIconoPertenecienteABoton(boton,filedir);
}

ControlAP::~ControlAP() {

}


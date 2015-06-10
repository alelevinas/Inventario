/*
 * common_AreaDeVision.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: leandro
 */

#include "common_AreaDeVision.h"

using common::Producto;

namespace common {

unsigned long int AreaDeVision::proximoID;

AreaDeVision::AreaDeVision(std::string ubicacion, std::string tipoDeCapturador, std::list<Producto*>* productosDetectados ,unsigned long int id):ubicacion(ubicacion),tipoDeCapturador(tipoDeCapturador),productosDetectados(productosDetectados),id(id){
	//llevo la cuenta de cual id sera el proximo
		if (AreaDeVision::proximoID<= id)
			AreaDeVision::proximoID=++id;
}

AreaDeVision::AreaDeVision(std::string ubicacion, std::string tipoDeCapturador):ubicacion(ubicacion),tipoDeCapturador(tipoDeCapturador),productosDetectados(new std::list<Producto*>()),id(AreaDeVision::proximoID++){}

AreaDeVision::~AreaDeVision() {
	liberarRecursosProductos();
}

void AreaDeVision::liberarRecursosProductos(){
	for (std::list<Producto*>::const_iterator it= productosDetectados->begin(); it != productosDetectados->end();++it)
		delete (*it);
	delete productosDetectados;
}



const std::string AreaDeVision::getUbicacion() const{
	return ubicacion;
}

const std::string AreaDeVision::getTipoDeCapturador() const{
	return tipoDeCapturador;
}

const unsigned long int AreaDeVision::getId() const{
	return id;
}

const std::list<Producto*>* const AreaDeVision::getProductosDetectados() const{
	return productosDetectados;
}

void AreaDeVision::actualizarDeteccion(std::list<Producto*>* productosDetectados) {
	liberarRecursosProductos();
	this->productosDetectados=productosDetectados;
}

void AreaDeVision::inicializarCuentaId(){
	proximoID=0;
}

} /* namespace common */
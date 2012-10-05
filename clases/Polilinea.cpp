/**
*	@file	Polilinea.cpp
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Implementación de la clase Polilinea
**/

#include "Polilinea.h"
#include <QPainter>
#include <sstream>
using namespace std;

const string Polilinea::tipoFigura = "polilinea_class";

Polilinea::Polilinea(string str){
	string aux;
	int r, g, b, estilo;
	int x, y;
	istringstream iss(str);
	
	getline(iss, aux, '.');
	iss >> r;
	getline(iss, aux, '.');
	iss >> g;
	getline(iss, aux, '.');
	iss >> b;
	this->colorBorde = QColor(r, g, b);
	getline(iss, aux, '.');
	iss >> this->grosorBorde;
	getline(iss, aux, '.');
	iss >> estilo;
	this->estiloBorde = (PenStyle)estilo;
	
	
	while(iss.good()){
		getline(iss, aux, '.');
		iss >> x;
		getline(iss, aux, '.');
		iss >> y;
		(this->puntos).push_back(pair<unsigned int, unsigned int>(x, y));
	}
}

Polilinea::Polilinea(pair<unsigned int, unsigned int> *p, QColor colorBorde,
				unsigned int grosorBorde, PenStyle estiloBorde){
	if(p != NULL)
		(this->puntos).push_back(*p);
	this->colorBorde = colorBorde;
	this->grosorBorde = grosorBorde;
	this->estiloBorde = estiloBorde;
}

QColor Polilinea::getColorBorde(){
	return this->colorBorde;
}

unsigned int Polilinea::getGrosorBorde(){
	return this->grosorBorde;
}

PenStyle Polilinea::getEstiloBorde(){
	return this->estiloBorde;
}

void Polilinea::setPunto(unsigned int posic, pair<unsigned int, unsigned int> nuevoPto){
	puntos[posic] = nuevoPto;
}

void Polilinea::setColorBorde(QColor color){
	this->colorBorde = color;
}

void Polilinea::setGrosorBorde(unsigned int grosor){
	this->grosorBorde = grosor;
}

void Polilinea::setEstiloBorde(PenStyle estilo){
	this->estiloBorde = estilo;
}

void Polilinea::addPunto(pair<unsigned int, unsigned int> p){
	(this->puntos).push_back(p);
}

void Polilinea::paint(QPaintDevice *win){
	QPainter painter(win);
	painter.setPen(QPen(this->colorBorde, this->grosorBorde, this->estiloBorde));
	if(puntos.size() > 1)
		for(int cont=0; cont < (int)puntos.size()-1; cont++)
			painter.drawLine(puntos[cont].first, puntos[cont].second, puntos[cont+1].first, puntos[cont+1].second);
}

string Polilinea::getTipoFigura(){
	return tipoFigura;
}

string Polilinea::str(){
	stringstream str;
	int r, g, b;
	
	colorBorde.getRgb(&r, &g, &b);
	str << "P." << r << "." << g << "." << b << "." << grosorBorde << "." << estiloBorde << ".";
	
	for(int cont=0; cont<puntos.size(); cont++){
		if(cont > 0)
			str << ".";
		str <<  puntos[cont].first << "." << puntos[cont].second;
	}	
		
	return str.str();
}

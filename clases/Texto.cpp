/**
*	@file Texto.cpp
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Implementación de la clase Texto.
**/

#include "Texto.h"
#include <sstream>
#include <QPainter>
using namespace std;

const string Texto::tipoFigura = "texto_class";

Texto::Texto(QString cadena, unsigned int x, unsigned int y, QColor color){
	this->cadena = cadena;
	this->x = x;
	this->y = y;
	this->color = color;
}

Texto::Texto(string str){
	string aux;
	int r, g, b;
	istringstream iss(str);
	
	getline(iss, aux, '.');
	iss >> x;
	getline(iss, aux, '.');
	iss >> y;
	getline(iss, aux, '.');
	iss >> r;
	getline(iss, aux, '.');
	iss >> g;
	getline(iss, aux, '.');
	iss >> b;
	this->color = QColor(r, g, b);
	getline(iss, aux, '.');
	iss >> aux;
	this->cadena = QString(aux.c_str());
}

void Texto::paint(QPaintDevice *win){
	QPainter painter(win);
	painter.setPen(QPen(this->color));
	painter.drawText(this->x, this->y, this->cadena);
}

string Texto::getTipoFigura(){
	return tipoFigura;
}

string Texto::str(){
	stringstream str;
	int r, g, b;
	
	color.getRgb(&r, &g, &b);
	str << "T." << x << "." << y << "." << r << "." << g << "." << b << "." << cadena.toStdString() << "\n";
			
	return str.str();
}

void Texto::setCadena(QString cadena){
	this->cadena = cadena;
}

void Texto::setColor(QColor color){
	this->color = color;
}

QColor Texto::getColor(){
	return this->color;
}

QString Texto::getCadena(){
	return this->cadena;
}

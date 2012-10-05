/**
*	@file Rectangulo.cpp
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Implementación de la clase Rectangulo
**/

#include <QPainter>
#include <utility>
#include <sstream>
#include "Figura.h"
#include "Rectangulo.h"
using namespace std;


const string Rectangulo::tipoFigura = "rectangulo_class";

Rectangulo::Rectangulo(string str){
	string aux;
	int r, g, b, estilo;
	char c;
	istringstream iss(str);
	
	getline(iss, aux, '.');
	iss >> (this->p1).first;
	getline(iss, aux, '.');
	iss >> (this->p1).second;
	getline(iss, aux, '.');
	iss >> (this->p2).first;
	getline(iss, aux, '.');
	iss >> (this->p2).second;
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
	getline(iss, aux, '.');
	iss >> c;
	if(c != '*'){
		r = (int) c;
		getline(iss, aux, '.');
		iss >> g;
		getline(iss, aux, '.');
		iss >> b; 
		this->colorRelleno = new QColor(r, g, b);
	} else {
		this->colorRelleno = NULL;
	}
	
}

Rectangulo::Rectangulo(pair<unsigned int, unsigned int> p1, pair<unsigned int, unsigned int> p2, QColor colorBorde,
				unsigned int grosorBorde, PenStyle estiloBorde, QColor *colorRelleno){
	this->p1 = p1;
	this->p2 = p2;
	this->colorBorde = colorBorde;
	this->grosorBorde = grosorBorde;
	this->estiloBorde = estiloBorde;
	if(colorRelleno != NULL)
		this->colorRelleno = new QColor(*colorRelleno);
	else
		this->colorRelleno = NULL;
}

Rectangulo::~Rectangulo(){
	delete this->colorRelleno;
}

pair<unsigned int, unsigned int> Rectangulo::getP1(){
	return this->p1;
}

pair<unsigned int, unsigned int> Rectangulo::getP2(){
	return this->p2;
}

QColor Rectangulo::getColorBorde(){
	return this->colorBorde;
}

unsigned int Rectangulo::getGrosorBorde(){
	return this->grosorBorde;
}

PenStyle Rectangulo::getEstiloBorde(){
	return this->estiloBorde;
}

QColor Rectangulo::getColorRelleno(){
	return *(this->colorRelleno);
}

void Rectangulo::setP1(pair<unsigned int, unsigned int> p){
	this->p1 = p;
}

void Rectangulo::setP2(pair<unsigned int, unsigned int> p){
	this->p2 = p;
}

void Rectangulo::setColorBorde(QColor color){
	this->colorBorde = color;
}

void Rectangulo::setGrosorBorde(unsigned int grosor){
	this->grosorBorde = grosor;
}

void Rectangulo::setEstiloBorde(PenStyle estilo){
	this->estiloBorde = estilo;
}

void Rectangulo::setColorRelleno(QColor *color){
	if(color != NULL)
		this->colorRelleno = new QColor(*color);
	else
		this->colorRelleno = NULL;
}

void Rectangulo::paint(QPaintDevice *win){
	QPainter painter(win);
	painter.setPen(QPen(this->colorBorde, this->grosorBorde, this->estiloBorde));
	if(this->colorRelleno != NULL)
		painter.setBrush(QBrush(*(this->colorRelleno)));
	painter.drawRect(p1.first, p1.second, p2.first - p1.first, p2.second - p1.second);
}

string Rectangulo::getTipoFigura(){
	return tipoFigura;
}

string Rectangulo::str(){
	stringstream str;
	int r, g, b;
	
	colorBorde.getRgb(&r, &g, &b);
	str << "R." << p1.first << "." << p1.second << "." << p2.first << "."
			<< p2.second << "." << r << "." << g << "." << b << "." << grosorBorde << "." << estiloBorde << ".";
			
	if(colorRelleno == NULL)
		str << "*" << endl;
	else{
		colorRelleno->getRgb(&r, &g, &b);
		str << r << "." << g << "." << b << endl;
	}
			
	return str.str();
}

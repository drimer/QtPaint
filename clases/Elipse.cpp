/**
*	@file Elipse.cpp
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Implementación de la clase Elipse.
**/

#include <QPainter>
#include <utility>
#include <sstream>
#include "Figura.h"
#include "Elipse.h"
using namespace std;

const string Elipse::tipoFigura = "elipse_class";

Elipse::Elipse(string str){
	string aux;
	int r, g, b, estilo;
	char c;
	istringstream iss(str);
	
	getline(iss, aux, '.');
	iss >> centro.first;
	getline(iss, aux, '.');
	iss >> centro.second;
	getline(iss, aux, '.');
	iss >> radioAncho;
	getline(iss, aux, '.');
	iss >> radioAlto;
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

Elipse::Elipse(pair<unsigned int, unsigned int> p, unsigned int width, unsigned int height, QColor colorBorde,
			unsigned int grosorBorde, PenStyle estiloBorde, QColor *colorRelleno){
	this->centro = p;
	this->radioAncho = width;
	this->radioAlto = height;
	this->colorBorde = colorBorde;
	this->grosorBorde = grosorBorde;
	this->estiloBorde = estiloBorde;
	if(colorRelleno != NULL)
		this->colorRelleno = new QColor(*colorRelleno);
	else
		this->colorRelleno = NULL;
}

Elipse::~Elipse(){
	delete this->colorRelleno;
}

pair<unsigned int, unsigned int> Elipse::getCentro(){
	return this->centro;
}

unsigned int Elipse::getAnchura(){
	return this->radioAncho;
}

unsigned int Elipse::getAltura(){
	return this->radioAlto;
}

QColor Elipse::getColorBorde(){
	return this->colorBorde;
}

unsigned int Elipse::getGrosorBorde(){
	return this->grosorBorde;
}

PenStyle Elipse::getEstiloBorde(){
	return this->estiloBorde;
}

QColor Elipse::getColorRelleno(){
	return *(this->colorRelleno);
}

void Elipse::setCentro(pair<unsigned int, unsigned int> p){
	this->centro = p;
}

void Elipse::setAnchura(unsigned int anchura){
	this->radioAncho = anchura;
}

void Elipse::setAltura(unsigned int altura){
	this->radioAlto = altura;
}

void Elipse::setColorBorde(QColor color){
	this->colorBorde = color;
}

void Elipse::setGrosorBorde(unsigned int grosor){
	this->grosorBorde = grosor;
}

void Elipse::setEstiloBorde(PenStyle estilo){
	this->estiloBorde = estilo;
}

void Elipse::setColorRelleno(QColor *color){
	if(this->colorRelleno != NULL)
		delete this->colorRelleno;
	if(color != NULL)
		this->colorRelleno = new QColor(*color);
	else
		this->colorRelleno = NULL;
}

void Elipse::setP2(pair<unsigned int, unsigned int> p){
	setAnchura((p.first-centro.first));
	setAltura((p.second-centro.second));
}

void Elipse::paint(QPaintDevice *win){
	QPainter painter(win);
	painter.setPen(QPen(this->colorBorde, this->grosorBorde, this->estiloBorde));
	if(this->colorRelleno != NULL)
		painter.setBrush(QBrush(*(this->colorRelleno)));
	painter.drawEllipse(this->centro.first, this->centro.second, this->radioAncho, this-> radioAlto);
}

string Elipse::getTipoFigura(){
	return tipoFigura;
}

void Elipse::quitaRelleno(){
	setColorRelleno(NULL);
}

string Elipse::str(){
	stringstream str;
	int r, g, b;
	
	colorBorde.getRgb(&r, &g, &b);
	str << "E." << centro.first << "." << centro.second << "." << radioAncho << "."
			<< radioAlto << "." << r << "." << g << "." << b << "." << grosorBorde << "." << estiloBorde << ".";
			
	if(colorRelleno == NULL)
		str << "*" << endl;
	else{
		colorRelleno->getRgb(&r, &g, &b);
		str << r << "." << g << "." << b << endl;
	}
			
	return str.str();
}

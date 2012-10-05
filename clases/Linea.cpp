/**
*	@file Linea.cpp
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Implementacion de la clase Linea
**/

#include <QPainter>
#include <utility>
#include <sstream>
#include "Figura.h"
#include "Linea.h"
using namespace std;

const string Linea::tipoFigura = "linea_class";

Linea::Linea(pair<unsigned int, unsigned int> p1, pair<unsigned int, unsigned int> p2,
			QColor color, unsigned int grosor, PenStyle estilo){
	this->primerPunto = p1;
	this->segundoPunto = p2;
	this->color = color;
	this->grosor = grosor;
	this->estilo = estilo;
}

Linea::Linea(string str){
	string aux;
	int r, g, b, estilo;
	istringstream iss(str);
	
	getline(iss, aux, '.');
	iss >> (this->primerPunto).first;
	getline(iss, aux, '.');
	iss >> (this->primerPunto).second;
	getline(iss, aux, '.');
	iss >> (this->segundoPunto).first;
	getline(iss, aux, '.');
	iss >> (this->segundoPunto).second;
	getline(iss, aux, '.');
	iss >> r;
	getline(iss, aux, '.');
	iss >> g;
	getline(iss, aux, '.');
	iss >> b;
	this->color = QColor(r, g, b);
	getline(iss, aux, '.');
	iss >> this->grosor;
	getline(iss, aux, '.');
	iss >> estilo;
	this->estilo = (PenStyle)estilo;
}

pair<unsigned int, unsigned int> Linea::getP1(){
	return this->primerPunto;
}

pair<unsigned int, unsigned int> Linea::getP2(){
	return this->segundoPunto;
}

QColor Linea::getColor(){
	return color;
}

PenStyle Linea::getEstilo(){
	return estilo;
}

unsigned int Linea::getGrosor(){
	return grosor;
}

void Linea::setP1(pair<unsigned int, unsigned int> p){
	this->primerPunto = p;
}

void Linea::setP2(pair<unsigned int, unsigned int> p){
	this->segundoPunto = p;
}

void Linea::setColor(QColor color){
	this->color = color;
}

void Linea::setEstilo(PenStyle estilo){
	this->estilo = estilo;
}

void Linea::setGrosor(unsigned int grosor){
	this->grosor = grosor;
}

void Linea::paint(QPaintDevice *win){
	QPainter painter(win);
	painter.setPen(QPen(this->color, this->grosor, estilo));
	painter.drawLine(this->primerPunto.first, this->primerPunto.second,
						this->segundoPunto.first, this->segundoPunto.second);
}

string Linea::getTipoFigura(){
	return tipoFigura;
}

string Linea::str(){
	stringstream str;
	int r, g, b;
	
	color.getRgb(&r, &g, &b);
	str << "L." << primerPunto.first << "." << primerPunto.second << "." << segundoPunto.first << "."
			<< segundoPunto.second << "." << r << "." << g << "." << b << "." << grosor << "." << estilo << "\n";
			
	return str.str();
}

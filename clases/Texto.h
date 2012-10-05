/**
*	@file Texto.h
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Definición de la clase que representa una figura del tipo Texto.
**/

#ifndef __TEXTO_H
#define __TEXTO_H

#include "Figura.h"
#include <QColor>
#include <QString>
#include <string>
using namespace std;

class Texto : public Figura{
private:
	QString cadena;
	unsigned int x, y;
	QColor color;
public:
	static const string tipoFigura;
	
	/*
		@name: Texto(str)
		@brief: Constructor de un texto a partir de una cadena de caracteres.
		@param str: cadena a partir de la cual creamos el texto.
	*/
	Texto(string str);
	
	/*
		@name: Texto(cadena, x, y, color)
		@brief: Constructor de texto, que recibe los parámetros necesarios para construirlo.
		@param cadena: contiene la palabra o conjunto de palabras que van a ser escritas.
		@param x: coordenada x donde se va a escribir el texto.
		@param y: coordenada y donde se va a escribir el texto.
		@param color: color que va a tener el texto.
	*/
	Texto(QString cadena, unsigned int x = 0, unsigned int y = 0, QColor color = QColor(0,0,0));
	
	/*
		@name: setCadena(cadena)
		@brief: modifica el la cadena de caracteres actual del texto.
		@param color: nueva cadena de caracteres.
	*/
	void setCadena(QString cadena);
	
	/*
		@name: setColor(color)
		@brief: modifica el color actual del texto.
		@param color: nuevo color del texto.
	*/
	void setColor(QColor color);
	
	/*
		@name: getColor()
		@brief: devuelve el color actual del texto.
		@return: el color actual del texto.
	*/
	QColor getColor();
	
	/*
		@name: getCadena()
		@brief: devuelve la cadena de caracteres actual del texto.
		@return: la cadena de caracteres.
	*/
	QString getCadena();
	
	void paint(QPaintDevice *win);
	string getTipoFigura();	
	string str();
};

#endif

/**
*	@file Linea.h
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Definición de la clase que representa una figura del tipo Linea.
**/

#ifndef __LINEA_H
#define __LINEA_H

#include <utility>
#include <QColor>
#include <Qt>
#include <string>
#include "Figura.h"
using namespace std;
using namespace Qt;

class Linea : public Figura{
private:
	pair<unsigned int, unsigned int> primerPunto;
	pair<unsigned int, unsigned int> segundoPunto;
	QColor color;
	PenStyle estilo;
	unsigned int grosor;
	
	void setDefaultValues();
	
public:
	static const string tipoFigura;
	
	/**
	*	@name Linea(p1,p2,color,grosor,estilo)
	*	@brief Constructor de Linea, que creará una linea con los valores correspondientes.
	*	@param p1 punto donde empieza la linea.
	*	@param p2 punto donde acaba la linea.
	*	@param color color que tendrá la linea.
	*	@param grosor grosor del la linea.
	*	@param estilo tipo de trazo de la linea.
	**/
	Linea(pair<unsigned int, unsigned int> p1, pair<unsigned int, unsigned int> p2 = pair<unsigned int, unsigned int>(0,0),
			QColor color = QColor(0, 0, 0), unsigned int grosor = 0, PenStyle estilo = Qt::SolidLine);
			
	/**
	*	@name Linea(str)
	*	@brief Constructor de Linea, que crea una linea a partir de una cadena de caracteres.
	*	@param str cadena de caracteres con la información.
	**/		
	Linea(string str);
	
	/**
	*	@name getP1()
	*	@brief Devuelve el punto de origen de la linea.
	*	@return punto de origen.
	**/
	pair<unsigned int, unsigned int> getP1();
	
	/**
	*	@name getP2()
	*	@brief Devuelve el punto del final de la linea.
	*	@return punto final.
	**/
	pair<unsigned int, unsigned int> getP2();
	
	/**
	*	@name getColor()
	*	@brief devuelve el color actual que tiene la linea.
	*	@return color actual de la linea.
	**/
	QColor getColor();
	
	/**
	*	@name getEstilo()
	*	@brief devuelve el estilo actual del trazo de la linea.
	*	@return estilo de trazo de la linea.
	**/
	PenStyle getEstilo();
	
	/**
	*	@name getGrosor()
	*	@brief devuelve el valor del grosor actual de linea.
	*	@return grosor de la linea.
	**/
	unsigned int getGrosor();
	
	/**
	*	@name setP1(p)
	*	@brief modifica el punto donde comienza la linea.
	*	@param p punto donde comenzará la linea.
	**/
	void setP1(pair<unsigned int, unsigned int> p);
	
	/**
	*	@name setP2(p)
	*	@brief modifica el punto donde finaliza la linea.
	*	@param p punto donde acabará la linea.
	**/
	void setP2(pair<unsigned int, unsigned int> p);
	
	/**
	*	@name setColor(color)
	*	@brief modifica el color actual de la linea.
	*	@param color nuevo color que tendrá la linea.
	**/
	void setColor(QColor color);
	
	/**
	*	@name setEstilo(estilo)
	*	@brief modifica el estilo del trazo que tiene actualmente la linea.
	*	@param estilo nuevo estilo de traza de la linea.
	**/
	void setEstilo(PenStyle estilo);
	
	/**
	*	@name setGrosor(grosor)
	*	@brief modifica el grosor de la linea.
	*	@param grosor nuevo grosor de la linea. 
	**/
	void setGrosor(unsigned int grosor);
	
	void paint(QPaintDevice *win);
	string getTipoFigura();
	string str();
};

#endif /*__LINEA_H*/

/**
*	@file Polilinea.h
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Definición de la clase que representa una figura del tipo Polilinea.
**/


#ifndef __POLILINEA_H
#define __POLILINEA_H

#include "Figura.h"
#include <Qt>
#include <QColor>
#include <vector>
#include <string>
using namespace std;
using namespace Qt;

class Polilinea : public Figura{
private:
	vector< pair<unsigned int, unsigned int> > puntos;
	QColor colorBorde;
	unsigned int grosorBorde;
	PenStyle estiloBorde;

public:
	static const string tipoFigura;
	
	/**
	*	@name Polilinea(str)
	*	@brief Constructor de una polilinea a partir de una cadena de caracteres.
	*	@param str cadena a partir de la cual creamos la polilinea.
	**/
	Polilinea(string str);
	
	/**
	*	@name Polilinea(p, colorBorde, grosorBorde, estiloBorde)
	*	@brief Constructor de una polilinea que contiene todas las estructuras necesarias para tratar un elipse.
	*	@param p par de puntos que indican el inicio de la polilinea.
	*	@param colorBorde color del borde de la polilinea.
	*	@param grosorBorde valor que indica la anchura que tendrá el trazo.
	*	@param estiloBorde valor que indica el estilo del trazo.
	**/
	Polilinea(pair<unsigned int, unsigned int> *p = NULL, QColor colorBorde = QColor(0, 0, 0),
				unsigned int grosorBorde = 1, PenStyle estiloBorde = Qt::SolidLine);
	/**
	*	@name getColorBorde()
	*	@brief devuelve el color actual de la polilinea.
	* 	@return color actual de la polilinea.
	**/
	QColor getColorBorde();
	
	/**
	*	@name getGrosorBorde()
	*	@brief devuelve el grosor del trazo que tiene actualmente la polilinea.
	* 	@return el grosor del trazo.
	**/
	unsigned int getGrosorBorde();
	
	/**
	*	@name getEstiloBorde()
	*	@brief devuelve el estilo de trazo que tiene actualmente la polilinea.
	* 	@return el estilo de trazo.
	**/
	PenStyle getEstiloBorde();
	
	/**
	*	@name setPunto(posic, nuevoPto)
	*	@brief modifica un punto de la polilinea en posición posic
	* 	@param posic posicion donde se modifica el punto
	*	@param nuevoPto punto nuevo
	**/
	void setPunto(unsigned int posic, pair<unsigned int, unsigned int> nuevoPto);
	
	/**
	*	@name setColorBorde(color)
	*	@brief modifica el color actual de la polilinea
	* 	@param color nuevo color de la polilinea
	**/
	void setColorBorde(QColor color);
	
	/**
	*	@name setGrosorBorde(grosor)
	*	@brief modifica el grosor actual de la polilinea
	* 	@param grosor nuevo grosor de la polilinea
	**/
	void setGrosorBorde(unsigned int grosor);
	
	/**
	*	@name setEstiloBorde(estilo)
	*	@brief modifica el estilo de trazo que tiene actualmente la polilinea
	* 	@param estilo nuevo estilo de trazo de la polilinea
	**/
	void setEstiloBorde(PenStyle estilo);
	
	/**
	*	@name addPunto(p)
	*	@brief añade un punto a la polilinea.
	*	@param p nuevo punto.
	**/
	void addPunto(pair<unsigned int, unsigned int> p);
	

	void paint(QPaintDevice *win);	
	string getTipoFigura();
	string str();
};

#endif /*__POLILINEA_H*/

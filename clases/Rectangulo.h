/**
*	@file Rectangulo.h
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Definición de la clase que representa una figura del tipo Rectangulo.
**/

#ifndef __RECTANGULO_H
#define __RECTANGULO_H

#include <utility>
#include <QColor>
#include <Qt>
#include <string>
#include "Figura.h"
using namespace std;
using namespace Qt;

class Rectangulo : public Figura{
private:
	pair<unsigned int, unsigned int> p1;
	pair<unsigned int, unsigned int> p2;
	QColor colorBorde;
	unsigned int grosorBorde;
	PenStyle estiloBorde;
	QColor *colorRelleno;

public:
	static const string tipoFigura;
	
	/**
	*	@name Rectangulo(str)
	*	@brief Constructor de Rectangulo que crea uno a partir de una cadena de caracteres que 
	*	contiene la información necesaria para ello.
	*	@param str cadena con la información necesaria.
	**/
	Rectangulo(string str);
	
	/**
	*	@name Rectangulo (p1, p2, colorBorde, grosorBorde, estiloBorde, colorRelleno)
	*	@brief Constructor de Rectangulo que recibe como argumento todos los parámetros necesarios para
	*	su creación.
	*	@param p1 punto donde se comienzo a dibujar el rectangulo (juntando p1 y p2 obtenemos la diagonal del mismo)
	*	@param p2 punto donde finaliza el rectangulo.
	*	@param colorBorde color del borde de el rectangulo.
	*	@param grosorBorde valor que indica la anchura que tendrá el trazo.
	*	@param estiloBorde valor que indica el estilo del trazo.
	*	@param colorRelleno color del relleno de el rectangulo.
	**/
	Rectangulo(pair<unsigned int, unsigned int> p1, pair<unsigned int, unsigned int> p2, QColor colorBorde = QColor(0, 0, 0),
				unsigned int grosorBorde = 1, PenStyle estiloBorde = Qt::SolidLine, QColor *colorRelleno = NULL);
				
	~Rectangulo();
	
	/**
	*	@name getP1()
	*	@brief devuelvel el punto de inicio del rectangulo.
	*	@return punto de inicio del rectangulo.
	**/
	pair<unsigned int, unsigned int> getP1();
	
	/**
	*	@name getP2()
	*	@brief devuelve el punto final del rectangulo.
	*	@return punto final del rectangulo.
	**/
	pair<unsigned int, unsigned int> getP2();
	
	/**
	*	@name getAnchura()
	*	@brief devuelve la anchura del rectangulo.
	*	@return anchura del rectangulo.
	**/
	int getAnchura();
	
	/**
	*	@name getAltura()
	*	@brief devuelve la altura del rectangulo.
	*	@return altura del rectangulo.
	**/
	int getAltura();
	
	/**
	*	@name getColorBorde()
	*	@brief devuelve el color actual del borde del rectangulo.
	*	@return color del borde de rectangulo.
	**/
	QColor getColorBorde();
	
	/**
	*	@name getGrosorBorde()
	*	@brief devuelve el grosor actual del trazo del rectangulo.
	*	@return grosor del trazo del rectangulo.
	**/
	unsigned int getGrosorBorde();
	
	/**
	*	@name getEstiloBorde()
	*	@brief devuleve el actual estilo de trazo del rectangulo.
	*	@return estilo del trazo del rectangulo.
	**/
	PenStyle getEstiloBorde();
	
	/**
	*	@name QColor getColorRelleno()
	*	@brief devuelve el color actual del relleno del rectangulo.
	*	@return color de relleno del rectangulo.
	**/
	QColor getColorRelleno();
	
	/**
	*	@name setP1(p)
	*	@brief modifica el punto inicial del rectangulo.
	*	@param p nuevo punto inicial del rectangulo.
	**/
	void setP1(pair<unsigned int, unsigned int> p);
	
	/**
	*	@name setP2(p)
	*	@brief modifica el punto final del rectangulo.
	*	@param p nuevo punto final del rectangulo. 
	**/
	void setP2(pair<unsigned int, unsigned int> p);
	
	/**
	*	@name setColorBorde(color)
	*	@brief modifica el color del borde actual del rectangulo. 
	*	@param color nuevo color de borde.
	**/
	void setColorBorde(QColor color);
	
	/**
	*	@name setGrosorBorde(grosor)
	*	@brief modifica el grosor actual del trazo del rectangulo.
	*	@param grosor nuevo grosor del rectangulo.
	**/
	void setGrosorBorde(unsigned int grosor);
	
	/**
	*	@name setEstiloBorde(estilo)
	*	@brief modifica el estilo del trazo del rectangulo del rectangulo.
	*	@param estilo nuevo estilo de trazo.
	**/
	void setEstiloBorde(PenStyle estilo);
	
	/**
	*	@name setColorRelleno(color)
	*	@brief modifica el color de relleno del rectangulo
	*	@param color nuevo color de relleno.
	**/
	void setColorRelleno(QColor *color);
	
	void paint(QPaintDevice *win);
	string getTipoFigura();
	string str();
};

#endif

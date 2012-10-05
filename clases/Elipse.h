/**
*	@file Elipse.h
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Definición de la clase que representa una figura del tipo Elipse.
**/

#ifndef __ELIPSE_H
#define __ELIPSE_H

#include <utility>
#include <Qt>
#include <QColor>
#include <string>
#include "Figura.h"
using namespace std;
using namespace Qt;

class Elipse : public Figura{
private:
	pair<unsigned int, unsigned int> centro;
	unsigned int radioAncho;
	unsigned int radioAlto;
	QColor colorBorde;
	unsigned int grosorBorde;
	PenStyle estiloBorde;
	QColor *colorRelleno;
	

public:
	static const string tipoFigura;

	/**
	*	@name Elipse(str)
	*	@brief Constructor de una elipse a partir de una cadena de caracteres.
	*	@param str cadena a partir de la cual creamos la elipse
	**/
	Elipse(string str);
	
	/**
	*	@name Elipse(p, width, height, colorBorde, grosorBorde, estiloBorde,  colorRelleno)
	*	@brief Constructor de una elipse que contiene todas las estructuras necesarias para tratar un elipse.
	*	@param p par de puntos que indican el centro de la elipse.
	*	@param width dimensión del eje "x" de la elipse.
	*	@param height dimensión del eje "y" de la elipse.
	*	@param colorBorde color del borde de la elipse.
	*	@param grosorBorde valor que indica la anchura que tendrá el trazo.
	*	@param estiloBorde valor que indica el estilo del trazo.
	*	@param colorRelleno color del relleno de la elipse.
	**/
	Elipse(pair<unsigned int, unsigned int> p, unsigned int width = 0, unsigned int height = 0, QColor colorBorde = QColor(0, 0, 0),
			unsigned int grosorBorde = 1, PenStyle estiloBorde = Qt::SolidLine, QColor *colorRelleno = NULL);
						
	~Elipse();
	
	
	/**
	*	@name getCentro()
	*	@brief devuelve el centro de la elipse.
	*	@return un par de enteros que son la "x" e "y" del centro de la elipse.
	**/
	pair<unsigned int, unsigned int> getCentro();
	
	/**
	*	@name getAltura();
	*	@brief devuelve la dimensión del eje "y" de la elipse.
	*	@return el tamaño del eje "y".
	*	
	**/
	unsigned int getAltura();
	
	/**
	*	@name getAnchura()
	*	@brief devuelve la dimensión del eje "x" de la elipse.
	*	@return el tamaño del eje "x".
	**/
	unsigned int getAnchura();
	
	/**
	*	@name getColorBorde()
	*	@brief devuelve el color del borde de la elipse.
	*	@return el color del borde.
	**/
	QColor getColorBorde();
	
	/**
	*	@name getGrosorBorde()
	*	@brief devuelve el valor del grosor del trazo.
	*	@return el valor del grosor del trazo.
	**/
	unsigned int getGrosorBorde();
	
	/**
	*	@name getEstiloBorde()
	*	@brief devuelve el tipo de trazo que tiene asignado actualmente.
	*	@return el tipo de trazo actual.
	**/
	PenStyle getEstiloBorde();
	
	/**
	*	@name getColorRelleno()
	*	@brief devuelve el color del interior de la elipse.
	*	@return el color interno de la elipse.
	**/
	QColor getColorRelleno();
	
	/**
	*	@name setCentro(p)
	*	@brief modifica el centro de la elipse.
	*	@param p par de enteros con el nuevo centro de la elipse.
	**/
	void setCentro(pair<unsigned int, unsigned int> p);
	
	/**
	*	@name setAltura(altura)
	*	@brief modifica la dimensión del eje "y".
	*	@param altura nuevo dimensión para el eje "y".
	**/
	void setAltura(unsigned int altura);
	
	/**
	*	@name setAnchura(anchura)
	*	@brief modifica la dimensión del eje "x".
	*	@param altura nuevo dimensión para el eje "x".
	**/
	void setAnchura(unsigned int anchura);
	
	/**
	*	@name setP2(p)
	*	@brief establece el segundo punto que identifica la elipse,
				sirve como envoltorio de setAltura y setAnchura cuando se gestiona
				la elipse como dos puntos.
	*	@param p punto a establecer.
	**/
	void setP2(pair<unsigned int, unsigned int> p);
	
	/**
	*	@name setColorBorde(color)
	*	@brief modifica el color de borde actual de la elipse.
	*	@param color nuevo color que tendrá el borde de la elipse.
	**/
	void setColorBorde(QColor color);
	
	/**
	*	@name setGrosorBorde(grosor)
	*	@brief modifica el grosor del trazo con el que se pinta la elipse.
	*	@param grosor valor del nuevo grosor del trazo.
	**/
	void setGrosorBorde(unsigned int grosor);
	
	/**
	*	@name setEstiloBorde(estilo)
	*	@brief modifica el estilo de trazo con el que se pinta la elipse.
	*	@param estilo nuevo estilo de trazo.
	**/
	void setEstiloBorde(PenStyle estilo);
	
	/**
	*	@name setColorRelleno(color)
	*	@brief modifica el color del interior de la elipse.
	*	@param color color del relleno.
	**/
	void setColorRelleno(QColor *color);	
	
	/**
	*	@name quitaRelleno()
	*	@brief pone el color de relleno de la elipse a nulo.
	**/
	void quitaRelleno();
	
	void paint(QPaintDevice *win);
	string getTipoFigura();
	string str();
};

#endif

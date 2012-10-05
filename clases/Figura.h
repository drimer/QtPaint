/**
*	@file Figura.h
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Definición de la clase que representa una figura.
*	La clase contiene únicamente métodos abstractos.
**/

#ifndef __FIGURA
#define __FIGURA

#include <QWidget>
#include <string>
using namespace std;

class Figura{
public:

	/**
	*	@name paint(win)
	*	@brief dibuja la figura en la posición y con los atributos correspondientes.
	*	@param win lugar donde queremos pintar la figura.
	**/
	virtual void paint(QPaintDevice *win)=0;
	
	/**
	*	@name getTipoFigura()
	*	@brief devuelve qué tipo de figura es.
	*	@return una cadena con el tipo de figura.
	**/
	virtual string getTipoFigura()=0;
	
	/**
	*	@name string str()
	*	@brief devuelve una cadena de caracteres que contiene la información(atributos) referente a la figura.
	*	de figura se trata.
	*	@return cadena de caracteres que guarda la informacion.
	**/
	virtual string str()=0;
};

#endif /*__FIGURA*/


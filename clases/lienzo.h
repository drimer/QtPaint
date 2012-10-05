/**
*	@file lienzo.h
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Definición de la clase que representa el lienzo de la aplicación.
**/

#ifndef __LIENZO
#define __LIENZO

#include "ui_lienzo.h"
#include "Linea.h"
#include <QSpinBox>
#include <vector>
#include <stack>
#include <Qt>
#include <QImage>
#include <QString>

using namespace std;
using namespace Qt;

class Lienzo : public QWidget{
Q_OBJECT

private:
	Figura *f;
	vector<Figura*> figuras;
	QSpinBox *grosorSpinBox;
	string tipoFiguraPintando;
	QColor *colorRelleno;
	QColor colorBorde;
	stack<Figura*> figurasDeshechas;
	PenStyle tipoTrazo;
	QString ficheroCargar;
	QImage *imgCarga;
	bool modificado;

public:
	/**
	*	@name Lienzo (parent)
	*	@brief Constructor de Lienzo, que crea un lienzo a partir de un QWidget.
	*	@param parent Qwidget que le pasamos.
	**/
	Lienzo(QWidget *parent = 0);
	
	/**
	*	@name paintEvent(event)
	*	@brief Se encarga de pintar/repintar las figuras del lienzo.
	*	@param event evento que le llega.
	**/
	void paintEvent(QPaintEvent *event);
	
	/**
	*	@name setGrosorSpinBox(spinbox)
	*	@brief Modifica el spinbox de grosor.
	*	@param nuevo spinbox.
	**/
	void setGrosorSpinBox(QSpinBox *spinbox);
	
	/**
	*	@name getColorRelleno()
	*	@brief devuelve el color de relleno que está seleccionado en este momento. 
	*	@return color de relleno.
	**/
	QColor* getColorRelleno();
	
	/**
	*	@name setColorRelleno(QColor color)
	*	@brief modifica el color de relleno que está seleccionado en este momento.
	*	@param nuevo color de relleno.
	**/
	void setColorRelleno(QColor color);
	
	/**
	*	@name destruirContenido()
	*	@brief elimina todas las figuras del lienzo.
	**/
	void destruirContenido();
	
	/**
	*	@name pedirConfirmacion(msg)
	*	@brief crea una ventana de confirmación a partir de una cadena de caracteres.
	*	@param msg cadena que queremos que muestre la ventana.
	**/
	bool pedirConfirmacion(string msg);

public slots:
	/**
	*	@name mousePressEvent(event)
	*	@brief controla los eventos de hacer click con el ratón.
	*	@param event evento asociado.
	**/
	void mousePressEvent(QMouseEvent *event);
	
	/**
	*	@name mouseMoveEvent(event)
	*	@brief controla los eventos con arrastrar el raton (manteniendo pulsado el boton).
	*	@param event evento asociado.
	**/
	void mouseMoveEvent(QMouseEvent *event);
	
	/**
	*	@name mouseReleaseEvent(event)
	*	@brief controla los eventos de dejar de clickar con el ratón.
	*	@param event evento asociado.
	**/
	void mouseReleaseEvent(QMouseEvent *event);
	
	/**
	*	@name setPintandoLinea()
	*	@brief actualiza el tipo de figura que se está pintando en este momento a Linea.
	**/
	void setPintandoLinea();
	
	/**
	*	@name setPintandoPolilinea()
	*	@brief actualiza el tipo de figura que se está pintando en este momento a Polilinea.
	**/
	void setPintandoPolilinea();
	
	/**
	*	@name setPintandoRectangulo()
	*	@brief actualiza el tipo de figura que se está pintando en este momento a Rectangulo.
	**/
	void setPintandoRectangulo();
	
	/**
	*	@name setPintandoElipse()
	*	@brief actualiza el tipo de figura que se está pintando en este momento a Elipse.
	**/
	void setPintandoElipse();
	
	/**
	*	@name setPintandoTexto()
	*	@brief actualiza el tipo de figura que se está pintando en este momento a Texto.
	**/
	void setPintandoTexto();
	
	/**
	*	@name pideColorRelleno()
	*	@brief genera una ventana en la que se puede seleccionar el color que tendrá el relleno.
	**/
	void pideColorRelleno();
	
	/**
	*	@name pideColorBorde()
	*	@brief genera una ventana en la que se puede seleccionar el color que tendrá el borde.
	**/
	void pideColorBorde();
	
	/**
	*	@name deshabilitarRelleno()
	*	@brief pone el color de relleno a NULL.
	**/
	void deshabilitarRelleno();
	
	/**
	*	@name deshacer()
	*	@brief borra la última figura pintada.
	**/
	void deshacer();
	
	/**
	*	@name rehacer()
	*	@brief repinta la última figura borrada.
	**/
	void rehacer();
	
	/**
	*	@name setSolidLine()
	*	@brief establece un trazo contínuo.
	**/
	void setSolidLine();
	
	/**
	*	@name setDotLine()
	*	@brief establece un trazo de puntos.
	**/
	void setDotLine();
	
	/**
	*	@name setDashLine()
	*	@brief establece un trazo de barras.
	**/
	void setDashLine();
	
	/**
	*	@name setDashDotLine()
	*	@brief establece un trazo de barras-punto.
	**/
	void setDashDotLine();
	
	/**
	*	@name setDashDotDotLine()
	*	@brief establece un trazo de barras-punto-punto.
	**/
	void setDashDotDotLine();
	
	/**
	*	@name guardar()
	*	@brief guarda el dibujo realizado en un fichero.
	**/
	void guardar();
	
	/**
	*	@name cargar()
	*	@brief carga un dibujo desde un fichero.
	**/
	void cargar();

private:
	Ui::Lienzo ui;
};

#endif /*__LIENZO*/

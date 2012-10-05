/**
* @file ventanaPrincipal.h
* @version 1.0
* @author Salvador Castillo Beltrán
* @author Alberto Aguilera Juárez
* @brief Definición de la clase que representa la ventana principal de la aplicación.
**/

#ifndef __VENTANA_PRNCIPAL
#define __VENTANA_PRINCIPAL

#include "ui_ventanaPrincipal.h"
#include <QSpinBox>
#include <QAction>

class VentanaPrincipal : public QMainWindow{
Q_OBJECT

private:
	Ui::VentanaPrincipal ui;
	QSpinBox *grosorSpinBox;
	QAction *botonRectangulo;
	QAction *botonElipse;
	QAction *botonLinea;
	QAction *botonPolilinea;
	QAction *botonTexto;
	QAction *botonFiguraSeleccionado;
	QAction *botonColorBorde;
	QAction *botonColorRelleno;
	QAction *botonDeshabilitarRelleno;
	QAction *botonDeshacer;
	QAction *botonRehacer;
	QAction *botonSolidLine;
	QAction *botonDotLine;
	QAction *botonDashLine;
	QAction *botonDashDotLine;
	QAction *botonDashDotDotLine;
	QAction *botonNuevo;
	QAction *botonGuardar;
	QAction *botonCargar;
	QAction *botonSalir;
	QAction *botonAcercaDe;
	
	void creaInterfaz();
	void conectaSignals();
	void creaMenus();
	void creaMenuArchivo();
	void creaMenuEdicion();
	void creaMenuAyuda();
	
	void desmarcaFiguraSeleccionada();

private slots:
	void setPintandoLinea();
	void setPintandoRectangulo();
	void setPintandoElipse();
	void setPintandoPolilinea();
	void setPintandoTexto();
	void nuevoDibujo();
	void salir();
	void mostrarAcercaDe();

public:
	VentanaPrincipal(QWidget *parent = 0);

};

#endif /*__VENTANA_PRINCIPAL*/

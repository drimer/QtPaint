/**
* @file ventanaPrincipal.cpp
* @version 1.0
* @author Salvador Castillo Beltrán
* @author Alberto Aguilera Juárez
* @brief Implementación de la clase que representa la ventana principal de la aplicación.
**/

#include "ventanaPrincipal.h"
#include <QMenu>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <cstdlib>
using namespace std;

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
	: QMainWindow(parent){
	creaInterfaz();
	conectaSignals();
	
	ui.lienzo->setGrosorSpinBox(this->grosorSpinBox);
}

void VentanaPrincipal::creaInterfaz(){
	ui.setupUi(this);
	
	this->botonLinea = new QAction(tr("Linea recta"), this);
	this->botonLinea->setIcon(QIcon("images/linea.png"));
	this->botonLinea->setShortcut(QKeySequence("Alt+L"));
	this->botonLinea->setCheckable(true);
	this->botonLinea->setChecked(true);
	ui.toolBarFiguras->addAction(this->botonLinea);
	
	this->botonRectangulo = new QAction(tr("Rectangulo"), this);
	this->botonRectangulo->setIcon(QIcon("images/rectangulo.png"));
	this->botonRectangulo->setCheckable(true);
	ui.toolBarFiguras->addAction(this->botonRectangulo);
	
	this->botonElipse = new QAction(tr("Elipse"), this);
	this->botonElipse->setIcon(QIcon("images/elipse.png"));
	this->botonElipse->setCheckable(true);
	ui.toolBarFiguras->addAction(this->botonElipse);

	this->botonPolilinea = new QAction(tr("Polilinea"), this);
	this->botonPolilinea->setIcon(QIcon("images/polilinea.png"));
	this->botonPolilinea->setCheckable(true);
	ui.toolBarFiguras->addAction(this->botonPolilinea);
	
	this->botonTexto = new QAction(tr("Texto"), this);
	this->botonTexto->setIcon(QIcon("images/texto.png"));
	this->botonTexto->setCheckable(true);
	ui.toolBarFiguras->addAction(this->botonTexto);
	
	this->botonFiguraSeleccionado = this->botonLinea;
	
	this->botonColorBorde = new QAction(tr("Color del borde"), this);
	this->botonColorBorde->setIcon(QIcon("images/colorBorde.png"));
	ui.toolBarPropiedades->addAction(this->botonColorBorde);
	
	this->botonColorRelleno = new QAction(tr("Color del relleno"), this);
	this->botonColorRelleno->setIcon(QIcon("images/colorRelleno.png"));
	ui.toolBarPropiedades->addAction(this->botonColorRelleno);
	
	this->botonDeshabilitarRelleno = new QAction(tr("Deshabilitar relleno"), this);
	this->botonDeshabilitarRelleno->setIcon(QIcon("images/deshabilitarRelleno.png"));
	ui.toolBarPropiedades->addAction(this->botonDeshabilitarRelleno);
	
	this->grosorSpinBox = new QSpinBox();
	ui.toolBarPropiedades->addAction(QString("Grosor: "));
	ui.toolBarPropiedades->addWidget(this->grosorSpinBox);
	
	this->botonDeshacer = new QAction(tr("Deshacer"), this);
	this->botonDeshacer->setIcon(QIcon("images/deshacer.png"));
	this->botonDeshacer->setShortcut(QKeySequence("Ctrl+z"));
	this->botonDeshacer->setIconVisibleInMenu(true);
	ui.toolBarEdicion->addAction(this->botonDeshacer);
	
	this->botonRehacer = new QAction(tr("Rehacer"), this);
	this->botonRehacer->setIcon(QIcon("images/rehacer.png"));
	this->botonRehacer->setShortcut(QKeySequence("Ctrl+Shift+z"));
	this->botonRehacer->setIconVisibleInMenu(true);
	ui.toolBarEdicion->addAction(this->botonRehacer);
	
	this->botonSolidLine = new QAction(tr("Solida"), this);
	this->botonSolidLine->setIcon(QIcon("images/SolidLine.png"));
	this->botonSolidLine->setIconVisibleInMenu(true);
	ui.toolBarTrazo->addAction(this->botonSolidLine);
	
	this->botonDotLine = new QAction(tr("Punto"), this);
	this->botonDotLine->setIcon(QIcon("images/DotLine.png"));
	this->botonDotLine->setIconVisibleInMenu(true);
	ui.toolBarTrazo->addAction(this->botonDotLine);
	
	this->botonDashLine = new QAction(tr("Barra"), this);
	this->botonDashLine->setIcon(QIcon("images/DashLine.png"));
	this->botonDashLine->setIconVisibleInMenu(true);
	ui.toolBarTrazo->addAction(this->botonDashLine);
	
	this->botonDashDotLine = new QAction(tr("Barra-Punto"), this);
	this->botonDashDotLine->setIcon(QIcon("images/DashDotLine.png"));
	this->botonDashDotLine->setIconVisibleInMenu(true);
	ui.toolBarTrazo->addAction(this->botonDashDotLine);
	
	this->botonDashDotDotLine = new QAction(tr("Barra-Punto-Punto"), this);
	this->botonDashDotDotLine->setIcon(QIcon("images/DashDotDotLine.png"));
	this->botonDashDotDotLine->setIconVisibleInMenu(true);
	ui.toolBarTrazo->addAction(this->botonDashDotDotLine);
	
	this->botonNuevo = new QAction(tr("&Nuevo"), this);
	this->botonNuevo->setIcon(QIcon("images/nuevo.png"));
	this->botonNuevo->setShortcut(QKeySequence("Ctrl+n"));
	this->botonNuevo->setIconVisibleInMenu(true);
	ui.toolBarArchivo->addAction(this->botonNuevo);
	
	this->botonGuardar = new QAction(tr("&Guardar"), this);
	this->botonGuardar->setIcon(QIcon("images/Save.png"));
	this->botonGuardar->setShortcut(QKeySequence("Ctrl+g"));
	this->botonGuardar->setIconVisibleInMenu(true);
	ui.toolBarArchivo->addAction(this->botonGuardar);
	
	this->botonCargar = new QAction("&Abrir", this);
	this->botonCargar->setIcon(QIcon("images/Load.png"));
	this->botonCargar->setShortcut(QKeySequence("Alt+a"));
	this->botonCargar->setIconVisibleInMenu(true);
	ui.toolBarArchivo->addAction(this->botonCargar);
	
	this->botonSalir = new QAction(tr("&Salir"), this);
	this->botonSalir->setIcon(QIcon("images/salir.png"));
	this->botonSalir->setIconVisibleInMenu(true);
	this->botonSalir->setShortcut(QKeySequence("Alt+F4"));// Alt + F4
	
	this->botonAcercaDe = new QAction(tr("&Acerca De"), this);
	this->botonAcercaDe->setIcon(QIcon("images/acercaDe.png"));
	this->botonAcercaDe->setIconVisibleInMenu(true);
	//shortcut F1
	
	creaMenus();
}

void VentanaPrincipal::conectaSignals(){
	connect(this->botonLinea, SIGNAL(triggered()), this, SLOT(setPintandoLinea()));
	connect(this->botonElipse, SIGNAL(triggered()), this, SLOT(setPintandoElipse()));
	connect(this->botonRectangulo, SIGNAL(triggered()), this, SLOT(setPintandoRectangulo()));
	connect(this->botonPolilinea, SIGNAL(triggered()), this, SLOT(setPintandoPolilinea()));
	connect(this->botonColorRelleno, SIGNAL(triggered()), ui.lienzo, SLOT(pideColorRelleno()));
	connect(this->botonColorBorde, SIGNAL(triggered()), ui.lienzo, SLOT(pideColorBorde()));
	connect(this->botonDeshabilitarRelleno, SIGNAL(triggered()), ui.lienzo, SLOT(deshabilitarRelleno()));
	connect(this->botonDeshacer, SIGNAL(triggered()), ui.lienzo, SLOT(deshacer()));
	connect(this->botonRehacer, SIGNAL(triggered()), ui.lienzo, SLOT(rehacer()));
	connect(this->botonSolidLine, SIGNAL(triggered()), ui.lienzo, SLOT(setSolidLine()));
	connect(this->botonDotLine, SIGNAL(triggered()), ui.lienzo, SLOT(setDotLine()));
	connect(this->botonDashLine, SIGNAL(triggered()), ui.lienzo, SLOT(setDashLine()));
	connect(this->botonDashDotLine, SIGNAL(triggered()), ui.lienzo, SLOT(setDashDotLine()));
	connect(this->botonDashDotDotLine, SIGNAL(triggered()), ui.lienzo, SLOT(setDashDotDotLine()));
	connect(this->botonNuevo, SIGNAL(triggered()), this, SLOT(nuevoDibujo()));
	connect(this->botonGuardar, SIGNAL(triggered()), ui.lienzo, SLOT(guardar()));
	connect(this->botonCargar, SIGNAL(triggered()), ui.lienzo, SLOT(cargar()));
	connect(this->botonSalir, SIGNAL(triggered()), this, SLOT(salir()));
	connect(this->botonAcercaDe, SIGNAL(triggered()), this, SLOT(mostrarAcercaDe()));
	connect(this->botonTexto, SIGNAL(triggered()), this, SLOT(setPintandoTexto()));
}

void VentanaPrincipal::creaMenus(){
	creaMenuArchivo();
	creaMenuEdicion();
	creaMenuAyuda();
}

void VentanaPrincipal::creaMenuArchivo(){
	ui.menuArchivo->addAction(this->botonNuevo);
	ui.menuArchivo->addAction(this->botonCargar);
	ui.menuArchivo->addAction(this->botonGuardar);
	ui.menuArchivo->addAction(this->botonSalir);
}

void VentanaPrincipal::creaMenuEdicion(){
	ui.menuEdicion->addAction(this->botonDeshacer);
	ui.menuEdicion->addAction(this->botonRehacer);
	
	ui.menuEdicion->addSeparator();
	
	QMenu *menuTipoTrazo = new QMenu(QString("Tipo de trazo"));
	menuTipoTrazo->addAction(this->botonSolidLine);
	menuTipoTrazo->addAction(this->botonDotLine);
	menuTipoTrazo->addAction(this->botonDashLine);
	menuTipoTrazo->addAction(this->botonDashDotLine);
	menuTipoTrazo->addAction(this->botonDashDotDotLine);
	ui.menuEdicion->addMenu(menuTipoTrazo);
}

void VentanaPrincipal::creaMenuAyuda(){
	ui.menuAyuda->addAction(this->botonAcercaDe);
}

void VentanaPrincipal::desmarcaFiguraSeleccionada(){
	if(botonFiguraSeleccionado != NULL){
		botonFiguraSeleccionado->setChecked(false);
	}
	botonFiguraSeleccionado = NULL;
}

void VentanaPrincipal::setPintandoLinea(){
	desmarcaFiguraSeleccionada();
	botonFiguraSeleccionado = botonLinea;
	ui.lienzo->setPintandoLinea();
}

void VentanaPrincipal::setPintandoRectangulo(){
	desmarcaFiguraSeleccionada();
	botonFiguraSeleccionado = botonRectangulo;
	ui.lienzo->setPintandoRectangulo();
}

void VentanaPrincipal::setPintandoElipse(){
	desmarcaFiguraSeleccionada();
	botonFiguraSeleccionado = botonElipse;
	ui.lienzo->setPintandoElipse();
}

void VentanaPrincipal::setPintandoPolilinea(){
	desmarcaFiguraSeleccionada();
	botonFiguraSeleccionado = botonPolilinea;
	ui.lienzo->setPintandoPolilinea();
}

void VentanaPrincipal::setPintandoTexto(){
	desmarcaFiguraSeleccionada();
	botonFiguraSeleccionado = botonTexto;
	ui.lienzo->setPintandoTexto();
}

void VentanaPrincipal::nuevoDibujo(){
	bool ret = ui.lienzo->pedirConfirmacion("Se van a perder los datos que no haya guardado."
											" Realmente quiere continuar?");
	if(ret == true){
		ui.lienzo->destruirContenido();
		ui.lienzo->paintEvent(NULL);
	}
}

void VentanaPrincipal::salir(){
	bool ret = ui.lienzo->pedirConfirmacion("Se van a perder los datos que no haya guardado."
											" Realmente quiere continuar?");
	if(ret == true){
		ui.lienzo->destruirContenido();
		exit(0);
	}
}

void VentanaPrincipal::mostrarAcercaDe(){
	QMessageBox::information(this, QString("Acerca de"), QString("Nombre:\tPinturesco\n"
								"Version:\t1.0 RC\n"
								"Autores:\tSalvador Castillo Beltran\n\tAlberto Aguilera Juarez\n"
								"Comentarios:\n\nEste programa ha sido desarrollado en C++ usando"
								"la libreria Qt, con fines educativos para la asignatura de"
								"Nuevas Tecnologias de la Programacion"));
}

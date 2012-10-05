/**
*	@file lienzo.cpp
*	@version 0.1
*	@author
*		Salvador Castillo Beltrán
*		Alberto Aguilera Juárez
*	@brief Implementación de la clase lienzo.
**/

#include "lienzo.h"
#include <QPainter>
#include <QObject>
#include <QMouseEvent>
#include <utility>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <fstream>
#include <string>
#include "clases/Linea.h"
#include "clases/Elipse.h"
#include "clases/Rectangulo.h"
#include "clases/Polilinea.h"
#include "clases/Texto.h"
using namespace std;

Lienzo::Lienzo(QWidget *parent)
	: QWidget(parent){
	ui.setupUi(this);
	this->f = NULL;
	this->tipoFiguraPintando = Linea::tipoFigura;
	this->colorRelleno = NULL;
	this->colorBorde = QColor(0, 0, 0);
	this->tipoTrazo = Qt::SolidLine;
	this->modificado = false;
}

bool Lienzo::pedirConfirmacion(string msg){
	if(this->modificado){
		int opc = QMessageBox::warning(this, tr("Aviso"), tr(msg.c_str()),
								QString("No"),
								QString("Guardar"),
								QString("Si"),
								1);
	
		if(opc == 0)
			return false;
		else if(opc == 1){
			this->guardar();
		}
	}
	return true;
}

void Lienzo::setGrosorSpinBox(QSpinBox *spinbox){
	this->grosorSpinBox = spinbox;
}

void Lienzo::paintEvent(QPaintEvent *event){
	for(int cont=0; cont<figuras.size(); cont++)
		(this->figuras)[cont]->paint(this);
	if(this->f != NULL)
		f->paint(this);
}

void Lienzo::mousePressEvent(QMouseEvent *event){
	Figura *figNueva = NULL;
	
	if(!(this->figurasDeshechas).empty()){
		while(!(this->figurasDeshechas).empty())
			(this->figurasDeshechas).pop();
	}
	
	if(this->tipoFiguraPintando == Linea::tipoFigura){
		Linea *l = new Linea(pair<unsigned int, unsigned int>(event->x(), event->y()), pair<unsigned int, unsigned int>(event->x(), event->y()));
		l->setGrosor(this->grosorSpinBox->value());
		l->setColor(this->colorBorde);
		l->setEstilo(tipoTrazo);
		figNueva = l;
	} else if(this->tipoFiguraPintando == Polilinea::tipoFigura){
		pair<unsigned int, unsigned int> *punto = new pair<unsigned int, unsigned int>(event->x(), event->y());
		Polilinea *p = NULL;
		if((this->figuras).empty()){
			p = new Polilinea(punto);
			figNueva = p;
		} else {
			Figura *ultimaFigura = (this->figuras)[(this->figuras).size()-1];
			if(ultimaFigura->getTipoFigura() == Polilinea::tipoFigura){
				p = (Polilinea*) ultimaFigura;
				p->addPunto(pair<unsigned int, unsigned int>(event->x(), event->y()));
			} else {
				p = new Polilinea(punto);
				figNueva = p;
			}
		}
		p->setColorBorde(this->colorBorde);
		p->setEstiloBorde(this->tipoTrazo);
		p->setGrosorBorde(this->grosorSpinBox->value());
	} else if(this->tipoFiguraPintando == Elipse::tipoFigura){
		Elipse *e = new Elipse(pair<unsigned int, unsigned int>(event->x(), event->y()));
		e->setGrosorBorde(this->grosorSpinBox->value());
		e->setColorRelleno(this->colorRelleno);
		e->setColorBorde(this->colorBorde);
		e->setEstiloBorde(this->tipoTrazo);
		figNueva = e;
	} else if(this->tipoFiguraPintando == Rectangulo::tipoFigura){
		Rectangulo *r = new Rectangulo(pair<unsigned int, unsigned int>(event->x(), event->y()), pair<unsigned int, unsigned int>(event->x(), event->y()));
		r->setGrosorBorde(this->grosorSpinBox->value());
		r->setColorBorde(this->colorBorde);
		r->setEstiloBorde(this->tipoTrazo);
		figNueva = r;
	} else if(this->tipoFiguraPintando == Texto::tipoFigura){
		QString str = QInputDialog::getText(this, QString("Introducir texto"), QString("Texto:"));
		Texto *t = new Texto(str, event->x(), event->y(), this->colorBorde);
		
		figNueva = t;
	}
		
	this->f = figNueva;
	
	repaint();
}

void Lienzo::mouseMoveEvent(QMouseEvent *event){
	if(this->tipoFiguraPintando == Linea::tipoFigura){
		Linea *l = (Linea*) this->f;
		l->setP2(pair<unsigned int, unsigned int>(event->x(), event->y()));
	} else if(this->tipoFiguraPintando == Elipse::tipoFigura){
		Elipse *e = (Elipse*)this->f;
		e->setP2(pair<unsigned int, unsigned int>(event->x(), event->y()));
		e->setColorRelleno(this->colorRelleno);
	} else if(this->tipoFiguraPintando == Rectangulo::tipoFigura){
		Rectangulo *r = (Rectangulo*)this->f;
		r->setP2(pair<unsigned int, unsigned int>(event->x(), event->y()));
		r->setColorRelleno(this->colorRelleno);
	}
	
	repaint();
}

void Lienzo::mouseReleaseEvent(QMouseEvent *event){
	if(this->f != NULL)
		(this->figuras).push_back(this->f);
	this->f = NULL;
	repaint();
	this->modificado = true;
}

void Lienzo::setPintandoLinea(){
	this->tipoFiguraPintando = Linea::tipoFigura;
}

void Lienzo::setPintandoPolilinea(){
	this->tipoFiguraPintando = Polilinea::tipoFigura;
}

void Lienzo::setPintandoRectangulo(){
	this->tipoFiguraPintando = Rectangulo::tipoFigura;
}

void Lienzo::setPintandoElipse(){
	this->tipoFiguraPintando = Elipse::tipoFigura;
}

void Lienzo::setPintandoTexto(){
	this->tipoFiguraPintando = Texto::tipoFigura;
}

QColor* Lienzo::getColorRelleno(){
	return this->colorRelleno;
}

void Lienzo::setColorRelleno(QColor color){
	if(this->colorRelleno != NULL)
		delete this->colorRelleno;
	this->colorRelleno = new QColor(color);
}

void Lienzo::pideColorRelleno(){
	QColor color = QColorDialog::getColor();
	if(color.isValid()){
		if(this->colorRelleno != NULL)
			delete this->colorRelleno;
		this->colorRelleno = new QColor(color);
	}
}

void Lienzo::pideColorBorde(){
	this->colorBorde = QColorDialog::getColor();
}

void Lienzo::deshabilitarRelleno(){
	this->colorRelleno = NULL;
}

void Lienzo::deshacer(){
	if(figuras.size() > 0){
		Figura *f = figuras.back();
		figuras.pop_back();
		figurasDeshechas.push(f);
		repaint();
	}
	this->modificado = true;
}

void Lienzo::rehacer(){
	if(!figurasDeshechas.empty()){
		Figura *f = figurasDeshechas.top();
		figurasDeshechas.pop();
		figuras.push_back(f);
		repaint();
	}
	this->modificado = true;
}

void Lienzo::setSolidLine(){
	this->tipoTrazo = Qt::SolidLine;
}

void Lienzo::setDotLine(){
	this->tipoTrazo = Qt::DotLine;
}

void Lienzo::setDashLine(){
	this->tipoTrazo = Qt::DashLine;
}

void Lienzo::setDashDotLine(){
	this->tipoTrazo = Qt::DashDotLine;
}

void Lienzo::setDashDotDotLine(){
	this->tipoTrazo = Qt::DashDotDotLine;
}

void Lienzo::guardar(){
	QString path = QFileDialog::getSaveFileName(this, tr("Guardar archivo"));
	if(!path.isNull()){
		ofstream salida;
		salida.open(path.toUtf8().constData());
		
		for(int i=0; i<figuras.size(); i++){
			salida << figuras[i]->str();
		}
		salida.close();
		
		this->modificado = false;
	}
}

void Lienzo::cargar(){
	if(this->modificado)
		if(pedirConfirmacion("La imagen ha sido modificada.\nSeguro que desea continuar?") == false)
			return;
	
	QString path = QFileDialog::getOpenFileName(this, tr("Abrir archivo"));
	if(!path.isNull()){
		ifstream entrada;
		entrada.open(path.toUtf8().constData());
	
		destruirContenido();
		while(entrada.good()){
			string str;
			getline(entrada, str);
		
			if(str[0]=='L')
				(this->figuras).push_back(new Linea(str));
			else if(str[0]=='R')
				(this->figuras).push_back(new Rectangulo(str));
			else if(str[0]=='E')
				(this->figuras).push_back(new Elipse(str));
			else if(str[0]=='P')
				(this->figuras).push_back(new Polilinea(str));
			else if(str[0]=='T')
				(this->figuras).push_back(new Texto(str));
		}
	}
}

void Lienzo::destruirContenido(){
	while(!figuras.empty()){
		Figura *f = figuras.back();
		figuras.pop_back();
		delete f;
	}
	this->modificado = false;
}

#include "ventanaPrincipal.h"
#include <QApplication>

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	
	QWidget *editor = new VentanaPrincipal();
	editor->show();
	
	return app.exec();
}

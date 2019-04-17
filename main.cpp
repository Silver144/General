#include "General.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	General w;
	w.show();
	return a.exec();
}

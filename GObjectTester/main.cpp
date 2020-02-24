#include "GObjectTester.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GObjectTester w;
	w.show();
	return a.exec();
}

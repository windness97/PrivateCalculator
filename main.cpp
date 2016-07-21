#include "calculatorwindow.h"
#include <QtWidgets/QApplication>

//const int TOTAL_SYMBOL = 8;
//enum FLAG_SYMBOL {
//	EQUAL = 0,
//	CLEAR = 1,
//	PLUS = 2,
//	MINUS = 3,
//	MULTIPLY = 4,
//	DIVIDE = 5,
//	POINT = 6,
//	BACK = 7
//};

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//CalculatorWindow::init();
	CalculatorWindow w;
	w.show();

	return a.exec();
}

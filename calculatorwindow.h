#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QtWidgets>
#include <string>

//class QLineEdit;
//class QPushButton;

class CalculatorWindow : public QDialog
{
	Q_OBJECT

public:
	CalculatorWindow(QWidget *parent = 0);
	~CalculatorWindow();

signals:

private slots:

private: // widgets
	static const int TOTAL_SYMBOL = 8;

	static enum FLAG_SYMBOL {
		EQUAL = 0,
		CLEAR = 1,
		PLUS = 2,
		MINUS = 3,
		MULTIPLY = 4,
		DIVIDE = 5,
		POINT = 6,
		BACK = 7
	};

	//QString STRING_SYMBOL[TOTAL_SYMBOL];

	QLabel *showText;
	QPushButton *numberButtons[10];
	QPushButton *symbolButtons[TOTAL_SYMBOL];

	static const int MARGIN = 8;
	static const int SPACING = 8;
	static const int BUTTON_HEIGHT = 35;
	static const int BUTTON_WIDTH = 40;
	static const int BUTTON_WIDTH_LARGE = 2 * BUTTON_WIDTH + SPACING;

private: //private methods
	void p_initWidgets();
	void p_connect();
	void p_setLayout();
};

#endif // CALCULATORWINDOW_H

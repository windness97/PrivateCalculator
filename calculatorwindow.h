#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QtWidgets>
#include <string>
#include "NumberButton.h"
#include "SymbolButton.h"
#include "Calculator.h"

class SymbolButton; // !!!
class Calculator;

class CalculatorWindow : public QDialog
{
	Q_OBJECT
public: // static
	void init();

	static const int TOTAL_SYMBOL = 8;
	enum FLAG_SYMBOL {
		EQUAL = 0,
		CLEAR = 1,
		PLUS = 2,
		MINUS = 3,
		MULTIPLY = 4,
		DIVIDE = 5,
		POINT = 6,
		BACK = 7
	};

private: // C
	//static QString STRING_SYMBOL[TOTAL_SYMBOL];
	QString STRING_SYMBOL[TOTAL_SYMBOL];

	static const int MARGIN = 8;
	static const int SPACING = 8;
	static const int BUTTON_HEIGHT = 35;
	static const int BUTTON_WIDTH = 40;
	static const int BUTTON_WIDTH_LARGE = 2 * BUTTON_WIDTH + SPACING;

public:
	CalculatorWindow(QWidget *parent = 0);
	~CalculatorWindow();

private slots:
	void onNumberClicked(int n);
	void onSymbolClicked(FLAG_SYMBOL flag);
	void onSymbolClicked(int flag);

	void onReceiveResult(int result);
	void onReceiveInfo(QString &str);

private: // calculator
	Calculator *calculator;

private: // widgets
	QLabel *showText;
	SymbolButton *symbolButtons[TOTAL_SYMBOL];
	//QPushButton *symbolButtons[TOTAL_SYMBOL];
	NumberButton *numberButtons[10];

private: //private methods
	void p_initWidgets();
	void p_connect();
	void p_setLayout();
};

#endif // CALCULATORWINDOW_H

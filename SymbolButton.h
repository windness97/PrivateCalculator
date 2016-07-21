#pragma once
#ifndef SYMBOLBUTTON_H
#define SYMBOLBUTTON_H

#include <QtWidgets>
#include "calculatorwindow.h"

class CalculatorWindow;

class SymbolButton : public QPushButton
{
	Q_OBJECT
public:
	SymbolButton(QString &str);
	//SymbolButton(QString &str, CalculatorWindow::FLAG_SYMBOL);
	SymbolButton(QString &str, int flag);


private:
	//CalculatorWindow::FLAG_SYMBOL flag;
	int flag;

signals:
	//void symbolButtonClicked(CalculatorWindow::FLAG_SYMBOL);
	void symbolButtonClicked(int flag);

private slots:
	void p_onClicked();

};

#endif

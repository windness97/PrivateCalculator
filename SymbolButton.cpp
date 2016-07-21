#include "SymbolButton.h"

SymbolButton::SymbolButton(QString &str)
	: QPushButton(str)
{

}

//SymbolButton::SymbolButton(QString &str, CalculatorWindow::FLAG_SYMBOL flag)
//	: QPushButton(str), flag(flag)
//{
//	connect(this, SIGNAL(clicked()), this, SLOT(p_onClicked()));
//}

SymbolButton::SymbolButton(QString &str, int flag)
	: QPushButton(str), flag(flag)
{
	connect(this, SIGNAL(clicked()), this, SLOT(p_onClicked()));
}

void SymbolButton::p_onClicked()
{
	emit symbolButtonClicked(this->flag);
}

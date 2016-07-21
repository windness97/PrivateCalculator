#include "NumberButton.h"


NumberButton::NumberButton()
	: n(0)
{
	connect(this, SIGNAL(clicked()), this, SLOT(p_onClicked()));
}

NumberButton::NumberButton(QString &str, int n)
	: QPushButton(str), n(n)
{
	connect(this, SIGNAL(clicked()), this, SLOT(p_onClicked()));
}

NumberButton::~NumberButton() {}

void NumberButton::p_onClicked() {
	emit numberButtonClicked(this->n);
}

#pragma once
#ifndef NUMBERBUTTON_H
#define NUMBERBUTTON_H

#include <QtWidgets>

class NumberButton : public QPushButton
{
	Q_OBJECT
public:
	NumberButton();
	NumberButton(QString &str, int n = 0);
	~NumberButton();
	void setN(int);
	int getN();

private:
	int n;

signals:
	void numberButtonClicked(int n);

private slots:
	void p_onClicked();
};

#endif
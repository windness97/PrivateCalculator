#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtWidgets>

class Calculator : public QObject
{
	Q_OBJECT
public:
	Calculator();
	void receiveNumber(int input);
	void receiveSymbol(int flag);
private:
	static const int TOTAL_SYMBOL = 8;
	enum FLAG_SYMBOL {
		EQUAL = 0,
		CLEAR = 1,
		PLUS = 2,
		MINUS = 3,
		MULTIPLY = 4,
		DIVIDE = 5,
		POINT = 6,
		BACK = 7,
		P_NULL = 404
	};

	int input;
	int a;
	int b;
	FLAG_SYMBOL flag; // the last symbol
	FLAG_SYMBOL _operator; // the last operator { + - * / = }
signals:
	void pushResult(int);
	void pushInfo(QString &);

////// private methods //////
private:
	void clear();
	void push(int);
	void push(QString &);
};

#endif


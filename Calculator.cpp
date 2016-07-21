#include "Calculator.h"


Calculator::Calculator()
{
	clear();
}

void Calculator::receiveNumber(int input) {
	//emit pushResult(input);
	this->input = input;

	if (flag == EQUAL) clear();

	this->flag = P_NULL;
	b = b * 10 + input;
	push(b);
}

void Calculator::receiveSymbol(int flag) {
	if (flag == CLEAR) 
	{
		clear();
		push(0);
	}
	else if (flag == POINT) {}
	else if (flag == BACK)
	{
		flag = P_NULL;
		if (this->flag == PLUS || this->flag == MINUS || this->flag == MULTIPLY || this->flag == DIVIDE || this->flag == EQUAL) {
			b = a / 10;
			a = 0;
			_operator = PLUS;
		}
		else {
			b = b / 10;
		}
		push(b);
	}

	else // + - * / +
	{	
		if (this->flag == P_NULL) // the last input is number
		{
			if (_operator == PLUS) a = a + b;
			else if (_operator == MINUS) a = a - b;
			else if (_operator == MULTIPLY) a = a * b;
			else if (_operator == DIVIDE) {
				if (b == 0) {
					clear();
					push(QString("ERROR"));
					return;
				}
				a = a / b;
			}
			push(a);
			b = 0;

			if (flag == EQUAL) _operator = PLUS;
			else _operator = FLAG_SYMBOL(flag);
		}
		else if (this->flag == PLUS || this->flag == MINUS || this->flag == MULTIPLY || this->flag == DIVIDE || this->flag == EQUAL) // the last input is {+ - * / =}
		{
			_operator = FLAG_SYMBOL(flag);
		}
	}

	this->flag = FLAG_SYMBOL(flag);
}

void Calculator::clear() {
	input = a = b = 0;
	flag = P_NULL;
	_operator = PLUS;
}

void Calculator::push(int result) {
	emit pushResult(result);
}

void Calculator::push(QString &str) {
	emit pushInfo(str);
}
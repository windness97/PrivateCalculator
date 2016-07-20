#include "calculatorwindow.h"

CalculatorWindow::CalculatorWindow(QWidget *parent)
	: QDialog(parent)
{
	p_initWidgets();
	p_connect();
	p_setLayout();

	setWindowTitle(tr("calculator ver-1.0"));
	setFixedHeight(sizeHint().height());
}

CalculatorWindow::~CalculatorWindow()
{

}

////// private methods //////

void CalculatorWindow::p_initWidgets()
{
	QString STRING_SYMBOL[TOTAL_SYMBOL] = { "=", "C", "+", "-", "*", "/", ".", "<-" };

	showText = new QLabel(tr("0"));
	showText->setAutoFillBackground(true);
	showText->setBackgroundRole(QPalette::Base);
	showText->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	showText->setContentsMargins(8, 4, 8, 4);
	//showText->setStyleSheet("font-size : 16px");
	QFont textFont("Microsoft YaHei", 16, QFont::Black);
	showText->setFont(textFont);
	showText->setMinimumHeight(0);

	QFont buttonFont("Microsoft YaHei", 10, QFont::DemiBold);
	for (int i = 0; i < 10; i++) {
		numberButtons[i] = new QPushButton(QString::number(i, 10));
		numberButtons[i]->setFixedWidth(BUTTON_WIDTH);
		numberButtons[i]->setFixedHeight(BUTTON_HEIGHT);
		//numberButtons[i]->setText(QString::number((numberButtons[i]->contentsMargins)->top(), 10));
		//numberButtons[i]->setContentsMargins
		numberButtons[i]->setFont(buttonFont);
	}
	for (int i = 0; i < TOTAL_SYMBOL; i++) {
		symbolButtons[i] = new QPushButton(STRING_SYMBOL[i]);
		if (i == CLEAR || i == EQUAL) symbolButtons[i]->setFixedWidth(BUTTON_WIDTH_LARGE);
		else symbolButtons[i]->setFixedWidth(BUTTON_WIDTH);
		symbolButtons[i]->setFixedHeight(BUTTON_HEIGHT);
		symbolButtons[i]->setFont(buttonFont);
	}
}

void CalculatorWindow::p_setLayout()
{
	QString STRING_SYMBOL[TOTAL_SYMBOL] = { "=", "C", "+", "-", "*", "/", ".", "<-" };
	QVBoxLayout *mainLayout = new QVBoxLayout;

	QHBoxLayout *lines[5];
	for (int i = 0; i < 5; i++) lines[i] = new QHBoxLayout;

	lines[0]->addWidget(symbolButtons[CLEAR]);
	lines[0]->addWidget(symbolButtons[BACK]);
	lines[0]->addWidget(symbolButtons[DIVIDE]);

	lines[1]->addWidget(numberButtons[7]);
	lines[1]->addWidget(numberButtons[8]);
	lines[1]->addWidget(numberButtons[9]);
	lines[1]->addWidget(symbolButtons[MULTIPLY]);

	lines[2]->addWidget(numberButtons[4]);
	lines[2]->addWidget(numberButtons[5]);
	lines[2]->addWidget(numberButtons[6]);
	lines[2]->addWidget(symbolButtons[MINUS]);

	lines[3]->addWidget(numberButtons[1]);
	lines[3]->addWidget(numberButtons[2]);
	lines[3]->addWidget(numberButtons[3]);
	lines[3]->addWidget(symbolButtons[PLUS]);

	lines[4]->addWidget(numberButtons[0]);
	lines[4]->addWidget(symbolButtons[POINT]);
	lines[4]->addWidget(symbolButtons[EQUAL]);

	for (int i = 0; i < 5; i++) {
		lines[i]->setMargin(0);
		lines[i]->setSpacing(SPACING);
	}
	mainLayout->setMargin(MARGIN);
	mainLayout->setSpacing(SPACING);

	mainLayout->addWidget(showText);
	for (int i = 0; i < 5; i++) {
		mainLayout->addLayout(lines[i]);
	}

	setLayout(mainLayout);
}

void CalculatorWindow::p_connect()
{

}
#include "calculatorwindow.h"

CalculatorWindow::CalculatorWindow(QWidget *parent)
	: QDialog(parent)
{
	init();

	calculator = new Calculator();

	p_initWidgets();
	p_connect();
	p_setLayout();

	setWindowTitle(tr("calculator ver-1.0"));
	setFixedHeight(sizeHint().height());
}

CalculatorWindow::~CalculatorWindow() {}

////// slots //////

void CalculatorWindow::onNumberClicked(int n)
{
	showText->setText(QString::number(n, 10));
	calculator->receiveNumber(n);
}

// ERROR!!!
void CalculatorWindow::onSymbolClicked(FLAG_SYMBOL flag)
{
	showText->setText(STRING_SYMBOL[flag]);
}

void CalculatorWindow::onSymbolClicked(int flag)
{
	calculator->receiveSymbol(flag);
}

void CalculatorWindow::onReceiveResult(int result)
{
	showText->setText(QString::number(result, 10));
}

void CalculatorWindow::onReceiveInfo(QString &str) {
	showText->setText(str);
}

////// private methods //////

void CalculatorWindow::p_initWidgets()
{
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
		numberButtons[i] = new NumberButton(QString::number(i, 10), i);
		numberButtons[i]->setFixedWidth(BUTTON_WIDTH);
		numberButtons[i]->setFixedHeight(BUTTON_HEIGHT);
		//numberButtons[i]->setText(QString::number((numberButtons[i]->contentsMargins)->top(), 10));
		numberButtons[i]->setFont(buttonFont);
	}
	for (int i = 0; i < TOTAL_SYMBOL; i++) {

		//symbolButtons[i] = new SymbolButton(STRING_SYMBOL[i], FLAG_SYMBOL(i));
		symbolButtons[i] = new SymbolButton(STRING_SYMBOL[i], i);

		//symbolButtons[i] = new SymbolButton(STRING_SYMBOL[i]);
		//symbolButtons[i] = new QPushButton(STRING_SYMBOL[i]);

		if (i == CLEAR || i == EQUAL) symbolButtons[i]->setFixedWidth(BUTTON_WIDTH_LARGE);
		else symbolButtons[i]->setFixedWidth(BUTTON_WIDTH);
		symbolButtons[i]->setFixedHeight(BUTTON_HEIGHT);
		symbolButtons[i]->setFont(buttonFont);
	}
}

void CalculatorWindow::p_setLayout()
{
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
	for (int i = 0; i < 10; i++) 
		connect(numberButtons[i], SIGNAL(numberButtonClicked(int)), this, SLOT(onNumberClicked(int)));

	for (int i = 0; i < TOTAL_SYMBOL; i++) 
		//connect(symbolButtons[i], SIGNAL(symbolButtonClicked(FLAG_SYMBOL)), this, SLOT(onSymbolClicked(FLAG_SYMBOL)));
		connect(symbolButtons[i], SIGNAL(symbolButtonClicked(int)), this, SLOT(onSymbolClicked(int)));

	connect(calculator, SIGNAL(pushResult(int)), this, SLOT(onReceiveResult(int)));
	connect(calculator, SIGNAL(pushInfo(QString &)), this, SLOT(onReceiveInfo(QString &)));

	//connect(this, SIGNAL(numberClicked(i)), this, SLOT(onNumberClicked(i)));
	//connect(this, SIGNAL(symbolClicked(i)), this, SLOT(onSymbolClicked(i)));
}

////// static //////
void CalculatorWindow::init() {
	QString temp[TOTAL_SYMBOL] = { "=", "C", "+", "-", "*", "/", ".", "<-" };
	for (int i = 0; i < TOTAL_SYMBOL; i++) {
		STRING_SYMBOL[i] = QString(temp[i]);
	}
}
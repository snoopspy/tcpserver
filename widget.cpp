#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);
	setControl();
}

Widget::~Widget()
{
	delete ui;
}

void Widget::setControl() {
	bool active = tcpServer_.isListening();
	ui->pbOpen->setEnabled(!active);
	ui->pbClose->setEnabled(active);
}

void Widget::on_pbOpen_clicked()
{
	quint16 port = ui->lePort->text().toUShort();
	bool res = tcpServer_.listen(QHostAddress::Any, port);
	if (res)
		ui->plainTextEdit->appendPlainText("Ok");
	else
		ui->plainTextEdit->appendPlainText(tcpServer_.errorString());
	setControl();
}


void Widget::on_pbClose_clicked()
{
	tcpServer_.close();
	setControl();
}


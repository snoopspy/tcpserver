#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = nullptr);
	~Widget();

	QTcpServer tcpServer_;
	void setControl();

private slots:
	void on_pbOpen_clicked();

	void on_pbClose_clicked();

private:
	Ui::Widget *ui;
};
#endif // WIDGET_H

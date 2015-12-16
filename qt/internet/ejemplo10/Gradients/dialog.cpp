#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QLinearGradient grad1(25,100,150,0);
    QRadialGradient grad2(QPoint(100,100),100);
    QConicalGradient grad3(QPoint(100,100),100);

    grad1.setColorAt(0.0,Qt::white);
    grad1.setColorAt(0.2,Qt::green);
    grad1.setColorAt(1.0,Qt::black);

    QRect rec(10,10,200,200);
    painter.fillRect(rec,grad1);
}

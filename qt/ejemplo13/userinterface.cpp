#include "userinterface.h"

UserInterface::UserInterface(QWidget *parent)
    : QWidget(parent)
{
    scene = new QGraphicsScene(&view);
    view.setScene(scene);
    rect1 = new QGraphicsRectItem(250, 0, 20, 100);
    rect1->setBrush(Qt::red);
    scene->addItem(rect1);
    rect2 = new QGraphicsRectItem(-250, 0, 20, 100);
    rect2->setBrush(Qt::red);
    scene->addItem(rect2);
    ellipse = new QGraphicsEllipseItem(0, 25, 50, 50);
    ellipse->setBrush(Qt::green);
    scene->addItem(ellipse);
    deltaX = 4;
    //itemsToColision = scene->collidingItems(ellipse);

    view.show();

    // Timer
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);
}

UserInterface::~UserInterface()
{

}

void UserInterface::update()
{
    //qDebug() << "Timer...";
    //qDebug() << ellipse->pos();
    //deltaX+=1;
    //qDebug() << deltaX;
    //ellipse->setPos(deltaX,0);
    ellipse->setPos(ellipse->pos().rx()+deltaX,0);
    //ellipse->update();

    if(!scene->collidingItems(ellipse).empty()) {

        qDebug() << "Choque";
        deltaX = -deltaX;
    }

}

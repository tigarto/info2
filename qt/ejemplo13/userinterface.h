#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QWidget>
#include <QGraphicsView>
#include <QDebug>
#include <QTimer>
#include <QGraphicsItem>

class UserInterface : public QWidget
{
    Q_OBJECT

public:
    UserInterface(QWidget *parent = 0);
    ~UserInterface();

    QGraphicsView view;
    QGraphicsScene *scene;
    QGraphicsRectItem *rect1;
    QGraphicsRectItem *rect2;
    QGraphicsEllipseItem *ellipse;
    QTimer *timer;
    qreal deltaX;

public slots:
    void update(void);
};

#endif // USERINTERFACE_H

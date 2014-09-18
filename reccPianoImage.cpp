#include "reccPianoImage.h"

#include <QGraphicsScale>

reccPianoImage::reccPianoImage(QWidget *parent) :
    QGraphicsView(parent)
{

    myScene = new QGraphicsScene(this);
    this->setScene(myScene);
    //for(int i = 0;i<9;i++)
    {
        myScene->addRect(0,0,1,LINE_HEIGHT*3/2,QPen(Qt::NoPen),QBrush(QColor(0xdd,0xee,0xee)));
        myScene->addRect(0,LINE_HEIGHT*3/2,1,LINE_HEIGHT*3/2,QPen(Qt::NoPen),QBrush(QColor(0xee,0xee,0xdd)));
        myScene->addRect(0,LINE_HEIGHT,0.8,LINE_HEIGHT,QPen(Qt::NoPen),QBrush(QColor(0x00,0x00,0x00)));
    }
    ReScale();
}

void reccPianoImage::ReScale()
{
    this->setTransform(QTransform::fromScale(this->size().width(),1));
}

#include "reccPianoImage.h"

#include <QGraphicsScale>

reccPianoImage::reccPianoImage(QWidget *parent) :
    QGraphicsView(parent)
{

    myScene = new QGraphicsScene(this);
    this->setScene(myScene);
    for(int i = 0;i<9;i++)
    {
#define LH53 (LINE_HEIGHT*5.0/3.0)
#define LH75 (LINE_HEIGHT*7.0/4.0)
        myScene->addRect(0,LINE_HEIGHT*12*i+0,10,LH53,QPen(),QBrush(QColor(0xdd,0xee,0xee)));
        myScene->addRect(0,LINE_HEIGHT*12*i+LH53,10,LH53,QPen(),QBrush(QColor(0xee,0xee,0xdd)));
        myScene->addRect(0,LINE_HEIGHT*12*i+LH53*2,10,LH53,QPen(),QBrush(QColor(0xdd,0xee,0xee)));
        myScene->addRect(0,LINE_HEIGHT*12*i+LH53*3+LH75*0,10,LH75,QPen(),QBrush(QColor(0xee,0xee,0xdd)));
        myScene->addRect(0,LINE_HEIGHT*12*i+LH53*3+LH75*1,10,LH75,QPen(),QBrush(QColor(0xdd,0xee,0xee)));
        myScene->addRect(0,LINE_HEIGHT*12*i+LH53*3+LH75*2,10,LH75,QPen(),QBrush(QColor(0xee,0xee,0xdd)));
        myScene->addRect(0,LINE_HEIGHT*12*i+LH53*3+LH75*3,10,LH75,QPen(),QBrush(QColor(0xdd,0xee,0xee)));
        myScene->addRect(2,LINE_HEIGHT*12*i+LINE_HEIGHT*3,8,LINE_HEIGHT,QPen(),QBrush(QColor(0x00,0x00,0x00)));
        myScene->addRect(2,LINE_HEIGHT*12*i+LINE_HEIGHT,8,LINE_HEIGHT,QPen(),QBrush(QColor(0x00,0x00,0x00)));
        myScene->addRect(2,LINE_HEIGHT*12*i+LINE_HEIGHT*6,8,LINE_HEIGHT,QPen(),QBrush(QColor(0x00,0x00,0x00)));
        myScene->addRect(2,LINE_HEIGHT*12*i+LINE_HEIGHT*8,8,LINE_HEIGHT,QPen(),QBrush(QColor(0x00,0x00,0x00)));
        myScene->addRect(2,LINE_HEIGHT*12*i+LINE_HEIGHT*10,8,LINE_HEIGHT,QPen(),QBrush(QColor(0x00,0x00,0x00)));
#undef LH53
#undef LH75
    }
    ReScale();
}

void reccPianoImage::ReScale()
{

    this->setTransform(QTransform::fromScale(this->mapToScene(0,this->size().width()-5).x()*0.1,1));
}

void reccPianoImage::wheelEvent(QWheelEvent *event)
{
    //Do nothing.
    Q_UNUSED(event)
}

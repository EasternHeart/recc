#include "reccPianoRollInputArea.h"



reccPianoRollInputArea::reccPianoRollInputArea(QWidget *parent) :
    QGraphicsView(parent)
{
    myScene = new QGraphicsScene(this);
    this->setScene(myScene);
    lineItems = new QList<QGraphicsItem*>;

    lineWidth = 500.0;

    initLines();

    lineWidthNormalize();
}

void reccPianoRollInputArea::Extend()
{
    lineWidth += 100.0;
    lineWidthNormalize();
}

void reccPianoRollInputArea::lineWidthNormalize()
{

}

void reccPianoRollInputArea::initLines()
{
    for(int i = 0;i<9;i++)
    {
#define LINE(n,color) lineItems->append(myScene->addRect(0,-LINE_HEIGHT*(i*12+n),lineWidth,LINE_HEIGHT \
        ,QPen(Qt::NoPen),QBrush(color)));
#define TBLACK QColor(0x00,0x00,0x00,0x20)
#define TWHITE QColor(0xff,0xff,0xff,0x20)
        LINE(0,TWHITE);
        LINE(1,TBLACK);
        LINE(2,TWHITE);
        LINE(3,TBLACK);
        LINE(4,TWHITE);
        LINE(5,TBLACK);
        LINE(6,TWHITE);
        LINE(7,TWHITE);
        LINE(8,TBLACK);
        LINE(9,TWHITE);
        LINE(10,TBLACK);
        LINE(11,TWHITE);
#undef LINE
#undef TBLACK
#undef TWHITE
    }
}

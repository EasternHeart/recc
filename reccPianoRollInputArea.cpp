#include "reccPianoRollInputArea.h"

#include <QScrollBar>

reccPianoRollInputArea::reccPianoRollInputArea(QWidget *parent) :
    QGraphicsView(parent)
{
    myScene = new QGraphicsScene(this);
    this->setScene(myScene);
    lineItems = new QList<QGraphicsItem*>;

    lineWidth = 0;
    outHorizontalScrollBar = NULL;

    {
        reccNote n;
        n.position=0;
        n.note = 32;
        n.length=1920;
        n.lyric="a";
        n.xsampa="a";
        this->addNoteAndShow(n);
    }
}

void reccPianoRollInputArea::Extend()
{
    lineWidth += 100.0;
    lineWidthNormalize();
}

void reccPianoRollInputArea::lineWidthNormalize()
{
    QGraphicsItem *gi;
    foreach(gi,*lineItems)
    {
        delete gi;
    }
    initLines();
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

void reccPianoRollInputArea::setPianoImage(reccPianoImage *image)
{
    this->pianoImage = image;
}

void reccPianoRollInputArea::scrollContentsBy(int dx, int dy)
{
    int thisMin,thisMax,thisVal,imMin,imMax;
    thisMin = this->verticalScrollBar()->minimum();
    thisMax = this->verticalScrollBar()->maximum();
    thisVal = this->verticalScrollBar()->value();
    imMin = pianoImage->verticalScrollBar()->minimum();
    imMax = pianoImage->verticalScrollBar()->maximum();

    pianoImage->verticalScrollBar()->setValue(
                ((int)(((thisVal-thisMin)*1.0)/(thisMax-thisMin)*(imMax-imMin)+imMin)));

    /*qDebug("reccPianoRollInputArea::scrollContentsBy(%d,%d)\nthisVal = %d, thisMin = %d, thisMax = %d\n"
           "imMin = %d, imMax = %d, Target is %d\n"
           ,dx,dy,thisVal,thisMin,thisMax,imMin,imMax,((int)(((thisVal-thisMin)*1.0)/(thisMax-thisMin)*(imMax-imMin)+imMin)));*/

    QGraphicsView::scrollContentsBy(dx,dy);
}

void reccPianoRollInputArea::AutoMinimalLineWidth()
{
    double lineWidth1 = (mapToScene(size().width(),0)-mapToScene(0,0)).x();
    if(lineWidth1>lineWidth)
    {
        lineWidth = lineWidth1;
        lineWidthNormalize();
    }
}

void reccPianoRollInputArea::resizeEvent(QResizeEvent *event)
{
    AutoMinimalLineWidth();
    QGraphicsView::resizeEvent(event);
    updateScrollBarValue();
}

void reccPianoRollInputArea::setScrollBar(QScrollBar *sb)
{
    //this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //this->setHorizontalScrollBar(sb);
    outHorizontalScrollBar = sb;
    connect(sb,SIGNAL(sliderMoved(int)),this,SLOT(syncOutHorizontalScrollBar(int)));
    updateScrollBarValue();
}

void reccPianoRollInputArea::updateScrollBarValue()
{
    if(outHorizontalScrollBar)
    {
        outHorizontalScrollBar->setMinimum(this->horizontalScrollBar()->minimum());
        outHorizontalScrollBar->setMaximum(this->horizontalScrollBar()->maximum());
        outHorizontalScrollBar->setValue(this->horizontalScrollBar()->value());
    }
}

void reccPianoRollInputArea::syncOutHorizontalScrollBar(int value)
{
    this->horizontalScrollBar()->setValue(/*outHorizontalScrollBar->value()*/value);
}

static bool notePositionLessThan(const reccNote &s1, const reccNote &s2)
{
    return s1.position < s2.position;
}


void reccPianoRollInputArea::addNoteAndShow(const reccNote &note)
{
    reccPianoRollDisplayedNoteItems di;
    noteDisplayItems.insert(note,di);
    if(lineWidth < (note.position+note.length)*WIDTH_PER_TICK)
    {
        lineWidth = (note.position+note.length)*WIDTH_PER_TICK;
        lineWidthNormalize();
    }
    di.background = myScene->addRect(note.position*WIDTH_PER_TICK,
                                     -note.note*LINE_HEIGHT,
                                     note.length*WIDTH_PER_TICK,
                                     LINE_HEIGHT,QPen(),QBrush(QColor(0x66,0xcc,0xff)));
    di.lyric = myScene->addText(note.lyric + " [" + note.xsampa + "]");
    di.lyric->setPos(note.position*WIDTH_PER_TICK,
                     -note.note*LINE_HEIGHT);
    di.pitch = NULL;
    notes.append(note);
}

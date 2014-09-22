#ifndef RECCPIANOROLLINPUTAREA_H
#define RECCPIANOROLLINPUTAREA_H

#include "recc_global.h"

#include <QWidget>
#include <QScrollArea>
#include <QGraphicsView>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>

#include "reccPianoImage.h"
#include "reccNote.h"
#include "reccGraphicsPitchItem.h"

struct reccPianoRollDisplayedNoteItems
{
    QGraphicsRectItem *background;
    QGraphicsTextItem *lyric;
    reccGraphicsPitchItem *pitch;
};

class reccPianoRollInputArea : public QGraphicsView
{
    Q_OBJECT
    
    friend class reccPianoRoll;
    
public:
    explicit reccPianoRollInputArea(QWidget *parent = 0);
    void setPianoImage(reccPianoImage *image);
    void AutoMinimalLineWidth();
    void setScrollBar(QScrollBar *sb);
    void addNoteAndShow(const reccNote &note);
    
signals:
    
public slots:
    void syncOutHorizontalScrollBar(int value);

private:
    QList<QGraphicsItem*> *lineItems;
    QGraphicsScene *myScene;
    void Extend();
    double lineWidth;
    void lineWidthNormalize();
    void initLines();
    reccPianoImage *pianoImage;
    QScrollBar *outHorizontalScrollBar;
    void updateScrollBarValue();

    QList<reccNote> notes;
    QHash<reccNote,reccPianoRollDisplayedNoteItems> noteDisplayItems;


protected:
    void scrollContentsBy(int dx, int dy);
    virtual void	resizeEvent(QResizeEvent * event);

};

#endif // RECCPIANOROLLINPUTAREA_H

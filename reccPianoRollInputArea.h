#ifndef RECCPIANOROLLINPUTAREA_H
#define RECCPIANOROLLINPUTAREA_H

#include "recc_global.h"

#include <QWidget>
#include <QScrollArea>
#include <QGraphicsView>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "reccPianoImage.h"

class reccPianoRollInputArea : public QGraphicsView
{
    Q_OBJECT
public:
    explicit reccPianoRollInputArea(QWidget *parent = 0);
    void setPianoImage(reccPianoImage *image);
    void AutoMinimalLineWidth();
    
signals:
    
public slots:

private:
    QList<QGraphicsItem*> *lineItems;
    QGraphicsScene *myScene;
    void Extend();
    double lineWidth;
    void lineWidthNormalize();
    void initLines();
    reccPianoImage *pianoImage;

protected:
    void scrollContentsBy(int dx, int dy);
    virtual void	resizeEvent(QResizeEvent * event);

};

#endif // RECCPIANOROLLINPUTAREA_H

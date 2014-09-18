#ifndef RECCPIANOROLLINPUTAREA_H
#define RECCPIANOROLLINPUTAREA_H

#include "recc_global.h"

#include <QWidget>
#include <QScrollArea>
#include <QGraphicsView>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsScene>

class reccPianoRollInputArea : public QGraphicsView
{
    Q_OBJECT
public:
    explicit reccPianoRollInputArea(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    QList<QGraphicsItem*> *lineItems;
    QGraphicsScene *myScene;
    void Extend();
    double lineWidth;
    void lineWidthNormalize();
    void initLines();

};

#endif // RECCPIANOROLLINPUTAREA_H

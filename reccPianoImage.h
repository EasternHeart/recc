#ifndef RECCPIANOIMAGE_H
#define RECCPIANOIMAGE_H

#include "recc_global.h"

#include <QWidget>
#include <QGraphicsView>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsScene>

class reccPianoImage : public QGraphicsView
{
    Q_OBJECT
public:
    explicit reccPianoImage(QWidget *parent = 0);
    friend class reccPianoRollInputArea;
    
signals:
    
public slots:

private:
    QGraphicsScene *myScene;
    void ReScale();

protected:
    void wheelEvent ( QWheelEvent * event );

};

#endif // RECCPIANOIMAGE_H

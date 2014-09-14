#ifndef RECCPIANOIMAGE_H
#define RECCPIANOIMAGE_H

#include <QWidget>

class reccPianoImage : public QWidget
{
    Q_OBJECT
public:
    explicit reccPianoImage(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    
signals:
    
public slots:

private:
    int position;
    
};

#endif // RECCPIANOIMAGE_H

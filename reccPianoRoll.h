#ifndef RECCPIANOROLL_H
#define RECCPIANOROLL_H

#include <QWidget>

namespace Ui {
class reccPianoRoll;
}

class reccPianoRoll : public QWidget
{
    Q_OBJECT
    
public:
    explicit reccPianoRoll(QWidget *parent = 0);
    ~reccPianoRoll();
    
private:
    Ui::reccPianoRoll *ui;
};

#endif // RECCPIANOROLL_H

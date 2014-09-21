#include "reccPianoRoll.h"
#include "ui_pianoroll.h"

reccPianoRoll::reccPianoRoll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reccPianoRoll)
{
    ui->setupUi(this);
    //DPI Hack

    //setPianoImage
    ui->widget_2->setPianoImage(this->ui->widget);
    ui->widget_2->setScrollBar(this->ui->horizontalScrollBar);
}

reccPianoRoll::~reccPianoRoll()
{
    delete ui;
}

#include "reccPianoRoll.h"
#include "ui_pianoroll.h"

reccPianoRoll::reccPianoRoll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reccPianoRoll)
{
    ui->setupUi(this);
    //DPI Hack
}

reccPianoRoll::~reccPianoRoll()
{
    delete ui;
}

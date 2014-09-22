#ifndef RECCNOTEUSERDATA_H
#define RECCNOTEUSERDATA_H

#include <QObject>

class reccNoteUserData : public QObject
{
    Q_OBJECT
public:
    explicit reccNoteUserData(QObject *parent = 0);

    virtual QByteArray serialize() = 0;
    
signals:

public slots:

};

#endif // RECCNOTEUSERDATA_H

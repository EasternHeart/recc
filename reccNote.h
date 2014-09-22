#ifndef RECCNOTE_H
#define RECCNOTE_H


#include "reccNoteUserData.h"

struct reccNote
{
public:
    reccNote();

    reccNote(const reccNote &n);
    
    int position;
    int length;
    int note;
    QList<double> *pitchBend;
    
    QString lyric;
    QString xsampa;
    
    reccNoteUserData *userData;

    bool operator == (const reccNote& note) const;
    
    //QByteArray serialize();
};

uint qHash(const reccNote &note,uint seed = 0);

#endif // RECCNOTE_H

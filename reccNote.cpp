#include "reccNote.h"

reccNote::reccNote()
{
    pitchBend = new QList<double>;
}


reccNote::reccNote(const reccNote &n)
{
    position = n.position;
    lyric = n.lyric;
    pitchBend = new QList<double>;
    pitchBend->append(*n.pitchBend);
    length = n.length;
    xsampa = n.xsampa;
}

uint qHash(const reccNote &note,uint seed)
{
    uint temp = 0;
    temp += note.position;
    temp += note.length;
    //temp += qHash(note.lyric,seed);
    //temp += qHash(note.xsampa,seed);
    temp += seed;
    return temp;
}

bool reccNote::operator == (const reccNote& note) const
{
    if(length != note.length) return false;
    if(position != note.position) return false;
    if(lyric != note.lyric) return false;
    if(xsampa != note.xsampa) return false;
    return true;
}

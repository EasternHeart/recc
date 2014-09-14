#-------------------------------------------------
#
# Project created by QtCreator 2014-09-14T22:14:37
#
#-------------------------------------------------

QT       += gui

TARGET = recc
TEMPLATE = lib

DEFINES += RECC_LIBRARY

SOURCES += \
    reccNote.cpp \
    reccPianoRoll.cpp \
    reccPianoImage.cpp \
    reccPianoRollInputArea.cpp

HEADERS +=\
        recc_global.h \
    reccNote.h \
    reccPianoRoll.h \
    reccPianoImage.h \
    reccPianoRollInputArea.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    pianoroll.ui

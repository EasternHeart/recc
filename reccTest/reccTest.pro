#-------------------------------------------------
#
# Project created by QtCreator 2014-09-17T17:39:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = reccTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../recc-build/lib/debug/release/ -lrecc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../recc-build/lib/debug/debug/ -lrecc
else:unix: LIBS += -L$$PWD/../../recc-build/lib/debug/ -lrecc

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../

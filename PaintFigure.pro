#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T20:24:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PaintFigure
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    romb.cpp \
    paintscene.cpp \
    figure.cpp \
    triangle.cpp \
    square.cpp \
    krug.cpp \
    line.cpp

HEADERS  += mainwindow.h \
    romb.h \
    paintscene.h \
    figure.h \
    triangle.h \
    square.h \
    krug.h \
    line.h

FORMS    +=

RESOURCES += \
    Sourse/png.qrc

DISTFILES += \
    ../../../Desktop/romb.png

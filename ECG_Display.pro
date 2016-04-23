#-------------------------------------------------
#
# Project created by QtCreator 2015-10-02T11:49:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ECG_Display
TEMPLATE = app


SOURCES += main.cpp\
        ecgdisplay.cpp \
        qcustomplot.cpp

HEADERS  += ecgdisplay.h \
        qcustomplot.h

FORMS    += ecgdisplay.ui

DISTFILES += \
    100.dat



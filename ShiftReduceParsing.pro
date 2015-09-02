#-------------------------------------------------
#
# Project created by QtCreator 2013-09-16T12:09:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShiftReduceParsing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parse.cpp

HEADERS  += mainwindow.h \
    ../parse.h \
    parse.h

FORMS    += mainwindow.ui

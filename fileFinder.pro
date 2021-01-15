#-------------------------------------------------
#
# Project created by QtCreator 2021-01-15T14:03:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fileFinder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    threadfinder.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
    threadfinder.h \
    controller.h

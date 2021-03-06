#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T15:46:46
#
#-------------------------------------------------

QT       += core network

QT       -= gui

LIBS += -lwiringPi
#LIBS += wiringPi.a
TARGET = bottie
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    motor.cpp \
    networking.cpp \
    syslog.cpp \
    networkserver.cpp \
    nservicethread.cpp

HEADERS += \
    motor.hpp \
    networking.hpp \
    syslog.hpp \
    networkserver.hpp \
    nservicethread.hpp

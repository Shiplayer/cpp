#-------------------------------------------------
#
# Project created by QtCreator 2015-03-05T14:44:07
#
#-------------------------------------------------

QT       += core gui
QT       += network
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    chat.cpp

HEADERS  += login.h \
    chat.h

FORMS    += login.ui \
    chat.ui

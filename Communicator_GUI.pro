#-------------------------------------------------
#
# Project created by QtCreator 2019-05-04T21:08:41
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Communicator_GUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    database.cc \
    forgotten_password.cpp \
    help.cpp \
        main.cpp \
        mainwindow.cpp \
    menu.cpp \
    user.cpp \
    registration.cpp

HEADERS += \
    database.h \
    forgotten_password.h \
    help.h \
        mainwindow.h \
    menu.h \
    user.h \
    registration.h

FORMS += \
    forgotten_password.ui \
    help.ui \
        mainwindow.ui \
    menu.ui \
    registration.ui

RESOURCES += \
    gui.qrc \
    resources.qrc

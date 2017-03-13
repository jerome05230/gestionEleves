#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T08:46:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestEleves
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    etudiant.cpp \
    evaluation.cpp \
    matiere.cpp \
    note.cpp \
    Section.cpp \
    dialogmatiere.cpp

HEADERS  += mainwindow.h \
    etudiant.h \
    evaluation.h \
    matiere.h \
    note.h \
    section.h \
    dialogmatiere.h

FORMS    += mainwindow.ui \
    dialogmatiere.ui

OTHER_FILES += \
    gestEleves.pro.user \
    gestEleves.pro.user.e1ed551

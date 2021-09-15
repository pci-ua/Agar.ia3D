QT   += core gui widgets
LIBS += -lglut -lGLU

QMAKE_CC = gcc
QMAKE_CXX = g++

TARGET = Agaria
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17

SOURCES += \
     \
     $$files(Modele/*.cc,true) \
     $$files(Vue/*.cc) \
     $$files(Controlleur/*.cc) \
     $$files(Intelligence/*.cc) \
     $$files(Menu/*.cpp) \
     main.cpp \

HEADERS += \
     \
     $$files(Modele/*/*.hh) \
     $$files(Vue/*.hh) \
     $$files(Controlleur/*.hh) \
     $$files(Intelligence/*.hh) \
     $$files(Menu/*.hpp) \
     constante.hh \

DESTDIR = ./
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
UI_DIR = build/ui

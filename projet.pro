QT   += core gui
LIBS += -lglut -lGLU

greaterThan(QT_MAJOR_VERSION, 5): QT += widgetss

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
     main.cpp \

HEADERS += \
     \
     $$files(Modele/*/*.hh) \
     $$files(Vue/*.hh) \
     $$files(Controlleur/*.hh) \
     $$files(Intelligence/*.hh) \
     constante.hh \

DESTDIR = ./
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
UI_DIR = build/ui

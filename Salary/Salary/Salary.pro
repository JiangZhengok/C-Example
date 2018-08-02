TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    salary.cpp

HEADERS += \
    salary.h


#-------------------------------------------------
#
# Project created by QtCreator 2017-06-11T18:42:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Patterns_For_ImmunoAssay
TEMPLATE = app

INCLUDEPATH += C:/Boost/boost_1_62_0

SOURCES += main.cpp\
        mainwindow.cpp \
    Factory/factory.cpp \
    Instrument/DilutionRack/dilutionrack.cpp \
    Instrument/SampleRack/samplerack.cpp \
    Instrument/WellRack/wellrack.cpp \
    Instrument/configuration.cpp \
    Instrument/instrument.cpp \
    Exceptions/exceptions.cpp \
    Mago4/Mago4DilutionRack/mago4dilutionrack.cpp \
    Mago4/Mago4SampleRack/mago4samplerack.cpp \
    Mago4/Mago4WellRack/mago4wellrack.cpp \
    Mago4/mago4.cpp \
    Factory/mago4factory.cpp \
    Mago4s/Mago4sDilutionRack/mago4sdilutionrack.cpp \
    Mago4s/Mago4sSampleRack/mago4ssamplerack.cpp \
    Mago4s/Mago4sWellRack/mago4swellrack.cpp \
    Factory/mago4sfactory.cpp

HEADERS  += mainwindow.h \
    Factory/factory.h \
    Factory/mago4factory.h \
    Factory/mago4sfactory.h \
    Instrument/DilutionRack/dilutionrack.h \
    Instrument/SampleRack/samplerack.h \
    Instrument/WellRack/wellrack.h \
    Instrument/configuration.h \
    Instrument/instrument.h \
    Templates/listiterator.h \
    Templates/matrix.h \
    Templates/Singleton.h \
    Exceptions/exceptions.h \
    Mago4/Mago4DilutionRack/mago4dilutionrack.h \
    Mago4/Mago4SampleRack/mago4samplerack.h \
    Mago4/Mago4WellRack/mago4wellrack.h \
    Mago4/mago4.h \
    Mago4s/Mago4sDilutionRack/mago4sdilutionrack.h \
    Mago4s/Mago4sSampleRack/mago4ssamplerack.h \
    Mago4s/Mago4sWellRack/mago4swellrack.h

FORMS    += mainwindow.ui

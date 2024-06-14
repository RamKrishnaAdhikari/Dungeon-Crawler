QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    character.cpp \
    startscreen.cpp \
    tile.cpp \
    floor.cpp \
    wall.cpp \
    portal.cpp \
    level.cpp \
    input.cpp \
    dungeoncrawler.cpp \
    active.cpp \
    passive.cpp \
    switch.cpp \
    door.cpp \
    pit.cpp \
    ramp.cpp \
    abstractview.cpp \
    abstractcontroller.cpp \
    graphicalui.cpp

HEADERS += \
    mainwindow.h \
    character.h \
    startscreen.h \
    tile.h \
    floor.h \
    wall.h \
    portal.h \
    level.h \
    input.h \
    dungeoncrawler.h \
    active.h \
    passive.h \
    switch.h \
    door.h \
    pit.h \
    ramp.h \
    abstractview.h \
    abstractcontroller.h \
    graphicalui.h

FORMS += \
    mainwindow.ui \
    startscreen.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    textures.qrc

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractcontroller.cpp \
    abstractview.cpp \
    active.cpp \
    character.cpp \
    door.cpp \
    dungeoncrawler.cpp \
    floor.cpp \
    graphicalui.cpp \
    guardiancontroller.cpp \
    level.cpp \
    levelchanger.cpp \
    list.cpp \
    lootchest.cpp \
    main.cpp \
    mainwindow.cpp \
    passive.cpp \
    pit.cpp \
    portal.cpp \
    ramp.cpp \
    startscreen.cpp \
    stationerycontroller.cpp \
    switch.cpp \
    tile.cpp \
    wall.cpp\
    random.cpp

HEADERS += \
    abstractcontroller.h \
    abstractview.h \
    active.h \
    character.h \
    door.h \
    dungeoncrawler.h \
    floor.h \
    graphicalui.h \
    guardiancontroller.h \
    level.h \
    levelchanger.h \
    list.h \
    lootchest.h \
    mainwindow.h \
    passive.h \
    pit.h \
    portal.h \
    ramp.h \
    startscreen.h \
    stationerycontroller.h \
    switch.h \
    tile.h \
    wall.h \
    random.h

FORMS += \
    mainwindow.ui \
    startscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    textures.qrc

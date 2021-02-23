TEMPLATE = app
TARGET = LiveStreamCam
DESTDIR = ../x64/Debug
CONFIG += debug
INCLUDEPATH += OPENCV\include
LIBS += -L"C:\opencv-4.5.1\opencv\build\x64\vc15\lib"
LIBS += -lopencv_world451d
LIBS += -lOpengl32
QT += opengl
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
include(LiveStreamCam.pri)
win32:RC_FILE = LiveStreamCam.rc
RESOURCES += livestreamcam.qrc

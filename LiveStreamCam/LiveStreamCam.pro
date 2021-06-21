TEMPLATE = app
TARGET = LiveStreamCam
INCLUDEPATH += OPENCV\include
LIBS += -L"$$PWD\OPENCV\lib"
CONFIG(debug, debug|release) {
LIBS += -lopencv_world452d
DESTDIR = ../x64/Debug
}else{
LIBS += -lopencv_world452
DESTDIR = ../x64/Release
}
LIBS += -lOpengl32
QT += opengl
DEFINES += CAFFE_CONFIG_FILE=\\\"$$PWD/OPENCV/model/deploy.prototxt\\\"
DEFINES += CAFFE_WEIGHTS_FILE=\\\"$$PWD/OPENCV/model/res10_300x300_ssd_iter_140000_fp16.caffemodel\\\"
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
include(LiveStreamCam.pri)
win32:RC_FILE = LiveStreamCam.rc
RESOURCES += livestreamcam.qrc

TEMPLATE = app
TARGET = LiveStreamCam

# Windows
win32 {

    INCLUDEPATH += OPENCV\include
    LIBS += -L"$$PWD\OPENCV\lib"
    CONFIG(debug, debug|release) {
    LIBS += -lopencv_world452d
    } else {
    LIBS += -lopencv_world452
    }
    LIBS += -lOpengl32  
}

# Linux
unix:!macx {

    INCLUDEPATH += /usr/local/include/opencv4
    LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_dnn -lopencv_video -lopencv_videoio -lopencv_ml -lopencv_imgcodecs -lopencv_imgproc
}

# Mac OS
macx {

    INCLUDEPATH += /usr/local/include/opencv4
    LIBS += -L/usr/local/opt/opencv/lib/
    LIBS += -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_dnn -lopencv_video -lopencv_videoio -lopencv_ml -lopencv_imgcodecs -lopencv_imgproc
}

QT += opengl

DEFINES += CAFFE_CONFIG_FILE=\\\"$$PWD/OPENCV/model/deploy.prototxt\\\"
DEFINES += CAFFE_WEIGHTS_FILE=\\\"$$PWD/OPENCV/model/res10_300x300_ssd_iter_140000_fp16.caffemodel\\\"

CONFIG(debug, debug|release) {
    DESTDIR = debug
    OBJECTS_DIR = debug
    } else {
    DESTDIR = release
    OBJECTS_DIR = release
}

DEPENDPATH += .
MOC_DIR += .
UI_DIR += .
RCC_DIR += .

include(LiveStreamCam.pri)
win32:RC_FILE = LiveStreamCam.rc
RESOURCES += livestreamcam.qrc

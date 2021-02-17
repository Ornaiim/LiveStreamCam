#pragma once

#include "opencv2/opencv.hpp"
#include <QtWidgets/QMainWindow>
#include "ui_livestreamcam.h"
#include <QDebug>

class LiveStreamCam : public QMainWindow
{
    Q_OBJECT

public:
    LiveStreamCam(QWidget *parent = Q_NULLPTR);

    void setButtons();
    void openCamera(cv::VideoCapture cap, int cameraNumber);
    int validCamera(cv::VideoCapture cap);
    void recordVideo();

    int getVideoCaptureWidth(cv::VideoCapture cap);
    int getVideoCaptureHeight(cv::VideoCapture cap);
    const QString getCurrentDateAndTime();
    const QString getVideoFolder();

public slots:
    void launchCamera();
    void updateFrame();
    void nextCamera();
    void captureCamera();
    void toggleRecord();
    void updateVideoTimer();

private:
    Ui::LiveStreamCamClass ui;

    QTimer* frameTimer;
    QTimer* recordTimer;
    QTime* videoTime;

    QImage qFrame;
    QPixmap pixmap;

    const int MAX_CAMERA = 5;
    int numActiveCamera;
    int activeCamera;
    bool isRecording;

    cv::VideoCapture capture;
    cv::VideoWriter video;
};

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
    void openCamera(int cameraNumber);
    void launchCamera();
    void recordVideo();

    int validCamera(cv::VideoCapture cap);
    int getVideoCaptureWidth(cv::VideoCapture cap);
    int getVideoCaptureHeight(cv::VideoCapture cap);
    const QString getCurrentDateAndTime();
    const QString getVideoFolder();

public slots:
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

    const int MAX_CAMERA = 5;
    int numActiveCamera;
    int activeCamera;
    bool isRecording;

    cv::VideoCapture capture;
    cv::VideoWriter video;
};

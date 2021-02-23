#include "livestreamcam.h"
#include "stdafx.h"

LiveStreamCam::LiveStreamCam(QWidget *parent)
    : QMainWindow(parent)
{
    // Set UI from Qt Designer generated file
    ui.setupUi(this);

    activeCamera = 0;
    isRecording = false;
    numActiveCamera = validCamera(capture);
    frameTimer = new QTimer(this);
    recordTimer = new QTimer(this);
    videoTime = new QTime(0, 0, 0);

    // Center window on screen
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());

    connect(ui.captureButton, SIGNAL(clicked()), this, SLOT(captureCamera()));
    connect(ui.recordButton, SIGNAL(clicked()), this, SLOT(toggleRecord()));
    setButtons();
    launchCamera();
}

void LiveStreamCam::setButtons()
{
    // Set up widgets visibility
    ui.chronoLabel->setVisible(false);
    ui.recordButton->setIcon(QIcon(":/LiveStreamCam/Icons/VideoIcon.png"));
    ui.captureButton->setVisible(true);

    if (numActiveCamera > 1) 
    {
        ui.nextCameraButton->setVisible(true);
    }    
}

void LiveStreamCam::openCamera(int cameraNumber)
{
    // Open and set a new max size (default 480p)
    capture.open(cameraNumber);
    capture.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
}

void LiveStreamCam::nextCamera()
{
    activeCamera = activeCamera + 1;

    // Loop back to first active camera
    if (activeCamera >= numActiveCamera)
    {
        activeCamera = 0;
    }
    openCamera(activeCamera);
}

void LiveStreamCam::launchCamera()
{
    openCamera(activeCamera);

    // If no camera is found
    if (!capture.isOpened())
    {
        qCritical() << "Error: Unable to find your camera";
        return;
    }

    // Hide camera switch function if there is less than 2 cameras detected
    if (numActiveCamera <= 1)
    {
        ui.nextCameraButton->setVisible(false);
    }
    else
    {
        ui.nextCameraButton->setVisible(true);
        connect(ui.nextCameraButton, SIGNAL(clicked()), this, SLOT(nextCamera()));
    }

    // Start timer to refresh live stream images, updated every 20ms
    connect(frameTimer, SIGNAL(timeout()), this, SLOT(updateFrame()));
    frameTimer->start(20);
}

void LiveStreamCam::updateFrame()
{
    // Initiate OpenCV Mat type to contain VideoCapture
    cv::Mat frame;
    capture >> frame;

    // If a video is recording, write each frames into video file
    if (isRecording)
    {
        video.write(frame);
    }

    ui.openGLWidget->displayImage(frame);       // Display VideoCapture frames from QOpenGLWidget
    ui.openGLWidget->setMinimumSize(250, 200);  // Set a minimum size to QOpenGLWidget

    qFrame = ui.openGLWidget->getOGLImage();    // Get QImage from QOpenGLWidget
    qFrame = std::move(qFrame).rgbSwapped();    // BGR to RGB conversion
}

void LiveStreamCam::captureCamera()
{
    // Pause VideoCapture timer to get the wanted picture
    frameTimer->stop();

    // Set image file resolution to the VideoCapture size
    int imageWidth = getVideoCaptureWidth(capture);
    int imageHeight = getVideoCaptureHeight(capture);

    // Open dialog window to save the picture taken
    QString file = QFileDialog::getSaveFileName(this, "Save as...", getCurrentDateAndTime(), "JPEG (*.jpg *.jpeg);; PNG (*.png);; BMP (*.bmp)");
    qFrame = qFrame.scaled(imageWidth, imageHeight);
    qFrame.save(file);

    // Restart the timer once the user has saved or closed the dialog window
    frameTimer->start();
}

void LiveStreamCam::toggleRecord()
{
    // Start / stop video recording
    isRecording = !isRecording;

    // Start recording and set up UI
    if (isRecording)
    {
        ui.recordButton->setIcon(QIcon(":/LiveStreamCam/Icons/RecordingIcon.png"));
        ui.chronoLabel->setVisible(true);
        ui.captureButton->setVisible(false);
        ui.nextCameraButton->setVisible(false);
        ui.recordButton->setToolTip("Stop recording");
        recordVideo();

        // Video recording timer to display on screen
        connect(recordTimer, SIGNAL(timeout()), this, SLOT(updateVideoTimer()));
        videoTime->start();
        recordTimer->start(1000);
    }
    else
    {
        // Stop recording and set back UI to normal
        recordTimer->stop();
        ui.recordButton->setToolTip("Record video");
        ui.chronoLabel->setText("00:00");
        setButtons();
    }
}

void LiveStreamCam::recordVideo()
{
    int fcc = cv::VideoWriter::fourcc('D','I','V','X');                                  // Video codec initialization (types: H264, MJPG, DIVX...)
    int fps = 20;                                                                        // Set video FPS
    cv::Size frameSize(getVideoCaptureWidth(capture), getVideoCaptureHeight(capture));   // Get the resolution of the video
    QString file = getCurrentDateAndTime() + ".avi";                                     // File name + .avi type
    const cv::String filename = file.toStdString();                                      // Convert QString to const cv::String
    const cv::String path = getVideoFolder().toStdString();
    video = cv::VideoWriter(path + "/" + filename, fcc, fps, frameSize, true);           // Save video with given arguments, coloured = true, greyscale otherwise
}

void LiveStreamCam::updateVideoTimer()
{
    // Create QTime clocks
    QTime videoDuration(0, 0, 0);
    QTime tmp(0, 0, 0);                                             // Temporary QTime to count elapsed time between video timer and the beginning

    videoDuration = tmp.addMSecs(videoTime->elapsed());             // Add seconds to QTime
    ui.chronoLabel->setText(videoDuration.toString("mm:ss"));       // Set text to chronometer label on screen
}

int LiveStreamCam::validCamera(cv::VideoCapture cap)
{
    // Count how many cameras are available on the device
    int numCamera = 0;

    for (int i = 0; i < MAX_CAMERA; i++)
    {
        cap = cv::VideoCapture(i);
        // Test cameras from 0 (main camera) to MAX_CAMERA value
        if (cap.isOpened()) {
            numCamera++;
        }
    }
    qDebug() << numCamera << " cameras available";
    return numCamera;
}

int LiveStreamCam::getVideoCaptureWidth(cv::VideoCapture cap)
{
    return cap.get(cv::CAP_PROP_FRAME_WIDTH);
}

int LiveStreamCam::getVideoCaptureHeight(cv::VideoCapture cap)
{
    return cap.get(cv::CAP_PROP_FRAME_HEIGHT);
}

const QString LiveStreamCam::getCurrentDateAndTime()
{
    // Return current date and time (Year: 4 digits, Month, Day, Hour, Minutes, Seconds: 2 digits)
    return QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
}

const QString LiveStreamCam::getVideoFolder()
{
    // Get User Videos path of the device (compatible Windows, Linux, Mac)
    return QStandardPaths::writableLocation(QStandardPaths::MoviesLocation);
}

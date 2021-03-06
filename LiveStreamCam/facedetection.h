#ifndef FACEDETECTION_H
#define FACEDETECTION_H

#include "opencv2/dnn.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/core/cuda.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <QDebug>


class FaceDetection
{
public:
    FaceDetection();

    std::vector<cv::Rect> detectFace(const cv::Mat &frame);
    void drawDetection(const cv::Mat &frame);

private:
    // Face detection network
    cv::dnn::Net network;

    // Input image size
    const size_t imageWidth;
    const size_t imageHeight;

    // Scale factor and confidence threshold of the network
    const double scaleFactor;
    const float confidenceThreshold;

    // Mean values of the trained network
    const cv::Scalar meanValues;
};

#endif // FACEDETECTION_H

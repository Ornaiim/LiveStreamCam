#include "facedetection.h"

FaceDetection::FaceDetection() :

    imageWidth(300), imageHeight(300), scaleFactor(1.0), confidenceThreshold(0.5), meanValues({104.0, 177.0, 123,0})
{
    // Load network with Caffe files
    network = cv::dnn::readNetFromCaffe(CAFFE_CONFIG_FILE, CAFFE_WEIGHTS_FILE);

    // Network checking
    if (network.empty())
    {
        std::ostringstream msg;
        msg << "ERROR: Failed to load network!";
        throw std::invalid_argument(msg.str());
    }

    // Use GPU if available, using OPENCL
    network.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
    network.setPreferableTarget(cv::dnn::DNN_TARGET_OPENCL);

    // TO DO: build DNN module with CUDA for faster performances
}

std::vector<cv::Rect> FaceDetection::detectFace(const cv::Mat &frame)
{
    cv::Mat frameBGR;
    cvtColor(frame, frameBGR, cv::COLOR_RGBA2BGR);

    // Transform input image into a data BLOB
    // Resize image to the same format and input size of the network
    cv::Mat inputBlob = cv::dnn::blobFromImage(frameBGR, scaleFactor, cv::Size(imageWidth, imageHeight), meanValues, false, false);

    // Process data through the network and store the result into a detection matrix
    network.setInput(inputBlob, "data");
    cv::Mat detection = network.forward("detection_out");
    cv::Mat detectionMatrix(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

    // Create a vector of rectangles, each rectangle represent a face detection
    std::vector<cv::Rect> faces;

    // Iterate every rows of the detection matrix, each row contains one detection
    for(int i = 0; i < detectionMatrix.rows; i++)
    {
        float confidence = detectionMatrix.at<float>(i, 2);

        // Draw a rectangle if confidence value is greater than the threshold
        if(confidence > confidenceThreshold)
        {
            int x1 = static_cast<int>(detectionMatrix.at<float>(i, 3) * frame.cols);
            int y1 = static_cast<int>(detectionMatrix.at<float>(i, 4) * frame.rows);
            int x2 = static_cast<int>(detectionMatrix.at<float>(i, 5) * frame.cols);
            int y2 = static_cast<int>(detectionMatrix.at<float>(i, 6) * frame.rows);

            // Store constructed rectangle into faces vector
            faces.emplace_back(x1, y1, (x2 - x1), (y2 - y1));
        }
    }
    return faces;
}

void FaceDetection::drawDetection(const cv::Mat &frame)
{
    // Detect faces from live image and draw rectangles around each detections
    auto rectangles = detectFace(frame);

    // Colour of the rectangles
    cv::Scalar color(125, 125, 125);    // Grey
    // Thickness of the rectangles
    int frameThickness = 1;             // Thin

    for(const auto & r : rectangles)
    {
        cv::rectangle(frame, r, color, frameThickness);
    }
}

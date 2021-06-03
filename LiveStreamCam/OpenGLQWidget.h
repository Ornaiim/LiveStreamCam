#pragma once

#include <QOpenGLWidget>
#include "opencv2/opencv.hpp"
#include <QDebug>
#include <QImage>
#include <vector>

class OpenGLQWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	OpenGLQWidget(QWidget *parent = Q_NULLPTR);
	~OpenGLQWidget();

	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	void displayImage(cv::Mat image);
	QImage getOGLImage();

private:
	QImage qImage;
	QImage qImageResized;
	cv::Mat imageCaptured;

	GLuint texture;
};

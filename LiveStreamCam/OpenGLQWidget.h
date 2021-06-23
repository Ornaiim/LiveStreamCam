#pragma once

#include <QOpenGLWidget>
#include <QDebug>
#include <QImage>

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

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

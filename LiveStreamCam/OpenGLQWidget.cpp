#include "OpenGLQWidget.h"

OpenGLQWidget::OpenGLQWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
}

OpenGLQWidget::~OpenGLQWidget()
{
	glDeleteTextures(1, &texture);
}

void OpenGLQWidget::initializeGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Create texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void OpenGLQWidget::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void OpenGLQWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (!qImage.isNull())
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0f, this->width(), this->height(), 0.0f, 0.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);

		// Define image as texture and transfer data to the GPU
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, qImage.width(), qImage.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, qImage.bits());
		
		if (glGetError() != GL_NO_ERROR)
		{
			qCritical() << "Error: Failed to load texture";
		}

		// Resize image to QWidget size
		qImageResized = qImage.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

		// Center image on QWidget
		glTranslatef((this->width() - qImageResized.width()) / 2, (this->height() - qImageResized.height()) / 2, 0.0f);
		
		// Draw rectangle with texture
		glBegin(GL_QUADS);

			glTexCoord2i(0, 1); glVertex2i(0, qImageResized.height());
			glTexCoord2i(0, 0); glVertex2i(0, 0);
			glTexCoord2i(1, 0); glVertex2i(qImageResized.width(), 0);
			glTexCoord2i(1, 1); glVertex2i(qImageResized.width(), qImageResized.height());

		glEnd();

		glFlush();
	}
}

void OpenGLQWidget::displayImage(cv::Mat image)
{
	// Convert OpenCV BGR captured image to RGBA type
	cv::cvtColor(image, imageCaptured, cv::COLOR_BGR2RGBA);

	// Convert captured OpenCV image to QImage for QOpenGLWidget processing
	qImage = QImage((uchar*)imageCaptured.data, imageCaptured.cols, imageCaptured.rows, imageCaptured.step, QImage::Format_RGB32);

	// Trigger paintGL()
	this->update();
}

QImage OpenGLQWidget::getOGLImage()
{
	return qImage;
}
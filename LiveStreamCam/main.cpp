#include <iostream>
#include <QtWidgets/QApplication>

#include "livestreamcam.h"
#include "stdafx.h"
#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   LiveStreamCam w;
   w.show();

   return a.exec();

}

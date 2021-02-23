/********************************************************************************
** Form generated from reading UI file 'livestreamcam.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVESTREAMCAM_H
#define UI_LIVESTREAMCAM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "openglqwidget.h"

QT_BEGIN_NAMESPACE

class Ui_LiveStreamCamClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    OpenGLQWidget *openGLWidget;
    QGridLayout *gridLayout_4;
    QLabel *chronoLabel;
    QPushButton *recordButton;
    QPushButton *captureButton;
    QPushButton *nextCameraButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LiveStreamCamClass)
    {
        if (LiveStreamCamClass->objectName().isEmpty())
            LiveStreamCamClass->setObjectName(QString::fromUtf8("LiveStreamCamClass"));
        LiveStreamCamClass->resize(1280, 900);
        QPalette palette;
        QBrush brush(QColor(59, 59, 59, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(76, 76, 76, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        LiveStreamCamClass->setPalette(palette);
        LiveStreamCamClass->setAutoFillBackground(false);
        centralWidget = new QWidget(LiveStreamCamClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        openGLWidget = new OpenGLQWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        verticalLayout_2->addWidget(openGLWidget);


        horizontalLayout_3->addLayout(verticalLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        chronoLabel = new QLabel(centralWidget);
        chronoLabel->setObjectName(QString::fromUtf8("chronoLabel"));
        chronoLabel->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chronoLabel->sizePolicy().hasHeightForWidth());
        chronoLabel->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        chronoLabel->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        chronoLabel->setFont(font);
        chronoLabel->setAutoFillBackground(false);
        chronoLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: white;\n"
"}\n"
""));
        chronoLabel->setScaledContents(true);
        chronoLabel->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(chronoLabel, 2, 2, 1, 1);

        recordButton = new QPushButton(centralWidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(recordButton->sizePolicy().hasHeightForWidth());
        recordButton->setSizePolicy(sizePolicy1);
        recordButton->setToolTipDuration(1000000);
        recordButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgba(255, 255, 255, 0);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/LiveStreamCam/Icons/VideoIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        recordButton->setIcon(icon);
        recordButton->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(recordButton, 2, 3, 1, 1);

        captureButton = new QPushButton(centralWidget);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(captureButton->sizePolicy().hasHeightForWidth());
        captureButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(21);
        captureButton->setFont(font1);
        captureButton->setCursor(QCursor(Qt::ArrowCursor));
        captureButton->setToolTipDuration(1000000);
        captureButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgba(255, 255, 255, 0);\n"
"	color: white;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/LiveStreamCam/Icons/CameraIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        captureButton->setIcon(icon1);
        captureButton->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(captureButton, 1, 3, 1, 1);

        nextCameraButton = new QPushButton(centralWidget);
        nextCameraButton->setObjectName(QString::fromUtf8("nextCameraButton"));
        sizePolicy1.setHeightForWidth(nextCameraButton->sizePolicy().hasHeightForWidth());
        nextCameraButton->setSizePolicy(sizePolicy1);
        QPalette palette2;
        QBrush brush7(QColor(255, 255, 255, 0));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        nextCameraButton->setPalette(palette2);
        nextCameraButton->setToolTipDuration(1000000);
        nextCameraButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: rgba(255, 255, 255, 0);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/LiveStreamCam/Icons/SwitchIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextCameraButton->setIcon(icon2);
        nextCameraButton->setIconSize(QSize(32, 32));

        gridLayout_4->addWidget(nextCameraButton, 0, 3, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_4);

        LiveStreamCamClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(LiveStreamCamClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        LiveStreamCamClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LiveStreamCamClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        LiveStreamCamClass->setStatusBar(statusBar);

        retranslateUi(LiveStreamCamClass);

        QMetaObject::connectSlotsByName(LiveStreamCamClass);
    } // setupUi

    void retranslateUi(QMainWindow *LiveStreamCamClass)
    {
        LiveStreamCamClass->setWindowTitle(QCoreApplication::translate("LiveStreamCamClass", "LiveStreamCam", nullptr));
        chronoLabel->setText(QCoreApplication::translate("LiveStreamCamClass", "00:00", nullptr));
#if QT_CONFIG(tooltip)
        recordButton->setToolTip(QCoreApplication::translate("LiveStreamCamClass", "Record video", nullptr));
#endif // QT_CONFIG(tooltip)
        recordButton->setText(QString());
#if QT_CONFIG(tooltip)
        captureButton->setToolTip(QCoreApplication::translate("LiveStreamCamClass", "Take picture", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        captureButton->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        captureButton->setText(QString());
#if QT_CONFIG(tooltip)
        nextCameraButton->setToolTip(QCoreApplication::translate("LiveStreamCamClass", "Change camera", nullptr));
#endif // QT_CONFIG(tooltip)
        nextCameraButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LiveStreamCamClass: public Ui_LiveStreamCamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVESTREAMCAM_H

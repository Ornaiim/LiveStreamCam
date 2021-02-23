/********************************************************************************
** Form generated from reading UI file 'OpenGLQWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLQWIDGET_H
#define UI_OPENGLQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QOpenGLWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGLQWidget
{
public:

    void setupUi(QOpenGLWidget *OpenGLQWidget)
    {
        if (OpenGLQWidget->objectName().isEmpty())
            OpenGLQWidget->setObjectName(QString::fromUtf8("OpenGLQWidget"));
        OpenGLQWidget->resize(400, 300);

        retranslateUi(OpenGLQWidget);

        QMetaObject::connectSlotsByName(OpenGLQWidget);
    } // setupUi

    void retranslateUi(QOpenGLWidget *OpenGLQWidget)
    {
        OpenGLQWidget->setWindowTitle(QCoreApplication::translate("OpenGLQWidget", "OpenGLQWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenGLQWidget: public Ui_OpenGLQWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLQWIDGET_H

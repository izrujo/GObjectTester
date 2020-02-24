/********************************************************************************
** Form generated from reading UI file 'GObjectTester.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOBJECTTESTER_H
#define UI_GOBJECTTESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_GObjectTesterClass
{
public:

    void setupUi(QFrame *GObjectTesterClass)
    {
        if (GObjectTesterClass->objectName().isEmpty())
            GObjectTesterClass->setObjectName(QString::fromUtf8("GObjectTesterClass"));
        GObjectTesterClass->resize(600, 400);

        retranslateUi(GObjectTesterClass);

        QMetaObject::connectSlotsByName(GObjectTesterClass);
    } // setupUi

    void retranslateUi(QFrame *GObjectTesterClass)
    {
        GObjectTesterClass->setWindowTitle(QApplication::translate("GObjectTesterClass", "GObjectTester", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GObjectTesterClass: public Ui_GObjectTesterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOBJECTTESTER_H

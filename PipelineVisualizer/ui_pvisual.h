/********************************************************************************
** Form generated from reading UI file 'pvisual.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVISUAL_H
#define UI_PVISUAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PVisual
{
public:

    void setupUi(QWidget *PVisual)
    {
        if (PVisual->objectName().isEmpty())
            PVisual->setObjectName(QString::fromUtf8("PVisual"));
        PVisual->resize(400, 300);

        retranslateUi(PVisual);

        QMetaObject::connectSlotsByName(PVisual);
    } // setupUi

    void retranslateUi(QWidget *PVisual)
    {
        PVisual->setWindowTitle(QApplication::translate("PVisual", "PVisual", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PVisual: public Ui_PVisual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVISUAL_H

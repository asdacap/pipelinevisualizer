/********************************************************************************
** Form generated from reading UI file 'variabledoublegeneratorproviderdialog.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIABLEDOUBLEGENERATORPROVIDERDIALOG_H
#define UI_VARIABLEDOUBLEGENERATORPROVIDERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VariableDoubleGeneratorProviderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *VariableDoubleGeneratorProviderDialog)
    {
        if (VariableDoubleGeneratorProviderDialog->objectName().isEmpty())
            VariableDoubleGeneratorProviderDialog->setObjectName(QString::fromUtf8("VariableDoubleGeneratorProviderDialog"));
        VariableDoubleGeneratorProviderDialog->resize(400, 300);
        VariableDoubleGeneratorProviderDialog->setModal(true);
        verticalLayout = new QVBoxLayout(VariableDoubleGeneratorProviderDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(VariableDoubleGeneratorProviderDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(VariableDoubleGeneratorProviderDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(VariableDoubleGeneratorProviderDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(VariableDoubleGeneratorProviderDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setInputMethodHints(Qt::ImhDigitsOnly);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(VariableDoubleGeneratorProviderDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(VariableDoubleGeneratorProviderDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setInputMethodHints(Qt::ImhDigitsOnly);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(VariableDoubleGeneratorProviderDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(VariableDoubleGeneratorProviderDialog);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setInputMethodHints(Qt::ImhDigitsOnly);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label_5 = new QLabel(VariableDoubleGeneratorProviderDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_5 = new QLineEdit(VariableDoubleGeneratorProviderDialog);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setInputMethodHints(Qt::ImhDigitsOnly);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_5);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(VariableDoubleGeneratorProviderDialog);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);

        pushButton_2 = new QPushButton(VariableDoubleGeneratorProviderDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(VariableDoubleGeneratorProviderDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(VariableDoubleGeneratorProviderDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), VariableDoubleGeneratorProviderDialog, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), VariableDoubleGeneratorProviderDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(VariableDoubleGeneratorProviderDialog);
    } // setupUi

    void retranslateUi(QDialog *VariableDoubleGeneratorProviderDialog)
    {
        VariableDoubleGeneratorProviderDialog->setWindowTitle(QApplication::translate("VariableDoubleGeneratorProviderDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "Maximum", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "10000", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "Minimum", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "Increment", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "1", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "Current", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("VariableDoubleGeneratorProviderDialog", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VariableDoubleGeneratorProviderDialog: public Ui_VariableDoubleGeneratorProviderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIABLEDOUBLEGENERATORPROVIDERDIALOG_H

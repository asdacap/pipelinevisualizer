#include "variabledoublegeneratorproviderdialog.h"
#include "ui_variabledoublegeneratorproviderdialog.h"

VariableDoubleGeneratorProviderDialog::VariableDoubleGeneratorProviderDialog(QString name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VariableDoubleGeneratorProviderDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText(name);
}

VariableDoubleGeneratorProviderDialog::~VariableDoubleGeneratorProviderDialog()
{
    delete ui;
}

QString VariableDoubleGeneratorProviderDialog::getName(){
    return ui->lineEdit->text();
}

double VariableDoubleGeneratorProviderDialog::getMaximum(){
    return QVariant(ui->lineEdit_2->text()).toDouble();
}
double VariableDoubleGeneratorProviderDialog::getMinimum(){
    return QVariant(ui->lineEdit_3->text()).toDouble();
}
double VariableDoubleGeneratorProviderDialog::getIncrement(){
    return QVariant(ui->lineEdit_4->text()).toDouble();
}
double VariableDoubleGeneratorProviderDialog::getCurrent(){
    return QVariant(ui->lineEdit_5->text()).toDouble();
}

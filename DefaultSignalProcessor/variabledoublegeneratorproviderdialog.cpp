/*
    Copyright 2010-2011 Muhd Amirul Ashraf <asdacap@gmail.com>

    This file is part of PipelineVisualizer.

    PipelineVisualizer is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation.

    PipelineVisualizer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with PipelineVisualizer.  If not, see <http://www.gnu.org/licenses/>.

*/

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

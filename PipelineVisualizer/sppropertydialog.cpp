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

#include "sppropertydialog.h"
#include "QHBoxLayout"
#include "QPushButton"
#include "QFormLayout"

SPPropertyDialog::SPPropertyDialog(QMap<QString, QString> defaultsetting){
    idata=defaultsetting;
    QVBoxLayout* Vlayout=new QVBoxLayout();
    setLayout(Vlayout);

    QWidget* formwidget=new QWidget(this);
    Vlayout->addWidget(formwidget);
    QFormLayout* formlay=new QFormLayout();
    formwidget->setLayout(formlay);
    QList<QString> keylist=idata.keys();
    int i=0;
    while(i<keylist.count()){
        SPProperty* property=new SPProperty(this,keylist.at(i));
        formlay->addRow(keylist.at(i),property);
        i=i+1;
    }



    QWidget* lowidget=new QWidget(this);
    QHBoxLayout* lowlayout=new QHBoxLayout();
    lowidget->setLayout(lowlayout);
    QPushButton* okButton=new QPushButton("Ok",lowidget);
    lowlayout->addWidget(okButton);
    connect(okButton,SIGNAL(clicked()),SLOT(accept()));
    QPushButton* cancelButton=new QPushButton("Cancel",lowidget);
    lowlayout->addWidget(cancelButton);
    connect(cancelButton,SIGNAL(clicked()),SLOT(reject()));
    Vlayout->addWidget(lowidget);
}

void SPPropertyDialog::setSetting(QString key, QString value){
    idata[key]=value;
}

SPProperty::SPProperty(SPPropertyDialog *dialog, QString key){
    propertyDialog=dialog;
    this->key=key;
    setText(propertyDialog->getSetting()[key]);
    connect(this,SIGNAL(textChanged(QString)),SLOT(whenTextChanged(QString)));
}

void SPProperty::whenTextChanged(QString text){
    propertyDialog->setSetting(key,text);
}

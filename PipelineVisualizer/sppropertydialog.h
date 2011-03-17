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

#ifndef SPPROPERTYDIALOG_H
#define SPPROPERTYDIALOG_H

#include <QDialog>
#include <QMap>
#include <QLineEdit>

class SPPropertyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SPPropertyDialog(QMap<QString,QString> defaultsetting);
    QMap<QString,QString> getSetting(){return idata;}
    void setSetting(QString key,QString value);

private:
    QMap<QString,QString> idata;

signals:

public slots:

};

class SPProperty:public QLineEdit{
    Q_OBJECT
public:
    SPProperty(SPPropertyDialog* dialog,QString key);

    SPPropertyDialog* propertyDialog;
    QString key;

public slots:
    void whenTextChanged(QString text);
};

#endif // SPPROPERTYDIALOG_H

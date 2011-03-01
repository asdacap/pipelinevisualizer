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

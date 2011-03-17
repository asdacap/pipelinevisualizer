#ifndef VARIABLEDOUBLEGENERATORPROVIDERDIALOG_H
#define VARIABLEDOUBLEGENERATORPROVIDERDIALOG_H

#include <QDialog>

namespace Ui {
    class VariableDoubleGeneratorProviderDialog;
}

class VariableDoubleGeneratorProviderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VariableDoubleGeneratorProviderDialog(QString name,QWidget *parent = 0);
    ~VariableDoubleGeneratorProviderDialog();
    double getMaximum();
    double getMinimum();
    double getIncrement();
    double getCurrent();
    QString getName();

private:
    Ui::VariableDoubleGeneratorProviderDialog *ui;
};

#endif // VARIABLEDOUBLEGENERATORPROVIDERDIALOG_H

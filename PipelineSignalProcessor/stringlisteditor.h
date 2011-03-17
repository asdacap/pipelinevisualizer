#ifndef STRINGLISTEDITOR_H
#define STRINGLISTEDITOR_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
    class StringlistEditor;
}

class StringlistEditor : public QDialog
{
    Q_OBJECT

public:
    explicit StringlistEditor(QList<QString> thelist,QWidget *parent = 0);
    QList<QString> currentList();
    ~StringlistEditor();

public slots:
    void addButton();
    void removeButton();

private:
    Ui::StringlistEditor *ui;
    QStringListModel* themodel;
};

#endif // STRINGLISTEDITOR_H

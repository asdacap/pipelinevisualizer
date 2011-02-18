#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include "simplelinegraph.h"
#include "doublegenerator.h"
#include "booleangenerator.h"
#include "QComboBox"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void InitializeGraph();
    void InitializeInterfacePage();

    void registerVariable(DoubleGenerator* var,double min,double mac,double cur,double increm,QString name);
    void registerVariable(BooleanGenerator* var,QString name,bool editable=true);
    void registerVariable(DoubleGenerator *var, QString name);
    void addGroup(QString gname);
    void addGraph(GraphAbstraction* ga);

private:
    QTabWidget* cwid;
    int* gcounter;

    QTabWidget* rightwidOut;

    QWidget* rightwid;
    QVBoxLayout* ilayout;
    Ui::MainWindow *ui;

    SimpleLineGraph* grapha;
    SimpleLineGraph* graphb;
    QComboBox* cboxa;
    QComboBox* cboxb;

    QList<GraphAbstraction*> graphList;

public slots:
    void cboxAchanged(QString box);
    void cboxBchanged(QString box);

};

#endif // MAINWINDOW_H

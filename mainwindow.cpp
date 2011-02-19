#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "constSetting.h"
#include "util.h"
#include "qwt_slider.h"
#include "doublelabel.h"
#include "booleanlabel.h"
#include "QGroupBox"
#include "QCheckBox"
#include "QInputDialog"
#include "variabledoublegeneratorprovider.h"
#include "signalscaler.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(0,0,800,600);

    InitializeGraph();

    setWindowState(Qt::WindowMaximized);
}

void MainWindow::InitializeGraph(){


    cwid=new QTabWidget(this);
    setCentralWidget(cwid);
    InitializeInterfacePage();
    InitializePVisual();

}

void MainWindow::InitializePVisual(){
    PVisual* pv=new PVisual();
    pv->addProvider(new GraphAbstractionProvider(this,pv));
    pv->addProvider(new VariableDoubleGeneratorProvider(this,pv));
    pv->addProvider(new SignalScalerProvider(pv));
    cwid->addTab(pv,"PipeLineGraph");
}

void MainWindow::addGroup(QString gname){
    QWidget* pagewidget=new QWidget();
    QVBoxLayout* olayout=new QVBoxLayout();
    pagewidget->setLayout(olayout);
    rightwid=new QGroupBox(gname,pagewidget);
    olayout->addWidget(rightwid);
    ilayout=new QVBoxLayout();
    rightwid->setLayout(ilayout);
    rightwidOut->addTab(pagewidget,gname);

    QWidget* stretcher=new QWidget(pagewidget);
    olayout->addWidget(stretcher,1);

}

void MainWindow::InitializeInterfacePage(){
    QWidget* pageWidget=new QWidget();

    QGridLayout* thelayout=new QGridLayout();
    pageWidget->setLayout(thelayout);

    rightwidOut=new QTabWidget(pageWidget);
    thelayout->addWidget(rightwidOut,0,1,4,1);
    rightwidOut->setMinimumWidth(500);
    addGroup("Common");

    grapha=new SimpleLineGraph(pageWidget);
    thelayout->addWidget(grapha,1,0,1,1);

    cboxa=new QComboBox(pageWidget);
    thelayout->addWidget(cboxa,0,0,1,1);
    QObject::connect(cboxa,SIGNAL(currentIndexChanged(QString)),this,SLOT(cboxAchanged(QString)));

    graphb=new SimpleLineGraph(pageWidget);
    thelayout->addWidget(graphb,3,0,1,1);

    cboxb=new QComboBox(pageWidget);
    thelayout->addWidget(cboxb,2,0,1,1);
    QObject::connect(cboxb,SIGNAL(currentIndexChanged(QString)),this,SLOT(cboxBchanged(QString)));

    cwid->addTab(pageWidget,"Interface");
}

void MainWindow::addGraph(GraphAbstraction *ga){
    graphList.append(ga);
    cboxa->insertItem(0,ga->getName());
    cboxb->insertItem(0,ga->getName());
}

void MainWindow::cboxAchanged(QString box){
    int i=0;
    while(i<graphList.count()){
        if(graphList.at(i)->getName()==box){
            grapha->setGraphData(graphList.at(i));
        }
        i=i+1;
    }
}

void MainWindow::cboxBchanged(QString box){
    int i=0;
    while(i<graphList.count()){
        if(graphList.at(i)->getName()==box){
            graphb->setGraphData(graphList.at(i));
        }
        i=i+1;
    }
}

void MainWindow::registerVariable(DoubleGenerator *var, double min, double max, double cur, double increm, QString name){
    QLabel* namelabel=new QLabel(rightwid);
    namelabel->setText(name);
    ilayout->addWidget(namelabel);
    QwtSlider* propslider=new QwtSlider(rightwid,Qt::Horizontal,QwtSlider::TopScale,QwtSlider::BgTrough);
    ilayout->addWidget(propslider);
    propslider->setRange(min,max,increm,1);
    propslider->setThumbWidth(10);
    propslider->setToolTip(name);
    QObject::connect(propslider,SIGNAL(valueChanged(double)),var,SLOT(setValue(double)));
    propslider->setValue(cur);
}

void MainWindow::registerVariable(BooleanGenerator *var, QString name,bool editable){
    if(editable){
    QCheckBox* cbox=new QCheckBox(name,rightwid);
    cbox->setChecked(var->getValue());
    ilayout->addWidget(cbox);
    QObject::connect(cbox,SIGNAL(toggled(bool)),var,SLOT(setValue(bool)));
    }else{
    BooleanLabel* newlabel=new BooleanLabel(var,name);
    ilayout->addWidget(newlabel);
    }
}

void MainWindow::registerVariable(DoubleGenerator *var, QString name){
    DoubleLabel* newlabel=new DoubleLabel(var,name);
    ilayout->addWidget(newlabel);
}


MainWindow::~MainWindow()
{
    delete ui;
}

GraphAbstractionProvider::GraphAbstractionProvider(MainWindow *mw,PVisual* pvs){
    cmw=mw;
    pv=pvs;
}

QString GraphAbstractionProvider::getName(){
    return "Graph";
}

ProcessGraphics* GraphAbstractionProvider::newInstance(){
    bool ok;
    QString cand=nameCandidate();
    QString text = QInputDialog::getText(0,QString("Name the new processor"),
                                              QString("Processor name:"), QLineEdit::Normal,
                                              cand, &ok);
     if (ok && !text.isEmpty()){
         GraphAbstraction* sf=new GraphAbstraction(text);
         cmw->addGraph(sf);
         ProcessGraphics* pg=new ProcessGraphics(sf,text,2,1,0,0,0,0,pv);
         return pg;
     }else{
         std::cout<<"Fail to get processor name"<<std::endl;
         return 0;
     }
}


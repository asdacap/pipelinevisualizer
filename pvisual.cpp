#include "pvisual.h"
#include "ui_pvisual.h"
#include "pipefeed.h"
#include "pipeprovider.h"
#include "processgraphics.h"
#include "signalprocessor.h"
#include "QComboBox"
#include "QPushButton"
#include "soundfeeder.h"
#include "soundsink.h"

PVisual::PVisual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PVisual)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    QGraphicsView* view=new QGraphicsView(this);
    view->setScene(scene);

    QWidget* topbar=new QWidget(this);
    QHBoxLayout* toplayout=new QHBoxLayout();
    topbar->setLayout(toplayout);
    QComboBox* selectbox=new QComboBox(topbar);
    cbox=selectbox;
    QPushButton* addbutton=new QPushButton(topbar);
    addbutton->setText("Add");
    addbutton->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    selectbox->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Minimum);
    toplayout->addWidget(selectbox);
    toplayout->addWidget(addbutton);
    QObject::connect(addbutton,SIGNAL(clicked()),this,SLOT(addButton()));

    QBoxLayout* thislayout=new QBoxLayout(QBoxLayout::BottomToTop,this);
    this->setLayout(thislayout);
    thislayout->addWidget(topbar);
    thislayout->addWidget(view);

    sigcol=new TargetCollection();
    doubcol=new TargetCollection();
    boolcol=new TargetCollection();

    InitializeProvider();

}

void PVisual::InitializeProvider(){
    addProvider(new SoundSinkProvider(this));
    addProvider(new SoundFeederProvider(this));
}

void PVisual::addProvider(PipeProcessGraphicsProvider *prov){
    provider_list.append(prov);
    cbox->addItem(prov->getName());
}

void PVisual::addPG(ProcessGraphics* newpg){
    if(isExistPGName(newpg->getName()))return ;
    scene->addItem(newpg);
    pgraphics_list.append(newpg);
}

bool PVisual::isExistPGName(QString name){
    int i=0;
    while(i<pgraphics_list.count()){
        if(pgraphics_list.at(i)->getName()==name)return true;
        i=i+1;
    }
    return false;
}

void PVisual::addButton(){
    QString name=cbox->currentText();
    if(name.isEmpty()){
        return;
    }
    int i=0;
    while(i<provider_list.count()){
        if(provider_list.at(i)->getName()==name){
            ProcessGraphics* newpg=provider_list.at(i)->newInstance();
            if(newpg==0)return;
            addPG(newpg);
        }
        i=i+1;
    }
}

PVisual::~PVisual()
{
    delete ui;
}

TargetCollection* PVisual::getSignalTargetCollection(){
    return sigcol;
}


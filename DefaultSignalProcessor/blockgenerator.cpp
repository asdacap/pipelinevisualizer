#include "blockgenerator.h"
#include "widgetedprocessgraphics.h"

BlockGenerator::BlockGenerator(double dat, int length){
    val=dat;
    leng=length;
    setOutputNum(1);
    enableHelper(1,0,0);
    constantmode=true;
}

BlockGenerator::BlockGenerator(){

    setOutputNum(1);
    enableHelper(1,2,0);
    constantmode=false;
}

void BlockGenerator::feedData(QVector<QVector<double> > dat,
                              QVector<double> doubdat,
                              QVector<bool> booldat,
                              int counter){
    double value;
    int length;
    if(constantmode){
        value=val;
        length=leng;
    }else{
        length=doubdat[0];
        value=doubdat[1];
    }
    output_collection.at(0)->feedData(QVector<double>(length,value),counter);
}

VariableBlockGenerator::VariableBlockGenerator(PVisual *pv){
    PV=pv;
}

ProcessGraphics* VariableBlockGenerator::newInstance(QString name){
    BlockGenerator* bg=new BlockGenerator();
    return new WidgetedProcessGraphics(bg,name,1,1,2,0,0,0,PV,this);
}

ConstantBlockGenerator::ConstantBlockGenerator(PVisual *pv){
    PV=pv;
}

QMap<QString,QString> ConstantBlockGenerator::defaultSetting(){
    QMap<QString,QString> setting;
    setting["Name"]=nameCandidate();
    setting["Length"]="1024";
    setting["Value"]="0";
    return setting;
}

QMap<QString,QString> ConstantBlockGenerator::getSettings(ProcessGraphics *pg){
    QMap<QString,QString> setting;
    setting["Name"]=pg->getName();
    BlockGenerator* bg=(BlockGenerator*)pg->getProcessor();
    setting["Length"]=QVariant(bg->getLength()).toString();
    setting["Value"]=QVariant(bg->getValue()).toString();
    return setting;
}

ProcessGraphics* ConstantBlockGenerator::newInstance(QMap<QString, QString> setting){
    int length=QVariant(setting["Length"]).toInt();
    double value=QVariant(setting["Value"]).toDouble();
    BlockGenerator* bg=new BlockGenerator(value,length);
    return new WidgetedProcessGraphics(bg,setting["Name"],1,1,0,0,0,0,PV,this);
}

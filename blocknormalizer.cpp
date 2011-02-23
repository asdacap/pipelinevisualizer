#include "blocknormalizer.h"

BlockNormalizer::BlockNormalizer(int i)
{
    currentCount=0;
    division=i;
    setOutputNum(1);
}

void BlockNormalizer::feedData(QVector<double> dat,int counter,int){
    if(currentCount==division){
        output_collection.at(0)->feedData(dat,counter);
        currentCount=0;
    }else{
        currentCount=currentCount+1;
    }
}

QMap<QString,QString> BlockNormalizerProvider::defaultSetting(){
    QMap<QString,QString> setting;
    setting["Name"]=nameCandidate();
    setting["AntiResolution"]="0";
    return setting;
}

QMap<QString,QString> BlockNormalizerProvider::getSettings(ProcessGraphics *pg){
    QMap<QString,QString> setting;
    setting["Name"]=pg->getName();
    BlockNormalizer* bn=(BlockNormalizer*)pg->getProcessor();
    setting["AntiResolution"]=QVariant(bn->division).toString();
    return setting;
}

ProcessGraphics* BlockNormalizerProvider::newInstance(QMap<QString, QString> setting){
    QString name=setting["Name"];
    int resolution=QVariant(setting["AntiResolution"]).toInt();
    BlockNormalizer* bn=new BlockNormalizer(resolution);
    return new WidgetedProcessGraphics(bn,name,1,1,0,0,0,0,PV,this);
}

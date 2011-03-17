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

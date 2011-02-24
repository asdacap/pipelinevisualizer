#include "conditionalinputsignalpipe.h"
#include "widgetedprocessgraphics.h"

ConditionalInputSignalPipe::ConditionalInputSignalPipe()
{
    setOutputNum(1);
    tempbol=false;

    dat1set=false;
    dat2set=false;
    bolset=false;
}

void ConditionalInputSignalPipe::feedBoolData(bool dat, int counter, int channel){
    if(currentCounter==counter){
        tempbol=dat;
        if(tempbol){
            if(!dat1set)return;
            output_collection.at(0)->feedData(datchan1,counter);
        }else{
            if(!dat2set)return;
            output_collection.at(0)->feedData(datchan2,counter);
        }
        dat1set=false;
        dat2set=false;
        bolset=false;
    }else{
        currentCounter=counter;
        tempbol=dat;
        bolset=true;
    }
}

void ConditionalInputSignalPipe::feedData(QVector<double> dat, int counter, int channel){
    if(currentCounter==counter){
        if(!bolset){
            if(channel==0){
                datchan1=dat;
                dat1set=true;
            }else{
                datchan2=dat;
                dat2set=true;
            }
        }else{
            if(tempbol){
                if(channel==0){
                    output_collection.at(0)->feedData(dat,counter);
                }
            }else{
                if(channel==1){
                    output_collection.at(0)->feedData(dat,counter);
                }
            }
        }
    }else{
        currentCounter=counter;
        if(channel==0){
            datchan1=dat;
            dat1set=true;
        }else{
            datchan2=dat;
            dat2set=true;
        }
    }
}

void ConditionalInputSignalPipe::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat1=dat.at(0);
    QVector<double> dat2=dat.at(1);
    bool condition=booldat.at(0);
    if(condition){
        output_collection.at(0)->feedData(dat1,counter);
    }else{
        output_collection.at(0)->feedData(dat2,counter);
    }
}

QString ConditionalInputSignalPipeProvider::getName(){
    return "ConditionalInputSignalPipe";
}

ConditionalInputSignalPipeProvider::ConditionalInputSignalPipeProvider(PVisual *pv){
    PV=pv;
}

ProcessGraphics* ConditionalInputSignalPipeProvider::newInstance(QString name)
{
    ConditionalInputSignalPipe* sf=new ConditionalInputSignalPipe();
    return new WidgetedProcessGraphics(sf,name,2,1,0,0,1,0,PV,this);
}

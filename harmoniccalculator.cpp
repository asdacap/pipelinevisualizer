#include "harmoniccalculator.h"
#include "constSetting.h"

HarmonicCalculator::HarmonicCalculator()
{

    interval=herzToFreq(1);
    setOutputNum(1);
    enableHelper(1,2,0);
}

double HarmonicCalculator::sumIt(DoubleIndexVector* ind,double index){

    double startcalc=herzToFreq(50);
    double endcalc=herzToFreq(5000);

    int maxcalc=7;

    double i=0;
    double cur=0;
    int counter=0;
    int count=ind->data.count();
    while(i<count && counter<maxcalc){
        if(i>startcalc && i<endcalc){
            cur=cur+ind->at(i);
            counter=counter+1;
        }
        i=i+index;
    }
    return cur/counter;
}

void HarmonicCalculator::feedData(QVector<QVector<double> > datat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat=datat.at(0);
    double harmmin=doubdat.at(0);
    double harmmax=doubdat.at(1);

    DoubleIndexVector iv(dat);
    QVector<double> ret;

    double i=0;
    while(i<harmmax){
        if(i>harmmin&&i<harmmax){
            ret.append(sumIt(&iv,i));
        }else{
            ret.append(0);
        }
        i=i+interval;
    }

    output_collection.at(0)->feedData(ret,counter);
}


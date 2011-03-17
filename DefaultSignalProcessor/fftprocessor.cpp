#include "fftprocessor.h"
#include "fftw3.h"

FFTProcessor::FFTProcessor()
{
    setOutputNum(2);
}

void FFTProcessor::feedData(QVector<double> fed, int counter, int channel){
    fftw_complex* res;
    double* source;
    int length;
    source=fed.data();
    length=(fed.count()/2)+1;
    res=new fftw_complex[length];
    fftw_plan p;
    p=fftw_plan_dft_r2c_1d(fed.count(),source,res,FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);

    QVector<double> result(length);
    int i=0;
    while(i<length){
        result.replace(i,res[i][0]);
        i=i+1;
    }
    output_collection.at(0)->feedData(result,counter);

    i=0;
    while(i<length){
        result.replace(i,res[i][1]);
        i=i+1;
    }
    output_collection.at(1)->feedData(result,counter);


    //std::cout<<source[0]<<std::endl;
    delete []res;
}

ProcessGraphics* FFTProcessorProvider::newInstance(QString text){
    FFTProcessor* ffp=new FFTProcessor();
    return new WidgetedProcessGraphics(ffp,text,1,2,0,0,0,0,PV,this);
}

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

#include "inversefftprocessor.h"
#include <iostream>
#include "fftw3.h"

InverseFFtProcessor::InverseFFtProcessor()
{
    setOutputNum(1);
    enableHelper(2,0,0);
}

void InverseFFtProcessor::feedData(QVector<QVector<double> > dat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> realdata=dat.at(0);
    QVector<double> imaginarydat=dat.at(1);
    QVector<double>* realdat=&realdata;
    QVector<double>* imagdat=&imaginarydat;
    if(realdat->count()==imagdat->count()){
        fftw_complex* car=new fftw_complex[realdat->count()];
        int i=0;
        while(i<realdat->count()){
            car[i][0]=realdat->at(i);
            car[i][1]=imagdat->at(i);
            i=i+1;
        }
        int orlength=(realdat->count()-1)*2;
        double* resbuf=new double[orlength];
        fftw_plan theplan=fftw_plan_dft_c2r_1d(orlength,
                                               car, resbuf,
                                               FFTW_MEASURE);
        fftw_execute(theplan);
        QVector<double> resvec(orlength);
        i=0;
        while(i<orlength){
            resvec.replace(i,resbuf[i]/orlength);
            i=i+1;
        }
        output_collection.at(0)->feedData(resvec,counter);
        delete []car;
        delete []resbuf;

    }else{
        std::cout<<"Incorrect length in inverse fft feedme"<<std::endl;
        std::cout<<"imaginary count "<<imagdat->count()<<std::endl;
        std::cout<<"real count "<<realdat->count()<<std::endl;
    }
}

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

#include "selectivesignalelimination.h"

SelectiveSignalElimination::SelectiveSignalElimination()
{
    setOutputNum(1);
    enableHelper(1,2,0);
}

void SelectiveSignalElimination::feedData(QVector<QVector<double> > data, QVector<double> doubdat, QVector<bool> booldat, int counter){
    QVector<double> dat=data.at(0);

    QVector<double> res(dat.count());
    int i=0;
    int ofs=doubdat.at(0);
    int len=doubdat.at(1);

    //std::cout<<"offset "<<ofs<<std::endl;
    //std::cout<<"len "<<len<<std::endl;

    while(i<res.count()){

        if(i <= ofs){
            res.replace(i,dat.at(i));
        }else
            if(i > (ofs+len)){
                res.replace(i,dat.at(i));
            }else{
                res.replace(i,0);
            }

        i=i+1;
    }

    output_collection.at(0)->feedData(res,counter);
}

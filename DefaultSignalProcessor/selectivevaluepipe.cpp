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

#include "selectivevaluepipe.h"

SelectiveValuePipe::SelectiveValuePipe()
{
    setOutputNum(1);
    enableHelper(1,2,1);
}

void SelectiveValuePipe::feedData(QVector<QVector<double> > sdat, QVector<double> doubdat, QVector<bool> booldat, int counter){
    bool reducesize=booldat.at(0);
    int offset=doubdat.at(0);
    int length=doubdat.at(1);
    QVector<double> dat=sdat.at(0);
    if(!reducesize){
            QVector<double> res(dat.count());
            int i=0;
            int ofs=(int)offset;
            int len=(int)length;

            //std::cout<<"offset "<<ofs<<std::endl;
            //std::cout<<"len "<<len<<std::endl;

            while(i<res.count()){

                if(i <= ofs){
                    res.replace(i,0);
                }else
                    if(i > (ofs+len)){
                    res.replace(i,0);
                }else{
                    res.replace(i,dat.at(i));
                }

                i=i+1;
            }
            output_collection.at(0)->feedData(res,counter);
        }else{
            int i=0;
            int ofs=(int)offset;
            int len=(int)length;
            QVector<double> res(len);
            //std::cout<<"offset "<<ofs<<std::endl;
            //std::cout<<"len "<<len<<std::endl;

            while(i<dat.count()){

                if(i <= ofs){
                }else
                if(i > (ofs+len)){
                }else{
                    res.replace(i-ofs-1,dat.at(i));
                }

                i=i+1;
            }

            output_collection.at(0)->feedData(res,counter);
        }
}

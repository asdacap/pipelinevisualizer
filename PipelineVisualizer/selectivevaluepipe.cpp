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

#include "widgetedprocessgraphics.h"

SelectiveValuePipeProvider::SelectiveValuePipeProvider(PVisual *pv){
    PV=pv;
}

ProcessGraphics* SelectiveValuePipeProvider::newInstance(QString name){
    SelectiveValuePipe* sp=new SelectiveValuePipe();
    return new WidgetedProcessGraphics(sp,name,1,1,2,0,1,0,PV,this);
}

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

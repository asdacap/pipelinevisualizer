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

#include "simplelinegraph.h"
#include <QPainter>
#include <iostream>
#include <QGridLayout>
#include "qwt/qwt_plot_canvas.h"
#include "qwt/qwt_wheel.h"
#include "qwt/qwt_plot_panner.h"
#include "qwt/qwt_plot_magnifier.h"
#include <QAction>
#include "qwt/qwt_scale_div.h"
#include "qwt/qwt_plot_zoomer.h"

SimpleLineGraph::SimpleLineGraph(QWidget *parent) :
    QWidget(parent)
{
    gdata=new GraphAbstraction("Empty");

    thetimer=new QTimer();
    thetimer->setSingleShot(false);
    thetimer->setInterval(100);
    QObject::connect(thetimer,SIGNAL(timeout()),this,SLOT(timerElapsed()));
    thetimer->start();

    QGridLayout* lay=new QGridLayout(this);
    setLayout(lay);

    ploter=new QwtPlot(this);
    lay->addWidget(ploter,0,0,6,2);

    cCurve=new QwtPlotCurve();
    cCurve->attach(ploter);

    ploter->setAutoReplot(true);
    //ploter->canvas()->setPaintAttribute(QwtPlotCanvas::PaintCached, false);

    QwtPlotPanner* panner=new QwtPlotPanner(ploter->canvas());
   // QwtPlotZoomer* zomer=new QwtPlotZoomer(ploter->canvas());
    QwtPlotMagnifier* magni=new QwtPlotMagnifier(ploter->canvas());

    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QAction* ract=new QAction("R",this);
    QObject::connect(ract,SIGNAL(triggered(bool)),this,SLOT(resetTrigger(bool)));

    QToolButton* rb=new QToolButton(this);
    rb->setDefaultAction(ract);
    lay->addWidget(rb,2,3,1,1);

    QAction* act1=new QAction("^",this);
    QObject::connect(act1,SIGNAL(triggered(bool)),this,SLOT(resetTrigger1(bool)));

    rb=new QToolButton(this);
    rb->setDefaultAction(act1);
    lay->addWidget(rb,0,3,1,1);

    act1=new QAction("^",this);
    QObject::connect(act1,SIGNAL(triggered(bool)),this,SLOT(resetTrigger2(bool)));

    rb=new QToolButton(this);
    rb->setDefaultAction(act1);
    lay->addWidget(rb,1,3,1,1);

    act1=new QAction("v",this);
    QObject::connect(act1,SIGNAL(triggered(bool)),this,SLOT(resetTrigger3(bool)));

    rb=new QToolButton(this);
    rb->setDefaultAction(act1);
    lay->addWidget(rb,3,3,1,1);

    act1=new QAction("v",this);
    QObject::connect(act1,SIGNAL(triggered(bool)),this,SLOT(resetTrigger4(bool)));

    rb=new QToolButton(this);
    rb->setDefaultAction(act1);
    lay->addWidget(rb,4,3,1,1);

    enab=true;

    act1=new QAction("E",this);
    QObject::connect(act1,SIGNAL(triggered(bool)),this,SLOT(toggleEnab(bool)));

    rb=new QToolButton(this);
    rb->setDefaultAction(act1);
    lay->addWidget(rb,5,3,1,1);
}


void SimpleLineGraph::setGraphData(GraphAbstraction *ga){
    gdata=ga;
}

void SimpleLineGraph::setInterval(int interval){
    thetimer->setInterval(interval);
}

void SimpleLineGraph::timerElapsed(){
    if(!enab)return;

    gdata->lock();
    QwtCPointerData thedata(gdata->xdata.data(),gdata->ydata.data(),gdata->xdata.size()>gdata->ydata.size()?gdata->ydata.size():gdata->xdata.size());
    cCurve->setData(&thedata);
    gdata->unlock();
    ploter->repaint();
}

QwtPlot* SimpleLineGraph::getPlot(){
    return ploter;
}

void SimpleLineGraph::resetTrigger(bool act){
    std::cout<<"reset"<<std::endl;
    ploter->setAxisAutoScale(0);
    ploter->setAxisAutoScale(2);
}

void SimpleLineGraph::resetTrigger1(bool act){
    QwtScaleDiv* divis=ploter->axisScaleDiv(0);
    double min=divis->interval().minValue();
    double max=divis->interval().maxValue();
    double mid=(min+max)/2;
    double dmin=min-mid;
    double dmax=max-mid;
    double multi=0.5;
    double nmax=mid+(dmax*multi);
    double nmin=mid+(dmin*multi);
    ploter->setAxisScale(0,nmin,nmax);
}

void SimpleLineGraph::resetTrigger2(bool act){
    QwtScaleDiv* divis=ploter->axisScaleDiv(0);
    double min=divis->interval().minValue();
    double max=divis->interval().maxValue();
    double mid=(min+max)/2;
    double dmin=min-mid;
    double dmax=max-mid;
    double multi=0.9;
    double nmax=mid+(dmax*multi);
    double nmin=mid+(dmin*multi);
    ploter->setAxisScale(0,nmin,nmax);
}

void SimpleLineGraph::resetTrigger3(bool act){
    QwtScaleDiv* divis=ploter->axisScaleDiv(0);
    double min=divis->interval().minValue();
    double max=divis->interval().maxValue();
    double mid=(min+max)/2;
    double dmin=min-mid;
    double dmax=max-mid;
    double multi=1.1;
    double nmax=mid+(dmax*multi);
    double nmin=mid+(dmin*multi);
    ploter->setAxisScale(0,nmin,nmax);
}

void SimpleLineGraph::resetTrigger4(bool act){
    QwtScaleDiv* divis=ploter->axisScaleDiv(0);
    double min=divis->interval().minValue();
    double max=divis->interval().maxValue();
    double mid=(min+max)/2;
    double dmin=min-mid;
    double dmax=max-mid;
    double multi=2;
    double nmax=mid+(dmax*multi);
    double nmin=mid+(dmin*multi);
    ploter->setAxisScale(0,nmin,nmax);
}

void SimpleLineGraph::toggleEnab(bool act){
    enab=!enab;
}


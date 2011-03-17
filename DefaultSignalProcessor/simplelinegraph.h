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

#ifndef SIMPLELINEGRAPH_H
#define SIMPLELINEGRAPH_H

#include <QWidget>
#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include <QTimer>
#include <QToolButton>
#include "counterkeeper.h"
#include "graphabstraction.h"

class SimpleLineGraph : public QWidget
{
    Q_OBJECT
public:
    explicit SimpleLineGraph(QWidget *parent = 0);
    void setInterval(int interval);
    void setGraphData(GraphAbstraction* ga);
    QwtPlot* getPlot();

private:
    QTimer* thetimer;
    QVector<double> xdata;
    QwtPlotCurve* cCurve;
    QwtPlot* ploter;
    bool enab;
    QVector<double> curdat;
    GraphAbstraction* gdata;

signals:

public slots:
        void timerElapsed();
        void resetTrigger(bool act);
        void resetTrigger1(bool act);
        void resetTrigger2(bool act);
        void resetTrigger3(bool act);
        void resetTrigger4(bool act);
        void toggleEnab(bool act);
};

#endif // SIMPLELINEGRAPH_H

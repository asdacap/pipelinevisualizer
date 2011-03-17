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

#include "constSetting.h"

int SAMPLING_FREQ=22050;
int RAWFFTBLOCK=2205;
int ZERO_ADD=0;
int EXTRA_RESOLUTION=0;

int HARMONIC_MIN=20;
int HARMONIC_MAX=1000;

double freqSize(){
    return RAWFFTBLOCK+ZERO_ADD;
}

double herzToFreq(double herz){
    double ratio=herz/(SAMPLING_FREQ);
    double temp= ratio*freqSize();
    return temp;
}

double freqToHerz(double freq){
    double ratio=freq/(freqSize());
    return ratio*SAMPLING_FREQ;
}

void InitializeConfig(){

}

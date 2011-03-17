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

#ifndef CONSTSETTING_H
#define CONSTSETTING_H

extern int SAMPLING_FREQ;
extern int RAWFFTBLOCK;
extern int ZERO_ADD;
extern int EXTRA_RESOLUTION;

extern int HARMONIC_MIN;
extern int HARMONIC_MAX;


void InitializeConfig();

double freqSize();

double herzToFreq(double herz);

double freqToHerz(double freq);

#endif // CONSTSETTING_H

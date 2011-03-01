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

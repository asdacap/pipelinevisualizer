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

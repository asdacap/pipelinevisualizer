#include "soundplugin.h"
#include "soundfeeder.h"
#include "soundsink.h"

SoundPlugin::SoundPlugin(){

}

QList<PipeProcessGraphicsProvider*> SoundPlugin::getProviders(PVisual *pv){
    QList<PipeProcessGraphicsProvider*> ret;
    ret.append(new SoundSinkProvider(pv));
    ret.append(new SoundFeederProvider(pv));
    return ret;
}

Q_EXPORT_PLUGIN2(SoundPlugin,SoundPlugin)

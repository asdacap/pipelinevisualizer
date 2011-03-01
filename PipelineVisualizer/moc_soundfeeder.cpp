/****************************************************************************
** Meta object code from reading C++ file 'soundfeeder.h'
**
** Created: Tue Mar 1 14:52:32 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "soundfeeder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundfeeder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SoundFeeder[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SoundFeeder[] = {
    "SoundFeeder\0\0s\0auStateChanged(QAudio::State)\0"
};

const QMetaObject SoundFeeder::staticMetaObject = {
    { &QIODevice::staticMetaObject, qt_meta_stringdata_SoundFeeder,
      qt_meta_data_SoundFeeder, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SoundFeeder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SoundFeeder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SoundFeeder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SoundFeeder))
        return static_cast<void*>(const_cast< SoundFeeder*>(this));
    if (!strcmp(_clname, "SignalProcessor"))
        return static_cast< SignalProcessor*>(const_cast< SoundFeeder*>(this));
    return QIODevice::qt_metacast(_clname);
}

int SoundFeeder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: auStateChanged((*reinterpret_cast< QAudio::State(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

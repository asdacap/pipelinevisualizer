/****************************************************************************
** Meta object code from reading C++ file 'simplelinegraph.h'
**
** Created: Tue Mar 1 14:52:35 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "simplelinegraph.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simplelinegraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimpleLineGraph[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      36,   32,   16,   16, 0x0a,
      55,   32,   16,   16, 0x0a,
      75,   32,   16,   16, 0x0a,
      95,   32,   16,   16, 0x0a,
     115,   32,   16,   16, 0x0a,
     135,   32,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SimpleLineGraph[] = {
    "SimpleLineGraph\0\0timerElapsed()\0act\0"
    "resetTrigger(bool)\0resetTrigger1(bool)\0"
    "resetTrigger2(bool)\0resetTrigger3(bool)\0"
    "resetTrigger4(bool)\0toggleEnab(bool)\0"
};

const QMetaObject SimpleLineGraph::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SimpleLineGraph,
      qt_meta_data_SimpleLineGraph, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimpleLineGraph::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimpleLineGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimpleLineGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleLineGraph))
        return static_cast<void*>(const_cast< SimpleLineGraph*>(this));
    return QWidget::qt_metacast(_clname);
}

int SimpleLineGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timerElapsed(); break;
        case 1: resetTrigger((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: resetTrigger1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: resetTrigger2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: resetTrigger3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: resetTrigger4((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: toggleEnab((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

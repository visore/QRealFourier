/****************************************************************************
** Meta object code from reading C++ file 'vifouriertransformer.h'
**
** Created: Sun May 20 05:52:35 2012
**      by: The Qt Meta Object Compiler version 64 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../headers/vifouriertransformer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vifouriertransformer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 64
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViFourierTransformer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ViFourierTransformer[] = {
    "ViFourierTransformer\0\0finished()\0"
};

void ViFourierTransformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViFourierTransformer *_t = static_cast<ViFourierTransformer *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViFourierTransformer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViFourierTransformer::finished)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ViFourierTransformer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViFourierTransformer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ViFourierTransformer,
      qt_meta_data_ViFourierTransformer, &staticMetaObjectExtraData }
};

const QMetaObject *ViFourierTransformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViFourierTransformer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViFourierTransformer))
        return static_cast<void*>(const_cast< ViFourierTransformer*>(this));
    return QObject::qt_metacast(_clname);
}

int ViFourierTransformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ViFourierTransformer::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

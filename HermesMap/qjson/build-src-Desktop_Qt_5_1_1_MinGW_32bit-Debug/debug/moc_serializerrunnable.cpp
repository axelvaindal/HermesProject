/****************************************************************************
** Meta object code from reading C++ file 'serializerrunnable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/serializerrunnable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serializerrunnable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QJson__SerializerRunnable_t {
    QByteArrayData data[6];
    char stringdata[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QJson__SerializerRunnable_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QJson__SerializerRunnable_t qt_meta_stringdata_QJson__SerializerRunnable = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 15),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 10),
QT_MOC_LITERAL(4, 54, 2),
QT_MOC_LITERAL(5, 57, 9)
    },
    "QJson::SerializerRunnable\0parsingFinished\0"
    "\0serialized\0ok\0error_msg\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QJson__SerializerRunnable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool, QMetaType::QString,    3,    4,    5,

       0        // eod
};

void QJson::SerializerRunnable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerializerRunnable *_t = static_cast<SerializerRunnable *>(_o);
        switch (_id) {
        case 0: _t->parsingFinished((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerializerRunnable::*_t)(const QByteArray & , bool , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerializerRunnable::parsingFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QJson::SerializerRunnable::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QJson__SerializerRunnable.data,
      qt_meta_data_QJson__SerializerRunnable,  qt_static_metacall, 0, 0}
};


const QMetaObject *QJson::SerializerRunnable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QJson::SerializerRunnable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QJson__SerializerRunnable.stringdata))
        return static_cast<void*>(const_cast< SerializerRunnable*>(this));
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(const_cast< SerializerRunnable*>(this));
    return QObject::qt_metacast(_clname);
}

int QJson::SerializerRunnable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QJson::SerializerRunnable::parsingFinished(const QByteArray & _t1, bool _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

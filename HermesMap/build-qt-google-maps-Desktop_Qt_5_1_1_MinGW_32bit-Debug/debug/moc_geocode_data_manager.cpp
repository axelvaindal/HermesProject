/****************************************************************************
** Meta object code from reading C++ file 'geocode_data_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qt-google-maps-master/geocode_data_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'geocode_data_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GeocodeDataManager_t {
    QByteArrayData data[10];
    char stringdata[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GeocodeDataManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GeocodeDataManager_t qt_meta_stringdata_GeocodeDataManager = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 12),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 16),
QT_MOC_LITERAL(4, 50, 4),
QT_MOC_LITERAL(5, 55, 5),
QT_MOC_LITERAL(6, 61, 12),
QT_MOC_LITERAL(7, 74, 13),
QT_MOC_LITERAL(8, 88, 14),
QT_MOC_LITERAL(9, 103, 5)
    },
    "GeocodeDataManager\0errorOccured\0\0"
    "coordinatesReady\0east\0north\0addressReady\0"
    "replyFinished\0QNetworkReply*\0reply\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeocodeDataManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,
       3,    2,   37,    2, 0x05,
       6,    1,   42,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   45,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    4,    5,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void GeocodeDataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GeocodeDataManager *_t = static_cast<GeocodeDataManager *>(_o);
        switch (_id) {
        case 0: _t->errorOccured((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->coordinatesReady((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->addressReady((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GeocodeDataManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GeocodeDataManager::errorOccured)) {
                *result = 0;
            }
        }
        {
            typedef void (GeocodeDataManager::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GeocodeDataManager::coordinatesReady)) {
                *result = 1;
            }
        }
        {
            typedef void (GeocodeDataManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GeocodeDataManager::addressReady)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GeocodeDataManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GeocodeDataManager.data,
      qt_meta_data_GeocodeDataManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *GeocodeDataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeocodeDataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeocodeDataManager.stringdata))
        return static_cast<void*>(const_cast< GeocodeDataManager*>(this));
    return QObject::qt_metacast(_clname);
}

int GeocodeDataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GeocodeDataManager::errorOccured(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GeocodeDataManager::coordinatesReady(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GeocodeDataManager::addressReady(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

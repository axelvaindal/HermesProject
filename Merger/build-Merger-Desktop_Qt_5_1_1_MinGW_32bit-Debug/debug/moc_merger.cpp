/****************************************************************************
** Meta object code from reading C++ file 'merger.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Merger/merger.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'merger.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Merger_t {
    QByteArrayData data[7];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Merger_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Merger_t qt_meta_stringdata_Merger = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 23),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 21),
QT_MOC_LITERAL(4, 54, 16),
QT_MOC_LITERAL(5, 71, 13),
QT_MOC_LITERAL(6, 85, 14)
    },
    "Merger\0on_selectFolder_clicked\0\0"
    "on_selectJson_clicked\0on_merge_clicked\0"
    "replyFinished\0QNetworkReply*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Merger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    0,   35,    2, 0x08,
       4,    0,   36,    2, 0x08,
       5,    1,   37,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void Merger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Merger *_t = static_cast<Merger *>(_o);
        switch (_id) {
        case 0: _t->on_selectFolder_clicked(); break;
        case 1: _t->on_selectJson_clicked(); break;
        case 2: _t->on_merge_clicked(); break;
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
    }
}

const QMetaObject Merger::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Merger.data,
      qt_meta_data_Merger,  qt_static_metacall, 0, 0}
};


const QMetaObject *Merger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Merger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Merger.stringdata))
        return static_cast<void*>(const_cast< Merger*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Merger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
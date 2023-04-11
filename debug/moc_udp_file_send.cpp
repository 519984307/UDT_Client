/****************************************************************************
** Meta object code from reading C++ file 'udp_file_send.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../udp_file_send.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udp_file_send.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UDP_FILE_SEND_THREAD_t {
    QByteArrayData data[6];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDP_FILE_SEND_THREAD_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDP_FILE_SEND_THREAD_t qt_meta_stringdata_UDP_FILE_SEND_THREAD = {
    {
QT_MOC_LITERAL(0, 0, 20), // "UDP_FILE_SEND_THREAD"
QT_MOC_LITERAL(1, 21, 7), // "LogSend"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "text"
QT_MOC_LITERAL(4, 35, 16), // "ss_FileSendState"
QT_MOC_LITERAL(5, 52, 15) // "ss_SendComplete"

    },
    "UDP_FILE_SEND_THREAD\0LogSend\0\0text\0"
    "ss_FileSendState\0ss_SendComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDP_FILE_SEND_THREAD[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    2,   32,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void,

       0        // eod
};

void UDP_FILE_SEND_THREAD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UDP_FILE_SEND_THREAD *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LogSend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ss_FileSendState((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->ss_SendComplete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UDP_FILE_SEND_THREAD::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDP_FILE_SEND_THREAD::LogSend)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UDP_FILE_SEND_THREAD::*)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDP_FILE_SEND_THREAD::ss_FileSendState)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UDP_FILE_SEND_THREAD::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDP_FILE_SEND_THREAD::ss_SendComplete)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UDP_FILE_SEND_THREAD::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_UDP_FILE_SEND_THREAD.data,
    qt_meta_data_UDP_FILE_SEND_THREAD,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UDP_FILE_SEND_THREAD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDP_FILE_SEND_THREAD::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDP_FILE_SEND_THREAD.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int UDP_FILE_SEND_THREAD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void UDP_FILE_SEND_THREAD::LogSend(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDP_FILE_SEND_THREAD::ss_FileSendState(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UDP_FILE_SEND_THREAD::ss_SendComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

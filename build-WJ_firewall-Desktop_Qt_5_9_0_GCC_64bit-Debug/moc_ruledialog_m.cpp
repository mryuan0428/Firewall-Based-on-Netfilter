/****************************************************************************
** Meta object code from reading C++ file 'ruledialog_m.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WJ_firewall/ruledialog_m.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ruledialog_m.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ruledialog_m_t {
    QByteArrayData data[8];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ruledialog_m_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ruledialog_m_t qt_meta_stringdata_ruledialog_m = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ruledialog_m"
QT_MOC_LITERAL(1, 13, 13), // "modRuleSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "rule_str_tp"
QT_MOC_LITERAL(4, 40, 24), // "on_pushButton_ok_clicked"
QT_MOC_LITERAL(5, 65, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(6, 94, 39), // "on_comboBox_protocol_currentT..."
QT_MOC_LITERAL(7, 134, 4) // "text"

    },
    "ruledialog_m\0modRuleSignal\0\0rule_str_tp\0"
    "on_pushButton_ok_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_comboBox_protocol_currentTextChanged\0"
    "text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ruledialog_m[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void ruledialog_m::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ruledialog_m *_t = static_cast<ruledialog_m *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modRuleSignal((*reinterpret_cast< rule_str_tp(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_ok_clicked(); break;
        case 2: _t->on_pushButton_cancel_clicked(); break;
        case 3: _t->on_comboBox_protocol_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ruledialog_m::*_t)(rule_str_tp );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ruledialog_m::modRuleSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ruledialog_m::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ruledialog_m.data,
      qt_meta_data_ruledialog_m,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ruledialog_m::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ruledialog_m::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ruledialog_m.stringdata0))
        return static_cast<void*>(const_cast< ruledialog_m*>(this));
    return QDialog::qt_metacast(_clname);
}

int ruledialog_m::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ruledialog_m::modRuleSignal(rule_str_tp _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

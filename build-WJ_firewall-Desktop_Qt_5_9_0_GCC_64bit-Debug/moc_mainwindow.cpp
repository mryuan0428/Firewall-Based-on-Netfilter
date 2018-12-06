/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WJ_firewall/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 29), // "on_pushButton_addRule_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 29), // "on_pushButton_delRule_clicked"
QT_MOC_LITERAL(4, 72, 29), // "on_pushButton_fiterOn_clicked"
QT_MOC_LITERAL(5, 102, 30), // "on_pushButton_fiterOff_clicked"
QT_MOC_LITERAL(6, 133, 13), // "addRuleString"
QT_MOC_LITERAL(7, 147, 11), // "rule_str_tp"
QT_MOC_LITERAL(8, 159, 10), // "ruleString"
QT_MOC_LITERAL(9, 170, 13), // "modRuleString"
QT_MOC_LITERAL(10, 184, 13), // "delRuleString"
QT_MOC_LITERAL(11, 198, 6), // "action"
QT_MOC_LITERAL(12, 205, 9), // "updateLog"
QT_MOC_LITERAL(13, 215, 30), // "on_pushButton_logClean_clicked"
QT_MOC_LITERAL(14, 246, 29), // "on_pushButton_modRule_clicked"
QT_MOC_LITERAL(15, 276, 31), // "on_action_importRules_triggered"
QT_MOC_LITERAL(16, 308, 31), // "on_action_exportRules_triggered"
QT_MOC_LITERAL(17, 340, 27), // "on_action_exitAPP_triggered"
QT_MOC_LITERAL(18, 368, 25) // "on_action_about_triggered"

    },
    "MainWindow\0on_pushButton_addRule_clicked\0"
    "\0on_pushButton_delRule_clicked\0"
    "on_pushButton_fiterOn_clicked\0"
    "on_pushButton_fiterOff_clicked\0"
    "addRuleString\0rule_str_tp\0ruleString\0"
    "modRuleString\0delRuleString\0action\0"
    "updateLog\0on_pushButton_logClean_clicked\0"
    "on_pushButton_modRule_clicked\0"
    "on_action_importRules_triggered\0"
    "on_action_exportRules_triggered\0"
    "on_action_exitAPP_triggered\0"
    "on_action_about_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    1,   88,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      10,    1,   94,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_addRule_clicked(); break;
        case 1: _t->on_pushButton_delRule_clicked(); break;
        case 2: _t->on_pushButton_fiterOn_clicked(); break;
        case 3: _t->on_pushButton_fiterOff_clicked(); break;
        case 4: _t->addRuleString((*reinterpret_cast< rule_str_tp(*)>(_a[1]))); break;
        case 5: _t->modRuleString((*reinterpret_cast< rule_str_tp(*)>(_a[1]))); break;
        case 6: _t->delRuleString((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->updateLog(); break;
        case 8: _t->on_pushButton_logClean_clicked(); break;
        case 9: _t->on_pushButton_modRule_clicked(); break;
        case 10: _t->on_action_importRules_triggered(); break;
        case 11: _t->on_action_exportRules_triggered(); break;
        case 12: _t->on_action_exitAPP_triggered(); break;
        case 13: _t->on_action_about_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

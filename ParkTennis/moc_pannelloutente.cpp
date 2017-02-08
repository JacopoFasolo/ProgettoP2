/****************************************************************************
** Meta object code from reading C++ file 'pannelloutente.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pannelloutente.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pannelloutente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PannelloUtente[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      27,   15,   15,   15, 0x0a,
      47,   15,   15,   15, 0x0a,
      67,   15,   15,   15, 0x0a,
      92,   15,   15,   15, 0x0a,
     111,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PannelloUtente[] = {
    "PannelloUtente\0\0showTime()\0"
    "btnPrenotaclicked()\0btnEliminaclicked()\0"
    "btnDisiscriviticlicked()\0btnLogOutclicked()\0"
    "aggiornaTabella()\0"
};

void PannelloUtente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PannelloUtente *_t = static_cast<PannelloUtente *>(_o);
        switch (_id) {
        case 0: _t->showTime(); break;
        case 1: _t->btnPrenotaclicked(); break;
        case 2: _t->btnEliminaclicked(); break;
        case 3: _t->btnDisiscriviticlicked(); break;
        case 4: _t->btnLogOutclicked(); break;
        case 5: _t->aggiornaTabella(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PannelloUtente::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PannelloUtente::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PannelloUtente,
      qt_meta_data_PannelloUtente, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PannelloUtente::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PannelloUtente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PannelloUtente::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PannelloUtente))
        return static_cast<void*>(const_cast< PannelloUtente*>(this));
    return QWidget::qt_metacast(_clname);
}

int PannelloUtente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

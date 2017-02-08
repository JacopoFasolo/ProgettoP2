#ifndef PANNELLOMAESTRO_H
#define PANNELLOMAESTRO_H

#include <QWidget>
#include <pannelloutente.h>
#include <QLineEdit>
#include <QLabel>

class PannelloMaestro : public PannelloUtente
{
    Q_OBJECT

public:
    explicit PannelloMaestro(PannelloUtente *parent = 0);

signals:

public slots:
};

#endif // PANNELLOMESTRO_H

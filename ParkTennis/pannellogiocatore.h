#ifndef PANNELLOGIOCATORE_H
#define PANNELLOGIOCATORE_H

#include <pannelloutente.h>

class PannelloGiocatore : public PannelloUtente
{
    Q_OBJECT
public:
    explicit PannelloGiocatore(PannelloUtente *parent = 0);

signals:

public slots:
};

#endif // PANNELLOGIOCATORE_H

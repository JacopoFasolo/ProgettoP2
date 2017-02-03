#ifndef ORARIO_H
#define ORARIO_H

//La classe Orario rappresenta l'ora di inizio in cui è possibile prenotare un'ora di tennis.
//Un'ora di tennis è prenotabile dalle 9 alle 22.

class Orario
{
private:
    unsigned short int ora;
public:
    Orario(int o=0);
    int getOra() const;
    bool operator> (const Orario& o) const;
    bool operator>= (const Orario& o) const;
    bool operator< (const Orario& o) const;
    bool operator<= (const Orario& o) const;
    bool operator== (const Orario& o) const;
    bool operator!= (const Orario& o) const;
    Orario operator+ (const Orario& o) const;
    Orario& operator++ ();
    Orario& operator++ (int);
};

#endif // ORARIO_H

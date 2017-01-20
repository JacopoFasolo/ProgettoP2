#ifndef ORARIO_H
#define ORARIO_H

//La classe orario rappresenta l'ora di inizio in cui è possibile prenotare un'ora di tennis.
//Un'ora di tennis è prenotabile dalle 9 alle 22.

class orario
{
private:
    unsigned short int ora;
public:
    orario(int o);
    int getOra() const;
    bool operator==(const orario& o) const;
    bool operator> (const orario& o) const;
    bool operator>= (const orario& o) const;
    bool operator< (const orario& o) const;
    bool operator<= (const orario& o) const;
    bool operator== (const orario& o) const;
    bool operator!= (const orario& o) const;
    orario operator+ (const orario& o) const;
    orario& operator++ ();
    orario& operator++ (int);
};

#endif // ORARIO_H

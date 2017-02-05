#include "orario.h"

Orario::Orario(int o): ora(o){ora=ora%24;}

int Orario::getOra() const {return ora;}

bool Orario::operator> (const Orario& o) const {return ora>o.ora;}

bool Orario::operator>= (const Orario& o) const {return ora>=o.ora;}

bool Orario::operator< (const Orario& o) const {return ora<o.ora;}

bool Orario::operator<= (const Orario& o) const {return ora<=o.ora;}

bool Orario::operator== (const Orario& o) const {return ora==o.ora;}

bool Orario::operator!= (const Orario& o) const {return ora!=o.ora;}

Orario Orario::operator+ (const Orario& o) const {return Orario(ora+o.ora);}

Orario& Orario::operator++ () {ora+=1; ora=ora%24; return *this;}

Orario& Orario::operator++ (int) {Orario temp=*this; ora+=1; ora=ora%24; return temp;}

#include "orario.h"

orario::orario(int o): ora(o){ora=ora%24;}

int orario::getOra() const {return ora;}

bool orario::operator> (const orario& o) const {return ora>o.ora;}

bool orario::operator>= (const orario& o) const {return ora>=o.ora;}

bool orario::operator< (const orario& o) const {return ora<o.ora;}

bool orario::operator<= (const orario& o) const {return ora<=o.ora;}

bool orario::operator== (const orario& o) const {return ora==o.ora;}

bool orario::operator!= (const orario& o) const {return ora!=o.ora;}

orario::orario orario::operator+ (const orario& o) const {return orario(ora+o.ora);}

orario::orario& orario::operator++ () {ora+=1; return *this;}

orario::orario& orario::operator++ (int) {orario temp=*this; ora+=1; return temp;}
